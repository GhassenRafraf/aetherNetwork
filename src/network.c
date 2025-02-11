#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "network.h"
#include "aodv.h"

int node_id;
char node_ip[16];
pthread_t listener_thread;

void init_network(int id, const char* ip) {
    node_id = id;
    strncpy(node_ip, ip, 16);

    pthread_create(&listener_thread, NULL, receive_messages, NULL);
}

void send_message(const char* dest_ip, const char* message) {
    struct sockaddr_in dest_addr;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(AODV_PORT);
    inet_pton(AF_INET, dest_ip, &dest_addr.sin_addr);

    sendto(sock, message, strlen(message), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
    close(sock);
}

void* receive_messages(void* arg) {
    struct sockaddr_in server_addr, client_addr;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    char buffer[1024];

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(AODV_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    while (1) {
        socklen_t len = sizeof(client_addr);
        recvfrom(sock, buffer, 1024, 0, (struct sockaddr*)&client_addr, &len);
        buffer[strcspn(buffer, "\n")] = 0;

        char sender_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, sender_ip, INET_ADDRSTRLEN);

        handle_received_message(buffer, sender_ip);
    }
}

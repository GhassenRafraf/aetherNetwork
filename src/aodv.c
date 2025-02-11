#include <stdio.h>
#include <string.h>
#include "aodv.h"
#include "network.h"
#include "routing_table.h"

void init_aodv(int node_id, const char* ip) {
    init_network(node_id, ip);
}

// Sending RREQ (Route Request)
void send_rreq(int destination) {
    char message[50];
    snprintf(message, 50, "RREQ %d %d", node_id, destination);
    send_message(BROADCAST_ADDR, message);
}

// Sending RREP (Route Reply)
void send_rrep(int destination, int next_hop) {
    char message[50];
    snprintf(message, 50, "RREP %d %d", node_id, destination);
    send_message(get_next_hop(destination), message);
}

// Sending RERR (Route Error)
void send_rerr(int broken_link) {
    char message[50];
    snprintf(message, 50, "RERR %d", broken_link);
    send_message(BROADCAST_ADDR, message);
}

// Handling received messages
void handle_received_message(char* buffer, int sender) {
    int src, dest;
    if (sscanf(buffer, "RREQ %d %d", &src, &dest) == 2) {
        printf("[AODV] Received RREQ from %d for %d\n", src, dest);
        if (dest == node_id) {
            send_rrep(dest, src);
        } else {
            send_rreq(dest);
        }
    }
    else if (sscanf(buffer, "RREP %d %d", &src, &dest) == 2) {
        printf("[AODV] Received RREP from %d to %d\n", src, dest);
        add_route(dest, sender, 1);
    }
    else if (sscanf(buffer, "RERR %d", &src) == 1) {
        printf("[AODV] Received RERR for %d\n", src);
        remove_route(src);
    }
}

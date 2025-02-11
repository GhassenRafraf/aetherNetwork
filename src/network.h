#ifndef NETWORK_H
#define NETWORK_H

#define MAX_NODES 10

void init_network(int node_id, const char* ip);
void send_message(const char* dest_ip, const char* message);
void* receive_messages(void* arg);

#endif

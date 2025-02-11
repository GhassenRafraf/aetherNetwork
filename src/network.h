#ifndef NETWORK_H
#define NETWORK_H

#define MAX_NODES 10

// Initialize network layer with the local node's id and IP address.
void init_network(int node_id, const char* ip);

// Send a UDP message to dest_ip
void send_message(const char* dest_ip, const char* message);

// Thread function for receiving UDP messages.
void* receive_messages(void* arg);

#endif

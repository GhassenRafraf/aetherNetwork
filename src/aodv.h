#ifndef AODV_H
#define AODV_H

#include <stdint.h>

#define RREQ 1
#define RREP 2
#define RERR 3

#define BROADCAST_ADDR "255.255.255.255"
#define AODV_PORT 5555

void init_aodv(int node_id, const char* ip);
void send_rreq(int destination);
void send_rrep(int destination, int next_hop);
void send_rerr(int broken_link);
void listen_for_messages();
void handle_received_message(char* buffer, int sender);

#endif

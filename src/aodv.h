#ifndef AODV_H
#define AODV_H

#include <stdint.h>

#define RREQ 1
#define RREP 2
#define RERR 3

#define BROADCAST_ADDR "255.255.255.255"
#define AODV_PORT 5555

extern int node_id;  // Global node ID

// Initialize AODV and network (ip is our local IP)
void init_aodv(int id, const char* ip);

// Send a Route Request for destination
void send_rreq(int destination);

// Send a Route Reply back to a target IP
void send_rrep(int destination, const char* target_ip);

// Send a Route Error for a broken link
void send_rerr(int broken_link);

// Handle a received message (sender_ip is the IP from which the message came)
void handle_received_message(char* buffer, const char* sender_ip);

#endif

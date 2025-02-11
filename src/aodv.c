#include <stdio.h>
#include <string.h>
#include "aodv.h"
#include "network.h"
#include "routing_table.h"

int node_id;  // Defined here only

void init_aodv(int id, const char* ip) {
    node_id = id;
    init_network(id, ip);
}

// Sending RREQ (Route Request)
// Message format: "RREQ <source> <destination>"
void send_rreq(int destination) {
    char message[50];
    snprintf(message, sizeof(message), "RREQ %d %d", node_id, destination);
    send_message(BROADCAST_ADDR, message);
}

// Sending RREP (Route Reply)
// Message format: "RREP <source>"
// In this simplified design, the reply message carries the sender’s ID;
// we use the target IP (passed in) as the destination of the reply.
void send_rrep(int destination, const char* target_ip) {
    char message[50];
    snprintf(message, sizeof(message), "RREP %d", node_id);
    send_message(target_ip, message);
}

// Sending RERR (Route Error)
// Message format: "RERR <broken_link>"
void send_rerr(int broken_link) {
    char message[50];
    snprintf(message, sizeof(message), "RERR %d", broken_link);
    send_message(BROADCAST_ADDR, message);
}

// Handling received messages
// We no longer use the passed-in sender_ip as a destination for sscanf.
void handle_received_message(char* buffer, const char* sender_ip) {
    int src, dest;
    // Handle RREQ: "RREQ <source> <destination>"
    if (sscanf(buffer, "RREQ %d %d", &src, &dest) == 2) {
        printf("[AODV] Received RREQ from %d for %d\n", src, dest);
        if (dest == node_id) {  
            // If this node is the destination, send RREP back to sender
            send_rrep(dest, sender_ip);
        } else {
            // Otherwise, forward the RREQ (this simple demo just rebroadcasts)
            send_rreq(dest);
        }
    }
    // Handle RREP: "RREP <source>"
    else if (sscanf(buffer, "RREP %d", &src) == 1) {
        printf("[AODV] Received RREP from %d\n", src);
        // Use the sender's IP (from the network) as the next hop for the route.
        add_route(src, sender_ip, 1);
    }
    // Handle RERR: "RERR <broken_link>"
    else if (sscanf(buffer, "RERR %d", &src) == 1) {
        printf("[AODV] Received RERR for %d\n", src);
        remove_route(src);
    }
}

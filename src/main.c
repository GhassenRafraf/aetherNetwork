#include <stdio.h>
#include "aodv.h"

int main() {
    int my_node_id = 2;
    // Initialize AODV with node ID and local IP address.
    init_aodv(my_node_id, "192.168.1.2");

    // Simulate a route discovery: send a RREQ for destination node 5.
    send_rreq(2);

    // Keep the main thread alive.
    while (1) {
        // Optionally, add sleep or periodic routing table printing.
    }

    return 0;
}

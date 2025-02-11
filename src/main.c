#include <stdio.h>
#include <stdlib.h>
#include "aodv.h"

int main() {
    char *env_node_id = getenv("NODE_ID");
    char *env_node_ip = getenv("NODE_IP");

    if (!env_node_id || !env_node_ip) {
        fprintf(stderr, "Error: NODE_ID and NODE_IP environment variables must be set.\n");
        return 1;
    }

    int my_node_id = atoi(env_node_id);
    printf("Starting node %d with IP %s\n", my_node_id, env_node_ip);

    // Initialize AODV with the node id and local IP.
    init_aodv(my_node_id, env_node_ip);

    // For demonstration, we send a route request for destination 5.
    send_rreq(5);

    // Main loop—keeps the container running.
    while (1) {
        sleep(1);
    }

    return 0;
}

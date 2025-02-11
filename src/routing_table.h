#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#define MAX_ROUTES 100

// Add or update a route for destination with the next hop IP and hop count.
void add_route(int destination, const char* next_hop, int hop_count);

// Get the next hop for a given destination (returns pointer to internal storage).
char* get_next_hop(int destination);

// Remove the route for the given destination.
void remove_route(int destination);

// Optionally print the routing table.
void print_routing_table();

#endif

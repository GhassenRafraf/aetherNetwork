#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#define MAX_ROUTES 100

void add_route(int destination, const char* next_hop, int hop_count);
char* get_next_hop(int destination);
void remove_route(int destination);
void print_routing_table();

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "routing_table.h"

typedef struct {
    int destination;
    char next_hop[16];
    int hop_count;
} RouteEntry;

RouteEntry routing_table[MAX_ROUTES];
int route_count = 0;

void add_route(int destination, const char* next_hop, int hop_count) {
    for (int i = 0; i < route_count; i++) {
        if (routing_table[i].destination == destination) {
            strncpy(routing_table[i].next_hop, next_hop, 16);
            routing_table[i].hop_count = hop_count;
            return;
        }
    }

    if (route_count < MAX_ROUTES) {
        routing_table[route_count++] = (RouteEntry){destination, "", hop_count};
        strncpy(routing_table[route_count - 1].next_hop, next_hop, 16);
    }
}

char* get_next_hop(int destination) {
    for (int i = 0; i < route_count; i++) {
        if (routing_table[i].destination == destination) {
            return routing_table[i].next_hop;
        }
    }
    return NULL;
}

void remove_route(int destination) {
    for (int i = 0; i < route_count; i++) {
        if (routing_table[i].destination == destination) {
            routing_table[i] = routing_table[--route_count];
            return;
        }
    }
}

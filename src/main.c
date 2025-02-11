#include "aodv.h"

int main() {
    init_aodv(1, "192.168.1.1");

    send_rreq(5);

    while (1);
    return 0;
}

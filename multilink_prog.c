#include <stdio.h>
#include "unit_cfz.h"

int main() {
	unit_cfz_load("lib/unit_cfz_v1.so");
	
	DEBUG("%s\n", version());
	DEBUG("Enumerated %i ports\n", get_enumerated_number_of_ports(PortType_USBMultilink));
}

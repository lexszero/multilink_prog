#include <stdio.h>
#include "unit_cfz.h"

int main(int argc, char **argv) {
	unit_cfz_load("lib/unit_cfz_v1.so");
	
	DEBUG("%s\n", version());

	DEBUG("Enumerated %i ports\n", get_enumerated_number_of_ports(PortType_USBMultilink));

	char *port_desc = get_port_descriptor(PortType_USBMultilink, 1);
	DEBUG("Using port %s\n", port_desc);

	if (open_port(PortType_USBMultilink, 1) != 0) {
		DEBUG("open_port failed, check_critical_error = %x\n", check_critical_error());
		return 1;
	}

	close_port();
	unit_cfz_unload();

	return 0;
}

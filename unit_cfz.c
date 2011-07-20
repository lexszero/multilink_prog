#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "unit_cfz.h"

const int PortType_ParallelPortCable = 1; 
const int PortType_PCIBDMLightning = 2;
const int PortType_USBMultilink = 3;
const int PortType_CycloneProMaxSerial = 4;
const int PortType_CycloneProMaxUSB = 5;
const int PortType_CycloneProMaxEthernet = 6;

type_version version;
type_reenumerate_all_port_types reenumerate_all_port_types;
type_get_enumerated_number_of_ports get_enumerated_number_of_ports;

void *lib = NULL;

int unit_cfz_load(const char *path) {
	lib = dlopen(path, RTLD_NOW);
	if (!lib) {
		DEBUG("%s\n", dlerror());
		return 0;
	}

#define try_dlsym(sym) \
	sym = (type_##sym)dlsym(lib, #sym); \
	if (!sym) { DEBUG("%s\n", dlerror()); return 0; };

	try_dlsym(version);
	try_dlsym(reenumerate_all_port_types);
	try_dlsym(get_enumerated_number_of_ports);
#undef try_dlsym

	return 1;
}

int unit_cfz_unload() {
	if (!lib)
		return 1;

	if (dlclose(lib) != 0) {
		DEBUG("%s\n", dlerror());
		return 2;
	}

	return 0;
}

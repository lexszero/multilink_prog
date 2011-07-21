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

type_get_cable_version get_cable_version;
type_version version;
type_force_background_mode force_background_mode;
type_test_for_freeze test_for_freeze;
type_go_to_background go_to_background;
type_resume resume;
type_single_step single_step;
type_read_data_long read_data_long;
type_read_data_word read_data_word;
type_read_data_byte read_data_byte;
type_write_data_long write_data_long;
type_write_data_word write_data_word;
type_write_data_byte write_data_byte;
type_get_control get_control;
type_put_control put_control;
type_put_data_reg put_data_reg;
type_put_add_reg put_add_reg;
type_put_pc_value put_pc_value;
type_get_pc_value get_pc_value;
type_put_ccr_value put_ccr_value;
type_get_ccr_value get_ccr_value;
type_get_data_reg get_data_reg;
type_get_add_reg get_add_reg;
type_data_from_cpu_value data_from_cpu_value;
type_load_bin_file load_bin_file;
type_load_srec_file load_srec_file;
type_before_step before_step;
type_after_step after_step;
type_buss_error_value buss_error_value;
type_set_io_delay_cnt_value set_io_delay_cnt_value;
type_check_io_delay_cnt_value check_io_delay_cnt_value;
type_check_critical_error check_critical_error;
type_read_debug_module read_debug_module;
type_write_debug_module write_debug_module;
type_put_vbr_value put_vbr_value;
type_get_vbr_value get_vbr_value;
type_put_data_byte_block put_data_byte_block;
type_open_debug_file open_debug_file;
type_close_debug_file close_debug_file;
type_set_bdm_shift_speed set_bdm_shift_speed;

type_reenumerate_all_port_types reenumerate_all_port_types;
type_get_enumerated_number_of_ports get_enumerated_number_of_ports;
type_get_port_descriptor get_port_descriptor;
type_get_port_descriptor_short get_port_descriptor_short;
type_open_port open_port;
type_close_port close_port;
type_get_register_block get_register_block;
type_get_data_block get_data_block;
type_reset_hardware_interface reset_hardware_interface;

//The Following calls are legacy and are not recommended for use.
type_get_data_byte_block_with_errors get_data_byte_block_with_errors;
type_init_port init_port;
type_init_port_address init_port_address;
type_init_lightning_port init_lightning_port;
type_query_number_of_parallel_ports query_number_of_parallel_ports;
type_query_number_of_lightning_ports query_number_of_lightning_ports;
type_get_data_byte_block get_data_byte_block;
type_set_bdm_lightning_speed set_bdm_lightning_speed;

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

	try_dlsym(get_cable_version);
	try_dlsym(version);
	try_dlsym(force_background_mode);
	try_dlsym(test_for_freeze);
	try_dlsym(go_to_background);
	try_dlsym(resume);
	try_dlsym(single_step);
	try_dlsym(read_data_long);
	try_dlsym(read_data_word);
	try_dlsym(read_data_byte);
	try_dlsym(write_data_long);
	try_dlsym(write_data_word);
	try_dlsym(write_data_byte);
	try_dlsym(get_control);
	try_dlsym(put_control);
	try_dlsym(put_data_reg);
	try_dlsym(put_add_reg);
	try_dlsym(put_pc_value);
	try_dlsym(get_pc_value);
	try_dlsym(put_ccr_value);
	try_dlsym(get_ccr_value);
	try_dlsym(get_data_reg);
	try_dlsym(get_add_reg);
	try_dlsym(data_from_cpu_value);
	try_dlsym(load_bin_file);
	try_dlsym(load_srec_file);
	try_dlsym(before_step);
	try_dlsym(after_step);
	try_dlsym(buss_error_value);
	try_dlsym(set_io_delay_cnt_value);
	try_dlsym(check_io_delay_cnt_value);
	try_dlsym(check_critical_error);
	try_dlsym(read_debug_module);
	try_dlsym(write_debug_module);
	try_dlsym(put_vbr_value);
	try_dlsym(get_vbr_value);
	try_dlsym(put_data_byte_block);
	try_dlsym(open_debug_file);
	try_dlsym(close_debug_file);
	try_dlsym(set_bdm_shift_speed);
	try_dlsym(reenumerate_all_port_types);
	try_dlsym(get_enumerated_number_of_ports);
	try_dlsym(get_port_descriptor);
	try_dlsym(get_port_descriptor_short);
	try_dlsym(open_port);
	try_dlsym(close_port);
	try_dlsym(get_register_block);
	try_dlsym(get_data_block);
	try_dlsym(reset_hardware_interface);
	try_dlsym(get_data_byte_block_with_errors);
	try_dlsym(init_port);
	try_dlsym(init_port_address);
	try_dlsym(init_lightning_port);
	try_dlsym(query_number_of_parallel_ports);
	try_dlsym(query_number_of_lightning_ports);
	try_dlsym(get_data_byte_block);
	try_dlsym(set_bdm_lightning_speed);
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

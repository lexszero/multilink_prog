#ifndef __unit_cfz_h
#define __unit_cfz_h

#include <stdbool.h>

#define DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

#define _cdecl __attribute__((cdecl))

extern int unit_cfz_load(const char *path);
extern int unit_cfz_unload();

/* THESE ARE THE CALLS YOU CAN MAKE TO THIS FILE

NOTE: YOU MUST CALL load_dll(); FIRST!!!!!!!

unsigned int get_cable_version(void); 
pchar  version(void);
bool  force_background_mode(void);
bool  test_for_freeze(void);
bool  go_to_background(void);
void  resume(void);
void  single_step(void);
unsigned int  read_data_long(unsigned int);
unsigned short  read_data_word(unsigned int);
unsigned char  read_data_byte(unsigned int);
void  write_data_long(unsigned int, unsigned int);
void  write_data_word(unsigned int, unsigned short);
void  write_data_byte(unsigned int, unsigned short);
unsigned int get_control(unsigned int);
void  put_control(unsigned int, unsigned int);
void  put_data_reg(unsigned char, unsigned int);
void  put_add_reg(unsigned char, unsigned int);
void  put_pc_value(unsigned int);
unsigned int  get_pc_value(void);
void  put_ccr_value(unsigned short);
unsigned short  get_ccr_value(void);
unsigned int  get_data_reg(unsigned char);
unsigned int  get_add_reg(unsigned char);
unsigned short  data_from_cpu_value(void);
bool  load_bin_file(char *, unsigned int);
bool  load_srec_file(char *, unsigned int);
void  before_step(void);
void  after_step(void);
bool  buss_error_value(void);
void  set_io_delay_cnt_value(unsigned short);
unsigned short  check_io_delay_cnt_value(void);
unsigned char check_critical_error(void);
void write_debug_module(unsigned char, unsigned int);
unsigned int read_debug_module(unsigned char);
void put_vbr_value(unsigned int newvbr);
unsigned int get_vbr_value;
void put_data_byte_block(unsigned int address, unsigned int num_bytes, unsigned char *buffer_ptr);
void open_debug_file(char *filename);
void close_debug_file;
void set_bdm_shift_speed(unsigned short bdm_speed);

bool reenumerate_all_port_types(void);
unsigned int get_enumerated_number_of_ports(unsigned int PortType);
char * get_port_descriptor(unsigned int PortType, unsigned int PortNum);
char * get_port_descriptor_short(unsigned int PortType, unsigned int PortNum);
bool open_port(unsigned int PortType, unsigned int PortNum);
void  close_port(void);
void get_register_block(unsigned int *RegA7, unsigned int *RegA6, unsigned int *RegA5,
                        unsigned int *RegA4, unsigned int *RegA3, unsigned int *RegA2,
                        unsigned int *RegA1, unsigned int *RegA0,
                        unsigned int *RegD7, unsigned int *RegD6, unsigned int *RegD5,
                        unsigned int *RegD4, unsigned int *RegD3, unsigned int *RegD2,
                        unsigned int *RegD1, unsigned int *RegD0,
                        unsigned int *RegPC, unsigned int *RegVBR, unsigned int *RegCCR);
bool get_data_block(unsigned int address,
                    unsigned int num_bytes,
                    unsigned int read_type,    // 1, 2, or 4
                    unsigned char *buffer_ptr, // buffer that data is deposited in
                    unsigned char *error_ptr);
void reset_hardware_interface(void);


Now here comes the code...
*/

extern const int PortType_ParallelPortCable;
extern const int PortType_PCIBDMLightning;
extern const int PortType_USBMultilink;
extern const int PortType_CycloneProMaxSerial;
extern const int PortType_CycloneProMaxUSB;
extern const int PortType_CycloneProMaxEthernet;

typedef char * (_cdecl *type_version)(void);
extern type_version version;
typedef unsigned short (_cdecl *type_get_cable_version)(void); 
extern type_get_cable_version get_cable_version; 
typedef bool  (_cdecl *type_force_background_mode)(void);
extern type_force_background_mode force_background_mode;
typedef bool  (_cdecl *type_test_for_freeze)(void);
extern type_test_for_freeze test_for_freeze;
typedef bool  (_cdecl *type_go_to_background)(void);
extern type_go_to_background go_to_background;
typedef void  (_cdecl *type_resume)(void);
extern type_resume resume;
typedef void  (_cdecl *type_single_step)(void);
extern type_single_step single_step;
typedef unsigned int  (_cdecl *type_read_data_long)(unsigned int);
extern type_read_data_long read_data_long;
typedef unsigned short (_cdecl *type_read_data_word)(unsigned int);
extern type_read_data_word read_data_word;
typedef unsigned char  (_cdecl *type_read_data_byte)(unsigned int);
extern type_read_data_byte read_data_byte;
typedef void  (_cdecl *type_write_data_long)(unsigned int, unsigned int);
extern type_write_data_long write_data_long;
typedef void  (_cdecl *type_write_data_word)(unsigned int, unsigned short);
extern type_write_data_word write_data_word;
typedef void  (_cdecl *type_write_data_byte)(unsigned int, unsigned short);
extern type_write_data_byte write_data_byte;
typedef unsigned int  (_cdecl *type_get_control)(unsigned int);
extern type_get_control get_control;
typedef void  (_cdecl *type_put_control)(unsigned int, unsigned int);
extern type_put_control put_control;
typedef void  (_cdecl *type_put_data_reg)(unsigned char, unsigned int);
extern type_put_data_reg put_data_reg;
typedef void  (_cdecl *type_put_add_reg)(unsigned char, unsigned int);
extern type_put_add_reg put_add_reg;
typedef void  (_cdecl *type_put_pc_value)(unsigned int);
extern type_put_pc_value put_pc_value;
typedef unsigned int  (_cdecl *type_get_pc_value)(void);
extern type_get_pc_value get_pc_value;
typedef void  (_cdecl *type_put_ccr_value)(unsigned short);
extern type_put_ccr_value put_ccr_value;
typedef unsigned short  (_cdecl *type_get_ccr_value)(void);
extern type_get_ccr_value get_ccr_value;
typedef unsigned int  (_cdecl *type_get_data_reg)(unsigned char);

extern type_get_data_reg get_data_reg;
typedef unsigned int  (_cdecl *type_get_add_reg)(unsigned char);
extern type_get_add_reg get_add_reg;
typedef unsigned short  (_cdecl *type_data_from_cpu_value)(void);
extern type_data_from_cpu_value data_from_cpu_value;
typedef bool  (_cdecl *type_load_bin_file)(char *, unsigned int);
extern type_load_bin_file load_bin_file;
typedef bool  (_cdecl *type_load_srec_file)(char *, unsigned int);
extern type_load_srec_file load_srec_file;
typedef void  (_cdecl *type_before_step)(void);
extern type_before_step before_step;
typedef void  (_cdecl *type_after_step)(void);
extern type_after_step after_step;
typedef bool  (_cdecl *type_buss_error_value)(void);
extern type_buss_error_value buss_error_value;
typedef void  (_cdecl *type_set_io_delay_cnt_value)(unsigned short);
extern type_set_io_delay_cnt_value set_io_delay_cnt_value;
typedef unsigned short (_cdecl *type_check_io_delay_cnt_value)(void);
extern type_check_io_delay_cnt_value check_io_delay_cnt_value;
typedef unsigned char (_cdecl *type_check_critical_error)(void);
extern type_check_critical_error check_critical_error;
typedef void  (_cdecl *type_write_debug_module)(unsigned char, unsigned int);
extern type_write_debug_module write_debug_module;
typedef unsigned int (_cdecl *type_read_debug_module)(unsigned char);
extern type_read_debug_module read_debug_module;
typedef void  (_cdecl *type_put_vbr_value)(unsigned int);
extern type_put_vbr_value  put_vbr_value;
typedef unsigned int  (_cdecl *type_get_vbr_value)(void);
extern type_get_vbr_value  get_vbr_value;
typedef void   (_cdecl *type_put_data_byte_block)(unsigned int, unsigned int, unsigned char *);
extern type_put_data_byte_block  put_data_byte_block;
typedef void   (_cdecl *type_open_debug_file)(char *);
extern type_open_debug_file  open_debug_file;
typedef void   (_cdecl *type_close_debug_file)(void);
extern type_close_debug_file  close_debug_file;
typedef void (_cdecl *type_set_bdm_shift_speed)(unsigned short bdm_speed);
extern type_set_bdm_shift_speed set_bdm_shift_speed;

typedef bool (_cdecl *type_reenumerate_all_port_types)(void);
extern type_reenumerate_all_port_types reenumerate_all_port_types;
typedef unsigned int (_cdecl *type_get_enumerated_number_of_ports)(unsigned int PortType);
extern type_get_enumerated_number_of_ports get_enumerated_number_of_ports;
typedef char * (_cdecl *type_get_port_descriptor)(unsigned int PortType, unsigned int PortNum);
extern type_get_port_descriptor get_port_descriptor;
typedef char * (_cdecl *type_get_port_descriptor_short)(unsigned int PortType, unsigned int PortNum);
extern type_get_port_descriptor_short get_port_descriptor_short;
typedef bool (_cdecl *type_open_port)(unsigned int PortType, unsigned int PortNum);
extern type_open_port open_port;
typedef void  (_cdecl *type_close_port)(void);
extern type_close_port close_port;  
typedef void  (_cdecl *type_get_register_block)(unsigned int *RegA7, unsigned int *RegA6, unsigned int *RegA5,
												unsigned int *RegA4, unsigned int *RegA3, unsigned int *RegA2,
												unsigned int *RegA1, unsigned int *RegA0,
												unsigned int *RegD7, unsigned int *RegD6, unsigned int *RegD5,
												unsigned int *RegD4, unsigned int *RegD3, unsigned int *RegD2,
												unsigned int *RegD1, unsigned int *RegD0,
												unsigned int *RegPC, unsigned int *RegVBR, unsigned int *RegCCR);
extern type_get_register_block get_register_block;  
typedef bool  (_cdecl *type_get_data_block)(unsigned int address,
											unsigned int num_bytes,
											unsigned int read_type,    // 1, 2, or 4
											unsigned char *buffer_ptr, // buffer that data is deposited in
											unsigned char *error_ptr);
extern type_get_data_block get_data_block;  
typedef void  (_cdecl *type_reset_hardware_interface)(void);
extern type_reset_hardware_interface reset_hardware_interface;  


//The Following calls are legacy and are not recommended for use.
typedef void  (_cdecl *type_get_data_byte_block_with_errors)(unsigned int address, unsigned int num_bytes,
                                                             unsigned char *buffer_ptr, unsigned char *error_ptr);
extern type_get_data_byte_block_with_errors get_data_byte_block_with_errors;  
typedef void  (_cdecl *type_init_port)(unsigned short);
extern type_init_port init_port;
typedef void  (_cdecl *type_init_port_address)(unsigned short);
extern type_init_port init_port_address;
typedef void (_cdecl *type_init_lightning_port)(unsigned short lightning_port);
extern type_init_lightning_port init_lightning_port;
typedef int (_cdecl *type_query_number_of_parallel_ports)(void);
extern type_query_number_of_parallel_ports query_number_of_parallel_ports;
typedef int (_cdecl *type_query_number_of_lightning_ports)(void);
extern type_query_number_of_lightning_ports query_number_of_lightning_ports;
typedef void   (_cdecl *type_get_data_byte_block)(unsigned int, unsigned int, unsigned char *);
extern type_get_data_byte_block  get_data_byte_block;
typedef void (_cdecl *type_set_bdm_lightning_speed)(unsigned short pci_delay);
extern type_set_bdm_lightning_speed set_bdm_lightning_speed;

#endif

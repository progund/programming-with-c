#include "vehicle/bus.h"

#define GEAR_POS_MASK     0xE0 // 11100000
#define WHEEL_SPEED_MASK  0x18 // 00011000
#define ENGINE_SPEED_MASK 0x07 // 00000111

/**
 * bits:
 *  1-3, 3 bits [abc] : gear position, left shifted 5 
 *  4-5, 2 bits [rs]  : wheel speed, 
 *  6-8, 3 bits [xyz] : engine speed
 *
 * Result:
 *  [abcrsxyz]
 *
 */
int
pack_vechicle_info(vehicle_info* vi, __uint8_t *packed_data);

int
unpack_vechicle_info(__uint8_t packed_data, vehicle_info* vi);


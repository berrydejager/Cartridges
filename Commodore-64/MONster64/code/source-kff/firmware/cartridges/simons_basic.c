/*
 * Copyright (c) 2019 Kim Jørgensen
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

/*************************************************
* C64 bus read callback
*************************************************/
static inline bool simons_basic_read_handler(uint8_t control, uint16_t addr)
{
    if ((control & (C64_ROML|C64_ROMH)) != (C64_ROML|C64_ROMH))
    {
        c64_data_write(crt_ptr[addr & 0x3fff]);
        return true;
    }

    if (!(control & C64_IO1))
    {
        c64_crt_control(STATUS_LED_ON|CRT_PORT_8K);
    }

    return false;
}

/*************************************************
* C64 bus write callback
*************************************************/
static inline void simons_basic_write_handler(uint8_t control, uint16_t addr, uint8_t data)
{
    if (!(control & C64_IO1))
    {
        c64_crt_control(STATUS_LED_ON|CRT_PORT_16K);
    }
}

C64_BUS_HANDLER(simons_basic)

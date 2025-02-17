/*
 * Copyright (C) 2015 Jared Boone, ShareBrained Technology, Inc.
 * Copyright (C) 2023 Bernd Herzog
 *
 * This file is part of PortaPack.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "diskio.h"

#include "ch.h"
#include "hal.h"

uint32_t get_capacity(void) {
    return mmcsdGetCardCapacity(&SDCD1);
}

bool_t read_block(uint32_t startblk, uint8_t* buf, uint32_t n) {
    return sdcRead(&SDCD1, startblk, buf, n);
}

bool_t write_block(uint32_t startblk, uint8_t* buf, uint32_t n) {
    return sdcWrite(&SDCD1, startblk, buf, n);
}

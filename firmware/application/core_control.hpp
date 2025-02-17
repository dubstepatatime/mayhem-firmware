/*
 * Copyright (C) 2015 Jared Boone, ShareBrained Technology, Inc.
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

#ifndef __CORE_CONTROL_H__
#define __CORE_CONTROL_H__

#include <cstddef>

#include "memory_map.hpp"
#include "spi_image.hpp"

void m4_init(const portapack::spi_flash::image_tag_t image_tag, const portapack::memory::region_t to, const bool full_reset);
void m4_init_prepared(const uint32_t m4_code, const bool full_reset);
void m4_request_shutdown();

void m0_halt();

#endif /*__CORE_CONTROL_H__*/

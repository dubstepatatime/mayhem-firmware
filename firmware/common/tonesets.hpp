/*
 * Copyright (C) 2015 Jared Boone, ShareBrained Technology, Inc.
 * Copyright (C) 2016 Furrtek
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

#ifndef __TONESETS_H__
#define __TONESETS_H__

#include <memory>
#include <array>

#define TONES_SAMPLERATE 1536000
#define TONES_DELTA_COEF(sr) ((1ULL << 32) / sr)
#define TONES_F2D(f, sr) (uint32_t)(f * TONES_DELTA_COEF(sr))

#define BEEP_TONES_NB 6

#define DTMF_C0 TONES_F2D(1209, TONES_SAMPLERATE)
#define DTMF_C1 TONES_F2D(1336, TONES_SAMPLERATE)
#define DTMF_C2 TONES_F2D(1477, TONES_SAMPLERATE)
#define DTMF_C3 TONES_F2D(1633, TONES_SAMPLERATE)
#define DTMF_R0 TONES_F2D(697, TONES_SAMPLERATE)
#define DTMF_R1 TONES_F2D(770, TONES_SAMPLERATE)
#define DTMF_R2 TONES_F2D(852, TONES_SAMPLERATE)
#define DTMF_R3 TONES_F2D(941, TONES_SAMPLERATE)

const std::array<uint32_t, 16> ccir_deltas = {
    TONES_F2D(1981, TONES_SAMPLERATE),
    TONES_F2D(1124, TONES_SAMPLERATE),
    TONES_F2D(1197, TONES_SAMPLERATE),
    TONES_F2D(1275, TONES_SAMPLERATE),
    TONES_F2D(1358, TONES_SAMPLERATE),
    TONES_F2D(1446, TONES_SAMPLERATE),
    TONES_F2D(1540, TONES_SAMPLERATE),
    TONES_F2D(1640, TONES_SAMPLERATE),
    TONES_F2D(1747, TONES_SAMPLERATE),
    TONES_F2D(1860, TONES_SAMPLERATE),
    TONES_F2D(2400, TONES_SAMPLERATE),
    TONES_F2D(930, TONES_SAMPLERATE),
    TONES_F2D(2247, TONES_SAMPLERATE),
    TONES_F2D(991, TONES_SAMPLERATE),
    TONES_F2D(2110, TONES_SAMPLERATE),
    TONES_F2D(1055, TONES_SAMPLERATE)};

// 0123456789ABCD#*
const uint32_t dtmf_deltas[16][2] = {
    {DTMF_C1, DTMF_R3},
    {DTMF_C0, DTMF_R0},
    {DTMF_C1, DTMF_R0},
    {DTMF_C2, DTMF_R0},
    {DTMF_C0, DTMF_R1},
    {DTMF_C1, DTMF_R1},
    {DTMF_C2, DTMF_R1},
    {DTMF_C0, DTMF_R2},
    {DTMF_C1, DTMF_R2},
    {DTMF_C2, DTMF_R2},
    {DTMF_C3, DTMF_R0},
    {DTMF_C3, DTMF_R1},
    {DTMF_C3, DTMF_R2},
    {DTMF_C3, DTMF_R3},
    {DTMF_C2, DTMF_R3},
    {DTMF_C0, DTMF_R3}};

const std::array<uint32_t, 16> eia_deltas = {
    TONES_F2D(600, TONES_SAMPLERATE),
    TONES_F2D(741, TONES_SAMPLERATE),
    TONES_F2D(882, TONES_SAMPLERATE),
    TONES_F2D(1023, TONES_SAMPLERATE),
    TONES_F2D(1164, TONES_SAMPLERATE),
    TONES_F2D(1305, TONES_SAMPLERATE),
    TONES_F2D(1446, TONES_SAMPLERATE),
    TONES_F2D(1587, TONES_SAMPLERATE),
    TONES_F2D(1728, TONES_SAMPLERATE),
    TONES_F2D(1869, TONES_SAMPLERATE),
    TONES_F2D(2151, TONES_SAMPLERATE),
    TONES_F2D(2433, TONES_SAMPLERATE),
    TONES_F2D(2010, TONES_SAMPLERATE),
    TONES_F2D(2292, TONES_SAMPLERATE),
    TONES_F2D(459, TONES_SAMPLERATE),
    TONES_F2D(1091, TONES_SAMPLERATE)};

const std::array<uint32_t, 16> zvei_deltas = {
    TONES_F2D(2400, TONES_SAMPLERATE),
    TONES_F2D(1060, TONES_SAMPLERATE),
    TONES_F2D(1160, TONES_SAMPLERATE),
    TONES_F2D(1270, TONES_SAMPLERATE),
    TONES_F2D(1400, TONES_SAMPLERATE),
    TONES_F2D(1530, TONES_SAMPLERATE),
    TONES_F2D(1670, TONES_SAMPLERATE),
    TONES_F2D(1830, TONES_SAMPLERATE),
    TONES_F2D(2000, TONES_SAMPLERATE),
    TONES_F2D(2200, TONES_SAMPLERATE),
    TONES_F2D(2800, TONES_SAMPLERATE),
    TONES_F2D(810, TONES_SAMPLERATE),
    TONES_F2D(970, TONES_SAMPLERATE),
    TONES_F2D(885, TONES_SAMPLERATE),
    TONES_F2D(2600, TONES_SAMPLERATE),
    TONES_F2D(680, TONES_SAMPLERATE)};

const uint32_t beep_deltas[BEEP_TONES_NB] = {
    TONES_F2D(1475, TONES_SAMPLERATE),
    TONES_F2D(740, TONES_SAMPLERATE),
    TONES_F2D(587, TONES_SAMPLERATE),
    TONES_F2D(1109, TONES_SAMPLERATE),
    TONES_F2D(831, TONES_SAMPLERATE),
    TONES_F2D(740, TONES_SAMPLERATE)};

#endif /*__TONESETS_H__*/

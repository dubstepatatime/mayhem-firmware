/*
 * Copyright (C) 2014 Jared Boone, ShareBrained Technology, Inc.
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

#include "ch.h"

#include "lpc43xx_cpp.hpp"

#include "portapack_shared_memory.hpp"
#include "portapack_dma.hpp"

#include "gpdma.hpp"
#include "audio_dma.hpp"

static void init() {
    // Audio DMA initialization was moved to baseband proc's that actually use DMA audio, to save memory.
    nvicEnableVector(DMA_IRQn, CORTEX_PRIORITY_MASK(LPC_DMA_IRQ_PRIORITY));
}

static void halt() {
    port_disable();
    while (true) {
        port_wait_for_interrupt();
    }
}

extern "C" {

void __late_init(void) {
    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *   and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *   RTOS is active.
     */
    halInit();

    /* After this call, scheduler, systick, heap, etc. are available. */
    /* By doing chSysInit() here, it runs before C++ constructors, which may
     * require the heap.
     */
    chSysInit();

    /* Baseband initialization */
    init();
}

void _default_exit(void) {
    // TODO: Is this complete?

    audio::dma::disable();

    nvicDisableVector(DMA_IRQn);

    chSysDisable();

    systick_stop();

    ShutdownMessage shutdown_message;
    shared_memory.application_queue.push(shutdown_message);

    shared_memory.baseband_message = nullptr;

    halt();
}
}

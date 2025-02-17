/*
 * Copyright 2024 Tamas Eisenberger <e.tamas@iwstudio.hu>
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

#ifndef __VIEW_FACTORY_HPP__
#define __VIEW_FACTORY_HPP__

#include "view_factory_base.hpp"

namespace ui {

template <typename T>
class ViewFactory : public ViewFactoryBase {
   public:
    virtual std::unique_ptr<View> produce(NavigationView& nav) const override {
        return std::unique_ptr<View>(new T(nav));
    }
};

}  // namespace ui

#endif  //__VIEW_FACTORY_HPP__

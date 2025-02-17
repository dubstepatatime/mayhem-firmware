#!/usr/bin/env python3

# Copyright (C) 2016 Furrtek
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

import sys
import struct
from PIL import Image
from os import listdir
from os import path

usage_message = """
1BPP PortaPack bitmap.hpp generator

Usage: <directory>
"""

if len(sys.argv) < 2:
	print(usage_message)
	sys.exit(-1)

def convert_png(file):
	c = 0
	data = 0

	im = Image.open(file)
	rgb_im = im.convert('RGBA')

	if rgb_im.size[0] % 8 or rgb_im.size[1] % 8:
		print((file + ": Size isn\'t a multiple of 8"))
		sys.exit(-1)

	name = path.basename(file).split(".")[0].lower();

	f.write("static constexpr uint8_t bitmap_" + name + "_data[] = {\n")

	for i in range(rgb_im.size[1]):
		for j in range(rgb_im.size[0]):
			r, g, b, a = rgb_im.getpixel((j, i))
			
			data >>= 1
			
			if r > 127 and g > 127 and b > 127 and a > 127:
				data += 128
			
			if j % 8 == 7:
				f.write("    0x%0.2X,\n" % data)
				data = 0

	f.write("};\n")
	f.write("static constexpr Bitmap bitmap_"  + name + "{\n")
	f.write("    {" + str(rgb_im.size[0]) + ", " + str(rgb_im.size[1]) + "},\n    bitmap_" + name+ "_data};\n\n")
	return

count = 0

f = open('bitmap.hpp', 'w')
f.write("/*\n")
f.write(" * Copyright (C) 2015 Jared Boone, ShareBrained Technology, Inc.\n")
f.write(" * Copyright (C) 2016 Furrtek\n")
f.write(" *\n")
f.write(" * This file is part of PortaPack.\n")
f.write(" *\n")
f.write(" * This program is free software; you can redistribute it and/or modify\n")
f.write(" * it under the terms of the GNU General Public License as published by\n")
f.write(" * the Free Software Foundation; either version 2, or (at your option)\n")
f.write(" * any later version.\n")
f.write(" *\n")
f.write(" * This program is distributed in the hope that it will be useful,\n")
f.write(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n")
f.write(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n")
f.write(" * GNU General Public License for more details.\n")
f.write(" *\n")
f.write(" * You should have received a copy of the GNU General Public License\n")
f.write(" * along with this program; see the file COPYING.  If not, write to\n")
f.write(" * the Free Software Foundation, Inc., 51 Franklin Street,\n")
f.write(" * Boston, MA 02110-1301, USA.\n")
f.write(" */\n\n")
f.write("// This file was generated by make_bitmap.py\n\n")
f.write("#ifndef __BITMAP_HPP__\n")
f.write("#define __BITMAP_HPP__\n\n")
f.write("#include \"ui.hpp\"\n\n")
f.write("namespace ui {\n\n")

for file in listdir(sys.argv[1]):
    if file.endswith(".png"):
        convert_png(sys.argv[1] + file)
        count += 1

f.write("} /* namespace ui */\n\n")
f.write("#endif/*__BITMAP_HPP__*/\n")

print(("Converted " + str(count) + " files"))

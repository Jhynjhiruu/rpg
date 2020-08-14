from PIL import Image
import os

os.chdir("tilemaps")

files = sorted([i for i in os.listdir() if i.endswith(".png")], key = lambda x: int(x.split(".")[0]))

filesbytes = []
filesdimensions = []

for i in files:
    img = Image.open(i).convert("RGBA")
    filesbytes.append(img.tobytes())
    filesdimensions.append(img.size)

os.chdir("..")

b = []
w = []

for i in filesbytes:
    b.append(i[:])
    w.append(i[:])

for i, j in enumerate(b):
    out = bytearray()
    bytedata = iter(j)
    for k in bytedata:
        pixel = (k, next(bytedata), next(bytedata), next(bytedata))
        if sum(pixel[0:3]) / 3 > 0xF0:
            out.append(0xFF)
        else:
            out.append(0x00)
    b[i] = bytes(out)

for i, j in enumerate(w):
    out = bytearray()
    bytedata = iter(j)
    for k in bytedata:
        pixel = (k, next(bytedata), next(bytedata), next(bytedata))
        if sum(pixel[0:3]) / 3 > 100:
            out.append(0xFF)
        else:
            out.append(0x00)
    w[i] = bytes(out)


def tilesToBytes(tiles):
    byte = bytearray()
    for i in tiles:
        byte.extend(i.transpose(Image.ROTATE_90).transpose(Image.FLIP_LEFT_RIGHT).transpose(Image.FLIP_TOP_BOTTOM).tobytes())
    return byte

bimg = []
wimg = []


for index, i in enumerate(b):
    bimg = []
    wimg = []    
    
    size = len(i) // 64
    for j in range(size):
        bimg.append([])
        wimg.append([])
    
    for j, k in enumerate(i):
        hpos = (j % filesdimensions[index][0]) // 8
        ypos = (j // filesdimensions[index][0]) // 8
        bimg[hpos + ypos * (filesdimensions[index][0] // 8)].append(k)
        wimg[hpos + ypos * (filesdimensions[index][0] // 8)].append(w[index][j])
    
    for j, k in enumerate(bimg):
        bimg[j] = Image.frombytes("L", (8, 8), bytes(k)).convert("1")
        wimg[j] = Image.frombytes("L", (8, 8), bytes(wimg[j])).convert("1")

btiles = tilesToBytes(bimg)
wtiles = tilesToBytes(wimg)

bout = []
wout = []
for i in range(len(btiles) // 8):
    bout.append("")
    
for i in range(len(wtiles) // 8):
    wout.append("")

for k, l in enumerate(btiles):
    bout[k // 8] = ", ".join([bout[k // 8], "0x" + hex(l ^ 0xFF).lstrip("0x").zfill(2).upper()]).lstrip(", ")
    
for k, l in enumerate(wtiles):
    wout[k // 8] = ", ".join([wout[k // 8], "0x" + hex(l ^ 0xFF).lstrip("0x").zfill(2).upper()]).lstrip(", ")    

for i, j in enumerate(bout):
    bout[i] = "{{\t{}\t}},".format(j)

for i, j in enumerate(wout):
    wout[i] = "{{\t{}\t}},".format(j)

fout = open("tiles.h", "w")

fout.write("""#ifndef _TILES_H
#define _TILES_H

#include "types.h"

#define NUM_TILESETS {}
#define NUM_TILES {}
#define TILE_SIZE 8

const _rom u8 tiles[NUM_TILESETS][2][NUM_TILES][TILE_SIZE] _at(0x18000) = {{
	{{
		{{\n\t\t\t""".format(len(files), len(bimg)) + "\n\t\t\t".join(bout) + """
		},
		{\n\t\t\t""" + "\n\t\t\t".join(wout) + """
		},
	},	
};

#endif""")

fout.close()
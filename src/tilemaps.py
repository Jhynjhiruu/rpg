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

numtiles = 0

for index, i in enumerate(b):
    nbimg = []
    nwimg = []    
    
    size = len(i) // 64
    
    if size > numtiles:
        numtiles = size
        
    for j in range(size):
        nbimg.append([])
        nwimg.append([])
    
    for j, k in enumerate(i):
        hpos = (j % filesdimensions[index][0]) // 8
        ypos = (j // filesdimensions[index][0]) // 8
        nbimg[hpos + ypos * (filesdimensions[index][0] // 8)].append(k)
        nwimg[hpos + ypos * (filesdimensions[index][0] // 8)].append(w[index][j])
    
    for j, k in enumerate(nbimg):
        nbimg[j] = Image.frombytes("L", (8, 8), bytes(k)).convert("1")
        nwimg[j] = Image.frombytes("L", (8, 8), bytes(nwimg[j])).convert("1")
    
    bimg.append(nbimg)
    wimg.append(nwimg)

btiles = []
wtiles = []

for i, j in enumerate(bimg):
    btiles.append(tilesToBytes(j))
    wtiles.append(tilesToBytes(wimg[i]))

bout = []
wout = []

for i in btiles:
    bout.append([])
    wout.append([])

for k, j in enumerate(btiles):
    for i in range(len(j) // 8):
        bout[k].append("")
        
for k, j in enumerate(wtiles):
    for i in range(len(j) // 8):
        wout[k].append("")

for m, n in enumerate(btiles):
    for k, l in enumerate(n):
        bout[m][k // 8] = ", ".join([bout[m][k // 8], "0x" + hex(l ^ 0xFF).lstrip("0x").zfill(2).upper()]).lstrip(", ")

for m, n in enumerate(wtiles):
    for k, l in enumerate(n):
        wout[m][k // 8] = ", ".join([wout[m][k // 8], "0x" + hex(l ^ 0xFF).lstrip("0x").zfill(2).upper()]).lstrip(", ")    

for k, l in enumerate(bout):
    for i, j in enumerate(l):
        bout[k][i] = "{{\t{}\t}},".format(j)

for k, l in enumerate(wout):
    for i, j in enumerate(l):
        wout[k][i] = "{{\t{}\t}},".format(j)

fout = open("tiles.h", "w")

buffer = """#ifndef _TILES_H
#define _TILES_H

#include "types.h"

#define NUM_TILESETS {}
#define NUM_TILES {}
#define TILE_SIZE 8

const _rom u8 tiles[NUM_TILESETS][2][NUM_TILES][TILE_SIZE] _at(0x18000) = {{""".format(len(files), numtiles)
for i, j in enumerate(bout):
    buffer += """
    {
        {\n\t\t\t"""        + "\n\t\t\t".join(j) + """
        },
        {\n\t\t\t""" + "\n\t\t\t".join(wout[i]) + """
        },
    },    """
buffer += """
};

#endif"""

fout.write(buffer)

fout.close()
from PIL import Image
import os

os.chdir("sprites")

files = sorted([i for i in os.listdir() if i.endswith(".png")], key = lambda x: int(x.split(".")[0]))

filesbytes = []

for i in files:
    filesbytes.append(Image.open(i).convert("RGBA").tobytes())

os.chdir("..")

b = []
w = []
t = []

for i in filesbytes:
    b.append(i[:])
    w.append(i[:])
    t.append(i[:])

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

for i, j in enumerate(t):
    out = bytearray()
    bytedata = iter(j)
    for k in bytedata:
        pixel = (k, next(bytedata), next(bytedata), next(bytedata))
        if pixel[3] > 10:
            out.append(0xFF)
        else:
            out.append(0x00)
    t[i] = bytes(out)
    
    
    
def tilesToBytes(tiles):
    byte = bytearray()
    for i in tiles:
        byte.extend(i.transpose(Image.ROTATE_90).transpose(Image.FLIP_LEFT_RIGHT).transpose(Image.FLIP_TOP_BOTTOM).tobytes())
    return byte


bimg = [Image.frombytes("L", (16, 16), i).convert("1") for i in b]
wimg = [Image.frombytes("L", (16, 16), i).convert("1") for i in w]
timg = [Image.frombytes("L", (16, 16), i).convert("1") for i in t]

spriteMapping = [5, 7, 1, 3, 6, 8, 2, 4]

fout = open("sprites.h", "w")

fout.write("""#ifndef _SPRITES_H
#define _SPRITES_H

#include "types.h"

""")

fout.write("""const _rom u8 sprites[2][] _at(0x10000) = {
	{
""")

for i, j in enumerate(bimg):
    tiles = []
    for k in range(4):
        tiles.append(j.crop(((k % 2) * 8, (k // 2) * 8, (k % 2) * 8 + 8, (k // 2) * 8 + 8)))
        
    for k in range(4):
        tiles.append(timg[i].crop(((k % 2) * 8, (k // 2) * 8, (k % 2) * 8 + 8, (k // 2) * 8 + 8)))
    
    spriteTiles = [tiles[k - 1] for k in spriteMapping]
    data = tilesToBytes(spriteTiles)
    out = []
    for k in range(len(data) // 8):
        out.append("")
    for k, l in enumerate(data):
        out[k // 8] = ", ".join([out[k // 8], "0x" + hex(l ^ 0xFF).lstrip("0x").zfill(2).upper()]).lstrip(", ")
    fout.write("\t\t" + ",\n\t\t".join(out) + ",\n")
fout.write("""	},
	{
""")
for i, j in enumerate(wimg):
    tiles = []
    for k in range(4):
        tiles.append(j.crop(((k % 2) * 8, (k // 2) * 8, (k % 2) * 8 + 8, (k // 2) * 8 + 8)))
        
    for k in range(4):
        tiles.append(timg[i].crop(((k % 2) * 8, (k // 2) * 8, (k % 2) * 8 + 8, (k // 2) * 8 + 8)))
    
    spriteTiles = [tiles[k - 1] for k in spriteMapping]
    data = tilesToBytes(spriteTiles)
    out = []
    for k in range(len(data) // 8):
        out.append("")
    for k, l in enumerate(data):
        out[k // 8] = ", ".join([out[k // 8], "0x" + hex(l ^ 0xFF).lstrip("0x").zfill(2).upper()]).lstrip(", ")
    fout.write("\t\t" + ",\n\t\t".join(out) + ",\n")

fout.write("""
	}
};

#endif""")

fout.close()
; function for dealing with overworld stuff

GLOBAL _check_tile_attr

DEFSECT ".overworld_asm", CODE
SECT ".overworld_asm"

_check_tile_attr: ; u8 check_tile_attr(overworldTile _rom * tiles -> IY, u8 index -> A, u8 mask -> L)
    PUSH B
    PUSH HL
    LD B, #0
    LD HL, #1360h
    ADD HL, BA
    LD A, [HL] ; u8 dat = TILEMAP[index]
    LD L, #4
    MLT
    ADD IY, HL
    POP HL
    LD A, [IY]
    LD B, L
    AND A, B ; u8 rv = tiles[dat] & mask
    POP B
    RET

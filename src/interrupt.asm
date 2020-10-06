; call interrupt and get return value

GLOBAL _set_default_contrast
GLOBAL _adjust_contrast
GLOBAL _apply_default_contrast
GLOBAL _get_default_contrast
GLOBAL _set_contrast

DEFSECT ".call_interrupts", CODE
SECT ".call_interrupts"

_set_default_contrast:
    AND A, #3Fh    ; 0-40h
    INT [4Ch]
    RET
    
_adjust_contrast:
    CP A, #0    ; interrupt decreases contrast if zero flag is set,
    INT [4Eh]    ; increases contrast if not set
    RET

_apply_default_contrast:
    INT [50h]
    RET

_get_default_contrast:
    INT [52h]
    RET

_set_contrast:
    AND A, #3Fh    ; 0-40h
    INT [54h]
    RET
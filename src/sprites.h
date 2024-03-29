#ifndef _SPRITES_H
#define _SPRITES_H

#include "types.h"

const _rom u8 sprites[2][] _at(0x10000) = {
    {
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x30, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xFF, 0xFB, 0xFB, 0xFB,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x80, 0x80, 0x80, 0x90, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xFB, 0xFB, 0xFF, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0xE5, 0x80, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFB,
		0x00, 0x01, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
		0x1F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x01, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE5, 0xFF, 0xFF,
		0x00, 0x00, 0x98, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0xF0, 0x30, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF9, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x80, 0x80, 0x80, 0x90, 0xF0, 0xF9, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFF, 0xF1, 0xC0, 0x80, 0x80, 0x80,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xF7, 0xFA, 0xFA,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x90, 0xF8, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFA, 0xFA, 0xFB, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xCB, 0x01, 0x01, 0x01, 0x01, 0x01,
		0xFF, 0xFF, 0xFF, 0x89, 0x80, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFD, 0xFF, 0xF6,
		0x01, 0x03, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x00, 0x03, 0x8F, 0xFF, 0xFF,
		0x3F, 0xDF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF6, 0xF6, 0xFE, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x03, 0x01,
		0xFF, 0xFF, 0x8F, 0x03, 0x00, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xDF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFE, 0xF6, 0xF6,
		0x01, 0x01, 0x01, 0x01, 0x01, 0xCB, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x80, 0x89, 0xFF, 0xFF, 0xFF,
		0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF6, 0xFF, 0xFD, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFC, 0xC0, 0x80, 0x80, 0xC0, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x30, 0xF0, 0xFB, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xF9, 0xFB, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x90, 0x80, 0x80, 0x80, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xFF, 0xFB, 0xFB, 0xFB,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x30, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xFB, 0xFB, 0xFF, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0xE5, 0x80, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFB,
		0x00, 0x01, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
		0x1F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x01, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE5, 0xFF, 0xFF,
		0x00, 0x00, 0x98, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x90, 0x80, 0x80, 0x80, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF9, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x30, 0xF0, 0xF0, 0xF9, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xF8, 0x90, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFB, 0xFA, 0xFA,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0x80, 0x80, 0x80, 0xC0, 0xF1, 0xFF, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFA, 0xFA, 0xF7, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xCB, 0x01, 0x01, 0x01, 0x01, 0x01,
		0xFF, 0xFF, 0xFF, 0x89, 0x80, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFE,
		0x01, 0x03, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x00, 0x09, 0x8F, 0xFF, 0xFF,
		0x3F, 0xDF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFE, 0xFA, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x03, 0x01,
		0xFF, 0xFF, 0x8F, 0x09, 0x00, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xDF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFA, 0xFE, 0xFE,
		0x01, 0x01, 0x01, 0x01, 0x01, 0xCB, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x80, 0x89, 0xFF, 0xFF, 0xFF,
		0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFB, 0xF0, 0x30, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFB, 0xF9, 0xFF, 0xFF, 0xFF,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xE0, 0xC0, 0x80, 0x80, 0xC0, 0xFC, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF3, 0xE1, 0x20, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF3, 0xF5, 0xFF, 0xFB, 0xFB, 0xFB,
		0x01, 0x00, 0x00, 0x00, 0x80, 0xD5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x20, 0xE1, 0xF3, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xFB, 0xFB, 0xFF, 0xF5, 0xF3, 0xFF, 0xFF,
		0xFF, 0xFF, 0xE5, 0x80, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xE0, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xF7, 0xFB,
		0x00, 0x01, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x1F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x01, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x30, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFB,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE5, 0xFF, 0xFF,
		0x00, 0x00, 0xE0, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xF7, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF3, 0xE1, 0x20, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF3, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF,
		0x01, 0x00, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x20, 0xE1, 0xF3, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xF3, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0x01, 0xFD, 0x85, 0x85, 0xFD, 0x01, 0x01,
		0xFF, 0x80, 0xBF, 0x80, 0x80, 0x80, 0x80, 0x80,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x09, 0x05, 0xFD, 0x01, 0x01, 0x01, 0xFF,
		0x80, 0xA0, 0xA0, 0xBF, 0xA0, 0xA0, 0x80, 0xFF,
		0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x3F, 0x3F, 0x3F,
		0xFF, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
		0x00, 0x00, 0xE0, 0xA0, 0x00, 0x80, 0x00, 0x80,
		0x00, 0x00, 0x07, 0x04, 0x00, 0x04, 0x03, 0x04,
		0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x3F, 0xFF,
		0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF,
		0x00, 0x80, 0x00, 0x00, 0xC0, 0x80, 0x00, 0x00,
		0x00, 0x06, 0x04, 0x00, 0x07, 0x04, 0x00, 0x00,
    },
    {
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x30, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xBC, 0xB0, 0xF1, 0xF1,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x80, 0x80, 0x80, 0x90, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xF9, 0xD8, 0xDC, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0xE5, 0x80, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0x9B,
		0x00, 0x01, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
		0x1F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xBD, 0xF1, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x01, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xF1, 0xBD,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE5, 0xFF, 0xFF,
		0x00, 0x00, 0x98, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x9B, 0x98, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0xF0, 0x30, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF9, 0xFA, 0xFC, 0xB0, 0xB0, 0xF0,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x80, 0x80, 0x80, 0x90, 0xF0, 0xF9, 0xFF,
		0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF0, 0xF0, 0xD0, 0xDC, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFF, 0xF1, 0xC0, 0x80, 0x80, 0x80,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xF5, 0xFA, 0xF2,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x90, 0xF8, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF2, 0xF2, 0xB1, 0x9D, 0xFA, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xCB, 0x01, 0x01, 0x01, 0x01, 0x01,
		0xFF, 0xFF, 0xFF, 0x89, 0x80, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xC9, 0xFD, 0xFD, 0xE2,
		0x01, 0x03, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x00, 0x03, 0x8F, 0xFF, 0xFF,
		0x3F, 0xDF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xE2, 0xF2, 0xFE, 0xBB, 0x9F, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x03, 0x01,
		0xFF, 0xFF, 0x8F, 0x03, 0x00, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xDF, 0x3F,
		0xFF, 0xFF, 0xFF, 0x9F, 0xBB, 0xFE, 0xF2, 0xE2,
		0x01, 0x01, 0x01, 0x01, 0x01, 0xCB, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x80, 0x89, 0xFF, 0xFF, 0xFF,
		0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xE2, 0xFD, 0xFD, 0xC9, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFC, 0xC0, 0x80, 0x80, 0xC0, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFC, 0xCE, 0xC8, 0xF9, 0xF1,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x30, 0xF0, 0xFB, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xB1, 0xBE, 0xF8, 0xFB, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x90, 0x80, 0x80, 0x80, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xDC, 0xD8, 0xF9, 0xF1,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x30, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xF1, 0xB0, 0xBC, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0xE5, 0x80, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0xFB,
		0x00, 0x01, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
		0x1F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xBD, 0xB1, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x01, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xB1, 0xBD,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE5, 0xFF, 0xFF,
		0x00, 0x00, 0x98, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0x98, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x90, 0x80, 0x80, 0x80, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF9, 0xFA, 0xDC, 0xD0, 0xF0, 0xF0,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x30, 0xF0, 0xF0, 0xF9, 0xFF,
		0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF0, 0xB0, 0xB0, 0xFC, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xF8, 0x90, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFA, 0x9D, 0xB1, 0xF2, 0xF2,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0x80, 0x80, 0x80, 0xC0, 0xF1, 0xFF, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF2, 0xFA, 0xF5, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xCB, 0x01, 0x01, 0x01, 0x01, 0x01,
		0xFF, 0xFF, 0xFF, 0x89, 0x80, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xC9, 0xFF, 0xF1, 0xE2,
		0x01, 0x03, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x00, 0x09, 0x8F, 0xFF, 0xFF,
		0x3F, 0xDF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xE2, 0xF2, 0xFA, 0xB9, 0x9F, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x03, 0x01,
		0xFF, 0xFF, 0x8F, 0x09, 0x00, 0x80, 0xC0, 0xC0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xDF, 0x3F,
		0xFF, 0xFF, 0xFF, 0x9F, 0xB9, 0xFA, 0xF2, 0xE2,
		0x01, 0x01, 0x01, 0x01, 0x01, 0xCB, 0xFF, 0xFF,
		0xC0, 0xC0, 0x80, 0x80, 0x89, 0xFF, 0xFF, 0xFF,
		0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xE2, 0xF1, 0xFF, 0xC9, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFB, 0xF0, 0x30, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFB, 0xF8, 0xBE, 0xB1, 0xF1,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xE0, 0xC0, 0x80, 0x80, 0xC0, 0xFC, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xF9, 0xC8, 0xCE, 0xFC, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF3, 0xE1, 0x20, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF3, 0xF5, 0xBC, 0xB0, 0xF1, 0xF1,
		0x01, 0x00, 0x00, 0x00, 0x80, 0xD5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x20, 0xE1, 0xF3, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xF1, 0xB0, 0xBC, 0xF5, 0xF3, 0xFF, 0xFF,
		0xFF, 0xFF, 0xE5, 0x80, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xE0, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xF4, 0xB9,
		0x00, 0x01, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0x00, 0x00, 0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x1F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xB1, 0xB1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x01, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x30, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB1, 0xB1,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE5, 0xFF, 0xFF,
		0x00, 0x00, 0xE0, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xB9, 0xF4, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x80, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF3, 0xE1, 0x20, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xF3, 0xF5, 0xBC, 0xB0, 0xF0, 0xF0,
		0x01, 0x00, 0x00, 0x00, 0x80, 0xC5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x20, 0xE1, 0xF3, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF0, 0xF0, 0xB0, 0xBC, 0xF5, 0xF3, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0x01, 0xFD, 0x85, 0x85, 0xFD, 0x01, 0x01,
		0xFF, 0x80, 0xBF, 0x80, 0x80, 0x80, 0x80, 0x80,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x09, 0x05, 0xFD, 0x01, 0x01, 0x01, 0xFF,
		0x80, 0xA0, 0xA0, 0xBF, 0xA0, 0xA0, 0x80, 0xFF,
		0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x3F, 0x3F, 0x3F,
		0xFF, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
		0x00, 0x00, 0xE0, 0xA0, 0x00, 0x80, 0x00, 0x80,
		0x00, 0x00, 0x07, 0x04, 0x00, 0x04, 0x03, 0x04,
		0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x3F, 0xFF,
		0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF,
		0x00, 0x80, 0x00, 0x00, 0xC0, 0x80, 0x00, 0x00,
		0x00, 0x06, 0x04, 0x00, 0x07, 0x04, 0x00, 0x00,

    }
};

#endif
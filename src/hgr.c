#define VHEIGHT 192  // number of scanlines
#define VBWIDTH 40   // number of  unsigned chars per scanline
#define PIXWIDTH 280 // 7 pixels per  unsigned char

#define LUT(x) (unsigned char *)(0x2000 | x)

// starting address of each scanline
static unsigned char *const vidmem[VHEIGHT] = {
    LUT(0x0000), LUT(0x0400), LUT(0x0800), LUT(0x0c00), LUT(0x1000), LUT(0x1400), LUT(0x1800), LUT(0x1c00),
    LUT(0x0080), LUT(0x0480), LUT(0x0880), LUT(0x0c80), LUT(0x1080), LUT(0x1480), LUT(0x1880), LUT(0x1c80),
    LUT(0x0100), LUT(0x0500), LUT(0x0900), LUT(0x0d00), LUT(0x1100), LUT(0x1500), LUT(0x1900), LUT(0x1d00),
    LUT(0x0180), LUT(0x0580), LUT(0x0980), LUT(0x0d80), LUT(0x1180), LUT(0x1580), LUT(0x1980), LUT(0x1d80),
    LUT(0x0200), LUT(0x0600), LUT(0x0a00), LUT(0x0e00), LUT(0x1200), LUT(0x1600), LUT(0x1a00), LUT(0x1e00),
    LUT(0x0280), LUT(0x0680), LUT(0x0a80), LUT(0x0e80), LUT(0x1280), LUT(0x1680), LUT(0x1a80), LUT(0x1e80),
    LUT(0x0300), LUT(0x0700), LUT(0x0b00), LUT(0x0f00), LUT(0x1300), LUT(0x1700), LUT(0x1b00), LUT(0x1f00),
    LUT(0x0380), LUT(0x0780), LUT(0x0b80), LUT(0x0f80), LUT(0x1380), LUT(0x1780), LUT(0x1b80), LUT(0x1f80),
    LUT(0x0028), LUT(0x0428), LUT(0x0828), LUT(0x0c28), LUT(0x1028), LUT(0x1428), LUT(0x1828), LUT(0x1c28),
    LUT(0x00a8), LUT(0x04a8), LUT(0x08a8), LUT(0x0ca8), LUT(0x10a8), LUT(0x14a8), LUT(0x18a8), LUT(0x1ca8),
    LUT(0x0128), LUT(0x0528), LUT(0x0928), LUT(0x0d28), LUT(0x1128), LUT(0x1528), LUT(0x1928), LUT(0x1d28),
    LUT(0x01a8), LUT(0x05a8), LUT(0x09a8), LUT(0x0da8), LUT(0x11a8), LUT(0x15a8), LUT(0x19a8), LUT(0x1da8),
    LUT(0x0228), LUT(0x0628), LUT(0x0a28), LUT(0x0e28), LUT(0x1228), LUT(0x1628), LUT(0x1a28), LUT(0x1e28),
    LUT(0x02a8), LUT(0x06a8), LUT(0x0aa8), LUT(0x0ea8), LUT(0x12a8), LUT(0x16a8), LUT(0x1aa8), LUT(0x1ea8),
    LUT(0x0328), LUT(0x0728), LUT(0x0b28), LUT(0x0f28), LUT(0x1328), LUT(0x1728), LUT(0x1b28), LUT(0x1f28),
    LUT(0x03a8), LUT(0x07a8), LUT(0x0ba8), LUT(0x0fa8), LUT(0x13a8), LUT(0x17a8), LUT(0x1ba8), LUT(0x1fa8),
    LUT(0x0050), LUT(0x0450), LUT(0x0850), LUT(0x0c50), LUT(0x1050), LUT(0x1450), LUT(0x1850), LUT(0x1c50),
    LUT(0x00d0), LUT(0x04d0), LUT(0x08d0), LUT(0x0cd0), LUT(0x10d0), LUT(0x14d0), LUT(0x18d0), LUT(0x1cd0),
    LUT(0x0150), LUT(0x0550), LUT(0x0950), LUT(0x0d50), LUT(0x1150), LUT(0x1550), LUT(0x1950), LUT(0x1d50),
    LUT(0x01d0), LUT(0x05d0), LUT(0x09d0), LUT(0x0dd0), LUT(0x11d0), LUT(0x15d0), LUT(0x19d0), LUT(0x1dd0),
    LUT(0x0250), LUT(0x0650), LUT(0x0a50), LUT(0x0e50), LUT(0x1250), LUT(0x1650), LUT(0x1a50), LUT(0x1e50),
    LUT(0x02d0), LUT(0x06d0), LUT(0x0ad0), LUT(0x0ed0), LUT(0x12d0), LUT(0x16d0), LUT(0x1ad0), LUT(0x1ed0),
    LUT(0x0350), LUT(0x0750), LUT(0x0b50), LUT(0x0f50), LUT(0x1350), LUT(0x1750), LUT(0x1b50), LUT(0x1f50),
    LUT(0x03d0), LUT(0x07d0), LUT(0x0bd0), LUT(0x0fd0), LUT(0x13d0), LUT(0x17d0), LUT(0x1bd0), LUT(0x1fd0)};

// divide-by 7 table
const unsigned char DIV7[256] = {
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
    4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9,
    9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13,
    13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 18, 18,
    18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22,
    22, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27,
    27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31,
    32, 32, 32, 32, 32, 32, 32, 33, 33, 33, 33, 33, 33, 33, 34, 34, 34, 34, 34, 34, 34, 35, 35, 35, 35, 35, 35, 35, 36, 36, 36, 36};

// modulo-by-7 table
const unsigned char MOD7[256] = {
    0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3,
    4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0,
    1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4,
    5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1,
    2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5,
    6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2,
    3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6,
    0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3};

// bitmask table
const unsigned char BIT7[7] = {1, 2, 4, 8, 16, 32, 64};

// clear screen and set graphics mode
void hgr()
{
  STROBE(0xc052);                             // turn off mixed-mode
  STROBE(0xc054);                             // page 1
  STROBE(0xc057);                             // hi-res
  STROBE(0xc050);                             // set graphics mode
  memset((unsigned char *)0x2000, 0, 0x2000); // clear page 1
}

// draw (xor) vertical line
void xor_vline(unsigned char x, unsigned char y1, unsigned char y2)
{
  unsigned char xb = DIV7[x];         // divide x by 7
  unsigned char mask = BIT7[MOD7[x]]; // lookup bitmask for remainder
  unsigned char y;
  for (y = y1; y <= y2; y++)
  {
    unsigned char *dest = &vidmem[y][xb]; // lookup dest. address
    *dest ^= mask;                        // XOR mask with destination
  }
}

// draw (xor) a pixel
void xor_pixel(unsigned char x, unsigned char y)
{
  xor_vline(x, y, y); // draw line with 1-pixel height
}

typedef enum
{
  OP_DRAW,
  OP_XOR,
  OP_ERASE
} GraphicsOperation;

// render a sprite with the given graphics operation
unsigned char render_sprite(const unsigned char *src, unsigned char x, unsigned char y, unsigned char op)
{
  unsigned char i, j;
  unsigned char w = *src++;   // get width from 1st  unsigned char of sprite
  unsigned char h = *src++;   // get height from 2nd  unsigned char of sprite
  unsigned char xb = DIV7[x]; // xb = x DIV 7
  unsigned char xs = MOD7[x]; // xs = x MOD 7
  unsigned char result = 0;   // result (used only with XOR)
  for (j = 0; j < h; j++)
  {
    unsigned char *dest = &vidmem[y++][xb]; // lookup video address
    unsigned char rest = 0;                 // rest = leftover bits
    for (i = 0; i < w; i++)
    {
      unsigned char data = *src++;              // get next sprite  unsigned char
      unsigned char next = (data << xs) | rest; // shift and OR with leftover
      // compute graphics operation, write to dest
      switch (op)
      {
      case OP_DRAW:
        *dest++ = next;
        break;
      case OP_XOR:
        result |= (*dest++ ^= next) & next;
        break;
      case OP_ERASE:
        *dest++ &= ~next;
        break;
      }
      rest = data >> (7 - xs); // save leftover bits
    }
    // compute final  unsigned char operation
    switch (op)
    {
    case OP_DRAW:
      *dest = rest;
      break;
    case OP_XOR:
      result |= (*dest ^= rest) & rest;
      break;
    case OP_ERASE:
      *dest &= ~rest;
      break;
    }
  }
  return result;
}

void draw_sprite(const unsigned char *src, unsigned char x, unsigned char y)
{
  render_sprite(src, x, y, OP_DRAW);
}

// XOR returns non-zero if any pixels were overlapped
unsigned char xor_sprite(const unsigned char *src, unsigned char x, unsigned char y)
{
  return render_sprite(src, x, y, OP_XOR);
}

void erase_sprite(const unsigned char *src, unsigned char x, unsigned char y)
{
  render_sprite(src, x, y, OP_ERASE);
}

// clear just sets all  unsigned chars to 0, and is fast
void clear_sprite(const unsigned char *src, unsigned char x, unsigned char y)
{
  unsigned char i, j;
  unsigned char w = *src++;
  unsigned char h = *src++;
  unsigned char xb = DIV7[x];
  for (j = 0; j < h; j++)
  {
    unsigned char *dest = &vidmem[y++][xb];
    for (i = 0; i <= w; i++)
    {
      dest[i] = 0;
    }
  }
}
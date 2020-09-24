#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "common.c"
#include "sounds.c"
#include "hgr.c"
#include "fonts.c"
#include "bg.c"


void introText();

const unsigned char lem_bitmap[] =
    {2, 13, /*{w:16,h:13,bpp:1}*/ 0xC0, 0x03, 0x30, 0x0C, 0x48, 0x10, 0x28, 0x10, 0x08, 0x10, 0x30, 0x0C, 0xC0, 0x03, 0x3C, 0x3C, 0xE0, 0x07, 0x10, 0x08, 0xE8, 0x17, 0x04, 0x20, 0x0E, 0x70};

const unsigned char landing_bitmap[] =
    {3, 5, /*{w:24,h:5,bpp:1}*/ 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x3F, 0xFE, 0xFF, 0x7F, 0x66, 0x7E, 0x66, 0x02, 0x00, 0x40};

int main(void)
{
  unsigned char i, k, state, lnd_x;

  signed int dx, dy;

  signed int x, y, ox, oy;

  // tone(10, 220, 20);

  srand(100);

  while (1)
  {
    hgr();

    memcpy(0x2000, src_bg_bin, src_bg_bin_len);
    introText();

    get();

    memcpy(0x2000, src_bg_bin, src_bg_bin_len);

    lnd_x = (rand() % 170 + 20) * 16;

    render_sprite(landing_bitmap, lnd_x, 180, OP_DRAW);

    x = (rand() % 170 + 10) * 16;
    y = 0;
    dx = 0;
    dy = 0;
    ox = x;
    oy = y;

    state = 0;

    render_sprite(lem_bitmap, x / 16, y / 16, OP_XOR);
    while (1)
    {
      k = key();

      if (k == 'Z')
      {
        dx -= 5 + rand() % 20;
        tone(20, 2, 1);
      }
      if (k == 'X')
      {
        dx += 5 + rand() % 20;
        tone(20, 2, 1);
      }

      if (k == 'M')
      {
        dy -= 10;
        tone(20, 2, 1);
      }

      dy += 2;

      y += dy;
      x += dx;

      if (y < 0)
      {
        y = 0;
      }
      if (x < 0)
      {
        x = 0;
        dx = 0;
      }
      if (x > 250 * 16)
      {
        x = 250 * 16;
        dx = 0;
      }

      render_sprite(lem_bitmap, ox / 16, oy / 16, OP_XOR);
      render_sprite(lem_bitmap, x / 16, y / 16, OP_XOR);

      ox = x;
      oy = y;

      if (x / 16 > lnd_x && x / 16 < lnd_x + 26 && y / 16 == 168 && dy < 30)
      {
        state = 1;
        break;
      }

      if (y / 16 > 190)
      {
        state = 0;
        break;
      }
    }

    if (state == 1)
    {
      draw_string("Mission Success!", 12, 10, 0, 1);
      tone(20, 40, 6);
    }
    else
    {
      draw_string("Mission Failure!", 12, 10, 0, 1);
      tone(200, 40, 6);
    }
    wait(200);
    get();
  }

  return EXIT_SUCCESS;
}

void introText()
{
  draw_string("LUNAR MISSION", 13, 3, 0, 1);
  draw_string("Hello Commander. Your mission is to", 3, 8, 0, 0);
  draw_string("successfully land the LEM*.", 3, 9, 0, 0);
  draw_string("Landing should be smooth and soft.", 3, 10, 0, 0);
  draw_string("Test your piloting skills.", 3, 12, 0, 0);
  draw_string("Control the LEM with:", 3, 14, 0, 0);
  draw_string("Z-LEFT X-RIGHT M-UP ", 3, 15, 0, 0);
  draw_string("*LEM - Lunar (Excursion) Module", 3, 18, 0, 0);
}
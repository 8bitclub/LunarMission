
#define STROBE(addr)       __asm__ ("sta %w", addr)

#define CLICK STROBE(0xc030)

void tone(unsigned char period, unsigned char dur, signed char mod) {
  unsigned short i;
  while (dur--) {
    for (i=0; i<period; i++) ;
    CLICK;
    period += mod;
  }
}
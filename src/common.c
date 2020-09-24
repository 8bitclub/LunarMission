#define get() (cgetc())

char key()
{
    unsigned char ch;
    ch = 0;

    if (kbhit())
    {
        ch = cgetc();
    }

    return ch;
}

void wait(unsigned char count) {
  while (count--) {
    unsigned short i;
    for (i=0; i<200; i++) ;
  }
}
#include <stdio.h>


int main(int argc, int * argv[])
{
  int n = 1;
  // little endian if true - ACCORDING TO:
  // https://stackoverflow.com/questions/4181951/how-to-check-whether-a-system-is-big-endian-or-little-endian

  if (*(char *) &n == 1)
  {
    printf("Little endian system\n");
  }
  else
  {
    printf("Big endian system\n");
  }

  return 0;
}

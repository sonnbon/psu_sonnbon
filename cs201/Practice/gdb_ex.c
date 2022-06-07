#include <stdio.h>

void sub(int i);
void sub2(int j);



int main(int argc, char **argv)
{
  int x;
  x = 30;
  sub2(x);
  x = 90;
  sub2(x);
  sub(3);
  printf("%s %d\n", argv[0], argc);
  return(0);
}



void sub(int i)
{
  char here[900];
  sprintf((char *)here, "Function %s in %s", __FUNCTION__, __FILE__);
  printf("%s @ line %d\n", here, __LINE__);
}



void sub2(int j)
{
  printf("%d\n", j);
}

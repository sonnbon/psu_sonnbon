#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_midrev.h"


void swap(int *a, int *b);


int main(int argc, char *argv[])
{
  //Sizeof types
  printf("char        : %lu bytes\n", sizeof(char));
  printf("short       : %lu bytes\n", sizeof(short));
  printf("int         : %lu bytes\n", sizeof(int));
  printf("long        : %lu bytes\n", sizeof(long));
  printf("unsigned int: %lu bytes\n", sizeof(unsigned int));
  printf("float       : %lu bytes\n", sizeof(float));
  printf("double      : %lu bytes\n", sizeof(double));

  printf("\n\n");

  char ch = 'j';
  printf("%c\n", ch);

  char *chs = "abc";
  printf("%s\n", chs);

  printf("\n\n");

  int ar[100];
  printf("array size : %ld bytes\n", sizeof(ar));

  printf("\n\n");

  char str[10] = "Hello";
  char strs[] = "Hello";
  printf("str[10] size : %ld bytes\n", sizeof(str));  //Should be 10 bytes
  printf("strs[] size  : %ld bytes\n", sizeof(strs)); //Should be 6 bytes (includes the \0 as a char)

  printf("\n\n");

  int length = strlen(strs);
  printf("strs length = %d\n", length);

  printf("\n\n");

  name_t my_name;
  strcpy(my_name.given_name, "James");
  strcpy(my_name.family_name, "BW");

  printf("My name is %s %s\n", my_name.given_name, my_name.family_name);

  printf("\n\n");

  char *test;
  int *test2;

  printf("char* size: %ld bytes\n", sizeof(test));
  printf("int* size: %ld bytes\n", sizeof(test2));

  printf("\n\n");

  int *int_ptr = &length;

  printf("int_ptr address = %p\n", int_ptr);
  printf("int_ptr         = %d\n", *int_ptr);

  printf("\n\n");

  char *cp_ptr = "abcdefghijklmnop";
  int *int_ptr2 = ar;

  printf("cp_ptr start: %p\n", cp_ptr++);
  printf("cp_ptr incremented: %p\n", cp_ptr);

  printf("\n\n");

  printf("int_ptr2 start: %p\n", int_ptr2++);
  printf("int_ptr2 incremented: %p\n", int_ptr2);

  printf("\n\n");

  int x = 7;
  int y = 19;

  swap(&x, &y);

  printf("x = %d and y = %d\n", x, y);

  printf("\n\n");

  int g;
  scanf("%d", &g);
  printf("%d\n", g);

  printf("\n\n");

  char *ch_ptr3 = malloc(21 * sizeof(char));
    
  scanf("%20s", ch_ptr3);
  printf("%s\n", ch_ptr3);

  free(ch_ptr3);

  printf("\n\n");

  char str8[] = "gorksforgeeks";
  printf("%30s\n", str8);
  printf("%-10s\n", str8);
  printf("%10.7s\n", str8);
  printf("%-10.5s\n", str8);

  printf("\n\n");

  unsigned int test_int = 4;
  unsigned int test_int2 = 894;

  printf("test_u1: %091u\n", test_int);
  printf("test_u2: %091u\n", test_int2);

  printf("\n\n");

  comp_name_t company;

  int s1 = sizeof(struct comp_name_s);
  int s2 = sizeof(company);
  int s3 = sizeof(&company);

  printf("%d\n", s1);
  printf("%d\n", s2);
  printf("%d\n", s3);

  return 0;
}


void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}



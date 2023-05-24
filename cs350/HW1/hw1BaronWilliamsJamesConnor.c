#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#define M 100000000

// ----------------------------------------------------------------------------
// Author: James Connor Baron-Williams
// Course: CS350
// Assignment: HW1
// Due Date: January 18, 2023
// ----------------------------------------------------------------------------


// 100 million
int x[M] ;
int N ;



void print_array(int lo, int hi)
{
  int i ;
  for(i=lo;i<=hi;i++) {
    printf("(%d %d) ",i,x[i]) ;
  }
  printf("\n") ;
}



void create_array_gap_at_least_two() 
{
  int i ;
  int d ;
  srandom(300) ; // nothing special about 300
  x[0] = abs(random()) % 100 ;
  for(i=1;i<N;i++) {
      //      d = abs(random()) % 10 ; // non-decreasing
      //      d = 1 + abs(random()) % 10 ; // strictly increasing
      d = 2 + abs(random()) % 10 ; // strictly increasing and gap of at least 2
      x[i] = x[i-1] + d ;
  }
}



int linear_search(int lo, int hi, int key)
// if key is found in the array, return the location, otherwise return -1
{
    //From the beginning of the array, search each element incrementally.
    for (int i = lo; i < hi; ++i)
    {
      if (key == x[i])
          return i;
    }

    return -1;
}



int binary_search(int lo, int hi, int key)
// if key is found in the array, return the location, otherwise return -1  
{
    int mid = 0;

    //Base case: If there is only one element left or hi ended up less than low
    if (lo >= hi)
    {
        //If there is only one element left, check for a match.
        if (key == x[lo])
            return lo;

        return -1;
    }

    mid = (hi + lo) / 2; //Set mid to average of hi and lo

    if (key == x[mid])
        return mid;

    //If the key is less than the mid element, search the lower half.
    if (key < x[mid])
        return binary_search(lo, mid - 1, key);

    //Otherwise, search the upper half of the array.
    return binary_search(mid + 1, hi, key);
}



int non_recursive_binary_search(int lo, int hi, int key)
// if key is found in the array, return the location, otherwise return -1  
{
    int mid = 0;

    //While lo is not greater than hi, the list is still searchable.
    while (lo <= hi)
    {
        mid = (hi + lo) / 2; //Set mid to the average of hi and lo
        
        if (key == x[mid])
            return mid;

        //If the key is less than the mid element, set hi to one less than mid
        //to allow for searching the lower half of the array.
        if (key < x[mid])
            hi = mid - 1;

        //Otherwise, set lo to one more than mid to allow for searching the 
        //upper half of the array.
        else
            lo = mid + 1;
    }

    return -1;
}



// begin TIMING variables
int signal ;
struct timeval Tp;
struct timezone Tzp ;
long sec,usec ;
double dsec1, dsec2 ;



// end TIMING variables
void begin_timing()
{
  signal = gettimeofday(&Tp,&Tzp) ;
  usec = Tp.tv_usec ;
  sec = Tp.tv_sec ;
  dsec1 = sec + usec/1000000.0 ;
}



void end_timing()
{
  signal = gettimeofday(&Tp,&Tzp) ;
  usec = Tp.tv_usec ;
  sec = Tp.tv_sec ;
  dsec2 = sec + usec/1000000.0 ;
}



int test01(int size)
{
  int res,key,i ;
  unsigned long a ;
  int numdisagreements ;
  if (size > M) {
    printf("size request of %d is too big\n", size) ;
  }
  N = size ;
  create_array_gap_at_least_two()    ;
  //  print_array(0,100) ;
  
  int numreps = 100 ;
  int keyA[1000],locA[1000] ;
  int keyB[1000],locB[1000] ;
  int keyC[1000],locC[1000] ;
  
  printf("numreps = %d\n",numreps) ;
  
  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  
  
  //======================================================================
  printf("Testing searches for items that DO exist :\n") ;    
  //======================================================================

  begin_timing() ;
  srandom(100) ;

  for (i = 0 ; i < numreps ; i++) {
    a = random() % N ;
    // printf("{%lu}",a) ;
    key = x[a] ; // so these items WILL be found   
    keyA[i] = key ;    
    locA[i] = linear_search(0,N-1,key) ;
  }

  end_timing() ;
  printf("Average Linear search of %d items took %18lf seconds.\n",
          N, (dsec2 - dsec1)/numreps) ;
  //======================================================================
  
  begin_timing() ;
  srandom(100) ;
  for (i = 0 ; i < numreps ; i++) {
    a = random() % N ;    
    key = x[a] ; // so these items WILL be found       
    keyB[i] = key ;
    locB[i] = binary_search(0,N-1,key) ;
  }

  end_timing() ;
  printf("Average Binary search of %d items took %18lf seconds.\n",
  N, (dsec2 - dsec1)/numreps) ;  
  //======================================================================
  
  begin_timing() ;
  srandom(100) ;  
  for (i = 0 ; i < numreps ; i++) {
    a = random() % N ;
    key = x[a] ; // so these items WILL be found
    keyC[i] = key ;
    locC[i] = non_recursive_binary_search(0,N-1,key) ;
  }

  end_timing() ;
  printf("Average Non-Recursive Binary search of %d items took %18lf seconds.\n",
         N, (dsec2 - dsec1)/numreps) ;  
  
  //======================================================================
  
  numdisagreements = 0 ;
  for (i = 0 ; i < numreps ; i++) {
    if (locA[i] != locB[i]) {
      printf("[%d,%d]   [%d,%d]\n",locA[i],keyA[i],locB[i],keyB[i]) ;
      numdisagreements++ ;
    }
  }

  printf("numdisagreements between linear and binary search = %d\n",
 numdisagreements) ;
  
  numdisagreements = 0 ;
  for (i = 0 ; i < numreps ; i++) {
    if (locA[i] != locC[i]) {
      printf("[%d,%d]   [%d,%d]\n",locA[i],keyA[i],locC[i],keyC[i]) ;
      numdisagreements++ ;
    }
  }

  printf("numdisagreements between linear and non-recursive binary search = %d\n",
 numdisagreements) ;      
  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  
  //======================================================================
  printf("Testing searches for items that do NOT exist :\n") ;  
  //======================================================================
  
  begin_timing() ;
  srandom(100) ;
  for (i = 0 ; i < numreps ; i++) {
    a = random() % N ;
    // printf("{%lu}",a) ;
    key = x[a] + 1 ; 
           // so these items will NOT be found given a gapping >= 2
    keyA[i] = key ;    
    locA[i] = linear_search(0,N-1,key) ;
  }

  end_timing() ;
  printf("Average Linear search of %d items took %18lf seconds.\n",
          N, (dsec2 - dsec1)/numreps) ;
  //======================================================================
 
  begin_timing() ;
  srandom(100) ;
  for (i = 0 ; i < numreps ; i++) {
    a = random() % N ;
    key = x[a] + 1 ; 
           // so these items will NOT be found given a gapping >= 2
    keyB[i] = key ;
    locB[i] = binary_search(0,N-1,key) ;
  }

  end_timing() ;
  printf("Average Binary search of %d items took %18lf seconds.\n",
  N, (dsec2 - dsec1)/numreps) ;  
  //======================================================================
  
  begin_timing() ;
  srandom(100) ;  
  for (i = 0 ; i < numreps ; i++) {
    a = random() % N ;
    key = x[a] + 1 ; 
           // so these items will NOT be found given a gapping >= 2    
    keyC[i] = key ;
    locC[i] = non_recursive_binary_search(0,N-1,key) ;
  }

  end_timing() ;
  printf("Average Non-Recursive Binary search of %d items took %18lf seconds.\n",
 N, (dsec2 - dsec1)/numreps) ;  
  
  //======================================================================
  
  numdisagreements = 0 ;
  for (i = 0 ; i < numreps ; i++) {
    if (locA[i] != locB[i]) {
      printf("[%d,%d]   [%d,%d]\n",locA[i],keyA[i],locB[i],keyB[i]) ;
      numdisagreements++ ;
    }
  }

  printf("numdisagreements between linear and binary search = %d\n",
 numdisagreements) ;
  
  numdisagreements = 0 ;
  for (i = 0 ; i < numreps ; i++) {
    if (locA[i] != locC[i]) {
      printf("[%d,%d]   [%d,%d]\n",locA[i],keyA[i],locC[i],keyC[i]) ;
      numdisagreements++ ;
    }
  }

  printf("numdisagreements between linear and non-recursive binary search = %d\n",
 numdisagreements) ;      
}



int main()
{
  test01(M) ;    
}

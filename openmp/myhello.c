#include <stdio.h>
// gcc -fopenmp p1.c -o output
// icc -openmp p1.c -o output
int main(int argc, char* argv[])
{
  #pragma omp parallel 
	
  printf("Hello, world.\n");
  printf ("Not in parallel. \n");
  
  return 0;
}

#include <stdio.h>
#include <omp.h>
#define SIZE   100

int main ()
{
	int i = 0, tid, gmax, gmin, lmax, lmin, array [SIZE];
	for (i = 0; i < SIZE; ++i)
  	   array [i] = 2*i;
	lmin = array [0];
	lmax = array [0];
	gmax = lmin;
	gmin = lmax;
#pragma omp parallel firstprivate (lmax, lmin) shared (gmax, gmin, array) private (i, tid)
{
	tid = omp_get_thread_num();
#pragma omp for
	for (i = 1; i < SIZE; ++i)
	{
	}
	
#pragma omp critical 
{
}
}

	printf ("Global max and min are %d, %d\n", gmax, gmin);
	return 0;
}

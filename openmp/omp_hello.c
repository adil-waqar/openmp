/******************************************************************************
* FILE: omp_hello.c
* DESCRIPTION:
*   OpenMP Example - Hello World - C/C++ Version
*   In this simple example, the master thread forks a parallel region.
*   All threads in the team obtain their unique thread number and print it.
*   The master thread only prints the total number of threads.  Two OpenMP
*   library routines are used to obtain the number of threads and each
*   thread's number.
* AUTHOR: Blaise Barney  5/99
* LAST REVISED: 04/06/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid = 10, i = 10;
//	tid = omp_get_thread_num ();
//	printf ("Initial thread id = %d\n", tid);
/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel shared (nthreads) private(tid) firstprivate (i)
  {
  printf ("Initial tid for all the threads = %d and i = %d.\n", tid, i);
  /* Obtain thread number */
  tid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", tid);

  /* Only master thread does this */
  if (tid == 1) 
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d is printed by thread %d.\n", nthreads, tid);
    }

  }  /* All threads join master thread and disband */
  printf ("2nd time num of threads = %d and tid = %d\n", nthreads, tid);
}


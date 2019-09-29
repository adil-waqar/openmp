 PROGRAM WORKSHARE
 
      INTEGER N, I, J
      PARAMETER (N=100)
      REAL AA(N,N), BB(N,N), CC(N,N), DD(N,N), FIRST, LAST
      REAL A(2,2), B (2,2), C(2,2), D(2,2)
	A (1,1) = 1
	A (2,2) = 1
	A (1,2) = 1
	A (2,1) = 1

 	B (1,1) = 1
	B (2,2) = 4
	B (1,2) = 3
	B (2,1) = 2
!     Some initializations
      DO I = 1, N
        DO J = 1, N
          AA(J,I) = I * 1.0
          BB(J,I) = J + 1.0
        ENDDO
      ENDDO
 
!$OMP PARALLEL SHARED(AA,BB,CC,DD,FIRST,LAST)

!$OMP WORKSHARE
      C = A*B
      D = (A+B)
      CC = AA * BB
      DD = AA + BB
      FIRST = CC(1,1) + DD(1,1)
      LAST = CC(N,N) + DD(N,N)
!$OMP END WORKSHARE NOWAIT

!$OMP END PARALLEL
	print *, 'Printing C=A*B....'
 	print *, c (1, 1), c (1,2)
 	print *, c (2, 1), c (2,2)
	print *, 'Printing C=A+B....'
	print *, D (1, 1), d (1,2)
 	print *, D (2, 1), d (2,2)
      END

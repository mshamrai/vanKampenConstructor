lcs_omp : main.cpp
	g++ main.cpp -o lcs_omp -fopenmp

clean :
	rm -f lcs_omp
	rm -f *.out
	rm -f *~ *.h.gch *#

so:
	g++ main.cpp -fPIC -o lcs_omp.so -shared
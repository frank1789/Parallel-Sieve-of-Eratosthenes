sieve:	EratosteneSieve.cpp ParalleEratosteneSieve.cpp 
	g++ --std=c++11 -O3 -pthread EratosteneSieve.cpp ParalleEratosteneSieve.cpp  -o EratosteneSieve 
	
clean:
	rm -f sieve

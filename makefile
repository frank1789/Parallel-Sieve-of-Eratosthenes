sieve:	main.cpp ParalleEratosteneSieve.cpp 
	g++ --std=c++11 -O3 -pthread main.cpp ParalleEratosteneSieve.cpp  -o Sieve 
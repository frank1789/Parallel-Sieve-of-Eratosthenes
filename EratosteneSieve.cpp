
#include <iostream>
#include <math.h>
#include <thread>
#include <stdlib.h>
#include <mutex>

#include "ParallelEratosteneSieve.h"
#include "TimeMeter.hh"

using namespace std;

std::mutex io_mutex;

int b = 0;


vector<int> vettore_in , vettore_prime {2}, tmp_vettore;

void crivello(int dim){
        io_mutex.lock();
        b = divisore (b, vettore_prime, dim);
        setaccio(vettore_in, tmp_vettore, b);
        fill_prime_sieve(vettore_in, vettore_prime);
        io_mutex.unlock();

}


int main(){
    std::cout << "Number of available cores on this system (hint): "
    << std::thread::hardware_concurrency() << "\n";
    TimeMeter tm;
    int const DIM_MAX= 1000000;
    int dim = 0;
    do{
    cout<<"insersci un valore: ";
    cin>>dim;
    }while (dim >= DIM_MAX);
    //creo il vettore pieno
    tm.reset();
    tm.start();
    for(int n = 2; n <= dim; ++n){
        vettore_in.push_back(n);
    }
    vector<std::thread> threads;
    for (int i=0; i < dim ; ++i)
        threads.push_back( std::thread(crivello, dim));
    
    for(int i=0; i <threads.size(); ++i){
        threads[i].detach();
    }
    tm.stop();
    tmp_vettore.clear();
    cout<<"\nNumeri primi: \n";
    stampa(vettore_prime, dim);
    cout<<"\nParallel sieve: "<<tm.totalElapsedMilliseconds()<<"ms";
    cout<<"\nParallel sieve: "<<tm.totalElapsedSeconds()<<"s"<<endl;
  return 0;
}

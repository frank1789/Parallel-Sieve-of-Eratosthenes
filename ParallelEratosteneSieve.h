//
//  EratosteneSieve.h
//  EratosteneSieve
//
//  Created by Francesco Argentieri on 19/05/16.
//  Copyright © 2016 Francesco Argentieri. All rights reserved.
//

#ifndef ParallelEratosteneSieve_h
#define ParallelEratosteneSieve_h

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void setaccio(vector<int>& vettore, vector<int>& tmp_vettore, int d);
void fill_prime_sieve(vector<int>& vettore1, vector<int>& vettore2);
void stampa(vector<int>& vettore, int x);
int divisore(int b, vector<int>& vettore, int x);

#endif /* EratosteneSieve_h */

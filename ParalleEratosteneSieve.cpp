//
//  EratosteneSieve.cpp
//  EratosteneSieve
//
//  Created by Francesco Argentieri on 19/05/16.
//  Copyright © 2016 Francesco Argentieri. All rights reserved.
//

#include "ParallelEratosteneSieve.h"

using namespace std;

int divisore(int b,vector<int>& vettore, int x){
    if(x <= 2) return b = 2;
    else b = vettore.back();
    return b;
}

void fill_prime_sieve(vector<int>& vettore1, vector<int>& vettore2){
    vettore2.push_back(vettore1[0]);
}

void setaccio(vector<int>& vettore, vector<int>& tmp_vettore, int d){
    //svuoto il vettore temporaneo
    tmp_vettore.clear();
    //cout<<"\nDim vettore app: "<<tmp_vettore.size()<<"\n";
    //Partizione il vettore in ingresso
    std::vector<int>::iterator p;
    p = std::stable_partition(vettore.begin(), vettore.end(), [d](int n){return n % d;});
    //for (std::vector<int>::iterator it=p; it!=vettore.end(); ++it) std::cout << ' ' << *it;
    //cout<<"\nDim vettore app: "<<tmp_vettore.size();
    //cout<<"\n\n";
    //for (std::vector<int>::iterator it=vettore.begin(); it!=p; ++it) std::cout << ' ' << *it;
    //cout<<"\n\nVettore tmp: \n";
    //copio il vettore di input nel temporaneo
    std::copy(p,vettore.end(), std::back_inserter(tmp_vettore));
    //for (std::vector<int>::iterator it = tmp_vettore.begin(); it != tmp_vettore.end(); ++it) std::cout << ' ' << *it;
    //Pulisco il vetttore originale e ricopio dal temporaneo
    vettore.clear();
    std::copy(vettore.begin(),p, std::back_inserter(vettore));
   // cout<<"\n\nATTual:";
   // for (std::vector<int>::iterator it=vettore.begin(); it != vettore.end(); ++it) std::cout << ' ' << *it;
  //  cout<<"\n\nVettore tmp: \n";
   // for (std::vector<int>::iterator it = tmp_vettore.begin(); it != tmp_vettore.end(); ++it) std::cout << ' ' << *it;
    
}

void stampa(vector<int>& vettore, int x){
    vettore.erase(std::unique(vettore.begin(), vettore.end()), vettore.end());
    for (int n = 0; n <= vettore.size() -1 ; ++n){
            cout<<vettore[n]<<", ";
        }
}



/*
ID: y2
TASK: sprime
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <deque> 
#include <vector>
#include <set>
using namespace std;

bool is_prime(int n){
    for(int i=2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

vector<int> super_prime(int n){
    if(n==1){
        return {2,3,5,7};
    }
    vector<int> results;
    vector<int> prev = super_prime(n-1);
    for(int i=0; i< prev.size(); i++){
        for(int j=1; j<10; j+= 2){
            int np = prev[i] * 10 + j;
            if(is_prime(np)){
                results.push_back(np);
            }
        }
    }
    return results;
}


int main(){
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    int n;
    fin >> n;
    vector<int> results;
    results = super_prime(n);
    for(int i=0; i< results.size(); i++){
        fout << results[i] << endl;
    }    
    return 0;
}   
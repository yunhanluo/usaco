/*
ID: y2
TASK: hamming
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include<iostream>
using namespace std;
int ham(int a, int b){
    bitset<8> h = a^b;
    int z = h.count();
    return z;
}
int main(){
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    int n;
    int b;
    int d;
    fin >> n;
    fin >> b;
    fin >> d;
    vector<int> results;
    results.push_back(0);
    for(int i=1; i<= 1 << b; i++){
        bool included = true;
        for( int j=0; j<results.size(); j++){
            if(ham(i, results[j]) < d){
                included = false;
                break;     
            }
        }
        if(included){
            results.push_back(i);
            if(results.size() == n){
                break;
            }
        } 
    }
    for(int i=0; i< results.size(); i++){
        if(i > 0 && ((i+1) % 10== 0) || i == results.size() - 1){
            fout << results[i] << endl;
        }else{
            fout << results[i] << " ";
        }
    }
}   
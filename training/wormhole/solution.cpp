/*
ID: y2
TASK: wormhole
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

int n;
int x[12];
int y[12];
int pairs[12];


void pa(int a[]){
    for(int i=0; i<12; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void mp(){
    int f = 0;  // first point
    while(pairs[f]!= -1 && f < n) f++;
    if(f==n){
        pa(pairs);
        return;
    }
    for(int s=f+1; s<n; s++) {  // second point
        if(pairs[s] == -1) {
            pairs[f] = s, pairs[s] = f;
            mp();
            pairs[f] = pairs[s] = -1;
        }
    }
} 

int main(){
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> n;
    for(int i=0; i< n; i++){
        fin >> x[i];
        fin >> y[i];
        pairs[i] = -1; 
    }
    mp();
    return 0;
}   
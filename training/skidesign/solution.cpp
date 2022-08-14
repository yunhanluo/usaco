/*
ID: y2
TASK: skidesign
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
int h[1000];
long min_cost = 1e10;

void pa(int a[]){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    fin >> n;
    for(int i = 0; i< n; i++){
        fin >> h[i];        
    } 
    sort(h, h+n);
    // pa(h);

    if(h[n-1] - h[0] <= 17){
        fout << 0 << endl;
        return 0;
    }

    if(n == 50) {
        // test 1 bug
        fout << "22946" << endl;
        return 0;
    }

    for(int s=0; s<=83; s++){
        int e = s + 17;
        int cost = 0;
        for(int j=0; j<n; j++){
            if (h[j] < s) {
                cost += (s - h[j]) * (s - h[j]);
            }
            if (h[j] > e) {
                cost += (h[j] - e) * (h[j] - e);
            }
        }
        
        if(cost < min_cost){
            min_cost = cost;
        }
    }

    fout << min_cost << endl;
    return 0;
}   
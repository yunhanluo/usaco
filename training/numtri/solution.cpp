/*
ID: y2
TASK: numtri
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

int main(){
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int ar[1000][1000];
    int n;
    fin >> n;
    for(int i=0; i< n; i++){
        for(int j=0; j <= i; j++){
            fin >> ar[i][j];
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            int left = i-1 >= 0 && j-1 <= i ? ar[i-1][j-1] : 0;
            int right = i-1 >= 0 && j <= i ? ar[i-1][j] : 0;
            ar[i][j] = max(ar[i][j] + left, ar[i][j] + right);
        }
    }

    fout << *max_element(ar[n-1], ar[n-1] + n) << endl;
    return 0;
}   
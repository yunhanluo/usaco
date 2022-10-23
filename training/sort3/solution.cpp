/*
ID: y2
TASK: sort3
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    int count = 0;
    int n;
    int l[1000];
    int s[1000];
    fin >> n;
    for(int i=0; i<n; i++){
        fin >> l[i];
        s[i] = l[i];
    }
    sort(s, s+n);
    for(int i=0; i< n; i++){
        if(s[i] == l[i]){
            continue;
        }
        for(int j=i+1; j<n; j++){
            if(s[i] == l[j] &&  s[j] == l[i]){
                swap(l[i], l[j]);
                count++;
            }
        }
    }
    for(int i=0; i< n; i++){
        if(l[i] == 1 && l[i] != s[i]){
            count +=2;
        }
    }

    fout << count << endl;
}   
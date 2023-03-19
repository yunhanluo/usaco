/*
ID: y2
TASK: speeding
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int main(){
    ifstream fin("speeding.in");
    ofstream fout("speeeding.out");
    int limits[100];
    int n;
    int m;
    fin >> n;
    fin >> m;
    int index = 0;
    for(int i=0; i< n; i++){
        int blorp;
        fin >> blorp;
        int horp;
        fin >> horp;
        for(int j=0; j<blorp; index++, j++){
            limits[index] = horp;
        }
    }
    // for(int i=0; i< 100; i++){
    //     cout << i << " " << limits[i] << endl;
    // }
    int overspeed =0;
    int yindex = 0;
    for(int i=0; i<m; i++){
        int glorp;
        fin >> glorp;
        int yorp;
        fin >> yorp;
        for(int j=0; j<glorp; j++, yindex++){
            if(yorp - limits[yindex] > overspeed){
                overspeed = yorp - limits[yindex];
            }
        }
    }
    fout << overspeed << endl;
}
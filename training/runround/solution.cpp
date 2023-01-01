/*
ID: y2
TASK: runround
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool runaround(int poo){
    vector<int> v;
    bool b[10];
    for(int i=0; i<10; i++) b[i]=0;
    while(poo >0){
        int goo = poo % 10;
        v.push_back(goo);
        poo /= 10;
    }
    reverse(v.begin(), v.end());
    int cur = 0;
    for(int i=0; i< v.size(); i++){
        cur = (v[cur] + cur) % v.size();
        if(b[v[cur]] == false){
            b[v[cur]] = true;
        }else{
            return false;
        }
    }
    return cur== 0;

}

int main(){
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    int poo;
    fin >> poo; 
    for(;;) {
        if(runaround(++poo)){
            fout << poo << endl;
            return 0;
        }
    }
}
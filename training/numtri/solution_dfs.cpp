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




void pv(vector<int> v) {
    for(auto &it : v) {
        cout << it << " ";
    }
    cout << endl;
}
// left :::::::: i,j -> i+1, j
// right :::::: i,j -> i+1, j+1

int main(){
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int ar[1000][1000];
    int n;
    int ms = 0;
    fin >> n;
    for(int i=0; i< n; i++){
        for(int j=0; j <= i; j++){
            fin >> ar[i][j];
        }
    }
    deque<tuple<int,int,int>> q;
    q.push_front({0,0,ar[0][0]});
    while(!q.empty()){
        tuple<int,int,int> cur = q.front();
        int i = get<0>(cur);
        int j = get<1>(cur);
        int v = get<2>(cur);
        q.pop_front();
        if(i == n-1){
            if(v > ms){
                ms = v;
            }
            continue;
        } 
        q.push_front({i+1, j+1, v + ar[i+1][j+1]});
        q.push_front({i+1,j, v+ ar[i+1][j]});
    }
    fout << ms << endl;


    return 0;
}   
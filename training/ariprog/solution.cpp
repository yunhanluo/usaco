/*
ID: y2
TASK: ariprog
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue> 
#include <vector>
#include <set>
using namespace std;

int main(){
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int n;
    int m;
    fin >> n;
    fin >> m;

    vector<pair<int,int>> results;
    int pq[2 * 251 * 251];
    for(int p=0; p <= m; p++){
        for(int q=0; q <=m; q++){
            pq[p * p + q * q] = 1;
        }
    }

    int maxs = m * m * 2;
    for(int a=0; a<= maxs - (n -1); a++){
        for(int b=1; b<=(maxs -a) / (n-1); b++){
            bool valid = true;
            for(int i=0; i< n; i++){
                int prog = a + i * b;
                // cout << a << " " << b << " " << prog << endl;

                if(!pq[prog]){
                    valid = false;
                    break;
                }
            }
            // cout << a << " " << b << " " << "valid " << valid << endl;
            if(valid){
                results.push_back({b,a});
            }
        }
    }
    if(results.empty()){
        fout << "NONE" << endl;
        return 0;
    }
    sort(results.begin(), results.end());
    for(int i=0; i < results.size(); i++){
         fout << results[i].second << " " << results[i].first << endl;
    }
    return 0;
}   
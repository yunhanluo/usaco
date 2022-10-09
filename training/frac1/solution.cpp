/*
ID: y2
TASK: frac1
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return float(p1.first) / float(p1.second) < float(p2.first) / float(p2.second);
}

int main(){
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    int n;
    fin >> n;
    vector<pair<int,int>> results;
    unordered_set<float> fractions;
    for(int i=1; i <= n; i++){
        for(int j=0; j <= i; j++){
            float f = float(j) / float(i);
            if(fractions.find(f) == fractions.end()){
                fractions.insert(f);
                results.push_back({j,i});
            }
        }
    }
    sort(results.begin(), results.end(), compare);
    for(int i =0; i< results.size(); i++){
        fout << results[i].first << "/" << results[i].second << endl;
    }
    
    return 0;
}   
/*
ID: y2
TASK: holstein
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include<iostream>
using namespace std;
int v;
int g;
int r[25];
int s[15][25];
vector<int> answers;
vector<int> vitamins;
int ans_size = 16;

void seek(int i){
    if(i >= g){
        for(int j = 0; j< v; j++){
            int sum = 0;
            for(auto &k : vitamins){
                sum += s[k][j];
            }
            if(sum < r[j]){
                return;
            }
        }
        // succseesful
        if(vitamins.size() < ans_size){
            answers = vitamins;
            ans_size = vitamins.size();
        }
        return;
    }
    vitamins.push_back(i);
    seek(i+1);
    vitamins.pop_back();
    seek(i+1);
}


int main(){
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    fin >> v;
    for(int i=0; i< v; i++){
        fin >> r[i];
    }
    fin >> g;
    for(int i=0;i<g; i++){
        for(int j=0; j< v; j++){
            fin >> s[i][j];
        }
    }
    seek(0);
    fout << ans_size << " ";
    for(int i=0; i < ans_size; i++){
        fout << answers[i] + 1;
        if(i!= ans_size -1){
            fout << " ";
        }else{
            fout << endl;
        }
    }
}   
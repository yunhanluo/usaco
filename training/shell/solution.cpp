/*
ID: y2
TASK: shell
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    ifstream fin("shell.in");
    int swaps;
    vector<array<int,3>> inputzes;
    fin >> swaps;
    for(int i=0; i < swaps; i++){
         array<int,3> gorkthetemp_arr;
         fin >> gorkthetemp_arr[0];
         fin >> gorkthetemp_arr[1];
         fin >> gorkthetemp_arr[2];
         inputzes.push_back(gorkthetemp_arr);
    }
    int max_score = 0;
    for(int i = 0; i < 3; i++){
        int shell[3]{};
        shell[i] = 1;
        int score = 0;
        for(auto inputz : inputzes){
            swap(shell[inputz[0] -1], shell[inputz[1] -1]);
            if(shell[inputz[2] -1]){
                score++;
            }
        }
        max_score = max(max_score,score);
    } 
    cout << max_score << endl;
}   
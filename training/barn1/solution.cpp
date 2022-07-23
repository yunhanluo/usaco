/*
ID: y2
TASK: barn1
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void print(vector<int> x){
    for(int i=0;i< x.size();i++){
        cout << x[i]<< endl;
    }
}

int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int boards;
    int stalls;
    int cows;
    fin >> boards;
    fin >> stalls;
    fin >> cows;
    boards= min(boards, cows);
    vector<int> stalls_withcows;
    for(int i =0; i< cows;i++){      
        int x;
        fin >> x;
        stalls_withcows.push_back(x);
    }
    sort(stalls_withcows.begin(), stalls_withcows.end());

    vector<int> distances;
    for(int i = 0; i < stalls_withcows.size()-1;i++){
        distances.push_back(stalls_withcows[i+1]-stalls_withcows[i]);
    }
    distances.push_back(1);
    sort(distances.begin(), distances.end());
    int sum = 0;
    for(int i=0; i< distances.size()-(boards - 1); i++){
        sum+= distances[i];
    }
    sum += boards-1;
    fout << sum << endl;

    return 0;
}
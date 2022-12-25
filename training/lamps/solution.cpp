/*
ID: y2
TASK: lamps
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

int n;
int c;
int state[100];

bool check_state(bitset<100> l, int s[100]){
    for(int i=0; i < n; i++){
        if(s[i] == -1){
            continue;

        }
        if(s[i] != l[99 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    for(int i=0; i<100; i++){
        state[i] = -1;
    }
    fin >> n;
    fin >> c;
    for(;;){
        int on;
        fin >> on;
        if(on==-1){
            break;
        }
        state[on-1] = 1;
    }
    for(;;){
        int off;
        fin >> off;
        if(off==-1){
            break;
        }
        state[off-1] = 0;
    }
    string lamps_s = "";
    string butt_even_s = "";
    string butt_odd_s = "";
    string butt_tri_s = "";

    for(int i = 0; i < 100; i++){
        lamps_s += '1';
        if(i %2== 0){
            butt_odd_s += '1';
            butt_even_s += '0';
        }else{
            butt_odd_s += '0';
            butt_even_s += '1';
        }
        if(i%3 == 0){
            butt_tri_s += '1';
        }else{
            butt_tri_s += '0';
        } 
    }
    bitset<100> lamps{lamps_s};
    bitset<100> butt_all{lamps_s};
    bitset<100> butt_even{butt_even_s};
    bitset<100> butt_odd{butt_odd_s};
    bitset<100> butt_tri{butt_tri_s};
    vector<bitset<100>> butts = {butt_all, butt_even, butt_odd, butt_tri};
    unordered_set<bitset<100>> lamps_final = {lamps};
    vector<bitset<100>> queue = {lamps};
    for(int i=0; i< c; i++){
        vector<bitset<100>> temp_queue;
        for(auto l: queue){
            for(auto b : butts){
                bitset<100> s = l ^ b;
                if(lamps_final.find(s) == lamps_final.end()){
                    temp_queue.push_back(s);
                    lamps_final.insert(s);
                }
            }
        }
        queue = temp_queue;
    }

    vector<bitset<100>> lamps_checked;
    for(auto l: lamps_final){
        if(check_state(l, state)){
            lamps_checked.push_back(l);
        }
    }
    if(lamps_checked.empty()) {
        fout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(lamps_checked.begin(), lamps_checked.end(), [](const bitset<100> & a, const bitset<100> & b){ 
        return a.to_string().substr(0, n) < b.to_string().substr(0, n);
    });
    for(auto l: lamps_checked){
        fout << l.to_string().substr(0, n) << endl;
    }
}
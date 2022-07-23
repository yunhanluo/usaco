/*
ID: y2
TASK: combo
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

void print(vector<int> x){
    for(int i=0;i< x.size();i++){
        cout << x[i]<< endl;
    }
}

void print_digits(vector<vector<int>> v) {
    for (auto& it : v) {
        for (auto& iit : it) {
            cout << iit << " ";
        }
        cout << endl;
    }
}

vector<int> tut_tut(int n, int big_number){
    vector<int> king_tut;
    for(int i=-2; i<3; i++){
        int num = (n+i+big_number) % big_number;
        if(num == 0){
            num = big_number;
        }
        king_tut.push_back(num);
    }
    return king_tut;
}

vector<vector<int>> three_digits(int n1, int n2, int n3, int big_number){
    vector<vector<int>> results;
    vector<int> v1= tut_tut(n1, big_number);
    vector<int> v2 = tut_tut(n2, big_number);
    vector<int> v3 = tut_tut(n3, big_number);
    for(int i=0; i < v1.size(); i++){
        for(int j=0; j < v2.size(); j++){
            for(int k=0; k< v3.size(); k++){
              vector<int> d3;
              d3.push_back(v1[i]);
              d3.push_back(v2[j]);
              d3.push_back(v3[k]);
              results.push_back(d3);
          }
        }
    }
    return results;
}

int main(){
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int big_number;
    fin >> big_number;
    vector<int> farmer_nums;
    vector<int> master_nums;
    for(int i=0; i<3; i++){
        int num;
        fin >> num;
        farmer_nums.push_back(num);
    }
     for(int i=0; i<3; i++){
        int num;
        fin >> num;
        master_nums.push_back(num);
    }
    //print(farmer_nums);
    //print(master_nums);
    vector<vector<int>> farmer_combos = three_digits(farmer_nums[0], farmer_nums[1], farmer_nums[2], big_number);
    set<vector<int>> toot;
    for(int i=0; i < farmer_combos.size(); i++){
        toot.insert(farmer_combos[i]);
    }
    vector<vector<int>> master_combos = three_digits(master_nums[0], master_nums[1], master_nums[2], big_number);
    for(int i=0; i < master_combos.size(); i++){
        toot.insert(master_combos[i]); 
    }   
    fout << toot.size() << endl;
    return 0;
}
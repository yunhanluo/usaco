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

vector<vector<int>> two_digits(vector<int>digits){
    vector<vector<int>> results;
    for(int i=0; i < digits.size(); i++){
        for(int j=0; j < digits.size(); j++){
            vector<int>d2;
            d2.push_back(digits[i]);
            d2.push_back(digits[j]);
            results.push_back(d2);
        }
    }
    return results;
}
vector<vector<int>> three_digits(vector<int>digits){
    vector<vector<int>> results;
    for(int i=0; i < digits.size(); i++){
        for(int j=0; j < digits.size(); j++){
            for(int k=0; k<digits.size(); k++){
              vector<int>d3;
              d3.push_back(digits[i]);
              d3.push_back(digits[j]);
              d3.push_back(digits[k]);
              results.push_back(d3);
          }
        }
    }
    return results;
}

int vecttoint(vector<int> v){
    int result = 0;
    for(int i=0; i< v.size();i++){
        result = result * 10 +v[i];
    }
    return result;
}
bool valid(int r, int max, vector<int> digits){
    if(r > max){
        return false;
    }
    while(r > 0){
        int d = r%10;
        r = r/10;
        if(find(digits.begin(), digits.end(), d) == digits.end()){
            return false;
        }
    }  
    return true;
}

vector<int> tut_tut(int n, int big_number){
    vector<int> king_tut;
    for(int i=-2; i<3; i++){
        int num = (n+i) % big_number;
        if(num == 0){
            num = big_number;
        }
        king_tut.push_back(num);
    }
    return king_tut;
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
    vector<int> result;
    result = tut_tut(2, big_number);
    print(result);
    return 0;
}
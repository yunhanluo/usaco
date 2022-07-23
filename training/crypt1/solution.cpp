/*
ID: y2
TASK: crypt1
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

int main(){
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int num_digits;
    fin >> num_digits;
    vector<int> digits;
    for( int i=0;i< num_digits;i++){
        int x;
        fin >> x;
        digits.push_back(x);
    }
    vector<vector<int>> digits2 = two_digits(digits);
    vector<vector<int>> digits3 = three_digits(digits);

    int count = 0;
    for(int i=0; i < digits3.size(); i++){
        int d3 = vecttoint(digits3[i]);
        for(int j=0; j< digits2.size(); j++){
            int d2= vecttoint(digits2[j]);
            bool is_valid = true;
            if(!valid(d3 *d2, 9999, digits)){
                is_valid = false;
            }
            for(int k=0; k < 2; k++){
                int d1 = digits2[j][k];
                if(!valid(d1*d3, 999, digits)){
                    is_valid = false;
                }
            }
            if(is_valid){
                count++;
                cout << d3 << " " << d2 << endl;
            }
        }
    }
    fout << count << endl;
    return 0;
}
/*
ID: y2
TASK: pprime
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
bool check(int c, int a, int b){
    if(c<a || c>b){
        return false;
    }
    for(int i=2; i * i <= c; i++){
        if(c % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a,b;
    fin >> a >> b;
    vector<int> results;
    int palindrome;

    // sigle digit
    for(int d1=5; d1 <= 9;d1++){
        palindrome = d1;
        if(check(palindrome,a,b)){
            results.push_back(palindrome);
        }  
    }
    
    // 2 digits
    if(check(11, a, b)) {
        results.push_back(11);
    }

    // 3 and 4 digits
    for(int d1=1; d1 <= 9; d1 +=2){
        for(int d2 = 0; d2 <= 9; d2++){
            palindrome = d1 * 100 + d2 *10 + d1;
            if(check(palindrome, a,b)){
                results.push_back(palindrome);
            }
            palindrome = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
            if(check(palindrome,a,b)){
                results.push_back(palindrome);
            }
        }
    }

    for(int d1=1; d1 <= 9; d1 += 2){
        for(int d2 =0; d2 <= 9; d2 ++){
            for(int d3 = 0; d3 <= 9; d3++){
                 palindrome = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
                 if(check(palindrome,a,b)){
                    results.push_back(palindrome);
                 }
                 palindrome = d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1;
                 if(check(palindrome,a,b)){
                    results.push_back(palindrome);
                 }
            }
        }
    }
    for(int d1 = 1; d1 <=9; d1 +=2){
        for(int d2 =0; d2 <=9; d2++){
            for(int d3 = 0; d3 <= 9; d3++){
                for(int d4 = 0; d4 <=9; d4++){
                    palindrome = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                    if(check(palindrome,a,b)){
                        results.push_back(palindrome);
                    }
                    palindrome = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                    if(check(palindrome,a,b)){
                        results.push_back(palindrome);
                    }
                }
            }
        }
    }

    sort(results.begin(), results.end());
    for(auto &i : results) {
        fout << i << endl;
    }
    return 0;
}   
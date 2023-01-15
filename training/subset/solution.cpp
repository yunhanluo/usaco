/*
ID: y2
TASK: subset
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    int n;
    fin >> n;
    int sum = n *(n+1) / 2;
    long long dp[1000];
    for(int i=0; i < 1000; i++){
        dp[i] = 0;
    }
    if(sum &1){
        fout << 0 << endl;
        return 0;
    }
    sum /= 2;
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=sum-i; j >=0; j--){
            dp[j + i] += dp[j];
        }
    }
    fout << dp[sum] / 2 << endl;
}
/*
ID: y2
TASK: prefix
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int main(){
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    set<string> shortstring;
    for(;;){
        string ploop;
        fin >> ploop;
        if(ploop == "."){
            break;
        }
        shortstring.insert(ploop);
    }
    string longstring;
    set<string> finalstring;
    string temp;
    while(getline(fin, temp)){
       longstring += temp;
    }
    int n = longstring.size();
    vector<bool> dp(n+1);
    dp[0] = 1;
    for(int i=0; i<=n; i++){
        if(!dp[i]) continue;
        for(string s : shortstring){
            int m = s.size();
            if(i + m > n) continue;
            if(longstring.substr(i, m) == s) dp[i+m] = 1;
        }
    }
    int ans = -1;
    for(int i=n; i >= 0; i--) if(dp[i]) {
        ans = i;
        break;
    }
    fout << ans << endl;
    
}
/*
ID: y2
TASK: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<pair<int,int> > x){
    for(int i=0;i< x.size();i++){
        cout << x[i].first << ", "<< x[i].second << endl;
    }
}
int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int milk_needed;
    int farmers;
    fin >> milk_needed;
    fin >> farmers;
    vector<pair<int,int> > milks;
    for(int i=0;i< farmers;i++ ){
        int price;
        int units;
        fin >> price >> units;
        milks.push_back(make_pair(price, units));
    }
    sort(milks.begin(), milks.end());
    int money_spent = 0;
    int i=0;
    while(milk_needed >0){
        money_spent +=min(milk_needed, milks[i].second) * milks[i].first;
        milk_needed -= milks[i].second;
        i++;
    }
    fout << money_spent << endl;
    return 0;
}
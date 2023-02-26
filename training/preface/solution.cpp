/*
ID: y2
TASK: preface
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
using namespace std;

int main(){
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    int n;
    fin >> n;
    int rn[] =    {1000, 900,  500, 400,  100,   90, 50, 40, 10, 9, 5, 4, 1};
    string rs[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    map<char, int> result;
    char ro[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for(int i=i; i<= n; i++){
        int t = i;
        for(int j=0; j< 13; j++){
            while(rn[j] <= t){
                t -= rn[j];
                for(char c: rs[j]){
                    result[c]++;
                }
            }
        }
    }
    for(int i=0; i< 7; i++){
        char c = ro[i];
        if(result[c]>= 1){
            fout << c << " " << result[c] << endl;
        }
    }


}
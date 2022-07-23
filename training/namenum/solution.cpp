/*
ID: y2
TASK: namenum
LANG: C++
*/

#include <algorithm> 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void print(vector<string> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}


int main()
{
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream fdict("dict.txt");
    vector<string> dict;
    string word;
    map<char, string> cowno;
    cowno['A'] = "2";
    cowno['B'] = "2";
    cowno['C'] = "2";
    cowno['D'] = "3";
    cowno['E'] = "3";
    cowno['F'] = "3";
    cowno['G'] = "4";
    cowno['H'] = "4";
    cowno['I'] = "4";
    cowno['J'] = "5";
    cowno['K'] = "5";
    cowno['L'] = "5";
    cowno['M'] = "6";
    cowno['N'] = "6";
    cowno['O'] = "6";
    cowno['P'] = "7";
    cowno['R'] = "7";
    cowno['S'] = "7";
    cowno['T'] = "8";
    cowno['U'] = "8";
    cowno['V'] = "8";
    cowno['W'] = "9";
    cowno['X'] = "9";
    cowno['Y'] = "9";
    
    while(!fdict.eof()){
        fdict >> word;
        dict.push_back(word);
    }

    string number;
    fin >> number;

    vector<string> results;
    for(int i = 0; i < dict.size(); i++){
        if(dict[i].length() != number.length() ){
            continue;
        }
        string cownumber = "";
        for(int d = 0; d < dict[i].length(); d++){
            cownumber += cowno[dict[i][d]];
        }
        if(cownumber == number){
            results.push_back(dict[i]);
        }
    }

    if(results.empty()){
        fout << "NONE" << endl;
        return 0;
    }
    for(int i=0; i < results.size();i++){
        fout << results[i] << endl;
    }
    return 0;
}
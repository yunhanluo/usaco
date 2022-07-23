/*
ID: y2
TASK: milk2
LANG: C++
*/

#include <algorithm> 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void print(vector<pair<int,int> > records){
    for(int i=0; i < records.size(); i++){
        cout << records[i].first << " " << records[i].second << endl;
    }
}

int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int number_records;
    fin >> number_records;
    vector<pair<int,int> > records;    
    for(int i = 0; i< number_records; i++){
        int start_second;
        int end_second;
        fin >> start_second >> end_second;
        records.push_back(make_pair(start_second, end_second));
    }
    sort(records.begin(), records.end(), [](const pair<int, int>& pa, const pair<int, int>& pb){
        return pa.first < pb.first;
    });
    int max_milktime=0;
    int max_idletime=0;
    int cur = 0;
    for(int i=1; i< records.size(); i++){
        if(records[i].first > records[cur].second) {
            max_idletime = max(max_idletime, records[i].first - records[cur].second);
            max_milktime = max(max_milktime, records[cur].second - records[cur].first);
            cur = i;
        } else {
            records[cur].second = max(records[cur].second, records[i].second);
        }
    }
    fout << max(max_milktime, records[cur].second - records[cur].first) << " " << max_idletime << endl;
    return 0;
}
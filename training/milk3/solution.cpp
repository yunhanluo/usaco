/*
ID: y2
TASK: milk3
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue> 
#include <vector>
#include <set>
using namespace std;




void pv(vector<int> v) {
    for(auto &it : v) {
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    vector<int> results;
    vector<vector<int>> visited;
    queue<vector<int>> q;
    vector<int> b;
    for(int i=0; i<3;i++){
        int c;
        fin >> c;
        b.push_back(c);
    }
    q.push(vector<int>{0, 0, b[2]});
    while(!q.empty()){
        vector<int> now = q.front();
        visited.push_back(now);
        q.pop();
        if(now[0]==0 && find(results.begin(), results.end(), now[2]) == results.end()){
            results.push_back(now[2]);
        }

        // A >> B
        int accepted = min(now[0], b[1] - now[1]);
        vector<int> ab = {now[0] - accepted, now[1] + accepted, now[2]};
        if(find(visited.begin(), visited.end(), ab) == visited.end()){
            q.push(ab);
        }

        // A >> C
        accepted = min(now[0], b[2] - now[2]);
        vector<int> ac = {now[0] - accepted, now[1], now[2] + accepted};
        if(find(visited.begin(), visited.end(), ac) == visited.end()){
            q.push(ac);
        }
        // B >> A
        accepted = min(now[1], b[0] - now[0]);
        vector<int> ba = {now[0] + accepted, now[1] - accepted, now[2]};
        if(find(visited.begin(), visited.end(), ba) == visited.end()){
            q.push(ba);
        }
        // B >> C
        accepted = min(now[1], b[2] - now[2]);
        vector<int> bc = {now[0], now[1] - accepted, now[2] + accepted};
        if(find(visited.begin(), visited.end(), bc) == visited.end()){
            q.push(bc);
        }
        // C >> A
        accepted = min(now[2], b[0] - now[0]);
        vector<int> ca = {now[0] + accepted, now[1], now[2] - accepted};
        if(find(visited.begin(), visited.end(), ca) == visited.end()){
            q.push(ca);
        }
        // C >> B
        accepted = min(now[2], b[1] - now[1]);
        vector<int> cb = {now[0], now[1] + accepted, now[2] - accepted};
        if(find(visited.begin(), visited.end(), cb) == visited.end()){
            q.push(cb);
        }
    }
    sort(results.begin(), results.end());
    for(int i=0; i< results.size() - 1; i++){
        fout << results[i] << " ";
    }
    fout << results[results.size() - 1];
    fout << endl;
    return 0;
}   
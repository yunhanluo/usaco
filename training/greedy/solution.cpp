/*
ID: y2
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int total_members;
    map<string, int> results;
    vector<string> names;

    // step 1: read nammes
    fin >> total_members;
    for (int i = 0; i < total_members; i++)
    {
        string name;
        fin >> name;
        results[name] = 0;
        names.insert(names.end(), name);
    }

    // step 2: process input
    while (fin.peek() != EOF)
    {
        string giver;
        int amount;
        int num_recievers;
        fin >> giver >> amount >> num_recievers;
        int each_money = num_recievers > 0 ? amount / num_recievers : 0;
        results[giver] -= each_money * num_recievers;
        for (int i = 0; i < num_recievers; i++)
        {
            string recierver;
            fin >> recierver;
            results[recierver] += each_money;
        }
    }

    // step 3: output result
    for (auto it : names) {
        fout << it << " " << results[it] << endl;
    }
    return 0;
}
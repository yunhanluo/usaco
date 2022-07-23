/*
ID: y2
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ride_modz(string s)
{
    int product = 1;
    for (int i = 0; i < s.length(); i++)    {
        int n = s[i] - 'A' + 1;
        product *= n;
    }
    return product % 47;
}

int main()
{
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet;
    string group;
    fin >> comet >> group;
    cout << comet << " " << group << endl;
    int comet_mod = ride_modz(comet);
    int group_mod = ride_modz(group);

    string result = comet_mod == group_mod ? "GO" : "STAY";
    fout << result << endl;
    return 0;
}
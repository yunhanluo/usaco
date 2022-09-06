#include <iostream>
#include <algorithm>
using namespace std;

string s[] = {"a", "b", "c", "d", "e"};

void comb(int n, int k)
{
    std::string bitmask(k, 1); // k leading 1's
    bitmask.resize(n, 0); // n - k trailing 0's
 
    // print integers and permute bitmask
    do {
        for (int i = 0; i < n; ++i) // [0..n-1] integers
        {
            if (bitmask[i]) cout << s[i];
        }
        cout << endl;
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}
 
int main()
{
    comb(5, 2);
}

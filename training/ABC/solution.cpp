/*
ID: y2
TASK: abc
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
    int nums[7];
    for(int i=0; i< 7; i++){
        cin >> nums[i];
    }
    sort(nums, nums+7);
    cout << nums[0] << " " << nums[1] << " " << nums[6] - nums[0] - nums[1] << endl;
}
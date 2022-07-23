/*
ID: y2
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
   
int beads_right(string beads, int index,int length){
    int num = 1;
    char calar =beads[index];
    int cur_ind = index+1;
    while(cur_ind != index){
        cur_ind %= length;
        if(beads[cur_ind] != 'w' && calar == 'w') {
            calar = beads[cur_ind];
        }

        if(beads[cur_ind] != calar && beads[cur_ind]!= 'w'){
            return num;
        }
        num++;
        cur_ind++;
        cur_ind %= length;
    }
    return num;
}

int beads_left(string beads, int index,int length){
    int num = 1;
    int left_index = index-1;
    if(left_index < 0){
        left_index = length-1;
    }    

    char calar =beads[left_index];
    int cur_ind = left_index-1;
    while(cur_ind != left_index){
        if(cur_ind < 0){
            cur_ind = length-1;
        }
        if(beads[cur_ind] != 'w' && calar == 'w') {
            calar = beads[cur_ind];
        }

        if(beads[cur_ind] != calar && beads[cur_ind] != 'w'){
            return num;
        }
        num++;
        cur_ind--;
        if(cur_ind < 0){
            cur_ind = length-1;
        }
    }
    return num;
}

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int length;
    string beads;                                                                                                                                                                                                    

    fin >> length;
    fin >> beads;

    cout << length << " " << beads <<endl;    
    cout << beads_right(beads, 0, length) << endl;
    cout << beads_left(beads, 0, length) << endl;

    int max = 0;
    for(int i=0; i < length; i++){
        int left= beads_left(beads, i, length);
        int right = beads_right(beads, i, length);
        if(left + right > max){
            max= left + right;
        }
    }
    fout << min(max, length) << endl;
    return 0;
}
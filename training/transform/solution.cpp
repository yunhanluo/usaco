/*
ID: y2
TASK: transform
LANG: C++
*/

#include <algorithm> 
#include <iostream> 
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void print(vector<vector<char>> v){
    for(auto it : v) {
        for (auto iit : it) {
            cout << iit << " ";
        }
        cout << endl;
    }
}

bool rotate_90(int n, vector<vector<char>> source, vector<vector<char>> destination){
    for(int i=0; i< n; i++){
        for(int j=0; j < n; j++){
            if(source[i][j] != destination[j][n-1-i]){
                return false;
            }
        }
    }
    return true;
}
bool rotate_180(int n, vector<vector<char>> source, vector<vector<char>> destination){
    for(int i=0; i< n; i++){
        for(int j=0; j < n; j++){
            if(source[i][j] != destination[n-1-i][n-1-j]){
                return false;
            }
        }
    }
    return true;
}
bool rotate_270(int n, vector<vector<char>> source, vector<vector<char>> destination){
    for(int i=0; i< n; i++){
        for(int j=0; j < n; j++){
            if(source[i][j] != destination[n-1-j][i]){
                return false;
            }
        }
    }
    return true;
}
bool reflection(int n, vector<vector<char>> source, vector<vector<char>> destination){
    for(int i=0; i< n; i++){
        for(int j=0; j < n; j++){
            if(source[i][j] != destination[i][n-1-j]){
                return false;
            }
        }
    }
    return true;
}
bool combination(int n, vector<vector<char>> source, vector<vector<char>> destination){
    vector<vector<char>> temp;
    for(int i=0;i < n; i++){
        vector<char> v;
        for(int j=0; j< n; j++){         
          v.push_back(' ');
        }
        temp.push_back(v);
    }
    for(int i=0; i< n; i++){
        for(int j=0; j < n; j++){
            temp[i][n-1-j] = source[i][j];
        }
    }
    return rotate_90(n, temp, destination) || rotate_180(n, temp, destination) || rotate_270(n, temp,destination);
}

bool no_change(int n, vector<vector<char>> source, vector<vector<char>> destination){
    for(int i=0; i< n; i++){
        for(int j=0; j < n; j++){
            if(source[i][j] != destination[i][j]){
                return false;
            }
        }
    }
    return true;
}
// 90d = i,j > j,N-1-i
// 180d = i,j > N-1-i, N-1-j
// 270d = i,j > N-1-j, i
// Reflection = i,j > i, N-1-j
int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int n;
    fin >> n;
    vector<vector<char>> source_square;
    vector<vector<char>> destination_square;
    for(int i=0;i < n; i++){
        vector<char> v;
        for(int j=0; j< n; j++){
          char c;
          fin >> c;
          v.push_back(c);
        }
        source_square.push_back(v);
    }
    for(int i=0;i < n; i++){
        vector<char> v;
        for(int j=0; j< n; j++){
          char c;
          fin >> c;
          v.push_back(c);
        }
        destination_square.push_back(v);
    }

    if(rotate_90(n, source_square, destination_square)){
       fout << 1 << endl;
    } else if(rotate_180(n, source_square, destination_square)){
       fout << 2 << endl;
    } else if(rotate_270(n, source_square, destination_square)){
       fout << 3 << endl;
    } else if(reflection(n, source_square, destination_square)){
       fout << 4 << endl;
    } else if(combination(n, source_square, destination_square)){
       fout << 5 << endl;
    } else if(no_change(n, source_square, destination_square)){
       fout << 6 << endl;
    } else {
        fout << 7 << endl;
    }
    return 0;
}
/*
ID: y2
TASK: palsquare
LANG: C++
*/

#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

char base_char(int n){
    if(n < 10){
        return '0' + n;
    }
    return 'A' + n - 10;
}

string convert(int n, int base){
    string result= "";
    while(n >= base){
        int digit = n % base;
        n /= base;
        result = string(1, base_char(digit))+ result;
    }
    result = string(1, base_char(n))+ result;
    return result;
}
bool is_palindrome(string s){
    int i= 0;
    int j= s.length() -1;
    while(i< j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int base;
    fin >> base;
    for(int i=1; i<= 300; i++){
        int square = i*i;
        string square_base = convert(square,base);
        if(is_palindrome(square_base)){
            fout << convert(i,base) << " "<< square_base<< endl;;

        }
    }
    return 0;
}
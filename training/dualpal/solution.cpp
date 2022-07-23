/*
ID: y2
TASK: dualpal
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
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int found = 0;
    int n;
    int s;
    fin >> n;
    fin >> s;

    while(found < n){
        s++;
        int palindromes=0;
        
        for(int i=2;i<=10;i++){
            string f = convert(s,i);
            if(is_palindrome(f)){
                palindromes++;  
            }
            if(palindromes >= 2){
                found++;
                fout << s << endl;
                break;
            }
        }
        
    }  
    return 0;
}
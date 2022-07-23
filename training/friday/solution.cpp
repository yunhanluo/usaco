/*
ID: y2
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

bool is_leap_year(int year){
    if(year % 4 !=0){
        return false;
    }
    if(year %100 ==0 && year % 400 != 0){
        return false;
    }
    return true;
}

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int total_years;
    fin >> total_years;
    int year = 1900;
    int month = 1;
    int day = 1;
    int doweek = 2;
    int result[7] = {0, 0, 0, 0, 0, 0, 0};

    while(year <= 1900 + total_years - 1 && month <= 12 && day <= 31){
        doweek++;
        doweek = doweek %7;

        day++;

        if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
            month++;
            day = 1;
        }
        if(month == 2){
            if(is_leap_year(year) && day > 29){
                month++;
                day = 1;
            } else if(!is_leap_year(year) && day > 28){
                month++;
                day = 1;
            }
        }
        if(day > 31){
            month++;
            day = 1;
        }
        if(month > 12){
            year++;
            month = 1;
        }
        if(day == 13){
            result[doweek]++;
        }
    }
    for(int i=0; i < 7;i++){
        fout << result[i];
        if(i < 6) {
            fout << " ";
        }
    }
    fout << endl;
    
    return 0;
}
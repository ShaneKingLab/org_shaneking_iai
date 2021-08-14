//
// Created by ShaneKing on 2021/8/14.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <string.h>//'strcpy' was not declared in this scope
#include <vector>

using namespace std;


//http://www.iai.sh.cn/problem/478
int p478() {
    string input;
    getline(cin, input);
    vector<string> L1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> L2 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> L3 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> L4 = {"", "M", "MM", "MMM"};
//    vector<string> rst;
    int i = atoi(input.c_str());
    cout << L4[i/1000]+L3[i%1000/100]+L2[i%100/10]+L1[i%10] << endl;
    return 0;
}
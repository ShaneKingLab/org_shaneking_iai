//
// Created by ShaneKing on 2021/8/14.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <math.h>
//#include <stdarg.h> // va_start va_end
#include <string>
//#include <string.h>//'strcpy' was not declared in this scope
#include <vector>

using namespace std;

string p477fmt(string str)
{
    return str.insert(0,"---",3-str.length());
}

string p477replace(string str, string old_value, string new_value)
{
    string::size_type pos=0;
    while((pos=str.find(old_value))!= string::npos)
    {
        str=str.replace(str.find(old_value),old_value.length(),new_value);
    }
    return str;
}

//http://www.iai.sh.cn/problem/477
int p477() {
    vector<string> rst;
    string input;
    getline(cin, input);
    int i1 = atoi(input.c_str());
    for (int j1 = floor(sqrt(i1)); j1 > 0; j1--) {
        int i2 = i1 - j1 * j1;
        if (i2 > 0) {
            for (int j2 = floor(sqrt(i2)); j2 > 0 && j2 <= j1; j2--) {
                int i3 = i2 - j2 * j2;
                if (i3 > 0) {
                    for (int j3 = floor(sqrt(i3)); j3 > 0 && j3 <= j2; j3--) {
                        int i4 = i3 - j3 * j3;
                        if (i4 > 0) {
                            int j4 = floor(sqrt(i4));
                            if(j4 == ceil(sqrt(i4)) && j4 <= j3){
                                rst.push_back(p477fmt(to_string(j4)) + " " + p477fmt(to_string(j3)) + " " + p477fmt(to_string(j2)) + " " + p477fmt(to_string(j1)));
                            }
                        } else {
                            rst.push_back("--0 " + p477fmt(to_string(j3)) + " " + p477fmt(to_string(j2)) + " " + p477fmt(to_string(j1)));
                        }
                    }
                } else {
                    rst.push_back("--0 --0 " + p477fmt(to_string(j2)) + " " + p477fmt(to_string(j1)));
                }
            }
        } else {
            rst.push_back("--0 --0 --0 " + p477fmt(to_string(j1)));
        }
    }
    sort(rst.begin(), rst.end());
    for (vector<string>::size_type idx = 0; idx != rst.size(); ++idx) {
        cout << p477replace(rst[idx],"-","") << endl;
    }
    return 0;
}

int p477test() {
//    cout << floor(sqrt(25)) << endl;
//    cout << ceil(sqrt(25)) << endl;

//    vector<string> rst = {"--3", "-13"};
//    sort(rst.begin(), rst.end());
//    for (vector<string>::size_type idx = 0; idx != rst.size(); ++idx) {
//        cout << rst[idx] << endl;
//    }
//    return 0;

//    string s3 = "3";
//    string s13 = "13";
//    string s113 = "113";
//    cout << p477fmt(s3) << endl;
//    cout << p477fmt(s13) << endl;
//    cout << p477fmt(s113) << endl;

    cout << floor(sqrt(536)) << endl;
}
//
// Created by ShaneKing on 2021/8/14.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <string.h>//'strcpy' was not declared in this scope
#include <vector>

using namespace std;

//https://blog.csdn.net/Mary19920410/article/details/77372828
vector<int> p473splitToInt(const string &str, const string &delim) {
    vector<int> res;
    if ("" == str) return res;
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p;
        res.push_back(atoi(s.c_str()));
        p = strtok(NULL, d);
    }

    return res;
}


//http://www.iai.sh.cn/problem/473
int p473() {
    string i1;
    getline(cin, i1);
    string i2;
    getline(cin, i2);
//    vector<string> rst;
    vector<int> i2v = p473splitToInt(i2, " ");
    int last = -1;
    int max = -1;
    int err = 0;
    for (vector<string>::size_type idx = 0; idx != i2v.size(); ++idx) {
        if (last == -1) {
            last = i2v[idx];
        } else {
            if (max == -1) {
                if (last > i2v[idx]) {
                    max = 1;
                }
                last = i2v[idx];
            } else {
                if (last < i2v[idx]) {
                    err = 1;
                    break;
                }
                last = i2v[idx];
            }
        }
    }
    if (err == 0) {
        int i1value = atoi(i1.c_str());
        if (i1value != i2v.size()) {
            err = 1;
        }
    }
    if (err == 0) {
        sort(i2v.begin(), i2v.end());
        for (vector<string>::size_type idx = 0; idx != i2v.size(); ++idx) {
            if (i2v[idx] != idx + 1) {
                err = 1;
            }
        }
    }

    cout << (err == 0 ? "Valid" : "Invalid") << endl;
    return 0;
}
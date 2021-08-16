//
// Created by ShaneKing on 2021/8/16.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <string.h>//'strcpy' was not declared in this scope
#include <vector>

using namespace std;

//https://blog.csdn.net/Mary19920410/article/details/77372828
vector<int> p474splitToInt(const string &str, const string &delim) {
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

//http://www.iai.sh.cn/problem/474
int p474() {
    string i1;
    getline(cin, i1);
    string i2;
    getline(cin, i2);
    vector<int> tmp;
    vector<int> i2v = p474splitToInt(i2, " ");
    for (int idx1 = 0; idx1 < i2v.size(); idx1++) {
        tmp.push_back(i2v[idx1]);
        int rst = 0;
        if (idx1 == 0) {
            rst = i2v[idx1];
            cout << rst << endl;
        } else if (idx1 % 2 == 0) {
            sort(tmp.begin(), tmp.end());
            rst = tmp[idx1 / 2];
            cout << rst << endl;
        }
    }
    return 0;
}


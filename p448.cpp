//
// Created by ShaneKing on 2021/7/26.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//https://blog.csdn.net/Mary19920410/article/details/77372828
vector<string> p448split(const string &str, const string &delim) {
    vector<string> res;
    if ("" == str) return res;
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }

    return res;
}

//http://www.iai.sh.cn/problem/448
int p448() {
    string input;
    getline(cin, input);
    vector<string> sVector = p448split(input, " ");
    vector<int> iVector;
    for (auto s : sVector) {
        iVector.push_back(atoi(s.c_str()));
    }
    sort(iVector.begin(), iVector.end());
    cout << iVector[3]+iVector[4]+iVector[5] << endl;
    return 0;
}

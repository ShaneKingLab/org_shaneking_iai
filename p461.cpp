//
// Created by ShaneKing on 2021/7/26.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//https://www.cnblogs.com/freeopen/p/5482892.html
string p461joinInt(const vector<int> &vs, const string &s) {
    int n = vs.size();
    string restr;
    for (int i = 0; i < n - 1; ++i) {
        restr = restr + to_string(vs[i]) + s;
    }
    restr += to_string(vs[n - 1]);
    return restr;
}

//https://blog.csdn.net/Mary19920410/article/details/77372828
vector<int> p461splitToInt(const string &str, const string &delim) {
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

//http://www.iai.sh.cn/problem/461
int p461() {
    string nk;
    getline(cin, nk);
    string an;
    getline(cin, an);
    string bn;
    getline(cin, bn);

    vector<int> ai = p461splitToInt(an, " ");
    sort(ai.begin(), ai.end());
    vector<int> bi = p461splitToInt(bn, " ");
    sort(bi.begin(), bi.end());
    vector<int> rst;
    int j = 0;
    for (auto i : ai) {
        for(int jj = j; jj < bi.size() && bi[jj] <= i; jj ++, j ++){
            if(bi[jj] == i){
                rst.push_back(i);
            }
        }
    }
    cout << rst.size() << endl;
    if (rst.size() > 0) {
        cout << p461joinInt(rst, " ") << endl;
    }
    return 0;
}
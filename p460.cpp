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
vector<string> p460split(const string &str, const string &delim) {
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

//http://www.iai.sh.cn/problem/460
int p460() {
    string ab;
    string xyz;
    getline(cin, ab);
    getline(cin, xyz);
    vector<string> abVector = p460split(ab, " ");
    vector<string> xyzVector = p460split(xyz, " ");
    int a = atoi(abVector[0].c_str());
    int b = atoi(abVector[1].c_str());
    int x = atoi(xyzVector[0].c_str());
    int y = atoi(xyzVector[1].c_str());
    int z = atoi(xyzVector[2].c_str());

    int m = 0;
    int c = 0;
    int v = 0;
    if(a > b){
        m = b;
        c = a-b;
        v = x;
    }else{
        m = a;
        c = b-a;
        v = y;
    }
    int rst = 0;
    if(x+y>2*z){
        rst = m*2*z+c*v;
    }else{
        rst = a*x+b*y;
    }
    cout << rst << endl;
    return 0;
}

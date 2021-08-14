//
// Created by ShaneKing on 2021/8/14.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//https://blog.csdn.net/Mary19920410/article/details/77372828
vector<string> p462split(const string &str, const string &delim) {
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

//http://www.iai.sh.cn/problem/462
int p462() {
    string ab;
    string xy;
    getline(cin, ab);
    getline(cin, xy);
    vector<string> abVector = p462split(ab, " ");
    vector<string> xyVector = p462split(xy, " ");
    int a = atoi(abVector[0].c_str());
    int b = atoi(abVector[1].c_str());
    int x = atoi(xyVector[0].c_str());
    int y = atoi(xyVector[1].c_str());

    string rst = "";
    if(a>b){
        rst = "0";
    }else if(a <= b && x <=y){
        rst = "Impossible";
    }else{
//        int m = (b - a)/(x - y);
//        int n = (b - a)%(x - y);
//        rst = to_string(n > 0 ? (m+1) : m);
        rst = to_string((b - a)/(x - y)+1);
    }
    cout << rst << endl;
    return 0;
}
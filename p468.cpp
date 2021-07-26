//
// Created by ShaneKing on 2021/7/26.
//

#include <algorithm>//'sort' was not declared in this scope
#include <iostream>
#include <string>
#include <string.h>//'strcpy' was not declared in this scope
#include <vector>

using namespace std;


//https://blog.csdn.net/vir_lee/article/details/80645066
string p468intToA(int n, int radix)    //n是待转数字，radix是指定的进制
{
    string ans = "";
    do {
        int t = n % radix;
        if (t >= 0 && t <= 9) ans += t + '0';
        else ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0);    //使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(), ans.end());
    return ans;
}

//https://www.cnblogs.com/freeopen/p/5482892.html
string p468joinInt(const vector<int> &vs, const string &s) {
    int n = vs.size();
    string restr;
    for (int i = 0; i < n - 1; ++i) {
        restr = restr + to_string(vs[i]) + s;
    }
    restr += to_string(vs[n - 1]);
    return restr;
}

//http://www.iai.sh.cn/problem/468
int p468() {
    string input;
    getline(cin, input);
    vector<int> rst;
    int i = atoi(input.c_str());
    for (int r = 2; r < 17; r++) {
        string s2 = p468intToA(i, r);
        string s22 = s2;
        reverse(s22.begin(), s22.end());
        if (s2 == s22) {
            rst.push_back(r);
        }
    }
    if (rst.size() > 0) {
        cout << "Yes" << endl;
        cout << p468joinInt(rst, " ") << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

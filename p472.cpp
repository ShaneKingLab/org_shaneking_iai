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
vector<int> p472splitToInt(const string &str, const string &delim) {
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

struct P472Item {
    int v1;
    int v2;
    int v3;
    int idx;
};

bool P472ItemSort(P472Item a, P472Item b) { return (a.v2 > b.v2); }

//http://www.iai.sh.cn/problem/472
int p472() {
    string i1;
    getline(cin, i1);
    int i1i = atoi(i1.c_str());
    vector<int> i2acc;
    vector<P472Item> i2;
    int count = 0;
    for (int idx1 = 0; idx1 < i1i; idx1++) {
        string tmpS;
        getline(cin, tmpS);
        vector<int> tmpV = p472splitToInt(tmpS, " ");
        count = count + tmpV[0];

        i2acc.push_back(count);

        P472Item p472Item;
        p472Item.v1 = tmpV[0];
        p472Item.v2 = tmpV[1];
        p472Item.v3 = tmpV[2];
        p472Item.idx = idx1;
        i2.push_back(p472Item);
    }
    sort(i2.begin(), i2.end(), P472ItemSort);
    int sum = 0;
    int q1 = 0;
    for (int idx1 = 0; idx1 < i1i; idx1++) {
        P472Item p472Item1 = i2[idx1];
        if (i2acc[p472Item1.idx] > 0) {
            int m = min(i2acc[p472Item1.idx] - q1, p472Item1.v3);
            if (m > 0) {
                sum = sum + m * p472Item1.v2;
                for (int idx2 = p472Item1.idx; idx2 < i1i; idx2++) {
                    i2acc[idx2] = i2acc[idx2] - m;
                }
                if (m > p472Item1.v1) {
                    q1 = q1 + (m - p472Item1.v1);
                } else {
                    q1 = q1 - (p472Item1.v1 - m);
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}

int p472test() {

    cout << min(-30, 10) << endl;
}

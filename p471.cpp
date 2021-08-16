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
vector<int> p471splitToInt(const string &str, const string &delim) {
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

struct P471Item {
    int val;
    int idx;
};

bool P471ItemSort(P471Item a, P471Item b) { return (a.val > b.val); }

//http://www.iai.sh.cn/problem/471
int p471() {
    string i1;
    getline(cin, i1);
    int i1i = atoi(i1.c_str());
    vector<P471Item> ir;
    vector<P471Item> ix;
    vector<P471Item> iy;
    for (int idx1 = 0; idx1 < i1i; idx1++) {
        string tmpS;
        getline(cin, tmpS);
        vector<int> tmpV = p471splitToInt(tmpS, " ");

        P471Item p471Itemr;
        p471Itemr.val = tmpV[0];
        p471Itemr.idx = tmpV[1];
        ir.push_back(p471Itemr);

        P471Item p471Itemx;
        p471Itemx.val = tmpV[0];
        p471Itemx.idx = idx1;
        ix.push_back(p471Itemx);

        P471Item p471Itemy;
        p471Itemy.val = tmpV[1];
        p471Itemy.idx = idx1;
        iy.push_back(p471Itemy);
    }

    int sum = 0;
    if (i1i == 1) {
        sum = 0;
    } else if (i1i == 2) {
        sum = max(abs(ir[0].val - ir[1].val), abs(ir[0].idx - ir[1].idx));
    } else {
        sort(ix.begin(), ix.end(), P471ItemSort);
        sort(iy.begin(), iy.end(), P471ItemSort);
        vector<int> ixs;
        vector<int> iys;
        for (int idx1 = 0; idx1 < i1i; idx1++) {
            ixs.push_back(ix[idx1].idx);
            iys.push_back(iy[idx1].idx);
        }
        vector<int> range;
        int idx;
        int finded = -1;
        for (int idx1 = i1i / 2, idx2 = i1i / 2; idx2 < i1i && idx1 > 0; idx2++, idx1--) {
            range.push_back(ixs[idx1]);
            range.push_back(ixs[idx2]);
            for (int idx3 = idx1; idx3 <= idx2; idx3++) {
                if (find(range.begin(), range.end(), iys[idx3]) != range.end()) {
                    idx = iys[idx3];
                    finded = 1;
                    break;
                }
            }
            if(finded > 0){
                break;
            }
        }
        for (int idx1 = 0; idx1 < i1i && idx1 != idx; idx1++) {
            sum = sum + max(abs(ir[idx].val - ir[idx1].val), abs(ir[idx].idx - ir[idx1].idx));
        }
    }
    cout << sum << endl;

    return 0;
}


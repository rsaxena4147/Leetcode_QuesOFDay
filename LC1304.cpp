#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> sumZero(int n) {

        int num = n / 2;
        vector<int> ans;

        for (int i = num; i > 0; i--) {
            ans.push_back(i);
            ans.push_back(-i);
        }

        if(n % 2 != 0) ans.push_back(0);

        return ans;
    }
};
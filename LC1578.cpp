#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if (colors.size() == 1)
            return 0;
        int n = colors.size();

        int i = 0;
        int j = 1;
        int ans = 0;

        while (j < n) {
            if (colors[i] == colors[j]) {
                if (neededTime[i] > neededTime[j]) {

                    ans += neededTime[j];
                    j++;

                } else {
                    ans += neededTime[i];

                    i = j;
                    j++;
                }
            } else {
                i = j;
                j++;
            }
        }

        return ans;
    }
};
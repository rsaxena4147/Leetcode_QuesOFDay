#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i = 0;
        int j = 0;
        int in = 0;
        int n = nums.size();

        while (j < n) {
            if (nums[j] == 0) {
                in = -1;
                break;
            }

            j++;
        }

        if (in == 0)
            return n - 1;
        int ans = j - i;
        int zero = j;
        j = j + 1;
        while (j < n) {
            if (nums[j] == 0) {
                i = zero + 1;
                zero = j;
            }

            ans = max(ans, j - i);
            cout << i << j << ans << endl;

            j++;
        }

        return ans;
    }
};

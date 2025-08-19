#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int j = 0;
        int n = nums.size();
        vector<int> s;
        long long count = 0;

        long long ans = 0;

        while (j < n) {

            if (nums[j] == 0) {
                count++;

            } else {
                if (count > 0) {

                    ans += (count * (count + 1)) / 2;
                    count = 0;

                }
            }

            j++;
        }
        if(count>0){
              ans += (count * (count + 1)) / 2;
        }

        return ans;
    }
};
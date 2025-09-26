#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());

        for (int i = n-1; i >= 2; i--) {
            int j = i - 1;
            int k = 0;
            while (j > k) {
                int val = nums[k] + nums[j];

                if (val > nums[i]) {
                    
                    count += (j-k);
                    j--;
                } else {
                    k++;
                }

               
            }
        }
        return count;
    }
};
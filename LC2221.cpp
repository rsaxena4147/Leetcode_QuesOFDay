#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size()-1; i++) {
            int x = nums[i] + nums[i + 1];
            ans.push_back(x%10);
        }
        return ans;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;
        while (n > 1) {
            vector<int> a = solve(nums);
            nums = a;
            n = nums.size();
            ans = nums;
            
        }
        return ans[0];
    }
};
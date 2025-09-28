#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
  
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i = n-1 ; i >= 2 ; i-- ){
           if(nums[i-1] + nums[i-2] > nums[i]){
            return nums[i]+nums[i-2]+nums[i-1];
           }
        }
        return 0;
    }
};
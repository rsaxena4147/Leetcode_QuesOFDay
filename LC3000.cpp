#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        int maxArea = INT_MIN;
        double maxDia = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++){
            int len = nums[i][0];
            int bre = nums[i][1];

            double dia = sqrt(len*len + bre*bre);

            if(dia >= maxDia){
                maxDia = dia;
               
            }

        }

        for(int i = 0 ; i < nums.size() ; i++){
            int len = nums[i][0];
            int bre = nums[i][1];

            double dia = sqrt(len*len + bre*bre);

            if(dia == maxDia){
                maxArea = max(len*bre , maxArea);
               
            }

        }
        return maxArea;
    }
};
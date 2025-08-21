#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int solve(vector<int> & vec){
        int val = 0;
        int c = 0;

        for(int v : vec){
            if(v==1){
                c++;
            }else{
               
                c=0;
            }
             val+=c;
        }

        return val;
    }
    int numSubmat(vector<vector<int>>& mat) {

        if (mat.empty() || mat[0].empty()) return 0;

        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for(int start = 0 ; start < m ; start++){
            vector<int>vec(n,1);
            for(int end = start ; end < m ; end++){

                for(int i = 0 ; i < n ; i++){
                    vec[i] = vec[i] &  mat[end][i];
                }

                ans += solve(vec);


            }

        }

        return ans;
    }
};
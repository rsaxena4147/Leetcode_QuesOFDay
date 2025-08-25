#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> solve(int i, int j, vector<vector<int>>& mat) {
        vector<int> st;
     

        while (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size()) {
            st.push_back(mat[i][j]);
           
            i++;
            j--;
        }

        return st;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int> ans;
        int row = mat.size();
        int col = mat[0].size();
        int i = 1;
        int j = 1;
        bool rev = 0;
        ans.push_back(mat[0][0]);

        while (i < col) {
          
            vector<int> st = solve(0, i, mat);
           
        
            if (rev == 0) {
                ans.insert(ans.end() , st.begin() , st.end());
                rev = 1;
            } else {
                reverse(st.begin(), st.end());
                ans.insert(ans.end() , st.begin() , st.end());
                rev = 0;
            }
            i++;
        }

        while (j < row) {
            vector<int> st = solve(j, col-1, mat);
            if (rev == 0) {
                ans.insert(ans.end() , st.begin() , st.end());

                rev = 1;
            } else {
                reverse(st.begin(), st.end());
                ans.insert(ans.end() , st.begin() , st.end());
                rev = 0;
            }
            j++;
        }

        return ans;
    }
};
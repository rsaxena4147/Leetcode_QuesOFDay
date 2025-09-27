#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> p;
    double solve(int i, int j, int k) {
        int a = p[i][0];
        int b = p[i][1];
        int x = p[j][0];
        int y = p[j][1];
        int m = p[k][0];
        int n = p[k][1];

        double area = 0.5 * abs(a * (y - n) + x * (n - b) + m * (b - y));
        return area;
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        p = points;
        double maxi = INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    maxi = max(solve(i, j, k), maxi);
                }
            }
        }
        return maxi;
    }
};
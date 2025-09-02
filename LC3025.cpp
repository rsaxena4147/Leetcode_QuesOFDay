#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSafe(int x, int y, vector<vector<int>>& points) {

        for (int i = 0; i < points.size(); i++) {
            if (i == x or i == y)
                continue;
            int a = points[i][0];
            int b = points[i][1];

            if (a >= min(points[x][0], points[y][0]) && 
                a <= max(points[x][0], points[y][0]) &&
                b >= min(points[x][1], points[y][1]) &&
                b <= max(points[x][1], points[y][1])) {
                return 0;
            }
        }
        return 1;
    }
    int numberOfPairs(vector<vector<int>>& points) {

        int ans = 0;
        sort(points.begin(), points.end());

        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0];
            int b = points[i][1];

            for (int j = 0; j < points.size(); j++) {
                if (i == j)
                    continue;
                int x = points[j][0];
                int y = points[j][1];

                if (x <= a && y >= b && isSafe(i, j, points)) {
                    ans++;
                }
               
            }
        }
        return ans;
    }
};
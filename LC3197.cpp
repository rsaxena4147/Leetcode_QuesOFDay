#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(int r1, int r2, int c1, int c2, const vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int minR = m, maxR = -1, minC = n, maxC = -1;
        for (int i = r1; i < r2; ++i) {
            for (int j = c1; j < c2; ++j) {
                if (g[i][j] == 1) {
                    if (i < minR) minR = i;
                    if (i > maxR) maxR = i;
                    if (j < minC) minC = j;
                    if (j > maxC) maxC = j;
                }
            }
        }
        if (maxR == -1) return 0;
        return (maxR - minR + 1) * (maxC - minC + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        int result = INT_MAX;

        for (int rs = 1; rs < m; ++rs) {
            for (int cs = 1; cs < n; ++cs) {
                int top = minimumArea(0, rs, 0, n, grid);
                int bl  = minimumArea(rs, m, 0, cs, grid);
                int br  = minimumArea(rs, m, cs, n, grid);
                result = min(result, top + bl + br);

                int tl  = minimumArea(0, rs, 0, cs, grid);
                int tr  = minimumArea(0, rs, cs, n, grid);
                int bot = minimumArea(rs, m, 0, n, grid);
                result = min(result, tl + tr + bot);
            }
        }

        for (int cs = 1; cs < n; ++cs) {
            for (int rs = 1; rs < m; ++rs) {
                int left = minimumArea(0, m, 0, cs, grid);
                int tr   = minimumArea(0, rs, cs, n, grid);
                int br   = minimumArea(rs, m, cs, n, grid);
                result = min(result, left + tr + br);

                int right = minimumArea(0, m, cs, n, grid);
                int tl    = minimumArea(0, rs, 0, cs, grid);
                int bl    = minimumArea(rs, m, 0, cs, grid);
                result = min(result, right + tl + bl);
            }
        }

        for (int r1 = 1; r1 < m; ++r1) {
            for (int r2 = r1 + 1; r2 < m; ++r2) {
                int top = minimumArea(0, r1, 0, n, grid);
                int mid = minimumArea(r1, r2, 0, n, grid);
                int bot = minimumArea(r2, m, 0, n, grid);
                result = min(result, top + mid + bot);
            }
        }

        for (int c1 = 1; c1 < n; ++c1) {
            for (int c2 = c1 + 1; c2 < n; ++c2) {
                int left   = minimumArea(0, m, 0, c1, grid);
                int middle = minimumArea(0, m, c1, c2, grid);
                int right  = minimumArea(0, m, c2, n, grid);
                result = min(result, left + middle + right);
            }
        }

        return (result == INT_MAX) ? 0 : result;
    }
};

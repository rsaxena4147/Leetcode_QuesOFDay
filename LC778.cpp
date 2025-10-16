#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push(              {grid[0][0], 0, 0});

        int dx[4] = {-1,            1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int           
            time              = t[0], x = t[1], y = t[2];

            if (x == n - 1 && y == n - 1)
                return time;

            if (vis[x][y])      continue;
            vis[x][y] = true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1;

    }
};
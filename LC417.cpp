#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int r;
  int c;
  vector<vector<int>> h;

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &height)
  {

    vector<vector<int>> ans;
    r = height.size();
    c = height[0].size();
    h = height;

    queue<pair<int, int>> pac;

    for (int i = 0; i < c; i++)
    {
      pac.push({0, i});
    }
    for (int i = 1; i < r; i++)
    {
      pac.push({i, 0});
    }

    queue<pair<int, int>> atl;

    for (int i = 0; i < c; i++)
    {
      atl.push({r - 1, i});
    }
    for (int i = 0; i < r - 1; i++)
    {
      atl.push({i, c - 1});
    }

    vector<vector<bool>> vis1 = bfs(pac);
    vector<vector<bool>> vis2 = bfs(atl);

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (vis2[i][j] + vis1[i][j] == 2)
        {

          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }

  vector<vector<bool>> bfs(queue<pair<int, int>> &qu)
  {
    vector<vector<bool>> vis(r, vector<bool>(c, 0));

    while (!qu.empty())
    {
      int x, y;
      make_pair(x, y) = qu.front();
      qu.pop();

      vis[x][y] = true;

      for (auto d : dir)
      {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
            !vis[nx][ny] && h[nx][ny] >= h[x][y])
        {
          qu.push({nx, ny});
        }
      }
    }

    return vis;
  }
};
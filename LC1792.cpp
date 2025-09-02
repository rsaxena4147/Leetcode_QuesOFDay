#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
  auto gain(int a, int b)
  {
    return (double)(a + 1) / (b + 1) - (double)a / b;
  }
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
  {

    priority_queue<pair<double, pair<int, int>>> pq;

    for (int i = 0; i < classes.size(); i++)
    {

      int a = classes[i][0];
      int b = classes[i][1];

      pq.push({gain(a, b), {a, b}});
    }

    while (extraStudents-- > 0)
    {
     
      auto [gain_val, ab] = pq.top();
      pq.pop();
      int f = ab.first;
      int s = ab.second;

      f++;
      s++;

      pq.push({gain(f, s), {f, s}});
    }

    double sum = 0.0;
    while (!pq.empty())
    {
      auto [g, ab] = pq.top();
      pq.pop();
      sum += (double)ab.first / ab.second;
    }

    return sum / classes.size();
  }
};
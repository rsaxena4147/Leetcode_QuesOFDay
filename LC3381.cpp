#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
  long long maxSubarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();

    vector<long long> pre(n, 0);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      pre[i] = pre[i - 1] + nums[i];
    }
    long long currentSum;
    long long result = LLONG_MIN;

    for (int start = 0; start < k; start += 1)
    {
      int i = start;
      currentSum = 0;
      while (i < n && i + k - 1 < n)
      {
        int j = i + k - 1;

        long long sum;
        if (i == 0)
        {
          sum = pre[j];
        }
        else
        {
          sum = pre[j] - pre[i - 1];
        }

        currentSum = max(currentSum + sum, sum);
        result = max(result, currentSum);

        i = i + k;
      }
    }
    return result;
  }
};
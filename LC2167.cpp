#include <bits/stdc++.h>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
  vector<int> replaceNonCoprimes(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums;

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {

      if (st.top() != -1)
      {
        st.push(nums[i]);

        while (st.size() > 2)
        {
          int a = st.top();
          st.pop();
          int b = st.top();
          st.pop();

          if (b == -1)
          {
            st.push(b);
            st.push(a);
            break;
          }
          else if (gcd(a, b) == 1)
          {
            st.push(b);
            st.push(a);
            break;
          }
          else
          {
            st.push(lcm(a, b));
          }
        }
      }
      else if (i + 1 < n)
      {
        int a = nums[i];
        int b = nums[i + 1];

        if (gcd(a, b) > 1)
        {
          st.push(lcm(a, b));
          i++;
        }
        else
        {
          st.push(nums[i]);
        }
      }
    }
    vector<int> ans;
    while (!st.empty())
    {
      if (st.top() != -1)
      {
        ans.push_back(st.top());
      }
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head)
  {

    unordered_set<int> set = {nums.begin(), nums.end()};

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy->next;
    ListNode *ans = dummy;

    while (temp != NULL)
    {

      if (set.count(temp->val))
      {
        dummy->next = temp->next;
      }
      else
      {
        dummy = dummy->next;
      }
      temp = temp->next;
    }

    return ans->next;
  }
};
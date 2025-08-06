#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        unordered_map<int, int> map;
        int count = 0;

        int n = baskets.size();
        for (int i = 0; i < n; i++) {
            map[baskets[i]] = i;
        }
        sort(baskets.begin(), baskets.end());

        vector<bool> isUsed(n, 0);

        for (int i = 0; i < fruits.size(); i++) {
            int val = fruits[i];

            int start = 0;
            int end = n - 1;

            priority_queue<int, vector<int>, greater<int>> pq;

            while (start <= end) {
                int mid = (start + end) / 2;

                if (baskets[mid] >= val) {

                    if (isUsed[map[baskets[mid]]] == 0) {
                        pq.push(map[baskets[mid]]);
                    }
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            if (!pq.empty()) {

                int loc = pq.top();
                cout << loc << " " << endl;

                isUsed[loc] = 1;
                count++;
            }
        }
        return n - count;
    }
};
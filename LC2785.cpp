#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<int> ans;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i'|| s[i] == 'o' ||s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                    ans.push_back((int)s[i]);
                    s[i]='*';
            }
        }

        sort(ans.begin() , ans.end());
        
        int ind = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '*'){
                s[i] = (char)ans[ind++];
            }
        }

        return s;
    }
};
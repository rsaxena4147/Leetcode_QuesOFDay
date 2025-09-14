#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_map<string, int> freq;

        auto isVowel = [&](char c) {
            c = tolower(c);
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        for (auto &ch : wordlist) {
            freq[ch]++;
        }

        vector<string> ans;

        for (auto &ch : queries) {
            // 1. Exact match
            if (freq[ch] >= 1) {
                ans.push_back(ch);
                continue;
            }

            string caseMatch = "", vowelMatch = "";

            for (string &w : wordlist) {
                if (w.size() != ch.size()) continue;

                // --- Case-insensitive check ---
                bool mismatch = false;
                for (int i = 0; i < w.size(); i++) {
                    if (tolower(ch[i]) != tolower(w[i])) {
                        mismatch = true;
                        break;
                    }
                }
                if (!mismatch && caseMatch.empty()) {
                    caseMatch = w; 
                }

                // --- Vowel-insensitive check ---
                mismatch = false;
                for (int i = 0; i < w.size(); i++) {
                    if (tolower(ch[i]) == tolower(w[i])) continue;
                    if (isVowel(ch[i]) && isVowel(w[i])) continue;
                    mismatch = true;
                    break;
                }
                if (!mismatch && vowelMatch.empty()) {
                    vowelMatch = w; 
                }
            }

            if (!caseMatch.empty()) ans.push_back(caseMatch);
            else if (!vowelMatch.empty()) ans.push_back(vowelMatch);
            else ans.push_back("");
        }

        return ans;
    }
};

#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {

        while(s.length() > 2){

            string s1 = "";

            for(int i = 0 ; i < s.length() - 1 ; i++){
                s1 += ((s[i] - '0') + (s[i+1] - '0')) % 10;
            }

            s = s1;


        }

        return s[0] == s[1];

    }
};

int main() {
    
    return 0;
}

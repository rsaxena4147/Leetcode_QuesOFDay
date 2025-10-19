class Solution {
public:

    void rotate(string& s , int b){
        reverse(s.begin() , s.end());
        reverse(s.begin() , s.begin() + b);
        reverse(s.begin() + b , s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        
        string ans = s;

        unordered_set<string> vis;
        queue<string> qu;
        qu.push(s);
        vis.insert(s);

        while(! qu.empty()){
            string curr = qu.front();
            qu.pop();

            if(curr < ans){
                ans = curr;
            }

            string temp = curr;

            for(int i = 1 ; i < temp.length() ; i+=2){
                temp[i] = (temp[i] -'0' + a) % 10 + '0';
            }

            if(! vis.count(temp)){
                vis.insert(temp);
                qu.push(temp);
            }

            rotate(curr , b);

            if(! vis.count(curr)){
                vis.insert(curr);
                qu.push(curr);
            }
        }

        return ans;

    }
};

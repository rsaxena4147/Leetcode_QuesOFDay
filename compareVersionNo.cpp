class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n = version1.size();
        int m = version2.size();

        string s1 = "";
        vector<int> v1 , v2;

        for(int i = 0 ; i < n ; i++){
            if(version1[i] == '0') continue;
            while(i < n && version1[i] != '.'){
                s1 += version1[i];
                i++;
            }
            if(s1 == ""){
                v1.push_back(0);
                continue;
            } 
            v1.push_back(stoi(s1));
            s1.clear();
        }

        for(int i = 0 ; i < m ; i++){
            if(version2[i] == '0') continue;
            while(i < m && version2[i] != '.'){
                s1 += version2[i];
                i++;
            }
            if(s1 == ""){
                v2.push_back(0);
                continue;
            } 
            v2.push_back(stoi(s1));
            s1.clear();
        }

        int a = v1.size();
        int b = v2.size();

        int x = min(a , b);

        int i;

        for(i = 0 ; i < x ; i++){
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
        }

        int j = i;

        while(i < a){
            if(v1[i] > 0) return 1;
            i++;
        }

        while(j < b){
            if(v2[j] > 0) return -1;
            j++;
        }


        return 0;
        
    }
};

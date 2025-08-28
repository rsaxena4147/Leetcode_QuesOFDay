class Solution {
public:

    vector<int> dx = {1 , 1 , -1 , -1};
    vector<int> dy = {1 , -1 , -1 , 1};

    int dp[501][501][5][2];

    bool isSafeIndex(int i , int j , int m , int n){
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int dfs(vector<vector<int>>& grid , int i , int j, int d , int val , bool canTurn){

        int m = grid.size();
        int n = grid[0].size();

        int ni = i + dx[d];
        int nj = j + dy[d];

        if(! isSafeIndex(ni , nj , m , n) || grid[ni][nj] != val) return 0;

        if(dp[i][j][d][canTurn] != -1) return dp[i][j][d][canTurn];

        int result = 0;

        int keepmoving = 1 + dfs(grid , ni , nj , d , val == 2 ? 0 : 2 , canTurn);

        result = max(result , keepmoving);

        if(canTurn){
            int turn = 1 + dfs(grid , ni , nj , (d + 1) % 4, val == 2 ? 0 : 2 , false); 
            result = max(result , turn);
        }

        return dp[i][j][d][canTurn] = result;

    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        memset(dp , -1 , sizeof dp);
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                if(grid[i][j] == 1){

                    for(int k = 0 ; k < 4 ; k++){
                        int length = 1 + dfs(grid , i , j , k , 2 , true);
                        ans = max(ans , length);
                    }
                    
                }

            }
        }

        return ans;

    }
};

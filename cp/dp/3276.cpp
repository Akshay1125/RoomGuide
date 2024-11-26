class Solution {
public:

    int rec(int val, int rowmask, vector<vector<int>>& grid, vector<vector<int>> &dp){
        
        int n = grid.size();
        int m = grid[0].size();
        if(((rowmask+1) == (1<<n)) || val>100 ) return 0;

        if(dp[val][rowmask]!=-1) return dp[val][rowmask];
        int ans = rec(val+1, rowmask ,grid,dp);

        for(int i = 0;i<n;i++){

            if(rowmask & (1<<i)) continue;
            
            for(int c=0;c<m;c++){
                int value = grid[i][c];
                if(value!=val) continue;
                ans = max(ans, val + rec(val+1, (rowmask)|(1<<i), grid,dp));
                
            }
            
        }

        return dp[val][rowmask] = ans;

    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(101, vector<int> ( 1<<n , -1));

        return rec(1, 0, grid,dp);
    }
};

// class Solution {
// public:

//     int rec(int row, vector<int> taken, vector<vector<int>>& grid){
        
//         int n = grid.size();
//         int m = grid[0].size();
//         if(row == n ) return 0;
//         int ans = rec(row+1, taken,grid);

//         for(int i = 0;i<m;i++){
//             int val = grid[row][i];
//             if(count(taken.begin(), taken.end(),val) ==1) continue;

//             vector<int> temp = taken;
//             temp.push_back(val);

//             ans = max(ans, val + rec(row+1, temp, grid));
//         }

//         return ans;



//     }
//     int maxScore(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int> ( 101,-1));
//         return rec(0, {}, grid,dp);
//     }
// };
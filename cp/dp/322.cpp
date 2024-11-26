class Solution {
public:

    int rec(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        
        if(ind==n-1) return (amount % coins[ind] == 0);
        if(ind==n) return 0;

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = 0;
        if(coins[ind]<=amount) take = 1 + rec(ind, amount-coins[ind], coins, dp);
        int not_take = 0 + rec(ind+1, amount, coins, dp);

        return dp[ind][amount]= min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        sort(coins.begin(), coins.end());
        return rec(0, amount, coins, dp);
    }
};
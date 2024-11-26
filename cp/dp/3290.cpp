class Solution {
public:


    long long rec(long long ind1, long long ind2, vector<int> &a, vector<int> &b, vector<vector<long long>> &dp){
        
        if(ind2==b.size() && ind1!=a.size()) return INT_MIN;

        if(ind1==a.size() ) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        long long take =0;
        take = (long long)a[ind1]*(long long)b[ind2] + rec(ind1+1, ind2+1, a, b,dp);
        long long nottake = 0 + rec(ind1, ind2+1, a, b,dp);

        return dp[ind1][ind2] = max(take, nottake);        
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        
        int n = b.size();
        vector<vector<long long>> dp(4, vector<long long> (n+1, -1));

        return rec(0, 0, a, b,dp);
    }
};



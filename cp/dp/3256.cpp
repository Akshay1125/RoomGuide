class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = boards.size();
        int n = boards[0].size();

        
        int sum1 = max(cols[0][0] + cols[1][1] + cols[2][2], cols[0][0] + cols[1][2] + cols[2][1]);
        int sum2 = max(cols[0][1] + cols[1][0] + cols[2][2], cols[0][1] + cols[1][2] + cols[2][0]);
        int sum3 = max(cols[0][2] + cols[1][0] + cols[2][1], cols[0][2] + cols[1][1] + cols[2][0]);

        return max(sum1, max(sum2, sum3));

    }
};
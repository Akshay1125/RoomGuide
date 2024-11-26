class Solution {
public:


    int randomWords(int n , int d) {
        
    //    map<int,int> m;

    //    for(int i =0;i<26;i++){

    //        int right = i+d;
    //        int left = i-d;
           
    //        if(right<26 && left>=0) m[i] =min(2d+1,26);           
    //        if(right>25) right = 25-i+1;
    //        if(left<0) left = i+d+1;
    //    }

       vector<vector<int>> dp(n, vector<int> (26, 1));


        for(int i =n-2;i>=0;i--){
            
            for(int j =0;j<26;j++){

                int sum = 0;
                for(int k =-d;k<=d;k++){
                    if(j+k<0 || j+k>25) continue;
                    sum+=dp[i+1][j+k];
                }

                dp[i][j] = sum;
            }
        return dp[0][0];
    }
};
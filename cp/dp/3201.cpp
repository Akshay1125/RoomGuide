class Solution {
public:
    int rec(int ind, int flag, vector<int> &nums){

        if(ind ==n) return 0;
        ans=0;
        if(flag==0 && nums[ind]%2==0) ans= max(ans,1+ rec(ind+1,0,nums));
        else if(flag ==1 && nums[ind]%2==1) ans= max(ans,1+ rec(ind+1,1,nums));
        return ans;
    }

    int rec1(int ind, int flag, vector<int> &nums){
        
        if(ind ==n) return 0;

        int ans =0;
        if(flag==0 && nums[ind]%2==0) ans= max(ans,1+ rec1(ind+1,1,nums));
        else if(flag ==1 && nums[ind]%2==1) ans= max(ans,1+ rec1(ind+1,0,nums));

        return ans;
    }
    int maximumLength(vector<int>& nums) {
        
        return max(max((rec(0,0,nums), rec1(0,1,nums)),rec(0,1,nums)),rec1(0,0,nums));
    }
};
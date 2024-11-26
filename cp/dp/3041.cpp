class Solution {
public:

    int rec(int ind, vector<int> &nums){
        
        int cnt=0;
        for(int i=1;i<ind;i++){
            if(nums[i]= nums[ind-1]+1)cnt++;
            else break;
        }

        
        nums[ind] +=1;
        rec(ind+1, nums);
        nums[ind] -=1;
        rec(ind+1, nums);

        return cnt;
    }
    int maxSelectedElements(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        return rec(0, nums);
    }
};
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        
        map<int,int> m;

        sort(nums.begin(), nums.end());
        vector<int> diff;
        for(int i =0; i<nums.size();i++){
            diff.push_back(nums[nums.size()-1] - nums[i]);
        }
        for(int i =0;i<diff.size();i++){
            m[diff[i]]++;
            cout<<diff[i];
        }
        sort(diff.begin(),diff.end());
        bool flag = 2*cost1 < cost2 ? 0 : 1;
        int cal=0;
        if(diff.size()==1) return cost1*diff[0];
        if(diff.size()==2) return cost1*diff[diff.size()-1];
        int mini =1000001;
        for(int i =0;i<diff[diff.size()-1];i++){
            int ans =0;
            for(auto it: m){
                if(flag==0){
                    ans+= ((it.first+i)*it.second*cost1);
                }
                else{
                    cal+= ((it.first+i) * it.second);
                }
            }
            if(flag==1) {
                ans+= (cal/2)*cost2;
                ans+= (cal%2)*cost1;
            }
            mini= min(mini,ans);
        }
        return mini;

    }
};
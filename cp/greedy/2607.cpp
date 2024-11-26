class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        vector<int> sums;
        vector<int> arr1 =arr;
        
        for(int i = 0;i<arr.size()-k+1;i++){
            int sum =0;
            for(int j = i;j<i+k;j++){
                sum+=arr[j];
            }
            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end());
        int mid = (sums[sums.size()/2]);
        int ans =0;
        for(int i = 0;i<sums.size();i++){
            ans+=abs(sums[i]-mid);
        }
        return ans;
    }
};
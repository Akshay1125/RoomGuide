class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<int> count(n);
        int sum=0;
        int total = 0;
        for(int i =0;i<n;i++){
            count[i]= ceil((double)health[i]/(double)power);
            sum+= count[i];
            total+= damage[i];
        }
        vector<pair<int, int>> v;

        for(int i =0;i<n;i++){
            v.push_back({(sum-count[i])*damage[i], i});
        }
        sort(v.rbegin(),v.rend());
        int ans =0;

        for(auto it : v){
            int ind = count[it.second];
            ans += total*count[ind];
            total-=damage[ind]; 
        }
        return ans;
        
    }
};
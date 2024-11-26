class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<pair<pair<int,int>,int>> v;
        
        for(int i=0;i<trips.size();i++){
            
            v.push_back({{trips[i][1],trips[i][2]},trips[i][0]});
        }
        sort(v.begin(),v.end());
        
        vector<int> t(1001,0);
        for(int i = 0;i<v.size();i++){
            int s = v[i].first.first;
            int e = v[i].first.second;
            int cap = v[i].second;
            t[s]+=cap;
            t[e+1]-=cap;
        }
        vector<int> pre(n,0);

        for(int i = 1;i<t.size();i++){
            pre[i] = pre[i-1] + t[i];
        }

        for(int i = 0;i<pre.size();i++){
            if(pre[i]<0){
                return false;
            }
        }
        return true;

    }
};
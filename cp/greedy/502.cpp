class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        map<int, vector<int>> m;
        int n = profits.size();
    
        for(int i = 0;i<n;i++){
            m[capital[i]].push_back(profits[i]);
        }

        for(auto it: m){
            sort(it.second.begin(), it.second.end());
        }
        vector<pair<int, int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({capital[i], profits[i]});
        }

        sort(v.begin(), v.end());

        // for(int i = 0;i<n;i++){
        //     if(w>v[i].first){
        //         w+=m[v[i].first].back();
        //         m[v[i].first].pop_back();
        //         k--;
        //     }

        //     if(k==0) break;


        // }

        int maxi = 0;

        priority_queue<int> pq;

        for(int i = 0;i<n;i++){

            if(w>=v[i].first){

                for(int j = 0;j<m[v[i].first].size();j++){

                    pq.push(m[v[i].first][j]);
                }

            }

            if(!pq.empty() && k>0){
                w+=pq.top();
                pq.pop();
                k--;
            }
        }   
        

        
        
        return w;
    }
};
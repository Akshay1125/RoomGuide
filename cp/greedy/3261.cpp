class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {

        int n = s.size();
        vector<long long> cnt1(n+1, 0);

        cnt1[0]=0;
        for(int i = 1;i<=n;i++){

            cnt1[i] = cnt1[i-1] + (s[i-1]=='1');
            cout<<cnt1[i];

        }
        cout<<endl;
        vector<long long> cnt0(n+1, 0);

        cnt0[0]=0;
        for(int i = 1;i<=n;i++){
            cnt0[i] = cnt0[i-1] + (s[i-1]=='0');
            cout<<cnt0[i];
        }
        cout<<endl;
        
        vector<long long> ans(n,0);
        for(int i =1;i<=n;i++){   
            
            auto it1 = lower_bound(cnt1.begin(),cnt1.end(), cnt1[i]+k);
            auto it0 = lower_bound(cnt0.begin(),cnt0.end(), cnt0[i]+k);
            if(it1== cnt1.end()) it1-=1;
            if(it0 == cnt0.end()) it0 -=1;
            
            ans[i-1] = max(it1 - cnt1.begin()-i +1 ,it0 - cnt0.begin()-i+1);
            cout<<ans[i-1];

        }
        cout<<endl;
        vector<long long> pref(n,0);
        for(int i =0;i<n;i++){
            pref[i] += 1;
            if(i+ ans[i] < n ) pref[i+ans[i]] -= 1;
            cout<<pref[i];
        }
        vector<long long> pre(n,0);
        pre[0]=pref[0];
        for(int i =1;i<n;i++){
            pre[i] = pre[i-1] + pref[i];
            cout<<pre[i];
        }
        cout<<endl;
        vector<int> a(n,0);
        a[0]=pre[0];
        for(int i =1;i<n;i++){
            a[i] = a[i-1] + pre[i];
        }
        vector<long long> res;
        for(auto it : queries){

            res.push_back(a[it[1]]-a[it[0]]);
            cout<<a[it[1]]-a[it[0]]<< " ";
        }
        return res;
    }


};
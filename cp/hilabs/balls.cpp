#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<int> pre(n,0);
    vector<int> suf(n,0);
    for(int i=1;i<n;i++){
        pre[i] = __gcd(pre[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suf[i] = __gcd(suf[i+1],arr[i]);
    }
    int ans =1;
    for(int i =0;i<n;i++){
        int val;
        if(i==0){
            val = suf[i+1];
            ans = max(ans,val);
        }
        else if(i==n-1){
            val = pre[i-1];
            ans = max(ans,val);
        }
        else{
            val = __gcd(pre[i-1],suf[i+1]);
            ans = max(ans,val);
        }
    }
    cout<<ans<<endl;
    return 0;
}
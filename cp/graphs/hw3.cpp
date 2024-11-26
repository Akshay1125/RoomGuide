#include<bitset>/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    
    vector<int> v(n,0);

    for(int i =0;i<n;i++){
        cin>> v[i]%100;
    }

    int pro = 1;

    for(int i =0;i<n;i++){
        pro = pro%100000;
        pro*=v[i];
    }

    while(pro%10 ==0 ){
        pro = pro/10;
    }

    cout<<pro%10<<endl;
}
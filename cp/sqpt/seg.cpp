#include<bitset>/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int low=1;
    int high = n-1;
    int p1= 0;
    int ans =0;
    while(low<=high){

        int mid = (low+high)/2;
        int len =mid;
        int flag=0;
        int p2 = p1+1;
        int seg=0;
        while(p2<=n){

            if(arr[p1]>=arr[p2+seg]){
                seg++;
                if(seg==len+1){
                    p1++;
                    flag=1;
                    p2 = p2+seg-1;
                    if(p2>n-1) {
                        high = mid-1;
                        ans = mid;
                        break;
                    }
                }

            }
            else{
                seg=0;
                p1=0;
                low = mid+1;
                break;
            }

        }

    }
    if(ans==0) cout<< -1<<endl;
    else cout<<ans<<endl;
    return 0;


}
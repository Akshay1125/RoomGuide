#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m,k ;
    cin>>n>>m>>k;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>v[i][j];
        }
    }

    vector<vector<int>> row(n, vector<int>(m));
    vector<vector<int>> col(n, vector<int>(m));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            int el = v[i][j];
            int cntr =0;
            for(int l=0;l<m;l++){
                if(el == v[i][l]){
                    cntr++;
                }
            }
            row[i][j] = cntr-1;
        }
    }


    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            int el = v[i][j];
            int cntr =0;
            for(int l=0;l<n;l++){
                if(el == v[l][j]){
                    cntr++;
                }
            }
            col[i][j] = cntr-1;
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            pq.push({row[i][j]+col[i][j]+1, {i, j}});
        }
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<row[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<col[i][j]<<" ";
        }
        cout<<endl;
    }
    int flag=1;
    int g =-1;
    int cnt =0;
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(v[x][y]!=g){
            cnt++;
            int ele = v[x][y];
            for(int i=0;i<m;i++){
                if(v[x][i] == ele){
                    v[x][i] = g;
                }
            }

            for(int i=0;i<n;i++){
                if(v[i][y] == ele){
                    v[i][y] = g;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
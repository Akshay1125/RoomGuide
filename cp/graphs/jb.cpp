#include<bits/stdc++.h>
using namespace std;


vector<int> toposort(int v, vector<pair<int,int>> adj[]){
    int indeg[v] = {0};
    
    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indeg[it.second]++;
        }
    }

    queue<int> q;
    for(int i =0;i<v;i++){
        if(indeg[i]==0) q.push(i);
    }


    vector<int> topo;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it : adj[node]){

            indeg[it.second]--;

            if(indeg[it.second]==0) q.push(it.first);

        }

    }

    return topo;
}

void dfs(int node,vector<pair<int,int> > adj[],vector<int> &noncycle,vector<int> &vis,int sum,vector<int> &vec){
    
    vis[node] =1;
    for(auto it : adj[node]){
        if(!vis[it.first] && noncycle[it.first]==1){
            sum+=it.second;
            dfs(it.first,adj,noncycle,vis,sum,vec);
        }
        else if(vis[it.first] && noncycle[it.first]==1){
            vec.push_back(sum);
        }

    }
    

    
}

int main(){
    int v;
    cin>>v;

    int e;
    cin>>e;


    vector<pair<int,int>> adj[v];
    for(int i =0;i<e;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});

    }
    vector<int> topo = toposort(v,adj);
    vector<int> noncycle(v,1);
    vector<int> vis(v,0);
    vector<int> vec;

    for(int i =0;i<topo.size();i++){
        noncycle[topo[i]] = 0;
        vis[topo[i]] = 1;
    }
    for(int i =0;i<v;i++){
        if(!vis[i]){
            int sum =0;
            dfs(i,adj,noncycle,vis,sum,vec);
        }
    } 
    int mini = 0;
    for(auto it : vec){
        cout<<it << " ";
    }
    for(auto it :vec){
        
        if(it<mini) mini = it;
    }

    cout<<mini<<endl;

    return 0;
}
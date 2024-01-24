//POTD 24-01
bool bfs(int node,vector<vector<int>> &adj,vector<int> &vis,int p){
    vis[node]=1;
    queue<pair<int,int>> q;
    q.push({node,p});
    while(!q.empty()){
        node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else{
                if(it!=par) return true;
            }
        }
    }
    return false;
}
int isTree(int n, int m, vector<vector<int>> &pre){
    if(m==0){
        if(n==1) return 1;
        return 0;
    }
    vector<int> vis1(n,0);
    for(int i=0;i<m;i++){
        vis1[pre[i][0]]=1;
        vis1[pre[i][1]]=1;
    }
    for(int i=0;i<n;i++){
        if(vis1[i]==0) return 0;
    }
    vector<int> vis(n,0);
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        adj[pre[i][0]].push_back(pre[i][1]);
        adj[pre[i][1]].push_back(pre[i][0]);
    }
    if(bfs(0,adj,vis,-1)) return 0;
    for(int i=0;i<n;i++){
        if(vis[i]==0) return 0;
    }
    return 1;
}

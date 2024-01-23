//POTD 23-1
vector<int> findOrder(int n, int m, vector<vector<int>> p){
    vector<vector<int>> adj(n);
    vector<int> in(n,0);
    vector<int> ans;
    queue<int> q;
    int t;
    for(int i=0;i<m;i++) adj[p[i][1]].push_back(p[i][0]);
    for(int i=0;i<m;i++) in[p[i][0]]++;
    for(int i=0;i<n;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        t=q.front();
        ans.push_back(t);
        q.pop();
        for(auto it:adj[t]){
            in[it]--;
            if(in[it]==0) q.push(it);
        }
    }
    if(ans.size()==n) return ans;
    ans.clear();
    return ans;
}

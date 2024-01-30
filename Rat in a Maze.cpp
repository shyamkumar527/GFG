void RatPath(string s,int d,int r,int n,vector<string>& v,vector<vector<int>> &arr,vector<vector<int>> &vis){
    vis[d][r]=1;
    if(r==n-1 and d==n-1){
        v.push_back(s);
        return;
    }
    if(d<n-1 and arr[d+1][r]==1 and vis[d+1][r]==0){
        s.push_back('D');
        RatPath(s,d+1,r,n,v,arr,vis);
        s.pop_back();
        vis[d+1][r]=0;
    }
    if(r<n-1 and arr[d][r+1]==1 and vis[d][r+1]==0){
        s.push_back('R');
        RatPath(s,d,r+1,n,v,arr,vis);
        s.pop_back();
        vis[d][r+1]=0;
    }
    if(d>0 and arr[d-1][r]==1 and vis[d-1][r]==0){
        s.push_back('U');
        RatPath(s,d-1,r,n,v,arr,vis);
        s.pop_back();
        vis[d-1][r]=0;
    }
    if(r>0 and arr[d][r-1]==1 and vis[d][r-1]==0){
        s.push_back('L');
        RatPath(s,d,r-1,n,v,arr,vis);
        s.pop_back();
        vis[d][r-1]=0;
    }
}
vector<string> findPath(vector<vector<int>> &m, int n){
    vector<string> v;
    if(m[n-1][n-1]==0 or m[0][0]==0) return v;
    vector<vector<int>> vis(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i].push_back(0);
        }
    }
    RatPath("",0,0,n,v,m,vis);
    return v;
}

//Maximum Connected group
//POTD 11/7/24
class Solution {
  public:
    int vsk(vector<vector<int>>& temp,int i,int j,unordered_map<int,int>& mp){
        unordered_map<int,int> x;
        if(i-1 >= 0 and temp[i-1][j]) x[temp[i-1][j]]=1;
        if(j-1 >= 0 and temp[i][j-1]) x[temp[i][j-1]]=1;
        if(j+1 < temp.size() and temp[i][j+1]) x[temp[i][j+1]]=1;
        if(i+1 < temp.size() and temp[i+1][j]) x[temp[i+1][j]]=1;
        int ans = 1;
        for(auto it : x){
            ans += mp[it.first];
        }
        return ans;
    }
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& temp,int x,int y,int c){
        queue<pair<int,int>> q;
        q.push({x,y});
        temp[x][y]=c;
        int val=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            val++;
            if(i-1>=0 and grid[i-1][j] and temp[i-1][j]==0){
                q.push({i-1,j});
                temp[i-1][j]=c;
            }
            if(j-1>=0 and grid[i][j-1] and temp[i][j-1]==0){
                q.push({i,j-1});
                temp[i][j-1]=c;
            }
            if(j+1<grid.size() and grid[i][j+1] and temp[i][j+1]==0){
                q.push({i,j+1});
                temp[i][j+1]=c;
            }
            if(i+1<grid.size() and grid[i+1][j] and temp[i+1][j]==0){
                q.push({i+1,j});
                temp[i+1][j]=c;
            }
        }
        return val;
    }
    int MaxConnection(vector<vector<int>>& grid){
        int n=grid.size(),c=1,val,ans=0;
        unordered_map<int,int> mp;
        vector<vector<int>> temp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] and temp[i][j]==0){
                    val=bfs(grid,temp,i,j,c);
                    ans=max(ans,val);
                    mp[c]=val;
                    c++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    ans=max(ans,vsk(temp,i,j,mp));
                }
            }
        }
        return ans;
    }
};

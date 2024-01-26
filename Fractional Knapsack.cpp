double fractionalKnapsack(int w, Item arr[], int n){
    double ans=0,x,a,b;
    int ind;
    priority_queue<pair<double,int>> q;
    for(int i=0;i<n;i++){
        a=arr[i].value;
        b=arr[i].weight;
        x=a/b;
        q.push({x,i});
    }
    while(!q.empty()){
        if(w==0) break;
        x=q.top().first;
        ind=q.top().second;
        q.pop();
        if(arr[ind].weight<=w){
            w-=arr[ind].weight;
            ans+=arr[ind].value;
        }
        else{
            ans+=(x*w);
            break;
        }
    }
    return ans;
}

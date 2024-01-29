void rec(int op,int cl,int n,string s,vector<string>& ans){
    if(op==n and cl==n){
        ans.push_back(s);
        return;
    }
    if(op<n) rec(op+1,cl,n,s+"(",ans);
    if(op>cl) rec(op,cl+1,n,s+")",ans);
}
vector<string> AllParenthesis(int n){
    vector<string> ans;
    rec(0,0,n,"",ans);
    return ans;
}

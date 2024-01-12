int num=1e4+1;
vector<int> v(num,1);
vector<int> primes;
class Solution{
public:
    void seive(){
        v[0]=v[1]=0;
        if(v[4]==0) return;
        for(int i=2;i*i<=num;i++){
            if(v[i]==1){
                for(int j=2*i;j<=num;j+=i) v[j]=0;
            }
        }
        for(int i=2;i<=num;i++){
            if(v[i]==1) primes.push_back(i);
        }
    }
    int kthPrime(int n, int k){
        seive();
        int ans=-1,c=0,vsk=n;
        if(v[n]==1){
            if(k==1) return n;
            return ans;
        }
        for(int i=0;i<primes.size();i++){
            if(primes[i]>(vsk/2)) break;
            while(n%primes[i]==0){
                n/=primes[i];
                c++;
                if(c==k) return primes[i];
            }
        }
        return ans;
    }
};

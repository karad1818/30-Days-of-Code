/*Today's topic is Rolling hash and bloom filters

Learning Resources :
                    1.video : https://www.youtube.com/watch?v=rA1ZevamGDc&list=PL1dLU3zjLr71xeAitgNBwp04JbGzAhn0j&index=36
                    2.Blog : https://cp-algorithms.com/string/string-hashing.html
*/

/* to decrease probability of collision use multiple Prime */

struct RollingHash{
    arr pre;
    const long long m=17;
    ll mmi;
    const long long M1=1000000007;
    ll MMI(ll a,ll m){
        ll m0=m,y=0,x=1;
        if(m==1) return 0;
        while(a>1){
            ll q=a/m,t=m;
            m=a%m,a=t,t=y,y=x-q*y,x=t;
        }
        if(x<0) x+=m0;
        return x;
    }
    void init(ll n){
        ll ans=1;
        for(int i=0;i<n;i++){
            pre.pb(ans);
            ans=(ans%M1*m%M1)%M1;
        }
        mmi=MMI(m,M1)%M1;
    }
    ll Hash(string s){
        ll ans=0;
        for(int i=0;i<(ll)s.length();i++){
            ans=(ans%M1+((s[i]-'a'+1)*pre[i])%M1)%M1;
        }
        return ans;
    }
    ll Concat(ll hash_of_a,ll hash_of_b,ll length_of_second_string){
        //a+b;
        return (hash_of_a%M1 + (hash_of_b%M1*pre[length_of_second_string]%M1))%M1;
    }
    void removeFirst(ll &ans,string s,ll i){
        ans=(ans-s[i]+M1)%M1;
        ans=(mmi%M1*ans%M1)%M1;
    }
    void addLast(ll &ans,string s,ll i,ll n){
        ans=(ans%M1+((s[i]-'a'+1)*pre[n-1])%M1)%M1;
    }
    
    
};

/* This File contains all the resources that i've used for learn Strongly connected components(SCC) ,
my code for SCC and also solution of Some of the question that I've solved today using SCC. */

/* Learn SCC :
              https://www.youtube.com/watch?v=z9oOadBgO9I
              
*/

/* SCC :
        for every node i , j there exist a path from i to j and j to i.
       
   Observations : lowlink never passes the root of SCC.
  Algorithms : 
              1.Warshall's transitive closure :
                  -> Same as floyd warshall algorithm 
                  -> complexity : O(V^3)
                  -> code : https://ideone.com/FRrxtu
              2.Tarjan's Algorithm :
                  ->complexity : O(V + E)
                  ->code : https://ideone.com/EiljmU
              3.Kosaraju's Algorithm :
                  ->complexity : O(V + E)
                  ->code : https://ideone.com/RTEiae
*/
//Code Template for Tarjan and kosaraju

struct Tarjan{
    vector<ll>id,pre,lowlink;
    vector<ll>scc[100010];  //stores meta graph that are created.
    stack<ll>st;
    ll numSCC,n,m;  //numSCC is a number of SCC.
    ll preNum;
    vector<ll>adj[100010];
    void input(){
        cin>>n;
        cin>>m;
        while(m--){
            ll a,b;
            cin>>a>>b;
            adj[a].pb(b);
        }
    }
    void init(){
        id.assign(2*n,0);
        pre.assign(2*n,-1);
        lowlink.assign(2*n,0);
        numSCC=1;
        preNum=0;
        while(st.size())
            st.pop();
    }
    void Solve(){
        for(int i=1;i<=n;i++){
            if(pre[i]==-1){
                dfs(i);
            }
        }
    }
    void dfs(ll node){
        pre[node]=preNum++;
        lowlink[node]=pre[node];
        st.push(node);
        for(auto i : adj[node]){
            //forward edge
            if(pre[i]==-1){
                dfs(i);
            }
            //backedge
            lowlink[node]=min(lowlink[node],lowlink[i]);
        }
        //we are at root
        if(lowlink[node]==pre[node]){
            while(true){
                ll s=st.top();
                st.pop();
                //set id for SCC
                id[s]=numSCC;
                scc[numSCC].pb(s);
                //set lowlink as max
                lowlink[s]=INT_MAX;
                //if we are at root break;
                if(s==node)
                    break;
            }
            numSCC++;
        }
    }
};

struct Kosaraju{
	using ll=long long;
    ll n,m,numSCC;
    vector<ll>adj[100001],rev[100001],order,scc[100001];
    bool vis[100001];
    void input(){
        cin>>n>>m;
        while(m--){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            rev[b].push_back(a);
        }
    }
    void init(){
        for(int i=1;i<=100001;i++)
            adj[i].clear(),rev[i].clear(),scc[i].clear();
        order.clear();
        memset(vis,0,sizeof(vis));
        numSCC=1;
    }
    void Solve(){
        for(int i=1;i<=n;i++){
            if(!vis[i])
                dfs(i);
        }
        memset(vis,0,sizeof(vis));
        for(int i=n-1;i>=0;i--){
            if(!vis[order[i]]){
                dfs_rev(order[i]);
                numSCC++;
            }
        }
    }
    void dfs(ll node){
        vis[node]=1;
        for(auto i : adj[node]){
            if(!vis[i])
                dfs(i);
        }
        order.push_back(node);
    }
    void dfs_rev(ll node){
        vis[node]=1;
        scc[numSCC].push_back(node);
        for(auto i : rev[node]){
            if(!vis[i]){
                dfs_rev(i);
            }
        }
    }
};

/*
    Problem : 
              1.https://codeforces.com/problemset/problem/427/C
                            Solution : https://ideone.com/8tCzmw
              2.https://www.spoj.com/problems/TFRIENDS/
                            Solution : https://ideone.com/tkYiIW

*/

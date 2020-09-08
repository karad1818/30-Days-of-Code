/*   
  Today's topic is heavy-light decomposition.
  Resources to learn : 
                        Video : https://www.youtube.com/watch?v=_G_LMuLWMaI
                        Blog : https://blog.anudeep2011.com/heavy-light-decomposition/
                  
*/

/*
  we have at most log(n) light edges after partition into edges.
  and we'll build segment tree on heavy edges.
  so overall complexity gonna be O(log(n) * log(n))  <-- For query
*/

struct heavy_light{
    ll chainNo,n;
    arr chainHeads,chainPos,chainInd,chainSize,adj[100001],subSize,vis,par;
    void input(){
        ll m;
        cin>>n;
        m=n-1;
        while(m--){
            ll x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }
    void init(){
        n++;
        vis.assign(n,0);
        chainHeads.assign(n,-1);
        chainPos.assign(n,0);
        chainInd.assign(n,0);
        chainSize.assign(n,0);
        subSize.assign(n,0);
        par.assign(n,0);
        chainNo=0;
        n--;
    }
    void Solve(){
        ll x=dfs(1);
        x++;
        HLD(1);
    }
    void HLD(ll currNode){
        // cout<<currNode<<endl;
        if(chainHeads[chainNo]==-1){
            //current node is starting node for chain
            chainHeads[chainNo]=currNode;  
        }
        chainInd[currNode]=chainNo;         //give a current node a chain number
        chainPos[currNode]=chainSize[chainNo];  //position of node in chain
        chainSize[chainNo]++;  //increae chain size for chainNo
        
        ll heavyChild=-1,maxSize=0;
        for(auto i : adj[currNode]){
            if(subSize[i]>maxSize and i!=par[currNode]){
                maxSize=subSize[i];
                heavyChild=i;
            }
        }
        //extract heavychild
        if(heavyChild>=0)
            HLD(heavyChild);
        for(auto i : adj[currNode]){
            if(i!=heavyChild and i!=par[currNode]){
                chainNo++;
                //extract light child
                HLD(i);
            }
        }
    }
    ll dfs(ll node){
        ll size=1;
        vis[node]=1;
        for(auto i : adj[node]){
            ll x=0;
            if(!vis[i]){
                par[i]=node;
                x+=dfs(i);
            }
            size+=x;
        }
        subSize[node]=size;
        return size;
    }
};

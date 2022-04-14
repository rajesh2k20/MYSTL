void dijks(vector<vector<pair<int, int>>> & adj, int src){
    // global dp array .
    set<pair<int, int>> s; // store the cost , node ;
    s.insert({0,src});

    dp[src]=0;
    
    for(int i=1; i<adj.size();i++){
         if(s.size()==0){
             return ;
         }

         auto it= s.begin();
         int u= it->second;
         int w= it->first;
         s.erase(it);
        for(auto  x: adj[u]){

             int v= x.first;
             int w1=x.second;

             if(dp[u]+w1<dp[v]){
                 s.erase({dp[v], v});
                 dp[v]=dp[u]+w1;
                 s.insert({dp[v], v});
             }
        }


    }
}

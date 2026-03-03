#include<bits/stdc++.h>
#define int         int64_t
#define ll          long long 
#define pb          push_back
#define endl        '\n'
#define pll         pair<int,int>
#define vll          vector<int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mi        map<int,int>
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
vector<vector<int>> adj;
vector<int> col;
vector<int> parentNodes;
vector<int> any_cycle;
bool iscycle=false;
 
void dfs(int src, int par){
 
	col[src]=1;
	parentNodes[src]=par;
	for(int nb : adj[src]){
		if(nb ==par){
			continue;
		}
		if(col[nb]==0){
			dfs(nb, src);
		}else if(col[nb]==1){
             
               // src->nb
			 if(iscycle==false){
			 	 // cout<<src<<" "<<nb<<endl;
			  int temp=src;
			  while(temp!=nb){
			  	  // cout<<temp<<" ";
                  any_cycle.push_back(temp);
                  temp=parentNodes[temp];
			  }
			  any_cycle.push_back(temp);
			  any_cycle.push_back(src);
			 }
             iscycle=true;
		}else{
          // ignore
		}
	}
	col[src]=1;
}
void solve(){
 
   int n, m;
   cin>>n>>m;
   adj.resize(n+1);
   col.resize(n+1,0);
   parentNodes.resize(n+1,0);
   for(int i=1;i<=m;i++){
   	 int u,v;
   	 cin>>u>>v;
   	 adj[u].push_back(v);
   	 adj[v].push_back(u);
   }
 
    for(int i=1;i<=n;i++){
      if(col[i]==0){
         dfs(i, 0);
      }
   }
 
   if(iscycle){
   	  // cout<<"YES ";
   	  // for(int i=1;i<=n;i++){
   	  // 	  cout<<i<<" "<<parentNodes[i]<<endl;
   	  // }
   	  cout<<any_cycle.size()<<endl;
   	  reverse(any_cycle.begin(), any_cycle.end());
   	  for(int val : any_cycle){
   	  	 cout<<val<<" ";
   	  }
   	  cout<<endl;
   }else{
   	  cout<<"IMPOSSIBLE";
   }
 
   
}
signed main(){
    ios
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
        
    int test=1;
    // cin>>test; 
    while(test--){
        solve();
    }    
    return 0;
 }

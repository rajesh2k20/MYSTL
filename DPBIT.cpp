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
int dp[30][(1LL<<22)];
int mat[30][30];
void  add( int  & set, int index){


    set |= (1LL<<index);
}
void remove(int & set, int index){

    if(  (1LL<<index & set)!=0){

         set^= 1LL<<index;
    }
}
void display(int set, vector<int> & arr){
  int n=arr.size();

    for(int i=0 ; i<10 ;i++){


        if( ( (1LL<<i)& set ) !=0 ){

             cout<<arr[i]<<" ";
        }
    }

    
}

int helper(int index, int mask, int n){


    if( mask == ((1LL<<n)-1)){

        return 1;
    }

    if(dp[index][mask]!=-1){

        return dp[index][mask];
    }

    int ans=0;
    for(int i= 0; i<n;i++){
          
       if(  ((1LL<<i) & mask) ==0 and mat[index][i]==1){

            int val= helper(index+1, mask|(1LL<<i),n);
            val%=hell;
            ans+=val;
            ans%=hell;
       }
    }

    return  dp[index][mask]= ans;
}
void solve(){
    
    
    int n=0;
    cin>>n;

   
    for(int i=0; i<n;i++){

        for(int j=0; j<n;j++){

            cin>>mat[i][j];
        }
    }

    int mask=0;
    memset( dp, -1, sizeof(dp));
    int ans=helper(0, mask, n);

    cout<<ans<<endl;




}
signed main(){
    ios
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
        
    int test=1;
    //cin>>test; 
    while(test--){
        solve();
    }    
    return 0;
}

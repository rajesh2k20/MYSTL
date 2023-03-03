class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    int strStr(string str, string needle){
        
        
        
        
        long long  x=1;
        
        long long val1=0;
        
        int mod=1e9+7;
        
        int b1=binpow(31, mod-2, mod);
        
        for(int i=0; i<needle.size();i++){
            
             int val= (needle[i]-'a')+1;
            
             val1+= (1LL*val*x)%mod;
            
             val1%=mod;
            
             x*=31;
            
             x%=mod;
            
        }
        
        x= (1LL*x*b1)%mod;
        
        cout<<val1<<endl;
        
        
        
        long long  val2=0;
        
        long long x2=1;
        
        
        for(int i=0; i< str.size();i++){
            
            
            if(i<needle.size()){
                
                long long val= (str[i]-'a')+1;
                
                val2+= (1LL*val*x2)%mod;
                
                val2%=mod;
                
                x2*=31;
                
                x2%=mod;
            }else{
                
                // cout<<val2<<endl;
                
                if(val1==val2){
                    return i-needle.size();
                }
                
                long long val= (str[i-needle.size()]-'a')+1;
                
                val2= (val2-val+mod)%mod;
                
                val2= (1LL*val2*b1)%mod;
                
                val= ((1LL*x*((str[i]-'a')+1)))%mod;
                
                val2+=val;
                
                val2%=mod;
            }
            
            
        }
        
        if(val1==val2){
            
            return  str.size()-needle.size();
        }else{
            
            return -1;
        }
        
        
        
    }
};

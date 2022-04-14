class dsu{

    public :
     int *par;
     int *height;
     dsu(int n){
         par=new int[n+1];
         height=new int[n+1];
         for(int i=0;i<=n;i++){
             par[i]=i;
             height[i]=1;
         }
     }

    int root(int a){

        if(a==par[a]){
            return a;
        }
        par[a]=root(par[a]);
        return par[a];
    }

    void un(int a,int b){

        int roota=root(a);
        int rootb=root(b);
        if(roota==rootb){
            return;
        }
        else{
            int heighta=height[a];
            int heightb=height[b];
            if(heighta>heightb){
                par[rootb]=roota;


            }else if(heightb>heighta){
              par[roota]=rootb;
            }else{
                par[roota]=rootb;
                height[roota]++;
            }
        }

    }
    int find(int a,int b){

        int roota=root(a);
        int rootb=root(b);
        return roota==rootb;
    }

};

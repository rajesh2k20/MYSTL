class store{
   
   public:

       int sum=0;

       store (int s=0){
           sum=s;
       }

};

class segment{

    vector<int> arr;
    vector<store> tree;
    int size;

   
private:
    store merge(store f1, store f2){

        return store(f1.sum+ f2.sum);
    }
    
    void build(int l, int r, int p){
       
       if(l==r){

             tree[p]= store(arr[l]);
           return ;
       }
       int mid= (l+r)/2;

       build(l, mid, 2*p);
       build(mid+1, r, 2*p+1);

       tree[p]= merge(tree[2*p], tree[2*p+1]);
    }

    void update(int l, int r, int index, int val, int p){

        if(l==r){

           
           tree[p]=store(val);

           return ;

        }

        int mid= (l+r)/2;

        if(mid>=index){
         
           update(l, mid, index, val, 2*p);

        }else{

            update(mid+1, r, index, val, 2*p+1);
        }


        tree[p]= merge(tree[2*p], tree[2*p+1]);
        
    }

    store query(int l, int r, int s, int e, int p){

      if(e<l || s>r){
           return store();
      }

      if(l>=s and r<=e){
           return tree[p];
      }

        int mid= (l+r)/2;
        store ans1=query(l, mid, s, e, 2*p);
        store ans2=query(mid+1, r, s, e, 2*p+1);

        return merge(ans1, ans2);

    }

public:
     segment(vector<int> a, int n){
        arr=a;
        tree.resize(4*n+1, 0);
        size=n;
        build(1, size, 1);
    }
    


    store query(int s, int e){

        return query(1, size, s, e, 1);
    }

     void update( int index, int val){

        update(1,size, index, val, 1);
    }

};

class myhash{

private:

    int * table;
    int size;

    int m=7;// any prime wich is close to size .

public:


    myhash(int size){

        this->size=size;

        table=new int [size];

        for(int i=0; i<size;i++){

            table[i]=-1;
        }
    }


    int h1(int key){


        return key%m;
    }

    int h2(int key){


        return  ((m-1)- (key)%(m-1));
    }


    void insert(int key){


        int probing = h1(key);

        int initial_probing=probing;

        int offset=h2(key);

        while(table[probing] !=-1 and table[probing] !=-2 
            and table[probing] !=key ){


           

           probing+= offset;


           probinf %=m;

           if(initial_probing ==probing){
              cout<<"Size is full";
              return;

           }

        }

        table[probing]=key;



    }


    bool search(int key){



        int probing = h1(key);

        int initial_probing=probing;

        int offset=h2(key);

        while(table[probing] !=-1 ){


            if(table[probing]==key){
                return true;
            }

           probing+= offset;


           probinf %=m;

           if(initial_probing ==probing){
              cout<<"Not found";
              return;

           }

        }

         cout<<"Not found";


    }


    void del(int key){


        int probing = h1(key);

        int initial_probing=probing;

        int offset=h2(key);

        while(table[probing] !=-1 ){


            if(table[probing]==key){
                table[probing]=-2;
                return true;
            }

           probing+= offset;


           probinf %=m;

           if(initial_probing ==probing){
              cout<<"Not found";
              return;

           }

        }

         cout<<"Not found";




    }


}

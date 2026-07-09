#include<fstream>
using namespace std ;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int Cmmdc(long long a , long long b ){
        while(b!=0){
            int r = a%b;
             a = b ;
              b = r ; 
        }
        return a ; 
}
int main(){

  
    long long n , x , k ;
      cin>>n;
        for(int i = 1 ; i <= n ; i ++  ){
              cin>>x>>k;
                cout<<Cmmdc(x,k)<<endl;
        }












    return 0 ; 
}
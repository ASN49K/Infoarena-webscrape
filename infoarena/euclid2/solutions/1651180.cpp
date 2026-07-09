#include <fstream>

using namespace std ;

 ifstream fin("euclid2.in");
 ofstream fout ("euclid2.out");

 int gcd(int a , int b ){
        if(!b) return a;
        else return gcd( b , a % b );
 }


int main (){
int T ;

    for( ; T ; --T){

        int a , b ;

            fin >> a >> b ;
            fout << gcd(a , b) ;
}
        return 0 ;
}

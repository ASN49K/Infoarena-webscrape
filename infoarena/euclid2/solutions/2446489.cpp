#include<fstream>
using namespace std  ;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){
unsigned int n ,a , b  ;

f>> n ;


while ( n){
    n--;
f>>a>>b;

    unsigned d ;


    while(b)
        d = a%b , a = b , b = d ;

       g << a << "\n";

}


return 0 ;
}

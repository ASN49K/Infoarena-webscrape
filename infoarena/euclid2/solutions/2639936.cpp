#include <iostream>
#include <fstream>

using namespace std;
int algoritmEclidScadere(int nr1 , int nr2);
int main()
{

    ifstream fisier_in("euclid2.in");
    ofstream fisier_out("euclid2.out");
int t;
fisier_in >> t;

for(int i = 0 ; i < t ; i++){
    int x,y;
    fisier_in >> x >> y;
    int r =  algoritmEclidScadere(x,y);
    fisier_out<< r;
}
return 0 ;

}

int algoritmEclidScadere(int nr1 , int nr2){

// n este numarul mai mare ca m;
int m,n;
if(nr1 < nr2){
    n = nr2;
    m= nr1
}else{
m = nr1 ; n = nr2;
}

    while ( n != m){
    n = n - m;
    }

    return m;

}

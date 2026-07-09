#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fisier_in("euclid2.in");
    ofstream fisier_out("euclid2.out");
int t;
fisier_in >> t;

for(int i = 0 ; i > t ; i++){
    int x,y;
    fisier_in >> x >> y;
    fisier_out<< algoritmEclidScadere(x,y) << "\n";


}

}

int algoritmEclidScadere(int nr1 , int nr2){

// n este numarul mai mare ca m;
int m,n;
    if(nr1 > nr2 ){
        n = nr1;
        m = nr2;
    }else if( nr1 == nr2){
        return nr1;
    }else{
    m = nr1;
    n = nr2;
    }
    while ( n != m)
    m = n - m;

    return m;

}

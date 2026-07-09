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
        fisier_out << r << endl;
    }
return 0;

}

int algoritmEclidScadere(int nr1 , int nr2){

// n este numarul mai mare ca m;
int m,n;

    m = nr1 ; n = nr2;


    while ( n != m){
        if(n > m)
            n-=m;
            else
            m-=n;
    }

    return m;

}

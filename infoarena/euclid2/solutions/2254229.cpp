#include <iostream>
#include <fstream>


using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int Euclid( int x, int y){
    int z;
    while( y){
        z= x%y;
        x=y;
        y=z;
    }
    return x;
}

int main()
{
    int a, b, n;
    in>>n;
    for(int i=1; i<=n; ++i){
       in>>a>>b;
       out<<Euclid(a, b)<<"\n";
    }

    return 0;
}

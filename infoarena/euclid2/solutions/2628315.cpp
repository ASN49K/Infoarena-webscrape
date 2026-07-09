#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
vector <unsigned> v;
unsigned t , nr1,nr2, i,r;
unsigned euclid(unsigned a , unsigned b){
    while( b != 0 ){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void citire(){
    fin >> t;
    for( i = 0 ; i < t ; ++i ){
        fin >> nr1 >> nr2;
        fout << euclid(nr1, nr2) << endl;
    }
}

int main()
{
    citire();
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
vector <unsigned> v;
unsigned t , nr, i,r;
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
    for( i = 0 ; i < t * 2; ++i ){
       fin >> nr;
       v.push_back(nr);
    }
    for( i = 0 ; i < t * 2 ; i+=2 ){
        fout << euclid(v[i],v[i+1]) << endl;
    }
}

int main()
{
    citire();
    return 0;
}

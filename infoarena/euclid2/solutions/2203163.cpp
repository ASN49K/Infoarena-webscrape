//Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche
//in parte
#include <iostream>
#include <fstream>
int a,b,n;
using namespace std;
int cmmdc(int a, int b){

    if(b==0){
        return a;
    }else{
       return cmmdc(b,a%b);
    }
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(n;n;--n){
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}

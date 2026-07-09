#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

//Gasesc minimul dintre cele 2 numere a si b
int gasesteMinim(int a,int b){
    if(a > b)
        return b;
    else
        return a;
}

//Parcurg de la minim(a,b) la 2, cautand cel mai mare divizor comun a perechii a si b
void gasesteCMMDC(int a,int b){
    for(int i = gasesteMinim(a,b);i >= 1;i--){
        if(a%i == 0 && b%i == 0){
            fout<<i<<endl;
            break;
        }
    }
}

int main()
{
    unsigned int a,b,t;

    fin>>t;

    for(int i = 1; i <= t ; i++){
        fin>>a>>b;

        gasesteCMMDC(a,b);
    }
    return 0;
}

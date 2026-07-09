#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fisier.in");
ofstream fout("fisier.out");

int main()
{
    int a,b,d,x;

    fin>>a;
    fin>>b;

    if(a<b){
        x=a;
        a=b;
        b=x;
    }

    if(a%b == 0)
    {
        d=b;
    }
    else{
        d=a%b;
    }
    fout<<d<<'\n';
    return 0;
}

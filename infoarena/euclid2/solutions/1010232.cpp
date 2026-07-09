#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

long long int a,b,t;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void citire()
{
    fin>>a;
    fin>>b;
}

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else cmmdc(b,a%b);

}


int main()
{
    fin>>t;
    while(t){
    citire();

    fout<<cmmdc(a,b);
    t--;
    }



    return 0;
}

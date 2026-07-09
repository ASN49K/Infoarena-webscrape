#include <iostream>
#include <fstream>

using namespace std;


ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int nrTeste;

int euclid(int a,int b)
{
    int c;

    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }

    return a;
}

int main()
{
    fi>>nrTeste;

    for(int test=1; test<=nrTeste; test++)
    {
        int a,b;
        fi>>a>>b;
        fo<<euclid(a,b)<<endl;
    }
    return 0;
}

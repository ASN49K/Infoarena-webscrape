#include <iostream>
#include <fstream>

using namespace std;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T,a,b,rest,i;

int main()
{
     int T,a,b,rest,i;
     fin>>T;
     for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        fout<<a<<endl;
    }
    return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

int a,b,r,t,i;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>t;
    for(i=0;i<t;i++)
    {
        fin>>a;
        fin>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }


    return 0;
}

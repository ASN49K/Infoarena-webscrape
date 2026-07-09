#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,d,i,t;
    fin>>t;
    for(i=1;i<=t;i++)
    {
    fin>>a>>b;
    while(b!=0)
    {
    d=a%b;
    a=b;
    b=d;
    }
    fout<<a<<endl;
    }
    return 0;
}

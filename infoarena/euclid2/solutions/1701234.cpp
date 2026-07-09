#include <iostream>
#include<fstream>
using namespace std;
int a,b,t;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(int i=1;i<=t;++i)
    {
        fin>>a>>b;
        while(b)
        {
            int temp=a%b;
            a=b;
            b=temp;
        }
        fout<<a<<"\n";
    }
}

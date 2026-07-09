#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,c,i;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}

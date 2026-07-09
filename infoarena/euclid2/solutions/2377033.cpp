#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,T,i,j,r;
    fin>>T;
    if(a>b) r=b;
    else r=a;
    for(i=1;i<=T;i++)
        fin>>a>>b;
    {
       for(j=r;j<=1;j--)
       {
           if((a/j==0) && (b/j==0)) fout<<j<<endl;

       }


    }

    fin.close();
    fout.close();
    return 0;
}

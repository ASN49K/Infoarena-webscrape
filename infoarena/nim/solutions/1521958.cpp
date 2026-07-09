#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int m,n,i=0,x,s,j;

int main()
{
   f>>m;
   for(i=1;i<=m;i++)
       {
           f>>n;
           s=0;
           for(j=1;j<=n;j++)
                {
                    f>>x;
                    s=s^x;
                }
            if(s) g<<"DA"<<endl;
            else g<<"NU"<<endl;
       }

    return 0;
}

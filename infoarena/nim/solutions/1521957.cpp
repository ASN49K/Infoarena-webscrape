#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int m,n,i,x,s;

int main()
{
   f>>m;
   for(i=1;i<=m;i++)
       {
           f>>n;
           s=0;
           for(i=1;i<=n;i++)
                {
                    f>>x;
                    s=s^x;
                }
            if(s>0) g<<"DA"<<endl;
            else g<<"NU"<<endl;
       }
cout<<m;
    return 0;
}

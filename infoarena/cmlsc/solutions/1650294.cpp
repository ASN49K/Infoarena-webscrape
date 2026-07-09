#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v1[100],v2[100],m,n,i,j,ok,z,ii,x[100];

void citire();
void program();

int main()
{
citire();
program();

g<<z<<"\n";
for(i=0;i<z;i++)
 g<<x[i]<<" ";

 return 0;
}


void citire()
{
    f>>m>>n;

        for(i=0;i<m;i++)
            {

                f>>v1[i];

            }

        for(j=0;j<n;j++)
            {

                f>>v2[j];

            }

}

void program()
{

 for(j=0,i=0;j<n;j++)
    {
     while(i<m&&ok==0)
       {
        if(v2[j]==v1[i])
            {ok=1;
             ii=i;
            }
        i++;
       }
       if(ok)
         {x[z]=v1[ii];
          z++;
         }
       ok=0;
       i=ii;

    }






}

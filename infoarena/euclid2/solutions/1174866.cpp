#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f;
ofstream g;

long int m,n,i,j,mn;

long int euclid(int i,int j)
        {
         if(i==0||j==0)return abs(j-i);
         else
         if(i>j)return euclid(i%j,j);
         else
         return euclid(i,j%i);

        }

int main()
{
f.open("euclid2.in");
g.open("euclid2.out");
f>>n;

while(n>0)
        {
        n--;
        f>>i>>j;
        g<<euclid(i,j)<<'\n';
        }
        
f.close();
g.close();
return 0;
}

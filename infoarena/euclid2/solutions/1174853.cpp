#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
ifstream f;
ofstream g;

long int m,n,i,j,mn;

long int euclid(int i,int j)
        {
         if(j==0||i==0)return abs(i-j);
         else
         if(i>j)return euclid(i-j,j);
         else
         return euclid(i,j-i);

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
        g<<euclid(i,j)<<endl;
        }
f.close();
g.close();
return 0;
}

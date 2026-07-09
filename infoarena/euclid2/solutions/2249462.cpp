#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    while(a>0&&b>0)
        if(a>b)
            a=a%b;
        else
            b=b%a;
   return a+b;
}
int main()
{ int a,b,T;

   fin>>T;
   for(int i=0;i<T;i++)
   {
       fin>>a>>b;
       fout<<euclid(a,b)<<'\n';
         }
    return 0;
}

#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
   int n,a,b,i,cmmdc=1,max,j;
   in>>n;
   for (j=0;j<n;j++)
   {


   in>>a>>b;
   if (a==b)cmmdc=a;

   if (a>b)
   {
       while (a-b>0)
       {
          a=a-b;

       }

   }

   else if (b>a)
   {
       while (b-a>0)
       {
          b=b-a;

       }

   }
   if (a>b)
   {
       while (a-b>0)
       {
          a=a-b;

       }

   }

   else if (b>a)
   {
       while (b-a>0)
       {
          b=b-a;

       }

   }

if (a>b) max=a;
if (b>a) max=b;

for (i=1;i<=max/2;i++)
{
    if (a%i==0&&b%i==0) cmmdc=i;
}


out<<cmmdc<<"\n";
}
in.close();
out.close();
return 0;

}

#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n;
int a[1024],b[1024];
short A[1024],B[1024];

int getMax()
{
   int i;
   int l=m-1;
   int maxA=0,maxB=0;
   
   A[l--] = 1;
   while(l>=0)
   {
         A[l]=1;     
         for(i=l+1;i<m;i++)
            if(a[l]<=a[i])
            {
                A[l]=A[i]+1;
                maxA<A[l]?maxA=A[l]:maxA;
                break;          
            }         
      l--;     
   } 
   
   l = n;
   B[l--] = 1;
   while(l>=0)
   {
         B[l]=1;     
         for(i=l+1;i<m;i++)
            if(b[l]<=b[i])
            {
                B[l]=B[i]+1;
                maxB<B[l]?maxB=B[l]:maxB;
                break;          
            }         
      l--;     
   }   
   int j;
   int len=0;
   int final[1024];
   if(maxB<maxA)
   {
      j=m;
      m=n;
      n=j;             
   }
   for(i=0;i<m;i++)
     for(j=0;j<n;j++)
      if(b[i]==a[j]&&maxB==B[i])
       {
        final[len++]=b[i];
        maxB--;
      }
   g << len << "\n";
   for(i=0;i<len;i++)
      g << final[i] << " " ;
   g.close();
   return 0;    
}

int main()
{
   f >> m >> n;
   int i;
   for(i=0;i<m;i++)
      f >> a[i];
   for(i=0;i<n;i++)
      f >> b[i];
   getMax();   
   return 0;    
}

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream in("cmlsc.in");
ofstream g("cmlsc.out");
 int verificare(long long a[],int B,int N)
    {
         int i;
         for(i=0;i<N;i++)
          {
               if(a[i]==B)
                 return 1;
          }
          return 0;
    }
void siruri(long long a[],long long b[],int N,int M)
  {
       int i,contor=0,c[1024];
        for(i=0;i<N;i++)
              if(verificare(a,b[i],M))
                {
                     c[contor++]=b[i];

                }
         g<<contor<<"\n";
         for(i=0;i<contor;i++)
          g<<c[i]<<" ";
  }

 int main(){
   long long a[1024],b[1024];
     int M,N,i,C;
     in>>N>>M;
      for(i=0;i<N;i++)
         in>>a[i];
     for(i=0;i<M;i++)
      in>>b[i];
     if(N>M)
       siruri(a,b,M,N);
      if(M>=N)
       siruri(b,a,N,M);
}

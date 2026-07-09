#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{ 
  int a,b,t,r,i;
  fin>>t;
  for(i=1;i<=t;i++)
  {fin>>a>>b;
   r=a%b;
   while(r)
   {a=b;
   b=r;
   r=a%b;}
   
   fout<<b<<endl;
   
   }
   fin.close();
   fout.close();

  return 0;
}

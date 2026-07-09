#include<fstream.h>   
  
int main()   
{int n,i,m,j,v[1025],t[1025],nr=0,max=0,ok=0,I=0,II=0;
 ifstream f("cmlsc.in");   
 f>>n>>m;   
 for(i=0;i<n;i++)
    f>>v[i];   
 for(i=0;i<m;i++)   
    f>>t[i];   
 f.close();   
  
    while(I<n)   
    {nr=0;   
        for(i=I;i<n;i++)   
         {  for(j=ok;j<m;j++)   
                if(v[i]==t[j])   
                   {nr++;   
                    ok=j+1;   
                    j=m;   
                    }   
  
          if(I==0&&ok==0)   
            i=n;   
          }   
    if(nr>max)   
    {   max=nr;   
        II=I;   
    }   
    ok=0;   
    I++;   
   }   
  
 ok=0;   
 ofstream g("cmlsc.out");
 g<<max<<'\n';
 for(i=II;i<n;i++)   
    for(j=ok;j<m;j++)   
        if(v[i]==t[j])   
           {    g<<v[i]<<" ";   
                ok=j+1;   
                j=m;   
           }   
 g.close();   
  
 return 0;   
}  

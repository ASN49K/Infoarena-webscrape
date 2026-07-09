#include<fstream.h>

long n,m,a[1025],b[1025],c[1025];

int main()
{long i,j;
 ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
 
 f>>n;
 f>>m;
 
 for(i=0;i<n;i++)
                 f>>a[i];
 for(j=0;j<m;j++)
                 f>>b[j];
 
                long contor=0;
       
                  long alfa=0;
                  for(j=0;j<m;j++)
                  {
                                  for(i=alfa;i<n;i++)
                                             if(a[i]==b[j]) {c[++contor]=a[i]; alfa=i;break; }
                                  
                                  }
                                    
                  
            
       
       g<<contor<<"\n";
       for(i=1;i<=contor;i++)
                            g<<c[i]<<" ";
       
 f.close();
 g.close();
 return 0;    
    
}

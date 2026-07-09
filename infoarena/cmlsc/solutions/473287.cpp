#include<fstream.h>

int n,m,a[1024],b[1024],c[1024];

int main()
{int i,j;
 ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
 
 f>>n;
 f>>m;
 
 for(i=0;i<n;i++)
                 f>>a[i];
 for(j=0;j<m;j++)
                 f>>b[j];
 
                 int contor=0;
       if(n<m)
                 {
                  
                  for(j=0;j<m;j++)
                  {
                                  for(i=0;i<n;i++)
                                             if(a[i]==b[j]) {contor++;c[contor]=a[i];  }
                                  }
                                    
                  }
                 
                 else    {
                          for(i=0;i<n;i++)
                  {
                                  for(j=0;j<m;j++)
                                             if(a[i]==b[j]) {c[contor]=a[i];contor++;  }
                                  }

                                                   
                         }
       
       g<<contor<<"\n";
       for(i=0;i<contor;i++)
                            g<<c[i]<<" ";
       
 f.close();
 g.close();
 return 0;    
    
}

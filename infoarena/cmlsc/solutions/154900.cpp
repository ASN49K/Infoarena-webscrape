#include<fstream.h>   
  
int main()   
{int n,m,j,v[40],t[40],nr=0,max=0,ok=0,w=0,ii=0;
 ifstream f("cmlsc.in");
 f>>n>>m;
 for(int i=0;i<n;i++)
	f>>v[i];
 for(i=0;i<m;i++)
	f>>t[i];
 f.close();

	while(w<n)
	{nr=0;
		for(i=w;i<n;i++)
		 {  for(j=ok;j<m;j++)
				if(v[i]==t[j])
				   {nr++;
					ok=j+1;
					j=m;
					}

		  if(w==0&&ok==0)
			i=n;
		  }
	if(nr>max)
	{   max=nr;
		ii=w;
	}
	ok=0;
	w++;
   }

 ok=0;
 ofstream g("cmlsc.out");
 for(i=ii;i<n;i++)
	for(j=ok;j<m;j++)
		if(v[i]==t[j])
           {    g<<v[i]<<" ";   
                ok=j+1;   
                j=m;   
           }   
 g.close();   
  
 return 0;   
}  

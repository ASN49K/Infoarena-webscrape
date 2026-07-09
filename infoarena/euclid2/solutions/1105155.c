#include <stdio.h>
#include <stdlib.h>
long long n,m,v[20][20],s[20],p=-1,i,j;        

 void ver()
      {
                   
     int x,t;        
     for(t=0,i=0;i<n;i++)
     {        
         for(j=0,x=0;j<m;j++)        
             x+=s[j]*v[i][j];        
             t+=((x>0)?x:-x);        
     }        
    if(t>p) p=t;         
    }        
    
void back(int i)
     {        
    if(i<m){        
        s[i]=1;        
        back(i+1);        
        s[i]=-1;        
        back(i+1);        
     }        
    else ver();  
    }    
int main()
{
    FILE *in, *out;
    in = fopen("flip.in", "r");
    out = fopen("flip.out", "w");
 
    fscanf(in,"%lld%lld",&n,&m); 
    
    for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    fscanf(in,"%lld", &v[i][j]); 
    
 
    back(0);
       fprintf(out,"%lld",p); 
       int fclose (FILE *in);
       int fclose (FILE *out);
    return 0;
}   

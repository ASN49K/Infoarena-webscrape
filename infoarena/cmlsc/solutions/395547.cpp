#include<stdlib.h>
#include<stdio.h>

#define max(a,b)  ((a > b) ? a : b) 

int main()
{int i,m,n,j,ct,a[100],b[100],sir[100],l[10][10],lun;
    
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%d %d",&m,&n);
    
    for(i=1;i<=m;i++)
    scanf("%d",&a[i]);
    
    for (i=1;i<=n;i++)
    scanf("%d",&b[i]);
    
    lun=0;ct=1;
  
    for (i=1;i<=m;i++) 
        for (j=1;j<=n;j++)
        {
            if (a[i]==b[j])
           {
           
                              l[i][j]=1 + l[i-1][j-1];
                              
                              }
           else l[i][j]=max(l[i-1][j],l[i][j-1]);
          
                       
                       }
    
    i=m;j=n;
     while (i && j)
     
     {
         if (a[i]==b[j])
         {
            sir[++lun] = a[i];
            i--;
            j--;
            }
         else
         
         if (l[i-1][j]<l[i][j-1]) 
         
            j--;
            
            else
            
            i--;
            }
     printf("%d\n",lun);
  
    for (i=lun;i;i--)
  printf("%d ",sir[i]);


return 0;
}                               

#include <iostream.h>  
int T,a[100000],b[100000],i,x;
int main()
{
    cin>>T;
    for(i=1;i<=T;i++) 
    {
                      cin>>a[i]>>b[i];
                      while(b[i])
                      {
                              x=a[i]%b[i];
                              a[i]=b[i];
                              b[i]=x;
                      }
    }
    for(i=1;i<=T;i++) cout<<a[i]<<endl;
    system("PAUSE"); return 0;
}
    
    

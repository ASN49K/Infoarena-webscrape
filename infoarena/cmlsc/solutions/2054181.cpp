#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;

int main(){
     int ok,m,n, a[1024],b[1024],k,x,maxim,c,l[1024],d[1024];
   ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>n;
    in>>m;
    for(int i=0;i<n;i++)
         in>>a[i];
    for(int j=0;j<m;j++)
         in>>b[j];

        k=0;
        c=m;
          ok=1;
          while(ok==1){
                ok=0;
                k=0;
        for(int i=m;i>0;i++){

               for(int j=c;j>0;j++)
                    if (b[i]==a[j]) {k++;
                                     c=j;
                                     ok=1;
                                     d[k]=b[i];
                                    break;
                                     }
            if(k>maxim) {maxim=k;
                          for(int i=0;i<maxim;i++)
                               l[i]=d[i];
                           }

          }
          }
        out<<maxim<<"\n";
        for(int i=0;i<maxim;i++)
            out<<l[i]<<" ";
    in.close();
    out.close();
return 0;


}

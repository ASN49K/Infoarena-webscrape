#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    int a[1025],b[1025],i,m,n,k=1,j=1,v[1025],poz=0;
    in>>m>>n;
    for(i=1;i<=m;i++) in>>a[i];
    for(i=1;i<=n;i++) in>>b[i];
    if(n < m)
        while(j <= n){
            for(i=1;i<=m ;i++)
                if(b[j] == a[i] && i>poz) { v[k++] = b[j]; poz=i; break;}
            j++;
        }
    if(n >= m)
        while(j <= m){
            for(i=1;i<=n ;i++)
                if(b[j] == a[i] && i>poz) { v[k++] = b[j]; poz=i; break;}
            j++;
        }
    for(i=1;i<k;i++)
        out<<v[i]<<" ";

    return 0;
}

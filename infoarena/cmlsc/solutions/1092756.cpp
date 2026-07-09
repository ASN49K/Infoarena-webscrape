#include <iostream>
#include <fstream>

int n,m,a[1025],b[1025],c[1025][1025],xi,yi;

using namespace std;

int main(){
    fstream ho( 'cmlsc.in');

    ho>>n;
    ho>>m;

    for(int i=1;i<=n;i++)
        ho>>a[i];
    for(int j=1;j<=n;j++)
        ho>>b[j];

    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
            if(a[i]==b[j]){
                c[i][j]=c[i-1][j-1]+1;

            }
            else{
            c[i][j]=max(c[i][j-1],c[i-1][j-1]);
            }

        xi=n;yi=m;

        while(xi>1||yi>1){
            if(xi>1)while(xi>1&&c[xi][yi]==c[xi-1][yi])xi--;
            if(yi>1)while(yi>1&&c[xi][yi]==c[xi][yi-1])yi--;
            x[c[xi][yi]]=a[xi];
            if(xi>1)xi--;
            if(yi>1)yi--;

        }

        fstream write('cmlsc.out')
        write<<c[n][m] << "\n";
        for(int i=1;i<=c[n][m])
            write<<x[i]<<" ";





return 0;

}

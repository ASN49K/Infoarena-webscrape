#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1030], b[1030], v[1030][1030], sir[1030], m, n, x, ok, x1, y1;



int main()
{
    in>>m>>n;
    for(int i=1;i<=m;i++){
        in>>a[i];
        ///v[0][i]=a[i];
    }
    for(int i=1;i<=n;i++){
        in>>b[i];
        ///v[i][0]=b[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(a[i]==b[j]){
                if(ok==0){
                    x1=i;
                    y1=j;
                    ok=1;
                }
                v[i][j]=v[i-1][j-1]+1;


            }else{
                v[i][j]=max(v[i-1][j], v[i][j-1]);
            }
        }
    }
    x=0;
    int i=m, j=n;

    while(i>0 && j>0){

        if(a[i]==b[j]){

                x++;
                sir[x]=a[i];
                --i;
                --j;
            }else{
                if(v[i-1][j]>v[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
    }




    out<<v[m][n]<<'\n';
    for(int i=x;x>=1;x--){
        out<<sir[x]<<" ";
    }




}

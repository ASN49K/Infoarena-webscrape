#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int sol[1025],d[1025][1025];
void cmlsc(int* x,int* y){
    int i,j;
    for(i=1;i<=x[0];i++){
        for(j=1;j<=y[0];j++){
            if(x[i]==y[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    while(j){
        if(x[i]==y[j]){
            sol[0]++;
            sol[sol[0]]=x[i];
            i--;j--;
        }
        else if(d[i-1][j]>d[i][j-1])i--;
        else j--;
    }
    fout<<sol[0]<<endl;
    for(i=sol[0];i>0;i--)fout<<sol[i]<<' ';
}
int main()
{
    int m,n,*a,*b,i;
    fin>>m>>n;
    a=new int[m+1];
    b=new int[n+1];
    a[0]=m;b[0]=n;
    for(i=1;i<=m;i++){
        fin>>a[i];
    }
    for(i=1;i<=n;i++){
        fin>>b[i];
    }
    cmlsc(a,b);
    return 0;
}

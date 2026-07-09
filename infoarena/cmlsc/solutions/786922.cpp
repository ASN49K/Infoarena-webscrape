#include <iostream>
#include <stdio.h>

using namespace std;
int d[1025][1025],n,m,a[1024],b[1024],r[1024],rn=0;

void sorozat(int i,int j){
    if(i>0 && j>0){
        if(d[i][j]==d[i-1][j-1]+1){
            r[rn++]=a[i-1];
            sorozat(i-1,j-1);
        }
        else if(d[i][j]==d[i-1][j]){
                sorozat(i-1,j);
             }
             else{
                sorozat(i,j-1);
             }

    }
}


int main()
{

    FILE *f, *g;
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");

    fscanf(f,"%d %d",&m,&n);
    cout<<m<<" "<<n<<endl;
    for(int i=0;i<m;i++){
        fscanf(f,"%d",&a[i]);
        cout<<a[i]<<" ";
        d[0][i]=0;
    }

    for(int i=0;i<n;i++){
        fscanf(f,"%d",&b[i]);
        cout<<b[i]<<" ";
        d[i][0]=0;
    }

    for(int j=1;j<n+1;j++){
        for (int i=1;i<=m;i++){
            if (a[i-1]==b[j-1]){
                d[i][j]=d[i-1][j-1]+1;
            }
            else{
                if(d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j];
                else d[i][j]=d[i][j-1];
            }
        }
    }
    cout<<endl<<d[m][n];
    sorozat(m,n);

    fprintf(g,"%d\n",d[m][n]);
    for(int i=rn-1;i>=0;i--){
    fprintf(g,"%d ",r[i]);
    }
    return 0;
}



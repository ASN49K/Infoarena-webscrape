#include <cstdio>

using namespace std;

int a[1030],b[1030],n,i,j,m,LCS[1030][1030],OP[1030][1030];

int main(){

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);


    scanf("%d%d",&n,&m);

    for(i=1;i<=n;++i){

        scanf("%d",&a[i]);

    }

    for(j=1;j<=m;++j){

        scanf("%d",&b[j]);

    }

    for(i=n;i>=1;--i){

        for(j=m;j>=1;--j){

            if(a[i]==b[j]){

                LCS[i][j]=1+LCS[i+1][j+1];

                OP[i][j]=1;

            }
            else{

                if(a[i]!=b[j]){

                    if(LCS[i+1][j]>LCS[i][j+1]){

                        LCS[i][j]=LCS[i+1][j];

                        OP[i][j]=2;
                    }
                    else{

                        LCS[i][j]=LCS[i][j+1];

                        OP[i][j]=3;

                    }

                }

            }

        }

    }

    printf("%d\n",LCS[1][1]);

    i=1;
    j=1;
    while(OP[i][j]!=0){

        if(OP[i][j]==1){
            printf("%d ",a[i]);
            ++i;
            ++j;
        }
        else{

            if(OP[i][j]==2){

                ++i;

            }

            else{ ++j;}

        }

    }
    return 0;
}

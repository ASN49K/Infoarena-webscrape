#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=1100;

int v1[MAX_N];
int v2[MAX_N];

vector<int>sol;

int d[2][MAX_N];
int p[2][MAX_N];

void dinamic(int x1,int x2,int y1,int y2) {
    if(x1==x2) {
        for(int i=y1;i<=y2;i++) {
            if(v2[i]==v1[x1]) {
                sol.push_back(v1[x1]);
                return ;
            }
        }
        return;
    }
    
    for(int j=y1-1;j<=y2;j++) {
       d[0][j]=0;
       d[1][j]=0;
       p[1][j]=0;
       p[0][j]=j;
    }
    
    int mij=(x1+x2)/2;

    for(int i=x1;i<=x2;i++) {
        for(int j=y1;j<=y2;j++) {
            if(v1[i]==v2[j]) {
                d[1][j]=d[0][j-1]+1;
                if(i>mij) {
                    p[1][j]=p[0][j-1];
                }
            }
            else { 
                if(d[0][j]>=d[1][j-1]) {
                    d[1][j]=d[0][j];
                    if(i>mij) {
                        p[1][j]=p[0][j];
                    }

                }
                else {
                    d[1][j]=d[1][j-1];
                    if(i>mij) {
                        p[1][j]=p[1][j-1];
                    }
                }
            }
        }

        for(int j=y1;j<=y2;j++) {
            d[0][j]=d[1][j];
            d[1][j]=0;
            if(i>mij) {
                p[0][j]=p[1][j];
                p[1][j]=0;
            }
            //if(i>=mij)
             //   printf("%d ",p[0][j]);
        }
       // printf("\n");
    }
    dinamic(x1,mij,y1,p[0][y2]);
    dinamic(mij+1,x2,p[0][y2]+1,y2);
}

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&v1[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&v2[i]);
    }
    dinamic(1,n,1,m);
    
    printf("%d\n",sol.size());
    for(vector<int>::iterator it=sol.begin(); it!=sol.end(); it++) {
        printf("%d ",*it);
    }

    return 0;
}

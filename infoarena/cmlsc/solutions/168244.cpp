#include <stdio.h>

int drum[1030][1030], len[1030][1030],drum_rec[1030],k,x[1030],y[1030];

void rec_drum(int i,int j){
     if (!i || !j) return;
     if (drum[i][j]==1) {drum_rec[k++]=x[i]; rec_drum(i-1,j-1);}
     else if (drum[i][j]==2) rec_drum(i,j-1);
     else rec_drum(i-1,j);

     }


int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&x[i]);
    for(i=1;i<=m;i++) scanf("%d",&y[i]);
    
    for (i=1;i<=n;i++)    
        for (j=1;j<=m;j++)
            if (x[i]==y[j]) {len[i][j]=len[i-1][j-1]+1;drum[i][j]=1;}
            else {if (len[i][j-1]>len[i-1][j]) len[i][j]=len[i][j-1], drum[i][j]=2;
                  else len[i][j]=len[i-1][j],drum[i][j]=3;
                 } 
    
    rec_drum(n,m);
          
    printf("%d\n",len[n][m]);                
    for(i=k-1;i>=0;i--) printf("%d ",drum_rec[i]);
    
    return 0;
    }

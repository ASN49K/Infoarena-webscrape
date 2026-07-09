#include<bits/stdc++.h>
using namespace std;

short int m, n, i;
unsigned char x[1025], y[1025], c[1025][1025];
vector<int>r;

int lcs(){
    int d;
     for(i=1; i<=m;i++){
         for(int j=1; j<=n; j++){
             if(x[i]==y[j]){c[i][j]=1+c[i-1][j-1]; r.push_back(x[i]);}
             else{if(c[i-1][j]>=c[i][j-1]){c[i][j]=c[i-1][j];}
                  else{c[i][j]=c[i][j-1];}    }

         }


     }

    
    return c[m][n];
}



int main(){
freopen("cmlsc.in", "r", stdin);
freopen("cmlsc.out", "w", stdout);


scanf("%d %d", &m, &n);
for(i=1;i<=m;i++){ scanf("%d", &x[i]);c[i][0]=0;}

for(i=1;i<=n;i++){ scanf("%d", &y[i]);  c[0][i]=0;}


printf("%d\n",lcs());
while(!r.empty()){printf("%d%c", r[0], ' '); r.erase(r.begin(), r.begin()+1);}

    return 0;
}
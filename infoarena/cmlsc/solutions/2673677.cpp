
#include<bits/stdc++.h>

using namespace std;

int a,b;
int x[1099],y[1099],v[1099][1099];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void citire(){
    in>>a>>b;
    for(int i=1;i<=a;i++){
        in>>x[i];
    }
    for(int i=1;i<=b;i++){
        in>>y[i];
    }
}

void prelucrare(){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(x[i]==y[j]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
}

void afisare(int m, int n){
    if(m==0 || n==0) return;
    if(x[m]==y[n]){
        afisare(m-1,n-1);
        out<<x[m]<<" ";//asa imi printeaza sirul invers
        //afisare(m-1,n-1);
    }
    else{
        if(v[m][n-1]>v[m-1][n]){
            afisare(m,n-1);
        }
        else afisare(m-1,n);
    }
}

int main()
{
    citire();
    prelucrare();
    out<<v[a][b]<<"\n";
    afisare(a,b);
    in.close();
    out.close();
    return 0;
}

#include <iostream>

using namespace std;

int x[1025],y[1025],n,m,t[1025][1025];;

long long LCS(int m,int n){
    for(int i=0;i<=m;i++)
        t[i][0]=0;
    for(int j=0;j<=n;j++)
        t[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i]==y[j]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
void afisare(int i, int j){
    if(i==0 || j==0){
        return;
    }
    else if(x[i]==y[j]){
        afisare(i-1,j-1);
        cout<<x[i]<<" ";
    }
    else{
        if(t[i-1][j]>t[i][j-1]){
            return afisare(i-1,j);
        }
        else{
            return afisare(i,j-1);
        }
    }

}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }

    cout<<LCS(m,n)<<endl;
    afisare(m,n);
    return 0;
}

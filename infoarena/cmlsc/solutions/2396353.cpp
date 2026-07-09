#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,x[1050],y[1050],z[1050][1050];
void citire()
{
    fin>>n>>m;
    int i;
    for(i=1; i<=n; i++)
        fin>>x[i];
    for(i=1; i<=m; i++)
        fin>>y[i];
}
void prelucrare()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            z[i][j]=max(z[i-1][j],z[i][j-1]);
            if(x[i]==y[j])
                z[i][j]++;
        }
    }
}
void afisare(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            cout << z[i][j] << " ";
        cout << "\n";
    }
}
void raspuns(){
    stack <int> stiva;
    fout << z[n][m] << "\n";
    int i=n,j=m;
    while(!i+j){
        while(z[i][j]==z[i-1][j])
            i--;
        while(z[i][j]==z[i][j-1])
            j--;
        stiva.push(x[i]);
        i--;
        j--;
    }
    while(!stiva.empty()){
        fout << stiva.top()<< " ";
        stiva.pop();
    }
}
int32_t main()
{
    citire();
    prelucrare();
    raspuns();
    return 0;
}

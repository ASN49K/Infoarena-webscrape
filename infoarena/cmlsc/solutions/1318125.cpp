#include<fstream>
using namespace std;

int N[1100],M[1100],n,m,sol[1100],d[1100][1100],lungime;


void citire(){

    ifstream in("cmlsc.in");
    int i;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>N[i];
    for(i=1;i<=m;i++)
        in>>M[i];
    in.close();

}
void solve() {

    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(N[i]==M[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=n;j=m;
    while(i)
        if(N[i]==M[j]) {
            sol[++lungime]=N[i];
            i--;j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;

}

void afisare() {

    ofstream out("cmlsc.out");
    int i;
    out<<lungime<<'\n';
    for(i=lungime;i>=1;i--)
        out<<sol[i]<<' ';
    out.close();

}


int main() {

    citire();
    solve();
    afisare();

}

#include<fstream>
using namespace std;

int n,m,v1[1100],v2[1100],sol[1100][1100], fin[1100],l;

void citire() {

    ifstream in("cmlsc.in");
    int i;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>v1[i];
    for(i=1;i<=m;i++)
        in>>v2[i];

    in.close();

}

void cmlsc() {

    int i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) {
        if(v1[i]==v2[j])
            sol[i][j]=sol[i-1][j-1]+1;
        else
            if(sol[i-1][j]>sol[j-1][i])
                sol[i][j]=sol[i-1][j];
             else
                sol[j][i]=sol[i][j-1];

        }
    for(i=n,j=m;i;)
        if(v1[i]==v2[j]) {
            fin[l++]=v1[i];
            i--;
            j--;
        }
        else
            if(sol[i-1][j]<sol[i][j-1])
                j--;
            else
                i--;
}

void afisare() {

    ofstream out ("cmlsc.out");
    int i;

    out<<l<<'\n';
    for(i=l-1;i>=0;i--)
        out<<fin[i]<<" ";
    out<<'\n';
    out.close();

}

int main() {

    citire();
    cmlsc();
    afisare();
    return 0;

}

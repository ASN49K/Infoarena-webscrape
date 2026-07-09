#include<fstream>
using namespace std;

int n,m,v1[1300],v2[1300],fin[1300],sol[1300][1300],q;

void citire() {

    ifstream in("cmlsc.in");
    int i;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>v1[i];
    for(i=1;i<=m;i++)
        in>>v2[i];

}

void cmlsc() {

    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)   {
            if(v1[i]==v2[j])
                sol[i][j]=sol[i-1][j-1]+1;
            else
                if(sol[i-1][j]>sol[i][j-1])
                    sol[i][j]=sol[i-1][j];
                    else
                    sol[i][j]=sol[i][j-1];

        }

    for (i = n, j = m; i;)
        if(v1[i]==v2[j])
            {fin[++q]=v1[i];i--;j--;}
        else
            if(sol[i-1][j]<sol[i][j-1])
                j--;
            else
                i--;

}

void afisare() {

    ofstream out("cmlsc.out");
    out<<q<<'\n';

    for(int i=q;i>=1;i--) {
        out<<fin[i]<<" ";

    }
}

int main () {

    citire();
    cmlsc();
    afisare();

    return 0;

}

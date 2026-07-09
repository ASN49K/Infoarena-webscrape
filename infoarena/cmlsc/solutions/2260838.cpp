#include <fstream>

#define FOR(i,a) for(i=1;i<=a;i++)

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int D[1025][1025];
int X[1025];
int Y[1025];
int sol[1025];
int solN;

int main()
{
    int n,m;

    cin>>n>>m;

    int i,j;

    FOR(i,n)
        cin>>X[i];

    FOR(i,m)
        cin>>Y[i];

    FOR(i,n)
        FOR(j,m)
            if( X[i] == Y[j] )
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = max(D[i-1][j],D[i][j-1]);

    i=n,j=m;
    while( i and j ){

        if( X[i] == Y[j] ){

            sol[++solN] = X[i];
            --i;
            --j;

        }else
            if ( D[i-1][j] < D[i][j-1] )
                --j;
            else
                --i;
    }

    cout<<solN<<'\n';
    for( i = solN ; i > 0 ; i-- )
        cout<<sol[i]<<" ";

    return 0;
}



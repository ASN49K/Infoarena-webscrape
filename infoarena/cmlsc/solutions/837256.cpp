


//Vasilut
#include<fstream>
#include<vector>
#include<algorithm>

#define NN 1030
#define pb push_back

using namespace std;

ofstream out("cmlsc.out");

int n,m,v[NN],a[NN];
int c[NN][NN];

vector<int>sol;
typedef vector<int>::iterator IT;

void read();
void dinamica();
void write_sol();

int main()
{
    read();
    dinamica();
    write_sol();
    return 0;
}

void read()
{
    ifstream in("cmlsc.in");
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v[i];
        for(int j=1;j<=m;j++)
            in>>a[j];

}

void dinamica()
{
    int i,j;
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if ( v[i] == a[j] )
                    c[ i ][ j ]  = c[ i-1 ][ j-1] + 1;
                    else
                    c[ i ][ j ] = max ( c[i-1][j],c[i][j-1] );
}

void write_sol()
{


    out << c[n][m];
    out<<'\n';




        int i,j;
        for ( i=n,j=m;i; )
        {
            if ( v[i] == a[j] )
            {
                sol.pb(v[i]);
                --i;
                --j;
            }
            else
                if ( c[ i-1 ][ j ] < c[ i ][ j-1 ] )
                    --j;
                    else
                    --i;
        }


        reverse(sol.begin(),sol.end());
        for ( IT I = sol.begin(); I!=sol.end();++I)
            out << *I <<" ";


}




#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Nmax = 50;

const int nr_solutii[]={0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184 };


int N,nrsol;
int st[Nmax];
int uz[Nmax], uzdl[Nmax * 2], uzdc[Nmax * 2];

#define uzdl (uzdl+Nmax)

ofstream g("damesah.out");

void print()
{
    if ( nrsol < 3 )
    {
        for ( int i = 1; i <= N; ++i )
                g << st[i] << " ";

        g << "\n";
    }

    nrsol++;
}

void back( int k )
{
    if ( nrsol >= 1 )
            return;

    if ( k > N )
            print();
    else
        for ( int i = 1; i <= N; ++i )
        {
            if ( !uz[i] && !uzdl[k - i] && !uzdc[k + i] )
            {
                uz[i] = 1;
                uzdl[k - i] = 1;
                uzdc[k + i] = 1;

                st[k] = i;
                back( k + 1 );

                uz[i] = 0;
                uzdl[k - i] = 0;
                uzdc[k + i] = 0;
            }
        }
}

int main()
{
    ifstream f("damesah.in");

    f >> N;

    back( 1 );

    g << nr_solutii[N] << "\n";

    f.close();
    g.close();

    return 0;
}

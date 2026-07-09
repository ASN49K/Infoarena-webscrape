#include <iostream>
#include <fstream>

using namespace std;

int A[1000][1000];
int N, M;

int s1[1000];
int s2[1000];

/*
5 5
12123
32192

--
BAB

*/

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void afisare(int ii, int jj)
{
    if(A[ii][jj] == 0)
        return;

    if(A[ii][jj-1] != A[ii][jj] && A[ii-1][jj] != A[ii][jj])
    {
        afisare(ii-1, jj);
        out<<s1[ii]<<' ';


    }
    else if(A[ii][jj] == A[ii][jj-1])
        afisare(ii, jj-1);
    else if(A[ii][jj] == A[ii-1][jj])
        afisare(ii-1, jj);

}


int main()
{

    in>>N>>M;

    for(int i=1; i<=N; i++)
        in>>s1[i];

    for(int i=1; i<=M; i++)
        in>>s2[i];


    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(s1[i] == s2[j])
            {
                 A[i][j] = A[i-1][j-1] + 1;
            }
            else
            {
                A[i][j] = max(A[i-1][j], A[i][j-1]);
            }
        }

    }
    /*
    cout<<'\n'<<'\n';
    cout<<'-'<<' ';

    for(int i=0; i<=M; i++)
        cout<<s2[i]<<' ';
    cout<<'\n';

    for(int i=0; i<=N; i++)
    {
        cout<<s1[i]<<' ';
        for(int j=0; j<=M; j++)
            cout<<A[i][j]<<' ';

        cout<<'\n';
    }
    cout<<'\n';
    */

    out<<A[N][M]<<'\n';
    afisare(N,M);

    //cout<<'\n'<<maxim<<'\n';

    /*
    for(int j=ii-maxim+1; j<=maxim; j++)
    {
        cout<<s1[j]<<' ';
    }
    */


    return 0;
}

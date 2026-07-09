#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"

#define MAXSIZE 1025

ifstream f(FIN);
ofstream g(FOUT);


vector<int> solution;
//the two arrays
int A[MAXSIZE], B[MAXSIZE];
int M[MAXSIZE][MAXSIZE]; //optimal structure
//the sizes of the arrays
int n,m;

void read()
{
    f >> n;
    f >> m;

    //reading the arrays from file
    for(int i = 1; i <= n; i++)
        f >> A[i];
    for(int j = 1; j <= m; j++)
        f >> B[j];

}

void solve()
{
    for(int i = 1; i <= n; i++ )
    {
        for(int j = 1; j <= m; j++)
        {
            if(A[i] == B[j])
            {
                M[i][j] = M[i-1][j-1] + 1;
            }
            else
            {
                M[i][j] = max(M[i-1][j], M[i][j-1]);
            }
        }

    }

}

int max(int a, int b)
{
    if( a > b)
        return a;
    else return b;
}

void write()
{
    int i = n;
    int j = m;
    //traceback
     while(i != 0 && j != 0)
     {
         if(A[i] == B[j])
         {
             solution.push_back(A[i]);
             i--;
             j--;
         }
         else
         {
             if(M[i-1][j] > M[i][j-1])
             {
                 i--;
             }
             else
             {
                 j--;
             }
         }
     }
     //print the lcs
     g << M[n][m] << endl;
     //print the common subsequence
     for(vector<int>::reverse_iterator it = solution.rbegin(); it != solution.rend(); it++)
     {
         g << *it <<" ";
     }
}



int main()
{
    read();
    solve();
    write();
    return 0;
}

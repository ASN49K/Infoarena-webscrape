#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");
std::vector<int> cmlsc;
#define MAX_SIZE 1027
int A[MAX_SIZE],B[MAX_SIZE];
int c[MAX_SIZE][MAX_SIZE],b[MAX_SIZE][MAX_SIZE];
void show(int i, int j)
{

    if(i ==-1 || j == -1)
        return;
    if(b[i][j] == 1)
    {
        cmlsc.push_back(A[i]);
        show(i-1,j-1);
    }
    else if(b[i][j] == -1)
        show(i,j-1);
    else
        show(i-1,j);
}
int main()
{

    int m,n;
    in >> m >> n;

    for(int i = 0 ; i < m ; i++)
       in >> A[i];
    for(int i = 0 ; i < n ; i++)
        in >> B[i];
    for(int i = 0 ; i < m ; i++)
        c[i][0] = 0;
    for(int i = 0 ; i < n ;i ++)
        c[0][i] = 0;

    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++)
    {

        if(A[i]==B[j])
        {
            c[i][j] = c[i-1][j-1]+1;
            b[i][j] = 1;
        }
        else if(c[i-1][j] >= c[i][j-1])
        {

            c[i][j] = c[i-1][j];
            b[i][j] = 2;
        }
        else
        {

            c[i][j] = c[i][j-1];
            b[i][j] = -1;
        }

    }
    out<<c[m-1][n-1]<<'\n';
    show(m-1,n-1);
    std::reverse(cmlsc.begin(),cmlsc.end());
    for(int x:cmlsc)
        out<<x<<" ";
    return 0;
}

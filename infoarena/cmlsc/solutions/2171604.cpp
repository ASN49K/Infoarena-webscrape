#include<iostream>
#include<fstream>
#include<vector>
#define MAX_N 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
std::vector< int > mat[MAX_N];
vector< int > v1;
vector< int > v2;
void build_solution(int i,int j)
{
    if(i < 0 || j < 0) return;
    int up = 0;
    int left = 0;
    int up_left = 0;
    int next_to_mat;
    if(j > 0) left = mat[i][j-1];
    if(i > 0) up = mat[i-1][j];
    if(j > 0 && i > 0) up_left = mat[i-1][j-1];
    if(mat[i][j] > max(up,left))
    {
        fout<<v2[i]<<" ";
        build_solution(i-1,j-1);
    }
    else if(mat[i][j] == max(up,left))
    {
        if(i > 0) build_solution(i-1,j);
        else build_solution(i,j-1);
    }
}
int main()
{
    fin>>n>>m;
    int k1;
    for(int i=0;i<n;i++)
    {
        fin>>k1;
        v1.push_back(k1);
    }
    for(int i=0;i<m;i++)
    {
        fin>>k1;
        v2.push_back(k1);
        for(int j=0;j<n;j++)
        {
            int up = 0;
            int left = 0;
            int up_left = 0;
            int next_to_mat;
            if(j > 0) left = mat[i][j-1];
            if(i > 0) up = mat[i-1][j];
            if(j > 0 && i > 0) up_left = mat[i-1][j-1];
            if(v2[i] == v1[j]) next_to_mat = up_left+1;
            else next_to_mat = max(left,up);
            mat[i].push_back(next_to_mat);
        }
    }
    fout<<mat[m-1][n-1]<<"\n";
    build_solution(m-1,n-1);
}

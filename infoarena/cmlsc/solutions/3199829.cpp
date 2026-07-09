#include<fstream>
#include<vector>
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
int mat[1024][1024];
int v1[1024], v2[1024];
void read(int &n, int &m)
{
    fin>>n>>m;
    for(int index=0; index<n; ++index)
        fin>>v1[index];
    for(int index=0; index<m; ++index)
        fin>>v2[index];
}
void createMatrix(int n, int m)
{
    for(int index=1; index<=n; ++index)
        for(int next=1; next<=m; ++next)
            mat[index][next]=std::max(std::max(mat[index-1][next], mat[index][next-1]), mat[index-1][next-1]+(v1[index-1]==v2[next-1]));
    fout<<mat[n][m]<<'\n';
}
void findAns(int i, int j)
{
    std::vector<int>ans;
    while(mat[i][j])
    {
        if(v1[i-1]==v2[j-1])
        {
            ans.push_back(v1[i-1]);
            --i;
            --j;
        }
        else if(mat[i][j]==mat[i][j-1])
            --j;
        else
            --i;
    }
    long long size=ans.size();
    for(int index=size-1; index>=0; --index)
        fout<<ans[index]<<' ';
}
int main()
{
    int n, m;
    read(n, m);
    createMatrix(n, m);
    findAns(n, m);
    fin.close();
    fout.close();
    return 0;
}

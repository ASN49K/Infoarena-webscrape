#include<fstream>
#include<vector>
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
int mat[1050][1050];
std::vector<int>ans;
void read(std::vector<int>&v1, std::vector<int>&v2, int &n, int &m)
{
    fin>>n>>m;
    for(int index=0; index<n; ++index)
    {
        int x;
        fin>>x;
        v1.push_back(x);
    }
    for(int index=0; index<m; ++index)
    {
        int x;
        fin>>x;
        v2.push_back(x);
    }
}
void createMatrix(int n, int m, std::vector<int>v1, std::vector<int>v2)
{
    for(int index=1; index<=n; ++index)
        for(int next=1; next<=m; ++next)
            mat[index][next]=std::max(std::max(mat[index-1][next], mat[index][next-1]), mat[index-1][next-1]+(v1[index-1]==v2[next-1]));
    fout<<mat[n][m]<<'\n';
}
void findAns(int i, int j, int local, std::vector<int>v1, std::vector<int>v2)
{
    if(local==0)
        return;
    if(v1[i-1]==v2[j-1])
        ans.push_back(v1[i-1]);
    if(mat[i-1][j]>mat[i][j-1])
        findAns(i-1, j, mat[i-1][j], v1, v2);
    else
        findAns(i, j-1, mat[i][j-1], v1, v2);
}
int main()
{
    std::vector<int>v1, v2;
    int n, m;
    read(v1, v2, n, m);
    createMatrix(n, m, v1, v2);//good
    findAns(n, m, mat[n][m], v1, v2);
    long long size=ans.size();
    for(int index=size-1; index>=0; --index)
        fout<<ans[index]<<" ";
    fin.close();
    fout.close();
    return 0;
}

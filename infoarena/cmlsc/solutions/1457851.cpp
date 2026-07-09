#include<fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,v[10000],v2[1000];
int main(){
    int s[1000][1000];
    fin >> n>>m;
    for(int i = 1;i<=n;i++)
        {fin >>v[i];s[i][0]=0;s[0][i]=0;}
    for(int i = 1;i<=m;i++)
        fin >>v2[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
             if(v[i]==v2[j])
             {

                s[i][j]=1+s[i-1][j-1];
             }
             else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
         }
fout<<s[n][m]<<endl;
for(int i =1;i<=n;i++)
        {for(int j = 0;j<=m;j++)
            if(s[i-1][j]<s[i][j] and s[i][j-1]<s[i][j])
            {
                fout<<v[i]<<" ";
            }
        }
return 0;
}

#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int s[1025][1025];
int n[1025],m[1025],afis[1025],N,M;
int main(){
    int k=0;
    fin>>N>>M;
    for(int i=0;i<N;i++)
    {
        fin>>n[i];
    }
    for(int i=0;i<M;i++)
    {
        fin>>m[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(n[i]==m[j])
            {
                 k++;
                s[i+1][j+1]=s[i][j]+1;
                afis[k]=m[j];
            }
            else
            {
                s[i+1][j+1]=max(s[i][j+1],s[i+1][j]);
            }
           
        }
        
    }
   fout<<s[N][M]<<endl;
    for(int i=1;i<=k;i++)
    {
        fout<<afis[i]<<' ';
    }
}
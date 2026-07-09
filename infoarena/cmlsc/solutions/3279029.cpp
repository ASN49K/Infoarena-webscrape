#include <fstream>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int s[1025][1025];
int n[1025],m[1025],afis[1025],N,M;
stack <int> dp;
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
            
                s[i+1][j+1]=s[i][j]+1;
               
            }
            else
            {
                s[i+1][j+1]=max(s[i][j+1],s[i+1][j]);
            }
           
        }
        
    }
      k=s[N][M];
      fout<<k<<endl;
      int i=N;
      int j=M;
     while (i > 0 && j > 0) {
        if (n[i - 1] == m[j - 1]) {
            dp.push(n[i - 1]);
            i--;
            j--;
        } else if (s[i - 1][j] >= s[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    while(!dp.empty())
    {
        fout<<dp.top()<<' ';
        dp.pop();
    }
}
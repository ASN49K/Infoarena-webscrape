#include <fstream>
std::ifstream cin("cmlsc.in");
std::ofstream cout("cmlsc.out");
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int M,N,k,v[1025][1025],a[1025],b[1025],i,j,sir[1025];
int main()
{
    cin>>M>>N;
    for(i=1; i<=M; i++)
        cin>>a[i];
    for(i=1; i<=N; i++)
        cin>>b[i];
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            if(a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=maxim(v[i-1][j],v[i][j-1]);

    for(i=M, j=N; i>0, j>0; )
        if(a[i]==b[j])
          {sir[++k]=a[i];
            i--; j--;}
        else
            if(v[i-1][j]<v[i][j-1])
                j--;
            else
                i--;
    cout<<k<<'\n';
    for(i=k; i>0; i--)
        cout<<sir[i]<<" ";
    return 0;
}


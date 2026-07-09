#include <iostream>
#include <fstream>
// # include <lapatenco>

#define maxn 1024
#define MAX(a, b) ((a>b)?a:b)
// #define lapatenco prost

using namespace std;

int N,M,a[maxn],b[maxn],d[maxn][maxn],sir[maxn],gubi;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in >> N >> M;
    for(int i=1;i<=N;i++){
        in >> a[i];
    }
    for(int i=1;i<=M;i++){
        in >> b[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=MAX(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i=N,j=M;i;){
        if(a[i]==b[j]) sir[++gubi]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1]) j--;
        else i--;
    }
    out << gubi << '\n';
    for(int i=gubi;i;i--){
        out << sir[i] << ' ';
    }
    return 0;
}

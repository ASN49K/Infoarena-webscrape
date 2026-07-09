#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");


int N,M, A[1024], B[1024], D[2048][2048], sir[2048],bst;

int main()
{
    cin>>M>>N;
    for(int i=1; i<=M; i++)
        cin>>A[i];
    for(int i=1; i<=N; i++)
        cin>>B[i];

    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);

    for (int i = M, j = N; i;)
        if (A[i] == B[j])
        {
            sir[++bst]=A[i];
            --i;
            --j;
        }
        else if(D[i-1][j]<D[i][j-1])
            --j;
        else
            --i;

    cout<<bst<<'\n';
    for (int i=bst; i>0; --i)
        cout<<sir[i]<<" ";
    ///cout<<'\n';
    /**for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
            cout<<D[i][j]<<" ";
        cout<<'\n';
    }*/
    return 0;
}

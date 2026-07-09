#include<cstdio>
#include <algorithm>
#include <vector>
//#include "Euclid.cpp"
//#include "EuclidExtended.cpp"
//#include "LCS.cpp"

using namespace std;

#define NMAX 1024+5

class LCS
{
private:
    int D[NMAX][NMAX];
    int A[NMAX];
    int B[NMAX];
    int N,M;
    vector<int> sol;

    int lcs(int n,int m)
    {
        if(!n || !m)
            return 0;
        if(A[n]==B[m]) {
            sol.push_back(A[n]);
            return 1 + max(lcs(n - 1, m), lcs(n, m - 1));
        }
        else
            return max(lcs(n-1,m),lcs(n,m-1));
    }

public:
    void LCS_main()
    {
        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);

        scanf("%d %d",&N,&M);

        for(int i=1;i<=N;i++)
            scanf("%d",&A[i]);

        for(int i=1;i<=M;i++)
            scanf("%d",&B[i]);

        printf("%d\n",lcs(N,M));

        int n=sol.size()/ sizeof(int);
        for(int i=n-1;i>=0;i--)
            printf("%d ",sol[i]);
    }

} LCS;

int main()
{
    LCS.LCS_main();
    return 0;
}
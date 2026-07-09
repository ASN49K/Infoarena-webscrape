#include <iostream>
#include <fstream>
using namespace std;

int euclidImpartiri(int a, int b)
{
    if(b==0)
        return a;
    else
        return euclidImpartiri(b, a % b );
}

int main()
{
    freopen("euclid2.in", "rt", stdin);
    freopen("euclid2.out", "wt", stdout);
    int N, x, y;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d", &x, &y);
        cout<<euclidImpartiri(x,y)<<'\n';
    }
}

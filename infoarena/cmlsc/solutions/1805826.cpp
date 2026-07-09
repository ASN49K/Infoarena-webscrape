#include <bits/stdc++.h>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int N , M ,arr[1025][1025] , arr1[1025] , arr2[1025] , x[1025];

void read_input ()
{
    in >> N >> M;
    for(int i = 1 ; i <= N ; ++ i)
        in >> arr1[i];
    for(int j = 1 ; j <= M ; ++ j)
        in >> arr2[j];
}

void solve ()
{
    int cri , crj , nr = 0;
    for(int i = 1 ; i <= N ; ++ i)
    {
        for(int j = 1 ; j <= M ; ++ j)
        {
            if(arr1[i] == arr2[j])
                arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max (arr[i-1][j] , arr[i][j-1]);
        }
    }

    cri = N , crj = M;
    out << arr[N][M] <<'\n';

    while(cri > 0 && crj > 0)
    {
        if(arr1[cri] == arr2[crj])
         x[++nr] = arr1[cri] , cri -- , crj -- ;
        else
        {
            if(arr[cri][crj - 1] > arr[cri - 1][crj])
                crj -- ;
            else cri -- ;
        }
    }

    for(int i = nr ; i >= 1 ; -- i)
        out << x[i] << " ";

}

int main()
{
    read_input ();
    solve ();
    return 0;
}

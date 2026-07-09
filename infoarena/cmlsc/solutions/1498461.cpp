#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m, n, p = 0;
int arr[1025][1025], arrm[1025], arrn[1025];
int main()
{

    in >> m >> n;

    for(int i = 1; i <= m; i++)
        in >> arrm[i];
    for(int i = 1; i <= n; i++)
        in >> arrn[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(arrm[i] == arrn[j])
                {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                    p++;
                }
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    out << p << '\n';
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cout << arr[i][j];
    int i = m, j = n;
    while(i > 0 && j > 0)
    {
            if(arrm[i] == arrn[j])
                {
                    out << arrm[i] << ' ';
                    i--;
                    j--;
                }
            else if(arrm[i - 1] >= arrn[j - 1])
                i--;
            else
                j--;
        }
    return 0;
}

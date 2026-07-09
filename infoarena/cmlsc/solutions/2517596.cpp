#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m;
int v[1030], w[1030];
int a[1030][1030];
int main()
{
    fin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> v[i];
    for ( int i = 1 ; i <= m ; i++ )
        fin >> w[i];
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
        {
            a[i][j] = max(a[i-1][j],a[i][j-1]);
            if ( v[i] == w[j] )
                a[i][j] = max(a[i][j], a[i-1][j-1] + 1);
        }
    }
    fout << a[n][m] << endl;

    /*
    int nr = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
        {
           if ( a[i][j] == (nr + 1) && v[i] == w[j] )
           {
               fout << v[i] << " ";
               nr++;
           }
        }
    }
*/

    stack<int> st;


    for (int i = n, j = m; i > 0 && j > 0 ; )
    {
        if (v[i] == w[j])
        {
            st.push(v[i]);
            i--;
            j--;
        }
        else if (a[i-1][j] < a[i][j-1])
            --j;
        else
            --i;
    }

    while(!st.empty())
    {
        fout << st.top() << " ";
        st.pop();

    }



    return 0;
}

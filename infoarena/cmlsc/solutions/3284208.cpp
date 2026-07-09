    #include <fstream>

    using namespace std;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n, m;
    int a[1025];
    int b[1025];
    int sir[1025][1025];
    int sol[1025];
    int main()
    {
        fin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            fin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            fin >> b[i];
        }
        int nr = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i] == b[j])
                {
                    sir[i][j]=sir[i-1][j-1]+1;
                }
                else
                {
                    sir[i][j] = max(sir[i - 1][j], sir[i][j - 1]);
                }
            }
        }
        fout << sir[n][m] << "\n";
        int l = sir[n][m];
        int i = n;
        int j = m;
        while (sir[i][j])
        {
            if (a[i] == b[j])
            {
                sol[l] = a[i];
                l--;
                i--;
                j--;
            }
            else
            {
                if (sir[i - 1][j] > sir[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        for (int i = 1; i <= sir[n][m]; i++)
            fout << sol[i] << " ";
        return 0;
    }
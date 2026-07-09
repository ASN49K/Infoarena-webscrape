#include<fstream>
using namespace std;

#define N 101
#define M 101

int c[N][M], a[N], b[M];
int n, m;

inline int maxim(int x, int y)
{
       if (x >= y) return x;
       return y;       
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    
    int i, j;
    int k, s[N];
    
    f>>n>>m;
    for (i = 1; i <= n; i++)
        f>>a[i];
    for (j = 1; j <= m; j++)
        f>>b[j];
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
               c[i][j] = c[i - 1][j - 1] + 1;
            else
               c[i][j] = maxim (c[i - 1][j], c[i][j - 1]);
    g<<c[n][m]<<"\n"; 
    
    k = c[n][m];
    i = n, j = m;
    while(k >= 1)
    {
                 if (a[i] == b[j])
                 {
                    s[k] = a[i];
                    i--; j--; k--;         
                 }   
                 else
                 {
                     if(maxim(c[i - 1][j], c[i][j - 1]) == c[i - 1][j])
                          i--;
                     else
                          j--;   
                 }
    }
    
    for (i = 1; i <= c[n][m]; i++)
        g<<s[i]<<" ";
    g<<"\n";
    
    f.close();
    g.close();
    return 0;
}

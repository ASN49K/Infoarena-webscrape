#include <fstream>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

void readArray(int n, int arr[])
{
    for (auto i = 1; i <= n; ++i)
        in >> arr[i];  
}


int main()
{
    int m, n, x[1040], y[1040], lcs[1040], index = 0, l[1040][1040] = {0};
    in >> m >> n;
    readArray(m, x);
    readArray(n, y);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (x[i] == y[j])
                l[i][j] = 1 + l[i - 1][j - 1]; 
            else
                l[i][j] = std::max(l[i - 1][j], l[i][j - 1]);
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i] == y[j])
        {
            lcs[++index] = x[i];
            --i;
            --j; 
        }
        else if (l[i - 1][j] > l[i][j - 1])
            --i;
        else
            --j;     
    }
    out << l[m][n] << '\n';
    for (i = index; i >= 1; --i)
        out << lcs[i] << ' ';  
    in.close();
    out.close();
    return 0;
    
}
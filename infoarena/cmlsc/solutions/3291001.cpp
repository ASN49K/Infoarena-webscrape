#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>

int x[1025], y[1025];
int result[1025][1025];
int n, m;

void LCS()
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(x[i] == y[j])
            {
                result[i][j] = 1 + result[i-1][j-1];
            }       
            else
            {
                result[i][j] = std::max(result[i-1][j], result[i][j-1]);
            }
        }
    }
}

int main()
{
    FILE* r = fopen("cmlsc.in", "r");
    FILE* w = fopen("cmlsc.out", "w");
    if(!r || !w) return 1;
    fscanf(r, "%d%d", &n, &m);
    
    for(int i = 1; i<=n; i++)
    {
        fscanf(r, "%d", x+i);
    }

    for(int i = 1; i<=m; i++)
    {
        fscanf(r, "%d", y+i);
    }

    LCS();
    
    int i = n;
    int j = m;


    std::array<int, 1024> res;
    size_t s = 0;
    while(i > 0 && j > 0)
    {
        if(x[i] == y[j] && result[i][j] > result[i-1][j-1])
        {
            res[s++] = x[i];
        } 
        if(result[i-1][j] > result[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    fprintf(w, "%d\n", s);
    for(int i = 0; i<s; i++)    
    {
        fprintf(w, "%d ", res[i]);
    }
}
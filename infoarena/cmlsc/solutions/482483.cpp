#include <iostream>
#include <fstream>

using namespace std;

int c[1025], N, M, v1[1025], v2[1025], maxim, minim;

bool combin(int n, int k, int pas)
{
    bool ans = true;
    if (pas == k)
    {
        int minCard = (minim == N) ? N : M;
        for (int i = 0; i < k; i++)
        {
            int pozPrev = 0;
            for (int j = 0; j < minCard; j++)
            {
                if (((maxim == N) ? v1[c[i]] : v2[c[i]]) == ((maxim == N) ? v2[j] : v1[j]))
                {
                    if (!pozPrev && pozPrev > j)
                        return false;
                    else
                    {
                        pozPrev = j;
                        break;
                    }
                }
                else
                {
                    if (j == minCard - 1)
                        return false;
                }
            }
        }

        return ans;
    }
    else
    {
        if (pas == 0)
        {
            for (int i = 0; i < n; i++)
            {
                c[pas] = i;
                ans = combin(n, k, pas + 1);

                if (ans == true)
                    return true;
            }
        }
        else
        {
            for (int i = c[pas - 1] + 1; i < n; i++)
            {
                c[pas] = i;
                ans = combin(n, k, pas + 1);

                if (ans == true)
                    return true;
            }
        }

        return false;
    }
}

int main()
{
    FILE *in = fopen("cmlsc.in", "r");
    FILE *out = fopen("cmlsc.out", "w");

    fscanf(in, "%d", &N);
    fscanf(in, "%d", &M);
    for (int i = 0; i < N; i++)
        fscanf(in, "%d", &v1[i]);

    for (int i = 0; i < M; i++)
        fscanf(in, "%d", &v2[i]);

    maxim = max(N, M); minim = min(N, M);
    bool gasit = false;
    while (!gasit)
    {
        gasit = combin(maxim, minim, 0);

        if (gasit == true)
        {
            fprintf(out, "%d\n", minim);
            for (int i = 0; i < minim; i++)
                fprintf(out, "%d ", v1[c[i]]);
        }

        minim--;
    }
    return 0;
}


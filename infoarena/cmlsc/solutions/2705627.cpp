#include <iostream>
#include <fstream>

int sol[1024], sol_index, A[1024], B[1024], m, n, prev_max, final_sol[1024], max_len;

void get_input()
{
    std::ifstream fin;
    fin.open("cmlsc.in");

    fin>>m>>n;

    for(int i = 0; i < m; i++)
        fin>>A[i];

    for(int i = 0; i < n; i++)
        fin>>B[i];
}

void print_sol()
{
    std::ofstream fout;
    fout.open("cmlsc.out");

    fout<<max_len<<'\n';
    for(int i = 0; i < max_len; i++)
    {
        fout<<final_sol[i]<<' ';
    }
}

void cmlsc_backtr(int level_A, int level_B)
{
    if(level_B == n)
    {
        if(sol_index > prev_max)
        {
            prev_max = sol_index;
            max_len = sol_index;

            for(int i = 0; i < sol_index; i++)
                final_sol[i] = sol[i];
        }

        return;
    }

    for(int i = level_A; i < m; i++)
    {
        if(A[i] == B[level_B])
        {
            sol[sol_index++] = A[i];

            cmlsc_backtr(level_A + 1, level_B + 1);

            sol[sol_index--] = 0;
        }
        else
        {
            cmlsc_backtr(level_A, level_B + 1);
        }
    }
}

int main()
{
    get_input();
    std::cout<<m<<' '<<n<<'\n';

    for(int i = 0; i < m; i++)
        std::cout<<A[i]<<' ';
    std::cout<<'\n';

    for(int i = 0; i < n; i++)
        std::cout<<B[i]<<' ';

    cmlsc_backtr(0, 0);

    print_sol();
    return 0;
}

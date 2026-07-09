#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N, M;
const int LIM = 1024;
int solutie[LIM][LIM];
short int sir_1[LIM], sir_2[LIM];


void citire()
{
    
    in >> N >> M;
    for (int i = 1; i <= N; i++)
    {
            in>>sir_1[i];
            sir_2[i] = sir_1[i];
    }
    if (M > N)
    {
        for (int i = 1; i <= M; i++)
        {
            in>>sir_1[i];
        } 
    }
    else
    {
         for (int i = 1; i <= M; i++)
        {
            in>>sir_2[i];
        } 
    }

}

int maxi(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void dinamic()
{
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if(i == 0 || j == 0)
            {
                solutie[i][j] = 0;
            }
        }        
    }

    int lungime = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(sir_2[i] == sir_1[j])
            {
                solutie[i][j] = ++lungime;
            }
            else
            {
                solutie[i][j] = maxi(solutie[i-1][j],solutie[i][j-1]);
            }
        }        
    }
    int sol = 0;
    int nr = 1;
        for (int i = 1; i <= N; i++)
        {
            if(solutie[M][i] > sol)
            {
                sol = solutie[M][i];
            }
            
        }

    out<<sol<<'\n';

    for (int i = 1; i <= N; i++)
        {
            if (solutie[M][i] == nr)
            {
                out<<sir_1[i]<<' ';
                ++nr;
            }   
        }
        
}


int main()
{
    citire();
    dinamic();
    return 0;
}
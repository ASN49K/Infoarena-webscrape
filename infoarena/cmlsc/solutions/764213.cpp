/* 
 * File:   cmlsc.cpp
 * Author: alex
 *
 * Created on July 3, 2012, 7:33 PM
 */

#include <cstdlib>
#include <vector>
#include <stdio.h>
using namespace std;

/*
 * 
 */

int** compLen(vector<char> A, vector<char>B)
{
    int M, N;
    M = (int)A.size();
    N = (int)B.size();
    int** C;
    C = new int*[M + 1];
    for(int i = 0; i <= M; i++)
        C[i] = new int[N + 1];
    for(int i = 0; i <= M; i++)
        C[i][0] = 0;
    for(int i = 0; i <= N; i++)
        C[0][i] = 0;
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
        {
            if(A[i - 1] == B[j - 1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
            {
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);
            }
        }
    return C;
}

vector<char> cmlsc(int** &C, vector<char> A, vector<char> B)
{
    int i, j;
    i = (int)A.size();
    j = (int)B.size();
    vector<char> R;
    while(i != 0 && j != 0)
    {
        if(A[i - 1] == B[j - 1])
        {
            R.push_back(A[i - 1]);
            i--;
            j--;
        }
        else
        {
            if(C[i][j - 1] > C[i - 1][j])
                j--;
            else
                i--;
        }
    }
    return R;
}

int main(int argc, char** argv) 
{
    int M, N;
    vector<char> A, B;
    short int c;
    FILE* f, *o;
    f = fopen("cmlsc.in", "r");
    fscanf(f, "%d", &M);
    fscanf(f, "%d", &N);
    for(int i = 0; i < M; i++)
    {
        fscanf(f, "%hd ", &c);
        A.push_back(c);
    }
    for(int i = 0; i < N; i++)
    {
        fscanf(f, "%hd ", &c);
        B.push_back(c);
    }
    
    int** C = compLen(A, B);
/*    for(unsigned int i = 0; i <= A.size();i++)
    {
        for(unsigned int j = 0; j <= B.size();j++)
            printf("%d ", C[i][j]);
        printf("\n");
        
    }
*/    
    vector<char> Rez = cmlsc(C, A, B);
    o = fopen("cmlsc.out", "w");
    fprintf(o, "%d\n", Rez.size());
    for(int i = (int)Rez.size() - 1; i >= 0; i--)      
        fprintf(o, "%d ", Rez[i]);
 
    fprintf(o, "\n");
    fclose(o);
    fclose(f);
    return 0;
}


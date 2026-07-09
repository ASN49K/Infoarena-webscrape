#include <iostream>
#include <fstream>
#define nmax 1024
#define maxsim(a,b) ((a > b)? a:b)
using namespace std;
ifstream fin("LCS.in");
ofstream fout("LCS.out");

int A, B;
int a[nmax], b[nmax], ans=0, sir[nmax], C[nmax][nmax];
int main()
{
     fin >> A >> B;
    for(int i = 1; i <= A; ++i)
        fin >> a[i];
    for(int i = 1; i <= B; ++i)
        fin >> b[i];

    for(int i = 1; i <= A; ++i)
        for(int j = 1; j <= B; ++j)
            if(a[i] == b[j]) C[i][j] = C[i - 1][j - 1] + 1;
            else C[i][j] = max(C[i - 1][j], C[i][j - 1]);

    fout<<C[A][B] << '\n';
     int i_curent=A;
     int j_curent=B;
     while(i_curent)
     {
         if(a[i_curent]==b[j_curent])
         {
             sir[++ans]=a[i_curent];
             i_curent--;
             j_curent--;
         }
         else if(C[i_curent][j_curent]>C[i_curent-1][j_curent]) j_curent--;
         else i_curent--;
     }
     for(int i = ans; i >= 1; --i)
        fout<<sir[i]<<" ";
    return 0;
}

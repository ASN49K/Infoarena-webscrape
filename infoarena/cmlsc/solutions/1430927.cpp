#include <iostream>
#include <fstream>

#define MAX 1024
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int length[MAX][MAX];
int number1[MAX];
int number2[MAX];
int final[MAX];
int main()
{
    int n,m;
    fin >> n;
    fin >> m;
    int index = 0;
    for(int i = 0; i < n; ++i)
    {
        fin >> number1[i];
        length[i][0] = 0;
    }
    for(int i = 0; i < m; ++i)
    {
        fin >> number2[i];
        length[0][i] = 0;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j){
            if(number1[i] == number2[j] ){
                length[i][j] = length[i-1][j-1] + 1;
                final[index] = number1[i];
                index++;
            }else{
                length[i][j] = std::max(length[i-1][j], length[i][j-1]);
            }
        }
    }
    fout << length[n][m]<<"\n";
    for(int i = 0; i < index; ++i)
    {
        fout << final[i]<<" ";
    }
}

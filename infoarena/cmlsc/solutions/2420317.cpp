#include<fstream>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int A[1026], B[1026], D[1026][1026],sir[1026] ,N, M,bst;

int main() {
    fin >> M >> N;
    for (int i = 1; i <= M; ++i)
        fin >> A[i];
    for (int j = 1; j <= N; ++j)
        fin >> B[j];

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);

            for(int i=M,j=N;i;)
                if(A[i]==B[j])
                    sir[++bst]=A[i],--i,--j;
                else
                    if(D[i-1][j]<D[i][j-1])
                        --j;
                    else
                        --i;

                    fout<<bst<<"\n";
                    for(int i=bst;i;--i)

                        fout<<sir[i]<<' ';
                    fin.close();
                    fout.close();
    return 0;
}
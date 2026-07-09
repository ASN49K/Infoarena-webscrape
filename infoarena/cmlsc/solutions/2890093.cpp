#include <fstream>
using namespace std;

#define maxN 1024

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int A[maxN], B[maxN];
int N, M;
int Matrix[maxN][maxN];
int Pair[maxN];

void LCS(int A[], int B[])
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(A[i] == B[j]) Matrix[i][j] = Matrix[i - 1][j - 1] + 1;
            else Matrix[i][j] = max(Matrix[i - 1][j], Matrix[i][j - 1]);
} 

void Route()
{
    int i = N;
    int j = M;
    int k = 0;
    while(i && j)
    {
        if(A[i] == B[j]) Pair[++k] = A[i], i --, j --;
        else{
            if(Matrix[i - 1][j] > Matrix[i][j - 1]) i --;
            else j--;
        } 
    }
    cout << k << endl;
    while(k)
    {
        cout << Pair[k] << " ";
        k --;
    }
}

void Read()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    for(int j = 1; j <= M; j++)
        cin >> B[j];
}

int main()
{
    Read();
    LCS(A, B);
    Route();
    cin.close();
    cout.close();
    return 0;

}
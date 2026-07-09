#include <fstream>
#include <vector>

using namespace std;
int max(int a, int b)
{
    if ( a > b )
        return a;
    else
        return b;
}
int main()
{
    
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int M, N, i, j, x,val;
    in >> M >> N;
    
    int C[M+1][N+1];
    vector<int> A, B, seq;

    A.push_back(0);
    B.push_back(0);

    //bordam matricea C
    for (i = 0; i < M+1; i++)
        C[i][0] = 0;
    for (i = 0; i < N+1; i++)
        C[0][i] = 0;

    //citim vectorii
    for (i = 1; i <= M; i++)
        in >> x, A.push_back(x);
    for (i = 1 ; i <= N; i++)
        in >> x, B.push_back(x);
    
    //completam matricea C
    for (i = 1; i < M+1; ++i)
        for (j = 1; j < N+1; ++j)
        {
            if (A[i] != B[j])
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            else
                C[i][j] = 1 + C[i-1][j-1];
        }
   val = C[M][N];
   out << val << endl;
   /*for (i = 1; i < M+1; ++i)
   {
       for (j = 1; j < N+1; ++j)
           out << C[i][j] << " ";
       out << endl;
   }*/

   //getting the elements
   i = M; j = N;
   while (val != 0)
   {
       if (C[i-1][j] == val)
           --i;
       else
           if (C[i][j-1] == val)
               --j;
            else
            {
                seq.push_back(A[i]);
                --i;
                --j;
                --val;
            }
   }
   for (i = seq.size() - 1; i >= 0; --i)
       out << seq[i] << " ";

}

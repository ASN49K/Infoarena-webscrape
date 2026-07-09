#include <fstream>
#include<stack>
using namespace std;

int main()
{
    int n, m, A[1000], B[1000], D[1000][1000];
    stack<int> st;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> m >> n;
    for(int i = 1; i<= m ; ++i)
        fin >> A[i];
    for(int i = 1; i<= n ; ++i)
        fin >> B[i];

    for(int i =1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if(A[i]==B[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j], D[i][j-1]);
    fout<< D[m][n]<< endl;
    int i=m, j=n;
    while(i>0 && j>0)
    {
        if(A[i]==B[j])
        {
            st.push(B[j]);
            i--;
            j--;
        }
        else if(D[i-1][j]>D[i][j-1])
            i--;
        else j--;

    }
    for (; !st.empty(); st.pop())
        fout << st.top() << " ";
    return 0;
}

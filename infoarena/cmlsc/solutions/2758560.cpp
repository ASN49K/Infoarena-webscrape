#include <fstream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
         
    int N, M;
    cin >> N >> M;
   
   vector<int> A(N + 1, 0), B(M + 1, 0);
   vector<vector<int>> LSC(N + 1, vector<int>(M + 1, 0));

   for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i <= M; ++i)
        cin >> B[i];

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                LSC[i][j] = LSC[i - 1][j - 1] + 1;
            else LSC[i][j] = max(LSC[i - 1][j], LSC[i][j - 1]);

    vector<int> result;
    for(int i = N, j = M; i > 0 && j > 0;)
        if(A[i] == B[j]){
            result.push_back(A[i]);
            --i; --j;
        }
        else if(LSC[i][j - 1] < LSC[i - 1][j])
            --i;
        else --j;

    cout << result.size() << "\n";
    for(int i = result.size() - 1; i >= 0; --i)
        cout << result[i] << " ";

    cin.close();
    cout.close();

    return 0;
}
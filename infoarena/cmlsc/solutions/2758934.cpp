#include <iostream>
#include<fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

//https://www.infoarena.ro/problema/cmlsc
int main()
{
    int M, N, A[1024], B[1024];

    // Reading format
    f >> M >> N;
    for(int i = 0; i < M; i++){ f >> A[i]; }
    for(int i = 0; i < N; i++){ f >> B[i]; }

    //compute longest common sequence length according to the D.P. strategy:
    int cmlsc[M][N], cmlsc_im1, cmlsc_jm1, cmlsc_ijm1;
    for(int i=0; i < M; i++){
        for(int j=0; j < N; j++){
            cmlsc_im1    =  i == 0 ? 0 : cmlsc[i - 1][j];
            cmlsc_jm1    =  j == 0 ? 0 : cmlsc[i][j - 1];
            cmlsc_ijm1   =  (j == 0 || i == 0) ? 0 : cmlsc[i - 1][j - 1];
            cmlsc[i][j]  =  A[i] == B[j] ? cmlsc_ijm1 + 1 : max(cmlsc_im1, cmlsc_jm1);
            cout<<cmlsc[i][j]<<" ";
        }
        cout<<"\n";
    }

    //cout << cmlsc[M - 1][N - 1] << endl;
    g << cmlsc[M - 1][N - 1] << "\n";

    //retrieve the elements of the logest common sequence based on the distances matrix:
    int lcs_length = cmlsc[M - 1][N - 1], i = M-1, j = N-1;
    int lcs[lcs_length];

    while(lcs_length){
        if(cmlsc[i][j] > cmlsc[i][j - 1]){
            lcs_length--;
            lcs[lcs_length] = B[j];
            j--;
            cout  << "B " << lcs[lcs_length]<<" "<<i<<j+1 <<"\n";
            continue;
        }
        if(cmlsc[i][j] > cmlsc[i - 1][j]){
            lcs_length--;
            lcs[lcs_length] = A[i];
            i--;
            cout << "A " << lcs[lcs_length]<<" "<<i+1<<j <<"\n";
            continue;
        }
        if (j > 0){ j --; continue; }
        if (i > 0){ i --; continue; }
        if (i==0 && j==0 && lcs_length==1){
            lcs[0] = A[0];
            break;
        }
    }

    //store lcs in output file:

    for (int i=0; i < cmlsc[M - 1][N - 1]; i++){
        g << lcs[i] << " ";
    }

    //cout << cmlsc[M - 1][N - 1] << endl;
    return 0;
}

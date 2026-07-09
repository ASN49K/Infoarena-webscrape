#include <fstream>
#include <vector>
#include <iostream>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int main()
{
    int n, m;
    fin >> n >> m;

    int a[n], b[m], din[n+1][m+1] = {};



    for (int i = 0; i < n; i++) {
            fin >> a[i];
        //din[i][0] = 0;
    }
    for (int i = 0; i < m; i++) {
            fin >> b[i];
        //din[0][i] = 0;
    }

    std::vector<int> subsir;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i] == b[j]){
                din[i+1][j+1] = 1 + din[i][j];
            } else {
                din[i+1][j+1] = std::max(din[i][j+1], din[i+1][j]);
            }
        }
    }


    for (int i = n, j = m; i != 0; ){
        if (a[i-1] == b[j-1]){
            //std::cout << a[i-1] << " " << b[j-1] <<  " " << i << " " << j << "\n";
            subsir.push_back(a[i-1]);
            i--;
            j--;
        } else if (din[i][j-1] > din[i-1][j]){
            j--;
        } else i--;

    }

    fout << subsir.size() << "\n";
    for (int i = subsir.size()-1; i >= 0; i--){
        fout << subsir[i] << " ";
    }

    return 0;
}

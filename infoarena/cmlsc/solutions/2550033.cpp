#include <fstream>
#include <vector>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int main()
{
    int n, m;
    fin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; i++) fin >> a[i];
    for (int i = 0; i < m; i++) fin >> b[i];

    std::vector<int> subsir;
    int anchor = 0;

    for (int i = 0; i < n; i++){
        //anchor = std::max(anchor, i);
        for (int j = anchor; j < m; j++){
            if (a[i] == b[j]){
                anchor = j;
                subsir.push_back(a[i]);
                j = m;
            }
        }
    }

    fout << subsir.size() << "\n";
    for (int i = 0; i < subsir.size(); i++){
        fout << subsir[i] << " ";
    }
    return 0;
}

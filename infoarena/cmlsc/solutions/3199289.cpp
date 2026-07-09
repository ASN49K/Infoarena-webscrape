#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[1026], v2[1026], d[1026][1026];

int main()
{
    int n1, n2;
    fin >> n1 >> n2;
    for(int i=1; i<=n1; i++){
        fin >> v1[i];
    }
    for(int i=1; i<=n2; i++){
        fin >> v2[i];
    }
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            //Caz 1: v1[i] == v2[j]
            if(v1[i] == v2[j]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            //Caz 2: v1[i] != v2[j]
            else{
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    fout << d[n1][n2] << '\n';
    //Reconstruirea sirului
    stack<int> sol;
    int i = n1, j = n2;
    while(i != 0 && j != 0){
        if(v1[i] == v2[j]){
            sol.push(v1[i]);
            i --;
            j --;
        }
        else{
            if(d[i][j] == d[i - 1][j]){
                i --;
            }
            else{
                j --;
            }
        }
    }
    while(!sol.empty()){
        fout << sol.top() << ' ';
        sol.pop();
    }
    return 0;
}

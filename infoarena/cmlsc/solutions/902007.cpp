#include <fstream>
 
#define Max 1024
 
using namespace std;
 
int main(int argc, char *argv[]){
    int sirA[Max], sirB[Max], solutie[Max];
    int mat[Max][Max];
    int lung_A, lung_B, lung_MAX = 0;
    int i, j;
 
    ifstream inFILE("cmlsc.in");
    ofstream outFILE("cmlsc.out");
 
    inFILE >> lung_A >> lung_B;
 
    for (i = 1; i <= lung_A; i++){
        inFILE >> sirA[i];
    }
 
    for (j = 1; j <= lung_B; j++){
        inFILE >> sirB[j];
    }
 
    for (i = 1; i <= lung_A; i++){
        for (j = 1; j <= lung_B; j++){
            if (sirA[i] == sirB[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
        }
    }
 
    i = lung_A;
    j = lung_B;
 
    while (mat[i][j]){
        while (mat[i][j] == mat[i-1][j])
            i--;
        while (mat[i][j] == mat[i][j-1])
            j--;
 
        lung_MAX++;
        solutie[lung_MAX] = sirA[i];
        i--;
        j--;
    }
 
    outFILE << mat[lung_A][lung_B] << "\n";
 
    for (i = lung_MAX; i >= 1; --i)
        outFILE << solutie[i] << " ";
 
    return 0;
}
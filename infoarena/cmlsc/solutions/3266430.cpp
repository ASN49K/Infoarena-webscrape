#include <fstream>
#include <vector>

using namespace std;

ifstream fin("pipe.in");
ofstream fout("pipe.out");

int n;

int DP(int index, int size, int target, vector<int> &dp, vector<int> &pipe) {

    if(index >= n)
        return 30001;
    
    if(target == 0)
        return 0;
    
    int value = pipe[index];

    return min(abs(value)+DP(index+1, size, target-value, dp, pipe), DP(index+1, size, target, dp, pipe));
}

int main() {

    int xi, yi, xf, yf, dist_x, dist_y;
    fin >> n >> xi >> yi >> xf >> yf;
    
    dist_x = abs(xf-xi);
    dist_y = abs(yf-yi);

    vector<int> x,y;
    
    for(int i=0; i<n; i++) {
        char type;
        int lenght;
        fin >> type >> lenght;
        if(type == 'A') {
            x.push_back(lenght);
            x.push_back(-lenght);
        }
            
        else {
            y.push_back(lenght);
            y.push_back(-lenght);
        }
            
    }

    vector<int> dp(29e3, 29001);

    int size1 = x.size();
    int size2 = y.size();

    int lung_x = DP(1, size1, dist_x, dp, x);
    for(int i=0; i<29e3; i++)
        dp[i]=0;
    int lung_y = DP(1, size2, dist_y, dp, y);
    
    if(lung_x >= 30001 || lung_y >= 30001) {
        fout << "imposibil";
    }
    else {
        fout << lung_x + lung_y;
    }
        

    return 0;
}
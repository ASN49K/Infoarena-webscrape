#include <fstream>
#include <vector>
using namespace std;

int main() 
{
    ifstream in;
    ofstream out;
    vector<int> v1;
    vector<int> v2;
    
    in.open("cmlsc.in");
    out.open("cmlsc.out");
    int m, n, a;
    
    in>>m>>n;
    
    for(int i = 0; i < m; i++)
    {
        in>>a;
        v1.push_back(a);
    }
    
    for(int i = 0; i < n; i++)
    {
        in>>a;
        for(int i = 0; i < m; i++)
        {
            if(v1[i] == a) out<<a<<" ";
        }
    }
    
    in.close();
    out.close();
    return 0;
}
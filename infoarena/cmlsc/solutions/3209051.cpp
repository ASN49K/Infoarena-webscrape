#include <fstream>
#include <vector>
using namespace std;

int main() 
{
    ifstream in;
    ofstream out;
    
    in.open("cmlsc.in");
    out.open("cmlsc.out");
    int v1[1024];
    vector<int> v2;
    
    long long m, n, a;
    
    in>>m>>n;
    
    for(int i = 0; i < m; i++)
    {
        in>>v1[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        in>>a;
        for(int i = 0; i < m; i++)
        {
            if(v1[i] == a) v2.push_back(a);
        }
    }
    
    out<<v2.size()<<endl;
    
    for(long long i = 0; i < v2.size(); i++)
    {
        out<<v2[i]<<" ";
    }
    
    in.close();
    out.close();
    return 0;
}
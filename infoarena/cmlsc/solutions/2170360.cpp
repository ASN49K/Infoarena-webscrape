#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int data1[1025], data2[1025], dynamicMap[1025][1025], answer[1024];
int data1_size, data2_size, answerPointer = 0;

int max(int x, int y)
{
    if(x==y)return x;
    if(x>y)return x;
    else return y;
}
void initialization()
{
    int i;
    for(i=1; i<=data1_size; i++)
        in>>data1[i];
    for(i=1; i<=data2_size; i++)
        in>>data2[i];
}
void mapInitialization()
{
    int i;
    for(i=0; i<=data1_size; i++)
        dynamicMap[i][0] = 0;
    for(i=1; i<=data2_size; i++)
        dynamicMap[0][i] = 0;
}

void mapLCS_Algorithm()
{
    int i, j;
    for(i=1; i<=data1_size; i++)
        for(j=1; j<=data2_size; j++)
        {
            if(data1[i]==data2[j]) dynamicMap[i][j] = dynamicMap[i-1][j-1] + 1;
            else
                dynamicMap[i][j] = max(dynamicMap[i-1][j], dynamicMap[i][j-1]);
        }
}

void dynamicBacktrack()
{
    int i,j;
    i = data1_size;
    j = data2_size;
    while(dynamicMap[i][j]!=0)
    {
        if(dynamicMap[i][j] == dynamicMap[i-1][j])
        {
            i = i-1;
        }
        else if(dynamicMap[i][j] == dynamicMap[i][j-1])
        {
            j = j-1;
        }
        else
        {
            answer[answerPointer] = data1[i];
            answerPointer++;
            i = i-1;
            j = j-1;
        }
    }

}

int main()
{
    in>>data1_size>>data2_size;
    int i;
    initialization();
    mapInitialization();
    mapLCS_Algorithm();
    out<<dynamicMap[data1_size][data2_size]<<'\n';
    dynamicBacktrack();
    for(answerPointer-=1; answerPointer>=0; answerPointer--)
        out<<answer[answerPointer]<<" ";
    return 0;
}

#include<fstream>
#include<string>
using namespace std;
int nrOfMatches=0, matches[1005];
ifstream inputStream("strmatch.in");
ofstream outputStream("strmatch.out");
void stringmatchNaive(string &pattern, string &subject)
{
	int patterSize = pattern.size(), subjectSize = subject.size(), i = 0,j;
	while (i < subjectSize - patterSize)
	{
		i++;
		j = 0;
		while (pattern[j] == subject[i + j])
		{
			if (j == patterSize - 1)
			{
				if (nrOfMatches == 999)
					break;
				matches[nrOfMatches] = i;
				nrOfMatches++;
				j++;
			}
			else
				j++;
		}
		
	}
}
int main()
{
	string pattern, subject;
	//inputStream >> pattern;
	getline(inputStream, pattern);
	//inputStream >> subject;
	getline(inputStream, subject);
	stringmatchNaive(pattern, subject);
	outputStream << nrOfMatches << std::endl;
	for (int i = 0; i < nrOfMatches; i++)
		outputStream << matches[i] << " ";
	return 0;
}
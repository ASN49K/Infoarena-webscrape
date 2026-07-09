#include <fstream>
#include <string>
#include <vector>

void swap(int& a, int& b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}

int cmmdc(int a, int b)
{
	if (a > b)
	{
		swap(a, b);
	}

	int r = a % b;

	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main()
{
	std::string input_filename = "euclid2.in";
	std::string output_filename = "euclid2.out";

	std::ifstream in_file(input_filename);

	int n_pairs;
	std::vector<std::vector<int>> v_pairs;

	if (in_file.is_open())
	{
		in_file >> n_pairs;

		for (unsigned int i = 0; i < n_pairs; i++)
		{
			int a, b;
			in_file >> a >> b;
			v_pairs.push_back({ a, b });
		}
	}

	std::ofstream out_file(output_filename);

	for (unsigned i = 0; i < v_pairs.size(); i++)
	{
		int result = cmmdc(v_pairs[i][0], v_pairs[i][1]);
		out_file << result << "\n";
	}

	out_file.close();
	return 0;

}
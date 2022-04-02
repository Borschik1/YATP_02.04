#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n, d, answer = 0, line_size = 0, maxi;
	fin >> n >> d;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		fin >> vec[i];
		line_size = max(line_size, vec[i]);
	}
	vector<int> line(line_size, 0);
	for (int i = 0; i < n; ++i) {
		line[vec[i] - 1]++;
		maxi = max(maxi, line[vec[i] - 1]);
		for (int j = 1; j <= d; ++j) {
			if (vec[i] - 1 + j < line_size) {
				line[vec[i] - 1 + j]++;
				maxi = max(maxi, line[vec[i] - 1 + j]);
			}
			if (vec[i] - 1 - j > 0) {
				line[vec[i] - 1 - j]++;
				maxi = max(maxi, line[vec[i] - 1 - j]);
			}
		}
	}
	fout << maxi << endl;
	maxi = 0;
	for (int i = 0; i < n; ++i) {
		maxi = line[vec[i] - 1];
		line[vec[i] - 1]--;
		for (int j = 1; j <= d; ++j) {
			if (vec[i] - 1 + j < line_size) {
				maxi = max(maxi, line[vec[i] - 1 + j]);
				line[vec[i] - 1 + j]--;
			}
			if (vec[i] - 1 - j > 0) {
				maxi = max(maxi, line[vec[i] - 1 - j]);
				line[vec[i] - 1 - j]--;
			}
		}
		fout << maxi << " ";
	}
	fin.close();
	fout.close();
}

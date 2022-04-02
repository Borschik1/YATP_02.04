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
	int n, d, now = 0, answer = 0;
	fin >> n >> d;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		fin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; ++i) {
		now += vec[i];
		if (now >= d) {
			answer++;
			now -= d;
		}
	}
	answer++;
	fout << answer;
	fin.close();
	fout.close();
}
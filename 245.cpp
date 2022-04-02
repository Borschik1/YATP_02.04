#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	vector<int> vec(60001, 0);
	int n, need, maxi = 0, prev = -1;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> need;
		vec[need]++;
	}
	for (int i = 0; i < 60001; ++i) {
		if (vec[i] == 0) {
			continue;
		}
		if (vec[i] >= 2) {
			int now = 0;
			for (int j = i; j <= min(2 * i, 60000); ++j) {
				now += vec[j] * j;
			}
			maxi = max(maxi, now);
		}
		if (prev >= 0) {
			int now = prev;
			for (int j = i; j <= prev + i; ++j) {
				now += vec[j] * j;
			}
			maxi = max(maxi, now);
		}
		prev = i;
	}
	fout << maxi;
	fin.close();
	fout.close();
}

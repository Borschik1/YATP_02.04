#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

map<char, int> inic() {
	map<char, int> dict;
	string nums = "0123456789", abc = "abcdefghijklmopqrstuvwxyz";
	for (int i = 0; i < 10; ++i) {
		dict.emplace(nums[i], 0);
	}
	for (int i = 0; i < 26; ++i) {
		dict.emplace(abc[i], 0);
	}
	return dict;
}


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n, k, answer = 0;
	string str;
	map<char, int> dict;
	fin >> n >> k;
	fin >> str;
	for (int i = 0; i < n; ++i) {
		dict = inic();
		for (int j = 0; j < n - i; ++j) {
			dict[str[i + j]]++;
			if (dict[str[i + j]] <= k) {
				answer++;
			}
			else {
				break;
			}
		}
	}
	fout << answer;
	fin.close();
	fout.close();
}
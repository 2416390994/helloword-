#include<iostream>
#include<fstream>
#include<string>
#include <vector>
using namespace std;
int main(int argv, char *arg[]){
	ofstream file;
	file.open("file.txt");
	file << "123" << endl;
	file << "123" << endl;
	fstream f("file.txt");
	string line;
	for (int i = 0; i < 2; i++)
	{
		getline(f, line);
		cout << line << endl;;
	}
	return  0;
}

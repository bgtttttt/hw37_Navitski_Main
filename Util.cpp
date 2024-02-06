#include <iostream>
#include <time.h>
#include <string>

#define m 4
#define n 6

using namespace std;

string ShowGrades(int matrix[][n]) {
	string s = "";
	for (int i = 0; i < m; i++) {
		s += "Group " + to_string(i+1) + ": ";
		for (int j = 0; j < n; j++) {
			s = s + to_string(matrix[i][j]) + "\t";
		}
		s += "\n";
	}
	return s;
}

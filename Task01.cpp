#include <iostream>
#include <time.h>
#include <string>

#define m 4
#define n 6

using namespace std;

string ShowGrades(int matrix[][n]);
int NumberOfGroupWithMaxNumOfTens(int matrix[m][n]);
int FindGroupWithUnsatisfGrade(int matrix[m][n]);
int FindGroupWithBestAvg(int matrix[m][n]);
void AddPointToGroup(int* group);
double getAvg(int* group);
void sortByAvgGrade(int groups[m][n]);


int main() {
	srand(time(0));

	int matrix[m][n] = {
		{8, 7, 7, 10, 9, 9},
		{5, 8, 7, 8, 10, 9},
		{9, 10, 10, 9, 10, 10},
		{9, 8, 7, 1, 2, 7}
	};

	cout << "Grades:" << endl;
	cout << ShowGrades(matrix);

	int group = FindGroupWithUnsatisfGrade(matrix);
	string msg = (group == -1) ?
		"There aren't any groups with unsatisfactory grades" : to_string(group);

	cout << "\n\nNumber of group with max number of tens: "
		<< NumberOfGroupWithMaxNumOfTens(matrix) << "\n";
	cout << "Number of group with unsatisfactory grade: "
		<< msg << "\n";
	AddPointToGroup(matrix[FindGroupWithBestAvg(matrix)]);
	cout << "\nGrades after adding points to best group:" << endl;
	cout << ShowGrades(matrix) << "\n";
	sortByAvgGrade(matrix);
	cout << "Groups after sorting by avg grade:" << endl;
	cout << ShowGrades(matrix) << "\n\n";
	return 0;
}

int NumberOfGroupWithMaxNumOfTens(int matrix[m][n]) {
	int count = 0;
	int maxCount[2] = { 0,0 };
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 10) {
				count++;
			}
		}
		if (maxCount[0] < count) {
			maxCount[0] = count;
			maxCount[1] = i + 1;
		}
		count = 0;
	}
	return maxCount[1];
}
int FindGroupWithUnsatisfGrade(int matrix[m][n]) {
	int group = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] < 4) {
				return (i + 1);
			}
		}
	}
	return -1;
}
int FindGroupWithBestAvg(int matrix[m][n]) {
	double maxAvg[2] = { 0,0 };
	double avg = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			avg += matrix[i][j];
		}
		avg /= n;
		if (maxAvg[0] < avg) {
			maxAvg[0] = avg;
			maxAvg[1] = i;
		}
		avg = 0;
	}
	return maxAvg[1];
}
void AddPointToGroup(int* group) {
	for (int i = 0; i < n; i++) {
		if (group[i] < 10) {
			group[i] += 1;
		}
	}
}
double getAvg(int* group) {
	int avg = 0;
	for (int i = 0; i < n; i++) {
		avg += group[i];
	}
	avg /= n;
	return avg;
}
void sortByAvgGrade(int groups[m][n]) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < m - i - 1; j++) {
			if (getAvg(groups[j]) < getAvg(groups[j + 1])) {
				for (int k = 0; k < n; k++) {
					swap(groups[j][k], groups[j + 1][k]);
				}
			}
		}
	}
}
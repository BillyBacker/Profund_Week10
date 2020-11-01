#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;
vector<vector<int>> pascalTriangle;
vector<int> triangleRow(int rowNum) {
	vector<int> output = {1};
	if (rowNum == 0) {
		pascalTriangle.push_back(output);
		return output;
	}
	else if (rowNum == 1){
		output.push_back(1);
		pascalTriangle.push_back(output);
		return output;
	}
	else {
		for (int i = 0; i < pascalTriangle[rowNum-1].size()-1; i++) {
			output.push_back(pascalTriangle[rowNum - 1][i] + pascalTriangle[rowNum - 1][i + 1]);
		}
		output.push_back(1);
		pascalTriangle.push_back(output);
		return output;
	}
}

int main() {
	vector<int> output;
	int row, factor = 2;
	printf("Enter row of triangle (0-25): ");
	scanf("%d", &row);
	if (row <= 6) {
		factor = 1;
	}
	else if(row <= 25){
		factor = 2;
	}
	else {
		printf("Number too big.");
		return 0;
	}
	for (int i = 0; i < row; i++) {
		output = triangleRow(i);
		for (int k = factor *row - factor *i; k > 0; k--) {
			printf("  ");
		}
		for (int j = 0; j < output.size(); j++) {
			if (row <= 6) {
				printf("%4d", output[j]);
			}
			else if(row <= 25) {
				printf("%8d", output[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
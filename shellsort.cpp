/*
MARIO ANDRES RENDON
SID: 200370018
ASSIGNMENT 4 - SHELLSORT
CS - 340

Implement Shellsort with Hibbard’s gap sequence, with Shell’s gap sequence, and with a gap sequence of your
own invention, and compare them on three input/output examples for duplicate-free arrays of size 10, 100, and
1000 (one of each size). Report the number of comparisons made in each case.

*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

class ToSort {
public:
	ToSort() {
		size_of_arr = 0;
	}

	ToSort(int size) {
		size_of_arr = size;
		arr = new int[size_of_arr];
	};

	void buildArr(string filename) {
		ifstream inData;
		inData.open(filename);
		if (!inData) {
			cout << "ERROR - FILE NOT FOUND!" << endl;
		}

		int number_of_elements = 0;
		while(!inData.eof()) {
			inData >> arr[number_of_elements];
			number_of_elements++;
		}
   }

	int ShellSort() {
		int comparisons = 0;
		for (int gap = floor(size_of_arr / 2); gap > 0; gap /= 2) {
			for (int i = gap; i < size_of_arr; ++i) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap; j -= gap) {
					if (arr[j - gap] > temp) {
						comparisons++;
						arr[j] = arr[j - gap];
					}
					else {
						comparisons++;
						break;
					}
				}
				arr[j] = temp;
			}

		}
		return comparisons;
	};


	int Hibbard() {
		int k = log(size_of_arr) / log(2);
		int gap = pow(2, k) - 1;
		int comparisons = 0;
		while(gap > 0){
			for (int i = gap; i < size_of_arr; ++i) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap; j -= gap) {
					if (arr[j - gap] > temp) {
						comparisons++;
						arr[j] = arr[j - gap];
					}
					else {
						comparisons++;
						break;
					}
				}
				arr[j] = temp;
			}
			k -= 1;
			gap = pow(2, k) - 1;
		}
		return comparisons;
	};

	int PrattSqn() {
		int k = log(size_of_arr/3) / log(3);
		int gap = (pow(3, k) - 1) / 2;
		int comparisons = 0;
		while (gap > 0) {
			for (int i = gap; i < size_of_arr; ++i) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap; j -= gap) {
					if (arr[j - gap] > temp) {
						comparisons++;
						arr[j] = arr[j - gap];
					}
					else {
						comparisons++;
						break;
					}
				}
				arr[j] = temp;
			}
			k -= 1;
			gap = (pow(3, k) - 1) / 2;
		}
		return comparisons;
	};

	void print(int comparison) {
		cout << comparison << " Comparison: " << " | ";
		for (int i = 0; i < size_of_arr; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << endl;
	};


private:
	int size_of_arr;
	int *arr;
};


int main() {
	cout << "Enter file name (size10.txt , size100.txt or size1000.txt): ";
	string file;
	getline(cin, file);
	cout << "Enter Size of array: ";
	int n;
	cin >> n;
	
	ToSort shellSequence(n);
	shellSequence.buildArr(file);
	ToSort HibbardSqn(n);
	HibbardSqn.buildArr(file);
	ToSort MySqn(n);
	MySqn.buildArr(file);
	
	int x = shellSequence.ShellSort();
	int y = HibbardSqn.Hibbard();
	int z = MySqn.PrattSqn();

	cout << "\n**************RESULTS***********\n";
	cout << "\nShellSort = ";
	shellSequence.print(x);
	cout << "\nHibbard's = ";
	HibbardSqn.print(y);
	cout << "\nPratt's =   ";
	MySqn.print(z);
	cout << endl;
	cout << endl;

};
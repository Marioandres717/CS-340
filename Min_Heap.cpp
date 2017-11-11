/*
Mario Andres Rendon
SID: 200370018
ASSIGNMENT 3 - CS 340

MIN HEAP - WHAT DO I DO FUNCTION

a) Implement the following algorithm, which is given a duplicate-free array array as input, in C++.
whatDoIDo (array):
1) Build a heap from array (using buildHeap as explained in class), where the heap starts at position array[0].
2) Starting from j = size of array - 1, as long as j>0:
i. Swap the entries array[0] and array[j].
ii. Percolate down array[0], but only within the subarray array[0..j-1].
iii. Decrement j by 1.
Provide three input/output examples for duplicate-free arrays of size about 10.
(b) What does whatDoIDo do? Explain your answer.
(c) What is the worst-case running time of whatDoIDo, in dependence of the size N of the given array? Explain your
answer.
*/

#include <iostream>
using namespace std;

void swap(int *x, int *y) {     //using pointers to change values in the heap array
	int temp = *x;		
	*x = *y;
	*y = temp;
};


class Heap {
private:
	int *arr;
	int size_of_array;
	int max_size;
public:
	Heap(int size) {
		size_of_array = 0;
		max_size = size;
		arr = new int[max_size];
	};

	int parent(int i) {
		return (i - 1) / 2;
	};

	int left_child(int i) {
		return (2 * i + 1);
	};

	int right_child(int i) {
		return (2 * i + 2);
	};

	void insertion(int k) {

		if (size_of_array == max_size) {
			cout << "OVERFLOW, cannot perform the insertion \n";
			return;
		}

		size_of_array++;
		int i = size_of_array - 1;
		arr[i] = k;
	};

	void printHeap() {
		for (int j = 0; j < size_of_array; j++) {
			cout << arr[j] << " ";
		}
	}


	// percolateDown  is implemented as the BuildHeap taught in class
	void percolateDown() {

		int i;

		for (i = floor(size_of_array / 2); i >= 0; i--) {
			int parent = i;
			bool exit_loop = true;

			while (exit_loop) {

				int left = arr[left_child(parent)];
				int right = arr[right_child(parent)]; 
				int smaller = arr[parent];
				bool left_is_smaller = false;	//use of flags to know which side of the tree we have to percolate
				bool right_is_smaller = false;


				//We have to make sure that we are not passing the boundaries (size_of_array) in our array.
				// after we compare the values of our left child and our parent, if child is smaller we store child in a var
				if (left_child(parent) < size_of_array && left < smaller) {
					smaller = left;
					left_is_smaller = true;
				}

				//Then we check the right child, if the right is smaller of all 3 (other 2 are parent,left child)
				//we store right child in a variable
				if (right_child(parent) < size_of_array && right < smaller) {
					smaller = right;
					right_is_smaller = true;
					left_is_smaller = false;
				}

				if (smaller != arr[parent]) {
					if (left_is_smaller) {    //use of flags to know which path in the tree we will take
						swap(&arr[left_child(parent)], &arr[parent]); //passing pointer values to the swap function
						parent = 2 * parent + 1;   //because we using index 0 as the beginning of our heap, the left child node
					}							// will be find at index 2*i+1. instead of 2*i
					else if (right_is_smaller) {
						swap(&arr[right_child(parent)], &arr[parent]);
						parent = 2 * parent + 2;	// Thus from the right child node will be located 2*i+2. instead of 2*i+1
					}
				}
				else
					exit_loop = false;
			}
		}

	};


	


	/**************************************************************************
	WHAT DO I DO FUNCTION AND PERCOLATEDOWN FROM ROOT FUNCTION
	***************************************************************************/
	void whatDoIDo(int duplicate[], int n) {
		Heap buildHeap(max_size);
		for (int i = 0; i < n; i++) {
			buildHeap.insertion(duplicate[i]);
		};

		cout << "\Printing after Calling the percolateDown function: ";
		buildHeap.percolateDown();
		buildHeap.printHeap();
		
		for (int j = n - 1; j > 0; j--) {
			swap(&buildHeap.arr[0], &buildHeap.arr[j]);
			buildHeap.percolateDownSubtree(j);
		};

		cout << "\nPrinting after Calling the percolateDownSubtree function: ";
		buildHeap.printHeap();
	
	};

	// This function works the same as the one above, the only difference is that we are percolating from the root everytime
	// and only in subtrees a[a...j-1] range.
	void percolateDownSubtree(int j) {

		bool isOver = true;
		int parent = 0;   // We percolate from the root down

		while (isOver) {

			int left = arr[left_child(parent)];
			int right = arr[right_child(parent)];
			int smaller = arr[parent];
			bool left_is_smaller = false;
			bool right_is_smaller = false;

			if (left_child(parent) < j && left < smaller) {  //our array boundarie (size) is j
				smaller = left;
				left_is_smaller = true;
			}

			if (right_child(parent) < j && right < smaller) {
				smaller = right;
				right_is_smaller = true;
				left_is_smaller = false;
			}

			if (smaller != arr[parent]) {
				if (left_is_smaller) {
					swap(&arr[left_child(parent)], &arr[parent]);
					parent = left_child(parent);
				}
				else if (right_is_smaller) {
					swap(&arr[right_child(parent)], &arr[parent]);
					parent = right_child(parent);
				}
			}
					
			else
				isOver = false;
		}
	}
};

int main() {
	cout << "Enter number of elements for WhatDoIDo arr: ";
	int Arr[100];
	int n;
	cin >> n;
	Heap WhatDoIDoArr(n);
	int k;
	for (int i = 0; i < n; i++) {
		cin >> Arr[i];
	};

	WhatDoIDoArr.whatDoIDo(Arr, n);

	return 0;

};
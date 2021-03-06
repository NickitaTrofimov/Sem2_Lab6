#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

void tusk1(int a[], int size) {
	int sum = 1;

	for (int i = 1; i < size; i = i + 2) {
		sum = sum * a[i];
	}

	cout << "Summ of mod = " << sum << endl;
}

void tusk2(int a[], int size) {
	int max = a[0];
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (a[i] <= a[i + 1]) {
			max = a[i + 1];
			count++;
		}
	}

	int *a2 = new int[size - 1];
	if (count != size - 1) {
		for (int i = 0; i < count + 1; i++) {
			a2[i] = a[i];
		}
		for (int i = count + 1; i < size - 1; i++) {
			a2[i] = a[i + 1];
		}

		cout << "Resulting array: ";
		for (int i = 0; i < size - 1; i++) {
			cout << a2[i] << " ";
		}
		cout << endl;

	}
	else {
		cout << "Last maximum was last element of array" << endl;
	}

	cout << endl;

	delete[] a2;
}

int main() {
	int size;
	cout << "Enter size of array" << endl;
	cin >> size;
	int *arr = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Arr[" << i << "] = ";
		cin >> arr[i];
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << "Arr[" << i << "] = " << arr[i] << endl;
	}

	int operation;
	int check = 0;

	cout << "What operations you want to do?\n1) Composition of elements with odd indices\n2) Removal of the element after the last maximum\n" << endl;
	while (check == 0) {
		cin >> operation;
		switch (operation) {
		case 1: {
			tusk1(arr, size);
			check = 1;
			break;
		}
		case 2: {
			tusk2(arr, size);
			check = 1;
			break;
		}
		default: {
			cout << "Incorrect input, try again: " << endl;
		}
		}
	}

	delete[] arr;

}

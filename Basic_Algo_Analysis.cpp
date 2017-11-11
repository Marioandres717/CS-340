/*
	Mario Andres Rendon
	SID: 200370018
	Assignment 1 - problem 4

	• Your main program declares variables named start and finish of type clock t.
	• In order to evaluate assignment1Algorithm on input n, your main program processes the
	following fragment.
	start = clock();
	result = assignment1Algorithm(n);
	finish = clock();
	timeUsed = ((long double)(finish - start))/CLOCKS PER SEC;
	This essentially stores the total time consumed by assignment1Algorithm(n) in timeUsed.
	• Your program outputs the following values (via std::cout) for every input value n:
	(i) the result returned by assignment1Algorithm(n), stored in a variable named result,
	(ii) the value of n divided by result,
	(iii) the value of n*log2(n) divided by result,
	(iv) the value of pow(n,1.5) divided by result,
	(v) the total time timeUsed used by assignment1Algorithm on input n,
	1
	(vi) the value of n divided by timeUsed,
	1
	(vii) the value of n*log2(n) divided by timeUsed,
	1
	(viii) the value of pow(n,1.5) divided by timeUsed.
	1
	1You may multiply the values (v) through (viii) by a constant factor (like 105 or 106
	) to be
	able to better observe the differences between the numbers you record.

	(b) Report the output of your program on the following inputs for n: 10, 100, 1,000, 10,000, 100,000,
	1,000,000, 10,000,000, 20,000,000, 50,000,000, 100,000,000, 300,000,000.

	(c) Taking the outputs reported in (b) into account, what do you conclude concerning the asymptotic
	growth of the result returned by assignment1Algorithm(n) for growing n? What do you conclude
	concerning the asymptotic growth of the running time of assignment1Algorithm(n) for growing n?
	What do you conclude about the growth rates of the three functions f1(n) = n, f2(n) = n · log(n),
	and f3(n) = n
	√
	n, compared to one another?


*/

#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

long long assignment1Algorithm(long long n) {

	long long sum = 0;

	for (long long i = 1; i <= n; i++) 
	{
		for (long long j = n; j > 1; j = floor(j / 2)) 
		{
			sum += 1;
		}
	}
	return (sum);
}

int main() {

	clock_t start;
	clock_t finish;
	long long n;

	cout << "ENTER N: ";
	cin >> n;
	start = clock();
	long long result = assignment1Algorithm(n);
	finish = clock();
	long double timeUsed = ((long double)(finish - start))/CLOCKS_PER_SEC;

	//cout << result << " TIME USED " << ((long double)(finish - start)) / CLOCKS_PER_SEC << endl;
	cout << "Result from assignment1Algorithm:  " << result << endl;
	cout << "Value of n divided by result:  " << n/result << endl;
	cout << "Value of n*log2(n) divided by result:  " << (n*log2(n))/result << endl;
	cout << "Value of pow(n,1.5) / result: " << pow(n,1.5) / result << endl;
	cout << "Total time used by assignment1Algorithm on input n:  " << timeUsed  << endl;
	cout << "Value of n / timeUsed:  " << (n/timeUsed)*1000000  << endl;
	cout << "Value of n*log2(n) divided by timeUsed:  " << ((n*log2(n)) / timeUsed) * 1000000 << endl;
	cout << "Value of pow(n,1.5) / timeUsed:  " << (pow(n, 1.5) / timeUsed)*1000000  << endl;
	return 0;
}
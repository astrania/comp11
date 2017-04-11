/* 
sortswap.cpp: sort four integers by repetitively
			  invoking a swap function
Created on: March.8, 2017
Author: Kaimeng Yang
*/

#include <iostream>
using namespace std;

int main()
{
	int n1, n2, n3, n4;

	cout << "Please enter four numbers: " << endl;
	cin >> n1; 
	cin >> n2;
	cin >> n3; 
	cin >> n4;

	if (n1 > n2) swap(n1, n2);
	if (n1 > n3) swap(n1, n3);
	if (n1 > n4) swap(n1, n4);

	if (n2 > n3) swap(n2, n3);
	if (n2 > n4) swap(n2, n4);

	if (n3 > n4) swap(n3, n4);
	
	cout << "In sorted order, they are: " << endl;
	cout << n1 << n2 << n3 << n4 << endl;

	return 0;
}

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
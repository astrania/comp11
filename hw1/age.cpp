/* 
Age.cpp: Calculate the how many hours old your user is, given their age in years
Created on: Jan.27, 2017
Author: Kaimeng Yang
*/

/*
Test files: 
Test input: 50 years
Expected output: 438000 hours

Test input: 200 years
Expected output: 1752000 hours

Test input: 78 years
Expected output: 683280 hours
*/

#include <iostream>
using namespace std;

int main(){
	int age_years, age_hours;
	int const converting_num = 8760; // One year is equal to 8760 hours

	cout << "Please input your current age, in years: " << endl;
	cin >> age_years;

	age_hours = age_years * converting_num;

	cout << "Wow, your age in hours is: " << age_hours << endl;

	return 0;
}
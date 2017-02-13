/* 
Bicycles.cpp: Calculate how many bikes you can make with the number of wheels, frames, and links. 
Created on: Feb.4, 2017
Author: Kaimeng Yang
*/

/*
Test input: 500 wheels, 50 frames, 50 links
output: 1 bikes, leftover: 498 wheels, 49 frames, 0 links  

input: 5 wheel, 6 frames, 7 links
output: 0 bikes, leftover: 5 wheels, 6 frames, 7 links

input: -6 wheels, -9 frames, -10 links
output: 1 bikes, leftover: 0 wheels, 0 frames, 0 links 
 */
#include <iostream> 
using namespace std;

const int min_value = 0, max_value = 1000;
const int wheels_default = 2, frames_default = 1, links_default = 50;

bool validityCheck(int num);
int minimum(int first_num, int second_num, int third_num);
int wheelsCheck(int num_wheels);
int framesCheck(int num_frames);
int linksCheck(int num_links);
int bikeCreation(int num_one, int num_two, int num_three);
void leftoversCheck(int num_wheels, int num_frames, int num_links, int num_bikes);

int main()
{	
	int num_wheels, num_frames, num_links;
	int wheels_bike, frames_bike, links_bike;
	int bikes;

	cout << "How many wheels do you have？" << endl;
	cin >> num_wheels;
	wheels_bike = wheelsCheck(num_wheels);

	cout << "How many frames do you have？" << endl;
	cin >> num_frames;
	frames_bike = framesCheck(num_frames);

	cout << "How many links do you have？" << endl;
	cin >> num_links;
	links_bike = linksCheck(num_links);

	bikes = bikeCreation(wheels_bike, frames_bike, links_bike);

	leftoversCheck(num_wheels, num_frames, num_links, bikes);

	return 0;
}

// check if the user enters valid numbers
// return false if the numbers are invalid 
bool validityCheck(int num)
{
    	if((num < min_value) ||(num > max_value))
    	{
		return false;
    	}
    	return true;
}

// calculate how many bikes can be made with the number of wheels specified
// perform a validity check first, if it can' pass it, use the default number for calculation
// return the number of bikes 
int wheelsCheck(int num_wheels){
	int wheels_bike;

	if (validityCheck(num_wheels) == false)
	{
		cout << "No you don't. I am going to assume you have " << wheels_default << " wheels." << endl;
		wheels_bike = wheels_default / wheels_default;
	}
	else 
	{	
		wheels_bike = num_wheels / wheels_default;
	}
	cout << "That's enough for " << wheels_bike << " bikes." << endl;

	return wheels_bike;
}

// same logic as above
int framesCheck(int num_frames){
	int frames_bike;

	if (validityCheck(num_frames) == false)
	{
		cout << "No you don't. I am going to assume you have " << frames_default << " frames." << endl;
		frames_bike = frames_default / frames_default;
	}
	else 
	{
		frames_bike = num_frames / frames_default;
	}
	cout << "That's enough for " << frames_bike << " bikes." << endl; 

	return frames_bike;
}

int linksCheck(int num_links){
	int links_bike;

	if (validityCheck(num_links) == false)
	{
		cout << "No you don't. I am going to assume you have " << links_default << " links." << endl;
		links_bike = links_default / frames_default;
	}
	else 
	{
		links_bike = num_links / links_default;
	}
	cout << "That's enough for " << links_bike << " bikes." << endl; 

	return links_bike;
}

// compute the min of three numbers
int minimum(int first_num, int second_num, int third_num)
{
	int min = first_num;

	if(second_num < min)
	{
		min = second_num;
	}
	if (third_num <  min)
	{
		min = third_num;
	}

	return min;
}

int bikeCreation(int num_one, int num_two, int num_three)
{
	int num_bikes;
	
	// number of bikes can be made is the minimum of the three numbers,
	// that is, the number of wheels_bike, frames_bike and links_bike
	num_bikes = minimum(num_one, num_two, num_three);

	cout << "I can make you " << num_bikes << " bikes, come back tomorrow with cash " << endl;

	return num_bikes;
}

void leftoversCheck(int num_wheels, int num_frames, int num_links, int num_bikes)
{
	int num_leftover_wheels, num_leftover_frames, num_leftover_links;
	
	// perform a validity check first
	// to make sure to use the correct numbers to calculate 
	if (validityCheck(num_wheels) == false)
	{
		num_wheels = wheels_default;
	}	
	num_leftover_wheels = num_wheels - num_bikes * wheels_default;

	if (validityCheck(num_frames) == false)
	{
		num_frames = frames_default;
	}
	num_leftover_frames = num_frames - num_bikes * frames_default;

	if (validityCheck(num_links) == false)
	{
	    num_links = links_default;
	}		
	num_leftover_links = num_links - num_bikes * links_default;
        

	cout << "I'm keeping the leftovers in my shop: " << endl;
	cout << num_leftover_wheels  << " wheels, " << num_leftover_frames << " frames, and " << num_leftover_links << " links"  << endl;

	return;
}

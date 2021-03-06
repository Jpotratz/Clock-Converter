// CH14_4.cpp : Defines the entry point for the console application.
// James Potratz

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
//Global Variables
string input, output, timeOfDay;
int hours, minutes, seconds;
//Exception class to handle invalid hours
class invalidHr
{
public:
	invalidHr()
	{
		message = "Hour input is invalid";
	}
	invalidHr(string str)
	{
		message = str + "is invalid";
	}
	string what()
	{
		return message;
	}
private:
	string message;
};
//Exception class to handle invalid minutes
class invalidMin
{
public:
	invalidMin()
	{
		message = "Minute input is invalid";
	}
	invalidMin(string str)
	{
		message = str + "is invalid";
	}
	string what()
	{
		return message;
	}
private:
	string message;
};
//Exception class to handle invalid seconds
class invalidSec
{
public:
	invalidSec()
	{
		message = "Second input is invalid";
	}
	invalidSec(string str)
	{
		message = str + "is invalid";
	}
	string what()
	{
		return message;
	}
private:
	string message;
};
//Exception class to handle invalid time of day
class invalidTimeOfDay
{
public:
	invalidTimeOfDay()
	{
		message = "Time of Day input is invalid";
	}
	invalidTimeOfDay(string str)
	{
		message = str + "is invalid";
	}
	string what()
	{
		return message;
	}
private:
	string message;
};
//Function to convert Hours, minutes, seconds into 24-hr format
void convertTime(int hours, int minutes, int seconds)
{
	if (hours > 12 || hours < 0) throw invalidHr();
	if (minutes > 59 || minutes < 0) throw invalidMin();
	if (seconds > 59 || seconds < 0) throw invalidSec();
	if (!((timeOfDay == "AM") || (timeOfDay == "PM") || (timeOfDay == "pm") || (timeOfDay == "am"))) throw invalidTimeOfDay();
	if (timeOfDay == "PM" || timeOfDay == "pm")
	{
		hours += 12;
	}
	cout << setfill('0') << setw(2) << hours 
		<< ":" 
		<< setfill('0') << setw(2) << minutes 
		<< ":" 
		<< setfill('0') << setw(2) << seconds 
		<< " 24-Hour Clock" << endl;
}
//Function to parse input string in format XX:XX:XX
void parseInput(string input)
{
	string temp;
	string delimiter = ":";
	//Find value of hours and write to int
	int length = input.length();
	hours = stoi(input.substr(0, input.find(delimiter)));
	//Find value of minutes and write to int
	temp = input.substr(input.find(delimiter)+1, length);
	length = temp.length();
	minutes = stoi(temp.substr(0, temp.find(delimiter)));
	//Find value of seconds and write to int
	temp = temp.substr(temp.find(delimiter) + 1, length);
	length = temp.length();
	seconds = stoi(temp.substr(0, temp.find(delimiter)));
}

int main()
{
	bool done = false;
	do {
		try
		{
			cout << "Please input the 12-hr time you want to convert into 24-hr time." << endl;
			cout << "XX:XX:XX   hours, minutes, seconds" << endl;
			cin >> input;
			cout << "Specify AM or PM time" << endl;
			cin >> timeOfDay;
			cout << endl << "Converting time..." << endl;
			parseInput(input);
			convertTime(hours, minutes, seconds);
			done = true;
		}
		catch (invalid_argument ia)
		{
			cout << ia.what() << endl;
			cout << "Error: Bad input. Please input in XX:XX:XX format using #'s." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (invalidHr invalidHrObj)
		{
			cout << invalidHrObj.what() << endl;
			cout << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (invalidMin invalidMinObj)
		{
			cout << invalidMinObj.what() << endl;
			cout << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (invalidSec invalidSecObj)
		{
			cout << invalidSecObj.what() << endl;
			cout << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (invalidTimeOfDay invalidTimeOfDayObj)
		{
			cout << invalidTimeOfDayObj.what() << endl;
			cout << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!done);
	system("PAUSE");
}



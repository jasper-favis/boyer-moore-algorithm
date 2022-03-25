/*
 * main.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Jasper Favis
 */

#include "boyerMoore.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstring>
#include <math.h>
#include <cstdio>
#include <ctime>

using namespace std;


int main()
{
	string inputFileName;
	fstream inputFile;
	int option;

	vector<int> locations;
	string pattern = "";
	string text = "";
	string temp;
	int plength;
	int tlength;
	double time;
	bool value = false;
	unsigned int j = 0;

	boyerMoore BM;

	while(1)
	{
		text = "";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << setw(30) << "Boyer-Moore Test" << endl;
		cout << setw(61) << "Press 1 to start. Press any other key to exit. ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		cin >> option;
		cin.ignore();
		if (option != 1)
			exit(1);
		cout << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << setw(48) << "Please enter file name to search: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		getline(cin, inputFileName);
		cout << endl;

		inputFile.open(inputFileName);
		if (inputFile.fail())
		{
			cout << setw(30) << "Input file failed to open." << endl;
			exit(1);
		}

		while(!inputFile.eof())
		{
			getline(inputFile, temp);
			text = text + temp;
		}
		tlength = text.length();

		for (int i = 0; i < tlength; i++)
		{
			if (i % 60 == 0)
			{
				cout << endl;
				cout << setw(20);
			}
			cout << text[i];
		}
		cout << endl;
		cout << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << setw(56) << "Please enter the string you want to find: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		getline(cin, pattern);
		plength = pattern.length();

		time = BM.search(pattern, text, locations);

		cout << endl;

		j = 0;
		for (int i = 0; i < tlength; i++)
		{
			if (i == locations[j] && j < locations.size())
			{
				j++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				value = true;
			}
			if ((value == true) && i == (locations[j - 1] + plength))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				value = false;
			}
			if (i % 60 == 0)
			{
				cout << endl;
				cout << setw(20);
			}
			cout << text[i];
		}
		cout << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(36) << "Number of occurences: " << locations.size() << endl;
		cout << setw(30) << "Execution time: " << time << " ms" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);

		cout << endl;
		cout << endl;

		if (!locations.empty())
			locations.clear();

		inputFile.close();
	}
}




//int main()
//{
//	LARGE_INTEGER frequency;        // ticks per second
//	LARGE_INTEGER t1, t2;           // ticks
//	double elapsedTime;
//
//	// get ticks per second
//	QueryPerformanceFrequency(&frequency);
//
//	// start timer
//	QueryPerformanceCounter(&t1);
//
//	// do something
//	for (unsigned int i = 0; i < 10000; i++)
//	{
//		//do nothing
//	}
//
//	// stop timer
//	QueryPerformanceCounter(&t2);
//
//	// compute and print the elapsed time in millisec
//	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
//
//	cout << "duration: " << elapsedTime << endl;
//
//	return 0;
//}







//	plength = pattern.length();
//	tlength = text.length();
//
//	BM.search(pattern, text, locations);
//
//
//	cout << endl;
//	cout << endl;
//	for (int i = 0; i < tlength; i++)
//	{
//		if (i == locations[j] && j < locations.size())
//		{
//			j++;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//			value = true;
//		}
//		if ((value == true) && i == (locations[j - 1] + plength))
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
//			value = false;
//		}
//		cout << text[i];
//	}
//	cout << endl;
//	cout << endl;
//
//
//	return 0;
//}

////////////////////////////////////////////////////
//                                                //
//	H O W   T O   R U N   C O D E   O N   C M D   //
//                                                //
////////////////////////////////////////////////////
// g++ main.cpp boyerMoore.cpp -o main  <--- compile
// main                                 <--- run




//int main()
//{
//    clock_t duration;
//
//    duration = clock();
//
//    /* Your algorithm here */
//    for (unsigned int i = 0; i < 100000; i++)
//    {
//    	// do nothing
//    }
//
//    duration = clock() - duration;
//
//    cout.precision(8);
//    cout << "duration: " << (float)duration/CLOCKS_PER_SEC << endl;
//
//
//    return 0;
//}








//string pattern = "racaarac";
//plength = pattern.length();
//string text = "i saw the racaarac doing its racaarac thing and it was so racaaracaarac the stupid thing"
//		" racaarac doing its racaarac thing and it was so racaaracaarac the stupid thing"
//		" racaarac doing its racaarac thing and it was so racaaracaarac the stupid thing";
//tlength = text.length();
//
//boyerMoore BM;
//BM.search(pattern, text, locations);
//
//
//cout << endl;
//cout << endl;
//for (int i = 0; i < tlength; i++)
//{
//	if (i == locations[j] && j < locations.size())
//	{
//		j++;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//		value = true;
//	}
//	if ((value == true) && i == (locations[j - 1] + plength))
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
//		value = false;
//	}
//	cout << text[i];
//}
//cout << endl;
//cout << endl;





//	cout << endl;
//	for (unsigned int i = 0; i < locations.size(); i++)
//	{
//		cout << "Location " << locations[i] << endl;
//	}

//Test
//system("color A1");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//	cout << "Hello World!" << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
//	cout << "Hello World!" << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//	cout << "Hello World!" << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
//	cout << "Hello World!" << endl;




//double PCFreq = 0.0;
//__int64 CounterStart = 0;
//
//void StartCounter()
//{
//    LARGE_INTEGER li;
//    if(!QueryPerformanceFrequency(&li))
//    cout << "QueryPerformanceFrequency failed!\n";
//
//    PCFreq = double(li.QuadPart)/1000.0;
//
//    QueryPerformanceCounter(&li);
//    CounterStart = li.QuadPart;
//}
//double GetCounter()
//{
//    LARGE_INTEGER li;
//    QueryPerformanceCounter(&li);
//    return double(li.QuadPart-CounterStart)/PCFreq;
//}
//
//int main()
//{
//    StartCounter();
//    Sleep(1000);
//    cout << GetCounter() <<"\n";
//    return 0;
//}

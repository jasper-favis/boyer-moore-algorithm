/*
 * boyerMoore.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Jasper Favis
 */

#include "boyerMoore.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>

using namespace std;

LARGE_INTEGER frequency;        // ticks per second
LARGE_INTEGER t1, t2;           // ticks
double elapsedTime;

boyerMoore::boyerMoore()
{
	// do nothing
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                              //
//                                     S E A R C H                                              //
//                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////
double boyerMoore::search(string pat, string txt, vector<int>& locations)
{
		int s = 0;
		int j;
		int m = pat.length();
		int n = txt.length();
		int occurence[256];
		int borderPosition[m+1];
		int shift[m+1];

		for (int i = 0; i < m + 1; i++)
			shift[i] = 0;

		badCharPreprocess(pat, occurence, m);
		goodSuffPreprocess(pat, borderPosition, shift, m);

		// get ticks per second
		QueryPerformanceFrequency(&frequency);
		// start timer
		QueryPerformanceCounter(&t1);

		///////////////////////////////////////////
		//  |  |                           |  |  //
		//  |  |  D O  S O M E T H I N G   |  |  //
		//  v  v                           v  v  //
		///////////////////////////////////////////

		while (s <= n - m)
		{
			j = m - 1;

			// When characters match between pattern and text
			// compare next pair of characters
			while (j >= 0 && pat[j] == txt[s+j])
				j--;

			if (j < 0)
			{
				// When j = -1, pattern successfully matches with
				// substring in text
				/////////////////////////////////////////////////
				//          Decide what to do here             //
				/////////////////////////////////////////////////
				//cout << "Pattern match at " << s << endl;
				locations.push_back(s);

				// We don't necessarily shift by the length of the pattern
				// because the next successful pattern match may overlap
				// with the current pattern
				// Example:
				// 		txt: abbababbabab
				//      pat: abbabab         match!
				//      pat:      abbabab    match!
				// Shift to the position of the widest border of the pattern
				s += shift[0];
			}
			else
				s += max(shift[j+1], j - occurence[(int)txt[s+j]]);
		}

		///////////////////////////////////////////
		//  ^  ^                           ^  ^  //
		//  |  |  D O  S O M E T H I N G   |  |  //
		//  |  |                           |  |  //
		///////////////////////////////////////////

		// stop timer
		QueryPerformanceCounter(&t2);

	//	// compute and print the elapsed time in millisec
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
		return elapsedTime;

		// compute and print the elapsed time in microsec
	//	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1.0 / frequency.QuadPart;
	//	return elapsedTime;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                              //
//                      B A D   C H A R A C T E R   T A B L E                                   //
//                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////
void boyerMoore::badCharPreprocess(string pat, int occ[], int m)
{
	/////////////////////////////////
	//  Bad Character Lookup Table //
	/////////////////////////////////

	// First initialize all entries to -1
	// (256 entries for 256 ASCII characters)
	for (int i = 0; i < 256; i++)
	{
		occ[i] = -1;
	}

	// Step through the pattern and store the
	// last occurence of each character
	// Example:
	// 		i:  0124567
	//    pat:  pattern
	//    The last occurence of 't' is at i = 4
	for (int i = 0; i < m; i++)
	{
		occ[(int)pat[i]] = i;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                              //
//                            G O O D   S U F F I X   T A B L E                                 //
//                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////
void boyerMoore::goodSuffPreprocess(string pat, int bpos[], int shift[], int m)
{
	//////////////////////////////////////////////////////////////
	// Case 1: Matching suffix exists somewhere in the pattern. //
	//////////////////////////////////////////////////////////////

	int i = m;
	int j = m + 1;

	bpos[i] = j;
	while (i > 0)
	{
		while (j <= m && pat[i-1] != pat[j-1])
		{
			if (shift[j] == 0)
				shift[j] = j - i;
			j = bpos[j];
		}
		i--;
		j--;
		bpos[i] = j;
	}

	//////////////////////////////////////////////////////////////
	// Case 2: Matching suffix does not exist somewhere in the  //
	// pattern but substring of suffix exists as prefix of the  //
	// pattern.                                                 //
	//////////////////////////////////////////////////////////////

	// The position of the widest border in the whole pattern
	// is given by the border position at index 0
	j = bpos[0];

	for (i = 0; i <= m; i++)
	{
		if (shift[i] == 0)
			shift[i] = j;

		// suffix becomes shorter than
		if (i == j)
			j = bpos[i];
	}

}

/*
 * boyerMoore.h
 *
 *  Created on: Nov 16, 2018
 *      Author: Jasper Favis
 */

#ifndef BOYERMOORE_H_
#define BOYERMOORE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class boyerMoore
{
public:
	boyerMoore();
	//void search(string pat, string txt);
	double search(string pat, string txt, vector<int>& locations);
	void badCharPreprocess(string pat, int occ[], int m);
	void goodSuffPreprocess(string pat, int bpos[], int shift[], int m);
};

#endif /* BOYERMOORE_H_ */

/*
* =========================================================================================
* Name        : eventLib.cpp
* Author      : Duc Dung Nguyen, Nguyen Hoang Minh
* Email       : nddung@hcmut.edu.vn
* Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
* Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
*               This library contains functions used for event management
* =========================================================================================
*/

#include "eventLib.h"

/// NOTE: each event will be separated by spaces, or endline character
void loadEvents(char* fName, L1List<ninjaEvent_t> &eList) {
	//TODO    
	fstream eventFile;
	eventFile.open(fName, ios::in);
	if (!eventFile) {
		DSAException *ex = new DSAException(-3, "can not open File !");
		throw ex;
	}
	string str;
	while (!eventFile.eof()) {
		getline(eventFile, str);
		if (str.empty())
			continue;
		stringstream ss(str);
		char *a = new char[EVENT_CODE_SIZE];
		while (ss >> a) {
			if (a[0] == ';') {
				break;
			}
			ninjaEvent ne(a);
			eList.push_back(ne);
			a = new char[EVENT_CODE_SIZE];
		}
	}
	eventFile.close();
}

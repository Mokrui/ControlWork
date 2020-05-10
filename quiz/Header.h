#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
struct Quest {
	string quest;
	string answears[3];

	int rightA;
};
struct Quiz {
	string title;
	Quest QA[5];
};

void init();
void save();

void addQ();
void takeQ();
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

#include "Settings.h"

using namespace std;

const int DEFAULT_COLOR = 10;
const int FIRST_REPETITION_COLOR = 142;
const int SECOND_REPETITION_COLOR = 139;

class Word
{
	Settings WordSettings;
	string Sequence;	
public:
	Word(Settings InitialSettings=Settings(), string InitialSequence = "");

	void ShowSequence() const;
	void ShowRepetition() const;
	void ShowInfo() const;
	bool Add(char letter);//true when success
	bool Move(int Player);//true when success
	bool Check();//true when repetition
	int Game();//returns index of winner
};
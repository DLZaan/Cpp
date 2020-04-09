#pragma once
#include <iostream>


using namespace std;

const int MIN_LENGTH = 6;
const int MAX_LENGTH = 1000;

const int MIN_ALPHABET = 2;
const int MAX_ALPHABET = 26;

const int FIRST_LETTER = 'A';

class Settings
{
	int length;
	int alphabet;
	int Player[2];

public:
	Settings(int length = 20, int alphabet = 3, int Player1=0,	int Player2=0);

	void SetLength();
	void SetAlphabet();
	void SetVersion();
	void ShowLength() const;
	void ShowAlphabet() const;
	void ShowVersion() const;

	const int& ReturnLength() const;//gives maximum size of sequence
	const int& ReturnAlphabet() const;//gives length of alphabet
	const int& ReturnPlayer(int i) const;//gives if human or computer

	friend ostream& operator<<(ostream& out, const Settings& Sett);
};
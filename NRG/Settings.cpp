#include "Settings.h"

Settings::Settings(int length, int alphabet, int Player1, int Player2) :length(length), alphabet(alphabet)
{
	Player[0] = Player1;
	Player[1] = Player2;
}

void Settings::SetLength()
{
	int change;
	ShowLength();
	cout <<"\tEnter new maximum length (from <"<< MIN_LENGTH<<","<<MAX_LENGTH <<">): ";
	cout << "\t";
	cin >> change;
	if (change<MIN_LENGTH || change>MAX_LENGTH)
		cout <<"\tERROR: Maximum length changed unsuccessfully!" << endl;
	else		
	{
		length = change;
		cout <<"\tMaximum length changed successfully!" << endl;
	}
	cout << endl;
}

void Settings::SetAlphabet()
{
	int change;
	ShowAlphabet();
	cout <<"\tEnter new size of alphabet (from <" << MIN_ALPHABET << "," << MAX_ALPHABET << ">): ";
	cout << "\t";
	cin >> change;
	if (change<MIN_ALPHABET || change>MAX_ALPHABET)
		cout <<"\tERROR: Size of alphabet changed unsuccessfully!" << endl;
	else
	{
		alphabet = change;
		cout <<"\tSize of alphabet changed successfully!" << endl;
	}
	cout << endl;
}

void Settings::SetVersion()
{
	int change;
	ShowVersion();
	cout <<"\tEnter new version settings: "<<endl;
	cout <<"\t0 - HUMAN" << endl;
	cout <<"\t1 - COMPUTER" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout <<"\tPlayer" << i+1 << ": ";
		cout << "\t";
		cin >> change;
		if ((change != 0) && (change != 1))
		{
			cout <<"\tERROR: Player" << i +1<< " changed unsuccessfully!"<<endl;
			continue;
		}
		cout << "\t";
		Player[i] = change;
		cout <<"\tPlayer" << i+1 << " changed successfully!"<<endl;
	}
	cout << endl;
}

void Settings::ShowLength() const
{
	cout <<"\tCurrent maximum length: " << length << endl;
}

void Settings::ShowAlphabet() const
{
	cout <<"\tCurrent alphabet size: " << alphabet << endl;
	cout <<"\tCurrent alphabet: ";
	for (int i = 0; i < alphabet; i++)
		cout << (char)(FIRST_LETTER + i) << " ";
	cout << endl;
}

void Settings::ShowVersion() const
{
	cout <<"\tCurrent version of game: "<<endl;
	for (int i = 0; i < 2; i++)
	{
		cout <<"\t\tPlayer" << i +1<< ": ";
		if (Player[i])
			cout <<"\tComputer" << endl;
		else
			cout <<"\tHuman" << endl;
	}
}

const int & Settings::ReturnLength() const
{
	return length;
}

const int & Settings::ReturnAlphabet() const
{
	return alphabet;
}

const int & Settings::ReturnPlayer(int i) const
{
	return Player[i];
}

ostream & operator<<(ostream & out, const Settings& Sett)
{
	out <<"\tCurrent settings:" << endl;
	Sett.ShowLength();
	Sett.ShowAlphabet();
	Sett.ShowVersion();
	return out;
}
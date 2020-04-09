#include "Word.h"

Word::Word(Settings InitialSettings, string InitialSequence): WordSettings(InitialSettings), Sequence(InitialSequence)
{}

void Word::ShowSequence() const
{
	cout <<"\tCurrent sequence: " << Sequence<<endl;
}

void Word::ShowRepetition() const
{
	int i = 2;
	int length=Sequence.length();
	cout <<"\tCurrent sequence: ";
	for (; 2 * i <= length; i++)
		if (!(Sequence.compare(length - 2 * i, i, Sequence, length - i, i)))
			break;
	cout << Sequence.substr(0, length - 2 * i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FIRST_REPETITION_COLOR);
	cout << Sequence.substr(length - 2 * i, i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SECOND_REPETITION_COLOR);
	cout << Sequence.substr(length -  i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);
	//cout << endl;
	//cout << "Repetition length (doubled): " << 2*i << endl;
	//cout << "Sequence length: " << length << endl;
	cout << endl;
}

void Word::ShowInfo() const
{
	WordSettings.ShowAlphabet();
	cout <<"\tRemaining number of moves: "<< WordSettings.ReturnLength() - Sequence.length()<<endl;
	cout <<"\tNext move: Player " << Sequence.length() % 2 +1<<endl;
	ShowSequence();
}

bool Word::Add(char letter)
{
	if (isalpha(letter))
	{
		if (isupper(FIRST_LETTER))
			letter = toupper(letter);
		else
			letter = tolower(letter);
			
		if ((letter>= FIRST_LETTER)&&(letter<FIRST_LETTER + WordSettings.ReturnAlphabet()))
		{
			Sequence += letter;
			return true;
		}
	}
	return false;
}

bool Word::Move(int Player)
{
	if (Player) //Computer
	{
		if (Sequence.length() % 2)// Player 2
		{
			Sequence += FIRST_LETTER+ WordSettings.ReturnAlphabet()-1;
			for (int i = 1; i < WordSettings.ReturnAlphabet(); i++)
				if (Check())
					break;
				else
					--Sequence.back();
			return true;
		}
		else//Player 1
		{

			for (int i = 0; i < WordSettings.ReturnAlphabet(); i++)//lvl 0
				if (Sequence.find(FIRST_LETTER + i) == string::npos)
				{
					Sequence += FIRST_LETTER + i;
					return true;
				}

			Sequence += FIRST_LETTER-1; //lvl 1 + 2
			for (int j = 0; j < WordSettings.ReturnAlphabet(); j++)
			{
				++Sequence.back();
				if (!Check())//lvl 1
				{//lvl 2
					Sequence += FIRST_LETTER;
					int i = 0;
					for (; i < WordSettings.ReturnAlphabet(); i++)
					{
						if (Check())
						{
							Sequence.pop_back();
							i = 0;
							break;
						}
						++Sequence.back();
					}
					if (i)
					{
						Sequence.pop_back();
						return true;
					}
				}
			}
			return true;
		}
	}
	//Human
	ShowInfo();
	cout <<"\tPlayer" << Sequence.length() % 2 +1<< ", please enter a letter: ";
	cout << "\t";
	string letter;
	cin >> letter;
	system("cls");
	cout << endl;
	cout << endl;
	if (Add(letter[0]))
	{
		cout <<"\tLetter added successfully!" << endl<<endl;
		return true;
	}
	cout <<"\tERROR: Wrong letter!" << endl<<endl;
	return false;
}

bool Word::Check()
{
	for (int i = 2; 2*i <= (int) Sequence.length(); i++)
		if (!(Sequence.compare(Sequence.length()-2*i,i,Sequence,Sequence.length()-i,i)))
			return true;
	return false;
}

int Word::Game()
{
	cout <<"\tTHE GAME HAS STARTED" << endl<<endl;
	while ((int) Sequence.length() < WordSettings.ReturnLength())
	{
		while (!(Move(WordSettings.ReturnPlayer(Sequence.length()%2))));
			if (Check())
				return 2;
	}
	return 1;
}

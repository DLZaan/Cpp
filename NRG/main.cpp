#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#include "Settings.h"
#include "Word.h"

using namespace std;


void Settin(Settings& CurrentSettings);
void Menu(Settings& CurrentSettings);
void Game(const Settings& CurrentSettings);

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);
	srand(time(NULL));
	Settings CurrentSettings;
	cout << endl<<endl;
	Menu(CurrentSettings);
	return 0;
}

void Settin(Settings& CurrentSettings)
{
	string controler;

	do
	{
		cout << CurrentSettings<<endl;

	cout<<"\tSETTINGS:"<<endl;
	cout<<"\t1 - SET LENGTH"<<endl;
	cout<<"\t2 - SET ALPHABET"<<endl;
	cout<<"\t3 - SET VERSION"<<endl;
	cout<<"\t4 - SET ALL DEFAULT"<<endl;
	cout<<"\t0 - RETURN"<<endl;
	cout<<"\tPass the index of option:"<<endl;
	cout << "\t";
	cin >> controler;

	system("cls");
	cout << endl;
	cout << endl;


		switch ((int)(controler[0] - '0'))
		{
		case 1:
			CurrentSettings.SetLength();				
			break;
		case 2:
			CurrentSettings.SetAlphabet();
			break;
		case 3:
			CurrentSettings.SetVersion();
			break;
		case 4:
			CurrentSettings = Settings();
			cout <<"\tSettings changed to default." << endl;
			break;
		case 0:
			break;
		default:
			cout <<"\tWrong option!" << endl <<"\tPlease enter the proper one:" << endl<<endl;
			Settin(CurrentSettings);
			break;
		}
	} while ((int) (controler[0] - '0'));
	
}

void Menu(Settings& CurrentSettings)
{
	string controler;

	do
	{

	cout<<"\tMAIN MENU:"<<endl;
	cout<<"\t1 - START NEW GAME"<<endl;
	cout<<"\t2 - SETTINGS"<<endl;
	cout<<"\t0 - EXIT"<<endl;
	cout<<"\tPass the index of option:"<<endl;
	cout << "\t";
	cin >> controler;

	system("cls");
	cout << endl;
	cout << endl;

		switch ((int) (controler[0]-'0'))
		{
		case 1:
			Game(CurrentSettings);
			break;
		case 2:
			Settin(CurrentSettings);
			break;
		case 0:
			break;
		default:
			cout <<"\tWrong option!" << endl <<"\tPlease enter the proper one:" << endl<<endl;
			Menu(CurrentSettings);
			break;
		}
	} while ((int)(controler[0] - '0'));
}
void Game(const Settings& CurrentSettings)
{
	int winner;
	Word NewGame(CurrentSettings);
	winner = NewGame.Game();
	if (winner == 1)
		NewGame.ShowSequence();
	else
		NewGame.ShowRepetition();
	cout <<"\tTHE WINNER IS: PLAYER" << winner << endl<<endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>



using namespace std;



/*bool IfHasLetter(const vector <char> &word, const char &l);*/



void AddChar(vector <char>& guessed_chars, const vector <char>& word, const char& l);



/*void DeleteChar(vector <char> &word, const char &l);*/


bool IfWin(vector <char>& guessed_chars);


int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int health = 10;

	bool gameover = false;



	vector<char> word;

	string entered_word;

	vector <char> guessed_chars;



	cout << "Введите слово: " << endl;

	cin >> entered_word;

	system("cls");

	for (int i = 0; i < entered_word.size(); i++)

	{

		word.push_back(entered_word[i]);

		guessed_chars.push_back('_');

	}

	cout << "Угадайте слово" << endl;

	cout << "У вас есть " << health << " попыток.\n";

	while (!gameover)

	{

		for (int i = 0; i < guessed_chars.size(); i++)

			cout << guessed_chars[i];



		cout << "\nНазовите букву:" << endl;

		char l;

		cin >> l;

		if (count(word.begin(), word.end(), l))

		{

			cout << "Откройте букву " << '"' << l << '"' << '!' << endl;

			/*DeleteChar(word, l);*/

			AddChar(guessed_chars, word, l);



		}
		else

		{

			cout << "Буквы " << l << " нет в слове!\n";



			health--;

			cout << "У вас осталось " << health << " попыток.\n";
		}

		if (health < 1)

		{

			cout << "Игра окончена. Вы проиграли!" << endl;

			gameover = true;

		}

		if (IfWin(guessed_chars))
		{

			cout << "Вы угадали слово " << entered_word << '!' << endl;

			gameover = true;

		}

	}
	system("pause");
}


bool IfWin(vector <char>& guessed_chars)
{
	for (char c : guessed_chars)

	{

		if (c == '_')

			return false;

	}

	return true;
}

void AddChar(vector <char>& guessed_chars, const vector <char>& word, const char& l)

{

	for (int i = 0; i < word.size(); i++)

	{

		if (word[i] == l)

			guessed_chars[i] = l;



	}

}



/*void DeleteChar(vector <char> &word, const char &l)

{

	for (int i = 0; i <= word.size(); i++)

	{

		if (word[i] == l)

		{

			word.erase(i);

		}

	}

}*/
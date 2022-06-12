#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string player_name_1 = "player 1 Name:";
string player_name_2 = "player 2 Name:";
int limit_length = 5;
int limit_guess = 7;

bool check_input(string a)
{
	if (a.length() < limit_length || a.length() > limit_length)
	{
		cout << player_name_1 << ", You must follow the rules of the game.\nPlease enter a word with length 5 character:" << endl;
		return false;
	}
	return true;
}

string delete_similar(string w, string a, string c)
{
	for (int i = 0; i < w.length(); i++)
	{
		if (w[i] == a[i])
		{
			c[i] = '+';
			a[i] = '+';
			w[i] = '+';
		}
	}
	return c;
}

string Existence(string w, string a, string c)
{
	for (int i = 0; i < w.length(); i++)
	{
		if (a[i] != '+' && w.find(a[i]) >= 0 && w.find(a[i]) <= w.length())
		{
			c[i] = '#';
			a[i] = '#';
			w[i] = '#';
		}
	}
	return c;
}

bool check_answer(string w, string a)
{
	if (a.length() < limit_length || a.length() > limit_length)
	{
		cout << player_name_2 << ", You must follow the rules of the game.\nPlease try Shanston to guess the word:" << endl;
		return false;
	}
	if (a == w)
		return true;

	string a_check = "-----";
	a_check = delete_similar(w, a, a_check);
	a_check = delete_similar(w, a, a_check);

	cout << a_check << endl
		 << player_name_2 << "\nPlease try Shanston to guess the word again:" << endl;
	return false;
}

int main()
{
	time_t start, end;
	int scour = 100;
	int index_answer = 0;
	string input, answer;
	bool find_answer = false;

	cout << player_name_1 << endl;
	cin >> player_name_1;

	cout << player_name_2 << endl;
	cin >> player_name_2;

	do
	{
		cout << player_name_1 << ", Please enter a word with length 5 character:" << endl;
		cin >> input;
	} while (check_input(input) == false);

	system("CLS");

	cout << player_name_2 << ", Please try Shanston to guess the word:" << endl;

	time(&start);

	do
	{
		if (index_answer > limit_guess)
		{
			cout << player_name_2 << ", You lost the game." << endl;
			break;
		}
		cin >> answer;
		index_answer++;
		system("CLS");
		find_answer = check_answer(input, answer);
		if (find_answer == false)
		{
			scour -= 20;
		}
	} while (find_answer == false);

	time(&end);

	double time_taken = double(end - start);
	system("CLS");
	if (find_answer == true)
	{
		cout << "Time to reach the answer is: " << time_taken << " sec " << endl;
		cout << "You got the answer after guessing " << index_answer - 1 << " times" << endl;
		cout << "Your score is " << scour << "/100" << endl;
	}
	cout << "END GAME" << endl;

	return 0;
}
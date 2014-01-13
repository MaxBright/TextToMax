//Text To Max
//Copyright 2014 Max Bright. All Rights Reserved.

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void playLetter(char);
void playString(string);

void playLetter(char input)
{
	//Convert char input to LPCSTR
	//There needs to be a better way to do this
	LPCSTR soundName;
	string inputString;
	inputString = input;
	soundName = inputString.c_str();

	//If upper case, convert input to lower case and run the function again
	if (65 <= input && input <= 90)
	{
		input += 32;
		playLetter(input);
	}
	else if (input == ' ' || input == ',' || input == '.')
	{
		Sleep(75);
	}
	else if (48 <= input && input <= 57)
	{
		switch(input)
		{
		case '0':
			playString("zero");
			break;
		case '1':
			playString("one");
			break;
		case '2':
			playString("two");
			break;
		case '3':
			playString("three");
			break;
		case '4':
			playString("four");
			break;
		case '5':
			playString("five");
			break;
		case '6':
			playString("six");
			break;
		case '7':
			playString("seven");
			break;
		case '8':
			playString("eight");
			break;
		case '9':
			playString("nine");
			break;
		default:
			//'!' will play the error message
			playString("!");
		}
	}
	//If on a-z set
	else if (97 <= input && input <= 122)
	{
		PlaySound(soundName, GetModuleHandle(0), SND_RESOURCE);
	}
	else
	{
		PlaySound("error", GetModuleHandle(0), SND_RESOURCE);
	}
}

void playString(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		playLetter(input[i]);
	}
}

int main()
{
	cout << "Welcome to TextToMax, type in something and listen to your favorite voice actor reading it out to you!\n";
	string input = "None";
	while (true)
	{
		getline(cin, input);
		playString(input);
	}
}

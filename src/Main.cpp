//Text To Max
//October 13, 2013
//Copyright 2013 Max Bright. All Rights Reserved.

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void playLetter(char input)
{
	LPCSTR soundFile;
	string soundFileString;
	bool useSoundFile = true;

	soundFileString = "resource/ .wav";
	if (input == ' ')
	{
		Sleep(100);
		useSoundFile = false;
	}
	else if (97 <= input && input <= 122)
	{
		soundFileString[9] = input;
	}
	else
	{
		soundFileString = "resource/unrecognizedinput.wav";
	}

	if (useSoundFile)
	{
		soundFile = soundFileString.c_str();
		PlaySound(TEXT(soundFile), NULL, SND_FILENAME);
	}
}

int main()
{
	cout << "Welcome to TextToMax, type in something and listen to your favorite voice actor reading it out to you!\n";
	string input = "None";
	bool running = true;
	while (running)
	{
		getline(cin, input);
		if (input == "quit")
		{
			running = false;
		}
		else
		{
			for (int i = 0; i < input.length(); i++)
			{
				playLetter(input[i]);
			}
		}
	}
}
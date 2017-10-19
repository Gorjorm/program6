#include "stdafx.h"
#include <iostream>
#include <cctype>

using namespace std;

const int SIZE = 200;
const int SHIFT = 4;

void printMessage(char a[], int size);
void encodeMessage(char a[], int size);
void encodeCipher(char a[], int size);
void decodeMessage(char a[], int size);
int main()
{
	char message[SIZE], letter;
	int count = 0;

	cout << "Please enter a message (200 character limit): ";
	cin.get(letter);
	while (letter != '\n' && count < SIZE) {
		message[count] = letter;
		count++;
		cin.get(letter);
	}
	for (int i = 0; i < count; i++)
		message[i] = toupper(message[i]);
	cout << endl;

	printMessage(message, count);
	encodeMessage(message, count);
	encodeCipher(message, count);
	decodeMessage(message, count);
	
	return 0;
}
void printMessage(char a[], int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i];
	cout << endl;
}
void encodeMessage(char a[], int size)
{
	for (int i = 0; i < size; i++) {
		if (a[i] != ' ') {
			//if (a[i] < 87)
			if (a[i] < 'W')
				a[i] += SHIFT;
			else
				a[i] -= 22;
		}
	}
	printMessage(a, size);
}
void encodeCipher(char a[], int size)
{
	char railFence[SIZE];
	cout << "size is " << size << endl;
	int add = (size - 1) / 2;
	cout << "add is " << add << endl;

	railFence[0] = a[0];

	for (int i = 1; i < size; i++) {
		if (i % 2 == 0) //when i is even
			railFence[i / 2] = a[i];
		else if (i % 2 != 0) { //when i is odd
			railFence[i + add] = a[i];
			add--;
		}
	}
	printMessage(railFence, size);
}
void decodeMessage(char a[], int size)
{
	for (int i = 0; i < size; i++) {
		if (a[i] != ' ') {
			//if (a[i] > 68)
			if (a[i] > 'D')
				a[i] -= SHIFT;
			else
				a[i] += 22;
		}
	}
	printMessage(a, size);
}
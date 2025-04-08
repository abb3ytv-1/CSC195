#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	int secretNumber = rand() % 100 + 1;
	int guess;
	int attempts = 0;
	const int maxAttempts = 10;
	bool hasWon = false;

	cout << "Welcome to the Guessing Game!" << endl;
	cout << "I have selected a number between 1 and 100." << endl;
	cout << "You have " << maxAttempts << " attempts to guess it." << endl;

	while (attempts < maxAttempts)
	{
		cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << ": Enter your guess: ";
		cin >> guess;
		attempts++;

		if (guess == secretNumber) {
			hasWon = true;
			break;
		}
		else if (guess < secretNumber) {
			cout << "Too low! Try again." << endl;
		}
		else {
			cout << "Too high! Try again." << endl;
		}

		if (attempts == maxAttempts / 2) {
			if (secretNumber % 2 == 0) {
				cout << "Hint: The secret number is even." << endl;
			}
			else {
				cout << "Hint: The secret number is odd." << endl;
			}
		}

		cout << endl;
	}

	if (hasWon) {
		cout << "Congratulations! You've guessed the number " << secretNumber << "!" << endl;
		cout << " in " << attempts << " attempts." << endl;
	}
	else {
		cout << "Sorry, you've used all your attempts. The secret number was " << secretNumber << "." << endl;
	}

	return 0;
}

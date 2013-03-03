/* CSCI 1205: Homework #1
* Student ID: 2132936 */
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;
int main(int argc, char *argv[])
{
int secret_number, guess, count;
cout << "Let's play a guessing game!" << endl << endl;
cout << "I'll pick a number from 0 to 9, inclusive." << endl; 
cout << "You have up to 9 tries to guess it." << endl;
cout << "Good luck!" << endl << endl;
// rand() returns an integer between 0 and RAND_MAX 
// we use modulo, to reduce the scale to 0 .. 9 
srand ( time(NULL) );
secret_number = (rand()%10);
count = 0;


do {
	if ( count )
	cout << "Sorry, that's not it!" << endl;

	cout << "Enter your guess:  " << endl;
	cin >> guess;
} 
while (( guess != secret_number ) && ( ++count < 9 ));
// we need this b/c of the "short-circuit" boolean expression
count++;
// we want some space between the guessing and the final result
cout << endl;
if ( guess == secret_number)
  {
	cout << "You got it in " << count << " guesses" << endl;
	cout << "Good Work" << endl;
}
else {
	cout << "Sorry, you used up all yout guesses!" << endl;
	cout << "the secret number was: " << secret_number << endl;
	cout << "Better luck next time!" << endl;
}


return EXIT_SUCCESS;
}

//end of Homework #0

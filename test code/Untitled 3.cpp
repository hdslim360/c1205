#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	cout << "Enter an int betweem 1 and 5  ";
		int y = 5;
		do {
			cin>> y;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
		
		}while ((y!=1)||(y!=2)||(y!=3)||(y!=4)||(y!=5));
cout<< "done";
}
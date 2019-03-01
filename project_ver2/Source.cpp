//Students "Ekin Karadag" and "Seyma Aybala Pamuk"

#include<iostream>
#include<ctime>
#include<string>
#include "data.h"
#include <sstream>

using namespace std;

int func0(const int defaultValue = -1) {//to make sure that the input from the user is an integer.***********

	string input;
	cin >> input;//takes input as a string

	stringstream stream(input);

	int result = defaultValue;

	if (stream >> result)
		return result; //if the input can be converted into an integer, no problem.
	else
		return defaultValue;//otherwise, gives the default value to make sure the program runs smoothly.
}

void func1();
void func2();
void func3();
void func4();
void func5();
void func6();
void func7();
void upload(int x[]);
void func8(string *usernameInput);
void func9(char userinput);
void func9_1();


int main()
{
	int firstChoice;
	string usernameInput;
	do {
		cout << "1) Display number of files and sum of file sizes for each user" << endl;
		cout << "2) Display usernames of the users who have no files in the system" << endl;
		cout << "3) Display average file size for each user" << endl;
		cout << "4) Display password of a username entered by the user" << endl;
		cout << "5) Search user (get username as input and display password and size of each file of that user)" << endl;
		cout << "6) Display the minimum file size (0 (zero) means nothing which should be ignored)" << endl;
		cout << "7) Display the maximum file size (0 (zero) means nothing which should be ignored)" << endl;
		cout << "8) Upload a new file for a user" << endl;
		cout << "9) Get a character (a single char) from the user and display all usernames beginning with the entered character" << endl;
		cout << "0) Exit" << endl << endl;

		cout << "Enter the number of your choice :";

		firstChoice = func0();//gets user's entry **********


		switch (firstChoice) {
		case 1: func1(); break;
		case 2: func2(); break;
		case 3: func3(); break;
		case 4: func4(); break;
		case 5: func5(); break;
		case 6: func6(); break;
		case 7: func7(); break;
		case 8: cout << "Enter the username of the user you want to upload a new file to: " << endl; cin >> usernameInput; func8(&usernameInput); break;
		case 9: func9_1(); break;
		case 0: exit;
		default: cout << "Wrong entry. Enter your choice according to the information given in the menu." << endl; break;
		}
	} while (firstChoice != 0);


	return 0;
}


void func1() {
	int fileCounter = 0, fileSizes = 0;
	for (int Users = 0; Users < 82; Users++) {
		for (int numofFiles = 0; numofFiles < 5; numofFiles++) {
			fileSizes = fileSizes + file_sizes[Users][numofFiles]; //for Summation
			if (file_sizes[Users][numofFiles] == 0)
				continue;
			else
				fileCounter++;//number of files counter

		}
		cout << "Number of files for " << usernames[Users] << ": " << fileCounter << endl;
		cout << "Total used storage for " << usernames[Users] << ": " << fileSizes << "MB" << endl;
		fileSizes = 0; //reset for new users
		fileCounter = 0;
		cout << "\n";
	}
}
void func2() {
	int fileCounter = 0;
	for (int Users = 0; Users < 82; Users++) {
		for (int numofFiles = 0; numofFiles < 5; numofFiles++) {
			if (file_sizes[Users][numofFiles] == 0)
				continue;
			else
				fileCounter++;//number of files counter

		}
		if (fileCounter == 0) //If the counter has not increased during the inner loop
			cout << usernames[Users] << " has no file in the system" << "\n";

		fileCounter = 0; // reset counter for any cases

	}
	cout << endl;
}
void func3() {
	int fileSizes;
	double averageFile, fileCounter;
	for (int Users = 0; Users < 82; Users++) {
		fileSizes = 0; //reset for new users
		fileCounter = 0;
		for (int numofFiles = 0; numofFiles < 5; numofFiles++) {
			fileSizes = fileSizes + file_sizes[Users][numofFiles]; //for Summation
			if (file_sizes[Users][numofFiles] == 0)
				continue;
			else
				fileCounter++;//number of files counter
		}

		if (fileCounter != 0)// the remainder cannot be 0!
			averageFile = fileSizes / fileCounter;
		else
			averageFile = 0; //because he/she has no file in the system

		cout << "Average file size of " << usernames[Users] << ": " << (double)averageFile << endl << endl;
	}
}
void func4() {
	string usr;
	cout << " Enter the username: ";
	cin >> usr;
	for (int startingPoint = 0; startingPoint < 82; startingPoint++) {
		if (usernames[startingPoint] == usr)
			cout << "Password of " << usernames[startingPoint] << " is " << passwords[startingPoint] << endl << endl;
	}

}
void func5() {
	string usr;
	cout << " Enter the username: ";
	cin >> usr;
	for (int startingPoint = 0; startingPoint < 82; startingPoint++) {
		if (usernames[startingPoint] == usr) {
			cout << "Password of " << usernames[startingPoint] << " is " << passwords[startingPoint] << endl;
			cout << "File sizes of " << usernames[startingPoint] << " in MB: \t";
			for (int numofFiles = 0; numofFiles < 5; numofFiles++) {
				cout << file_sizes[startingPoint][numofFiles] << "\t";
			}
		}
	}
	cout << endl << endl;
}
void func6() {

	int minval = 1000;

	for (int i = 0; i < 82; i++) {
		for (int j = 0; j < 5; j++) {
			if (file_sizes[i][j] != 0) {
				if (file_sizes[i][j] < minval)//if the loops find a value that is less than our current minimum value
					minval = file_sizes[i][j];
			}
		}

	}

	cout << "The minimum file size in the data base is " << minval << endl << endl;
}
void func7() {

	int maxval = 0;

	for (int i = 0; i < 82; i++) {
		for (int j = 0; j < 5; j++) {
			if (file_sizes[i][j] != 0) {
				if (file_sizes[i][j] > maxval)//if the loops find a value that is greater than our current minimum value
					maxval = file_sizes[i][j];
			}
		}

	}

	cout << "The maximum file size in the data base is " << maxval << endl << endl;
}
void upload(int x[]) {

	int file, sizeavb = 0;

	for (int i = 0; i < 5; i++) {

		if (x[i] == 0) 
			sizeavb++;

	}

	if (sizeavb > 0) {

		cout << "Enter the size of the file you want to upload." << endl;
		file = func0(); //to make sure that the input from the user is an integer.***********

		if (file > 1000) 
			cout << "The file you want to upload is too big. It must be smaller than or equal to 1000 MB." << endl << endl;

		else if (0 < file && file < 1000) { // if the input is in a valid interval

			for (int j = 0; j < 5; j++) {

				if (x[j] == 0) {

					x[j] = file;
					cout << file << " MB sized file has been uploaded." << endl << endl;
					break;
				}

			}

		}

		else
			cout << "You have entered an invalid value." << endl << endl;


	}

	else
		cout << "The user doesn't have available space to upload a file to." << endl << endl;

}
void func8(string *usernameInput) { //used pointer to allocate less memory. It points to username that has been declared in main()

	int x = 0;

	for (int k = 0; k < 82; k++) {

		if (usernames[k] == *usernameInput) {

			upload(file_sizes[k]);
			x++;
			break;
		}

	}

	if (x == 0) { //if the program has not found the entered username in the for loop

		cout << "Please make sure you entered the username correctly." << endl << endl;

	}


}
void func9(char userinput) {

	int x = 0;

	for (int i = 0; i < 82; i++) {

		if (userinput == usernames[i][0] || userinput == (usernames[i][0] - 32) || userinput == (usernames[i][0] + 32)) { //if a letter has been entered (Does not matter if it is uppercase or lowercase

			cout << usernames[i] << endl;
			x++;

		}


	}
	cout << endl; //for aesthetic reasons to display the main menu
	if (x == 0)
		cout << "There is no username starting with that character." << endl << endl;



}
void func9_1() { //to make sure the input from the user is in the right interval

	char input;
	cout << "Enter the character: " << endl;
	cin >> input;

	if ('a' <= input && input <= 'z' || 'A' <= input && input <= 'Z')
		func9(input);

	else
		cout << "There is no username starting with that character." << endl << endl;

}
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	bool keepRunning = true;

	while (keepRunning) {
		int input = 0;
		cout << "\n1. List directory contents \n2. Print working directory \n3. Create a working directory \n4. Display a message \n5. Concatenate and display content of a file \n6. Exit \nPlease input a number 1-6: ";
		cin >> input;
		if (input == 1) {
			system("dir");          //list files in current directory
		}
		else if(input == 2){
			system("cd");           //Print working directory
		}
		else if (input == 3) {
			int mkdirResult = system("mkdir new_folder");			//create a new directory					
			if (mkdirResult != 0) {
				//handle error, print an error message or exit the program
				return 1;
			}
			
		}
		else if (input == 4) {
			string message;
			cout << "Enter a message to display: ";				//ask for message to display
			cin.ignore();
			getline(cin, message);								//save the message
			system(("echo " + message).c_str());				//use echo to display the message back
		}
		else if (input == 5) {
			string filename;
			string filename2;
			cout << "Enter the first filename: ";				//get the first file name
			cin.ignore();
			getline(cin, filename);

			cout << "Enter the second filename: ";				//get the second file name
			getline(cin, filename2);

			ofstream file1(filename);							//Create and open the first file name
			if (!file1.is_open()) {
				cout << "Error: Unable to create/open";
			}

			file1 << "Content of file 1\n";						//set the contents of the first file
			file1.close();

			ofstream file2(filename2);							//Create and open the second file name
			if (!file2.is_open()) {
				cout << "Error: Unable to create/open";
			}

			file2 << "Content of file 2\n";						//set the contents of the second file
			file2.close();

			string command = "type " + filename + "&& type " + filename2;		//use the type shell command to concatenate and display the the contents of the two files
			system(command.c_str());
		}
		else if (input == 6) {									//exit
			keepRunning = false;
		}
		else {													//repeat menu for an invalid input
			cout << "Invalid Input" << endl;					
		}
	}

	return 0;
}
#include <cstdlib>
#include <iostream>
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
			int returnCode = system("echo Hello, World!");			//Echo the given text
			if (returnCode == 0) {
				cout << "Command executed successfully." << endl;
			}
			else {
				cout << "Command execution failed or returned "
					"non-zero: "
					<< returnCode << endl;
			}
		}
		else if (input == 5) {
			const char* fileName = "testing.txt";  							//grabs the file name
			char command[100];									//sets the size of the file
			sprintf_s(command, "type %s", fileName);						//prints the text from the file using the type shell command

			int typeResult = system(command);							
			if (typeResult != 0) {
				// Handle error, print an error message or exit the program
				return 1;
			}
		}
		else if (input == 6) {
			keepRunning = false;
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}

	return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write data (overwrite)
void writeToFile(const string& filename) {
    ofstream outFile(filename);  // opens in overwrite mode
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    string data;
    cout << "Enter data to write (end input with a single line 'END'):\n";
    while (getline(cin, data)) {
        if (data == "END") break;
        outFile << data << endl;
    }

    outFile.close();
    cout << "Data written to file successfully.\n";
}

// Function to append data
void appendToFile(const string& filename) {
    ofstream outFile(filename, ios::app);  // opens in append mode
    if (!outFile) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }

    string data;
    cout << "Enter data to append (end input with a single line 'END'):\n";
    while (getline(cin, data)) {
        if (data == "END") break;
        outFile << data << endl;
    }

    outFile.close();
    cout << "Data appended to file successfully.\n";
}

// Function to read data
void readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    cout << "\nContents of the file:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

int main() {
    string filename = "data.txt";
    int choice;

    do {
        cout << "\n--- File Operation Menu ---\n";
        cout << "1. Write to file (overwrite)\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To discard newline left in input buffer

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

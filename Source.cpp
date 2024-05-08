#include <iostream>
#include <fstream>
#include <string>  // Include <string> for getline
#include <cctype>
#include <iomanip>
#include <map>

using namespace std;

// Function to keep console window open after displaying results
void pressEnterToContinue() {
    char c;
    cout << "Press Enter to continue...";
    cin.ignore(1024, '\n');
    do { cin.get(c); } while (c != '\n' && c != EOF);
}

int main() {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);  // Use getline from the <string> header to read the filename

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Map to store frequency of each letter
    map<char, int> letterCounts;
    int totalLetters = 0;

    // Read each character in the file
    char ch;
    while (file >> noskipws >> ch) {
        if (isalpha(ch)) {  // Check if character is alphabetic
            ch = tolower(ch);  // Convert to lowercase
            letterCounts[ch]++;
            totalLetters++;
        }
    }

    file.close();

    // Display results
    cout << "Total number of letters: " << totalLetters << endl;
    cout << "Frequency:" << endl;

    cout << fixed << setprecision(3);  // Set precision for percentage output

    for (char c = 'a'; c <= 'z'; ++c) {
        if (letterCounts[c] > 0) {
            double frequency = (static_cast<double>(letterCounts[c]) / totalLetters) * 100;
            cout << "'" << c << "': " << frequency << endl;
        }
        else {
            cout << "'" << c << "': 0.000" << endl;  // Display zero frequency for letters not present
        }
    }

    // Wait for user to press enter before exiting
    pressEnterToContinue();

    return 0;
}

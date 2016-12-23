#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Analysis.hpp"
#include "BoyerMoore.hpp"

using namespace std;

void plainTest();
void fileTest();
void runAnalysis();


int main() {
    
    string choice;
    cout << "Q5. Boyer Moore's Algorithm\n\nEnter:\n" <<
            "\"1\" to test simple input and match.\n" <<
            "\"2\" to read a file and match a pattern.\n" <<
            "\"3\" to generate report of running time.\n" <<
            "\n==> ";
    
    getline(cin, choice);
    cout << "\n";
    
    if (choice == "1") plainTest();
    if (choice == "2") fileTest();
    if (choice == "3") runAnalysis();
    
    return 0;
}


/** Function to generate a csv file for running time.
 *
 */
void runAnalysis() {
    
    int trials;
    cout << "Enter number of trials ==> ";
    cin >> trials;
    
    srand((int) time(NULL));
    ofstream file("Report.txt");
    
    static const string alphanum = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int length = (int) alphanum.length();
    
    if (file.is_open()) {
    
        file << "length of text, length of pattern, Boyer-Moore, Naive\n";
        
        for (int i = 0; i < trials; ++i) {
            
            int n = (rand() % 800) + 1, m = (rand() % 200) + 1;
            string text, pattern;
            
            for (int j = 0; j < n; ++j) text += alphanum[rand() % length];
            for (int j = 0; j < m; ++j) pattern += alphanum[rand() % length];
        
            Analysis a(text, pattern);
            file << n << "," << m << ","
            << a.boyerMooreTime().count() << "," << a.naiveTime().count() << endl;
        }
    }
    else {
        
        cout << "Unable to open file\n";
        return;
    }
    
    file.close();
}


/** Function to accept small inputs.
 *
 */
void plainTest() {
    
    string input, pattern;
    cout << "Enter text ==> ";
    getline(cin, input);
    
    cout << "Enter pattern ==> ";
    getline(cin, pattern);
    
    BoyerMoore test(input, pattern);
    test.printLocations();
    if (input.size() <= 60) test.simulate();
}


/** Function to read a text file.
 *
 */
void fileTest() {
    
    string input;
    ifstream file;
    
    cout << "Enter input file.\n";
    cout << "File Path ==> ";
    getline(cin, input);
    
    file.open(input);
    if (file.is_open()) {
        
        string text;
        while (getline(file, input)) text = text + input;
        
        for (int i = 0; i < text.size(); ++i)
            if ((int) text[i] < 32 || (int) text[i] >= 127)
                text[i] = ' ';
        
        cout << "Enter pattern ==> ";
        getline(cin, input);
        
        BoyerMoore test(text, input);
        test.printLocations();
        if (text.size() <= 60) test.simulate();
    }
    else {
        
        cout << "   Error: unable to open file.\n\n";
        return;
    }
    
    file.close();
}

#include <iostream>
#include <fstream>
#include <string>
#include "BoyerMoore.hpp"

using namespace std;

void plainTest();
void fileTest();


int main() {
    
    string choice;
    cout << "Q5. Boyer Moore's Algorithm\n\nEnter:\n" <<
            "\"1\" to test simple input and match.\n" <<
            "\"2\" to read a file and match a pattern.\n" <<
            "\n==> ";
    
    getline(cin, choice);
    cout << "\n";
    
    if (choice == "1") plainTest();
    if (choice == "2") fileTest();
    
    return 0;
}


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

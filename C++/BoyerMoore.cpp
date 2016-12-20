#include "BoyerMoore.hpp"

/** Constructor.
 *
 * Input: input, the input string.
 *        pattern, the pattern to be found.
 *
 */
BoyerMoore::BoyerMoore(const string &input, const string &pattern) {
    
    this->matchSize = 10;
    this->size = 0;
    this->matchLocations = new int[matchSize];
    this->text = input;
    this->pattern = pattern;
    this->table = new MatchTable(pattern);
    
    this->run();
}


/** Destructor to free memory.
 *
 */
BoyerMoore::~BoyerMoore() {
    
    delete this->matchLocations;
    this->matchLocations = nullptr;
    
    delete this->table;
    this->table = nullptr;
}


/** Function to insert an integer to matchLocations and will resize matchLocations if needed to.
 *
 * Input: index, an integer
 *
 */
void BoyerMoore::push_back(const int &index) {
    
    if (matchSize == 0) ++matchSize;
    
    if (++size > matchSize) {
        
        // resize
        int* temp = matchLocations;
        
        matchSize *= 2;
        matchLocations = new int[matchSize];
        
        for (int i = 0; i < size; ++i) {
            
            matchLocations[i] = temp[i];
        }
        
        delete temp;
        temp = nullptr;
    }
    
    matchLocations[size-1] = index;
}


/** Function to print the first index locations where the pattern matches.
 *
 */
void BoyerMoore::printLocations() const {
    
    bool none = true;
    cout << "Matched at locations: ";
    for (int i = 0; i < size; ++i) {
        
        none = false;
        cout << matchLocations[i] << ", ";
    }
    if (none) cout << " NULL";
    cout << endl;
}


/** Function to run Boyer Moore's String Search Algorithm.
 *
 */
void BoyerMoore::run() {
    
    for (int i = (int) pattern.size() - 1; i < (int) text.size(); ) {
        
        int t = (int) pattern.size() - 1;
        for (int j = i; j > i - (int) pattern.size(); --j, --t) {
            
            if (text[j] != pattern[t]) break;
        }
        
        if (t == -1) {
            
            push_back(i - (int) pattern.size() + 1);
            ++i;
        }
        else i += table->skip(text[i]);
    }
}

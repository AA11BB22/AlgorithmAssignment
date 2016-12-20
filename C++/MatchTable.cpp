#include "MatchTable.hpp"

/** Constructor.
 *
 * Input: pattern, the string to be matched.
 *
 */
MatchTable::MatchTable(const string &pattern) {
    
    fill_n(this->table, ascii, pattern.size());
    this->init(pattern);
}


/** Empty Destructor.
 *
 */
MatchTable::~MatchTable() {
    
}


/** Function to get the skip value.
 *
 * Input: character, the character for finding its skip value.
 * Output: an integer which is the skip value for the character.
 *
 */
int MatchTable::skip(char character) const {
    
    int key = (int) character - non;
    if (key < 0 || key >= ascii) throw new out_of_range("Not a printable ASCII character");
    
    return this->table[key];
}


/** Function for initializing the table.
 *
 * Input: pattern, the string to be matched.
 *
 */
void MatchTable::init(const string &pattern) {
    
    for (int i = 0; i < (int) pattern.size() - 1; ++i) {
        
        int key = (int) pattern[i] - non;
        if (key < 0 || key >= ascii) throw new out_of_range("Not a printable ASCII character");
        
        this->table[key] = (int) pattern.size() - i - 1;
    }
}

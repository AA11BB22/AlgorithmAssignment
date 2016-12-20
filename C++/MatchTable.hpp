#ifndef MatchTable_hpp
#define MatchTable_hpp

#include <iostream>
#include <string>

using namespace std;

class MatchTable {
    
private:
    
    static const int non = 32, ascii = 128 - non;
    int table[ascii];
    
    void init(const string&);
    
public:
    
    MatchTable(const string&);
    ~MatchTable();
    
    int skip(char) const;
};

#endif /* MatchTable_hpp */

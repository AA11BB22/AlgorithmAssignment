#ifndef MatchTable_hpp
#define MatchTable_hpp

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class MatchTable {
    
private:
    
    static const int non = 32, ascii = 128 - non;
    int table[ascii];
    string pattern;
    
    void init();
    
public:
    
    MatchTable(const string&);
    ~MatchTable();
    
    int skip(char) const;
    void print() const;
};

#endif /* MatchTable_hpp */

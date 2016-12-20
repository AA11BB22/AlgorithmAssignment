#ifndef BoyerMoore_hpp
#define BoyerMoore_hpp

#include <iostream>
#include <string>
#include "MatchTable.hpp"

using namespace std;

class BoyerMoore {
    
private:
    int matchSize, size;
    int* matchLocations;
    string text, pattern;
    MatchTable* table;
    
    void run();
    void push_back(const int&);
    
public:
    BoyerMoore(const string &input, const string &pattern);
    ~BoyerMoore();
    
    void printLocations() const;
    
};

#endif /* BoyerMoore_hpp */

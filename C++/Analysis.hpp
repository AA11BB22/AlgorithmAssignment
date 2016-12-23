#ifndef Analysis_hpp
#define Analysis_hpp

#include <iostream>
#include <chrono>
#include <string>
#include "MatchTable.hpp"

using namespace std;

class Analysis {
    
private:
    
    string text, pattern;
    chrono::duration<double, micro> naive, boyerMoore;
    
    void naiveRun();
    void boyerMooreRun();
    
public:
    
    Analysis(const string& text, const string& pattern);
    
    chrono::duration<double, micro> naiveTime(), boyerMooreTime();
};

#endif /* Analysis_hpp */

#include <iostream>
#include "BoyerMoore.hpp"

using namespace std;

int main() {
    
    BoyerMoore test("abcasdadqjnkhqinfdvca", "asda");
    test.printLocations();
    test.simulate();
    
    return 0;
}

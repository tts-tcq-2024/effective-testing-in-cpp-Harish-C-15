#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void testPrintColorMap() {
    std::ostringstream oss;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    std::ostringstream expectedOutput;
    
    printColorMap();
    
    std::cout.rdbuf(originalCout);

     for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            expectedOutput << std::setw(2) << (i * 5 + j) << " | " 
                           << std::setw(6) << majorColor[i] << " | " 
                           << std::setw(6) << minorColor[j] << "\n";
        }
    }
   
    // Test if the output matches the expected output
    assert(oss.str() == expectedOutput && "Test failed: Output is not correctly aligned or mapped.");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}

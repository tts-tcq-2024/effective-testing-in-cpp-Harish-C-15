#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
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
    
    printColorMap();
    
    std::cout.rdbuf(originalCout);

    std::string expectedOutput =
        "0  | White | Blue\n"
        "1  | White | Orange\n"
        "2  | White | Green\n"
        "3  | White | Brown\n"
        "4  | White | Slate\n"
        "5  | Red   | Blue\n"
        "6  | Red   | Orange\n"
        "7  | Red   | Green\n"
        "8  | Red   | Brown\n"
        "9  | Red   | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow| Blue\n"
        "16 | Yellow| Orange\n"
        "17 | Yellow| Green\n"
        "18 | Yellow| Brown\n"
        "19 | Yellow| Slate\n"
        "20 | Violet| Blue\n"
        "21 | Violet| Orange\n"
        "22 | Violet| Green\n"
        "23 | Violet| Brown\n"
        "24 | Violet| Slate\n";

    // Test if the output matches the expected output
    assert(oss.str() == expectedOutput && "Test failed: Output is not correctly aligned or mapped.");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}

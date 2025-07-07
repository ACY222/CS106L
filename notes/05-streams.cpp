/* 1. Use '\n' instead of std::endl. Because the second trigger flush every
 * time, which is highly expensive
 * 2. A stringstream is both an input stream and an output stream
 *  The stream is very complex
 * 3. Don't use std::cin and std::getline together, because they treat
 * whitespace differently, unless you really really have to.
 * */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void stringStreamExample() {
    std::string initial_quote = 
        "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
    // Direct initialization
    std::stringstream ss(initial_quote);

    std::string first, last, language, extracted_quote;
    ss >> first >> last >> language;
    std::getline(ss, extracted_quote);
    std::cout << "using <<:\n";
    std::cout << first << " " << last << " said this: '" << language
        + " " + extracted_quote + "'" << std::endl;
    std::cout << "using +:\n";
    std::cout << first + " " + last + " said this: '" + language + " " +
        extracted_quote << "'" << std::endl;
}

void outputFileStreamExample() {
    std::ofstream ofs("hello.txt");
    ofs << "Hello CS106L! The file is open!" << '\n';     // will it be written?
    ofs << "this will get written" << '\n';
    ofs.close();
}

void inputFileStreamExample() {
    std::ifstream ifs("hello.txt");
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);
        std::cout << "Read the first line from the file: " << line << '\n';
    }
    else {
        std::cout << "Nothing from the file" << '\n';
    }
    if (ifs.is_open()) {
        std::string lineTwo;
        std::getline(ifs, lineTwo);
        std::cout << "Read the second line from the file: " << lineTwo << '\n';
    }
}

int main() {
    stringStreamExample();
    outputFileStreamExample();
    inputFileStreamExample();
    return 0;
}

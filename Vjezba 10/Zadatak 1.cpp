#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


void processFile(const std::string& filename, const std::string& targetWord, const std::string& targetSubstring) {
    
    std::ifstream file(filename);
    std::istream_iterator<std::string> fileIterator(file);
    std::istream_iterator<std::string> eof;
    std::vector<std::string> words(fileIterator, eof);

    std::vector<int> positions;
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == targetWord) {
            positions.push_back(i);
        }
    }

    words.erase(std::remove_if(words.begin(), words.end(), [targetSubstring](const std::string& str) {
        return str.find(targetSubstring) != std::string::npos;
        }), words.end());

    std::transform(words.begin(), words.end(), words.begin(), [](std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
        });

    std::ostream_iterator<std::string> outputIterator(std::cout, "\n");
    std::copy(words.begin(), words.end(), outputIterator);

    std::cout << "Pozicije rijeci '" << targetWord << "': ";
    std::copy(positions.begin(), positions.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    const std::string filename = "words.txt";
    const std::string targetWord = "target";
    const std::string targetSubstring = "substring";

    processFile(filename, targetWord, targetSubstring);

    return 0;
}

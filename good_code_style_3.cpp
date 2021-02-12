#include <iostream>
#include <string>
#include <vector>
 
const int alphabet = 26;
 
int main() {
    std::string word;
    std::vector<int> sameLetters(alphabet, 1);
    while (std::cin >> word) {
        std::vector<int> wordLetters(alphabet);
        for (auto letter : word) {
            ++wordLetters[letter - 'a'];
        }
        for (int i = 0; i < alphabet; ++i) {
            if (!wordLetters[i]) sameLetters[i] = 0;
        }
    }
    //std::cout << "something" << std::endl;
    for (int i = 0; i < alphabet; ++i) {
        if (sameLetters[i]) {
            std::cout << static_cast<char>('a' + i); 
        }
    }
}
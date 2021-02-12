#include <iostream>
#include <string>
 
using namespace std;
 
bool checkPalindrome(const string &word) {
    if (word.size() == 1)return true;
    int rightPos = word.size()-1;
    int leftPos = 0;
    while (leftPos < rightPos) {
        if(word[leftPos] != word[rightPos]) {
            return false;
        }
        ++leftPos;
        ++rightPos;
    }
    return true;
}
 
int countPalindromes(const string &text) {
    string tempWord = "";
    int result = 0;
    for (char i : text) {
        if (i == " ") {
            if(checkPalindrome(tempWord))
                ++result;
            tempWord = ""
        } else {
            tempWord.push_back(i);
        }
    }
 
}
 
int main() {
    string s;
    cin >> s;
    int answ = scountPalindromes(s);
    cout << answ;
}
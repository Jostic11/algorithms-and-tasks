#include <iostream>
#include <string>
 
using namespace std;
 
pair<int, int> FindVowels(const string &words, int position) {
    int startVowels = -1, len = 0;
    for (int i = position; i < words.size(); ++i) {
        if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' ||
            words[i] == 'o' || words[i] == 'u' || words[i] == 'y' ||
            words[i] == 'A' || words[i] == 'E' || words[i] == 'I' ||
            words[i] == 'O' || words[i] == 'U' || words[i] == 'Y') {
            if (startVowels == -1) {
                startVowels = i;
                len = 1;
            } else {
                ++len;
            }
        } else {
            if(startVowels != -1) {
                return {startVowels, len};
            }
        }
    }
    return {startVowels, len};
}
 
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    string text;
    getline(cin, text);
    size_t pos = 0;
    while (true) {
        auto [start, length] = FindVowels(text, pos);
        if (start == string::npos)
            break;
        cout << start << " " << length << " " << text.substr(start, length) << "\n";
        pos = start + length;
    }
}
#include <iostream>
#include <map>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    int numberOfContests;
    cin >> numberOfContests;
    map<string,vector<int>> table;
    for (int i = 0; i < numberOfContests; ++i) {
        int numberOfParticipans;
        cin >> numberOfParticipans;
        for (int j = 0; j < numberOfParticipans; ++j) {
            string login;
            cin >> login;
            int score;
            cin >> score;
            if(table.find(login) == table.end()) {
                table[login].resize(numberOfContests);
            }
            table[login][i] = score; 
        }
    }
    for(auto studentsResult : table) {
        cout << studentsResult.first << "\t";
        for(auto i : studentsResult.second) {
            cout << i << "\t";
        }
        cout << "\n";
    }
}
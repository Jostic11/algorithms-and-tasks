#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
string TreatmentString(string &cont) {
    string resultToString;
    cont.push_back(' ');
    int numberOfContest = 0;
    int pos = 0;
    while (cont[pos] != ' ') {
        numberOfContest *= 10;
        numberOfContest += (cont[pos]-'0');
        resultToString.push_back(cont[pos]);
        ++pos;
    }
    resultToString.push_back(' ');
    int numberOfTasks = 0;
    ++pos;
    while (cont[pos] != ' ') {
        numberOfTasks *= 10;
        numberOfTasks += (cont[pos]-'0');
        ++pos;
    }
    ++pos;
    if (pos == cont.size() || cont[pos] <= 90) {
        vector<int> digit(numberOfTasks);
        for (int i = 1; i <= numberOfTasks; ++i) {
            digit.push_back(i);
        }
        vector<int> done;
        for (; pos < cont.size(); pos += 2) {
            if(cont[pos+1] != ' ') {
                done.push_back((cont[pos]-'0')*10 + (cont[pos+1]-'0'));
                ++pos;
            } else {
                done.push_back(cont[pos]-'0');
            }
        }
        vector<int> result(numberOfTasks - done.size());
        //vector<int> result;
        //set_difference(digit.begin(), digit.end(), done.begin(), done.end(), inserter(result, result.begin()));
        set_difference(digit.begin(), digit.end(), done.begin(), done.end(), result.begin());
        cout << result.size() << endl;
        for (auto i : result) {
            cout << i << endl;
            //resultToString += (to_string(i));
            //resultToString.push_back(' ');
        }
    } else {
        vector<char> letter(numberOfTasks);
        for (int i = 0; i < numberOfTasks; ++i) {
            letter.push_back('A'+i);
        }
        vector<int> done;
        for (; pos < cont.size(); pos += 2) {
            done.push_back(cont[pos]);
        }
        vector<char> result;
        set_difference(letter.begin(), letter.end(), done.begin(), done.end(), inserter(result, result.begin()));
 
        for (auto i : result) {
            resultToString.push_back(i);
            resultToString.push_back(' ');
        }
    }
    return resultToString;
}
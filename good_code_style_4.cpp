#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
 
struct student {
    int score;
    std::string name, surname;
    int day, month, year;
    std::vector<std::string> preferredUnivers;
};
 
bool cmp(const student &l, const student &r) {
    if (l.score < r.score) {
        return true;
    } 
    if(l.score == r.score) {
        if(std::tie(l.year, l.month, l.day) > std::tie(r.year, r.month, r.day)) {
            return true;
        } 
        if(std::tie(l.year, l.month, l.day) == std::tie(r.year, r.month, r.day)) {
            return std::tie(l.surname, l.name) > std::tie(r.surname, r.name);
        }
    }
    return false;
}
 
int main() {
    int numberOfUnivers;
    std::cin >> numberOfUnivers;
    std::map<std::string, int> numberOfSeats;
    for (int i = 0; i < numberOfUnivers; ++i) {
        std::string universityName;
        std::cin >> universityName;
        std::cin >> numberOfSeats[universityName];
    }
    int numberOfApplicants;
    std::cin >> numberOfApplicants;
    std::vector<student> baseApplications(numberOfApplicants);
    for (int i = 0; i < numberOfApplicants; ++i) {
        std::cin >> baseApplications[i].name >> baseApplications[i].surname;
        std::cin >> baseApplications[i].day >> baseApplications[i].month >> baseApplications[i].year;
        std::cin >> baseApplications[i].score;
        int requestedUniversities;
        std::cin >> requestedUniversities;
        for (int j = 0; j < requestedUniversities; ++j) {
            std::string universityName;
            std::cin >> universityName;
            baseApplications[i].preferredUnivers.push_back(universityName);
        } 
    }
    sort(baseApplications.begin(), baseApplications.end(), cmp);
    reverse(baseApplications.begin(), baseApplications.end());
    /*
    for(const auto i : baseApplications) {
        std::cout << i.score << "\t" << i.year << "\t" << i.month << "\t" << i.day << "\t" << i.surname << "\t" << i.name << std::endl;
    }
    */
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> baseUniversity;
    for (int i = 0; i < numberOfApplicants; ++i) {
        for (const auto &j : baseApplications[i].preferredUnivers) {
            if (numberOfSeats[j] > 0) {
                baseUniversity[j].push_back({baseApplications[i].name, baseApplications[i].surname});
                --numberOfSeats[j];
                break;
            }
        }
    }
    for (const auto &university : baseUniversity) {
        std::cout << university.first << "\t";
        for (const auto &student : university.second) {
            std::cout << student.first << " " << student.second << "\t";
        }
        std::cout << "\n";
    }
}
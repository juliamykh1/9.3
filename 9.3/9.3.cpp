#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Zodiac {
    string surname;
    string firstName;
    string sign;
    int birthday[3];
};

bool compareByZodiacSign(const Zodiac& a, const Zodiac& b) {
    return a.sign < b.sign;
}

void displayPeopleByBirthMonth(const Zodiac* zodiacs, int size) {
    int birthMonth;
    cout << "Enter birth month (1-12): ";
    cin >> birthMonth;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (zodiacs[i].birthday[1] == birthMonth) {
            found = true;
            cout << zodiacs[i].surname << " " << zodiacs[i].firstName << " was born on " << zodiacs[i].birthday[0] << "/" << zodiacs[i].birthday[1] << "/" << zodiacs[i].birthday[2] << endl;
        }
    }

    if (!found) {
        cout << "No one was found born in month " << birthMonth << endl;
    }
}

int main() {
    const int SIZE = 5;
    Zodiac zodiacs[SIZE] = {
            { "Smith", "John", "Aquarius", {20, 1, 2000} },
            { "Johnson", "Lisa", "Aries", {1, 4, 1995} },
            { "Williams", "Emily", "Pisces", {10, 3, 1998} },
            { "Brown", "Michael", "Leo", {5, 8, 1997} },
            { "Jones", "Samantha", "Cancer", {22, 6, 1994} }
    };

    sort(zodiacs, zodiacs + SIZE, compareByZodiacSign);

    displayPeopleByBirthMonth(zodiacs, SIZE);

    return 0;
}
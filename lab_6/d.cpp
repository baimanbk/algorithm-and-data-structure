#include <bits/stdc++.h>

using namespace std;

struct Date {
    int day, month, year;
    //string original;

    bool operator<(const Date& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        //cin >> dates[i].original;
        cin >> dates[i].day;
        char dash;
        cin >> dash;
        cin >> dates[i].month;
        cin >> dash;
        cin >> dates[i].year;
    }

    sort(dates.begin(), dates.end());

    for (const Date& date : dates) {
        if(date.day < 10 || date.month < 10){
            if(date.month < 10 && date.day < 10){
                cout << "0" << date.day << "-0" << date.month << "-" << date.year << endl;
            }
            else if(date.day < 10){
                cout << "0" << date.day << "-" << date.month << "-" << date.year << endl;
            }
            else if(date.month < 10){
            cout << date.day << "-0" << date.month << "-" << date.year << endl;
        }
        }
        else{
        cout << date.day << "-" << date.month << "-" << date.year << endl;
        }
    }
    return 0;
}

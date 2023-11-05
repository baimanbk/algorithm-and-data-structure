#include <bits/stdc++.h>

using namespace std;

struct Date{
    string lname, fname;
    double gpa;
    bool operator<(const Date& other) const {
        if (gpa != other.gpa) {
            return  gpa < other.gpa;
        }
        if ( lname != other.lname) {
            return lname < other.lname;
        }
        return fname < other.fname;
    }
};

int main(){
    int n;
    cin >> n;
    vector<Date> dates(n);
    for(int i = 0 ; i < n ; i++){
        cin >> dates[i].lname;
        cin >> dates[i].fname;
        int m;
        cin >> m;
        double sumofci = 0;
        double sumofgi_ci = 0;
        for(int i = 0 ; i < m; i++){
            string s;
            cin >> s;
            double x;
            cin >> x;
            if(s == "A+"){
                sumofci += x;
                sumofgi_ci += x * 4.00;
            }
            else if(s =="A"){
                sumofci += x;
                sumofgi_ci += x * 3.75;
            }
            else if(s =="B+"){
                sumofci += x;
                sumofgi_ci += x * 3.50;
            }
            else if(s =="B"){
                sumofci += x;
                sumofgi_ci += x * 3.00;
            }
            else if(s =="C+"){
                sumofci += x;
                sumofgi_ci += x * 2.50;
            }
            else if(s =="C"){
                sumofci += x;
                sumofgi_ci += x * 2.00;
            }
            else if(s =="D+"){
                sumofci += x;
                sumofgi_ci += x * 1.50;
            }
            else if(s =="D"){
                sumofci += x;
                sumofgi_ci += x * 1.00;
            }
            else if(s =="F"){
                sumofci += x;
                sumofgi_ci += x * 0;
            }
        }
        dates[i].gpa = sumofgi_ci/sumofci;
    }
    sort(dates.begin(), dates.end());
    //reverse(dates.begin(), dates.end());
    for (const Date& date : dates) {
        cout << date.lname << " " << date.fname << " " << fixed << setprecision(3) << date.gpa << '\n';
    }

}
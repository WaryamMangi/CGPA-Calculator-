#include <iostream>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    int credits;
    float gradePoint;
};

float calculateGPA(Course courses[], int numCourses) {
    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        totalGradePoints += courses[i].gradePoint * courses[i].credits;
        totalCredits += courses[i].credits;
    }

    if (totalCredits == 0) return 0.0;
    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    Course courses[50];
    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter details for Course " << i + 1 << ":\n";

        cout << "Course Name: ";
        cin.ignore();
        getline(cin, courses[i].name);

        cout << "Credits: ";
        cin >> courses[i].credits;

        cout << "Grade Point (0.0 to 4.0): ";
        cin >> courses[i].gradePoint;
    }

    cout << "\nCourse Details and Grades:\n";
    cout << "-------------------------------------\n";
    cout << left << setw(15) << "Course Name" << setw(10) << "Credits" << "Grade Point\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(15) << courses[i].name << setw(10) << courses[i].credits << courses[i].gradePoint << endl;
    }

    float cgpa = calculateGPA(courses, numCourses);

    cout << "\nTotal Courses: " << numCourses << endl;
    cout << "Cumulative Grade Point Average (CGPA): " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
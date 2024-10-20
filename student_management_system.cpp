#include<bits/stdc++.h>
#include<string>
using namespace std;

class Student {
    private:
        string name;
        int roll;
        int marks[3];
        int total;
        float average;

    public:
        void inputData() {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter marks in 3 subjects: ";
            for(int i = 0; i < 3; i++) {
                cin >> marks[i];
            }
        }

        void calculateTotalAndAverage() {
            total = 0;
            for(int i = 0; i < 3; i++) {
                total += marks[i];
            }
            average = total / 3.0;
        }

        void displayData() {
            cout << "Name: " << name << ", Roll Number: " << roll;
            cout << ", Total Marks: " << total << ", Average: " << average << endl;
        }

        int getTotalMarks() {
            return total;
        }

        string getName() {
            return name;
        }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];
    for(int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i + 1 << ":\n";
        students[i].inputData();
        students[i].calculateTotalAndAverage();
    }

    cout << "\nStudent Information:\n";
    for(int i = 0; i < n; i++) {
        students[i].displayData();
    }

    int maxMarks = students[0].getTotalMarks();
    string topStudent = students[0].getName();
    
    for(int i = 1; i < n; i++) {
        if(students[i].getTotalMarks() > maxMarks) {
            maxMarks = students[i].getTotalMarks();
            topStudent = students[i].getName();
        }
    }
    cout << "\nStudent with highest marks: " << topStudent << endl;

    return 0;
}

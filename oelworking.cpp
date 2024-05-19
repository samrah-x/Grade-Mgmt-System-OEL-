#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_SUBJECTS = 3;

// Function to input marks for each student
void inputMarks(int marks[][NUM_SUBJECTS]) {
    cout << "Enter marks for each student (out of 100) for " << NUM_SUBJECTS << " subjects:\n";

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << (i + 1) << ":\n";
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            cout << "  Subject " << (j + 1) << ": ";
            cin >> marks[i][j];
        }
    }
}

// Function to classify each student's marks into categories
char classifyGrade(int marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

// Function to calculate average grade for each student and each subject
void calculateAverages(const int marks[][NUM_SUBJECTS], char studentGrades[], char subjectAverages[]) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int sum = 0;
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            sum += marks[i][j];
            studentGrades[i] = classifyGrade(sum / NUM_SUBJECTS);
        }
    }

    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        int sum = 0;
        for (int i = 0; i < NUM_STUDENTS; ++i) {
            sum += marks[i][j];
        }
        subjectAverages[j] = classifyGrade(sum / NUM_STUDENTS);
    }
}

// Function to display student-wise and subject-wise grades along with averages
void displayGrades(const int marks[][NUM_SUBJECTS], const char studentGrades[], const char subjectAverages[]) {
    cout << "\nStudent-wise Grades:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << (i + 1) << " - Grade: " << studentGrades[i] << "\n";
    }

    cout << "\nSubject-wise Averages:\n";
    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        cout << "Subject " << (j + 1) << " - Average Grade: " << subjectAverages[j] << "\n";
    }
}

// Function to update grades for a specific student or subject
void updateGrades(int marks[][NUM_SUBJECTS]) {
    int studentIndex, subjectIndex;

    cout << "Enter the student index (1-" << NUM_STUDENTS << ") to update grades: ";
    cin >> studentIndex;

    if (studentIndex < 1 || studentIndex > NUM_STUDENTS) {
        cout << "Invalid student index.\n";
        return;
    }

    cout << "Enter the subject index (1-" << NUM_SUBJECTS << ") to update grades: ";
    cin >> subjectIndex;

    if (subjectIndex < 1 || subjectIndex > NUM_SUBJECTS) {
        cout << "Invalid subject index.\n";
        return;
    }

    cout << "Enter new marks for Student " << studentIndex << ", Subject " << subjectIndex << ": ";
    cin >> marks[studentIndex - 1][subjectIndex - 1];
}

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS];
    char studentGrades[NUM_STUDENTS];
    char subjectAverages[NUM_SUBJECTS];

    // Task 1: Input marks for each student
    inputMarks(marks);

    // Task 2: Classify each student's marks into categories
    // Task 3: Calculate average grade for each student and each subject
    calculateAverages(marks, studentGrades, subjectAverages);

    // Task 5: Display student-wise and subject-wise grades along with averages
    displayGrades(marks, studentGrades, subjectAverages);
    
    // Additional Task: Allow the user to update grades
    updateGrades(marks);

    // Recalculate averages after the update
    calculateAverages(marks, studentGrades, subjectAverages);

    // Display updated results
    cout << "\nUpdated Results:\n";
    displayGrades(marks, studentGrades, subjectAverages);
    return 0;
}

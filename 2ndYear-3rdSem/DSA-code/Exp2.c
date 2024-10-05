#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int cetRank;
    char branch[20];
};

void input(struct Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("\nEnter details for student %d\n", i + 1);

        // Prompting for student's name and ensuring buffer safety
        printf("Name: ");
        scanf(" %49s", students[i].name);  // Limit input to 49 characters

        // Prompting for student's CET Rank
        printf("CET Rank: ");
        scanf("%d", &students[i].cetRank);

        // Prompting for branch and ensuring buffer safety
        printf("Branch (CSE, EE, Mech): ");
        scanf("%19s", students[i].branch);  // Limit input to 19 characters
    }
}

void segregateStudents(struct Student students[], int n, const char targetBranch[]) {
    printf("\nStudents who have selected %s branch:\n", targetBranch);
    printf("---------------------------------------------------\n");
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].branch, targetBranch) == 0) {
            printf("Name: %s, CET Rank: %d\n", students[i].name, students[i].cetRank);
            count++;
        }
    }
    if (count == 0) {
        printf("No students have selected %s branch.\n", targetBranch);
    }
}

int main() {
    int n;

    // Prompt for number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Validate that the number of students is positive
    if (n <= 0) {
        printf("Invalid number of students. Exiting program.\n");
        return 1;
    }

    // Allocate array of students
    struct Student students[n];  // Variable-length array in C99 and later

    // Input student data
    input(students, n);

    // Segregate and display students by branch
    segregateStudents(students, n, "CSE");
    segregateStudents(students, n, "EE");
    segregateStudents(students, n, "Mech");

    return 0;
}
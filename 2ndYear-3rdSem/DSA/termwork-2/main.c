#include <stdio.h>
#include <string.h>

struct student {
  char name[50];
  int cetRank;
  char branch[10];
};

void input(struct student students[], int size);
void segregate(struct student students[], int n, char targetBranch[]);

int main() {
  int n;
  printf("Enter the number of Students: ");
  scanf("%d", &n);

  struct student students[n];
  printf("Enter Student Details:\n");
  input(students, n);
  printf("-------\n");

  segregate(students, n, "CSE");
  segregate(students, n, "ME");
  segregate(students, n, "EC");
  segregate(students, n, "EE");

  return 0;
}

void segregate(struct student students[], int n, char targetBranch[]) {
  int stdAdmitted = 0;

  printf("\nStudents from %s branch:\n", targetBranch);
  for (int i = 0; i < n; i++) {
    if (strcmp(students[i].branch, targetBranch) == 0) {
      stdAdmitted = 1;
      printf("Student name: %s\n", students[i].name);
      printf("Student rank: %d\n", students[i].cetRank);
    }
  }
  if (stdAdmitted == 0) {
    printf("No students admitted for %s branch.\n", targetBranch);
  }
}

void input(struct student students[], int size) {
  for (int i = 0; i < size; i++) {
    printf("\nStudent name: ");
    scanf("%s", students[i].name);
    printf("Student branch: ");
    scanf("%s", students[i].branch);
    printf("Student rank: ");
    scanf("%d", &students[i].cetRank);
  }
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	double gpa;
	char* name;
} Student;

void cmpstudent(Student *s1, Student *s2) {

	printf("S1: %.2f %s\n", s1->gpa, s1->name);
	printf("S2: %.2f %s\n", s2->gpa, s2->name);

	if (s1->gpa > s2->gpa) {
		puts("s1>s2");
	}
	else if (s2->gpa > s1->gpa) {
		puts("s1<s2");
	}
	else {
		int cmp = strcmp(s1->name, s2->name);
		if (cmp > 0) {
			puts("s1>s2");
		}
		else if (cmp < 0) {
			puts("s1<s2");
		}
		else {
			puts("s1==s2");
		}
	}
}

int main() {

	Student* s1 = malloc(sizeof(Student));
	s1->gpa = 4.0;
	s1->name = "Rob";
	Student* s2 = malloc(sizeof(Student));
	s2->gpa = 4.0;
	s2->name = "Rob";

	cmpstudent(s1, s2);
	
	free(s1);
	free(s2);

	return 0;
}

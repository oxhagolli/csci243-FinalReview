#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* name;
} Person;

union data {
	double d;
	Person* p;
	int i;
};

typedef struct ListNode {
	union data d;
	struct ListNode* next;
} ListNode;

int main() {
	
	Person* aP = malloc(sizeof(Person));
	aP->name = "Rob";
	printf("Person: %s\n", aP->name);
	fflush(stdout);
	ListNode* l = malloc(sizeof(ListNode));
	l->d.p = aP;
	printf("Person: %s\n", (l->d.p)->name);
	fflush(stdout);
	l->d.i = 100;
	printf("Int: %d\n", l->d.i);
	fflush(stdout);
	// this will die
	printf("Person: %s\n", (l->d.p)->name);
	fflush(stdout);
	
	free(l);
	free(aP);
	return 0;
}


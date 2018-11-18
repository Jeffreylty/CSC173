#include<stdio.h>
#include<stdlib.h>

typedef struct CSG *CSGLIST;
struct CSG {
    char Courses[5];
    int StudentId;
    char Grade[2];
};
typedef CSGLIST CSGHASHTABLE[1009];

typedef struct SNAP *SNAPLIST;
struct SNAP {
    int StudentId;
    char Name[30];
    char Address[50];
    char Phone[8];
};
typedef SNAPLIST SANPHASHTABLE[1009];

typedef struct CP *CPLIST;
struct CP {
    char Courses[5];
    char Prerequisite[5];
};
typedef CPLIST CPHASHTABLE[1009];

typedef struct CDH *CDHLIST;
struct CDH {
    char Courses[5];
    char Day[2];
    char Hour[3];
};
typedef CDHLIST CDHHASHTABLE[1009];

typedef struct CR *CRLIST;
struct CR {
    char Courses[5];
    char Room[30];
};
typedef CRLIST CRHASHTABLE[1009];

int hashing(char* key);
int hashing(char* key) {
    int sum = 0;
    char * t;
    for (t = key; *t != '\0'; t++) {
        sum *= 10;
        sum += *t - '0';
    }
    return sum % 1009;
}

CSGHASHTABLE* insert_CSG(char* Courses, int StudentId, char* Grade, CSGHASHTABLE* CSGHASHTABLE);
CSGHASHTABLE* insert_CSG(char* Courses, int StudentId, char* Grade, CSGHASHTABLE* CSGHASHTABLE){
    int index = hashing(Courses);
    CSGLIST* position =CSGHASHTABLE[index];
    while(position != NULL){
        
    }
    
}

int main(void) {
	//part 1.3
	//populate the tables with the data given in the figures
	insert_CSG(new_CSG("CS101", 12345, "A"), Course-StudentID-Grade);
	insert_CSG(new_CSG("CS101", 67890, "B"), Course-StudentID-Grade);
	insert_CSG(new_CSG("EE200", 12345, "C"), Course-StudentID-Grade);
	insert_CSG(new_CSG("EE200", 22222, "B+"), Course-StudentID-Grade);
	insert_CSG(new_CSG("CS101", 33333, "A-"), Course-StudentID-Grade);
	insert_CSG(new_CSG("PH100", 67890, "A+"), Course-StudentID-Grade);

	insert_SNAP(new_SNAP(12345, "C. Brown", "12 Apple St.", "555-1234"), StudentID-Name-Address-Phone);
	insert_SNAP(new_SNAP(67890, "L. Van Pelt", "34 Pear Ave.", "555-5678"), StudentID-Name-Address-Phone);
	insert_SNAP(new_SNAP(22222, "P. Patty", "56 Grape Blvd.", "555-9999"), StudentID-Name-Address-Phone);

	insert_CP(new_CP("CS101", "CS100"), Course-Prerequisite);
	insert_CP(new_CP("EE200", "EE005"), Course-Prerequisite);
	insert_CP(new_CP("EE200", "CS100"), Course-Prerequisite);
	insert_CP(new_CP("CS120", "CS101"), Course-Prerequisite);
	insert_CP(new_CP("CS121", "CS120"), Course-Prerequisite);
	insert_CP(new_CP("CS205", "CS101"), Course-Prerequisite);
	insert_CP(new_CP("CS206", "CS121"), Course-Prerequisite);
	insert_CP(new_CP("CS206", "CS205"), Course-Prerequisite);

	insert_CDH(new_CDH("CS101", "M", "9AM"), Course-Day-Hour);
	insert_CDH(new_CDH("CS101", "W", "9AM"), Course-Day-Hour);
	insert_CDH(new_CDH("CS101", "F", "9AM"), Course-Day-Hour);
	insert_CDH(new_CDH("EE200", "Tu", "10AM"), Course-Day-Hour);
	insert_CDH(new_CDH("EE200", "W", "1PM"), Course-Day-Hour);
	insert_CDH(new_CDH("EE200", "Th", "10AM"), Course-Day-Hour);

	insert_CR(new_CR("CS101", "Turing Aud."), Course-Room);
	insert_CR(new_CR("EE200", "25 Ohm Hall"), Course-Room);
	insert_CR(new_CR("PH100", "Newton Lab."), Course-Room);

	printf("Find the grade of the student with ID 12345 in CS101: %s\n", print_CSG(lookup((“CS101”, 12345, ∗), Course-StudentId-Grade)));
	printf("Whether CS120 is a prerequisite of CS205: %s\n", print_CP(lookup((“CS205”, "CS120"), Course-Prerequisite)));
	printf("Drop the first tuple from CR: %s\n", print_CR(delete((“CS101”, ∗), Course-Room)));
	printf("Makes CS120 a prerequisite of CS205: %s\n", print_CP(insert((“CS205”, "CS120"), Course-Prerequisite)));
	printf("Has no effect on the relation of CP, because the inserted tuple is already there: %s\n", print_CP(insert((“CS205”, "CS101"), Course-Prerequisite)));

	return 0;
}

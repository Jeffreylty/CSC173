#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CSG *CSGLIST;
struct CSG {
    char Courses[5];
    int StudentId;
    char Grade[2];
};
typedef CSGLIST CSGHASHTABLE[1009];


//New CSG tuple
CSGLIST new_CSG(char* Courses, int StudentId, char* Grade);
CSGLIST new_CSG(char* Courses, int StudentId, char* Grade){
    CSGLIST csg = (CSGLIST)malloc(sizeof(struct CSG));
    if(sizeof(Courses)>5){
        printf("Wrong Course name length");
        return NULL;
    }
    if(sizeof(Grade)>2){
        printf("Wrong Grade length");
        return NULL;
    }
    strcpy(csg->Courses,Courses);
    csg->StudentId=StudentId;
    strcpy(csg->Grade,Grade);
    return csg;
}

typedef struct SNAP *SNAPLIST;
struct SNAP {
    int StudentId;
    char Name[30];
    char Address[50];
    char Phone[8];
};
typedef SNAPLIST SANPHASHTABLE[1009];

//new SNAP tuple
SNAPLIST new_SNAP(int StudentId, char* Name, char* Address, char* Phone);
SNAPLIST new_SNAP(int StudentId, char* Name, char* Address, char* Phone){
    SNAPLIST snap = (SNAPLIST)malloc(sizeof(struct SNAP));
    if(sizeof(Name)>30){
        printf("Wrong Name length");
        return NULL;
    }
    if(sizeof(Address)>50){
        printf("Wrong Address length");
        return NULL;
    }
    if(sizeof(Phone)>8){
        printf("Wrong Phone length");
        return NULL;
    }
    strcpy(snap->Name,Name);
    snap->StudentId=StudentId;
    strcpy(snap->Address,Address);
    strcpy(snap->Phone, Phone);
    return snap;
}

typedef struct CP *CPLIST;
struct CP {
    char Courses[5];
    char Prerequisite[5];
};
typedef CPLIST CPHASHTABLE[1009];

//New CP tuple
CPLIST new_CP(char* Courses, char* Prerequisite);
CPLIST new_CP(char* Courses, char* Prerequisite){
    CPLIST cp = (CPLIST)malloc(sizeof(struct CP));
    if(sizeof(Courses)>5){
        printf("Wrong Course name length");
        return NULL;
    }
    if(sizeof(Prerequisite)>5){
        printf("Wrong Prerequisite length");
        return NULL;
    }
    strcpy(cp->Courses,Courses);
    strcpy(cp->Prerequisite,Prerequisite);
    return cp;
}

typedef struct CDH *CDHLIST;
struct CDH {
    char Courses[5];
    char Day[2];
    char Hour[3];
};
typedef CDHLIST CDHHASHTABLE[1009];

//new CDH tuple
CDHLIST new_CDH( char* Courses, char* Day, char* Hour);
CDHLIST new_CDH( char* Courses, char* Day, char* Hour){
    CDHLIST cdh = (CDHLIST)malloc(sizeof(struct CDH));
    if(sizeof(Courses)>5){
        printf("Wrong Courses length");
        return NULL;
    }
    if(sizeof(Day)>2){
        printf("Wrong Day length");
        return NULL;
    }
    if(sizeof(Hour)>3){
        printf("Wrong Hour length");
        return NULL;
    }
    strcpy(cdh->Courses,Courses);
    strcpy(cdh->Day,Day);
    strcpy(cdh->Hour, Hour);
    return cdh;
}

typedef struct CR *CRLIST;
struct CR {
    char Courses[5];
    char Room[30];
};
typedef CRLIST CRHASHTABLE[1009];

//New CR tuple
CRLIST new_CR(char* Courses, char* Room);
CRLIST new_CR(char* Courses, char* Room){
    CRLIST cr = (CRLIST)malloc(sizeof(struct CR));
    if(sizeof(Courses)>5){
        printf("Wrong Course name length");
        return NULL;
    }
    if(sizeof(Room)>5){
        printf("Wrong Room length");
        return NULL;
    }
    strcpy(cr->Courses,Courses);
    strcpy(cr->Room,Room);
    return cr;
}

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

//print a tuple in CSG
int print_CSG(CSGLIST csg);
int print_CSG(CSGLIST csg){
	if (csg != NULL){
		printf("(%s, %d, %s) ", csg->Courses, csg->StudentId, csg->Grade);
	}
	return 1;
}

//print the table of CSG
int print_CSGTable(CSGHASHTABLE csgt);
int print_CSGTable(CSGHASHTABLE csgt){
	for(int i = 0; i < 1009; i++){
		if (csgt[i] != NULL){
			print_CSG(csgt[i]);
		}
	}
	printf("\n");
	return 1;
}

//print a tuple in SNAP
int print_SNAP(SNAPLIST snap);
int print_SNAP(SNAPLIST snap){
	if (snap != NULL){
		printf("(%d, %s, %s, %s) ", snap->StudentId, snap->Name, snap->Address, snap->Phone);
	}
	return 1;
}

//print the table of SNAP
int print_SNAPTable(SNAPHASHTABLE snapt);
int print_SNAPTable(SNAPHASHTABLE snapt){
	for(int i = 0; i < 1009; i++){
		if (snapt[i] != NULL){
			print_SNAP(snapt[i]);
		}
	}
	printf("\n");
	return 1;
}

//print a tuple in CP
int print_CP(CPLIST cp);
int print_CP(CPLIST cp){
	if (cp != NULL){
		printf("(%s, %s) ", cp->Courses, cp->Prerequisite);
	}
	return 1;
}

//print the table of CP
int print_CPTable(CPHASHTABLE cpt);
int print_CPTable(CPHASHTABLE cpt){
	for(int i = 0; i < 1009; i++){
		if (cpt[i] != NULL){
			print_CP(cpt[i]);
		}
	}
	printf("\n");
	return 1;
}

//print a tuple in CDH
int print_CDH(CDHLIST cdh);
int print_CDH(CDHLIST cdh){
	if (csg != NULL){
		printf("(%s, %s, %s) ", cdh->Courses, cdh->Day, cdh->Hour);
	}
	return 1;
}

//print the table of CDH
int print_CDHTable(CDHHASHTABLE cdht);
int print_CDHTable(CDHHASHTABLE cdht){
	for(int i = 0; i < 1009; i++){
		if (cdht[i] != NULL){
			print_CDH(cdht[i]);
		}
	}
	printf("\n");
	return 1;
}

//print a tuple in CR
int print_CR(CRLIST cr);
int print_CR(CRLIST cr){
	if (csg != NULL){
		printf("(%s, %s) ", cr->Courses, cr->Room);
	}
	return 1;
}

//print the table of CR
int print_CRTable(CRHASHTABLE crt);
int print_CRTable(CRHASHTABLE crt){
	for(int i = 0; i < 1009; i++){
		if (crt[i] != NULL){
			print_CR(crt[i]);
		}
	}
	printf("\n");
	return 1;
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

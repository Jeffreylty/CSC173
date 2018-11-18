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

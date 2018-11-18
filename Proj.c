typedef struct CSG *CSGLIST;
struct CSG {
	char Courses[5];
	int StudentId;
	char Grade[2];
};
typedef CSGLIST HASHTABLE[1009];

typedef struct SNAP *SNAPLIST;
struct SNAP {
	int StudentId;
	char Name[30];
	char Address[50];
	char Phone[8];
};
typedef SNAPLIST HASHTABLE[1009];

typedef struct CP *CPLIST;
struct CP {
	char Courses[5];
	char Prerequisite[5];
};
typedef CPLIST HASHTABLE[1009];

typedef struct CDH *CDHLIST;
struct CDH {
	char Courses[5];
	char Day[2];
	char Hour[3];
};
typedef CDHLIST HASHTABLE[1009];

typedef struct CR *CRLIST;
struct CR {
	char Courses[5];
	char Room[30];
};
typedef CRLIST HASHTABLE[1009];

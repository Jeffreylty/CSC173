//
//  main.c
//  Proj4
//
// By Canruo Zou, Tianyi Liu
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct CSG *CSGLIST;
struct CSG {
    char Courses[6];
    int StudentId;
    char Grade[3];
    CSGLIST next;
};
typedef CSGLIST CSGHASHTABLE[1009];


//compare two CSG tuple if they are same or not
bool equal_CSG(CSGLIST csg1, CSGLIST csg2);
bool equal_CSG(CSGLIST csg1, CSGLIST csg2){
    if(strcmp(csg1->Courses,csg2->Courses)==0 && csg1->StudentId==csg2->StudentId && strcmp(csg1->Grade,csg2->Grade)==0){
        return true;
    }
    return false;
}


//New CSG tuple
CSGLIST new_CSG(char* Courses, int StudentId, char* Grade);
CSGLIST new_CSG(char* Courses, int StudentId, char* Grade){
    CSGLIST csg = (CSGLIST)malloc(sizeof(struct CSG));
    if(strlen(Courses)>5){
        printf("Wrong Course length");
    }
    if(strlen(Grade)>2){
        printf("Wrong Grade length");
    }
    strncpy(csg->Courses,Courses,5);
    csg->Courses[5]='\0';
    csg->StudentId=StudentId;
    strncpy(csg->Grade,Grade,2);
    csg->Grade[2]='\0';
    csg->next= NULL;
    return csg;
}

//print a tuple in CSG
void print_CSG(CSGLIST csg);
void print_CSG(CSGLIST csg){
    if (csg != NULL){
        printf("(%s, %d, %s) ", csg->Courses, csg->StudentId, csg->Grade);
    }
}

//print the table of CSG
void print_CSGTable(CSGHASHTABLE* csgt);
void print_CSGTable(CSGHASHTABLE* csgt){
    printf("CSG Table: \n");
    for(int i = 0; i <= 1009; i++){
        CSGLIST* position = csgt[i];
        while((*position) != NULL){
            print_CSG(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct SNAP *SNAPLIST;
struct SNAP {
    int StudentId;
    char Name[31];
    char Address[51];
    char Phone[9];
    SNAPLIST next;
};
typedef SNAPLIST SNAPHASHTABLE[1009];

//compare two SNAP tuple if they are same or not
bool equal_SNAP(SNAPLIST snap1, SNAPLIST snap2);
bool equal_SNAP(SNAPLIST snap1, SNAPLIST snap2){
    if(strcmp(snap1->Address,snap2->Address)==0 && snap1->StudentId==snap2->StudentId && strcmp(snap1->Name,snap2->Name)==0 && strcmp(snap1->Phone, snap2->Phone)==0){
//        printf("SNAP tuple already exists\n");
        return true;
    }
    return false;
}

//new SNAP tuple
SNAPLIST new_SNAP(int StudentId, char* Name, char* Address, char* Phone);
SNAPLIST new_SNAP(int StudentId, char* Name, char* Address, char* Phone){
    SNAPLIST snap = (SNAPLIST)malloc(sizeof(struct SNAP));
    if(strlen(Name)>30){
        printf("Wrong Name length");
    }
    if(strlen(Address)>50){
        printf("Wrong Address length");
    }
    if(strlen(Phone)>8){
        printf("Wrong Phone length");
        return NULL;
    }
    strncpy(snap->Name,Name,30);
    snap->Name[30]='\0';
    snap->StudentId=StudentId;
    strncpy(snap->Address,Address,50);
    snap->Address[50]='\0';
    strncpy(snap->Phone, Phone,8);
    snap->Phone[8]='\0';
    snap->next= NULL;
    return snap;
}

//print a tuple in SNAP
void print_SNAP(SNAPLIST snap);
void print_SNAP(SNAPLIST snap){
    if (snap != NULL){
        printf("(%d, %s, %s, %s) ", snap->StudentId, snap->Name, snap->Address, snap->Phone);
    }
}

//print the table of SNAP
void print_SNAPTable(SNAPHASHTABLE* cnapt);
void print_SNAPTable(SNAPHASHTABLE* cnapt){
    printf("SNAP Table: \n");
    for(int i = 0; i <= 1009; i++){
        SNAPLIST* position = cnapt[i];
        while((*position) != NULL){
            print_SNAP(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct CP *CPLIST;
struct CP {
    char Courses[6];
    char Prerequisite[6];
    CPLIST next;
};
typedef CPLIST CPHASHTABLE[1009];


//compare two CP tuple if they are same or not
bool equal_CP(CPLIST cp1, CPLIST cp2);
bool equal_CP(CPLIST cp1, CPLIST cp2){
    if(strcmp(cp1->Courses,cp2->Courses)==0 && strcmp(cp1->Prerequisite,cp2->Prerequisite)==0){
        return true;
    }
    return false;
}

//New CP tuple
CPLIST new_CP(char* Courses, char* Prerequisite);
CPLIST new_CP(char* Courses, char* Prerequisite){
    CPLIST cp = (CPLIST)malloc(sizeof(struct CP));
    if(strlen(Courses)>5){
        printf("Wrong Course name length");
    }
    if(strlen(Prerequisite)>5){
        printf("Wrong Prerequisite length");
    }
    strncpy(cp->Courses,Courses,5);
    cp->Courses[5]='\0';
    strncpy(cp->Prerequisite,Prerequisite,5);
    cp->Prerequisite[5]='\0';
    cp->next= NULL;
    return cp;
}

//print a tuple in CP
void print_CP(CPLIST cp);
void print_CP(CPLIST cp){
    if (cp != NULL){
        printf("(%s, %s) ", cp->Courses, cp->Prerequisite);
    }
}

//print the table of CP
void print_CPTable(CPHASHTABLE* cpt);
void print_CPTable(CPHASHTABLE* cpt){
    printf("CP Table: \n");
    for(int i = 0; i <= 1009; i++){
        CPLIST* position = cpt[i];
        while((*position) != NULL){
            print_CP(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct CDH *CDHLIST;
struct CDH {
    char Courses[6];
    char Day[3];
    char Hour[5];
    CDHLIST next;
};
typedef CDHLIST CDHHASHTABLE[1009];

//compare two CDH tuple if they are same or not
bool equal_CDH(CDHLIST cdh1, CDHLIST cdh2);
bool equal_CDH(CDHLIST cdh1, CDHLIST cdh2){
    if(strcmp(cdh1->Courses,cdh2->Courses)==0 && strcmp(cdh1->Day,cdh2->Day)==0 && strcmp(cdh1->Hour,cdh2->Hour)==0){
        return true;
    }
    return false;
}

//new CDH tuple
CDHLIST new_CDH( char* Courses, char* Day, char* Hour);
CDHLIST new_CDH( char* Courses, char* Day, char* Hour){
    CDHLIST cdh = (CDHLIST)malloc(sizeof(struct CDH));
    if(strlen(Courses)>5){
        printf("Wrong Courses length");
    }
    if(strlen(Day)>2){
        printf("Wrong Day length");
    }
    if(strlen(Hour)>4){
        printf("Wrong Hour length");
    }
    strncpy(cdh->Courses,Courses,5);
    cdh->Courses[5]='\0';
    strncpy(cdh->Day,Day,2);
    cdh->Day[2]='\0';
    strncpy(cdh->Hour, Hour,4);
    cdh->Hour[4]='\0';
    cdh->next= NULL;
    return cdh;
}

//print a tuple in CDH
void print_CDH(CDHLIST cdh);
void print_CDH(CDHLIST cdh){
    if (cdh != NULL){
        printf("(%s, %s, %s) ", cdh->Courses, cdh->Day, cdh->Hour);
    }
}

//print the table of CDH
void print_CDHTable(CDHHASHTABLE* cdhpt);
void print_CDHTable(CDHHASHTABLE* cdhpt){
    printf("CDH Table: \n");
    for(int i = 0; i <= 1009; i++){
        CDHLIST* position = cdhpt[i];
        while((*position) != NULL){
            print_CDH(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct CR *CRLIST;
struct CR {
    char Courses[6];
    char Room[31];
    CRLIST next;
};
typedef CRLIST CRHASHTABLE[1009];


//compare two CR tuple if they are same or not
bool equal_CR(CRLIST cr1, CRLIST cr2);
bool equal_CR(CRLIST cr1, CRLIST cr2){
    if(strcmp(cr1->Courses,cr2->Courses)==0 && strcmp(cr1->Room,cr2->Room)==0){
        return true;
    }
    return false;
}

//New CR tuple
CRLIST new_CR(char* Courses, char* Room);
CRLIST new_CR(char* Courses, char* Room){
    CRLIST cr = (CRLIST)malloc(sizeof(struct CR));
    if(strlen(Courses)>5){
        printf("Wrong Course name length");
    }
    if(strlen(Room)>30){
        printf("Wrong Room length");
    }
    strncpy(cr->Courses,Courses,5);
    cr->Courses[5]='\0';
    strncpy(cr->Room,Room,30);
    cr->Room[30]='\0';
    cr->next= NULL;
    return cr;
}


//print a tuple in CR
void print_CR(CRLIST cr);
void print_CR(CRLIST cr){
    if (cr != NULL){
        printf("(%s, %s) ", cr->Courses, cr->Room);
    }
}

//print the table of CR
void print_CRTable(CRHASHTABLE* crt);
void print_CRTable(CRHASHTABLE* crt){
    printf("CR Table: \n");
    for(int i = 0; i <= 1009; i++){
        CRLIST* position = crt[i];
        while((*position) != NULL){
            print_CR(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
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

//initialize a CSG table
CSGHASHTABLE* new_CSGHASHTABLE(void);
CSGHASHTABLE* new_CSGHASHTABLE(){
    CSGHASHTABLE * TABLE = (CSGHASHTABLE*)malloc(sizeof(CSGHASHTABLE));
    for(int i=0;i<=1009;i++){
        CSGLIST * index = TABLE[i];
        (*index)=NULL;
    }
    return TABLE;
}

//initialize a SNAP table
SNAPHASHTABLE* new_SNAPHASHTABLE(void);
SNAPHASHTABLE* new_SNAPHASHTABLE(){
    SNAPHASHTABLE * TABLE = (SNAPHASHTABLE*)malloc(sizeof(SNAPHASHTABLE));
    for(int i=0;i<=1009;i++){
        SNAPLIST * index = TABLE[i];
        (*index)=NULL;
    }
    return TABLE;
}

//initialize a CP table
CPHASHTABLE* new_CPHASHTABLE(void);
CPHASHTABLE* new_CPHASHTABLE(){
    CPHASHTABLE * TABLE = (CPHASHTABLE*)malloc(sizeof(CPHASHTABLE));
    for(int i=0;i<=1009;i++){
        CPLIST * index = TABLE[i];
        (*index)=NULL;
    }
    return TABLE;
}

//initialize a CDH table
CDHHASHTABLE* new_CDHHASHTABLE(void);
CDHHASHTABLE* new_CDHHASHTABLE(){
    CDHHASHTABLE * TABLE = (CDHHASHTABLE*)malloc(sizeof(CDHHASHTABLE));
    for(int i=0;i<=1009;i++){
        CDHLIST * index = TABLE[i];
        (*index)=NULL;
    }
    return TABLE;
}

//initialize a CR table
CRHASHTABLE* new_CRHASHTABLE(void);
CRHASHTABLE* new_CRHASHTABLE(){
    CRHASHTABLE * TABLE = (CRHASHTABLE*)malloc(sizeof(CRHASHTABLE));
    for(int i=0;i<=1009;i++){
        CRLIST * index = TABLE[i];
        (*index)=NULL;
    }
    return TABLE;
}

//insert CSG tuple into CSGTABLE
CSGHASHTABLE* insert_CSG(CSGLIST csg, CSGHASHTABLE* CSGHASHTABLE);
CSGHASHTABLE* insert_CSG(CSGLIST csg, CSGHASHTABLE* CSGHASHTABLE){
    int index = hashing(csg->Courses);
    CSGLIST* position =CSGHASHTABLE[index];
//    CSGLIST* first=CSGHASHTABLE[index];
    while((*position) != NULL){
        if(equal_CSG(csg, (*position))){
            printf("CSG tuple :");
            print_CSG(csg);
            printf(" already exists\n");
            return CSGHASHTABLE;
        }else{
            position=&(*position)->next;
        }
    }
    *position = csg;
    return CSGHASHTABLE;
}

//insert SNAP tuple into SNAPTABLE
SNAPHASHTABLE* insert_SNAP(SNAPLIST snap, SNAPHASHTABLE* SNAPHASHTABLE);
SNAPHASHTABLE* insert_SNAP(SNAPLIST snap, SNAPHASHTABLE* SNAPHASHTABLE){
    char str[10];
    sprintf(str,"%d", snap->StudentId);
    int index = hashing(str);
    SNAPLIST* position =SNAPHASHTABLE[index];
    while((*position) != NULL){
        if(equal_SNAP(snap, (*position))){
            printf("SNAP tuple :");
            print_SNAP(snap);
            printf(" already exists\n");
            return SNAPHASHTABLE;
        }else{
            position=&(*position)->next;
        }
    }
    *position = snap;
    return SNAPHASHTABLE;
}

//insert CP tuple into CPTABLE
CPHASHTABLE* insert_CP(CPLIST cp, CPHASHTABLE* CPHASHTABLE);
CPHASHTABLE* insert_CP(CPLIST cp, CPHASHTABLE* CPHASHTABLE){
    int index = hashing(cp->Courses);
    CPLIST* position =CPHASHTABLE[index];
    while((*position) != NULL){
        if(equal_CP(cp, (*position))){
            printf("CP tuple :");
            print_CP(cp);
            printf(" already exists\n");
            return CPHASHTABLE;
        }else{
            position=&(*position)->next;
        }
    }
    *position = cp;
    return CPHASHTABLE;
}

//insert CDH tuple into CDHTABLE
CDHHASHTABLE* insert_CDH(CDHLIST cdh, CDHHASHTABLE* CDHHASHTABLE);
CDHHASHTABLE* insert_CDH(CDHLIST cdh, CDHHASHTABLE* CDHHASHTABLE){
    int index = hashing(cdh->Courses);
    CDHLIST* position =CDHHASHTABLE[index];
    while((*position) != NULL){
        if(equal_CDH(cdh,(*position))){
            printf("CDH tuple :");
            print_CDH(cdh);
            printf(" already exists\n");
            return CDHHASHTABLE;
        }else{
            position=&(*position)->next;
        }
    }
    *position = cdh;
    return CDHHASHTABLE;
}

//insert CR tuple into CRTABLE
CRHASHTABLE* insert_CR(CRLIST cr, CRHASHTABLE* CRHASHTABLE);
CRHASHTABLE* insert_CR(CRLIST cr, CRHASHTABLE* CRHASHTABLE){
    int index = hashing(cr->Courses);
    CRLIST* position =CRHASHTABLE[index];
    while((*position) != NULL){
        if(equal_CR(cr,(*position))){
            printf("CR tuple :");
            print_CR(cr);
            printf(" already exists\n");
            return CRHASHTABLE;
        }else{
            position=&(*position)->next;
        }
    }
    *position = cr;
    return CRHASHTABLE;
}

//look up a givin condtition in CSGTABLE
CSGHASHTABLE* lookup_CSG(char* Courses, int StudentId, char* Grade,CSGHASHTABLE* TABLE);
CSGHASHTABLE* lookup_CSG(char* Courses, int StudentId, char* Grade,CSGHASHTABLE* TABLE){
    CSGHASHTABLE* result = new_CSGHASHTABLE();
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkS=true;
    if(StudentId==-1){checkS=false;}
    bool checkG=true;
    if(*Grade == '*'){checkG=false;}
    if(checkC){
        int index = hashing(Courses);
        CSGLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkS==false || StudentId==(*position)->StudentId)&&(checkG==false || strcmp(Grade, (*position)->Grade)==0)){
                CSGLIST temp= new_CSG((*position)->Courses, (*position)->StudentId, (*position)->Grade);
                temp->next=NULL;
                insert_CSG(temp, result);
//                free(temp);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return result;
    }else{
        for(int i=0; i<= 1009; i++){
            CSGLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkS==false || StudentId==(*position)->StudentId)&&(checkG==false || strcmp(Grade, (*position)->Grade)==0)){
                    CSGLIST temp= new_CSG((*position)->Courses, (*position)->StudentId, (*position)->Grade);
                    temp->next=NULL;
                    insert_CSG(temp, result);
//                    free(temp);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

//look up a givin condtition in SNAPTABLE
SNAPHASHTABLE* lookup_SNAP(int StudentId, char* Name, char* Address, char* Phone,SNAPHASHTABLE* TABLE);
SNAPHASHTABLE* lookup_SNAP(int StudentId, char* Name, char* Address, char* Phone,SNAPHASHTABLE* TABLE){
    SNAPHASHTABLE* result = new_SNAPHASHTABLE();
    bool checkN =true;
    if(*Name == '*'){checkN=false;}
    bool checkS=true;
    if(StudentId==-1){checkS=false;}
    bool checkA=true;
    if(*Address == '*'){checkA=false;}
    bool checkP=true;
    if(*Phone=='*'){checkP=false;}
    if(checkS){
        char str[10];
        sprintf(str,"%d", StudentId);
        int index = hashing(str);
        SNAPLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Name, (*position)->Name)==0 || checkN==false )&&(StudentId==(*position)->StudentId)
               &&(checkA==false || strcmp(Address, (*position)->Address)==0)&&(checkP==false || strcmp(Phone, (*position)->Phone)==0)){
                SNAPLIST temp= new_SNAP((*position)->StudentId, (*position)->Name, (*position)->Address,(*position)->Phone);
                temp->next=NULL;
                insert_SNAP(temp, result);
//                free(temp);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return result;
    }else{
        for(int i=0; i<= 1009; i++){
            SNAPLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_SNAP((*position));
                if((strcmp(Name, (*position)->Name)==0 || checkN==false )
                   &&(checkA==false || strcmp(Address, (*position)->Address)==0)&&(checkP==false || strcmp(Phone, (*position)->Phone)==0)){
                    SNAPLIST temp= new_SNAP((*position)->StudentId, (*position)->Name, (*position)->Address,(*position)->Phone);
                    temp->next=NULL;
                    insert_SNAP(temp, result);
//                    free(temp);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

//look up a givin condtition in CPTABLE
CPHASHTABLE* lookup_CP(char* Courses, char* Prerequisite,CPHASHTABLE* TABLE);
CPHASHTABLE* lookup_CP(char* Courses, char* Prerequisite,CPHASHTABLE* TABLE){
    CPHASHTABLE* result = new_CPHASHTABLE();
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkP=true;
    if(*Prerequisite== '*'){checkP=false;}
    if(checkC){
        int index = hashing(Courses);
        CPLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkP==false || strcmp(Prerequisite, (*position)->Prerequisite)==0)){
                CPLIST temp= new_CP((*position)->Courses, (*position)->Prerequisite);
                temp->next=NULL;
                insert_CP(temp, result);
//                free(temp);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return result;
    }else{
        for(int i=0; i<= 1009; i++){
            CPLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkP==false || strcmp(Prerequisite, (*position)->Prerequisite)==0)){
                    CPLIST temp= new_CP((*position)->Courses, (*position)->Prerequisite);
                    temp->next=NULL;
                    insert_CP(temp, result);
//                    free(temp);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

//look up a givin condtition in CDHTABLE
CDHHASHTABLE* lookup_CDH(char* Courses, char* Day, char* Hour,CDHHASHTABLE* TABLE);
CDHHASHTABLE* lookup_CDH(char* Courses, char* Day, char* Hour,CDHHASHTABLE* TABLE){
    CDHHASHTABLE* result = new_CDHHASHTABLE();
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkD=true;
    if(*Day== '*'){checkD=false;}
    bool checkH=true;
    if(*Hour == '*'){checkH=false;}
    if(checkC){
        int index = hashing(Courses);
        CDHLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkD==false || strcmp(Day, (*position)->Day)==0)&&(checkH==false || strcmp(Hour, (*position)->Hour)==0)){
                CDHLIST temp= new_CDH((*position)->Courses, (*position)->Day, (*position)->Hour);
                temp->next=NULL;
                insert_CDH(temp, result);
//                free(temp);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return result;
    }else{
        for(int i=0; i<= 1009; i++){
            CDHLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkD==false || strcmp(Day, (*position)->Day)==0)&&(checkH==false || strcmp(Hour, (*position)->Hour)==0)){
                    CDHLIST temp= new_CDH((*position)->Courses, (*position)->Day, (*position)->Hour);
                    temp->next=NULL;
                    insert_CDH(temp, result);
//                    free(temp);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

//look up a givin condtition in CRTABLE
CRHASHTABLE* lookup_CR(char* Courses, char* Room,CRHASHTABLE* TABLE);
CRHASHTABLE* lookup_CR(char* Courses, char* Room,CRHASHTABLE* TABLE){
    CRHASHTABLE* result = new_CRHASHTABLE();
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkR=true;
    if(*Room== '*'){checkR=false;}
    if(checkC){
        int index = hashing(Courses);
        CRLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkR==false || strcmp(Room, (*position)->Room)==0)){
                CRLIST temp= new_CR((*position)->Courses, (*position)->Room);
                temp->next=NULL;
                insert_CR(temp, result);
//                free(temp);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return result;
    }else{
        for(int i=0; i<= 1009; i++){
            CRLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkR==false || strcmp(Room, (*position)->Room)==0)){
                    CRLIST temp= new_CR((*position)->Courses, (*position)->Room);
                    temp->next=NULL;
                    insert_CR(temp, result);
//                    free(temp);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

//delete a givin tuole from CSGTABLE
CSGHASHTABLE* delete_CSG(char* Courses, int StudentId, char* Grade,CSGHASHTABLE* TABLE);
CSGHASHTABLE* delete_CSG(char* Courses, int StudentId, char* Grade,CSGHASHTABLE* TABLE){
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkS=true;
    if(StudentId==-1){checkS=false;}
    bool checkG=true;
    if(*Grade == '*'){checkG=false;}
    if(checkC){
        int index = hashing(Courses);
        CSGLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkS==false || StudentId==(*position)->StudentId)&&(checkG==false || strcmp(Grade, (*position)->Grade)==0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return TABLE;
    }else{
        for(int i=0; i<= 1009; i++){
            CSGLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkS==false || StudentId==(*position)->StudentId)&&(checkG==false || strcmp(Grade, (*position)->Grade)==0)){
                   *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return TABLE;
    }
}

//delete a givin tuple from SNAPTABLE
SNAPHASHTABLE* delete_SNAP(int StudentId, char* Name, char* Address, char* Phone,SNAPHASHTABLE* TABLE);
SNAPHASHTABLE* delete_SNAP(int StudentId, char* Name, char* Address, char* Phone,SNAPHASHTABLE* TABLE){
    bool checkN =true;
    if(*Name == '*'){checkN=false;}
    bool checkS=true;
    if(StudentId==-1){checkS=false;}
    bool checkA=true;
    if(*Address == '*'){checkA=false;}
    bool checkP=true;
    if(*Phone=='*'){checkP=false;}
    if(checkS){
        char str[10];
        sprintf(str,"%d", StudentId);
        int index = hashing(str);
        SNAPLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Name, (*position)->Name)==0 || checkN==false )&&(StudentId==(*position)->StudentId)
               &&(checkA==false || strcmp(Address, (*position)->Address)==0)&&(checkP==false || strcmp(Phone, (*position)->Phone)==0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return TABLE;
    }else{
        for(int i=0; i<= 1009; i++){
            SNAPLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_SNAP((*position));
                if((strcmp(Name, (*position)->Name)==0 || checkN==false )
                   &&(checkA==false || strcmp(Address, (*position)->Address)==0)&&(checkP==false || strcmp(Phone, (*position)->Phone)==0)){
                *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return TABLE;
    }
}

//delete a givin tuple from CPTABLE
CPHASHTABLE* delete_CP(char* Courses, char* Prerequisite,CPHASHTABLE* TABLE);
CPHASHTABLE* delete_CP(char* Courses, char* Prerequisite,CPHASHTABLE* TABLE){
        bool checkC =true;
        if(*Courses == '*'){checkC=false;}
        bool checkP=true;
        if(*Prerequisite== '*'){checkP=false;}
        if(checkC){
            int index = hashing(Courses);
            CPLIST* position =TABLE[index];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                if((strcmp(Courses, (*position)->Courses)==0)&&(checkP==false || strcmp(Prerequisite, (*position)->Prerequisite)==0)){
                    *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
            
            return TABLE;
        }else{
            for(int i=0; i<= 1009; i++){
                CPLIST* position =TABLE[i];
                while((*position) != NULL){
                    //check if the current tuple is what we are looking for
                    //print_CSG((*position));
                    if((checkP==false || strcmp(Prerequisite, (*position)->Prerequisite)==0)){
                        *position = (*position)->next;
                    }else{
                        position=&(*position)->next;
                    }
                }
            }
            return TABLE;
        }
}

//delete a givin tuple from CDHTABLE
CDHHASHTABLE* delete_CDH(char* Courses, char* Day, char* Hour,CDHHASHTABLE* TABLE);
CDHHASHTABLE* delete_CDH(char* Courses, char* Day, char* Hour,CDHHASHTABLE* TABLE){
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkD=true;
    if(*Day== '*'){checkD=false;}
    bool checkH=true;
    if(*Hour == '*'){checkH=false;}
    if(checkC){
        int index = hashing(Courses);
        CDHLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkD==false || strcmp(Day, (*position)->Day)==0)&&(checkH==false || strcmp(Hour, (*position)->Hour)==0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return TABLE;
    }else{
        for(int i=0; i<= 1009; i++){
            CDHLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkD==false || strcmp(Day, (*position)->Day)==0)&&(checkH==false || strcmp(Hour, (*position)->Hour)==0)){
                    *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return TABLE;
    }
}

//delete a givin tuple from CRTABLE
CRHASHTABLE* delete_CR(char* Courses, char* Room,CRHASHTABLE* TABLE);
CRHASHTABLE* delete_CR(char* Courses, char* Room,CRHASHTABLE* TABLE){
    bool checkC =true;
    if(*Courses == '*'){checkC=false;}
    bool checkR=true;
    if(*Room== '*'){checkR=false;}
    if(checkC){
        int index = hashing(Courses);
        CRLIST* position =TABLE[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if((strcmp(Courses, (*position)->Courses)==0)&&(checkR==false || strcmp(Room, (*position)->Room)==0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return TABLE;
    }else{
        for(int i=0; i<= 1009; i++){
            CRLIST* position =TABLE[i];
            while((*position) != NULL){
                //check if the current tuple is what we are looking for
                //print_CSG((*position));
                if((checkR==false || strcmp(Room, (*position)->Room)==0)){
                    *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return TABLE;
    }
}

////part 2
//void getStudCoursGrade(char* name, char* course){
//    SNAPHASHTABLE* idname = lookup_SNAP("*", name, "*", "*", SNAPTABLE);
//    if(*idname != null) {
//        int id = (*idname)->StudentID;
//    }else{
//        printf("Student doesn't exist");
//    }
//    CSGHASHTABLE* idgrade = lookup_CSG(course, id, "*", CSGTABLE);
//    if(*idgrade != null) {
//        printf(*idgrade->Grade);
//    }else{
//        printf("Student doesn't take that course");
//    }
//}

//void getStudPlace(char* name, char* day, char* hour){
//    SNAPHASHTABLE* idname = lookup_SNAP("*", name, "*", "*", SNAPTABLE);
//    if(*idname != null) {
//        int id = *idname->StudentID;
//    }else{
//        printf("Student doesn't exist");
//    }
//    CSGHASHTABLE* idgrade = lookup_CSG("*", id, "*", Courses-StudentID-Grade);
//    CDHHASHTABLE* timecourse = lookup_CDH("*", day, hour, Courses-Day-Hour);
//    if(*idgrade != null & *timecourse != null) {
//        for(int i = 0; i < (int) (sizeof(timecourse) / sizeof(timecourse[0])) - 1, i++){
//            for(int j = 0; j < (int) (sizeof(idgrade) / sizeof(idgrade[0])) - 1, j++){
//                if(strcmp(*(timecourse + i)->Courses, *(idgrade + j)->Courses) == 0){
//                    CRHASHTABLE* courseroom = lookup_CR(*(idgrade+j)->Courses, "*", Courses-Room);
//                    printf(*courseroom->Room);
//                }
//            }
//        }
//    }
//}else{
//    printf("Student doesn't take a course at that time");
//}
//}





typedef struct CRDH *CRDHLIST;
struct CRDH {
    char Courses[6];
    char Room[31];
    char Day[3];
    char Hour[5];
    CRDHLIST next;
};
typedef CRDHLIST CRDHHASHTABLE[1009];

bool equal_CRDH(CRDHLIST crdh1, CRDHLIST crdh2);
bool equal_CRDH(CRDHLIST crdh1, CRDHLIST crdh2){
    if(strcmp(crdh1->Courses,crdh2->Courses)==0 && strcmp(crdh1->Day,crdh2->Day)==0 && strcmp(crdh1->Hour,crdh2->Hour)==0 && strcmp(crdh1->Room,crdh2->Room)==0){
        return true;
    }
    return false;
}

//initialize a CRDH table
CRDHHASHTABLE* new_CRDHHASHTABLE(void);
CRDHHASHTABLE* new_CRDHHASHTABLE(){
    CRDHHASHTABLE * TABLE = (CRDHHASHTABLE*)malloc(sizeof(CRDHHASHTABLE));
    for(int i=0;i<=1009;i++){
        CRDHLIST * index = TABLE[i];
        (*index)=NULL;
    }
    return TABLE;
}

//print a tuple in CRDH
void print_CRDH(CRDHLIST crdh);
void print_CRDH(CRDHLIST crdh){
    if (crdh != NULL){
        printf("(%s, %s, %s, %s) ", crdh->Courses, crdh->Room, crdh->Day, crdh->Hour);
    }
}


//insert CRDH tuple into CRDHTABLE
CRDHHASHTABLE* insert_CRDH(CRDHLIST crdh, CRDHHASHTABLE* CRDHHASHTABLE);
CRDHHASHTABLE* insert_CRDH(CRDHLIST crdh, CRDHHASHTABLE* CRDHHASHTABLE){
    int index = hashing(crdh->Courses);
    CRDHLIST* position =CRDHHASHTABLE[index];
    while((*position) != NULL){
        if(equal_CRDH(crdh, (*position))){
            printf("CRDH tuple :");
            print_CRDH(crdh);
            printf(" already exists\n");
            return CRDHHASHTABLE;
        }else{
            position=&(*position)->next;
        }
    }
    *position = crdh;
    return CRDHHASHTABLE;
}

//print the table of CRDH
void print_CRDHTable(CRDHHASHTABLE* crdht);
void print_CRDHTable(CRDHHASHTABLE* crdht){
    for(int i=0; i<= 1009; i++){
        CRDHLIST* position =crdht[i];
        while((*position) != NULL){
            print_CRDH(*position);
            printf("\n");
            position=&(*position)->next;
            }
        }
    printf("\n");
}

//new CRDH tuple
CRDHLIST new_CRDH( char* Courses, char* Room, char* Day, char* Hour);
CRDHLIST new_CRDH( char* Courses, char* Room, char* Day, char* Hour){
    CRDHLIST crdh = (CRDHLIST)malloc(sizeof(struct CRDH));
    if(strlen(Courses)>5){
        printf("Wrong Courses length");
    }
    if(strlen(Room)>30){
        printf("Wrong Room length");
    }
    if(strlen(Day)>2){
        printf("Wrong Day length");
    }
    if(strlen(Hour)>4){
        printf("Wrong Hour length");
    }
    strncpy(crdh->Courses,Courses,5);
    crdh->Courses[5]='\0';
    strncpy(crdh->Room,Room,30);
    crdh->Room[30]='\0';
    strncpy(crdh->Day,Day,2);
    crdh->Day[2]='\0';
    strncpy(crdh->Hour, Hour,4);
    crdh->Hour[4]='\0';
    crdh->next= NULL;
    return crdh;
}

//if the CSGTABLE is null return true;
bool NULL_CSGTABLE(CSGHASHTABLE * TABLE);
bool NULL_CSGTABLE(CSGHASHTABLE * TABLE){
    for(int i=0; i<= 1009; i++){
        CSGLIST* position =TABLE[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}

//if the SNAPTABLE is null return true;
bool NULL_SNAPTABLE(SNAPHASHTABLE * TABLE);
bool NULL_SNAPTABLE(SNAPHASHTABLE * TABLE){
    for(int i=0; i<= 1009; i++){
        SNAPLIST* position =TABLE[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}

//if the CPTABLE is null return true;
bool NULL_CPTABLE(CPHASHTABLE * TABLE);
bool NULL_CPTABLE(CPHASHTABLE * TABLE){
    for(int i=0; i<= 1009; i++){
        CPLIST* position =TABLE[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}

//if the CDHTABLE is null return true;
bool NULL_CDHTABLE(CDHHASHTABLE * TABLE);
bool NULL_CDHTABLE(CDHHASHTABLE * TABLE){
    for(int i=0; i<= 1009; i++){
        CDHLIST* position =TABLE[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}

//if the CRTABLE is null return true;
bool NULL_CRTABLE(CRHASHTABLE * TABLE);
bool NULL_CRTABLE(CRHASHTABLE * TABLE){
    for(int i=0; i<= 1009; i++){
        CRLIST* position =TABLE[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}

//if the CRDHTABLE is null return true;
bool NULL_CRDHTABLE(CRDHHASHTABLE * TABLE);
bool NULL_CRDHTABLE(CRDHHASHTABLE * TABLE){
    for(int i=0; i<= 1009; i++){
        CRDHLIST* position =TABLE[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}






//part 2
void getStudCoursGrade(char* name, char* course, SNAPHASHTABLE* SNAP, CSGHASHTABLE* CSG);
void getStudCoursGrade(char* name, char* course, SNAPHASHTABLE* SNAP, CSGHASHTABLE* CSG){
    int id = 0;
    SNAPHASHTABLE* idname = lookup_SNAP(-1, name, "*", "*", SNAP);
    int snaptNull = 1;
    for(int i = 0; i <= 1009; i++){
        SNAPLIST* position = idname[i];
        while((*position) != NULL){
            snaptNull = 0;
            id = (*position)->StudentId;
            position=&(*position)->next;
            break;
        }
    }
    if(snaptNull != 0) {
        printf("Student doesn't exist");
        return;
    }
    CSGHASHTABLE* idgrade = lookup_CSG(course, id, "*", CSG);
    int csgtNull = 1;
    for(int i = 0; i <= 1009; i++){
        CSGLIST* position = idgrade[i];
        while((*position) != NULL){
            csgtNull = 0;
            printf("%s got grade: ", name);
            printf("%s", (*position)->Grade);
            position=&(*position)->next;
            break;
        }
    }
    if(csgtNull != 0) {
        printf("Student doesn't take that course");
    }
}

void getStudPlace(char* name, char* day, char* hour, SNAPHASHTABLE* SNAP, CSGHASHTABLE* CSG, CDHHASHTABLE* CDH, CRHASHTABLE* CR);
void getStudPlace(char* name, char* day, char* hour, SNAPHASHTABLE* SNAP, CSGHASHTABLE* CSG, CDHHASHTABLE* CDH, CRHASHTABLE* CR){
    SNAPHASHTABLE* idname = lookup_SNAP(-1, name, "*", "*", SNAP);
    int id = 0;
    int snaptNull = 1;
    for(int i = 0; i <= 1009; i++){
        SNAPLIST* position = idname[i];
        while((*position) != NULL){
            snaptNull = 0;
            id = (*position)->StudentId;
            position=&(*position)->next;
            break;
        }
    }
    if(snaptNull != 0) {
        printf("Student doesn't exist");
        return;
    }
    CSGHASHTABLE* idgrade = lookup_CSG("*", id, "*", CSG);
    CDHHASHTABLE* timecourse = lookup_CDH("*", day, hour, CDH);
    int csgtNull = 1;
    for(int i = 0; i <= 1009; i++){
        CSGLIST* position = idgrade[i];
        while((*position) != NULL){
            csgtNull = 0;
            position=&(*position)->next;
        }
    }
    int cdhtNull = 1;
    for(int i = 0; i <= 1009; i++){
        CDHLIST* position = timecourse[i];
        while((*position) != NULL){
            cdhtNull = 0;
            position=&(*position)->next;
        }
    }
    if(csgtNull == 0 & cdhtNull == 0) {
        for(int i = 0; i <= 1009; i++) {
            CSGLIST* positionCSG = idgrade[i];
            while((*positionCSG) != NULL) {
                CDHLIST* positionCDHT = timecourse[i];
                while((*positionCDHT) != NULL){
                    if(strcmp((*positionCSG)->Courses, (*positionCDHT)->Courses) == 0){
                        CRHASHTABLE* courseroom = lookup_CR((*positionCDHT)->Courses, "*", CR);
                        for(int i = 0; i <= 1009; i++){
                            CRLIST* position = courseroom[i];
                            while((*position) != NULL){
                                printf("%s is at ", name);
                                printf("%s", (*position)->Room);
                                return;
                            }
                        }
                    }
                    positionCDHT = &(*positionCDHT)->next;
                }
                positionCSG = &(*positionCSG)->next;
            }

        }
    }else{
        printf("Student doesn't take a course at that time");
    }
}


void removeNewLine(char* str);
void removeNewLine(char* str){
    long length= strlen(str);
    if(str[length-1] == '\n'){
        str[length-1] = '\0';
    }
}

void demo_part1(void);
void demo_part1(){
    
    CSGHASHTABLE * CSGTABLE = new_CSGHASHTABLE();
    //part 1.1 Figure 8.1 and 8.2
    //populate the tables with the data given in the figures
    insert_CSG(new_CSG("CS101", 12345, "A"), CSGTABLE);
    insert_CSG(new_CSG("CS101", 67890, "B"), CSGTABLE);
    insert_CSG(new_CSG("EE200", 12345, "C"), CSGTABLE);
    insert_CSG(new_CSG("EE200", 22222, "B+"), CSGTABLE);
    insert_CSG(new_CSG("CS101", 33333, "A-"), CSGTABLE);
    insert_CSG(new_CSG("PH100", 67890, "A+"), CSGTABLE);
    print_CSGTable(CSGTABLE);
    
    SNAPHASHTABLE* SNAPTABLE= new_SNAPHASHTABLE();
    
    insert_SNAP(new_SNAP(12345, "C. Brown", "12 Apple St.", "555-1234"), SNAPTABLE);
    insert_SNAP(new_SNAP(67890, "L. Van Pelt", "34 Pear Ave.", "555-5678"), SNAPTABLE);
    insert_SNAP(new_SNAP(22222, "P. Patty", "56 Grape Blvd.", "555-9999"), SNAPTABLE);
    
    print_SNAPTable(SNAPTABLE);
    
    CPHASHTABLE * CPTABLE =new_CPHASHTABLE();
    
    insert_CP(new_CP("CS101", "CS100"), CPTABLE);
    insert_CP(new_CP("EE200", "EE005"), CPTABLE);
    insert_CP(new_CP("EE200", "CS100"), CPTABLE);
    insert_CP(new_CP("CS120", "CS101"), CPTABLE);
    insert_CP(new_CP("CS121", "CS120"), CPTABLE);
    insert_CP(new_CP("CS205", "CS101"), CPTABLE);
    insert_CP(new_CP("CS206", "CS121"), CPTABLE);
    insert_CP(new_CP("CS206", "CS205"), CPTABLE);
    
    print_CPTable(CPTABLE);
    
    CDHHASHTABLE * CDHTABLE =new_CDHHASHTABLE();
    insert_CDH(new_CDH("CS101", "M", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("CS101", "W", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("CS101", "F", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "Tu", "10AM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "W", "1PM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "Th", "10AM"), CDHTABLE);
    
    print_CDHTable(CDHTABLE);
    
    CRHASHTABLE * CRTABLE = new_CRHASHTABLE();
    
    insert_CR(new_CR("CS101", "Turing Aud."), CRTABLE);
    insert_CR(new_CR("EE200", "25 Ohm Hall"), CRTABLE);
    insert_CR(new_CR("PH100", "Newton Lab."), CRTABLE);
    
    print_CRTable(CRTABLE);
    
    printf("\nDemostrating Part1\n\n");
    printf("Example 8.2:\n\n\n");
    
    printf("The result for lookup_CSG(\"CS101\", 12345, \"*\", CSGTABLE) is: ");
    print_CSGTable(lookup_CSG("CS101", 12345, "*", CSGTABLE));
    
    
    printf("The result for lookup_CP(\"CS205\", \"CS120\", CPTABLE) is: ");
    if(NULL_CPTABLE(lookup_CP("CS205", "CS120", CPTABLE))){
        printf("Empty.\n\n");
    }else{
        print_CPTable(lookup_CP("CS205", "CS120", CPTABLE));
    }
    
    printf("Table before remove: ");
    print_CRTable(CRTABLE);
    printf("Table after delete_CR(\"CS101\", \"*\", CRTABLE) is: ");
    print_CRTable(delete_CR("CS101", "*", CRTABLE));
    
    
    printf("Table before insert: ");
    print_CPTable(CPTABLE);
    printf("Table after (insert_CP(new_CP(\"CS205\", \"CS120\"), CPTABLE)) is: ");
    print_CPTable(insert_CP(new_CP("CS205", "CS120"), CPTABLE));
    
    printf("Table before insert: ");
    print_CPTable(CPTABLE);
    printf("Table after (insert_CP(new_CP(\"CS205\", \"CS120\"), CPTABLE)) is: \n");
    print_CPTable(insert_CP(new_CP("CS205", "CS120"), CPTABLE));
    
    free(CSGTABLE);
    free(SNAPTABLE);
    free(CPTABLE);
    free(CRTABLE);
    free(CDHTABLE);
}

void demo_part2(void);
void demo_part2(){
    CSGHASHTABLE * CSGTABLE = new_CSGHASHTABLE();
    insert_CSG(new_CSG("CS101", 12345, "A"), CSGTABLE);
    insert_CSG(new_CSG("CS101", 67890, "B"), CSGTABLE);
    insert_CSG(new_CSG("EE200", 12345, "C"), CSGTABLE);
    insert_CSG(new_CSG("EE200", 22222, "B+"), CSGTABLE);
    insert_CSG(new_CSG("CS101", 33333, "A-"), CSGTABLE);
    insert_CSG(new_CSG("PH100", 67890, "A+"), CSGTABLE);
    print_CSGTable(CSGTABLE);
    
    SNAPHASHTABLE* SNAPTABLE= new_SNAPHASHTABLE();
    
    insert_SNAP(new_SNAP(12345, "C. Brown", "12 Apple St.", "555-1234"), SNAPTABLE);
    insert_SNAP(new_SNAP(67890, "L. Van Pelt", "34 Pear Ave.", "555-5678"), SNAPTABLE);
    insert_SNAP(new_SNAP(22222, "P. Patty", "56 Grape Blvd.", "555-9999"), SNAPTABLE);
    
    print_SNAPTable(SNAPTABLE);
    
    CPHASHTABLE * CPTABLE =new_CPHASHTABLE();
    
    insert_CP(new_CP("CS101", "CS100"), CPTABLE);
    insert_CP(new_CP("EE200", "EE005"), CPTABLE);
    insert_CP(new_CP("EE200", "CS100"), CPTABLE);
    insert_CP(new_CP("CS120", "CS101"), CPTABLE);
    insert_CP(new_CP("CS121", "CS120"), CPTABLE);
    insert_CP(new_CP("CS205", "CS101"), CPTABLE);
    insert_CP(new_CP("CS206", "CS121"), CPTABLE);
    insert_CP(new_CP("CS206", "CS205"), CPTABLE);
    
    print_CPTable(CPTABLE);
    
    CDHHASHTABLE * CDHTABLE =new_CDHHASHTABLE();
    insert_CDH(new_CDH("CS101", "M", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("CS101", "W", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("CS101", "F", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "Tu", "10AM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "W", "1PM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "Th", "10AM"), CDHTABLE);
    
    print_CDHTable(CDHTABLE);
    
    CRHASHTABLE * CRTABLE = new_CRHASHTABLE();
    
    insert_CR(new_CR("CS101", "Turing Aud."), CRTABLE);
    insert_CR(new_CR("EE200", "25 Ohm Hall"), CRTABLE);
    insert_CR(new_CR("PH100", "Newton Lab."), CRTABLE);
    
    print_CRTable(CRTABLE);
    
    //test part 2
    
    printf("\nDemostrating Part2\n\n\n");
    
    
    char input1[256];
    char input2[256];
    char input3[256];
    do {
        printf("What grade did StudentName get in CourseName?\nEnter: StudentName (\"quit\" to quit): ");
        fgets(input1, 255, stdin);
        removeNewLine(input1);
        if(strcmp(input1,"quit")!=0){
            printf("Enter: CourseName: ");
            fgets(input2, 255, stdin);
            removeNewLine(input2);
            getStudCoursGrade(input1, input2, SNAPTABLE,CSGTABLE);
            printf(" in %s\n\n", input2);
        }
    } while(strcmp(input1,"quit")!=0);
    
    printf("\n\n");
    
    do {
        printf("Where is StudentName at Time on Day?\nEnter: StudentName (\"quit\" to quit): ");
        fgets(input1, 255, stdin);
        removeNewLine(input1);
        if(strcmp(input1,"quit")!=0){
            printf("Enter: Time: ");
            fgets(input2, 255, stdin);
            removeNewLine(input2);
            printf("Enter: Day: ");
            fgets(input3, 255, stdin);
            removeNewLine(input3);
            getStudPlace(input1, input3, input2,SNAPTABLE,CSGTABLE,CDHTABLE,CRTABLE);
            printf(" at %s on %s\n\n", input2, input3);
        }
    }while(strcmp(input1,"quit")!=0);
    free(CSGTABLE);
    free(SNAPTABLE);
    free(CPTABLE);
    free(CRTABLE);
    free(CDHTABLE);
}

//part3
//Example 8.12
void select_CSG(char* course, CSGHASHTABLE* CSG);
void select_CSG(char* course, CSGHASHTABLE* CSG){
    print_CSGTable(lookup_CSG(course, -1, "*", CSG));
}

//Example 8.13
void projection_CSG(char* course, CSGHASHTABLE* CSG);
void projection_CSG(char* course, CSGHASHTABLE* CSG){
    CSGHASHTABLE* csgt = lookup_CSG(course, -1, "*", CSG);
    int csgtNull = 1;
    for(int i = 0; i <= 1009; i++){
        CSGLIST* position = csgt[i];
        while((*position) != NULL){
            csgtNull = 0;
            printf("%d \n", (*position)->StudentId);
            position=&(*position)->next;
        }
    }
    if(csgtNull == 1){
        printf("Wrong projection");
    }
}

CRDHHASHTABLE* join_CRDH(CDHHASHTABLE* CDH, CRHASHTABLE* CR);
CRDHHASHTABLE* join_CRDH(CDHHASHTABLE* CDH, CRHASHTABLE* CR){
    CRDHHASHTABLE * CRDH = new_CRDHHASHTABLE();
    int cdhtNull = 1;
    int crtNull = 1;
    for(int i = 0; i < 1009; i++){
        CDHLIST* positionCDH = CDH[i];
        while((*positionCDH) != NULL){
            cdhtNull = 0;
            CRLIST* positionCR = CR[i];
            while((*positionCR) != NULL){
                crtNull = 0;
                if(strcmp((*positionCDH)->Courses, (*positionCR)->Courses) == 0){
                    insert_CRDH(new_CRDH((*positionCDH)->Courses, (*positionCR)->Room, (*positionCDH)->Day, (*positionCDH)->Hour), CRDH);
                }
                positionCR=&(*positionCR)->next;
            }
            positionCDH=&(*positionCDH)->next;
        }
    }
    if(cdhtNull == 1 || crtNull == 1){
        printf("Wrong join");
    }
    return CRDH;
}

//Example 8.15
void allthree(CDHHASHTABLE* CDH, CRHASHTABLE* CR);
void allthree(CDHHASHTABLE* CDH, CRHASHTABLE* CR){
    CRDHHASHTABLE * crdht = join_CRDH(CDH,CR);
    int crdhtNull = 1;
    for(int i = 0; i < 1009; i++){
        CRDHLIST* position = crdht[i];
        while((*position) != NULL){
            crdhtNull = 0;
            if(strcmp((*position)->Room, "Turing Aud.") == 0){
                printf("(%s, %s) \n", (*position)->Day, (*position)->Hour);
            }
            position=&(*position)->next;
        }
    }
    if(crdhtNull == 1){
        printf("Wrong allthree");
    }
}

void demo_part3(void);
void demo_part3(){
    CSGHASHTABLE * CSGTABLE = new_CSGHASHTABLE();
    insert_CSG(new_CSG("CS101", 12345, "A"), CSGTABLE);
    insert_CSG(new_CSG("CS101", 67890, "B"), CSGTABLE);
    insert_CSG(new_CSG("EE200", 12345, "C"), CSGTABLE);
    insert_CSG(new_CSG("EE200", 22222, "B+"), CSGTABLE);
    insert_CSG(new_CSG("CS101", 33333, "A-"), CSGTABLE);
    insert_CSG(new_CSG("PH100", 67890, "A+"), CSGTABLE);
    print_CSGTable(CSGTABLE);
    
    CDHHASHTABLE * CDHTABLE =new_CDHHASHTABLE();
    insert_CDH(new_CDH("CS101", "M", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("CS101", "W", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("CS101", "F", "9AM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "Tu", "10AM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "W", "1PM"), CDHTABLE);
    insert_CDH(new_CDH("EE200", "Th", "10AM"), CDHTABLE);
    print_CDHTable(CDHTABLE);
    
    CRHASHTABLE * CRTABLE = new_CRHASHTABLE();
    insert_CR(new_CR("CS101", "Turing Aud."), CRTABLE);
    insert_CR(new_CR("EE200", "25 Ohm Hall"), CRTABLE);
    insert_CR(new_CR("PH100", "Newton Lab."), CRTABLE);
    print_CRTable(CRTABLE);
    
    printf("\nDemostrating Part3\n\n");
    printf("Example 8.12. : \n\n");
    
    printf("Table of select_CSG(\"CS101\",CSGTABLE) is: ");
    select_CSG("CS101",CSGTABLE);
    
    printf("Example 8.13. : \n\n");
    printf("Table of projection on StudentId where course is \"CS101\" in CSGTABLE: \nStudentId\n");
    projection_CSG("CS101", CSGTABLE);
    
    printf("\nExample 8.14. : \n\n");
    printf("CRDHTable of join CDHTABLE and CRTABLE is:\n");
    print_CRDHTable(join_CRDH(CDHTABLE, CRTABLE));
    
    printf("\nExample 8.15. : \n\n");
    printf("Table of all three is \n");
    allthree(CDHTABLE, CRTABLE);
    free(CSGTABLE);
    free(CDHTABLE);
    free(CRTABLE);
}
int main(void) {
    
    demo_part1();
    demo_part2();
    demo_part3();
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

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
    if(strlen(Room)>5){
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
    char* str= NULL;
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
        char* str= NULL;
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
CRHASHTABLE* lookup_CR(char* Courses, char* Room, char* Hour,CRHASHTABLE* TABLE);
CRHASHTABLE* lookup_CR(char* Courses, char* Room, char* Hour,CRHASHTABLE* TABLE){
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
        char* str= NULL;
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
CRHASHTABLE* delete_CR(char* Courses, char* Room, char* Hour,CRHASHTABLE* TABLE);
CRHASHTABLE* delete_CR(char* Courses, char* Room, char* Hour,CRHASHTABLE* TABLE){
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

//part 2
void getStudCoursGrade(char* name, char* course){
	SNAPHASHTABLE* idname = lookup_SNAP("*", name, "*", "*", StudentID-Name-Address-Phone);
	if(*idname != null) {
		int id = *idname->StudentID;
	}else{
		printf("Student doesn't exist");
	}
	CSGHASHTABLE* idgrade = lookup_CSG(course, id, "*", Courses-StudentID-Grade);
	if(*idgrade != null) {
		printf(*idgrade->Grade);
	}else{
		printf("Student doesn't take that course");
	}
}
	
void getStudPlace(char* name, char* day, char* hour){
	SNAPHASHTABLE* idname = lookup_SNAP("*", name, "*", "*", StudentID-Name-Address-Phone);
	if(*idname != null) {
		int id = *idname->StudentID;
	}else{
		printf("Student doesn't exist");
	}
	CSGHASHTABLE* idgrade = lookup_CSG("*", id, "*", Courses-StudentID-Grade);
	CDHHASHTABLE* timecourse = lookup_CDH("*", day, hour, Courses-Day-Hour);
	if(*idgrade != null & *timecourse != null) {
		for(int i = 0; i < (int) (sizeof(timecourse) / sizeof(timecourse[0])) - 1, i++){
			for(int j = 0; j < (int) (sizeof(idgrade) / sizeof(idgrade[0])) - 1, j++){
				if(strcmp(*(timecourse + i)->Courses, *(idgrade + j)->Courses) == 0){
					CRHASHTABLE* courseroom = lookup_CR(*(idgrade+j)->Courses, "*", Courses-Room);
					printf(*courseroom->Room);
					}
				}
			}
		}
	}else{
		printf("Student doesn't take a course at that time");
	}
}

//part3
//Example 8.12
void select_CSG(char* course){
	print_CSGTable(lookup_CSG(course, "*", "*", Courses-StudentID-Grade));
}

//Example 8.13
void projection_CSG(char* course){
	CSGHASHTABLE* csgt = lookup_CSG(course, "*", "*", Courses-StudentID-Grade);
	if(*csgt != null){
		for(int i = 0; i < (int)(sizeof(csgt)/sizeof(csgt[0])) - 1; i++){
			printf(%s" ",*(csgt + i)->StudentID)
			
			;
		}
	}
}

//Example 8.14
typedef struct CRDH *CRDHLIST;
struct CRDH {
    char Courses[6];
    char Room[31];
    char Day[3];
    char Hour[5];
    CRDHLIST next;
};
typedef CRDHLIST CRDHHASHTABLE[1009];

//compare two CRDH tuple if they are same or not
bool equal_CRDH(CRDHLIST crdh1, CRDHLIST crdh2);
bool equal_CRDH(CRDHLIST crdh1, CRDHLIST crdh2){
    if(strcmp(crdh1->Courses,crdh2->Courses)==0 && strcmp(crdh1->Day,crdh2->Day)==0 && strcmp(crdh1->Hour,crdh2->Hour)==0
       && strcmp(crdh1->Room,crdh2->Room)==0){
        return true;
    }
    return false;
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
    for(int i = 0; i <= 1009; i++){
        CRDHLIST* position = crdht[i];
        while((*position) != NULL){
            print_CRDH(*position);
            printf("\n");
            position = &(*position)->next;
            }
        }
    printf("\n");
}

void join_CRDH(){
	CRDHTable crdht = null;
	for(int i = 0; i < 1009; i++){
		for(int j = 0; j < 1009; j++){
			if (cdht[i] != NULL & cr[j] != NULL){
				if(strcmp(cdht[i]->Courses, cr[j]->Courses) == 0){
					insert_CRDH(new_CRDH(cdht[i]->Courses, cr[j]->Room, cdht[i]->Day, cdht[i]->Hour), crdht);
				}
			}
        }
    }
	print_CRDHTable(crdht);
}

//Example 8.15
void allthree(){
	CRDHHASHTABLE crdht = join_CRDH();
	for(int i = 0; i < 1009; i++){
		if(crdht[i] != null){
			if(strcmp(crdht[i]->Room, "Turing Aud.") == 0){
				printf("(%s, %s) ", crdht[i]->Day, crdht[i]->Hour);
			}
		}
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

	//test part 2
	char input1[256];
	char input2[256];
	char input3[256];
	do {
    		printf("What grade did StudentName get in CourseName? Enter: StudentName (\"quit\" to quit): ");
    		fgets(input1, 255, stdin);
    		removeNewLine(input1);
    		if(strcmp(input1,"quit")!=0){
			printf("Enter: CourseName: ");
			fgets(input2, 255, stdin);
			removeNewLine(input2);
			printf("%s got grade , input1");
			getStudCoursGrade(input1, input2);
			printf(" in %s\n, input2");
        		}
    		}
	} while(strcmp(input1,"quit")!=0);

	do {
    		printf("Where is StudentName at Time on Day? Enter: StudentName (\"quit\" to quit): ");
    		fgets(input1, 255, stdin);
    		removeNewLine(input1);
    		if(strcmp(input1,"quit")!=0){
			printf("Enter: Time: ");
			fgets(input2, 255, stdin);
			removeNewLine(input2);
			printf("Enter: Day: ");
			fgets(input3, 255, stdin);
			removeNewLine(input3);
			printf("%s is at , input1");
			getStudPlace(input1, input2, input3);
			printf(" at %s on %s\n, input2, input3");
        		}
    		}
	} while(strcmp(input1,"quit")!=0);
	
	return 0;
}

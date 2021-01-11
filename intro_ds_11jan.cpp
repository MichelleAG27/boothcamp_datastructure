#include<stdio.h> // untuk i/o
#include<stdlib.h> // strcpy
#include<string.h> //memory allocation

struct Kursus{
char ID[10]; // 10 bytes
int nilai; // int = 4 bytes
// total 14 byte
};

struct Student{
char name [255]; //255 bytes
double GPA; //8 bytes
Kursus les; // as object
};


//const char *name sama dengan char name[], bedanya kalau pakai [] di vscode akan dapat warning
Student *createStudent(const char *name, double GPA, const char *ID,  int nilai){

// memory allocation
Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name); // sama kek strcpy((*newStudent).name, name);
    newStudent->GPA = GPA; // sama kek (*newStudent).GPA = GPA;
    strcpy(newStudent->les.ID, ID); //sama kek strcpy((*newStudent).les.ID, ID);
    newStudent->les.nilai = nilai; //sama kek (*newStudent),nilai = nilai;
    return newStudent;


// (*newStudent).atributnya sama saja dengan newStudent->atributnya

}

void removeStudent(Student *s){
    free(s);  // free allocated memory from malloc
    s = NULL; // protect against dangling pointer
}

//tipe data yang di return :Student*
//nama function : createstudent
//parameter: name, gpa, kursus (id dan nilai)

void printStudent(Student *s){
    printf("Name: %s\n", s->name);
    printf("GPA: %lf\n", s->GPA);
    printf("Course ID: %s\n", s->les.ID);
    printf("Score: %d\n", s->les.nilai);
}
int main()
{
    //Student students[10]; //static memory allocation
    // Student dummy;
    // isi dummy.name, dummy.gpa;
    // createstudent(dummy);

    //s1 mengarah ke student yang diarahkan oleh createstudent
 Student *s1 = createStudent("Budi", 3.90, "COMP6048", 100);
 Student *s2 = createStudent("Abdul", 4.00, "COMP6049", 85);
  printf("Before Remove : \n");
    
    printStudent(s1);
    removeStudent(s1);
    printf("After Remove : \n");
    printStudent(s1);//Print setelah remove termasuk undefined behaviour, mengakses memori ilegal
    // NOTE: Jangan print nilai yg udh di free.
    return 0;

}

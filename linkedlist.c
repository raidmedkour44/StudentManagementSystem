#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int age;
    float moyenne;
    char nom[50];
    struct student *suivant;
} student;
student *creatstudent(int age, float moyenne, char nom[])
{
    student *nouvs = (student *)malloc(sizeof(student));
    nouvs->age = age;
    nouvs->moyenne = moyenne;
    strcpy(nouvs->nom, nom);
    nouvs->suivant = NULL;
    return nouvs;
}
int main()
{
    student *tete;
    student *premier = creatstudent(20, 15.5, "John");
    student *dexieume = creatstudent(12, 14.3, "raid");
    student *fin = creatstudent(15, 12.8, "ahmed");
    tete = premier;
    premier->suivant = dexieume;
    dexieume->suivant = fin;
    fin->suivant = NULL;
    printf("%d", tete->age);
    return 0;
}
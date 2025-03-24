#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char name[50];
    int age;
    float moyenne;
    struct student *suivant;
} student;
void afficherstudent(student *tete)
{
    student *counter = tete;
    if (counter == NULL)
    {
        printf("Ther is no student right now\n");
    }
    while (counter != NULL)
    {
        printf("The name of student is: %s,the age of student is: %d,the moyenne of student is: %0.2f\n", counter->name, counter->age, counter->moyenne);
        counter = counter->suivant;
    }
}
int taill(student *tete)
{
    int T = 0;
    student *counter = tete;
    while (counter != NULL)
    {
        counter = counter->suivant;
        T++;
    }
    return T;
}
student *searchstudent(student *tete, char name[])
{
    student *counter = tete;
    while (counter != NULL)
    {
        if (strcmp(counter->name, name) == 0)
        {
            return counter;
        }
        counter = counter->suivant;
    }
    return NULL;
}
student *ajouterstudentaudebut(student *tete, char name[], int age, float moyenne)
{
    student *nouvs = (student *)malloc(sizeof(student));
    strcpy(nouvs->name, name);
    nouvs->age = age;
    nouvs->moyenne = moyenne;
    nouvs->suivant = NULL;
    if (tete != NULL)
    {
        nouvs->suivant = tete;
    }
    tete = nouvs;
    return tete;
}
student *addstudent(student *tete, int id, char firstname[], char lastname[], int BirthDate, char address[], int mobile, char email[], int parentContact)
{
    student *counter = tete;
    student *nouvs = (student *)malloc(sizeof(student));
    nouvs->id = id;
    nouvs->suivant = NULL;
    if (tete == NULL)
    {
        return nouvs;
    }
    while (counter->suivant != NULL)
    {
        counter = counter->suivant;
    }
    counter->suivant = nouvs;
    return tete;
}

int main()
{
    student *L = NULL;
    int o;
    do
    {
        printf("Enter number of operation you want: ");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            int id;
            char firstName[30];
            char lastname[30];
            char birthDate[15];
            char address[100];
            int mobile;
            char email[50];
            int parentContact;

            L = addstudent(L, id, firstName, lastname, birthDate, address, mobile, email, parentContact);
            break;
        case 2:
            afficherstudent(L);
            break;
        default:
            printf("Veuillez choisir une option valide\n");
        }
    } while (o <= 2 && o >= 1);
    return 0;
}
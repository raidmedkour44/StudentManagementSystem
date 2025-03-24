#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int id;
    char firstname[30];
    char lastname[30];
    int birthdate;
    char address[100];
    int mobile;
    char email[50];
    int parentContact;
    char modulesname[1][50];
    float modulesinformation[1][6];
    struct student *suivant;
} student;
student *addstudent(student *tete, int id, char firstname[], char lastname[], int birthdate, char address[], int mobile, char email[], int parentContact, char modulesname[1][50], float modulesinformation[1][6])
{
    student *counter = tete;
    student *nouvs = (student *)malloc(sizeof(student));
    printf("Enter Student id: ");
    scanf("%d", &nouvs->id);
    printf("Enter First Name: ");
    scanf("%s", nouvs->firstname);
    printf("Enter Last Name: ");
    scanf("%s", nouvs->lastname);
    printf("Enter Birth Date : ");
    scanf("%d", &nouvs->birthdate);
    printf("Enter Address: ");
    scanf(" %[^\n]", nouvs->address);
    //%[^\n] we us it to allow space when user put address like ain benian
    printf("Enter Mobile: ");
    scanf("%d", &nouvs->mobile);
    printf("Enter Email: ");
    scanf("%s", nouvs->email);
    printf("Enter Parent Contact: ");
    scanf("%d", &nouvs->parentContact);
    for (int i = 0; i < 2; i++)
    {
        printf("Enter module %d name: ", i + 1);
        scanf(" %[^\n]", nouvs->modulesname[i]);
        printf("Enter Module Average: ");
        scanf("%f", &nouvs->modulesinformation[i][0]);
        printf("Enter Coefficient: ");
        scanf("%f", &nouvs->modulesinformation[i][1]);
        printf("Enter Final Exam note: ");
        scanf("%f", &nouvs->modulesinformation[i][2]);
        printf("Enter Midterm note: ");
        scanf("%f", &nouvs->modulesinformation[i][3]);
        printf("Enter Labs note: ");
        scanf("%f", &nouvs->modulesinformation[i][4]);
        printf("Enter Continuous Evaluation note: ");
        scanf("%f", &nouvs->modulesinformation[i][5]);
    }
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
student *searchstudent(student *tete, char firstname[])
{
    student *counter = tete;
    printf("Enter name student you want to find: ");
    scanf("%s", firstname);
    while (counter != NULL)
    {
        if (strcmp(counter->firstname, firstname) == 0)
        {
            return counter;
        }
        counter = counter->suivant;
    }
    return NULL;
}
student *searchstudentbyid(student *tete, int id)
{
    student *counter = tete;
    printf("Enter id of student you want to find: ");
    scanf("%d", &id);
    while (counter != NULL)
    {
        if (counter->id == id)
        {
            return counter;
        }
        counter = counter->suivant;
    }
    return NULL;
}
student *searchstudentbyEmail(student *tete, char email[])
{
    student *counter = tete;
    printf("Enter email of student you want to find: ");
    scanf("%s", email);
    while (counter != NULL)
    {
        if (strcmp(counter->email, email) == 0)
        {
            return counter;
        }
        counter = counter->suivant;
    }
    return NULL;
}
void displaystudent(student *tete)
{
    student *counter = tete;
    char firstname[30];
    char email[50];
    int id;
    student *L = NULL;
    if (counter == NULL)
    {
        printf("Student not found\n");
        return;
    }

    printf("1-search for student by firstname");
    printf("2-search for student by id");
    printf("3-search for student by email");
    int c;
    printf("Enter method of search you want: ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        counter = searchstudent(tete, firstname);
        break;
    case 2:
        counter = searchstudentbyid(tete, id);
        break;
    case 3:
        counter = searchstudentbyEmail(tete, email);
        break;
    default:
        printf("Erorr put valid number ");
    }
    float Sum = 0;
    float SumofCoefficients = 0;

    for (int i = 0; i < 1; i++)
    {
        Sum += counter->modulesinformation[i][0] * counter->modulesinformation[i][1];
        SumofCoefficients += counter->modulesinformation[i][1];
    }

    float generalAverage;
    if (SumofCoefficients == 0)
    {
        generalAverage = 0;
    }
    else
    {
        generalAverage = Sum / SumofCoefficients;
    }

    char grade[20];
    if (generalAverage >= 18)
    {
        printf("Excellent");
    }
    else if (generalAverage >= 15)
    {
        printf("Very Good");
    }
    else if (generalAverage >= 12)
    {
        printf("Good");
    }
    else if (generalAverage >= 10)
    {
        printf("PASS");
    }
    else
    {
        printf("FAIL");
    }
    char specialization[50];
    if (generalAverage >= 15)
    {
        printf("Eligible for Artificial Intelligence");
    }
    else if (generalAverage >= 10)
    {
        printf("Eligible for Network and Security");
    }
    else
    {
        printf("Ther no specializatio available");
    }
    if (counter != NULL)
    {
        printf("The student named %s  is here \n", firstname);
        printf("and this are all information about this student:");
        printf("Id: %d\nFirst name: %s\nLast name: %s\nBirth date: %d\n Address: %s\nMobile: %d\nEmail: %s\nParentcontact: %d\n", counter->id, counter->firstname, counter->lastname, counter->birthdate, counter->address, counter->mobile, counter->email, counter->parentContact);
        for (int i = 0; i < 2; i++)
        {
            printf("%s ,Avg: %.2f ,Coef:%d ,Final: %.2f,Mid: %.2f,Labs: %.2f,Eval: %.2f\n",
                   counter->modulesname[i], counter->modulesinformation[i][0], counter->modulesinformation[i][1],
                   counter->modulesinformation[i][2], counter->modulesinformation[i][3],
                   counter->modulesinformation[i][4], counter->modulesinformation[i][5]);
            float GeneralAverage;
        }
    }
    else
    {
        printf("The student with this %s is not here ", email);
    }
}
student *deletstudent(student *tete, int id)
{
    student *counter = tete;
    student *P = NULL;
    if (tete == NULL)
    {
        printf("Ther is no student in the list\n");
        return tete;
    }
    if (tete->id == id)
    { // if the student in the begin of the list
        student *temp = tete;
        tete = tete->suivant;
        free(temp);
        printf("student deleted");
        return tete;
    }
    while (counter != NULL && counter->id != id)
    {
        P = counter;
        counter = counter->suivant;
    }
    if (counter == NULL)
    {
        printf("Student not found\n");
        return tete;
    }

    P->suivant = counter->suivant;
    free(counter);
    printf("Student deleted \n");
    return tete;
}
student *modifistudent(student *tete, int id)
{
    student *counter = tete;
    printf("Enter the iD of the student: ");
    scanf("%d", &id);

    while (counter != NULL)
    {
        if (counter->id == id)
        {
            printf("write new informations\n");
            printf("Enter First Name: ");
            scanf("%s", counter->firstname);
            printf("Enter Last Name: ");
            scanf("%s", counter->lastname);

            printf("Enter Birth Date: ");
            scanf("%d", &counter->birthdate);

            printf("Enter Address: ");
            scanf(" %[^\n]", counter->address);

            printf("Enter Mobile: ");
            scanf("%d", &counter->mobile);

            printf("Enter Email: ");
            scanf("%s", counter->email);

            printf("Enter Parent Contact: ");
            scanf("%d", &counter->parentContact);

            for (int i = 0; i < 8; i++)
            {
                printf("Enter module %d name: ", i + 1);
                scanf(" %[^\n]", counter->modulesname[i]);

                printf("Enter Module Average: ");
                scanf("%f", &counter->modulesinformation[i][0]);

                printf("Enter Coefficient: ");
                scanf("%d", &counter->modulesinformation[i][1]);

                printf("Enter Final Exam note: ");
                scanf("%f", &counter->modulesinformation[i][2]);

                printf("Enter Midterm note: ");
                scanf("%f", &counter->modulesinformation[i][3]);

                printf("Enter Labs note: ");
                scanf("%f", &counter->modulesinformation[i][4]);

                printf("Enter Continuous Evaluation note: ");
                scanf("%f", &counter->modulesinformation[i][5]);
            }

            printf(" information updated\n");
            return tete;
        }
        counter = counter->suivant;
    }

    printf("Student not found\n", id);
    return tete;
}
void menu()
{
    student *L = NULL;
    student *counter = L;
    int o;
    int id;
    char firstname[30];
    char lastname[30];
    int birthdate;
    char address[100];
    int mobile;
    char email[50];
    int parentContact;
    char modulesname[8][50];
    float modulesinformation[8][6];
    do
    {
        printf("1-addstudent\n");
        printf("2-displaystudent\n");
        printf("3-deleteStudent\n");
        printf("4-modify information of student\n");
        printf("Enter number of operation you want: ");
        scanf("%d", &o);
        switch (o)
        {
        case 0:
            printf("Exit");
            return;
        case 1:

            L = addstudent(L, id, firstname, lastname, birthdate, address, mobile, email, parentContact, modulesname, modulesinformation);
            break;
        case 2:
            displaystudent(L);
            break;
        case 3:
            printf("Enter the ID of the student to delete: ");
            scanf("%d", &id);
            L = deletstudent(L, id);
            break;
        case 4:
            L = modifistudent(L, id);
            break;
        default:
            printf("Veuillez choisir une option valide\n");
        }
    } while (o != 0);
}
int main()
{
    menu();
    return 0;
}
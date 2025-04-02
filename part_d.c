#include <stdio.h>
#include <stdlib.h>
#include <string.h> //include string header file

//constants
const int NO_OF_STUDENT_RECORDS = 10;

//enumu
enum mainMenuOptions
{
    ADD = 1,
    EDIT,
    DELETE_LAST_RECORD,
    PRINT_STUDENT_RESULTS,
    PRINT_COURSE_SUMMARY,
    LOAD_DATA,
    SAVE_DATA,
    EXIT,
};
//---

//structure
struct StudentDataRecord
{
    char indexNo[20];
    int maths;
    int physics;
    int chemistry;
    float average;
    char grade;
};
//---

//function declaration
int displayMainMenu();
void mainMenuHandler();

void loadData();
void saveData();

int isArrayFull(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
char findGrade(float avgMark);
void addNewRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
//----

//----
int main()
{
    //Function call
    mainMenuHandler();

    return 0;
}
//----

//function definition
int displayMainMenu()
{
    int mainMenuChoice;

    printf("\n\t\t========================\n");
    printf("\t\t Main Menu \n");
    printf("\t\t========================\n");
    printf("\n");
    printf("(1) Add \n");
    printf("(2) Edit \n");
    printf("(3) Delete Last Record \n");
    printf("(4) Print Student Results \n");
    printf("(5) Print Course Summary \n");
    printf("(6) Load Data \n");
    printf("(7) Save Data \n");
    printf("(8) Exit \n");

    printf("\nEnter your choice : ");
    scanf("%d", &mainMenuChoice);

    return mainMenuChoice;
}
//----

void mainMenuHandler()
{
    //Defining an array of structures with type of StudentDataRecord
    struct StudentDataRecord studentDataArr[NO_OF_STUDENT_RECORDS];
    int number_of_records = 0;

    //menu functions
    int mainMenuOption;

    do
    {
        mainMenuOption = displayMainMenu();

        switch(mainMenuOption)
        {
        case ADD :
            addNewRecord(&number_of_records, studentDataArr);
            break;

        case EDIT :
            printf("option -02 \n");
            break;

        case DELETE_LAST_RECORD :
            printf("option -03 \n");
            break;

        case PRINT_STUDENT_RESULTS :
            printf("option -04 \n");
            break;

        case PRINT_COURSE_SUMMARY :
            printf("option -05 \n");
            break;

        case LOAD_DATA :
            loadData();
            break;

        case SAVE_DATA :
            saveData();
            break;

        case EXIT :
            printf("\nExiting...\n");
            break;

        default:
            printf("Invalid menu choice! \n");
        }
    }
    while(mainMenuOption != EXIT);
}
//----

//----
void loadData()
{
    printf("option -06 \n");
}
//----

//----
void saveData()
{
    printf("option -07 \n");
}
//----

//----
int isArrayFull(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS])
{
    if(*arrExistingElementCountPtr == NO_OF_STUDENT_RECORDS)
    {
        return -1; // No empty space found
    }
    else
    {
        return *arrExistingElementCountPtr; // Return the index of the first empty slot
    }
}
//----

//----
char findGrade(float avgMark){
    char grade;

    if(avgMark >= 75){
        grade = 'A';
    }
    else if(avgMark >= 65){
        grade = 'B';
    }
    else if(avgMark >= 55){
        grade = 'C';
    }
    else if(avgMark >= 50){
        grade = 'S';
    }
    else{
        grade = 'F';
    }

    return grade;
}
//----

//----
void addNewRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS])
{
    int vacantArrayIndex;

    char indexNo[20];
    int maths, physics, chemistry;
    float average;

    char userFeedback;

    do
    {
        //check whether array has a vacant spot or not
        vacantArrayIndex = isArrayFull(arrExistingElementCountPtr, arr);

        if(vacantArrayIndex != -1)
        {
            // If there is an empty space, add a new record
            printf("\nEnter IndexNo             : ");
            scanf("%s", indexNo);

            printf("Enter Maths Marks       : ");
            scanf("%d", &maths);

            printf("Enter Physics Marks     : ");
            scanf("%d", &physics);

            printf("Enter Chemistry Marks   : ");
            scanf("%d", &chemistry);

            // Assign values to the structure
            struct StudentDataRecord newRecord;

            strcpy(newRecord.indexNo, indexNo);
            newRecord.maths = maths;
            newRecord.physics = physics;
            newRecord.chemistry = chemistry;

            //calculate average
            average =(maths + physics + chemistry) / 3.0;
            newRecord.average = average;

            newRecord.grade = findGrade(average);

            // Store the new record in the array
            arr[vacantArrayIndex] = newRecord;

            // Correct increment of the count of records
            (*arrExistingElementCountPtr)++;
        }
        else
        {
            printf("\nSorry! No space to add another record.\n");
            break;
        }

        getchar();
        printf("Do you want to add another record? [Y|N] : ");
        scanf("%c", &userFeedback);
    }
    while(userFeedback != 'N' && userFeedback != 'n');
}
//----


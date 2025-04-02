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

struct StudentDataRecord searchByIndexNo(char indexNo[20], int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
void editRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);

struct StudentDataRecord findLastRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
void deleteLastRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);

void printStudentResults(struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
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
            editRecord(&number_of_records, studentDataArr);
            break;

        case DELETE_LAST_RECORD :
            deleteLastRecord(&number_of_records, studentDataArr);
            break;

        case PRINT_STUDENT_RESULTS :
            printStudentResults(studentDataArr);
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
char findGrade(float avgMark)
{
    char grade;

    if(avgMark >= 75)
    {
        grade = 'A';
    }
    else if(avgMark >= 65)
    {
        grade = 'B';
    }
    else if(avgMark >= 55)
    {
        grade = 'C';
    }
    else if(avgMark >= 50)
    {
        grade = 'S';
    }
    else
    {
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


//----
struct StudentDataRecord searchByIndexNo(char indexNo[20], int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS])
{
    struct StudentDataRecord searchDataRecord;
    int found = 0;  // Flag to check if record is found

    for (int i = 0; i < *arrExistingElementCountPtr; i++)
    {
        if (strcmp(arr[i].indexNo, indexNo) == 0)
        {
            searchDataRecord = arr[i];
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("There is no such record!\n");
    }

    return searchDataRecord;
}
//----


//----
void editRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS])
{
    char userFeedback;
    char searchIndexNo[20];
    struct StudentDataRecord searchDataRecord;
    int edited_maths, edited_physics, edited_chemistry;
    float edited_average;

    if (*arrExistingElementCountPtr == 0)
    {
        printf("\nSorry! There are no records to search!\n");
        return;
    }

    do
    {
        printf("\nEnter IndexNo to search : ");
        scanf("%s", searchIndexNo);

        searchDataRecord = searchByIndexNo(searchIndexNo, arrExistingElementCountPtr, arr);

        // If the record is found, display and prompt for editing
        if (strcmp(searchDataRecord.indexNo, "") != 0)
        {
            printf("\n\t\t IndexNo      : %s\n", searchDataRecord.indexNo);
            printf("\t\t Maths Marks    : %d\n", searchDataRecord.maths);
            printf("\t\t Physics Marks  : %d\n", searchDataRecord.physics);
            printf("\t\t Chemistry Marks: %d\n", searchDataRecord.chemistry);
            printf("\t\t Average Marks  : %.2f\n", searchDataRecord.average);
            printf("\t\t Grade          : %c\n", searchDataRecord.grade);

            getchar();
            printf("\nDo you want to edit this record? [Y|N] : ");
            scanf("%c", &userFeedback);

            if(userFeedback == 'Y' || userFeedback == 'y')
            {
                printf("Enter Maths Marks       : ");
                scanf("%d", &edited_maths);

                printf("Enter Physics Marks     : ");
                scanf("%d", &edited_physics);

                printf("Enter Chemistry Marks   : ");
                scanf("%d", &edited_chemistry);

                // Edit values in the selected record
                searchDataRecord.maths = edited_maths;
                searchDataRecord.physics = edited_physics;
                searchDataRecord.chemistry = edited_chemistry;

                // Calculate new average
                edited_average = (edited_maths + edited_physics + edited_chemistry) / 3.0;
                searchDataRecord.average = edited_average;

                // Determine the new grade based on the updated average
                searchDataRecord.grade = findGrade(edited_average);

                // Now, update the original array with the modified record
                for (int i = 0; i < *arrExistingElementCountPtr; i++)
                {
                    if (strcmp(arr[i].indexNo, searchDataRecord.indexNo) == 0)
                    {
                        // Replace the record with the updated data
                        arr[i] = searchDataRecord;
                        printf("\nRecord updated successfully!\n");
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            printf("\nRecord not found for IndexNo: %s\n", searchIndexNo);
        }
    }
    while(userFeedback != 'N' && userFeedback != 'n');
}
//----


//----
struct StudentDataRecord findLastRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]) {
    struct StudentDataRecord lastDataRecord;
    if (*arrExistingElementCountPtr > 0) {
        lastDataRecord = arr[*arrExistingElementCountPtr - 1];
    }
    return lastDataRecord;
}
//----


//----
void deleteLastRecord(int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]) {
    char userFeedback;

    struct StudentDataRecord lastDataRecord;

    if (*arrExistingElementCountPtr == 0) {
        printf("\nSorry! There are no records to delete!\n");
        return;
    }

    do {
        lastDataRecord = findLastRecord(arrExistingElementCountPtr, arr);

        // If the record is found, display and prompt for deleting
        if (strcmp(lastDataRecord.indexNo, "") != 0) {
            printf("\n\t\t IndexNo      : %s\n", lastDataRecord.indexNo);
            printf("\t\t Maths Marks    : %d\n", lastDataRecord.maths);
            printf("\t\t Physics Marks  : %d\n", lastDataRecord.physics);
            printf("\t\t Chemistry Marks: %d\n", lastDataRecord.chemistry);
            printf("\t\t Average Marks  : %.2f\n", lastDataRecord.average);
            printf("\t\t Grade          : %c\n", lastDataRecord.grade);

            getchar();
            printf("\nDo you want to delete this record? [Y|N] : ");
            scanf("%c", &userFeedback);

            if(userFeedback == 'Y' || userFeedback == 'y') {
                // Reset the values
                strcpy(lastDataRecord.indexNo, "");
                lastDataRecord.maths = 0;
                lastDataRecord.physics = 0;
                lastDataRecord.chemistry = 0;
                lastDataRecord.average = 0.0;
                lastDataRecord.grade = 'F';

                // Now, update the original array with the modified record
                for (int i = 0; i < *arrExistingElementCountPtr; i++) {
                    if (strcmp(arr[i].indexNo, lastDataRecord.indexNo) == 0) {
                        // Replace the record with the updated data
                        arr[i] = lastDataRecord;
                        printf("\nThe last record was successfully deleted!\n");
                        break;
                    }
                }

                // Decrease the record count as we have deleted the last record
                (*arrExistingElementCountPtr)--;
                break;
            }
        }
        else {
            printf("\nRecord not found for IndexNo: %s\n", lastDataRecord.indexNo);
        }
    }
    while(userFeedback != 'N' && userFeedback != 'n');
}
//----


//----
void printStudentResults(struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]){
    printf("\n\t\t========================\n");
    printf("\t\t Exam Results \n");
    printf("\t\t========================\n");

    printf("%-10s %-10s %-10s %-15s %-10s %-10s\n", "IndexNo", "Math", "Physics", "Chemistry", "Avg", "Grade");
    printf("-----------------------------------------------------------------------------------------\n");

    int i;
    for(i=0; i<NO_OF_STUDENT_RECORDS; i++){
        printf("%-10s %-10d %-10d %-15d %-12.2f %-10c\n", arr[i].indexNo, arr[i].maths, arr[i].physics, arr[i].chemistry, arr[i].average, arr[i].grade);
    }
}
//----


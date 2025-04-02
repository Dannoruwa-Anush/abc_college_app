#include <stdio.h>
#include <stdlib.h>

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

//function declaration
int displayMainMenu();
void mainMenuHandler();

void loadData(FILE *cfptr, int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
void saveData(FILE *cfptr, int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS]);
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
    int mainMenuOption;

    //menu functions
    do
    {
        mainMenuOption = displayMainMenu();

        switch(mainMenuOption)
        {
        case ADD :
            printf("option -01 \n");
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
            loadData(cfptr, &number_of_records, studentDataArr);
            break;

        case SAVE_DATA :
            saveData(cfptr, &number_of_records, studentDataArr);
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
void loadData(FILE *cfptr, int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS])
{
    // Open the file for reading
    cfptr = fopen("data.txt", "r");

    // Check if the file could not be opened
    if (cfptr == NULL)
    {
        printf("Could not open file for reading.\n");
        return;
    }

    // Initialize the record count to 0 before loading
    *arrExistingElementCountPtr = 0;

    // Read the data from the file into the array of structures
    while (fscanf(cfptr, "%s %d %d %d %f %c",
                   arr[*arrExistingElementCountPtr].indexNo,
                   &arr[*arrExistingElementCountPtr].maths,
                   &arr[*arrExistingElementCountPtr].physics,
                   &arr[*arrExistingElementCountPtr].chemistry,
                   &arr[*arrExistingElementCountPtr].average,
                   &arr[*arrExistingElementCountPtr].grade) == 6) // Ensure that all 6 fields are read
    {
        // Successfully read one record, increment the count
        (*arrExistingElementCountPtr)++;

        // Check if we have reached the maximum number of records
        if (*arrExistingElementCountPtr >= NO_OF_STUDENT_RECORDS)
        {
            printf("Maximum number of records reached. No more records can be loaded.\n");
            break;
        }
    }

    // Close the file after reading
    fclose(cfptr);

    printf("Data loaded successfully from the file.\n");
}
//----

//----
void saveData(FILE *cfptr, int *arrExistingElementCountPtr, struct StudentDataRecord arr[NO_OF_STUDENT_RECORDS])
{
    // Open the file in write mode ("w")
    cfptr = fopen("data.txt", "w");

    // Check if the file could not be opened
    if (cfptr == NULL)
    {
        printf("File could not be opened for writing.\n");
        return;
    }

    // Write data to the file
    for (int i = 0; i < *arrExistingElementCountPtr; i++)
    {
        // Write the student record to the file
        fprintf(cfptr, "%s %d %d %d %.2f %c\n", arr[i].indexNo, arr[i].maths, arr[i].physics, arr[i].chemistry, arr[i].average, arr[i].grade);
    }

    // Close the file
    fclose(cfptr);

    printf("Data saved successfully to the file.\n");
}
//----


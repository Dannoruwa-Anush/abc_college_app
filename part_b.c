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

//function declaration
int displayMainMenu();
void mainMenuHandler();
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
            printf("option -06 \n");
            break;

        case SAVE_DATA :
            printf("option -07 \n");
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

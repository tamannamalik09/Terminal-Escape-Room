// TERMINAL ESCAPE ROOM
#include<stdio.h>
int main()
{
    printf("==================================\n");
    printf("       TERMINAL ESCAPE ROOM       \n");
    printf("==================================\n");
    printf("You wake up in an abandoned house.\n\n");
    int hasFlashlight = 0;
    int hasNote = 0;
    int hasKey = 0;
    int gameRunning = 1;
    while(gameRunning)
    {
        printf("\n\nWhat would you like to do?\n\n");
        printf("1. Bedroom\n2. Library\n3. Main Hall\n4. Basement\n5. Exit Door\n6. Inventory\n7. Quit");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("\nYou entered the bedroom.\n");
                if( hasFlashlight == 0)
                {
                    printf("Yeahh! You found a flashlight!\n");
                    hasFlashlight = 1;
                }
                else printf("Nothing useful remains here.\n");
                break;
            case 2:
                printf("\nYou entered the library.\n");
                if(hasNote == 0)
                {
                    printf("Yeah!! You found a mysterious note.\n");
                    hasNote = 1;
                }
                else printf("Nothing useful remains here.\n");
                break;
            case 3:
                printf("\nYou entered the main hall.\n");
                printf("You found a locked chest!\n");
                if(hasNote == 0)
                {
                    printf("The hidden key is inside it.\nGo to the library to find the hidden note.\n");
                }
                if(hasNote)
                {
                    printf("You have a note. Maybe the clue is useful somewhere...\n");
                }
                break;
            case 4: 
                printf("\nYou entered the basement.\n");
                if(hasFlashlight == 0)
                {
                    printf("OOPs! You don't have flashlight.\nIt's too dark here.Go to the bedroom to find Flashlight.\n");
                }
                if(hasFlashlight)
                {
                    printf("You swept the flashlight beam across the dark basement.\n");
                    printf("You discovered a Keypad on the wall.\n");
                }
                break;
            case 5:
                printf("\nThe door is locked.\n");
                if( hasKey == 0)
                {
                    printf("OOPs! You don't have the key to unlock the door.\n Find the hidden key to unlock this door and escape.\n");
                }
                break;
            case 6:
                printf("\nInventory:\n");
                if(hasFlashlight)
                printf("- Flashlight\n");
                if(hasNote)
                printf("- Mysterious Note\n");
                if(hasKey)
                printf("- Hidden Key\n");            
                break;
            case 7:
                printf("\nGoodbye!");
                return 0;
            default:
                printf("\nInvalid move\n Try again\n");
                break;
        }
    }//while ends here
    return 0;
}
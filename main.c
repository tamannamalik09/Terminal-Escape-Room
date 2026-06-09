// TERMINAL ESCAPE ROOM
#include<stdio.h>
// Global variables
int hasFlashlight = 0;
int hasNote = 0;
int hasKey = 0;
int hasChestKey = 0;
int gameRunning = 1;
// Function prototypes
void bedroom();
void library();
void mainHall();
void basement();
void door();
void inventory();
void openNote();
void codeMatch();
void gameWin();
// Function definitions
void bedroom()
{
    if( hasFlashlight == 0)
    {
        printf("Yeahh! You found a flashlight!\n");
        hasFlashlight = 1;
    }
    else printf("Nothing useful remains here.\n");
}
void library()
{
    if(hasNote == 0)
    {
        hasNote = 1;
        printf("Yeah!! You found a mysterious note.\n");
    }
    if(hasNote)
    {
        openNote();
    }
     else printf("Nothing useful remains here.\n");
}
void mainHall()
{
    printf("You found a chest!\n");
    if(hasChestKey == 0)
    {
        printf("The hidden key is inside it but it's locked.\nGo to the basement and find the chest key to open it.\n");
    }
    else if(hasChestKey && !hasKey)
    {
        printf("The chest is open.\n");
        printf("You got the hidden key.\n");
        hasKey = 1;
    }
    else
    {
        printf("Nothing useful remains here.\n");
    }
}
void basement()
{
    if(hasFlashlight == 0)
    {
        printf("OOPs! You don't have flashlight.\nIt's too dark here.Go find flashlight and come back.\n");
    }
    if(hasFlashlight == 1)
    {
        printf("\nYou swept the flashlight beam across the dark basement.\n");
        printf("You discovered a Keypad on the wall.\n");
        printf("It requires a 3 digit code.Put the right code and you'll unlock the chest.\n");
        codeMatch();
    }
}
void door()
{
    if( hasKey == 0)
    {
        printf("OOPs! You don't have the key to unlock the door.\n Find the hidden key to unlock this door and escape.\n");
    }
    if( hasKey == 1)
    {
        printf("\nYou can now unlock the door with the hidden key.\n");
        gameWin();
    }
}
void inventory()
{
    if(hasFlashlight)
        printf("- Flashlight - Used to explore the basement\n");
    if(hasNote)
        printf("- Mysterious Note - Contains a clue\n");
    if(hasKey)
        printf("- Hidden Key - Opens the exit door\n");
    if(hasChestKey)
        printf("- Chest Key - used to open the locked chest\n");
    if(hasFlashlight == 0 && hasNote == 0 && hasKey == 0 && hasChestKey == 0)
    {
        printf("\nInventory is empty.\n");
    }
}
void openNote()
{
    printf("===============================================\n");
    printf("               MYSTERIOUS NOTE                 \n");
    printf("===============================================\n");
    printf("The chest obeys only three numbers.\n\nFive knocks upon the door.\nThree whispers in the dark.\nEight steps to freedom.\n");
    printf("The chest guards the key.The basement guards the truth.\n");
}
void codeMatch()
{ 
    int code;
    int chance = 3;
    while(chance > 0)
    {
        printf("Enter the three digit code: ");
        scanf("%d",&code);
        if(code == 538)
        {
            printf("\nChest successfully unlocked!\n");
            hasChestKey = 1;
            return;
        }
        chance--;
        printf("Wrong code!\n");
        printf("You have %d chances left.\n",chance);
    }
     printf("GAME OVER!\nBetter luck next time\n");
     gameRunning = 0;
}
void gameWin()
{
    printf("The lock clicks.\nThe front door slowly opens.\nFresh air rushes inside.\nYou take one last glance at the abandoned house and step outside\n");
    printf("Congratulations! YOU ESCAPED.\n");
    gameRunning = 0;
}
int main()
{
    printf("==================================\n");
    printf("       TERMINAL ESCAPE ROOM       \n");
    printf("==================================\n");
    printf("You wake up in an abandoned house.\n\n");
    while(gameRunning)
    {
        printf("\n\nWhat would you like to do?\n\n");
        printf("[1] Bedroom\n[2] Library\n[3] Main Hall\n[4] Basement\n[5] Exit Door\n[6] Inventory\n[7] Quit");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("\nYou entered the bedroom.\n");
                bedroom();
                break;
            case 2:
                printf("\nYou entered the library.\n");
                library();
                break;
            case 3:
                printf("\nYou entered the main hall.\n");
                mainHall();
                break;
            case 4: 
                printf("\nYou entered the basement.\n");
                basement();
                break;
            case 5:
                printf("\nThe door is locked.\n");
                door();
                break;
            case 6:
                printf("\nInventory:\n");
                inventory();            
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
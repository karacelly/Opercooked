#include <stdio.h>
#include <string.h>

char menuName[100][255];
char typeMenu[100][255];
char topping[100][255];
char menuSize[100];
char menuFlavor[100][50];
double calories[100];
int menuPrice[100];
int currentMenu = 1;

void order();

void order(){
    
        if (strlen(menuName[1]) == 0)
        {
            puts("There is no Dessert or Drink on the list!");
            printf ("\nPress Enter to continue");
            getchar();
        }
        else if (strlen(menuName[1]))
        {
            printf ("| %-5s| %-20s| %-7s| %-12s| %-11s| %-11s| %-6s|\n","No", "Name", "Price", "Topping", "Callories", "Flavor", "size");
            puts ("---------------------------------------------------------------------------------------");
            //kalau dia dessert
            for (int i = 1; i < 100; i++)
            {
                if (strcmp(typeMenu[i], "Dessert") == 0)
                {
                    printf ("| %-5d| %-20s| %-7d| %-12s| %-11.2lf| %-11s| %-6s|\n", i, menuName[i], menuPrice[i], topping[i], calories[i], "-", "-");
                }
                //kalau dia drink
                if (strcmp(typeMenu[i], "Drink") == 0)
                {
                    printf ("| %-5d| %-20s| %-7d| %-12s| %-11.2lf| %-11s| %-6s|\n", i, menuName[i], menuPrice[i], "-", "-", menuFlavor[i], menuSize[i]);
                }
            }
            
            while(1)
            {
            printf ("Choose a menu to order [1 - %d]: ", currentMenu - 1);
            int input;
            scanf ("%d", &input); getchar();
            if (input >= 1 && input <= currentMenu - 1) break;
            }
            printf("\nSuccessfully add to order list!\n");
            printf ("Press Enter to continue"); getchar();
        }
    
}
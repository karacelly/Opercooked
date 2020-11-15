#include <stdio.h>
#include <string.h>
#include <time.h>

void addDessertOrderTime(int indexMenu){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    orderDessert[indexMenu].orderTime.year = tm.tm_year + 1900;
    orderDessert[indexMenu].orderTime.month = tm.tm_mon + 1;
    orderDessert[indexMenu].orderTime.date = tm.tm_mday;
    orderDessert[indexMenu].orderTime.hour = tm.tm_hour;
    orderDessert[indexMenu].orderTime.min = tm.tm_min;
    orderDessert[indexMenu].orderTime.sec = tm.tm_sec;
    if (orderDessert[indexMenu].orderTime.hour > 12)
    {
        strcpy(orderDessert[indexMenu].orderTime.form, "PM");
        orderDessert[indexMenu].orderTime.hour -= 12;
    }
    else strcpy(orderDessert[indexMenu].orderTime.form, "AM");
}

void addDrinkOrderTime(int indexMenu){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    orderDrink[indexMenu].orderTime.year = tm.tm_year + 1900;
    orderDrink[indexMenu].orderTime.month = tm.tm_mon + 1;
    orderDrink[indexMenu].orderTime.date = tm.tm_mday;
    orderDrink[indexMenu].orderTime.hour = tm.tm_hour;
    orderDrink[indexMenu].orderTime.min = tm.tm_min;
    orderDrink[indexMenu].orderTime.sec = tm.tm_sec;
    if (orderDrink[indexMenu].orderTime.hour > 12)
    {
        strcpy(orderDrink[indexMenu].orderTime.form, "PM");
        orderDrink[indexMenu].orderTime.hour -= 12;
    }
    else strcpy(orderDrink[indexMenu].orderTime.form, "AM");
}

struct OrderTime
{
    int year,month,date,hour,min,sec;
    char form[3];
};

struct pesanDrink
{
 char menuName[255];
 int menuPrice;
 char typeMenu[255];
 char menuSize[3];
 char menuFlavor[50];
 int drinkTime;
 OrderTime orderTime;
};

struct pesanDessert
{
 char typeMenu[255];
 char menuName[255];
 char topping[255];
 double calories;
 int menuPrice;
 int dessertTime;
 OrderTime orderTime;
};

char menuName[100][255];
char typeMenu[100][255];
char topping[100][255];
char menuSize[100][3];
char menuFlavor[100][50];
double calories[100];
int menuPrice[100];
int currentMenu = 1;
int indexMenu = 1;

pesanDessert orderDessert[105];
pesanDrink orderDrink[105];

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
            
            int input;
            while(1)
            {
                printf ("Choose a menu to order [1 - %d]: ", currentMenu - 1);
                scanf ("%d", &input); getchar();
                if (input >= 1 && input <= currentMenu - 1) break;
            }
            if (strcmp(typeMenu[input], "Dessert") == 0)
            {
                strcpy(orderDessert[indexMenu].typeMenu, typeMenu[input]);
                strcpy(orderDessert[indexMenu].menuName, menuName[input]);
                strcpy(orderDessert[indexMenu].topping, topping[input]);
                orderDessert[indexMenu].calories =  calories[input];
                orderDessert[indexMenu].menuPrice = menuPrice[input];
                orderDessert[indexMenu].dessertTime = dessertTime[input];
                addDessertOrderTime(indexMenu);
            }
            else if (strcmp(typeMenu[input], "Drink") == 0)
            {
                strcpy(orderDrink[indexMenu].typeMenu, typeMenu[input]);
                strcpy(orderDrink[indexMenu].menuName, menuName[input]);
                strcpy(orderDrink[indexMenu].menuSize, menuSize[input]);
                strcpy(orderDrink[indexMenu].menuFlavor, menuFlavor[input]);
                orderDrink[indexMenu].menuPrice = menuPrice[input];
                orderDrink[indexMenu].drinkTime = drinkTime[input];
                addDrinkOrderTime(indexMenu);
            }
            indexMenu++;
            printf("\nSuccessfully add to order list!\n");
            printf ("Press Enter to continue"); getchar();
        }
    
}
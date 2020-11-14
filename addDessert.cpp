#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char typeMenu[100][255];
char menuName[100][255];
char topping[100][255];
double calories[100];
int currentMenu = 1;
int menuPrice[100];
int dessertTime[100];

void addDesert();

void addDesert(){
    strcpy(typeMenu[currentMenu], "Dessert");
    char namaMenu[255], toppingMenu[255];
    int price;
    double calorie;

    //input nama dessert
    do
    {
        printf ("Input the name [at least 5 characters]: ");
        scanf ("%[^\n]", namaMenu); getchar();
    }while(strlen(namaMenu) < 5);
    strcpy(menuName[currentMenu], namaMenu);

    //input harga
    do
    {
        printf ("Input the price [10 - 500]: "); 
        scanf ("%d", &price); getchar();
    }while(price < 10 || price > 500);
    menuPrice[currentMenu] = price;

    //input topping
    do
    {
        printf ("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
        scanf ("%s", toppingMenu); getchar();
    }while(strcmp("Caramel", toppingMenu) != 0 || strcmp("Honey", toppingMenu) != 0 || strcmp("Syrup", toppingMenu) != 0);
    strcpy(topping[currentMenu], toppingMenu);

    //input kalori
    do
    {
        printf ("Insert calories [1.00 - 99.00]: ");
        scanf ("%lf", &calorie); getchar();
    }while(calorie < 1.00 || calorie > 99.00);
    calories[currentMenu] = calorie;
    printf("Successfully added a new menu!");
    getchar();
    currentMenu++;

    //ngitung cooking time
    //random waktu pembuatan dessert(line 100)
    srand(time(0));
    int totaltime = (rand() % 40)+50;

    if(strcmp(toppingMenu, "Caramel") == 0){
        totaltime += 10;
    }
    else if(strcmp(toppingMenu, "Honey") == 0){
        totaltime+=15;
    }
    else if(strcmp(toppingMenu, "Syrup") == 0){
        totaltime+=20;
    }

    dessertTime[currentMenu] = totaltime;
    
}

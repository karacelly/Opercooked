#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char menuName[100][255];
int menuPrice[100];
int currentMenu = 1;
char typeMenu[100][255];
char menuSize[100][2];
char menuFlavor[100][50];
int drinkTime[100];

void addDrink();

void addDrink(){
    strcpy(typeMenu[currentMenu], "Drink");
    char namaMenu[255], toppingDrink[255];
    int price;
    char size[2];

    getchar();
    //input nama drink
    do {   
        printf ("Input the name [at least 5 characters]: ");
        scanf ("%[^\n]", namaMenu); getchar();
    }while(strlen(namaMenu) < 5);
    strcpy(menuName[currentMenu], namaMenu);

    //input harga
    do {
        printf ("Input the price [10 - 500]: $ "); 
        scanf ("%d", &price); getchar();
    }while(price < 10 || price > 500);
    menuPrice[currentMenu] = price;

    //input flavor
    int flag = 0;
    do {   
        printf ("Input the topping ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        scanf ("%s", toppingDrink); getchar();
        if (strcmp("Mint", toppingDrink) == 0 || strcmp("Mix Berry", toppingDrink) == 0 || strcmp("Cheese", toppingDrink) == 0){
            flag = 1;
        }
    }while(flag == 0);
    strcpy(menuFlavor[currentMenu], toppingDrink);

    //input size
    flag = 0;
    do {
        printf ("Insert the size [S | M | L](Case Sensitive): ");
        scanf ("%s", size); getchar();
        if (strcmp("S", size) == 0 || strcmp("M", size) == 0 || strcmp("L", size)==0){
            flag = 1;
        }
    }while(flag == 0);
    strcpy(menuSize[currentMenu], size);

    int totalTime = (rand() % 41) + 10;
    if (strcmp(toppingDrink, "Mint") == 0){
        totalTime+=10;
    }
    else if(strcmp(toppingDrink, "Mix Berry") == 0){
        totalTime+=20;
    }
    else if(strcmp(toppingDrink, "Cheese") == 0){
        totalTime+=30;
    }
    drinkTime[currentMenu]=totalTime;

    printf("Successfully added a new menu!");
    getchar();
    currentMenu++;
}

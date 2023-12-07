#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int TakCzyNie();

int main(){

int odpowiedz = 2;

printf("\nStart programu\n");

odpowiedz = TakCzyNie();
printf("\ndebug  %d\n", odpowiedz);
switch (odpowiedz){

case 0:
    printf("nieodp");
    break;
case 1:
    printf("takodp");
    break;
default:
    printf("zlaodp");
}


return 0;
}

int TakCzyNie()
{
    char userInput[10];
    scanf("%9s", userInput);
    if (strcmp(userInput, "tak") == 0)
        return 1;
    else if (strcmp(userInput, "nie") == 0)
        return 0;
    else
        return 2;
}

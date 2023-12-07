#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int InputReader();
int InputValidation();

int main(){

int odpowiedz = 2;

printf("\nStart programu\n");

odpowiedz = InputValidation();
printf("\ndebug  %d\n", odpowiedz);


return 0;
}

int InputReader()
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

int InputValidation()
{
    int inputValue;
    inputValue = InputReader();
    switch(inputValue)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    default:
        printf("\nZly format odpowiedzi, wpisz odpowiedz ponownie [tak/nie]\n");
        return InputValidation();
    }

}

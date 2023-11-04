#include <stdio.h>

//tutaj są deklaracje wszystkich funkcji-odgałęzień
//ich nazwy odpowiadają nazwom bloków w Twine
void czy_zaczac(char answer);
void rekursywne_oczekiwanie_na_start(char answer);
void start_gry(char answer);
void odmowa_startu(char answer);
void tak_dziecko(char answer);
void nie_karawana(char answer);
void tak_morderstwo(char answer);
void nie_podróż(char answer);


//to jest input handler
int yesno(char answ)
{
    answ = getchar();
     while (getchar() != '\n');
    if (answ == 't' || answ == 'n')
    {
    return answ;
    }

    else
    {
        printf("Błąd. Odpowiadaj tylko literami t lub n!\n");
        while (getchar() != '\n');
        return yesno(answ);
    }
}
int main(){
    char answer;
    czy_zaczac(answer);
    return 0;
}

void czy_zaczac(char answer)
{
  printf("Witaj.\n");
    printf("Na pytania odpowiadaj poprzez wpisanie t (tak) lub n (nie)\n");
    printf("Czy jesteś gotowy?\n");
    answer = yesno(answer);
    if (answer == 't')      
    start_gry(answer);
    else
    odmowa_startu(answer);
}

void rekursywne_oczekiwanie_na_start(char answer)
{
 printf("Czy jesteś już gotowy?\n");
    answer = yesno(answer);
    if (answer == 't')      
    start_gry(answer);
    else
    odmowa_startu(answer);
}

void start_gry(char answer)
{
    printf("Jesteś samotnym wędrowcem.\n");
    printf("Stoisz w ciemnej dolinie.\n");
    printf("Jesteś zmęczony. Nie wiesz gdzie jesteś.\n");
    printf("Czy chcesz iść dalej?\n");
    answer = yesno(answer);
    if (answer == 't')      
    tak_dziecko(answer);
    else
    nie_karawana(answer);

}

void odmowa_startu(char answer)
{
    printf("odmowa startu\n");
    rekursywne_oczekiwanie_na_start(answer);
}

void nie_karawana(char answer)
{
    printf("Spotykasz karawanę.\n");
    printf("Jakiś człowiek schodzi ze swojego wozu i podchodzi do ciebie.\n");
    printf("Nie znasz go.\n");
    printf("Czy chcesz go zaatakować?\n");

    answer = yesno(answer);
    if (answer == 't')      
    tak_morderstwo(answer);
    else
    nie_podróż(answer);
}

void tak_dziecko(char answer)
{
    printf("dziecko\n");
}

void tak_morderstwo(char answer)
{
    printf("morderstwo\n");
}

void nie_podróż(char answer)
{
        printf("podróż\n");

}

#include <stdio.h>

//muszę dodać reset prompt

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
void nie_wilki(char answer);
void tak_wioska_pod_mgla(char answer);
void nie_dym(char answer);
void tak_rozszarpany(char answer);
void tak_upadek(char answer);
void nie_zgliszcza(char answer);


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
    printf("Nie spodziewał się ciosu.\n");
    printf("Zanim reszta podróżnych zrozumiała, co się stało, zabrałeś mu nóż i wodę, po czym uciekłeś spoza światła ich pochodni na zbocze górskie.\n");
    printf("Robiłeś gorsze rzeczy, by przeżyć.\n");
    printf("Czy chcesz wspiąć się na szczyt i rozejrzeć po okolicy?\n");
    answer = yesno(answer);
    if (answer == 't')      
    tak_wioska_pod_mgla(answer);
    else
    nie_wilki(answer);
}

void nie_podróż(char answer)
{
        printf("podróż\n");
}

void nie_wilki(char answer) 
{
    printf("Czekasz na skale i wypijasz wodę z bukłaka.\n");
    printf("Zaczyna się świt. Słyszysz szelest w krzakach. Wychodzi z nich para wilków.\n");
    printf("Czy z nimi walczysz?\n");
    answer = yesno(answer);
    if (answer == 't')      
    tak_rozszarpany(answer);
    else
    nie_dym(answer);

}

void tak_wioska_pod_mgla(char answer) 
{
    // Function body for tak_wioska_pod_mgla
}

void nie_dym(char answer) 
{
    printf("Wchodzisz na szczyt.\n");
    printf("Widzisz czarny dym, który zasłania ci podnóże góry.\n");
    printf("Możesz zejść stromym zboczem albo łagodną ścieżką.\n");
    printf("Patrzysz w dół. Jeśli są tam ludzie, to potrzebują pomocy.\n");
    printf("Ale czy chcesz dla nich ryzykować?\n");
    answer = yesno(answer);
    if (answer == 't')      
    tak_upadek(answer);
    else
    nie_zgliszcza(answer);
}
void tak_rozszarpany(char answer) 
{
    printf("Pierwszy wilk wyje z bólu, gdy wbijasz nóż w jego bok.\n");
    printf("Nie możesz wyjąć ostrza z jego żeber.\n");
    printf("Pojawiają się kolejne.\n");
    printf("Nie dasz rady.\n");
}

void tak_upadek(char answer) 
{
    printf("Nie byłeś przygotowany na taki wysiłek. Ciągła walka i ucieczka zabrały ci resztki energii.\n");
    printf("Spadłeś i nawet nie zdążyłeś poczuć uderzenia.\n");
}

void nie_zgliszcza(char answer) 
{
    printf("Łagodna ścieżka zajęła ci sporo do przejścia.\n");
    printf("Nie przeszkadza ci to. Najważniejsze, że jesteś bezpieczny.\n");
    printf("Ciągły marsz wywołuje u ciebie poczucie głodu.\n");
    printf("Widzisz palące się zgliszcza jakiejś osady. To z nich leciał dym.\n");
    printf("Wejście do nich jest niebezpieczne, ale może znajdziesz jakieś jedzenie.\n");
    printf("Czy chcesz wejść między płonące ruiny?\n");

}

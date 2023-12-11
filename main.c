#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//czytelne nazwy dla możliwych wyników odpowiedzi
enum Odpowiedzi {
    NIE = 0,
    TAK = 1,
    POWROT = 2,
    WYJSCIE = 3,
};

//drzewo binarne, pozwalające na efektywne "podróżowanie" po strukturze gry
//krok 1. deklaracja struktury drzewa, pozwala ona na podróż także w górę drzewa
struct TreeNode{
int identifier;
char message[500];
struct TreeNode* right;
struct TreeNode* left;
struct TreeNode* parent;
};


//deklaracje funkcji drzewa binarego
struct TreeNode* createNode(int identifier, const char* message);
struct TreeNode* insertNode(struct TreeNode* root, int identifier, const char* message, struct TreeNode* parent);
void treeLoader(struct TreeNode** root, int identifiers[], const char* messages[], struct TreeNode* parent, int treeSize);

//sekcja kodu odpowiedzialna za odpowiedzi gracza i ich walidację
//implementacja tych funkcji znajduje się pod main() dla lepszej czytelności kodu
int InputReader();
int InputValidation();

//sekcja kodu odpowiedzialna za losowe zakończenie gry przy spotkaniu rekina na plaży i opcji braku walki
int main(){
struct TreeNode* root = NULL;

int zakonczenie;

int identifiers[] = {4,2,6,1,3,5,7};
const char* messages[] = 
        {
            //start
            "Czy chcesz zaczac gre?",
            //start->tak
            "Idziesz przez ciemny las i spotykasz niedzwiedzia, czy chcesz z nim walczyc?",
            //start->nie
            "Nigdy nie miales prawdziwego wyboru. Idziesz na plazę i spotykasz rekina, czy chcesz z nim walczyc?",
            //start->tak->tak
            "Niespodziewanie niedzwiedz okazal sie silniejszy.\nPrzegrales.\nWpisz 'powrot' by cofnac sie o jeden krok, lub 'wyjdz', by wyjsc z gry",
            //start->tak->nie
            "To byla dobra decyzja, wrociles do domu caly i zdrowy.\nWygrales.\nWpisz 'powrot', by cofnac sie o jeden krok, lub 'wyjdz', by wyjsc z gry",
            //start->nie->tak
            "Niespodziewanie rekin ma ostrzejsze zeby od ciebie i cie zjada.\nPrzegrales.\nWpisz 'powrot' by cofnac sie o jeden krok, lub 'wyjdz', by wyjsc z gry",

            //start->nie->nie
            "Nie chcesz walczyc z rekinem, zostales na plazy sie poopalac"
        };
//inicjalizacja drzewa
treeLoader(&root, identifiers, messages, NULL, sizeof(identifiers) / sizeof(identifiers[0]));

    int odpowiedz;
while (root != NULL) 
{
printf("\n%s ", root->message);
 if (root->identifier == 7)
          {
              
              zakonczenie = rand() % 10;
              switch (zakonczenie) {
                case 0:
                  printf("\nNagle rekin wyskoczyl z wody i cie zjadl.\nPrzegrales.\nWpisz 'powrot' by cofnac sie o jeden krok, lub 'wyjdz', by wyjsc z gry ");
                  break;
                default:
                  printf("\nWygrales.\nWpisz 'powrot', by cofnac sie o jeden krok, lub 'wyjdz', by wyjsc z gry ");
                  break;
              
              }
          }


odpowiedz = InputValidation();
        if (odpowiedz == TAK && root->left != NULL)
        {
            root = root->left;
        }
        else if (odpowiedz == NIE && root->right != NULL)
        {
            root = root->right;
        }
        else if (odpowiedz == POWROT && root->parent != NULL)
        {
            root = root->parent;         
        }
        else if (odpowiedz == WYJSCIE)
        {
            exit(0);
        }
        else 
            break;
}


return 0;
}

int InputReader()
{
    char userInput[10];
    scanf("%9s", userInput);
    if (strcmp(userInput, "nie") == 0)
        return 0;
    else if (strcmp(userInput, "tak") == 0)
        return 1;
    else if (strcmp(userInput, "powrot") == 0)
        return 2;
    else if(strcmp(userInput, "wyjdz") == 0)
        return 3;
    else
        return -1;
}

int InputValidation()
{
    int inputValue;
    inputValue = InputReader();
    switch(inputValue)
    {
    case 0:
        return NIE;
        break;
    case 1:
        return TAK;
        break;
    case 2:
        return POWROT;
        break;
    case 3:
      return WYJSCIE;
      break;
    default:
        printf("\nZly format odpowiedzi, wpisz odpowiedz ponownie [tak/nie]\n");
        return InputValidation();
    }

}

//krok 2. funkcja tworząca nowe elementy drzewa
struct TreeNode* createNode(int identifier, const char* message)
{
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->identifier = identifier;
    strcpy(newTreeNode->message, message);
    newTreeNode->left = newTreeNode->right = newTreeNode->parent = NULL;
    return newTreeNode;
}

//krok 3. funkcja dodająca element do drzewa po utworzeniu
struct TreeNode* insertNode(struct TreeNode* root, int identifier, const char* message, struct TreeNode* parent)
{
    if (root == NULL)
    {
        struct TreeNode* newTreeNode = createNode(identifier, message);
        newTreeNode->parent = parent;
        return newTreeNode;
    }

    if (identifier < root->identifier){
        root->left = insertNode(root->left, identifier, message, root);
    }
    else if (identifier > root->identifier){
        root->right = insertNode(root->right, identifier, message, root);
    }
   return root;

}

//krok 4. funkcja zapełniająca drzewo tekstem do wyświetlenia (blokami gry)
void treeLoader(struct TreeNode** root, int identifiers[], const char* messages[], struct TreeNode* parent, int treeSize)
{
    for (int i = 0; i < treeSize; i++) 
    {
        *root = insertNode(*root, identifiers[i], messages[i], parent);
    }
}


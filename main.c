#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//drzewo binarne, pozwalające na efektywne "podróżowanie" po strukturze gry
//krok 1. deklaracja struktury drzewa, pozwala ona na podróż także w górę drzewa
struct TreeNode{
int indentifier;
char message[500];
struct TreeNode* right;
struct TreeNode* left;
struct TreeNode* parent;
};

//krok 2. funkcja tworząca nowe elementy drzewa
struct TreeNode* createNode(int identifier, char message[500])
{
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->identifier = identifier;
    strcpy(newTreeNode->message, message);
    newTreeNode->left = newTreeNode->right = newTreeNode->parent = NULL;
    return newTreeNode;
}

//krok 3. funkcja dodająca element do drzewa po utworzeniu
//sprawdza ona, czy dany element jest pierwszym (root)
//jeżeli tak, to tworzony jest korzeń (root)
//jeżeli nie, tworzony jest kolejny element drzewa
struct TreeNode* insertNode(struct TreeNode* root, int identifier, char message, struct TreeNode* parent)
{
    if (root == NULL)
    {
        struct TreeNode* newTreeNode = createNode(identifier. message);
        newTreeNode->parent = parent;
        return newTreeNode;
    }

    if (strcmp(identifier, root->indentifier) < 0){
        root->left = In
    }
}


//sekcja kodu odpowiedzialna za odpowiedzi gracza i ich walidację
//implementacja tych funkcji znajduje się pod main() dla lepszej czytelności kodu
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

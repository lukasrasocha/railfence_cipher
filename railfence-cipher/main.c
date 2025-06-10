#include<stdio.h>
#include<string.h>

void encryptMsg(char msg[], int key){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;  //Určuje délku zprávy (msgLen), nastavuje proměnné pro iterace (i, j), a inicializuje proměnné pro kontrolu směru pohybu v mřížce (k), řádky a sloupce (row, col).
    char railMatrix[key][msgLen];  //Vytváří mřížku o rozměrech key (počet řádků) a msgLen (počet sloupců) pro šifrování.

    for(i = 0; i < key; ++i)  //Inicializuje mřížku railMatrix na prázdné hodnoty (\n), což znamená prázdné místo.
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for(i = 0; i < msgLen; ++i){  //Vkládá znaky z původní zprávy do mřížky podle šifrovacího vzoru.
        railMatrix[row][col++] = msg[i];

        if(row == 0 || row == key-1)  //Mění směr pohybu po řádcích, když dosáhne prvního nebo posledního řádku.
            k= k * (-1);

        row = row + k;  //Posunuje řádek o 1 (nebo -1, podle směru) pro další znak.
    }

    printf("\nEncrypted Message: ");

    for(i = 0; i < key; ++i)  //Vypisuje šifrovanou zprávu tím, že prochází mřížku a vypisuje všechny nenulové hodnoty.
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] != '\n')
                printf("%c", railMatrix[i][j]);
}

void decryptMsg(char enMsg[], int key){
    int msgLen = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;  //Nastavuje délku šifrované zprávy (msgLen) a proměnné pro práci s mřížkou a pro iterace.
    char railMatrix[key][msgLen];  //Vytváří mřížku pro dešifrování zprávy, která bude mít stejný tvar jako při šifrování.

    for(i = 0; i < key; ++i)  //Inicializuje mřížku na prázdné hodnoty.
        for(j = 0; j < msgLen; ++j)  ////Inicializuje mřížku na prázdné hodnoty.
            railMatrix[i][j] = '\n';

    for(i = 0; i < msgLen; ++i){  //Zapisuje do mřížky zástupné znaky (*), kde budou později vloženy písmena z šifrované zprávy.
        railMatrix[row][col++] = '*';  //Zapisuje do mřížky zástupné znaky (*), kde budou později vloženy písmena z šifrované zprávy.

        if(row == 0 || row == key-1)  //Stejně jako v šifrování, mění směr pohybu mezi řádky při dosažení krajních řádků.
            k= k * (-1);

        row = row + k;
    }

    for(i = 0; i < key; ++i)  //Nahrazuje zástupné znaky (*) skutečnými písmeny z šifrované zprávy.
        for(j = 0; j < msgLen; ++j) //viz radek 46
            if(railMatrix[i][j] == '*')  //viz radek 46
                railMatrix[i][j] = enMsg[m++];  //viz radek 46

    row = col = 0;  //Resetuje hodnoty pro dešifrování: řádek, sloupec a směr.
    k = -1;

    printf("\nDecrypted Message: ");

    for(i = 0; i < msgLen; ++i){  //Vypisuje dešifrovanou zprávu tím, že čte písmena z mřížky v požadovaném pořadí.
        printf("%c", railMatrix[row][col++]);

        if(row == 0 || row == key-1)
            k= k * (-1);

        row = row + k;
    }
}

int main(){
    char msg[] = "Lukas Rasocha";  // Původní zpráva k šifrování.
    char enMsg[] = "Horel ollWd";  //Šifrovaná verze zprávy, kterou dešifrujeme.
    int key = 5;  //Počet řádků v mřížce pro šifrování/dešifrování.

    printf("Original Message: %s", msg);

    encryptMsg(msg, key);  //Zavolá funkci pro šifrování zprávy.
    decryptMsg(enMsg, key);  //Zavolá funkci pro dešifrování zprávy.

    return 0;
}


//  myLib.c

void errore(char* s, int n) {
    printf("Errore %d in %s (%s) \n (exiting with error level %d)\n", errno, s, strerror(errno), n);
    exit(n);
}

char* readLine(FILE* f) {
    char buffer[MAX_STRING_LENGTH];
    int i;
    for(i = 0;
        ((buffer[i]=fgetc(f))!='\n') && (buffer[i]!=EOF);  /*l'alternativa di getc e gets ecc.*/
        i++) { }  
    buffer[i] = '\0';
    return (i==0)? NULL: strdup(buffer);
}

/* ATTENZIONE: Altera la stringa originale con strtok() = funzione che cerca le occorrenze, 
ed e strate full si ricorda la ricorrenza se legge il primo, si ricorda e prende il secondo*/
char** splitString(char* s, char separator) {
    char** tokens = NULL;
    char delimiter[2] = {separator, '\0' };  //strtok potrebbe accettare piu di un carattere
    int count = 0;  /*serve per contare*/
    char* token = strtok(s, delimiter);  /*questa strtok e quella fuori ciclo perchè e fuori dal ciclo
    restituisce la prima sottostringa, l'indirizzo della prima stringa*/
    while(token != NULL) {
        // realloc(): come malloc(), ma rialloca la memoria copiando i vecchi dati
        tokens = realloc(tokens, sizeof(char*) * (count + 1)); /*<-- restituisce: 
        aggiunge un elemento al vetore di stringhe*/
        tokens[count] = strdup(token); /*dentro al vettore ci mette il tappo della stringa*/
        count++;
        token = strtok(NULL, delimiter);  /*non gli passa la stringa intera ma gli passa NULL*/
        /*il while e fino a quando la stringa non restituisce NULL*/
    }
    tokens = realloc(tokens, sizeof(char*) * (count + 1)); 
    tokens[count] = NULL; // Terminatore
    return tokens;
}

void disposeStringArray(char** arr) {  /*una volta che verra memorizzato il vettore 
    servira uccidere il vettore per evitare un memory leek*/
    for(char** temp = arr; *temp; temp++) { 
        free(*temp);
    }
    free(arr);
}

int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

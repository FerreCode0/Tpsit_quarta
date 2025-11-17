// funzione = int, float, char ...
// procedura = void
// || = or (o uno o l'altro)
// && = and (deve essere tutto)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ======================
//      STRUTTURE
// ======================
typedef struct {
    int giorno;
    int mese;
    int anno;
} Date;

typedef struct {
    char nome[50];
    Date dataNascita;
} Persona;

// ======================
//      PROTOTIPI
// ======================
int RandomRange(int min, int max);
void sets(char *s, Persona *r);
void errore(char *s, int n);
Persona *createPerson(Date *d, char *nome);
char *readLine(FILE *in);

// ======================
//      FUNZIONI
// ======================

// Restituisce un numero casuale compreso tra min e max (inclusi)
int RandomRange(int min, int max) {
    if (max <= min) return min;
    return rand() % (max - min + 1) + min;
}

// Copia una stringa nel campo nome di una Persona
void sets(char *s, Persona *r) {
    if (s == NULL || r == NULL) return;
    strncpy(r->nome, s, sizeof(r->nome) - 1);
    r->nome[sizeof(r->nome) - 1] = '\0';
}

// Stampa un messaggio d'errore e termina il programma
void errore(char *s, int n) {
    fprintf(stderr, "Errore: %s\n", s);
    exit(n);
}

// Crea dinamicamente una persona con nome e data di nascita
Persona *createPerson(Date *d, char *nome) {
    Persona *p = malloc(sizeof(Persona));
    if (p == NULL)
        errore("Impossibile allocare memoria per Persona", 1);

    if (nome != NULL)
        sets(nome, p);
    else
        strcpy(p->nome, "Sconosciuto");

    if (d != NULL)
        p->dataNascita = *d;
    else {
        p->dataNascita.giorno = 1;
        p->dataNascita.mese = 1;
        p->dataNascita.anno = 2000;
    }

    return p;
}

// Legge una riga di testo da un file (o da stdin)
char *readLine(FILE *in) {
    if (in == NULL) return NULL;

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), in) == NULL)
        return NULL;

    buffer[strcspn(buffer, "\n")] = '\0'; // rimuove '\n' finale

    char *line = malloc(strlen(buffer) + 1);
    if (line == NULL)
        errore("Impossibile allocare memoria per la riga", 2);

    strcpy(line, buffer);
    return line;
}

// ======================
//      MAIN DI TEST
// ======================
int main() {
    srand(time(NULL)); // inizializza generatore numeri casuali

    printf("Esempio funzione RandomRange(1, 10): %d\n", RandomRange(1, 10));

    printf("Inserisci un nome: ");
    char *nome = readLine(stdin);

    Date d = { RandomRange(1, 28), RandomRange(1, 12), RandomRange(1970, 2015) };
    Persona *p = createPerson(&d, nome);

    printf("\n--- DATI PERSONA ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Data di nascita: %02d/%02d/%04d\n",
           p->dataNascita.giorno, p->dataNascita.mese, p->dataNascita.anno);

    // Libera la memoria allocata
    free(p);
    free(nome);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>

#define JOGOS 15
#define OITAVAS 8
#define QUARTAS 4
#define SEMI 2
#define FINAL 1

typedef struct {
    int placar0;
    int placar1;
} Jogo;

typedef struct {
    int n;
    char *nome;
} Equipe;

typedef struct {
    Jogo *jogos;
    int n;
} CopaDoMundo;


void printEquipes(Equipe *equipes, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s", equipes[i].nome);
    }
    printf("\n");
}

Equipe *oitavas(CopaDoMundo *copa, Equipe *times) {
    Equipe *vencedores = malloc(OITAVAS * sizeof(Equipe));
    int j = 0;
    for (int i = 0; i < OITAVAS; i++) {
        if (copa->jogos[i].placar0 > copa->jogos[i].placar1) {
            vencedores[i] = times[j];
        } else {
            vencedores[i] = times[j + 1];
        }
        j += 2;
    }
    return vencedores;
}

Equipe *quartas(CopaDoMundo *copa, Equipe *oitavas)
{
    Equipe *vencedores = malloc(QUARTAS * sizeof(Equipe));
    int j = 0;
    
    for (int i = 0; i < QUARTAS; i++) 
    {
        int indicejogo = i + OITAVAS; 

        if (copa->jogos[indicejogo].placar0 > copa->jogos[indicejogo].placar1) {
            vencedores[i] = oitavas[j];
        } else {
            vencedores[i] = oitavas[j + 1];
        }
        j += 2;
    }
    
    return vencedores;
}

Equipe *semi(CopaDoMundo *copa, Equipe *semi)
{
    Equipe *vencedores = malloc(SEMI * sizeof(Equipe));
    int j = 0;
    
    for (int i = 0; i < SEMI; i++) 
    {
        int indicejogo = i + QUARTAS + OITAVAS; 

        if (copa->jogos[indicejogo].placar0 > copa->jogos[indicejogo].placar1) {
            vencedores[i] = semi[j];
        } else {
            vencedores[i] = semi[j + 1];
        }
        j += 2;
    }
    
    return vencedores;
}

Equipe *final(CopaDoMundo *copa, Equipe *final)
{
    Equipe *vencedores = malloc(FINAL * sizeof(Equipe));
    int j = 0;
    
    for (int i = 0; i < FINAL; i++) 
    {
        int indicejogo = i + SEMI + QUARTAS + OITAVAS; 

        if (copa->jogos[indicejogo].placar0 > copa->jogos[indicejogo].placar1) {
            vencedores[i] = final[j];
        } else {
            vencedores[i] = final[j + 1];
        }
        j += 2;
    }
    
    return vencedores;
}

int main() {
    Equipe equipes[16] = {
        {1, "A"}, {2, "B"}, {3, "C"}, {4, "D"},
        {5, "E"}, {6, "F"}, {7, "G"}, {8, "H"},
        {9, "I"}, {10, "J"}, {11, "K"}, {12, "L"},
        {13, "M"}, {14, "N"}, {15, "O"}, {16, "P"}
    };

    CopaDoMundo *copa = malloc(sizeof(CopaDoMundo));
    copa->n = JOGOS;
    copa->jogos = malloc(JOGOS * sizeof(Jogo));

    for (int i = 0; i < JOGOS; i++) {
        scanf("%d %d", &copa->jogos[i].placar0, &copa->jogos[i].placar1);
    }

    Equipe *vencedoresOitavas = oitavas(copa, equipes);
    Equipe *vencedoresQuartas = quartas(copa, vencedoresOitavas);
    Equipe *vencedoresSemi = semi(copa, vencedoresQuartas);
    Equipe *vencedor = final(copa, vencedoresSemi);
    printEquipes(vencedor, FINAL);

    free(vencedoresOitavas);
    free(copa->jogos);
    free(copa);

    return 0;
}
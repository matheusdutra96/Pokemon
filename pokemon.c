#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

Pokemon leituraPokemon()
{
    int copia1=0;/* variáveis auxiliares para mantes os laços do while
    para as alocações dinâmicas no final desta função*/


    Pokemon pokemon;

    move *Moves;

    pokemon.nomepokemon=(Pokemon *) malloc(100*sizeof(char));


    printf("Digite o nome do pokemon:\n");
    scanf("%s",pokemon.nomepokemon);

    printf("Digite o numero do pokemon:\n");
    scanf("%d",&pokemon.numpokemon);

    printf("Digite o nivel do pokemon:\n");
    scanf("%d",&pokemon.nivelpokemon);

    printf("Digite os valores de ataque,defesa e hp do pokemon:\n");
    scanf("%d %d %d",&pokemon.ataque,&pokemon.defesa,&pokemon.hpatual);

    pokemon.hpmaxima=pokemon.hpatual;

    printf("Digite o numero de golpes do pokemon:\n");
    scanf("%d",&pokemon.numerodegolpes);

    pokemon.golpe=(move *) malloc(pokemon.numerodegolpes*(sizeof(move)));

    //laço para preenche os golpes do pokemon.

    while(copia1<pokemon.numerodegolpes)
    {
        pokemon.golpe[copia1].nomegolpe=(char *)  malloc(100*(sizeof(char)));

        printf("Digite o nome do golpe do pokemon:\n");
        scanf("%s",pokemon.golpe[copia1].nomegolpe);

        printf("Digite o valor base do golpe do pokemon:\n");
        scanf("%d",&pokemon.golpe[copia1].base);
        copia1+=1;
    }

    return pokemon;
}
int estaVivo(Pokemon p)
{
    if(p.hpatual>0)
        return 1;
    else
        return 0;
}

char* nomePokemon(Pokemon p)
{
    return p.nomepokemon;
}

int numeroPokemon(Pokemon p)
{
    return p.numpokemon;
}

int numeroGolpes(Pokemon p)
{
    return p.numerodegolpes;
}

int ataque(Pokemon p1, int m, Pokemon *p2)
{
    int dano;

    dano=(((float)((float)(2*p1.nivelpokemon+10)/250)*((float)p1.ataque/p2->defesa) * p1.golpe->base +2))*4;
    (*p2).hpatual-=dano;

    return dano;
}

void curaPokemon(Pokemon *p)
{
    p->hpatual=p->hpmaxima;

}
void desaloca_moves(Pokemon pokemon,int n)
{
    int copia1=0;

    while(copia1<n)
    {
        free(pokemon.golpe[copia1].nomegolpe);
        free(pokemon.golpe->nomegolpe);
        free(pokemon.golpe);
        copia1+=1;
    }
}
int continua_batalha(Pokemon p)
{
    if(p.hpmaxima==p.hpatual)
        return 1;
    if(p.hpmaxima<p.hpatual)
        return 0;

}

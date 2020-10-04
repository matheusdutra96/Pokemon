#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

int main()
{
    int cont=0,opcao,num_pokes,pokemon_attack=1,p1,p2,pergunta=0;
    int copia=0;
    char novabatalha='S';//variável para determinar se o usuário quer lutar novamente.

    Pokemon *pont;

    printf("Digite o numero total de pokemons: \n");
    scanf("%d",&num_pokes);

    pont=(Pokemon *) malloc(num_pokes*(sizeof(Pokemon)));

    while(copia<num_pokes)
    {
        pont[copia]=leituraPokemon();
        copia+=1;
    }

    printf("\n");

    printf("Digite o numero do primeiro pokemon a atacar: \n");
    scanf("%d",&p1);
    p1-=1;

    printf("Digite o numero do segundo pokemon a atacar: \n");
    scanf("%d",&p2);
    p2-=1;

    // Laço para manter a batalha enquanto os dois pokemons estiverem vivos.

    while(estaVivo(pont[p1])==1 && estaVivo(pont[p2])==1 && novabatalha=='S')
    {

        if(continua_batalha(pont[p1])==1 && continua_batalha(pont[p2])==1 && pergunta==1)
        {
            printf("Digite o numero do primeiro pokemon a atacar: \n");
            scanf("%d",&p1);
            p1-=1;

            printf("Digite o numero do segundo pokemon a atacar: \n");
            scanf("%d",&p2);
            p2-=1;
          }

        if(pokemon_attack==1)
        {
            printf("O pokemon %s esta atacando.\n",nomePokemon(pont[p1]));
            printf("Digite o movimento que ele deve usar.(1 a %d)\n",numeroGolpes(pont[p2]));
            scanf("%d",&opcao);

            printf("Dano causado em %s = %d\n",nomePokemon(pont[p2]),ataque(pont[p1],opcao,&pont[p2]));
            pokemon_attack=2;
            cont+=1;
        }
        // Verifica se pokemon2 continua vivo.
        if(estaVivo(pont[p2])==1)
        {
            if(pokemon_attack==2)
            {
                printf("O pokemon %s esta atacando.\n",nomePokemon(pont[p2]));
                printf("Digite o movimento que ele deve usar.(1 a %d)\n",numeroGolpes(pont[p2]));
                scanf("%d",&opcao);
                printf("Dano causado em %s = %d\n",nomePokemon(pont[p1]),ataque(pont[p2],opcao,&pont[p1]));
                pokemon_attack=1;
                cont+=1;
            }
        }

        if (estaVivo(pont[p1])==0 || estaVivo(pont[p2])==0)
        {

            printf("Fim da batalha!\n");
            if (estaVivo(pont[p1])==1)
            {
                printf("O pokemon %s(#%d)venceu apos %d movimentos!\n",nomePokemon(pont[p1]),numeroPokemon(pont[p1]),cont);
            }
            if (estaVivo(pont[p2])==1)
            {
                printf("O pokemon %s(#%d)venceu apos %d movimentos!\n",nomePokemon(pont[p2]),numeroPokemon(pont[p2]),cont);
            }
            printf("\n");
            printf("Deseja simular outra batalha?\n");
            scanf(" %c",&novabatalha);
            if(novabatalha=='S')
            {
                curaPokemon(&pont[p1]);
                curaPokemon(&pont[p2]);
                pergunta=1;
                printf("\n");
            }
            copia=0;
            if(novabatalha=='N')
            {
                while(copia<num_pokes)
                {
                    desaloca_moves(pont[copia],numeroGolpes(pont[copia]));
                    free(nomePokemon(pont[copia]));
                    free(pont);
                    copia+=1;
                }
            }
        }
    }
    return 0;
}

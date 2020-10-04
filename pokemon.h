#ifndef POKEMON_H
#define POKEMON_H

typedef struct
{
    char* nomegolpe;
    int base;

}move;

typedef struct
{
   move *golpe;
   char* nomepokemon;
   int numpokemon,nivelpokemon,ataque,defesa,hpmaxima,hpatual,numerodegolpes;

}Pokemon;

//Lê os dados pokémons
Pokemon leituraPokemon();

//retorna 1 se o hp atual do Pokemon é maior que 0 e 0 se o hp do pokémon é menor ou igual a 0.
int estaVivo(Pokemon p);

 //retorna o nome do pokémon.
char* nomePokemon(Pokemon p);

//retorna o número do pokémon
int numeroPokemon(Pokemon p);

//retorna o número de golpes de um pokemon.
int numeroGolpes(Pokemon p);

//simula um ataque do Pokemon p1 ao Pokemon p2 utilizando o golpe m, retornando o dano causado.
int ataque(Pokemon p1, int m, Pokemon *p2);

//restaura o hp do pokemon ao máximo.
void curaPokemon(Pokemon *p);

//Desaloca memória dos golpesdos pokemons,o n éa variável para rodar o loop do free.
void desaloca_moves(golpes,n);

//checa se a batalha já começou.
int continua_batalha(Pokemon p);

#endif

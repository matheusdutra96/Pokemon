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

//L� os dados pok�mons
Pokemon leituraPokemon();

//retorna 1 se o hp atual do Pokemon � maior que 0 e 0 se o hp do pok�mon � menor ou igual a 0.
int estaVivo(Pokemon p);

 //retorna o nome do pok�mon.
char* nomePokemon(Pokemon p);

//retorna o n�mero do pok�mon
int numeroPokemon(Pokemon p);

//retorna o n�mero de golpes de um pokemon.
int numeroGolpes(Pokemon p);

//simula um ataque do Pokemon p1 ao Pokemon p2 utilizando o golpe m, retornando o dano causado.
int ataque(Pokemon p1, int m, Pokemon *p2);

//restaura o hp do pokemon ao m�ximo.
void curaPokemon(Pokemon *p);

//Desaloca mem�ria dos golpesdos pokemons,o n �a vari�vel para rodar o loop do free.
void desaloca_moves(golpes,n);

//checa se a batalha j� come�ou.
int continua_batalha(Pokemon p);

#endif

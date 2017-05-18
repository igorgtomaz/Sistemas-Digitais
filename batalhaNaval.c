#include <stdio.h>
#include <stdlib.h>

  void codifica_jogada(int *jog){

  if (jog[0] == 0 && jog[1] == 0 && jog[2] == 0)
    jog[2] = 1;
  if (jog[0] == 0 && jog[1] == 1 && jog[2] == 1)
  {
    jog[0] = 1;
    jog[1] = 0;
    jog[2] = 0;
  }
  if (jog[0] == 1 && jog[1] == 0 && jog[2] == 1)
  {
    jog[0] = 0;
    jog[1] = 1;
    jog[2] = 1;
  }
  if (jog[0] == 1 && jog[1] == 1 && jog[2] == 0)
  {
    jog[0] = 1;
    jog[1] = 1;
    jog[2] = 0;
  }
  if (jog[0] == 1 && jog[1] == 1 && jog[2] == 1)
  {
    jog[0] = 1;
    jog[1] = 0;
    jog[2] = 1;
  }

}

void jogadas()
{
  int jog1[3], jog2[3], i;

  for (i = 0; i < 3; i++)
  {
    printf("Jogada %d do Jogador 1: ", i);
    scanf("%d", &jog1[i]);
  }

  codifica_jogada(jog1);

  for (i = 0; i < 3; i++)
  {
    printf("Jogada %d do Jogador 2: ", i);
    scanf("%d", &jog2[i]);
  }

  if (jog1[0] == jog2[0] && jog1[1] == jog2[1] && jog1[2] == jog2[2])
    printf("Jogador 2 acertou.\n");
  else
      printf("Jogador 2 errou.\n");
}

int main()
{
  jogadas();

  return 0;
}

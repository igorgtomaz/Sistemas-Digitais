/*
  Este programa pega as coordenadas do arquivo entradaT3.txt
  e imprime os triangulos com seu resultado.
  A função maiorMenor faz com que o triangulo seja impresso
  no tamanho certo.
*/

#include <stdio.h>
#include <stdlib.h>

void maiorMenor(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y, float *mX, float *mY)
{
  if (xa > xb && xa > xc && xa > x)
      *mX = xa;
  else if (xb > xa && xb > xc && xb > x)
      *mX = xb;
  else if (xc > xa && xc > xb && xc > x)
      *mX = xc;
  else if (x > xa && x > xb && x > xc)
      *mX = x;

  if (ya > yb && ya > yc)
      *mY = ya;
  else if (yb > ya && yb > yc)
      *mY = yb;
  else if (yc > ya && yc > yb)
      *mY = yc;
  else if (y > ya && y > yb && y > yc)
      *mY = y;
}

int pontoTriangulo(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y)
{
  float a, b, c;

  a = ((x-xa)*(yb-ya))-((y-ya)*(xb-xa));
  b = ((x-xb)*(yc-yb))-((y-yb)*(xc-xb));
  c = ((x-xc)*(ya-yc))-((y-yc)*(xa-xc));

  if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0))
    return 1;
  else
    return 0;
}

int main()
{
  float xa, xb, xc, ya, yb, yc, x, y, maiorX = 0, maiorY = 0;
  int i, j;
  FILE *ent;

  ent = fopen("entradaT3.txt", "r");

  if(ent == NULL)
    printf("Erro ao abrir arquivo.\n");
  else
  {
    while ((fscanf(ent, "%f %f %f %f %f %f %f %f\n", &xa, &ya, &xb, &yb, &xc, &yc, &x, &y)) != EOF)
    {
      maiorMenor(xa, ya, xb, yb, xc, yc, x, y, &maiorX, &maiorY);

      for(i = 0; i < (maiorX+20); i++){
        for(j = 0; j < (maiorY+20); j++){
          if (pontoTriangulo(xa, ya, xb, yb, xc, yc, i, j) == 1)
          {
              if (x == i && y == j)
              {
                printf("x");
              }
              else
                printf("*");
          }
          else
          if (x == i && y == j)
            printf("x");
          else
            printf(" ");
        }
        printf("\n");
      }
    }
  }
  fclose(ent);
}

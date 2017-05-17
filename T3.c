#include <stdio.h>
#include <stdlib.h>


int pontoTriangulo(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y)
{
  float aux, a, b, c;

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
  FILE *ent, *sai;

  ent = fopen("entrada.txt", "r");
  sai = fopen("saida.txt", "w+");

  if(ent == NULL || sai == NULL)
    printf("Erro ao abrir arquivos.\n");
  else
  {
    while ((fscanf(ent, "%f %f %f %f %f %f %f %f\n", &xa, &ya, &xb, &yb, &xc, &yc, &x, &y)) != EOF)
    {
      for(i = 0; i < 50; i++){
        for(j = 0; j < 50; j++){
          if (pontoTriangulo(xa, ya, xb, yb, xc, yc, i, j) == 1)
          {
              if (x == i && y == j)
              {
                printf("x");
                fprintf(sai, "O ponto (%.1f, %.1f) pertence ao triangulo de coordenadas A(%.1f, %.1f), B(%.1f, %.1f) e C(%.1f, %.1f).\n", x, y, xa, ya, xb, yb, xc, yc);
              }
              else
                printf("*");
          }
          else
          if (x == i && y == j)
          {
            printf("x");
            fprintf(sai, "O ponto (%.1f, %.1f) não pertence ao triangulo de coordenadas A(%.1f, %.1f), B(%.1f, %.1f) e C(%.1f, %.1f).\n", x, y, xa, ya, xb, yb, xc, yc);
          }
          else
            printf(" ");
        }
        printf("\n");
      }
    }
  }
  fclose(ent);
  fclose(sai);
}

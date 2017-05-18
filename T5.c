#include<stdlib.h>
#include<stdio.h>

int main(){
    char c1, c2;
    FILE *ent_c,*ent_v,*Resultado;

    int verif = 0;

    ent_c = fopen("saidaT3.txt","r");
    ent_v = fopen("saidaT4.txt","r");
    Resultado = fopen("resultComparacao.txt","w");

    while(!feof(ent_c)){

        c1 = fgetc(ent_c);
        c2 = fgetc(ent_v);

        if(c1 != c2)
        {
            fprintf(Resultado,"%c difere de %c\n", c1, c2);
            verif++;
        }
        else
            fprintf(Resultado, "%c", c1);

    }

      if (verif > 0)
        fprintf(Resultado, "Os resultados sao diferentes.");
      else
        fprintf(Resultado, "Os resultados sao identicos.");

    fclose(ent_c);
    fclose(ent_v);
    fclose(Resultado);

    return(0);
}

#include<stdio.h>

main(){

FILE *arquivo;
int caractere, i;
char nome[11];
printf("Abrindo o arquivo Nomes.txt\n");
arquivo = fopen ("Nomes.txt", "r"); // fopen retorna null se o arquivo não exite, e o ponteiro para o arquivo se o arquivo exite.
if(arquivo==NULL)
{
    printf("Arquivo nao encontrado!");
    exit(1);

}
i = 0;
 while (!feof(arquivo)) // feof retorna verdadeiro se chegou no arquivo e retorna falso se não chegou no final
 {
     caractere = fgetc (arquivo); // ler o caractere e vai para o proximo
     //printf("%c", caractere);
     if(caractere != 10)
     {
         nome[i] = (char) caractere;
         i++;

     }
     else{
        nome[i] = '\0';
        i=0;
        printf("Nome lido = %s\n", nome);

     }
 }
fclose (arquivo);

}



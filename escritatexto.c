#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//programa que ler texto
//arquivos textuais
//abertura de arquivo textual
int main()
{

    int tam;
    char texto[100];
    char filename[50]= "C:\\Users\\1493789\\Documents\\Arquivos\\teste.txt"; //nome do arquivo, texto

    FILE *f;
    f = fopen(filename,"w");
    if(f==NULL)
    {
        printf("Problema ao abrir o arquivo...");
        exit(0);

    }
    printf( " Digite uma mmensagem  para ser salvo no arquivo:\n");
    fgets(texto,100, stdin); //entrada padrão=stdin . terminador de string \0
    tam = strlen(texto);
    if(texto[tam-1]== '\n'&& tam > 0)
    {
        texto[tam-1] = '\0';
        tam--;
    }
    for(int i = 0; i < strlen(texto); i++)
    {
        fputc(texto[i],f);

    }

    fputc('\n', f);

    printf( " Digite uma mmensagem  para ser salvo no arquivo:\n");
    fgets(texto,100, stdin); //entrada padrão=stdin . terminador de string \0
    tam = strlen(texto);
    if(texto[tam-1]== '\n'&& tam > 0)
    {
        texto[tam-1] = '\0';
        tam--;
    }

    fputs(texto,f);
    fputc('\n',f);
    fclose(f);

    return 1;

}

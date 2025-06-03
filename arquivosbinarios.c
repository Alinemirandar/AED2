#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//arquivo binario salva os bits no arquivo

typedef struct
{
    int id;
    char nome[20];
    char raca[20];
    int idade;
    float peso;


} cao;

cao registracao();
void escrevearquivo(char *filename, cao *v, int n);
int learquivo(char *fileneme, cao *v, int n);


int main()
{
    cao v[10];
    int n;

    char filename [20] = "caes.b";

    n = learquivo(filename, v, 10);

    printf("Exibindo caes cadastrados:\n\n");
    for(int i=0; i<n; i++)
    {
        printf("id:%d\n", v[i].id);
        printf("nome:%s\n", v[i].nome);
        printf("raca:%s\n", v[i].raca);
        printf("idade:%d\n", v[i].idade);
        printf("peso:%f\n", v[i].peso);
    }


    printf("Digite quantos caes voce quer cadastrar:\n");
    scanf("%d", &n);

    for(int i = 0; i< n; i++)
    {
        v[i] = registracao();

    }

    escrevearquivo(filename, v, n);



    return 1;
}
cao registracao()
{
    cao c;
    printf("Registrando um cao:\n");
    printf("id:");
    scanf("%d", &c.id);
    getchar();

    printf("Nome: ");
    fgets(c.nome, 20, stdin);

    printf("Raca: ");
    fgets(c.raca, 20, stdin);

    printf("Idade: ");
    scanf("%d", &c.idade);

    printf("Peso: ");
    scanf("%f", &c.peso);

    return c;

}
void escrevearquivo(char *filename, cao *v, int n)
{
    FILE *f = fopen(filename,"wb");
    if(f == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(0);
    }

    fwrite(v,sizeof(cao),n, f);

    fclose(f);

}
int learquivo(char *filename, cao *v, int n)
{

    FILE *f = fopen(filename, "rb");
    if(f == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(0);

    }
    n = fread(v, sizeof(cao), n, f);

    fclose(f);
    return n;
}


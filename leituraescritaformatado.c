#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int id;
    char cor[20];
    float coordX;
    float coordY;
} ponto;
ponto registraPonto();
void escrevePonto(FILE *f, ponto);

int main()
{
    char filename[50]= "pontos.abacate";
    ponto p;
    int n;

    FILE *f = fopen(filename, "a+");
    if(f==NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(0);

    }
    printf("Exibindo pontos registrados : ");
    while (fscanf(f, "%d %s %f %f", &p.id, &p.cor, &p.coordX, &p.coordY)>0)
    {
        printf("%d %s %f %f\n",p.id, p.cor, p.coordX, p.coordY);
    }


    printf("\n----Registando pontos ----\n");
    printf("quantos pontos voce quer registrar?");
    scanf("%d", &n);

    for (int i = 0; i< n; i++)
    {
        p = registraPonto();
        escrevePonto(f, p);
    }

    fclose(f);
    return 1;
}

ponto registraPonto()
{
    ponto p;
    printf("\n---- Registrando pontos ----\n");

    printf("Digite as informacoes do ponto:\n");
    printf("id :");
    scanf("%d", &p.id);
    getchar();
    printf("cor: ");
    scanf("%s", p.cor);
    printf("coordenada X: ");
    scanf("%f", &p.coordX);
    printf("coordenada Y: ");
    scanf("%f", &p.coordY);

    return p;

}
void escrevePonto(FILE *f, ponto p)
{
    fprintf(f, "%d %s %f %f\n", p.id, p.cor, p.coordX, p.coordY);
}


//Ex21.c
//Descrição: Calculo da divisao do mercado
//Autores: 
//       Matheus Pontes
//       Rafael de Souza Pereira
//       Wagner Lucas
//Professor: Ruben C Benante
//Data: 26/10/2015

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXI 3                                  //máximo de integrantes
#define MAXL 80                                 //quantidade de letras para os nomes
#define MAXV (MAXI*MAXI)-n                      //quantidades de valores para entrade de dados

int main (void)
{
    int n=0;                                    
    int i, j;                                   //contadores
    int k;                                      //posição do vetor fixo (integrante que pagou a conta)
    float valor[MAXV], deve[MAXI], X=0;         //vetores para os valores das perguntas e  
    char nome[MAXI][MAXL], r, *p;
    
    for(i=1;i<MAXI;i++)
        n+=i;

    printf("Calculo da divisao do mercado\n\n");

    /*Entrada de dados*/

    //preenchimento das strings com o nome dos integrantes
    do
    {   
        for(i=0;i<MAXI;i++)
        {
            printf("Nome do %d° integrante?\n", i+1);
            fgets(nome[i], MAXL, stdin);
            if((p=strchr(nome[i], '\n'))) *p='\0';
        }
        
        printf("\nOk! Os integrantes sao:\n");

    //impressão das strings
        for(i=0;i<MAXI;i++) 
            printf("O %d° integrante eh: %s\n", i+1, nome[i]);
        
        printf("Tudo certo? (S/N)\n");
        r=getchar();
        getchar();
    } 
    while(r!='S');
    
    printf("\nQual foi o valor total da conta?\n");
    scanf("%f", &valor[MAXV]);

    printf("\nQuem pagou a conta? (1-%d)\n", MAXI);

    for(i=0;i<MAXI;i++)
        printf("%d- %s\n", i+1, nome[i]);
    scanf("%d", &k);
    k=k-1;
    
    //combinação dos integrantes

    //combinação individual
    for(i=0;i<MAXI;i++)
    {
        printf("Quanto %s pagou que somente %s quer?\n", nome[k], nome[i]);
        scanf("%f", &valor[i]);
    }
    
    //combinação das duplas
    for(i=0;i<MAXI-1;i++)
        for(j=1;j<MAXI;j++)       
            if(i!=j && j>i)
            {
                printf("Quanto %s e %s gastaram que somente eles(as) querem?\n", nome[i], nome[j]);
                scanf("%f", &valor[i+j+2]);
            }
    
    //valor total gasto pelos integrantes
    for(i=0;i<MAXV;i++)
        X+=valor[i];
    printf("O valor que todos gastaram foi R$ %.2f.\n", valor[MAXV]-X);

    /*processamento*/
      
    deve[0]=valor[0]+(valor[3]/2)+(valor[4]/2)+((valor[MAXV]-X)/3);
    deve[1]=valor[1]+(valor[3]/2)+(valor[5]/2)+((valor[MAXV]-X)/3);
    deve[2]=valor[2]+(valor[4]/2)+(valor[5]/2)+((valor[MAXV]-X)/3);
    
    /*resultados*/

    for(i=0;i<MAXI;i++)
    {
        if(i!=k)
            printf("%s deve R$ %.2f.\n", nome[i], deve[i]);
        else        
            printf("%s recebe R$ %.2f.\n", nome[i], valor[MAXV]-deve[i]);
    }
 
    return EXIT_SUCCESS;
}

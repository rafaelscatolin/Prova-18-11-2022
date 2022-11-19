//RAFAEL VERCEZI SCATOLIN 768377

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node{
int codigo; // campo 1
float custo, venda, impostos, margem; // campos 2, 3, 4 e 5 respectivamente

} produto;

void limpa_dados(produto *p){
    for (int i =0 ; i < MAX; i++){
        p[i].codigo=0;
        p[i].custo=p[i].venda=p[i].margem=0;
        p[i].impostos=i%2==0?.18:.15;
    }
}

float gera_custo (){ // gera custos de até 3000.00
    int d1=rand()%3001;
    int d2 = rand()%701;
    return (float) d1/d2;
}
float gera_margem (){// gera margem de até 25%
     int val = rand()%26;
    return (float)val/100.0;
}

void gera_dados(produto *p){
    for (int i =0 ; i < MAX; i++){
        p[i].codigo=i + 1000;
        p[i].margem=gera_margem();
        p[i].impostos=i%2==0?.18:.15;
        p[i].custo=gera_custo();
        p[i].venda= p[i].custo +  p[i].impostos*p[i].custo + p[i].margem*p[i].custo;
    }
}

void imprime (produto *p){
printf ("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");
printf ("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for (int i =0 ; i < MAX; i++)
        printf ("%d \t\t%4.2f \t\t%4.2f \t\t%.2f \t\t%.2f\n",
               p[i].codigo, p[i].custo, p[i].venda, p[i].impostos, p[i].margem );
printf ("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");

}


void organiza_ascendente (produto *p) {
	
	int codigo;
	float custo, venda, impostos, margem;
	
	for (int j=0; j<MAX; j++)
	
		for (int i=0; i<MAX; i++)
		
			if (p[i].venda < p[j].venda) {
				
				codigo = p[j].codigo;
				custo = p[j].custo;
				venda = p[j].venda;
				impostos = p[j].impostos;
				margem = p[j].margem;
				
				p[j].codigo = p[i].codigo;
				p[j].custo = p[i].custo;
				p[j].venda = p[i].venda;
				p[j].impostos = p[i].impostos;
				p[j].margem = p[i].margem;
				
				p[i].codigo = codigo;
				p[i].custo = custo;
				p[i].venda = venda;
				p[i].impostos = impostos;
				p[i].margem = margem;
			}
	
}


void organiza_descendente (produto *p) {
	
	int codigo;
	float custo, venda, impostos, margem;
	
	for (int j=0; j<MAX; j++)
	
		for (int i=0; i<MAX; i++)
		
			if (p[i].custo > p[j].custo) {
				
				codigo = p[j].codigo;
				custo = p[j].custo;
				venda = p[j].venda;
				impostos = p[j].impostos;
				margem = p[j].margem;
				
				p[j].codigo = p[i].codigo;
				p[j].custo = p[i].custo;
				p[j].venda = p[i].venda;
				p[j].impostos = p[i].impostos;
				p[j].margem = p[i].margem;
				
				p[i].codigo = codigo;
				p[i].custo = custo;
				p[i].venda = venda;
				p[i].impostos = impostos;
				p[i].margem = margem;
			}
	
}

int valor_buscado, i, result=-1;

int busca (int valor_buscado, produto *p, int minimo, int maximo) {

	for (int i=minimo; i<maximo; i++)
		if (p[i].codigo == valor_buscado)
			result = i;
		
	return result;
}




int main (){
srand(time(NULL));
produto produtos[MAX];
limpa_dados(produtos);
gera_dados(produtos);
imprime(produtos);



printf("\n\n\n\n\n\n\n");
organiza_ascendente(produtos);//Organiza de forma ascendente por vendas
imprime(produtos);
printf("\n\n\n\n\n\n\n");
organiza_descendente(produtos);//Organiza de forma descendente por custos
imprime(produtos);

printf("\n\n\n\n\n\n\n");


int b = busca(1623,produtos,0,MAX);
if (b!=-1)
    printf ("\nProduto %d encontrado:\nCusto: %.2f\nVenda: %.2f\nTaxas + Imp: %.2f%%\n",
        produtos[b].codigo, produtos[b].custo, produtos[b].venda, (produtos[b].impostos + produtos[b].margem)*100);
    else
        printf ("\nPRoduto nao encontrado\n");

printf("\n\n\n\n\n\n\n");

/*
ordena (produtos,3 ); // aplique bubble sort neste campo 3 ascedente
imprime(produtos);
ordena (produtos,2 ); // aplique bubble sort neste campo 2 descedente
????????????????;
int b = busca(1623,produtos,0,MAX); // implementar
if (b!=-1)
    printf ("\nProduto %d encontrado:\nCusto: %.2f\nVenda: %.2f\nTaxas + Imp: %.2f%%\n",
        p[i].codigo, p[i].custo, p[i].venda, (p[i].impostos + p[i].margem)*100 );
    else
        printf ("\nPRoduto nao encontrado\n");
*/
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//nome do arquivo principal
#define FILE_NAME "produtos.txt"
//nome do arquivo temporário
#define FILE2_NAME "produtos2.txt"

FILE *arquivo2;
FILE *arquivo;

//para guardar quantos produtos já temos
int qtde_p;

typedef struct produto{
  char nome[40];
  float preco;
  char tipo[40];
  int qtde;
}produto_f;

void inserir(produto_f* vetor_inserir, int qtde_inserir){
  vetor_inserir = 
    (produto_f*)malloc(qtde_inserir*sizeof(produto_f));
  
  for(int i=0; i<qtde_inserir; i++){
    printf("\ndigite nome do produto:\n");
    scanf("%s", vetor_inserir[i].nome);
    printf("digite preco do produto:\n");
    scanf("%f", &vetor_inserir[i].preco);
    printf("digite tipo do produto:\n");
    scanf("%s", vetor_inserir[i].tipo);
    printf("digite qtde do produto:\n");
    scanf("%d", &vetor_inserir[i].qtde);
  }
  
  arquivo = fopen(FILE_NAME, "a");
  fwrite(vetor_inserir, sizeof(produto_f), qtde_inserir, arquivo);
  fclose(arquivo);
  free(vetor_inserir);
  
  if(qtde_inserir==1)
    printf("\nproduto inserido\n");
  else
    printf("\nprodutos inseridos\n");
}

void pesquisar(produto_f* vetor_pesquisar, int qtde_p){
  char nome_pesquisar[40];
  int achou=0;
  
  arquivo = fopen(FILE_NAME, "r");
  vetor_pesquisar = 
    (produto_f*)malloc(qtde_p*sizeof(produto_f));
  fread(vetor_pesquisar, sizeof(produto_f), qtde_p, arquivo);
  
  printf("\ndigite nome para pesquisar:\n");
  scanf("%s", nome_pesquisar);
  
  for(int i=0; i<qtde_p; i++){
    if(strcmp(vetor_pesquisar[i].nome,nome_pesquisar)==0){
      printf("\nproduto encontrado\n");
      achou++;
      
      printf("Nome do produto: %s\n", vetor_pesquisar[i].nome);
      printf("Preco do produto: %.2f\n", vetor_pesquisar[i].preco);
      printf("Tipo do produto: %s\n", vetor_pesquisar[i].tipo);
      printf("Qtde do produto: %d\n", vetor_pesquisar[i].qtde);
      break;
    }
  }
  if(achou==0){
    printf("produto não encontrado\n");
  }
  
  fclose(arquivo);
  free(vetor_pesquisar);
}

void alterar(produto_f* vetor_alterar){
  char nome_alterar[40];
  int achou=0;
  
  arquivo = fopen(FILE_NAME, "r");
  vetor_alterar = 
    (produto_f*)malloc(qtde_p*sizeof(produto_f));
  fread(vetor_alterar, sizeof(produto_f), qtde_p, arquivo);
  
  printf("\ndigite nome para alterar:\n");
  scanf("%s", nome_alterar);
  
  for(int i=0; i<qtde_p; i++){
    if(strcmp(vetor_alterar[i].nome,nome_alterar)==0){
      printf("produto encontrado\n");
      achou=1;
      
      printf("digite novo nome do produto:\n");
      scanf("%s", vetor_alterar[i].nome);
      printf("digite novo preco do produto:\n");
      scanf("%f", &vetor_alterar[i].preco);
      printf("digite novo tipo do produto:\n");
      scanf("%s", vetor_alterar[i].tipo);
      printf("digite nova qtde do produto:\n");
      scanf("%d", &vetor_alterar[i].qtde);
      break;
    }
  }
  if(achou==0){
    printf("produto não encontrado\n");
  }
  else{
    //abrindo arquivo temporário
    arquivo2=fopen(FILE2_NAME, "a");
    
    //colocando informações atualizadas nele
    fwrite(vetor_alterar, sizeof(produto_f), qtde_p, arquivo2);
    
    //fechando arquivo
    fclose(arquivo2);
    
    //excluindo 1o arquivo
    /* renomeando segundo arquivo para
    nome do 1o */
    remove(FILE_NAME);
    rename(FILE2_NAME, FILE_NAME);
    
    free(vetor_alterar);
  }
}

void remover(produto_f* vetor_remover){
  char nome_remover[40];
  int achou=0;
  
  arquivo = fopen(FILE_NAME, "r");
  vetor_remover = 
    (produto_f*)malloc(qtde_p*sizeof(produto_f));
  fread(vetor_remover, sizeof(produto_f), qtde_p, arquivo);
  
  printf("\ndigite nome para remover:\n");
  scanf("%s", nome_remover);
  
  for(int i=0; i<qtde_p; i++){
    if(strcmp(vetor_remover[i].nome,nome_remover)==0){
      achou++;
      
       for(int j = i; j<qtde_p;j++){
        if(j==qtde_p-1){
          //ultimo elemento zerado
          //ele não vai ser contado por causa do "qtde_p--" abaixo
          strcpy(vetor_remover[j].nome,"0"); 
          vetor_remover[j].preco=0;          
          strcpy(vetor_remover[j].tipo,"0");
          vetor_remover[j].qtde=0;
        }
         else{
          //trazendo os elementos para frente
          strcpy(vetor_remover[j].nome,vetor_remover[j+1].nome); 
          vetor_remover[j].preco=vetor_remover[j+1].preco;          
          strcpy(vetor_remover[j].tipo,vetor_remover[j+1].tipo);
          vetor_remover[j].qtde=vetor_remover[j+1].qtde; 
        }
      }
    }
   } 
  if(achou==0){
    printf("produto não encontrado\n");
  }
  else{
    printf("produto removido\n");
    qtde_p--;
    
    //abrindo e escrevendo no arquivo temporário
    arquivo2=fopen(FILE2_NAME, "a");
    fwrite(vetor_remover, sizeof(produto_f), qtde_p, arquivo2);
    
    //fechando arquivo
    fclose(arquivo2);
    
    //excluindo 1o arquivo
    /* renomeando segundo arquivo para
    nome do 1o */
    remove(FILE_NAME);
    rename(FILE2_NAME, FILE_NAME);
    
    free(vetor_remover);}
}
    
void listar(produto_f* vetor_listar, int qtde_p){
  arquivo = fopen(FILE_NAME, "r");
  vetor_listar = 
    (produto_f*)malloc(qtde_p*sizeof(produto_f));
  fread(vetor_listar, sizeof(produto_f), qtde_p, arquivo);
  
  for(int i=0; i<qtde_p; i++){
    printf("\nNome do produto: %s\n", vetor_listar[i].nome);
    printf("Preco do produto: %.2f\n", vetor_listar[i].preco);
    printf("Tipo do produto: %s\n", vetor_listar[i].tipo);
    printf("Qtde do produto: %d\n", vetor_listar[i].qtde);
  }
  fclose(arquivo);
  free(vetor_listar);
}

int main()
{
  int opcao;
  produto_f* vetor_inserir;
  produto_f* vetor_pesquisar;
  produto_f* vetor_listar;
  produto_f* vetor_remover;
  produto_f* vetor_alterar;
  int qtde_inserir;
  
  while(opcao!=6){
  if(qtde_p==0){
    printf("\n1) inserir\n");
  }
  else{
    printf("\n1) inserir \t 2) alterar\n");
    printf("3) pesquisar \t 4) remover\n");
    printf("5) listar \t 6) sair\n");
  }
  printf("digite a opção:\n");
  scanf("%d", &opcao);
    
  switch(opcao){
    case 1:
      printf("\nQuantos produtos para inserir?\n");
      scanf("%d", &qtde_inserir);
      qtde_p+=qtde_inserir;
      inserir(vetor_inserir, qtde_inserir);
      break;
    
    case 2:
      alterar(vetor_alterar);
      break;
    
    case 3:
      pesquisar(vetor_pesquisar, qtde_p);
      break;
    
    case 4:
      remover(vetor_remover);
      break;
    
    case 5:
      listar(vetor_listar, qtde_p);
      break;
    
    case 6:
      /* estou removendo arquivo porque inicio 
      qtde_p sempre com 0 */
      remove(FILE_NAME);
      break;
  }} 
  return 0;
}

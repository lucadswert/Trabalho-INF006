#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int main() {
    char menuPrincipal(  );
    void inserir( );
    void listarOfertas( );
    arquivoCompras();
    arquivoVendas();
    int resposta;
    do{
      printf( "\n=====================================\n"
                "||        MERCADO DE AÇÕES         || \n"
                "=====================================\n"
                "[1] | Incluir Ofertas\n"
                "[2] | Mostrar as Ofertas Disponíveis\n"
                "[3] | Negociar as Ofertas Disponíveis\n"
                "[4] | Excluir Oferta\n"
                "[0] | Encerrar\n-> " );
      scanf("%d", &resposta);
      switch( resposta ){
          case 1: inserir( ); break;
          case 2: listarOfertas( ); break;
          case 3: negociarOfertas(); break;
          case 4: apagarOfertas(); break;
          case 0: printf( "\n <<<<<<<<< Programa Encerrado >>>>>>>>>\n\n" );
          break;}
      }while(resposta != 0);
        return 0;
}

void inserir( ){
  Compra compra;
  Venda venda;
  int qtd, opAcao;
  float valor;
  int resposta;
  do{
    printf( "\n=====================================\n"
            "||          MENU - INSERIR         || \n"
            "=====================================\n"
            "[1] | Compra\n"
            "[2] | Venda\n"
            "[0] | Voltar \n-> " );
        scanf("%d", &resposta);
        getchar();
        switch(resposta){
          case 1:
            printf("=====================================\n"
                  "||         OFERTA DE COMPRA        ||\n"
                  "=====================================\n");
                do{
                  printf("Que ação deseja comprar?\n");
                  printf("[1] | PETR4 (PETROBRAS)\n");
                  printf("[2] | VALE5 (VALE)\n");
                  printf("[3] | ITSA4 (ITAÚ)\n");
                  printf("[0] | VOLTAR\n-> ");
                  scanf("%d", &opAcao);
                  getchar();
                  if(opAcao < 0 || opAcao > 3){
                    puts("OPÇAO INVÁLIDA!");
                  }
                  }while(opAcao < 0 || opAcao > 3);
                  if(opAcao == 0){
                    break;}
                  do{
                  printf("\nInsira a quantidade:\n-> ");
                  scanf("%d", &qtd);
                  if(qtd < 0){
                  puts("INSIRA UMA QUANTIDADE POSITIVA!\n");
                  }
                  }while(qtd < 0);
                  do{
                  printf("\nInsira o valor:\n-> ");
                  scanf("%f", &valor);
                  if(valor < 0){
                  puts("INSIRA UM VALOR POSITIVO!\n");
                  }
                  }while (valor < 0);
                  listaCompra = inserir_lista_compra(listaCompra, qtd, valor, opAcao);
          case 2:
           printf("=====================================\n"
                  "||        OFERTA DE VENDA          ||\n"
                  "=====================================\n");
               do{
                  printf("Que ação deseja vender?\n");
                  printf("[1] | PETR4 (PETROBRAS)\n");
                  printf("[2] | VALE5 (VALE)\n");
                  printf("[3] | ITSA4 (ITAÚ)\n");
                  printf("[0] | VOLTAR\n-> ");
                  scanf("%d", &opAcao);
                  getchar();
                  if(opAcao < 0 || opAcao > 3){
                    puts("OPÇAO INVÁLIDA!");
                  }
                  }while(opAcao < 0 || opAcao > 3);
                  if(opAcao == 0){
                    break;}
                  do{
                  printf("\nInsira a quantidade:\n-> ");
                  scanf("%d", &qtd);
                  if(qtd < 0){
                  puts("INSIRA UMA QUANTIDADE POSITIVA!\n");
                  }
                  }while(qtd < 0);
                  do{
                  printf("\nInsira o valor:\n-> ");
                  scanf("%f", &valor);
                  if(valor < 0){
                  puts("INSIRA UM VALOR POSITIVO!\n");
                  }
                  }while (valor < 0);
                  listaVenda = inserir_lista_venda(listaVenda, qtd, valor, opAcao);
          break;
          default:
          break;
          }
    }while (resposta != 0);
}

void arquivoCompras(){
    Compra arquivo;   
    FILE * file  = fopen("compras.txt","r");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.sigla,&arquivo.qtd,&arquivo.valor) != EOF ){
            listaCompra = inserir_lista_compra(listaCompra,arquivo.qtd, arquivo.valor, arquivo.sigla);
        }
    }
    fclose(file);
}

void arquivoVendas(){
    Venda arquivo;   
    FILE * file  = fopen("vendas.txt","r");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.sigla,&arquivo.qtd,&arquivo.valor) != EOF ){
            listaVenda = inserir_lista_venda(listaVenda,arquivo.qtd, arquivo.valor, arquivo.sigla);
        }
    }
    fclose(file);
}

void listarOfertas(){
  int resposta;
  int opAcao;
  do{
    printf( "\n=====================================\n"
            "||          MENU - LISTAR          ||\n"
            "=====================================\n"
            "[1] | Todas\n"
            "[2] | Compra\n"
            "[3] | Venda\n"
            "[0] | Voltar \n-> " );
        scanf("%d", &resposta);
        getchar();
        switch(resposta){
          case 1:
            consultar_lista_compra(listaCompra);
            consultar_lista_venda(listaVenda);
          break;
          case 2:
            do{
            printf( "\n=====================================\n"
                    "||         LISTAR - COMPRA         ||\n"
                    "=====================================\n"
                    "[1] | Todas\n"
                    "[2] | PETR4\n"
                    "[3] | VALE5\n"
                    "[4] | ITSA4\n"
                    "[0] | VOLTAR \n-> " );
                    scanf("%d", &opAcao);
                    getchar();
            if(opAcao == 0){
              break;}
            if(opAcao == 1){
            consultar_lista_compra(listaCompra);
            }else{
            consultar_lista_individual(listaCompra, opAcao);}
              }while(opAcao < 1 || opAcao > 4);
          break;
          case 3:
            do{
            printf( "\n=====================================\n"
                    "||          LISTAR - VENDA         ||\n"
                    "=====================================\n"
                    "[1] | Todas\n"
                    "[2] | PETR4\n"
                    "[3] | VALE5\n"
                    "[4] | ITSA4\n"
                    "[0] | VOLTAR \n-> " );
                    scanf("%d", &opAcao);
                    getchar();
            if(opAcao == 0){
              break;}
            if(opAcao == 1){
              consultar_lista_venda(listaVenda);
            }else{
            consultar_lista_venda_individual(listaVenda, opAcao);}
              }while(opAcao < 1 || opAcao > 4);
          break;
          default:
          break;
          }
    }while (resposta != 0);
}

void negociarOfertas(){
  int resposta;
          consultar_registro(listaRegistro);
  do{
     printf( "\n=====================================\n"
             "||            NEGOCIAR             ||\n"
             "=====================================\n"
             "[1] | TODAS\n"
             "[2] | PETR4\n"
             "[3] | VALE5\n"
             "[4] | ITSA4\n"
             "[0] | VOLTAR \n-> " );
             scanf("%d", &resposta);
             getchar();
        if(resposta == 0){
              break;}
        if(resposta == 1){
            consultar_lista_compra(listaCompra);
            consultar_lista_venda(listaVenda);
            listaRegistro = realizarOperacoes(listaRegistro, listaCompra, listaVenda);
        }if(resposta == 2){
            consultar_lista_venda_individual(listaVenda, 1);
            consultar_lista_individual(listaCompra, 1);
        }if(resposta == 3){
            consultar_lista_venda_individual(listaVenda, 2);
            consultar_lista_individual(listaCompra, 2);
        }if(resposta == 4){
            consultar_lista_venda_individual(listaVenda, 3);
            consultar_lista_individual(listaCompra, 3);
        }
    }while(resposta != 0);
}

Registro* realizarOperacoes(Registro* l, Compra* listaCompra, Venda* listaVenda){
  Compra *referenciaCompra = listaCompra;
  Venda *referenciaVenda = listaVenda;
  
  int siglaCompra = referenciaCompra->sigla, siglaVenda = referenciaVenda->sigla;
  int qtdCompra = referenciaCompra->qtd, qtdVenda = referenciaVenda->qtd;
  float valorCompra = referenciaCompra->valor, valorVenda = referenciaVenda->valor;
  
  if(siglaCompra == siglaVenda){
    if(valorCompra > valorVenda || valorCompra == valorVenda ){
      if(qtdCompra > qtdVenda){
        Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
        acoesRegistro->sigla = siglaCompra;
        acoesRegistro->valor = valorCompra;
        acoesRegistro->qtd = referenciaVenda->qtd;
	      acoesRegistro->prox = l;
        referenciaCompra->qtd = qtdCompra  - qtdVenda;
        RemoveDadoEspecificoVenda(qtdVenda, siglaCompra, valorVenda, listaVenda);
        printf("Operações Realizadas\n");
        return acoesRegistro;
      }else if(qtdCompra < qtdVenda){
        Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
        acoesRegistro->qtd = referenciaCompra->qtd;
        acoesRegistro->sigla = siglaCompra;
        acoesRegistro->valor = valorVenda;
        acoesRegistro->prox = l;
        referenciaVenda->qtd = qtdVenda - qtdCompra;
        RemoveDadoEspecifico(qtdCompra, siglaCompra, valorVenda, listaCompra);
        printf("Operações Realizadas\n");
        return acoesRegistro;
      }
      else{
        Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
        acoesRegistro->qtd = qtdCompra;
        acoesRegistro->sigla = siglaCompra;
        acoesRegistro->valor = valorCompra;
        acoesRegistro->prox = l;
        RemoveDadoEspecificoVenda(qtdVenda, siglaCompra, valorVenda, listaVenda);
        RemoveDadoEspecifico(qtdCompra, siglaCompra, valorVenda, listaCompra);
        return acoesRegistro;
      }
      }
    }
  return NULL;
}

Registro* inserir_lista_registro(Registro* l, int qtd, float valor, int sigla){
	Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
  acoesRegistro->sigla = sigla;
	acoesRegistro->qtd = qtd;
  acoesRegistro->valor = valor;
	acoesRegistro->prox = l;
	return acoesRegistro;
  }

Venda* inserir_lista_venda(Venda* l, int qtd, float valor, int sigla){
	Venda* acoesVenda= (Venda*) malloc(sizeof(Venda));
  acoesVenda->sigla = sigla;
	acoesVenda->qtd = qtd;
  acoesVenda->valor = valor;
	acoesVenda->prox = l;
	return acoesVenda;
  }

Compra* inserir_lista_compra(Compra* l, int qtd, float valor, int sigla){
	Compra* acoesCompra= (Compra*) malloc(sizeof(Compra));
  acoesCompra->sigla = sigla;
	acoesCompra->qtd = qtd;
  acoesCompra->valor = valor;
	acoesCompra->prox = l;
	return acoesCompra;
}

void consultar_lista_compra(Compra* inicioCompra){
	Compra *referencia = inicioCompra;
  if (referencia == NULL){
   printf("\nNENHUMA OFERTA DE COMPRA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE COMPRA            \n"
         "=====================================\n");
	for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("PETR4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
}

void consultar_registro(Registro* inicioRegistro){
	Registro *referencia = inicioRegistro;
  if (referencia == NULL){
   printf("\nNENHUMA NEGOCIAÇÃO FOI REALIZADA ATÉ O MOMENTO!\n");
  }else{
    printf( "\nA útlima ação comprada foi:\n");
    if(referencia->sigla == 1){
		printf("PETR4 | %d unidades | Pelo valor de: R$%.2f\n", referencia->qtd, referencia->valor);
    }
    if(referencia->sigla == 2){
		printf("VALE5 | %d unidades | Pelo valor de: R$%.2f\n", referencia->qtd, referencia->valor);
    }
    if(referencia->sigla == 3){
		printf("ITSA4 | %d unidades | Pelo valor de: R$%.2f\n", referencia->qtd, referencia->valor);
    }
  }
}

void consultar_lista_venda(Venda* inicioVenda){
	Venda *referencia = inicioVenda;
  if (referencia == NULL){
   printf("\nNENHUMA OFERTA DE VENDA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE VENDA            \n"
         "=====================================\n");
	for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("PETR4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    } }
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    } }
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
}

void consultar_lista_individual(Compra* inicioCompra, int opAcao){
	Compra *referencia = inicioCompra;
  if (referencia == NULL){
   printf("\nNENHUMA OFERTA DE COMPRA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE COMPRA            \n"
         "=====================================\n");
  if(opAcao == 2){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("PETR4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}  }
  if(opAcao == 3){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 4){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
      }  }
    }
  }
}

void consultar_lista_venda_individual(Venda* inicioVenda, int opAcao){
	Venda *referencia = inicioVenda;
  if(referencia == NULL){
   printf("\nNENHUMA OFERTA DE VENDA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE VENDA            \n"
         "=====================================\n");
  if(opAcao == 2){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("PETR4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 3){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 4){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
      }  }
    }
  }
}

Venda* apagaVendas(Venda* listaVenda){
    Venda* p = listaVenda;
    while(p!=NULL){
        Venda* t = p->prox;
        free(p);
        p = t;
    } 
    return p;
}

Compra* apagaCompras(Compra* listaCompra){
    Compra* p = listaCompra;
    while(p!=NULL){
        Compra* t = p->prox;
        free(p);
        p = t;
    } 
    return p;
}

void apagarOfertas(){
  int resposta;
  int opAcao;
  do{
    printf( "\n=====================================\n"
            "||          MENU - APAGAR          ||\n"
            "=====================================\n"
            "[1] | Compra\n"
            "[2] | Venda\n"
            "[0] | Voltar \n-> " );
        scanf("%d", &resposta);
        getchar();
        switch(resposta){
          case 1:
            do{
            printf( "\n=====================================\n"
                    "||         APAGAR - COMPRA         ||\n"
                    "=====================================\n"
                    "[1] | TODAS\n"
                    "[2] | PETR4\n"
                    "[3] | VALE5\n"
                    "[4] | ITSA4\n"
                    "[0] | VOLTAR \n-> " );
                    scanf("%d", &opAcao);
                    getchar();
                    if(opAcao == 1){
                          printf("Todas ofertas de venda foram apagadas!\n");
                          apagaCompras(listaCompra);
                    }if(opAcao == 2){    
                          printf("Todas ofertas de PETR4 foram apagadas!\n");
                          RemoveDado(1,listaCompra);
                    }if(opAcao == 3){
                          printf("Todas ofertas de VALE5 foram apagadas!\n");
                          RemoveDado(2,listaCompra);
                    }if(opAcao == 4){
                          printf("Todas ofertas de ITSA4 foram apagadas!\n");
                          RemoveDado(3,listaCompra);
                      }
                    if(opAcao == 0){
                          break;}
          }while(opAcao != 0);
          break;
          case 2:
            do{
            printf( "\n=====================================\n"
                    "||          APAGAR - VENDA         ||\n"
                    "=====================================\n"
                    "[1] | TODAS\n"
                    "[2] | PETR4\n"
                    "[3] | VALE5\n"
                    "[4] | ITSA4\n"
                    "[0] | VOLTAR \n-> " );
                    scanf("%d", &opAcao);
                    getchar();
                    if(opAcao == 1){
                          printf("Todas ofertas de venda foram apagadas!\n");
                          apagaVendas(listaVenda);
                    }if(opAcao == 2){    
                          printf("Todas ofertas de PETR4 foram apagadas!\n");
                          RemoveDado(1,listaVenda);
                    }if(opAcao == 3){
                          printf("Todas ofertas de VALE5 foram apagadas!\n");
                          RemoveDado(2,listaVenda);
                    }if(opAcao == 4){
                          printf("Todas ofertas de ITSA4 foram apagadas!\n");
                          RemoveDado(3,listaVenda);
                      }
                    if(opAcao == 0){
                          break;}
              }while(opAcao < 1 || opAcao > 4);
          break;
          default:
          break;
          }
    }while (resposta != 0);
}

Compra *RemoveDado(int dado, Compra *ptr){
	Compra* busca;
	Compra* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == dado) {
			if (anterior != NULL){
				anterior->prox = busca -> prox;
			}else{
				ptr = busca-> prox;
			}
			free(busca);
		}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}

Compra *RemoveDadoEspecifico(int qtd, int sigla, float valor, Compra *ptr){
	Compra* busca;
	Compra* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == sigla) {
      if (busca->qtd == qtd){
        if (busca->valor == valor){
    			if (anterior != NULL){
    				anterior->prox = busca -> prox;
    			}else{
    				ptr = busca-> prox;
    			}
			free(busca);
		}}}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}

Venda *RemoveDadoEspecificoVenda(int qtd, int sigla, float valor, Venda *ptr){
	Venda* busca;
	Venda* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == sigla) {
      if (busca->qtd == qtd){
        if (busca->valor == valor){
    			if (anterior != NULL){
    				anterior->prox = busca -> prox;
    			}else{
    				ptr = busca-> prox;
    			}
			free(busca);
		}}}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}

Venda *RemoveDadoVenda(int dado, Venda *ptr){
	Venda* busca;
	Venda* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == dado) {
			if (anterior != NULL){
				anterior->prox = busca -> prox;
			}else{
				ptr = busca-> prox;
			}
			free(busca);
		}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\
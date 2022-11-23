#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "portuc.h"

funcao estrutura Aluno{
	estrutura Aluno *anterior;
	caractere nome[20], curso[50];
	inteiro ra;
}t_aluno;

vazio inserir(vazio);
vazio consultar(vazio);
vazio alterar(vazio);
vazio deletar(vazio);

t_aluno *p = NULO;
t_aluno *anterior = NULO;

inteiro principal(){
	por(;;){
		sistema("cls");
		inteiro op;
		imprimir("Menu principal\n\n");
		imprimir("1 - Inserir\n");
		imprimir("2 - Consultar\n");
		imprimir("3 - Alterar\n");
		imprimir("4 - Deletar\n");
		imprimir("5 - Sair\n");
		imprimir("\nOpcao> ");
		leia("%i", &op);
	
		trocar(op){
			caso 1:
				inserir();
				parar;
			caso 2:
				consultar();
				parar;
			caso 3:
				alterar();
				parar;
			caso 4:
				deletar();
				parar;
			caso 5:
				sistema("cls");
				imprimir("Fim do programa\n\n");
				retorno 0;
			padrao:
				sistema("cls");
				imprimir("ERRO: OPCAO INVALIDA\n\n");
				sistema("pause");
				sistema("cls");
				
		}
	}
}


vazio inserir(vazio){
	sistema("cls");
	p = (t_aluno *) malloc(sizeof(t_aluno));
	
	imprimir("Digite seu RA: ");
	leia("%d", &p->ra);
	imprimir("Digite seu nome: ");
	fflush(stdin);
	gets(p->nome);
	imprimir("Digite seu curso: ");
	fflush(stdin);
	gets(p->curso);
	
	p->anterior = anterior;
	anterior = p;
	
	imprimir("\n\n\nAluno cadastrado com sucesso\n");
	sistema("pause");
	sistema("cls");
	retorno;
}

vazio consultar(vazio){
	sistema("cls");
	inteiro n = 0;
	imprimir("digite o RA buscado ou 0 para listar todos: ");
	leia("%i",&n);
	
		enquanto(p->anterior!=NULO){
			se(n==0){
				faz{
					imprimir(" RA: %i\n Nome: %s\n Curso:%s\n",p->ra,p->nome,p->curso);		
					se (p->anterior==NULO){		
					parar;
					}
				p = p->anterior;
				}enquanto(1);
			sistema("pause");
			retorno;
			}
			se(p->ra == n){
				imprimir(" RA: %i\n Nome: %s\n Curso:%s\n",p->ra,p->nome,p->curso);
				sistema("pause");
				retorno;
			}
		
		p = p->anterior;
	}
	
	imprimir("\n\n\nERRO 404: RA nao existe no sistema\n");
	leia("pause");
	retorno;
	
}

vazio alterar(vazio){
	sistema("cls");
	inteiro n = 0, o =0;
	imprimir("Digite o RA que deseja alterar: ");
	leia("%i", &n);
	enquanto(p->anterior!=NULO){
		
		se(p->ra == n){
			imprimir("Digite 1 para alterar o nome ou 2 para alter o curso :");
			leia("%i",&o);
			se(o==1){
			imprimir("\n\nDigite um novo nome:");
			fflush(stdin);
			gets(p->nome);
			sistema("pause");
			retorno;
			}
			se(o==2){
			imprimir("\n\nDigite um novo curso:");
			fflush(stdin);
			gets(p->curso);
			sistema("pause");
			retorno;
			}
		}
		
		p = p->anterior;
	}
	
	imprimir("\n\n\nERRO 404: RA nao existe no sistema\n");
	sistema("pause");
	retorno;
	
}

vazio deletar(vazio){
	sistema("cls");
	inteiro n = 0;
	imprimir("Digite o RA que deseja deletar: ");
	leia("%i", &n);
	
	enquanto(p->anterior!=NULO){
		se(p->ra == n){
			free(p);
			imprimir("\n\n\nAluno deletado com sucesso\n");
			sistema("pause");
			retorno;
		}
		
		p = p->anterior;
	}
	
	imprimir("\n\n\nERRO 404: RA nao existe no sistema\n");
	sistema("pause");
	retorno;
}
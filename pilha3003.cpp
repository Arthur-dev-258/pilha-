#include<iostream>
#include<conio.h>
#define TAM 5
using namespace std;

void empilha(int p[], int &t, int v);
int desempilha(int p[], int &t, int &v);
void mostraTopo(int p[], int &t);
void situacaoPilha(int p[], int &t);

int main()
{
	int op, val, topo=-1, pilha[TAM], resp;
	
	do
	{
		system("cls");
		system("color f0");
		cout<<"\nPILHA(LIFO- Last In - First Out) \n\n";
		cout<<"\n1- Inserir um valor na pilha";
		cout<<"\n2- Remover um valor da pilha";
		cout<<"\n3- Mostrar o elemento do topo da pilha";
		cout<<"\n4- Mostrar situacao da pilha";
		cout<<"\n5- Mostrar maior elemento da Pilha";
		cout<<"\n6- Mostrar elementos pares da Pilha"; 
		cout<<"\n7- Mostrar elementos impares da Pilha"; 
		cout<<"\n8- Sai";
		cout<<"\nOpcao: ";
		cin>>op;
		system("cls");

		switch(op)
		{
			case 1: 
				cout<<"Digite o valor a ser empilhado: "; 
				cin>>val;
	            empilha(pilha, topo, val);
	            break;

			case 2: 
				resp=desempilha(pilha, topo, val);
	            if(resp==0){ 
					cout<<"\nATENCAO. Pilha Vazia\n";
				}
	            else{       
					cout<<"\nValor removido: "<<val;
				} 
	            break;

			case 3: 
				mostraTopo(pilha, topo);
	            break;

			case 4: 
				situacaoPilha(pilha, topo);
	            break;

			case 5: {
				int maior;
				if(topo == -1){
					cout<<"\nATENCAO. Pilha Vazia\n";
				}else{
					maior = pilha[0];
					for(int i = 1; i <= topo; i++){
						if(pilha[i] > maior){
							maior = pilha[i];
						}
					}
					cout<<"\nMaior elemento: "<<maior;
				}
				break;
			}

			case 6: {
				if(topo == -1){
					cout<<"\nATENCAO. Pilha Vazia\n";
				}else{
					bool encontrou = false;
					cout<<"\nElementos pares: ";
					for(int i = 0; i <= topo; i++){
						if(pilha[i] % 2 == 0){
							cout<<pilha[i]<<" ";
							encontrou = true;
						}
					}
					if(!encontrou){
						cout<<"Nenhum elemento par encontrado";
					}
				}
				break;
			}

			case 7: {
				if(topo == -1){
					cout<<"\nATENCAO. Pilha Vazia\n";
				}else{
					bool encontrou = false;
					cout<<"\nElementos impares: ";
					for(int i = 0; i <= topo; i++){
						if(pilha[i] % 2 != 0){
							cout<<pilha[i]<<" ";
							encontrou = true;
						}
					}
					if(!encontrou){
						cout<<"Nenhum elemento impar encontrado";
					}
				}
				break;
			}

			case 8: 
				cout<<"\nSaindo do programa\n";	
	  		    break;	

			default: 
				cout<<"\nOPCAO INVALIDA\n";	              
		}

		cout<<"\n\n";
		system("pause");

	}while(op != 8);
}

/* insere*/
void empilha(int p[], int &t, int v)
{
	if(t == TAM-1)
		cout<<"\nATENCAO. Pilha Cheia\n";
	else
	{
	 	t++; 
	 	p[t]=v; 
	 }
}

/* Remove */
int desempilha(int p[], int &t, int &v)
{
	if(t == -1)
		return 0;
	else
	{
		v=p[t];
		t--; 
		return 1;
	}
}

/* Mostra o topo */
void mostraTopo(int p[], int &t)
{
	if(t == -1)
		cout<<"\nATENCAO. Pilha Vazia\n";
	else
		cout<<"\nElemento do Topo da PILHA: "<<p[t];
}

/* Mostrar situacao da Pilha*/
void situacaoPilha(int p[], int &t)
{
	int i;

	if(t == -1){
		cout<<"\nATENCAO. Pilha Vazia\n";
	}
	else{
		cout<<"\nTotal de elementos na pilha: "<<t+1<<"\n";
		cout<<"\nEspaco disponivel na pilha: "<<TAM-(t+1)<<"\n";
		cout<<"\n\nElementos na pilha: ";

		for(i=0; i<=t; i++){
			cout<<p[i]<<" ";
		}
	}
}

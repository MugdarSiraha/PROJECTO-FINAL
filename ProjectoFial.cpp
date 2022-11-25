#include <stdlib.h>//� um arquivo cabe�alho da biblioteca de prop�sito geral padr�o da linguagem de programa��o C e compativel em C++
#include <stdio.h> //Diz ao compilador que ele deve incluir o arquivo-cabe�alho
#include <string.h> //Realiza a concatena��o do conte�do de uma vari�vel a outra, por�m, deve ser especificado o tamanho a ser concatenado. Ambas devem ser strings.
#include <stdbool.h> //� um arquivo cabe�alho da biblioteca padr�o da linguagem de programa��o C que foi introduzido a partir de 1999, com C99. � usada para manipular vari�veis l�gicas, como verdadeiro e falso. Pode ser substitu�da pela utiliza��o de valores inteiro, sua fun��o � simplesmente facilitar a compreens�o do c�digo.
#include <windows.h> //cont�m declara��es para todas as fun��es da API do Windows, todos os macros comuns utilizados pelos programadores do Windows, e todos os tipos de dados utilizados pelas v�rias fun��es e subsistemas, Possibilita voc� a fazer coisas como: Criar janelas e bot�es; Enumerar arquivos de um diret�rio; Consultar informa��es sobre o sistema(eg processos, servi�os, janelas); Coisas do g�nero.
#define STRTAM 110 //Define a coluna da Borda(str)
#define limit 20 //Define o Limite da minha FiLa
void criarMenuLinhaSuperior(){//Funcao para criar borda superior
    int i;
    printf("%c", 201);
    for(i=0;i<STRTAM;i++)
        printf("%c",205);
    printf("%c\n", 187);
}

void criarMenuLinhaRodape(int tamX){//Funcao para criar a borda do rodape/borda inferior
    int i;
    printf("%c", 200);
    for(i=0;i<STRTAM;i++)
    printf("%c",205);
    printf("%c\n", 188);
}

void criarMenuItem(int tamX, char str[]){//Funcao para posessionar  o menu
    int contaletras=0;
    int i;

    for(i=0;i<tamX;i++){
        if(str[i]=='\0')
            break;
        else
            contaletras++;
    }
    printf("%c", 186);
    //for(i=0;i<STRTAM;i++)
    printf("%s",str);
    while(contaletras<tamX){
        printf("%c",32);
        contaletras++;
    }
    printf("%c\n", 186);
}

void montaMenu(){//Menu do meu programa criada numa funcao montamenu que ira colocar o menu dentro das bordas acima criadas.
    criarMenuLinhaSuperior();
    criarMenuItem(STRTAM,"     MUGDAR RESORT");
    criarMenuItem(STRTAM,"   MENU:");
    criarMenuItem(STRTAM,"   1 - PROXIMO CLIENTE");
    criarMenuItem(STRTAM,"   2 - RETIRAR SENHA");
    criarMenuItem(STRTAM,"   3 - ILUSTRAR FILA");
    criarMenuItem(STRTAM,"   4 - SAIR");
    criarMenuLinhaRodape(STRTAM);
}

void eixo_x_y(int x, int y);//Funcao que serve para Encaixar qualquer tipo de dado em um angulo na tela.

struct fila_struct {
	int position[limit];
	int initial_position;
	int end_position;
};
//DECLARACAO DE VARIAVEIS DE ENCREMENTO, DECREMENTO, VALIDACAO, VER FILA, LIMPAR FILA, SEPARADOR(TRACOS)
struct fila_struct fila;
int num_atendimento = 0;
int num = 0;

int senha = 0;
bool sair = true;

int exit_program();
int validar();
void ver_fila();
void limpar_msg(int num);
void fila_increment(int senha);
void fila_decrement();
void exit();
void retirar_senha();
void painel();
void grid();


int main(){//FUNCAO MAIN(A PRINCIPAL FUNCAO PARA O FUNCIONAMENTO DO PROGRAMA).
	fila.initial_position = 0;
	fila.end_position = 0;
	int opcao = 1, x = 4;

    system("cls");
    system("color 0F");
    printf("\n");
    montaMenu();
        eixo_x_y(0,2);
    eixo_x_y(0,3);
        eixo_x_y(0,4); printf("->");
	grid();
    while(sair){
        eixo_x_y(2,4);
        eixo_x_y(2,5);
        eixo_x_y(2,6);
        eixo_x_y(2,7);

        eixo_x_y(32,14); printf("\n\nESCOLHA A OPCAO QUE DESEJA: %d", num_atendimento);


        system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && x != 7) {
            eixo_x_y(0,x); printf("  ");
            x++;
            eixo_x_y(0,x); printf("->");
            opcao++;
            continue;
        }

		if(GetAsyncKeyState(VK_UP) && x != 4){
            eixo_x_y(0,x); printf("  ");
            x--;
            eixo_x_y(0,x); printf("->");
            opcao--;
            continue;
        }

		if(GetAsyncKeyState(VK_RETURN)){
            switch (opcao) {
            case 1:
                retirar_senha();
                break;
            case 2:
                fila_decrement();
                break;
            case 3:
                ver_fila();
                break;
            case 4:
                exit_program();
            }
        }
    }
    eixo_x_y(20,21);


	exit();
	return 0;
}

void eixo_x_y(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void grid(){//FILEIRAS, COLUNAS, SEPARADORES ETC...

	int pos = 0;
	int y = 10;
	for(int i = 0; pos <= 5; i++){
		eixo_x_y(30, y);
		printf("|");

		eixo_x_y(60, y);
		printf("|");

		pos++;
		y++;
	}

}

void fila_increment(int senha){//ENCREMENTO DA FILA/INSERCAO
	if (fila.end_position == limit) {
		printf("Fila cheia.");
	}
	else {
		fila.position[fila.end_position] = senha;
		fila.end_position++;
	}
}

void fila_decrement(){//DECREMENTO DA FILA/ RETIRAR SENHA

	if (fila.initial_position == fila.end_position) {
		eixo_x_y(35,14);
		printf("Fila vazia");
	}
	else {
		eixo_x_y(35,14);
		printf("               ");
		for (int i=0; i<limit; i++) {
			fila.position[i] = fila.position[i+1];
		}
		fila.position[fila.end_position] = 0;
		fila.end_position--;
		num_atendimento++;
		painel();
	}
	ver_fila();
	limpar_msg(0);
	limpar_msg(1);
}

void ver_fila() {

	painel();
	eixo_x_y(65,10);
	printf("Fila: ");
	eixo_x_y(65,11);
	for (int i=0; i<limit; i++){

		printf("%d, ", fila.position[i]);
	}
	eixo_x_y(65,11);
	printf("Atendimento: %d", num_atendimento);
	limpar_msg(0);
}


void exit(){//FUNCAO PARA SAIR/ EM OUTRAS PALAVRAS TERMINAR PROGRAMA
	printf("EXIT");
}

void retirar_senha(){

	int sua_senha;
	if (validar() == 1) {
		sua_senha = senha + 1;

		eixo_x_y(1,12);
		printf("Sua senha: %d", sua_senha);
		senha++;
		fila_increment(sua_senha);
	} else if(senha == 10) {
		eixo_x_y(30,17);
 		printf("A fila ja esta completa, tente novamente mais tarde.");
	}

	ver_fila();
	limpar_msg(0);

}

int validar(){
	if (senha == limit) {
		return -1;
	}
	else if(senha <= limit) {
		return 1;
	}

}


void painel(){//FUNCAO DO PAINEL DE INFORMACOES RECOLHIDAS DURANTE A EXECUCAO DO PROGRAMA

	if (num_atendimento - 1 < 0){
		eixo_x_y(35,11);
		printf("SENHA ANTERIOR: 0\n");
	}
	else {
		eixo_x_y(35,11);
		printf("SENHA ANTERIOR: %d\n", num_atendimento -1);
	}

	eixo_x_y(35,12);
	printf("SENHA CHAMADA: %d \n", num_atendimento);

	eixo_x_y(35,13);
	printf("PROXIMO CLIENTE: %d\n",  num_atendimento + 1);

}

void limpar_msg(int num){

	if(num == 1){
		eixo_x_y(30,17);
 		printf("                                                               ");
	} else {
		eixo_x_y(30,16);
		printf("                                                              ");
	}


}

int exit_program(){//FUNCAO DE TERMINAR O PROGRAMA COM UMA CONDICAO, O PROGRAMA NAO IRA FECHAR ATE TODAS AS PESSOAS SEREM ATENDIDAS
	if (fila.position[fila.initial_position] != 0){
		eixo_x_y(30,16);
		printf("Ainda ha pessoas para serem atendidas.");
		return 1;
	}
	else{
		sair = false;
		return sair;
	}

}

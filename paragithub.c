//bibliotecas para usar as funcoes vitais
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //a biblioteca serve para utilizar o getchar()
#include <windows.h> //foi usada para usar o gotoxy
#include <locale.h>

//////////////////////////////////////////

//Variaveis globais e estaticas
#define C_MINIMA 5 //foi usado para usar a caixinha da interface
#define C_MAXIMA 74 //a mesma coisa de cima
#define L_MINIMA 2 //a mesma coisa de cima
#define L_MAXIMA 36 //mesma coisa de cima


//////////////////////////////////

//DEFINES PARA USAR NA FUNÇÃO TEXTCOLOR
#define BLACK 0
#define BLUE 1
#define GRREN 2
#define GREENBLUE 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define GREENWATER 11
#define LIGHTRED 12
#define LILAC 13
#define LIGHTYELLOW 14
#define BRIGHTWHITE 15

///////////////////////////////

//CÓDIGOD DAS TECLAS (SETA)
#define ENTER 13
#define CIMA 72
#define ESQUERDA 75
#define DIREITA 77
#define BAIXO 80
#define ESC 27

////////////////////////////////////

void cadastrar();//cadastro de funcionarios
void consultaC();//consulta funcionarios
void alterar();//altera o cadastro do funcionario
void exclusao();//exclui o cadastro do funcionario
void moldurinhaMenu(int x, int y, int tamanho, char *texto);//faz a caixa para interface
void cadastroFun();//menu principal
void menuPrincipal();
void registro();
void gotoxy(int x, int y);//cursor
void textcolor(int x);//cores para a interface

//////////////////////////////////

int centraliza(int);
void caixa_menu( int cMinima, int cMaxima, int lMinima,int lMaxima);
void desenho();

////////////////////////////////////
//struct principal
typedef struct func{

	char nome[100];
	int matricula;
	char entrada[6];
	char saida[6];
	char entrada2[6];
	char saida2[6];
	
}func;

//variavel global 

struct func cadf;


//FUNÇÃO TEXTCOLOR
void textcolor(int i){ 

	 HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
	 CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	 BOOL b = GetConsoleScreenBufferInfo(h1, &bufferInfo);
	 bufferInfo.wAttributes &= 0x00F0;
	 SetConsoleTextAttribute (h1, bufferInfo.wAttributes |= i);
}


//FUNÇÃO GOTOXY (CURSOR/INTERFACE)
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

//menu principal
void menuPrincipal(){
	
	int x = 20, y = 12;
    char tecla;
    int op = 0;
	
	//EXIBE AS OPÇÕES DISPONIVEIS
	
	moldurinhaMenu(22,11,90," ");
	gotoxy(23,12);
	textcolor(GREENWATER);
	printf("                            MENU PRINCIPAL \n\n");
	moldurinhaMenu(22,15,90," ");
	gotoxy(23,16);
	textcolor(GREENWATER);
	printf("                            CADASTRO DE FUNCION%cRIO \n\n",181);
	moldurinhaMenu(22,19,90," ");
	gotoxy(23,20);
	textcolor(GREENWATER);+3,
	printf("                            REGISTRO DE PONTO  \n\n");
	moldurinhaMenu(22,23,90," ");
	gotoxy(23,24);
	textcolor(GREENWATER);
	printf("                             RELAT%cRIOS    \n\n",224);
	moldurinhaMenu(22,27,90," ");
	gotoxy(23,28);
	textcolor(GREENWATER);
	printf("                             FINALIZAR \n\n");
	
	gotoxy(x,y);
    printf("%c", 175);
	
	do {
        tecla = getch(); //tecla recebe o getchar, que e a tecla enter

        switch (tecla) {
        case CIMA:
            if (y >= 16) { // Verifica pra não passar da tela.
                gotoxy(x, y);
                printf(" ");
                gotoxy(x, y-=4);
                printf("%c", 175);
            }

            break;
        case BAIXO:
        	if(y<=24){
	           	gotoxy(x,y);
	           	printf(" ");
	           	gotoxy(x,y+=4);
	            printf("%c ", 175);
        	}
            break;
        }

        }while (tecla != ENTER);
    
    system("cls");
    
    if(y == 16)	//se a opcao for igual a 16, ele vai para cadastro
    	cadastroFun();
    
    if(y == 20) //se a opcao for igual a 16, ele vai para o relario
		registro();
	
	if(y == 24) //se a opcao for igual a 16, ele vai para o relatorio
		printf("Relatorio ainda nao fiz");
		
	if(y == 28)
		exit(1);
    
        
	getchar();
	
}

//cadastro de funcionario
void cadastroFun(){
	
	
	moldurinhaMenu(22,11,90," ");
	gotoxy(23,12);
	textcolor(GREENWATER);
	//EXIBE AS OPÇÕES DISPONIVEIS
	printf("                            CADASTRO DE FUNCION%cRIO \n\n",181);
	moldurinhaMenu(22,15,90," ");
	gotoxy(23,16);
	textcolor(GREENWATER);
	printf("                            CADASTRAR \n\n");
	moldurinhaMenu(22,19,90," ");
	gotoxy(23,20);
	textcolor(GREENWATER);+3,
	printf("                            CONSULTAR  \n\n");
	moldurinhaMenu(22,23,90," ");
	gotoxy(23,24);
	textcolor(GREENWATER);
	printf("                             ALTERAR    \n\n");
	moldurinhaMenu(22,27,90," ");
	gotoxy(23,28);
	textcolor(GREENWATER);
	printf("                             EXCLUIR \n\n");
	

	//Variaveis da seta
	int x = 20, y = 12;
    char tecla;

    // Printa a seta pela primeira vez.
    gotoxy(x,y);
    printf("%c", 175);


	//LAÇO PARA UTILIZAR O CURSOR (INTERFACE)
    do {
        tecla = getch(); //tecla recebe o getchar, que e a tecla enter

        switch (tecla) {
        case CIMA:
            if (y >= 14) { // Verifica pra não passar da tela.
                gotoxy(x, y);
                printf(" ");
                gotoxy(x, y-=4);
                printf("%c", 175);
            }

            break;
        case BAIXO:
        	if(y<=24){
	           	gotoxy(x,y);
	           	printf(" ");
	           	gotoxy(x,y+=4);
	            printf("%c ", 175);
        	}
            break;
        case ESC:
        	system("cls");
        	menuPrincipal();
        	break;
        }

        }while (tecla != ENTER);

		
		//CONDIÇÕES PARA A OPÇÃO DESEJADA SER SELECIONADA COM ENTER
         if(x== 20 && y==16){
         	getchar();
         	system("cls");
			cadastrar();
			system("cls");
			getchar();
			cadastroFun();
			}

			if(x== 20 && y==20){
			getchar();
			system("cls");
			consultaC();
			getchar();
			system("cls");
			cadastroFun();
			}
		    if(x== 20 && y==24){
		    getchar();
			system("cls");
			alterar();
			getchar();
			system("cls");
			cadastroFun();
			}
			if(x==20 && y==28){
			getchar();
			system("cls");
			exclusao();
			getchar();
			system("cls");
			cadastroFun();
			}
			
			if(x==20 && y==32){
			getchar();
			system("cls");
			exit(1);
			
		}
	}

//registro de funcionario
void registro(){
	
	FILE *arq;
	arq=fopen("./arq.cadastroF", "rb");
	
	int encontrou = FALSE;
	int matricula_ler;
	char nome[100];
	char entrada_funcionario[6];
	char saida_funcionario[6];
	char entrada2_funcionario[6];
	char saida2_funcionario[6];
	
	if(arq==NULL){
		printf("Problemas na criacao do arquivo");
		exit(1);
		
	}
	
	gotoxy(45, 5);
	printf("REGISTRO DE FUNCION%cRIO",181);
	
	fflush(stdin);
	gotoxy(25, 7);
	printf("Matricula:");
	scanf("%d",&matricula_ler);
	gotoxy(25,8);
	printf("Nome:");
	fflush(stdin);
	gets(nome);
	
    while(fread(&cadf, sizeof(func), 1, arq)){
    	if(cadf.matricula == matricula_ler) {
            encontrou = TRUE;
            break;
        }
    }
    
    fclose(arq);
    	
	if(!encontrou){
		gotoxy(45,9);
		puts("Matricula nao encontrada");
        getchar();
        return; // Retorna à função principal.
	}
	
	gotoxy(43, 10);
    printf("HOR%cRIO DE TRABALHO",181);
	fflush(stdin);
	gotoxy(25, 12);
	printf("Entrada formato(hh:mm): ");
	fgets(entrada_funcionario, 6, stdin);
	
	fflush(stdin);
	gotoxy(25, 13);
	printf("Sa%cda formato(hh:mm): ",214);
	fgets(saida_funcionario, 6, stdin);	

	fflush(stdin);
	gotoxy(25, 14);
	printf("Entrada formato(hh:mm): ");
	fgets(entrada2_funcionario, 6, stdin);
	
	fflush(stdin);
	gotoxy(25, 15);
	printf("Sa%cda formato(hh:mm): ",214);
	fgets(saida2_funcionario, 6, stdin);
	
	gotoxy(40,17);
	printf("Registro Salvo");
	getchar();
	getchar();
	system("cls");
	menuPrincipal();
	
}


//faz a caixa da interface
void moldurinhaMenu(int x, int y, int tamanho, char *texto){
	
        //canto superior esquerda
		textcolor(GREENWATER);
		gotoxy(x,y);
        printf("%c",205);
        //barra superior
        int i = x + 1;
        for(; i < tamanho; i++){
        gotoxy(i,y);
        printf("%c", 205);
        }
        //canto superior direito
        gotoxy(tamanho,y++);
        printf("%c", 205);
        //esquerda
        gotoxy(x,y);
        printf("%c", 205);
        //texto
        gotoxy(x+1, y);
        printf("%s", texto);
        //direita
        gotoxy(tamanho,y++);
        printf("%c",205);
        //canto inferior  esquerdo
        gotoxy(x,y);
        printf("%c",205);
        //barra inferior
        i = x + 1;
        for(; i < tamanho; i++){
        gotoxy(i,y);
        printf("%c", 205);
        }
        //canto inferior direito
        gotoxy(tamanho,y);
        printf("%c", 205);


}


//cadastra funcionarios
void cadastrar(){
	
	
	FILE *arq;
	//abertura do arquivo 
	arq=fopen("./arq.cadastroF", "ab");
	
	if(arq==NULL){
		printf("Erro na abertura do arquivo.");
		exit(1);
		
	}
	
	gotoxy(45, 5);
	printf("INCLUS%cO DE FUNCION%cRIO",199,181);
	fflush(stdin);
	gotoxy(25, 7);
	printf("Nome:");
	fgets(cadf.nome, 100, stdin);

    gotoxy(25, 8);
	printf("Matr%ccula: ",214);
	scanf("%d", &cadf.matricula);

    gotoxy(43, 10);
    printf("HOR%cRIO DE TRABALHO(MATUTINO)",181);
	fflush(stdin);
	gotoxy(25, 12);
	printf("Entrada formato(00:00): ");
	fgets(cadf.entrada, 6, stdin);
	
	fflush(stdin);
	gotoxy(25, 13);
	printf("Sa%cda formato(00:00): ",214);
	fgets(cadf.saida, 6, stdin);	

    gotoxy(43, 15);
    printf("HOR%cRIO DE TRABALHO(VESPERTINO)",181);
	fflush(stdin);
	gotoxy(25, 17);
	printf("Entrada formato(00:00): ");
	fgets(cadf.entrada2, 6, stdin);
	
	fflush(stdin);
	gotoxy(25, 18);
	printf("Sa%cda formato(00:00): ",214);
	fgets(cadf.saida2, 6, stdin);
	
	//ler para ir para o arquivo
	fwrite(&cadf, sizeof(func), 1, arq); //ela joga os dados para a variavel
	
	fclose(arq);

}

//consulta 
void consultaC(){

	FILE *arq;
	
	arq=fopen("./arq.cadastroF", "rb");
	
	if(arq==NULL){
		printf("Problemas na criacao do arquivo");
		exit(1);
		
	}else{

			//imprime dados do arquivo
			while(fread(&cadf, sizeof(func), 1, arq)){
				gotoxy(45, 5);
				printf("CONSULTA FUNCION%cRIO",181);
				gotoxy(25, 7);
				printf("Nome: %s\n", cadf.nome);
				fflush(stdin);
				gotoxy(25, 8);
				printf("Matricula: %d\n", cadf.matricula);
				fflush(stdin);
				gotoxy(25, 9);
				printf("Entrada: %s\n", cadf.entrada);
				fflush(stdin);
				gotoxy(25, 10);
				printf("Saida: %s\n", cadf.saida);
				fflush(stdin);
				gotoxy(25, 11);
				printf("Entrada adc: %s\n", cadf.entrada2);
				fflush(stdin);
				gotoxy(25, 12);
				printf("Saida adc: %s\n", cadf.saida2);
				fflush(stdin);
				
				puts(" ");
		}

			fclose(arq);		
		getchar();
		setbuf(stdin, NULL);
	}
	
}

//altera dados
void alterar(){
	
	FILE *arq;
	FILE *arqaux;
	int matricula_verifica;
	int encontrou=FALSE;
	
	arq=fopen("./arq.cadastroF", "rb");
	
	if(arq==NULL){
		
		printf("Problemas na abertura do arquivo: ");
		exit(1);
	}
	
	fflush(stdin);
	printf("Entre com o numero da sua matricula: ");
	scanf("%d", &matricula_verifica);
	fflush(stdin);
	
	//Laço para pesquisar 
	while(fread(&cadf, sizeof(func), 1, arq)){
		if(matricula_verifica==cadf.matricula){
			encontrou=TRUE;
			break;
		}
		
	}
	
	system("cls");
	setbuf(stdin, NULL);
	
	//if se a matricula nao for encontrada 
	if(!encontrou){
		
		printf("Matricula nao encontrada.");
		getchar();
		return;
	}
	
	system("cls");
	
	//Imprime dados do usuario
		printf("Nome: %s\n", cadf.nome);
		printf("Matricula: %d\n", cadf.matricula);
		printf("Entrada: %s\n", cadf.entrada);
		printf("Saida: %s\n", cadf.saida);
		printf("Entrada adc: %s\n", cadf.entrada2);
		printf("Saida adc: %s\n", cadf.saida2);
	
		setbuf(stdin, NULL);
		
	//Dados que seram alterados
	fflush(stdin);
	
	printf("Nome:");
	fgets(cadf.nome, 100, stdin);

	fflush(stdin);
	printf("Entrada formato(00:00): ");
	fgets(cadf.entrada, 6, stdin);
	
	fflush(stdin);
	printf("Sa%cda formato(00:00): ",214);
	fgets(cadf.saida, 6, stdin);	

	fflush(stdin);
	printf("Entrada formato(00:00): ");
	fgets(cadf.entrada2, 6, stdin);
	
	fflush(stdin);
	printf("Sa%cda formato(00:00): ",214);
	fgets(cadf.saida2, 6, stdin);
		
	
	rewind(arq);
		
	if(arq==NULL){
		printf("Problema na criacao do arquivo.");
		exit(1);
		
	}else{
		
		struct func FUNC;
		
		//pesquisa se existe uma pessoa igual	
		while(fread(&FUNC, sizeof(func), 1, arq)){
			if (cadf.matricula == FUNC.matricula && cadf.matricula != matricula_verifica){
				
				printf("Usuario existente");
				fclose(arq);
				getchar();
				
				return;
			}
		}
	}
	
	fclose(arq);
	
	arqaux=fopen("./arq.cadastroAUX", "ab");	
	arq=fopen("./arq.cadastroF", "rb");
	
	if (arq == NULL && arqaux == NULL) { // Finaliza o programa se não conseguir criar o arquivo.
        printf("Problemas na criacao do arquivo. ");
        exit(1);
        
    }else{
    	
    	//faz alteração 
    	fwrite(&cadf, sizeof(func), 1, arqaux);
    	
    		while(fread(&cadf, sizeof(func), 1, arq)){
    			if(cadf.matricula != matricula_verifica) {
                  fwrite(&cadf, sizeof(func), 1, arqaux);
            }
    	}
	}
    	
    //fecha 
	fclose(arq);
   	fclose(arqaux);
   	
   	//renomeia 
   	remove("./arq.cadastroF");
   	rename("./arq.cadastroAUX", "./arq.cadastroF");    	
    	    
}

//exclui cadastro
void exclusao(){
	
	FILE *arq;
	FILE *arqAUX;
	char resp;
	int encontrou=FALSE;
	int matricula;
	
	arq=fopen("./arq.cadastroF", "rb");
	
	if(arq==NULL){
		printf("Problemas na criacao do arquivo");
		exit(1);
	}
	
	fflush(stdin);
	printf("Entre com o numero da sua matr%ccula: ",214);
	scanf("%d", &matricula);
	fflush(stdin);
	
	
	while (fread(&cadf, sizeof(func), 1, arq)) { // Lê todo o arquivo.
        if (cadf.matricula==matricula) { // Verifica se o código informado foi encontrado.
            encontrou = TRUE;
            break; // Sai do laço.
        }
    }
    
    
    system("cls");
    setbuf(stdin, NULL);
    fclose(arq);

    // Caso não tenha encontrado.
    if (!encontrou) {
        puts("Matricula nao encontrada");
        getchar();
        return; // Retorna à função principal.
        
    }

    system("cls");
    setbuf(stdin, NULL);
	
	printf("Nome: %s\n", cadf.nome);
	fflush(stdin);
	printf("Matricula: %d\n", cadf.matricula);
	printf("Entrada: %s\n", cadf.entrada);
	printf("Saida: %s\n", cadf.saida);
	printf("Entrada adc: %s\n", cadf.entrada2);
	printf("Saida adc: %s\n", cadf.saida2);
	
	printf("\n");
	
	fflush(stdin);
	printf("Tem certeza que deseja excluir este cadastro? (S/N)");
	scanf("%c", &resp);
	fflush(stdin);
	
	if(resp=='N'  || resp=='n'){
		
		printf("voltando para o menu principal...");
		fclose(arq);
		Sleep(300);
		return;
		
	}
	
	arqAUX= fopen("./arq.cadastroAUX", "ab"); // Cria um novo arquivo em modo de adição binária.
    arq = fopen("./arq.cadastroF", "rb"); // Reabre o arquivo principal em modo de leitura binária.

    if (arq == NULL && arqAUX == NULL) {
        printf("Problemas na abertura do arquivo: ");
        exit(1);
        
    } else {
        while (fread(&cadf, sizeof(func), 1, arq)) {
            if (cadf.matricula != matricula) { // Adiciona todos os registros no novo arquivo, exeto o que não será mais utilizado.
                fwrite(&cadf, sizeof(func), 1, arqAUX);
            }
        }
    }

    // Fecha os arquivos.
    fclose(arq);
    fclose(arqAUX);

    remove("./arq.cadastroF"); // Remove o arquivo principal.
    rename("./arq.cadastroAUX", "./arq.cadastroF"); // Renomeia o novo arquivo para o nome do arquivo principal.
	
	
	
}

void caixa_menu( int cMinima, int cMaxima, int lMinima,int lMaxima){
	int i;
	//Linhas
	for(i = cMinima+1;i < cMaxima;i++){
		gotoxy(i,lMinima);
		printf("\xCD");
		gotoxy(i,lMaxima);
		printf("\xCD");
	}

	//Desenho das Colunas
	for(i = lMinima + 1;i <lMaxima;i++){
		gotoxy(cMinima,i);
		printf("\xBA");
		gotoxy(cMaxima,i);
		printf("\xBA");
	}

	//Desenhos dos cantos
	gotoxy (cMinima,lMinima);
	printf ("\xC9");
	gotoxy (cMinima,lMaxima);
	printf ("\xC8");
	gotoxy (cMaxima,lMinima);
	printf ("\xBB");
	gotoxy (cMaxima,lMaxima);
	printf ("\xbc");

}

void desenho(){
	//Variaveis de localização
	int x,y =6;
	x = centraliza(25);
	char tecla;

	gotoxy(x, y);
	textcolor(GREENWATER);
	printf("  _____  _            _ _      ");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |  __ \\(_)          (_) |\n");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | |__) |___   ____ _ _| |  \n");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |  _  /| \\ \\ / / _` | | |   \n");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | | \\ \\| |\\ V / (_| | | |     \n");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |_|  \\_\\_| \\_/ \\__,_|_|_|");
	y++;

	//Proxima Palavra
	x = centraliza(37);
	gotoxy(22,y);
	textcolor(GREENWATER);
	printf("____");
	gotoxy(34,y);
	textcolor(GREENWATER);
	printf("_");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |  _ \\      | |");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | |_) | __ _| | __ _ _ __   ___ ___");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |  _ < / _` | |/ _` | '_ \\ / __/ _ \\");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | |_) | (_| | | (_| | | | | (_| (_) |");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |____/ \\__,_|_|\\__,_|_| |_|\\___\\___/");
	y++;

	//Proxima Palavra
	x = centraliza(12);
	gotoxy(38,y);
	textcolor(GREENWATER);
	printf("_");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf("     | |");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf("   __| | ___");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf("  / _` |/ _ \\");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | (_| |  __/");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf("  \\__,_|\\___|");
	y++;

	//Proxima Palavra
	x = centraliza(27);
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf("  _____            _");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |  __ \\          | |");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | |__) |__  _ __ | |_ ___");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |  ___/ _ \\| '_ \\| __/ _ \\");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" | |  | (_) | | | | || (_) |");
	y++;
	gotoxy(x, y);
	textcolor(GREENWATER);
	printf(" |_|   \\___/|_| |_|\\__\\___/");
	printf("\n\n");
	printf("\t\t\tPresione Enter Para Continuar");
	do{
		tecla = getch();
	}while(tecla != 13);
	
	
}

int centraliza(int tamanho){ //Função que retornara a coluna centralizada//
	return ((65 - tamanho)/2)+6;
}

void menu(){
	caixa_menu(C_MINIMA+1,C_MAXIMA-1,L_MINIMA+1,L_MAXIMA-1);
	caixa_menu(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	desenho();
	Sleep(500);
	system("cls");
	menuPrincipal();
	
}

int main(){
	
	system("mode 100,40");
	menu();
	//menu();
	
	return 0;
}

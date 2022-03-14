#include <stdio.h>
 //llibreria per utilitzar el clrscr 
#define FILES 3
#define COLUMNES 3
#define CUADRADO 254
#define ROJO 1
#define VERDE 2
#define INTC 206
#define CONV 186
#define CONH 205

int estaPlena(int graella[FILES][COLUMNES], int fila, int columna);
void inicialitzaMatriu (int graella[FILES][COLUMNES]); 
void introdueix(int graella[FILES][COLUMNES], int fila, int columna, int jugador);
int comprovaGuanyat(int graella[FILES][COLUMNES], int jugador);
int taules(int matriuJoc[FILES][COLUMNES]);
void imprimir(int graella[FILES][COLUMNES]);
void _textcolor(int);


int main(int argc, char *argv[])
{
 	char continuar; 
	int fila, columna;
	int fin=0;
	int graella[FILES][COLUMNES]; 
	
    do		
  	{	
		printf("3 en ralla 2k19\n");
		printf("1.JUGAR\n");
		printf("2.SALIR\n");
		scanf("%d",&fin);
		switch(fin)
		{
			case 1:
		//declaraci� variables locals i inicialitzaci� de variables per una nova partida
					_clrscr();
					printf("3 en ralla 2k19\n");
					int plena=0;
					int gana=0;
					int empata=0;
					int jugador;
					int nj=2;  //�s el nombre de la jugada. Comen�o amb 2 per evitarme 1/2
	
					inicialitzaMatriu(graella);  //comoncem a treballar amb la matriu graella[][]
					imprimir(graella);	
					while(gana==0&&empata==0)
	 					{
							if(nj%2==1)   // El jugador depen de si nj es par o impar
							{
								jugador=2;
							}else{jugador=1;}
		
							do
							{
		   						if(plena==1)  //aquest if est� aqu� per no executar directament aquest missatge despr�s del do si no acredita
		   						{
		  							printf("posicio plena\n"); 	
		   						}
								printf("\nTorn del jugador %i", jugador);
								printf("\nIntrodueix la fila i la columna: ");
								scanf("%d%d", &fila, &columna);
								while(fila<0||fila>3||columna<0||columna>3)
								{
									printf("posicio incorrecta!\n");
									printf("introdueix la fila i la columna: ");
									scanf("%d%d", &fila, &columna);
								}
								fila-=1;
								columna-=1;

								plena=estaPlena(graella, fila, columna);
							}while(plena==1);
							introdueix(graella, fila, columna, jugador);
							_clrscr();
							imprimir(graella);
							gana=comprovaGuanyat(graella, jugador); //error a la funcio que no deixa executar el programa
	   						empata=taules(graella);
							nj++; 
	
		
						}
					//fin del bucle de la partida
	
					if(gana==1)
					{
						printf("Jugador %i, has guanyat!\n",jugador);
					}
					if(empata==1)
					{
						printf("Heu empatat!\n");
					}		

	
		}		 
 	}while(fin!=2);
	return 0;

}


void inicialitzaMatriu (int graella[FILES][COLUMNES])
{
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			graella[i][j]=0;
		}
	}
}

int estaPlena(int graella[FILES][COLUMNES], int fila, int columna)
{
	if(graella[fila][columna]!=0)
	{
		return 1;
	}else{ return 0;}
}
void introdueix(int graella[FILES][COLUMNES], int fila, int columna, int jugador)
{
	graella[fila][columna]= jugador; 
}

int comprovaGuanyat(int graella[FILES][COLUMNES], int jugador)
{
	int suma=0;
	for(int i=0;i<3&&suma!=3;i++)//asi a ojo estos estan bien
	{
		suma=0;
		for(int j=0; j<3; j++)
		{
			if(graella[i][j]==jugador)
			{
				suma++;
			}
		}
	}//aqui si suma=3 no continua haciendo los bucles verticla y diagonal pk suma tiene que ser diferente de 0
	for(int j=0;j<3&&suma!=3;j++)//asi a ojo estos estan bien
	{
			suma= 0; 
		for(int i=0;i<3&&suma!=3;i++)
		{
			if(graella[i][j]==jugador)
			{
				suma++;
			}	
		}	
	}
		
	for(int d=0;d<COLUMNES&&suma!=3;d++)//asi a ojo esta tambien
	{	
		if(d==0)
		{suma=0;}
		if(graella[d][d]==jugador)
		{suma++;}
	}
	for(int di=0;di<FILES&&suma!=3;di++)
	{	
		if(di==0)
		{suma=0;}
		int dj=FILES-di-1;
		if(graella[di][dj]==jugador)
		{suma++;}
	}

	if(suma==3)
	{
		return 1;
	}else{return 0;}

}
int taules(int matriuJoc[FILES][COLUMNES])
{	
	int suma=0;
	for(int i=0; i<FILES; i++)
	{
		for(int j=0; j<COLUMNES; j++)
		{
			if(matriuJoc[i][j]!=0)
			{
				suma++;
			}
		}
	}if(suma==9){return 1;}
	else{return 0;}
}
void imprimir(int graella[FILES][COLUMNES])
{
	for(int i=0; i<FILES; i++)
	{
		for(int j=0; j<COLUMNES; j++)
		{
			if(j==0)
			{
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",INTC,CONH,CONH,CONH,INTC,CONH,CONH,CONH,INTC,CONH,CONH,CONH,INTC);
			}
			if(graella[i][j]==0)
			{
				printf("%c   ",CONV);
			}
			if(graella[i][j]==1)
			{
				printf("%c ",CONV);
				_textcolor(37);
				printf("%c ",CUADRADO);
				_textcolor(63);
			}
			if(graella[i][j]==2)
			{
				printf("%c ",CONV);
				_textcolor(27);
				printf("%c ",CUADRADO);
				_textcolor(63);
			}
			if(j==2)
			{
				printf("%c",CONV);
			}
		}printf("\n");
	}printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",INTC,CONH,CONH,CONH,INTC,CONH,CONH,CONH,INTC,CONH,CONH,CONH,INTC);
	

}

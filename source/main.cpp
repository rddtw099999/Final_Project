#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <iostream> 

void sudokuDataGen(void);
void sudokuDataScan(void);
void GameGUI(void);
void selectionPointer(int x,int y,int z);
void keyProcess(void);
void Reset(void); 

int sudokuData[9][9];
int sudokuDataIO[9][9];
int selectionRow=0; //���C 
int selectionCol=0; //��C 
int keyData; 
using namespace std; 

//�W72 �U80 ��75 �k77 


int main(void){
	system("title �ƿW�C��"); 
	sudokuDataGen();
	sudokuDataScan(); 
	GameGUI();
	while(1){	 
		keyProcess();
	}
	exit:; 
		system("pause");
	return 0;
} 

void sudokuDataGen(void){ 
		srand(time(NULL));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			sudokuData[i][j]=(rand()%10);
		}
	}
}
void sudokuDataScan(void){ 
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(sudokuData[i][j]==0)
				sudokuDataIO[i][j]=1; 
		}
	}
}

void GameGUI(void){
	system("cls"); 
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(selectionCol==i && selectionRow==j){
			    	selectionPointer(i,j,0); //�ثe��ܪ���� 
				}
				else{
				if(sudokuDataIO[i][j]==0){
					selectionPointer(i,j,1); //�D�خ� 
				} 
				else 
				if(sudokuData[i][j]==0){
					printf("  "); 
				}
				else
					printf(" %d",sudokuData[i][j]); 
				 // 
				} 
		}
		printf("\n");
	}
	if(sudokuDataIO[selectionCol][selectionRow]==1)  
	printf("\n%s","�y�z�G���׮�A�Ʀr��s�覹��",sudokuData[selectionCol][selectionRow]) ;
	else 
	printf("\n%s","�y�z�G�D�خ�A���i�ܧ�",sudokuData[selectionCol][selectionRow]) ;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n%s","����: Ctrl-E �^��D��� | ���s�}�l Ctrl-R | �x�s�ɮ� Ctrl-S  \n���� �������� | ��J���� Num0-9");
}


void keyProcess(void){ 
		keyData=getch(); 
	   if(keyData==72 || keyData==75||keyData==77||keyData==80){ 
	  	   switch(keyData){
				case 72:
					selectionCol--; 
		 			break; 
		 		case 75: 
		 			selectionRow--; 
		 			break;
		 		case 77: 
		 			selectionRow++; 
		 			break;
				case 80: 
					selectionCol++; 
		 			break;
			 } 
			 if(selectionRow>8)selectionRow=0; 
			 if(selectionCol>8)selectionCol=0; 
		 	 if(selectionRow<0)selectionRow=8; 
		 	 if(selectionCol<0)selectionCol=8; 
	    	 GameGUI();
       }
    	else if(keyData>=48 && keyData<=57 ){
    		if(sudokuDataIO[selectionCol][selectionRow]==1){
			
       		sudokuData[selectionCol][selectionRow]=keyData-48;
	    	GameGUI();
	    	Beep(500,10);
	    }
	     Beep(1500,10);
	   }
	   else if(keyData==18)
	   	Reset(); 
		else if(keyData==5){ 
			printf("function is now developing");
		} 
		else if(keyData==19){ 
			printf("function is now developing");
		} 
	   else
	   	Beep(100,10);
    
	}
	    


void selectionPointer(int x,int y,int z){ 
	printf ( " ");
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	if(z==0) 
	SetConsoleTextAttribute ( h, BACKGROUND_BLUE | FOREGROUND_INTENSITY );
	if(z==1) 
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
	printf ( "%d" ,sudokuData[x][y]); //
	SetConsoleTextAttribute ( h, wOldColorAttrs);
}

void Reset(void){
	selectionRow=0; 
	selectionCol=0;   		 
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(sudokuDataIO[i][j]==1)
				sudokuData[i][j]=0; 
		}
	}
	GameGUI();
} 





//���ߣ��ų��� 
//���ܣ�ʵ�ֿ���̨������С��Ϸ 
//���ڣ�2018.04.02   
//
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define N 15
using namespace std;
char chessborad[N][N];
enum chess_color{black,white};
int T=black;	//��ǵ�ǰ�ֵ�������߰��� 
int winner=-1;  //��¼ʤ����� 

//������ɫ
void setcolor(int Forecolor=0xe,int Backcolor=0x9) { 
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Backcolor*16+Forecolor);
}

//�ƶ���� 
void gotoxy(int x,int y){
	COORD point;
	point.X=x;
	point.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}

//��ʼ�����̣���ά���������'.'�� 
void init_chessborad(){
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			chessborad[i][j]='.'; 
		}
	}
}

//��ӡ������� 
void printf_chessborad(){
	setcolor();
	for(int i=0;i<N;i++){
		gotoxy(0,i);
		if(i<9)	cout<<' ';
		cout<<i+1;
		for(int j=0;j<N;j++){
			gotoxy(2*i+2,j);
			cout << "��";
		}
	}
	cout<<endl<<"   1 2 3 4 5 6 7 8 9101112131415"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(chessborad[i][j]=='@'){
				setcolor(0x0);
				gotoxy(2*i+2,j);
				cout <<"��";
			}
			if(chessborad[i][j]=='#'){
				setcolor(0xf);
				gotoxy(2*i+2,j);
				cout <<"��";
			}
		}
	}
	gotoxy(0,N+1);
	cout <<endl;;
} 

int x,y;//��������

//���壬�ֵ����彫�����λ�ã���ά�����Ӧ���꣩ ��Ϊ'@' ,������Ϊ '#'
void play_chess(){
	setcolor(0xf,0);
	if(T==black){
		cout << "���������" <<endl;
		cout << "�������������������:" <<endl;
		cout << "(����������꣬�����������):" <<endl;
		gotoxy(0,N+5);cout<<"     ";//��յ�ǰλ������ 
		gotoxy(0,N+6);cout<<"     ";
		gotoxy(0,N+5);cin >> y >> x; 
	} 
	else if(T==white){
		cout << "���������" << endl;
		cout << "�������������������:" <<endl;
		cout << "(����������꣬�����������):" <<endl;
		gotoxy(0,N+5);cout<<"     ";
		gotoxy(0,N+6);cout<<"     ";
		gotoxy(0,N+5);cin >> y >> x;
	} 
	if(chessborad[x-1][y-1]=='.'){
		if(T==black){
			chessborad[x-1][y-1]='@';
			T=white;
		}
		else if(T==white){
			chessborad[x-1][y-1]='#';
			T=black;
		}
	}
	else {
		gotoxy(0,N+5);
		cout << "error";
		Sleep(500);
	}
}

//�жϽ�� 
int jungle_result(){
	x=x-1;
	y=y-1;	
	for(int i=0;i<5;i++){
		if(chessborad[x-i][y]==chessborad[x-i+1][y]&&chessborad[x-i][y]==chessborad[x-i+2][y]&&chessborad[x-i][y]==chessborad[x-i+3][y]&&chessborad[x-i][y]==chessborad[x-i+4][y]){
			if(chessborad[x][y]=='@')	return winner=black;
			else if(chessborad[x][y]=='#')	return winner=white;
		}
		else if(chessborad[x][y-i]==chessborad[x][y-i+1]&&chessborad[x][y-i]==chessborad[x][y-i+2]&&chessborad[x][y-i]==chessborad[x][y-i+3]&&chessborad[x][y-i]==chessborad[x][y-i+4]){
			if(chessborad[x][y]=='@')	return winner=black;
			else if(chessborad[x][y]=='#')	return winner=white;
		}
		else if(chessborad[x-i][y-i]==chessborad[x-i+1][y-i+1]&&chessborad[x-i][y-i]==chessborad[x-i+2][y-i+2]&&chessborad[x-i][y-i]==chessborad[x-i+3][y-i+3]&&chessborad[x-i][y-i]==chessborad[x-i+4][y-i+4]){
			if(chessborad[x][y]=='@')	return winner=black;
			else if(chessborad[x][y]=='#')	return winner=white;
		}
		else if(chessborad[x-i][y+i]==chessborad[x-i+1][y+i-1]&&chessborad[x-i][y+i]==chessborad[x-i+2][y+i-2]&&chessborad[x-i][y+i]==chessborad[x-i+3][y+i-3]&&chessborad[x-i][y+i]==chessborad[x-i+4][y+i-4]){
			if(chessborad[x][y]=='@')	return winner=black;
			else if(chessborad[x][y]=='#')	return winner=white;
		}
	}
	return -1;
}
int main(){
//	system("color f0");
	setcolor();
	do{
		int result;
		init_chessborad();
		printf_chessborad();
		do{
			play_chess();
			printf_chessborad();
			result=jungle_result();
			if(result>-1)	break;
		}while(1);	
		if(result==black){
			setcolor(0xc,0x9);
			cout << "black win" << endl;
			Sleep(2000);
			continue;
		}
		else if(result==white){
			setcolor(0x9,0xc);
			cout << "white win" << endl;
			Sleep(2000);
			continue;
		}
	}while(1);
	return 0;
	system("pause");
} 

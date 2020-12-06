#include<bits/stdc++.h>

using namespace std;


int turn=1;//1-p1//0-p2
char mark='0';//0-p1 //x-p2
int input;
void printinputmatrix() //pass
{
	cout<<endl<<endl<<"INPUT MATRIX"<<endl;
	cout<<"1 | 2 | 3"<<endl;
	cout<<"---------"<<endl;
	cout<<"4 | 5 | 6"<<endl;
	cout<<"---------"<<endl;
	cout<<"7 | 8 | 9"<<endl;
}
char board[3][3]={' ',' ', ' ',   //pass
		  ' ',' ', ' ',
		  ' ',' ', ' '};
		  

void printboard()
{
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"---------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
	cout<<"---------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
	
}
int addmark()//pass
{
	for(int i=0,k=1;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(k==input)
			{
				if(board[i][j]==' ')
				{
					board[i][j]=mark;
					return 1;
				}
				else
				{
					cout<<"Invalid Input"<<endl;
					return 0;
				}
			}
			k++;
		}
	}
	
}
int check()//pass
{
	//checking rows
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
	return 1;
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
	return 1;
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
	return 1;
	
	//checking columns
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
	return 1;
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
	return 1;
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
	return 1;
	
	//checking diagonals
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
	return 1;
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
	return 1;
	
	return 0;
	
}



int main()
{
	int won=0;
	int validinput=0;
	
	for(int i=0;i<9;i++)
	{
		system("cls");
		printboard();
		if(turn) cout<<"Player 1 turn Symbol:0"<<endl;
		else  cout<<"Player 2 turn Symbol:X"<<endl;
		printinputmatrix();
		cout<<"Enter the input matrix: "<<endl;
		cin>>input;
		while(input<1 || input>9)
		{
			cout<<"Valid input please:-"<<endl;
			cin>>input;
		}
		if(turn) mark='0';
		else mark='X';
		
		validinput=addmark();
		if(!validinput)
		{
			i--;
			continue;
		}
		won=check();
		if(won)
		{
			system("cls");
			if(turn) cout<<endl<<"*** Player 1 won ***"<<endl;
			else cout<<endl<<"*** Player 2 won ***"<<endl;
			break;
		}
		if(i==8)
		{
			system("cls");
			cout<<endl<<"*** Match Draw ***"<<endl;
		}
		if(turn==0)turn=1;
		else	turn=0;
	} 	
	return 0;
}

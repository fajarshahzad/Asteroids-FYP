///************************************************LIBRARIES*******************************************///
#include<iostream>
#include<windows.h>   
#include<conio.h>
#include<iomanip>
using namespace std;
///************************************************GOTO FUNCTION*******************************************///
void gotoxy(int x, int y);
///************************************************GETCHAR FUNCTION*******************************************///
char getCharAtxy(short int x, short int y);
/// PRINT TITLE
void printName();
/// PRINT MAZE
void printBoundary();
///*************************************************FUNCTIONS OF PLAYER**********************************///
void printPlayer();
void movePlayerRight();
void movePlayerLeft();
void movePlayerUp();
void movePlayerDown();
void erasePlayer();
void printPlayerFIRE();
void movePlayerFIRE();
///***********************************************PLAYER'S VARIABLES*******************************************///
int pX=27 ,   pY=27;
int score=0;
int health=3;
int PlayerbulletX = 0;
int PlayerbulletY = 0;
bool Playerfired = false;
///************************************************ENEMEY'S FUNCTIONS************************************///
void printEnemy1();
void printEnemy2();
void printEnemy3();
void moveEnemy1();
void moveEnemy2();
void moveEnemy3();
void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();
void printE1FIRE();
void printE2FIRE();
void moveE1FIRE();
void moveE2FIRE();
void printE3FIRE();
void moveE3FIRE();
string Menu();
void EndGame();
void options();
void welcome();
void Won();
void GameOver();
///********************************************ENEMEY'S VARIABLES******************************************///
int x=85,y=0;
int lives1=5;
int lives2=5;
int lives3=5;
int eX1=3 ,  eY1=2;
bool eY1wallhit=false;
int eX2=30 , eY2=2;
bool eX2wallhit=false;
int eX3=55 ,  eY3=2;
bool eX3wallhit=false;
bool E1fired = false;
int bullet1X = 0;
int bullet1Y = 0;
bool E2fired = false;
int bullet2X = 0;
int bullet2Y = 0;
bool E3fired = false;
int bullet3X = 0;
int bullet3Y = 0;
///******************************Static color setting function for better UI**************************************///
/// COLOR               INT VALUES
/// -------------------------------
/// BLACK                   0
/// BLUE                    1
/// GREEN                   2
/// CYAN                    3   
/// RED                     4
/// MAGENTA                 5
/// BROWN                   6 
/// LIGHTGRAY               7 
/// DARKGRAY                8
/// LIGHTBLUE               9
/// LIGHTGREEN             10
/// LIGHTCYAN              11
/// LIGHTRED               12
/// LIGHTMAGENTA           13
/// YELLOW                 14
/// WHITE                  15
string setcolor(unsigned short color);
///*********************************************DEFINATION OF GOTO AND GETCHAR FUNCTION*******************************///
void gotoxy(int x,int y)
{
	COORD coordinates;
	coordinates.X=x;
	coordinates.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';
}
///************************************PRINT TITLE *************************************************///
void printName()
{
	setcolor(3);
	cout<<R"(
	
  /$$$$$$              /$$                                   /$$       /$$          
 /$$__  $$            | $$                                  |__/      | $$          
| $$  \ $$  /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$  /$$  /$$$$$$$  /$$$$$$$
| $$$$$$$$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$ /$$__  $$| $$ /$$__  $$ /$$_____/
| $$__  $$|  $$$$$$   | $$    | $$$$$$$$| $$  \__/| $$  \ $$| $$| $$  | $$|  $$$$$$ 
| $$  | $$ \____  $$  | $$ /$$| $$_____/| $$      | $$  | $$| $$| $$  | $$ \____  $$
| $$  | $$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$      |  $$$$$$/| $$|  $$$$$$$ /$$$$$$$/
|__/  |__/|_______/    \___/   \_______/|__/       \______/ |__/ \_______/|_______/ 
                                                                                    
                                                                                    
                                                                                    )"<<endl;
    setcolor(15);
}
///************************************PRINT MAZE *************************************************///
void printBoundary()
{
	setcolor(3);
    cout<<"####################################################################################"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                     $                                                            #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl; 
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl; 
    cout<<"#                          $                                   $                   #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                       $                                          #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                 $                                                                #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"#                   $                                                              #"<<endl;
    cout<<"#                                                                            $     #"<<endl;
    cout<<"#                                                                                  #"<<endl;
    cout<<"####################################################################################"<<endl;
	setcolor(15);
} 
///************************************PLAYER FUNCTIONS *************************************************///
void printPlayer()
{
	setcolor(14);
    gotoxy(pX,pY);
    cout<<"  -----  ";
    gotoxy(pX,pY+1);
    cout<<"_       _";
    gotoxy(pX,pY+2);
    cout<<"|       |";
    gotoxy(pX,pY+3);
    cout<<"  _____  ";
    setcolor(15);
}
void erasePlayer()
{
    gotoxy(pX,pY);
    cout<<"           ";
    gotoxy(pX,pY+1);
    cout<<"           "; 
    gotoxy(pX,pY+2);
    cout<<"           ";
    gotoxy(pX,pY+3);
    cout<<"           ";
}
void movePlayerRight()
{
	if(getCharAtxy(pX+12,pY)=='$'|| getCharAtxy(pX+12,pY+1)=='$' || getCharAtxy(pX+12,pY+2)=='$'|| getCharAtxy(pX+12,pY+3)=='$')
	{
	score=score+10;
	erasePlayer();
	pX=pX+1;
	printPlayer();
	}
    if(getCharAtxy(pX+12,pY)==' '&& getCharAtxy(pX+12,pY+1)==' ' && getCharAtxy(pX+12,pY+2)==' '&& getCharAtxy(pX+12,pY+3)==' ')
	{
	erasePlayer();
	pX=pX+1;
	printPlayer();
	}
}
void movePlayerLeft()
{
	if(getCharAtxy(pX-1,pY)=='$'|| getCharAtxy(pX-1,pY+1)=='$' || getCharAtxy(pX-1,pY+2)=='$'  || getCharAtxy(pX-1,pY+3)=='$' )
	{
	score=score+10;
	erasePlayer();
	pX=pX-1;
	printPlayer();
	}
	if(getCharAtxy(pX-1,pY)==' '&& getCharAtxy(pX-1,pY+1)==' ' && getCharAtxy(pX-1,pY+2)==' '&& getCharAtxy(pX-1,pY+3)==' ' )
	{
	erasePlayer();
	pX=pX-1;
	printPlayer();
	}
}
void movePlayerUp()
{
	if(getCharAtxy(pX,pY-1)=='$'|| getCharAtxy(pX+1,pY-1)=='$' || getCharAtxy(pX+2,pY-1)=='$' || getCharAtxy(pX+3,pY-1)=='$' || getCharAtxy(pX+4,pY-1)=='$' ||getCharAtxy(pX+5,pY-1)=='$'|| getCharAtxy(pX+6,pY-1)=='$'|| getCharAtxy(pX+7,pY-1)=='$'|| getCharAtxy(pX+8,pY-1)=='$')
	{
	score=score+10;
	erasePlayer();
	pY=pY-1;
	printPlayer();
	}
	if(getCharAtxy(pX,pY-1)==' ' && getCharAtxy(pX+1,pY-1)==' '&& getCharAtxy(pX+2,pY-1)==' ' && getCharAtxy(pX+3,pY-1)==' '&& getCharAtxy(pX+4,pY-1==' ')&& getCharAtxy(pX+5,pY-1)==' '&& getCharAtxy(pX+6,pY-1)==' '&& getCharAtxy(pX+7,pY-1)==' '&& getCharAtxy(pX+8,pY-1)==' ')
	{
	erasePlayer();
	pY=pY-1;
	printPlayer();
	}
}
void movePlayerDown()
{
	if(getCharAtxy(pX,pY+4)=='$'|| getCharAtxy(pX+1,pY+4)=='$' || getCharAtxy(pX+2,pY+4)=='$'|| getCharAtxy(pX+3,pY+4)=='$'|| getCharAtxy(pX+4,pY+4)=='$'|| getCharAtxy(pX+5,pY+4)=='$')
	{
		score=score+10;
		erasePlayer();
		pY=pY+1;
		printPlayer();
	}	
	if(getCharAtxy(pX,pY+4)==' '&& getCharAtxy(pX+1,pY+4)==' ' && getCharAtxy(pX+2,pY+4)==' '&& getCharAtxy(pX+3,pY+4)==' '&& getCharAtxy(pX+4,pY+4)==' '&& getCharAtxy(pX+5,pY+4)==' ')
	{
		erasePlayer();
		pY=pY+1;
		printPlayer();
	}	
}
///************************************ENEMEY'S FUNCTIONS *************************************************///
void printEnemy1()
{
	setcolor(14);
	gotoxy(eX1,eY1);
	cout<<"   ^     ^   ";
	gotoxy(eX1,eY1+1);
	cout<<"    ^   ^     ";
	gotoxy(eX1,eY1+2);
	cout<<"      ^       ";
	gotoxy(eX1,eY1+3); 
	cout<<"    ^   ^    ";
	gotoxy(eX1,eY1+4);
	cout<<"   ^     ^   ";	
	setcolor(15);
}
void eraseEnemy1()
{
	gotoxy(eX1,eY1);
	cout<<"              ";
	gotoxy(eX1,eY1+1);
	cout<<"              ";
	gotoxy(eX1,eY1+2);
	cout<<"              ";
	gotoxy(eX1,eY1+3);
	cout<<"             ";
	gotoxy(eX1,eY1+4);
	cout<<"             ";	
}
void printEnemy2()
{
	setcolor(14);
	gotoxy(eX2,eY2);
	cout<<" @@@@@@@@   ";
	gotoxy(eX2,eY2+1);
	cout<<" @@@@@@@@   ";
	gotoxy(eX2,eY2+3);
	cout<<" @ %  % @   ";
	gotoxy(eX2,eY2+4);
	cout<<" @ %  % @   ";
	gotoxy(eX2,eY2+5);
	cout<<"     @     ";
	setcolor(15);
}
void eraseEnemy2()
{
	gotoxy(eX2,eY2);
	cout<<"           ";
	gotoxy(eX2,eY2+1);
	cout<<"           ";
	gotoxy(eX2,eY2+3);
	cout<<"           ";
	gotoxy(eX2,eY2+4);
	cout<<"           ";
	gotoxy(eX2,eY2+5);
	cout<<"            ";
}
void printEnemy3()
{
	setcolor(14);
	gotoxy(eX3,eY3);
	cout<<"  *******   ";
	gotoxy(eX3,eY3+1);
	cout<<"   *****    ";
	gotoxy(eX3,eY3+2);
	cout<<"    ***      ";
	gotoxy(eX3,eY3+3);
	cout<<"     *     ";
	setcolor(15);
}
void eraseEnemy3()
{
	gotoxy(eX3,eY3);
	cout<<"            ";
	gotoxy(eX3,eY3+1);
	cout<<"            ";
	gotoxy(eX3,eY3+2);
	cout<<"            ";
	gotoxy(eX3,eY3+3);
	cout<<"            ";
}
void moveEnemy1()
{
	eraseEnemy1();
	if(!eY1wallhit)
	eY1=eY1+1;
	if(eY1==25)
	{
		eY1wallhit=true;
	}
	if(eY1wallhit)
	{
	eY1=eY1-1;
	if(eY1<2)
	eY1wallhit=false;
		}
	printEnemy1();	
}
void moveEnemy2()
{
	eraseEnemy2();
	if(!eX2wallhit)
	eX2=eX2+1;
	if(eX2==43)
	{
		eX2wallhit=true;
	}
	if(eX2wallhit)
	{
	eX2=eX2-1;
	if(eX2<30)
	eX2wallhit=false;
	}
	printEnemy2();
	
}
void moveEnemy3()
{
	eraseEnemy3();
	if(!eX3wallhit)
	{
	eX3=eX3+1;
	eY3=eY3+1;
	}
	if(eX3==65&&eY3==12)
	{
	eX3wallhit=true;
	}
	if(eX3wallhit)
	{
	eX3=eX3-1;
	eY3=eY3-1;
	if(eX3<56&&eY3<4)
	eX3wallhit=false;	
	}
	printEnemy3();	

}
///************************************MAIN FUNCTION *************************************************///
main()
{
	system("cls");
	welcome();
	string value = "";
	while (value!="3")
	{
		value=Menu();
	}
	
}
///************************************FIRING FUNCTIONS *************************************************///
void movePlayerFIRE()
{
    gotoxy(PlayerbulletX, PlayerbulletY);
    cout << " ";
    if (getCharAtxy(PlayerbulletX, PlayerbulletY - 1) == ' ')
    {
        PlayerbulletY = PlayerbulletY-1;
        gotoxy(PlayerbulletX, PlayerbulletY);
        cout << "!";
    }
    else if (getCharAtxy(PlayerbulletX,PlayerbulletY - 1) == '*')
    {
    	lives3--;
    	PlayerbulletY = PlayerbulletY-1;
        gotoxy(PlayerbulletX, PlayerbulletY);
        cout << "!";
        if(lives3==0)
        {
        	eraseEnemy3();
		}
	}
	else if (getCharAtxy(PlayerbulletX,PlayerbulletY - 1) == '@'||getCharAtxy(PlayerbulletX,PlayerbulletY-1)=='%')
    {
    	
    	PlayerbulletY = PlayerbulletY-1;
        gotoxy(PlayerbulletX, PlayerbulletY);
        cout << "!";
        lives2--;
        if(lives2==0)
        {
        	eraseEnemy2();
		}
	}
	else if (getCharAtxy(PlayerbulletX,PlayerbulletY - 1) == '^')
    {
    	lives1--;
    	PlayerbulletY = PlayerbulletY-1;
        gotoxy(PlayerbulletX, PlayerbulletY);
        cout << "!";
        if(lives1==0)
        {
        	eraseEnemy1();
		}
	}
    else
    {
        gotoxy(PlayerbulletX, PlayerbulletY);
        cout << " ";
        Playerfired = false;
    }
}
void printPlayerFIRE()
{
    PlayerbulletX = pX + 4;
    PlayerbulletY = pY - 1;
    gotoxy(PlayerbulletX, PlayerbulletY);
    cout << "!";
}
void printE1FIRE()
{
	if (getCharAtxy(eX1 + 7, eY1 + 7) == ' ')
	{

    bullet1X = eX1 + 7;
    bullet1Y = eY1 + 7;
    gotoxy(bullet1X, bullet1Y);
    cout << "^";
	}
}
void moveE1FIRE()
{
    gotoxy(bullet1X, bullet1Y);
    cout << " ";
    if (getCharAtxy(bullet1X, bullet1Y+1) == ' ')
    {
        bullet1Y = bullet1Y+1;
        gotoxy(bullet1X, bullet1Y);
        cout << "^";
    }
    else if (getCharAtxy(bullet1X,bullet1Y + 1) == '|'||getCharAtxy(bullet1X,bullet1Y + 1)=='-'||getCharAtxy(bullet1X,bullet1Y + 1)=='_')
    {
    	score--;
    	bullet1Y= bullet1Y+1;
        gotoxy(bullet1X, bullet1Y);
        cout << "^";
        if(score==0)
        {
        	health--; 
		}
	}
	else
	{
		gotoxy(bullet1X, bullet1Y);
        cout << " ";
        E1fired = false;
	}
}
void printE2FIRE()
{
    bullet2X = eX2 + 6;
    bullet2Y = eY2 + 6;
    gotoxy(bullet2X, bullet2Y);
    cout << "%";
}
void moveE2FIRE()
{
    gotoxy(bullet2X, bullet2Y);
    cout << " ";
    if (getCharAtxy(bullet2X, bullet2Y+1) == ' ')
    {
        bullet2Y = bullet2Y+1;
        gotoxy(bullet2X, bullet2Y);
        cout << "%";
    }
    else if (getCharAtxy(bullet2X,bullet2Y+1) == '|'||getCharAtxy(bullet2X,bullet2Y+1)=='-'||getCharAtxy(bullet2X,bullet2Y+1)=='_')
    {
    	score--;
    	bullet2Y = bullet2Y+1;
        gotoxy(bullet2X, bullet2Y);
        cout << "%";
        if(score==0)
        {
        	health--; 
		}
	}
	else
	{
		gotoxy(bullet2X, bullet2Y);
        cout << " ";
        E2fired = false;
	}
}
void printE3FIRE()
{
    bullet3X = eX3 + 6;
    bullet3Y = eY3 + 6;
    gotoxy(bullet3X, bullet3Y);
    cout << "*";
}
void moveE3FIRE()
{
    gotoxy(bullet3X, bullet3Y);
    cout << " ";
    if (getCharAtxy(bullet3X, bullet3Y+1) == ' ')
    {
        bullet3Y = bullet3Y+1;
        gotoxy(bullet3X, bullet3Y);
        cout << "*";
    }
    else if (getCharAtxy(bullet3X,bullet3Y+1) == '|'||getCharAtxy(bullet3X,bullet3Y+1)=='-'||getCharAtxy(bullet3X,bullet3Y+1)=='_')
    {
    	score--;
    	bullet3Y = bullet3Y+1;
        gotoxy(bullet3X, bullet3Y);
        cout << "*";
        if(score==0)
        {
        	health--; 
		}
	}
	else
	{
		gotoxy(bullet3X, bullet3Y);
        cout << " ";
        E3fired = false;
	}
}
///************************************COLOR SETTING*************************************************///
string setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	return "";
}
///************************************MAIN MENU *************************************************///
string Menu()
{
	string option;
			
	while(option!="3")
	{
		cout<<endl;
		options();
	again:
		cout<<"Enter your option: ";
		cin>>option;
		if(option<"1"||option>"3")
		{
			cout<<"Invalid option"<<endl;
			goto again;
		}
		if(option=="1")
		{	
			system("cls");
			printBoundary();
			printName();
			printPlayer();
			printEnemy1();
			printEnemy2();
			while(true)
		    {
					if(GetAsyncKeyState(VK_LEFT))
					{
						movePlayerLeft();
					}
					if(GetAsyncKeyState(VK_RIGHT))
					{
						movePlayerRight();
					}
					if(GetAsyncKeyState(VK_UP))
					{
						movePlayerUp();
					}
					if(GetAsyncKeyState(VK_DOWN))
					{
						movePlayerDown();
					}
        			if (GetAsyncKeyState('M'))
        			{
            			if (!Playerfired)
            			{
                			printPlayerFIRE();
                			Playerfired = true;
            			}
						if(Playerfired)
						{
							movePlayerFIRE();	
						}	
        			}		
        			if(GetAsyncKeyState(VK_ESCAPE))
        			{
        			EndGame();
        			break;
					}
					setcolor(14);
					if (!E1fired)
					{
						printE1FIRE();
						E1fired = true;
					}
					if (E1fired)
					{
						moveE1FIRE();
					}
					if(lives1==0)
					{
					eraseEnemy1();
					E1fired = true;	
					}
					if (!E2fired)
					{
						printE2FIRE();
						E2fired = true;
					}
					if (E2fired)
					{
						moveE2FIRE();
					}
					if(lives2==0)
					{
					eraseEnemy2();
					E2fired = true;	
					}
					if (!E3fired)
					{
						printE3FIRE();
						E3fired = true;
					}
					if (E3fired)
					{
						moveE3FIRE();
					}
					if(lives3==0)
					{
					eraseEnemy3();
					E3fired = true;	
					}
        			gotoxy(x,y);
        			if(score==0)
        				cout << "SCORE= " << 0;
	    				else
						cout<<"SCORE= "<<score;
	    			gotoxy(x,y+1);
	    			cout<<"LIVES OF ENEMY 1= "<<lives1;
	    			gotoxy(x,y+2);
	    			cout<<"LIVES OF ENEMY 2= "<<lives2;
	    			gotoxy(x,y+3);
	    			cout<<"LIVES OF ENEMY 3= "<<lives3;
	    			gotoxy(x,y+4);
	    			cout<<"HEALTH= "<<health;
	    			setcolor(15);
					if (lives1!=0)
					moveEnemy1();
					Sleep(50);
					if (lives2!=0)
					moveEnemy2();
					Sleep(50);
					if (lives3!=0)
					moveEnemy3();
					Sleep(50);
//		if (score!=0)
//			movePlayerUp();
//			movePlayerDown();
//			movePlayerLeft();
//			movePlayerRight();
//			Sleep(50);
			if(lives1==0&&lives2==0&&lives3==0)
			{
				system("cls");
				Won();
				Sleep(600);
				break;
			}
			if(health==0)
			{
				system("cls");
				GameOver();
				Sleep(600);
				break;
			}

		}
	}
	if(option=="2")
	{
		system("cls");
		printName();
		  	cout << " 1. Press Left Arrow Key <- to move Left the Spaceship" << endl;
		  	cout<<endl;
            cout << " 2. Press Right Arrow Key -> to move Right the Spaceship" << endl;
            cout<<endl;
            cout << " 3. Press M key to Fire " << endl;
            cout<<endl;
            cout << " 4. Keep Spaceship Away From The Enemies and their Fire " << endl;
            cout<<endl;
            cout << " 5. Save your lives otherwise you'll lose:("<<endl;
            cout<<endl;
            cout << " 6. Press ESC key to End the Game "<<endl;
            cout<<endl;
            cout << ">>>>Press any key to continue...";
            getch();
	}
	system("cls");
}
	return option;
}
///************************************CLEARING SYSTEM*************************************************///
void EndGame()
{
	system("cls");
}
///************************************PRINT WELCOME*************************************************///
void welcome()
{
	setcolor(14);
	cout<<R"(
 $$$$$$\                          $$\                            $$$$$$\                                              $$$\   
$$  __$$\                         \__|                          $$  __$$\                                              \$$\  
$$ /  \__| $$$$$$\  $$$$$$\$$$$\  $$\ $$$$$$$\   $$$$$$\        $$ /  $$ | $$$$$$\   $$$$$$\  $$$$$$$\   $$$$$$\  $$\   \$$\ 
$$ |$$$$\  \____$$\ $$  _$$  _$$\ $$ |$$  __$$\ $$  __$$\       $$$$$$$$ |$$  __$$\ $$  __$$\ $$  __$$\  \____$$\ \__|   $$ |
$$ |\_$$ | $$$$$$$ |$$ / $$ / $$ |$$ |$$ |  $$ |$$ /  $$ |      $$  __$$ |$$ |  \__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |       $$ |
$$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |$$\   $$  |
\$$$$$$  |\$$$$$$$ |$$ | $$ | $$ |$$ |$$ |  $$ |\$$$$$$$ |      $$ |  $$ |$$ |      \$$$$$$$\ $$ |  $$ |\$$$$$$$ |\__|$$$  / 
 \______/  \_______|\__| \__| \__|\__|\__|  \__| \____$$ |      \__|  \__|\__|       \_______|\__|  \__| \_______|    \___/  
                                                $$\   $$ |                                                                   
                                                \$$$$$$  |                                                                   
                                                 \______/                                                                    
	)"<<endl;
	setcolor(15);
}
///************************************PRINT OPTIONS*************************************************///
void options()
{
	setcolor(3);
	cout<<R"(
  $$\       $$$$$$\    $$\                          $$\                                                                       
$$$$ |     $$  __$$\   $$ |                         $$ |                                                                      
\_$$ |     $$ /  \__|$$$$$$\    $$$$$$\   $$$$$$\ $$$$$$\                                                                     
  $$ |     \$$$$$$\  \_$$  _|   \____$$\ $$  __$$\\_$$  _|                                                                    
  $$ |      \____$$\   $$ |     $$$$$$$ |$$ |  \__| $$ |                                                                      
  $$ |     $$\   $$ |  $$ |$$\ $$  __$$ |$$ |       $$ |$$\                                                                   
$$$$$$\ $$\\$$$$$$  |  \$$$$  |\$$$$$$$ |$$ |       \$$$$  |                                                                  
\______|\__|\______/    \____/  \_______|\__|        \____/                                                                   
                                                                                                                              
                                                                                                                              
                                                                                                                              
 $$$$$$\      $$$$$$\                       $$\                                     $$\     $$\                               
$$  __$$\     \_$$  _|                      $$ |                                    $$ |    \__|                              
\__/  $$ |      $$ |  $$$$$$$\   $$$$$$$\ $$$$$$\    $$$$$$\  $$\   $$\  $$$$$$$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ 
 $$$$$$  |      $$ |  $$  __$$\ $$  _____|\_$$  _|  $$  __$$\ $$ |  $$ |$$  _____|\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|
$$  ____/       $$ |  $$ |  $$ |\$$$$$$\    $$ |    $$ |  \__|$$ |  $$ |$$ /        $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\  
$$ |            $$ |  $$ |  $$ | \____$$\   $$ |$$\ $$ |      $$ |  $$ |$$ |        $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ 
$$$$$$$$\ $$\ $$$$$$\ $$ |  $$ |$$$$$$$  |  \$$$$  |$$ |      \$$$$$$  |\$$$$$$$\   \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |
\________|\__|\______|\__|  \__|\_______/    \____/ \__|       \______/  \_______|   \____/ \__| \______/ \__|  \__|\_______/ 
                                                                                                                              
                                                                                                                              
                                                                                                                              
 $$$$$$\      $$$$$$$$\           $$\   $$\                                                                                   
$$ ___$$\     $$  _____|          \__|  $$ |                                                                                  
\_/   $$ |    $$ |      $$\   $$\ $$\ $$$$$$\                                                                                 
  $$$$$ /     $$$$$\    \$$\ $$  |$$ |\_$$  _|                                                                                
  \___$$\     $$  __|    \$$$$  / $$ |  $$ |                                                                                  
$$\   $$ |    $$ |       $$  $$<  $$ |  $$ |$$\                                                                               
\$$$$$$  |$$\ $$$$$$$$\ $$  /\$$\ $$ |  \$$$$  |                                                                              
 \______/ \__|\________|\__/  \__|\__|   \____/                                                                               
	)"<<endl;
	setcolor(15);
}
///************************************PRINT WINING STATE*************************************************///
void Won()
{
	setcolor(3);
	cout<<R"(
	
$$\     $$\                         $$\      $$\                         $$$\   
\$$\   $$  |                        $$ | $\  $$ |                         \$$\  
 \$$\ $$  /$$$$$$\  $$\   $$\       $$ |$$$\ $$ | $$$$$$\  $$$$$$$\  $$\   \$$\ 
  \$$$$  /$$  __$$\ $$ |  $$ |      $$ $$ $$\$$ |$$  __$$\ $$  __$$\ \__|   $$ |
   \$$  / $$ /  $$ |$$ |  $$ |      $$$$  _$$$$ |$$ /  $$ |$$ |  $$ |       $$ |
    $$ |  $$ |  $$ |$$ |  $$ |      $$$  / \$$$ |$$ |  $$ |$$ |  $$ |$$\   $$  |
    $$ |  \$$$$$$  |\$$$$$$  |      $$  /   \$$ |\$$$$$$  |$$ |  $$ |\__|$$$  / 
    \__|   \______/  \______/       \__/     \__| \______/ \__|  \__|    \___/                                                                                                                                                                                                                                                
	)"<<endl;
	setcolor(15);
}
///************************************PRINT LOSING STATE*************************************************///
void GameOver()
{
	setcolor(14);
	cout<<R"(
 $$$$$$\                                     $$$$$$\                                      $$$\ 
$$  __$$\                                   $$  __$$\                                    $$  _|
$$ /  \__| $$$$$$\  $$$$$$\$$$$\   $$$$$$\  $$ /  $$ |$$\    $$\  $$$$$$\   $$$$$$\ $$\ $$  /  
$$ |$$$$\  \____$$\ $$  _$$  _$$\ $$  __$$\ $$ |  $$ |\$$\  $$  |$$  __$$\ $$  __$$\\__|$$ |   
$$ |\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  $$ | \$$\$$  / $$$$$$$$ |$$ |  \__|   $$ |   
$$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|$$ |  $$ |  \$$$  /  $$   ____|$$ |     $$\ \$$\   
\$$$$$$  |\$$$$$$$ |$$ | $$ | $$ |\$$$$$$$\  $$$$$$  |   \$  /   \$$$$$$$\ $$ |     \__| \$$$\ 
 \______/  \_______|\__| \__| \__| \_______| \______/     \_/     \_______|\__|           \___|	
	)"<<endl;
	setcolor(15);
}


#include <iGraphics.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <shellapi.h>

void gameover();
int score=0;
char scoreText[100];

int pic_x=0, pic_y=0,gox=0,goy=0,life=0;
int car1x=250,car1y=10,car2x=230,car2y=390,car3x=310,car3y=280,car4x=260,car4y=190,car5x=190,car5y=100,car6x=140,car6y=310,car7x=335,car7y=100;

void iDraw()
{

	iClear();
	iShowBMP(pic_x, pic_y, "road.bmp");

	iShowBMP(car2x,car2y, "car2.bmp");
	iShowBMP(car3x,car3y, "car3.bmp");
	iShowBMP(car4x,car4y, "car4.bmp");
	iShowBMP(car5x,car5y, "car5.bmp");
	iShowBMP(car6x,car6y, "car6.bmp");
	iShowBMP(car7x,car7y, "car7.bmp");
	iShowBMP(car1x,car1y, "car1.bmp");

	iSetColor(255,0,0);
	iText(335,420,"Score:");
	_itoa_s(score,scoreText,10);
	iText(385,420,scoreText);


	if(car1x>=200 && car1x<=255 && car2y==80){
		iShowBMP(gox,goy, "gameover.bmp");
		life=1;
	}
	if(car1x>=290 && car1x<=345 && car3y==80){
		iShowBMP(gox,goy, "gameover.bmp");
		life=1;
	}
	if(car1x>=230 && car1x<=285 && car4y==80){
		iShowBMP(gox,goy, "gameover.bmp");
		life=1;
	}
	if(car1x>=165 && car1x<=215 && car5y==80){
		iShowBMP(gox,goy, "gameover.bmp");
		life=1;
	}
	if(car1x>=140 && car1x<=165 && car6y==80){
		iShowBMP(gox,goy, "gameover.bmp");
		life=1;
	}
	if(car1x>=305 && car1x<=335 && car7y==80){
		iShowBMP(gox,goy, "gameover.bmp");
		life=1;
	}



}
void carmove(){
	if(life==0){
	car2y-=5;
	car3y-=5;
	car4y-=5;
	car5y-=5;
	car6y-=5;
	car7y-=5;

	if(car2y<0){
		score++;
		car2y=390;
	}
	if(car3y<0){
		score++;
		car3y=390;
	}
	if(car4y<0){
		score++;
		car4y=390;
	}
	if(car5y<0){
		score++;
		car5y=390;
	}
	if(car6y<0){
		score++;
		car6y=390;
	}
	if(car7y<0){
		score++;
		car7y=390;
	}
	}
}


void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

}

void iKeyboard(unsigned char key)
{

}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_LEFT)
	{
		if(car1x!=140){
		car1x-=5;
	}
	}

	if(key == GLUT_KEY_RIGHT)
	{
		if(car1x!=335){
		car1x+=5;
	}
	}
}


int main()
{
	ShellExecute(NULL, "open","dhoom.mp3", 0, 0, 0);
	if(life==0){
	iSetTimer(150, carmove);
	}
iInitialize(500,450,"SAVE YOUR CAR");
return 0;
}

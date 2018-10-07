#include<string.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
//#include<dos.h>
union REGS in,o;
int i,j,driver,mode,x,y,k,c[10],count=0,but,xc,yc;
char name[100];
void squaree(int);
void getmove();
void myfirstmove();
void mysecmove();
void mythirdmove();
void myfourthmove();
void iswin();
void print(int);
int initmouse()
{
in.x.ax=0;
int86(0x33,&in,&o);
return(in.x.ax);
}
void showmouse()
{
in.x.ax=1;
int86(51,&in,&o);
}
void getps(int *b,int *xco,int *yco)
{
in.x.ax=3;
int86(51,&in,&o);
*b=o.x.bx;
*xco=o.x.cx;
*yco=o.x.dx;
}









void main()
{
driver= DETECT;
initgraph(&driver,&mode,"F:\\tc\\bgi");
clrscr();
initmouse();
setfillstyle(SOLID_FILL,0);
floodfill(0,0,0);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
setcolor(2);
squaree(100);
squaree(0);
for(i=0;i<10;i++)
c[i]=0;
showmouse();

getmove();myfirstmove();delay(1000);
getmove();mysecmove();delay(1000);
getmove();mythirdmove();iswin();delay(1000);
getmove();myfourthmove();iswin();
for(i=1;i<10;i++)
cout<<c[i];
getch();
}





void getmove()
{
while(1)
{
getps(&but,&xc,&yc);
if(but==1)
{
	if(xc>400&&xc<420)
	{
	      if(yc>25&&yc<45&&c[1]==0)
	      {
	      moveto( 410,135);
	      outtext("x");c[1]=1;break;
	      }
	      if(yc>45&&yc<65&&c[2]==0)
	      {
	      moveto( 410,155);  c[2]=1;
	      outtext("x");break;
	      }
	      if(yc>65&&yc<85&&c[3]==0)
	      {
	      moveto( 410,175);
	      outtext("x");c[3]=1;  break;
	      }
	}
	if(xc>420&&xc<440)
	{
	      if(yc>25&&yc<45&&c[4]==0)
	      {
	      moveto( 430,135);
	      outtext("x");c[4]=1;  break;
	      }
	      if(yc>45&&yc<65&&c[5]==0)
	      {
	      moveto( 430,155);
	      outtext("x");c[5]=1;  break;
	      }
	      if(yc>65&&yc<85&&c[6]==0)
	      {
	      moveto( 430,175);
	      outtext("x"); c[6]=1; break;
	      }
	}
	if(xc>440&&xc<460)
	{
	      if(yc>25&&yc<45&&c[7]==0)
	      {
	      moveto( 450,135);
	      outtext("x"); c[7]=1; break;
	      }
	      if(yc>45&&yc<65&&c[8]==0)
	      {
	      moveto( 450,155);
	      outtext("x");c[8]=1;  break;
	      }
	      if(yc>65&&yc<85&&c[9]==0)
	      {
	      moveto( 450,175);
	      outtext("x"); c[9]=1; break;
	      }
	}

}
}
}

void myfirstmove()
{
if(c[5]==0)
  {
  moveto(430,155);c[5]=2;
  outtext("o");
  }
else if(c[6]==0)
  {
  moveto(430, 175);c[6]=2;
  outtext("o");
  }
}
void mysecmove()
{
if(c[5]==1&&c[4]==1)
      {  moveto(450,275);
outtext("o");
      }
}
void mythirdmove()
{

}
void myfourthmove()
{

}












void iswin()
{
int x;
for(int co=0;co<=6;co+=3)
{
if(c[co+1]==c[co+2]&&c[co+2]==c[co+3])
{
x=c[co+2];
print(x);
} }
for( co=0;co<=2;co++)
{
if(c[co+1]==c[co+4]&&c[co+4]==c[co+7])
{
x=c[co+4];
print(x);
}}
if(c[1]==c[5]&&c[5]==c[9])
{
x=c[5];
print(x);
}
if(c[3]==c[5]&&c[5]==c[7])
{
x=c[5];
print(x);
}
}




void print(int n)
{
if(n==1)
printf("u won the game");
else if(n==2)
printf("sorry!! you lose");
}















void squaree(int a=200)
{
rectangle(400,a+25,420,a+45);
rectangle(400,a+45,420,a+65);
rectangle(400,a+65,420,a+85);
rectangle(420,a+25,440,a+45);
rectangle(420,a+45,440,a+65);
rectangle(420,a+65,440,a+85);
rectangle(440,a+25,460,a+45);
rectangle(440,a+45,460,a+65);
rectangle(440,a+65,460,a+85);
int number =1;;
for(int l=0;l<=40;l+=20)
for(int f=0;f<=40;f+=20)
{
moveto(l+410,f+235);
printf("%d",number++);
}/*
moveto( 410,255);
outtext("2");
moveto( 410,275);
outtext("3");
moveto( 430,235);
outtext("4");
moveto( 430,255);
outtext("5");
moveto( 430,275);
outtext("6");
moveto( 450,235);
outtext("7");
moveto( 450,255);
outtext("8");
moveto( 450,275);
outtext("9");

}
*/}

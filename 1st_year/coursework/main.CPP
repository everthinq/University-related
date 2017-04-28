#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>


/////////////////////////////////Structures/////////////////////////////////////////
struct A{                                                                         //
    char type[2];                 /* Magic identifier            */               //
    unsigned long size;                       /* File size in bytes          */   //
    unsigned short int reserved1, reserved2;                                      //
    unsigned long offset;                     /* Offset to image data, bytes */   //
};                                                                                //
										  //
A HEADER,HEADER1;                                                                 //
										  //
struct B{                                                                         //
    unsigned long size;               /* Header size in bytes      */             //
    unsigned long width,height;                /* Width and height of image */    //
    unsigned short int planes;       /* Number of colour planes   */              //
    unsigned short int bits;         /* Bits per pixel            */              //
    unsigned long compression;        /* Compression type          */             //
    unsigned long imagesize;          /* Image size in bytes       */             //
    unsigned long xresolution,yresolution;     /* Pixels per meter          */    //
    unsigned long ncolours;           /* Number of colours         */             //
    unsigned long importantcolours;   /* Important colours         */             //
};                                                                                //
 B INFOHEADER,INFOHEADER1;                                                        //
////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////GLOBAL_C//////////////////////////////////////////
int XCor=0, YCor=0;
int x=1, y=1;
int sc=0;


////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////BG///////////////////////////////////////////////

void bg()
{
cleardevice();
setbkcolor(0);
}

////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////EGGS////////////////////////////////////////////////

void egg1 ()
   {
    
    setcolor(0);
    circle (x + 85, y + 273, 9);
    delay(200);
    setcolor(7);
    circle (x + 85, y + 273, 9);


    setcolor(0);
    circle (x + 105, y + 285, 9);
    delay(200);
    setcolor(7);
    circle (x + 105, y + 285, 9);


    setcolor(0);
    circle (x + 125, y + 297, 9);
    delay (200);
    setcolor(7);
    circle (x + 125, y + 297, 9);


    setcolor(0);
    circle (x + 145, y + 309, 9);
    delay (200);
    setcolor(7);
    circle (x + 145, y + 309, 9);


    setcolor(0);
    circle (x + 165, y + 321, 9);
    delay (200);
    setcolor(7);
    circle (x + 165, y + 321, 9);

}

void egg2 ()
   {
    setcolor(0);
    circle (x + 85, y + 447, 9);
    delay (200);
    setcolor(7);
    circle (x + 85, y + 447, 9);
  

    setcolor(0);
    circle (x + 105, y + 459, 9);
    delay (200);
     setcolor(7);
    circle (x + 105, y + 459, 9);
 

    setcolor(0);
    circle (x + 125, y + 471, 9);
    delay (200);
    setcolor(7);
    circle (x + 125, y + 471, 9);


    setcolor(0);
    circle (x + 145, y + 483, 9);
    delay (200);
    setcolor(7);
    circle (x + 145, y + 483, 9);
 
    

    setcolor(0);
    circle (x + 165, y + 495, 9);
    delay (200);
    setcolor(7);
    circle (x + 165, y + 495, 9);

   

 
   }


    void egg3 ()
   {

    setcolor(0);
    circle (x + 712, y + 273, 9);
    delay (200);
    setcolor(7);
    circle (x + 712, y + 273, 9); 
  

    setcolor(0);
    circle (x + 692, y + 285, 9);
    delay (200);
    setcolor(7);
    circle (x + 692, y + 285, 9);
  

    setcolor(0);
    circle (x + 672, y + 297, 9);
    delay (200);
    setcolor(7);
    circle (x + 672, y + 297, 9);

    
    setcolor(0);
    circle (x + 652, y + 309, 9);
    delay (200);
    setcolor(7);
    circle (x + 652, y + 309, 9);
    

    setcolor(0);
    circle (x + 632, y + 321, 9);
    delay (200);
    setcolor(7);
    circle (x + 632, y + 321, 9);
   

   }


    void egg4 ()
   {
    setcolor(0);
    circle (x + 712, y + 450, 9);
    delay (200);
    setcolor(7);
    circle (x + 712, y + 450, 9);


    setcolor(0);
    circle (x + 692, y + 462, 9);
    delay (200);
    setcolor(7);
    circle (x + 692, y + 462, 9);

   
    setcolor(0);
    circle (x + 672, y + 474, 9);
    delay (200);
    setcolor(7);
    circle (x + 672, y + 474, 9);
  

    setcolor(0);
    circle (x + 652, y + 486, 9);
    delay (200);
    setcolor(7);
    circle (x + 652, y + 486, 9);


    setcolor(0);
    circle (x + 632, y + 498, 9);
    delay (200);
    setcolor(7);
    circle (x + 632, y + 498, 9);



   
   }

//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Controls/////////////////////////////////////////

 void controls ()
{
int e;
randomize();
while(1)
{


e=random(5);

{

if (e==4){egg4();}
if (e==3){egg3();}
if (e==2){egg2();}
if (e==1){egg1();}

}

int c=0;
    if (kbhit())
    {
c=getch();
if (c==13) exit(1);
switch (c)
{
case 'q':

{setcolor(0);
arc( x + 215, y + 350, 180, 360, 35);
line(x + 210, y + 310, x + 210, y + 350); //levaya1
line(x + 210, y + 311, x + 250, y + 350); //pravaya1
line(x + 215, y + 320, x + 215, y + 350); //levaya2	
line(x + 215, y + 320, x + 245, y + 350); //pravaya2
line(x + 180, y + 350, x + 250, y + 350); //verh
setfillstyle(1,7);
bar (x + 175, y + 420, x + 270, y + 580);
bar (x + 530, y + 220, x + 615, y + 580);}


break;


case 'a':

{setcolor(0);
arc( x + 215, y + 520, 180, 360, 35);
line(x + 210, y + 480, x + 210, y + 520); //levaya1
line(x + 210, y + 481, x + 250, y + 520); //pravaya1
line(x + 215, y + 490, x + 215, y + 520); //levaya2
line(x + 215, y + 490, x + 245, y + 520); //pravaya2
line(x + 181, y + 520, x + 250, y + 520); //verh
setfillstyle(1,7);
bar (x + 175, y + 300, x + 250, y + 450);
bar (x + 530, y + 220, x + 615, y + 580);}

break;

case 'e':

{setcolor(0);
arc( x + 575, y + 350, 180, 360, 35);
line(x + 570, y + 310, x + 570, y + 350); //levaya1
line(x + 570, y + 311, x + 540, y + 350); //pravaya1
line(x + 565, y + 325, x + 545, y + 350);
line(x + 566, y + 325, x + 565, y + 350); //levaya2
line(x + 610, y + 350, x + 540, y + 350); //verh
setfillstyle(1,7);
bar (x + 615, y + 490, x + 535, y + 595);
bar (x + 175, y + 220, x + 255, y + 580);}

break;

case 'd':

{setcolor(0);
arc( x + 575, y + 530, 180, 360, 35);
line(x + 570, y + 490, x + 570, y + 530); //pr1
line(x + 570, y + 491, x + 540, y + 530); //lev1
line(x + 565, y + 505, x + 545, y + 530); //lev2
line(x + 565, y + 505, x + 565, y + 530); //pr2
line(x + 610, y + 530, x + 540, y + 530); //verh
setfillstyle(1,7);
bar (x + 530, y + 310, x + 610, y + 400);
bar (x + 175, y + 220, x + 255, y + 580);}


break;
}

if ((e==1)&&(c=='q'))
{

    setcolor(0);
    circle (x + 185, y + 333, 9);
    delay (400);
    setcolor(7);
    circle (x + 185, y + 333, 9);
clrscr();
sc++;

cout<<"\n                                                            "<<sc<<"                                    ";
}

if ((e==2)&&(c=='a'))
{
 
   setcolor(0);
    circle (x + 185, y + 507, 9);
    delay (400);
    setcolor(7);
    circle (x + 185, y + 507, 9);
 
clrscr();
sc++;
setcolor(7);

cout<<"\n                                                            "<<sc<<"                                    ";
}

if ((e==3)&&(c=='e'))
{

    setcolor(0);
    circle (x + 612, y + 333, 9);
    delay (400);  
    setcolor(7);
    circle (x + 612, y + 333, 9);

clrscr();
sc++;
setcolor(7);
cout<<"\n                                                            "<<sc<<"                                    ";
}



if ((e==4)&&(c=='d'))
{

    setcolor(0);
    circle (x + 612, y + 510, 9);
    delay (400);
    setcolor(7);
    circle (x + 612, y + 510, 9);

clrscr();
sc++;
setcolor(7);
bar (x -1, y + 4, x + 730, y + 4);
cout<<"\n                                                            "<<sc<<"                                    ";

}



}


}
}


//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Display Bitmap/////////////////////////////////////
huge DetectSvga()
{
    return 3;
}

void Show()
{
    fstream File;

    //Here you have to define the path of the bitmap file. Like according to this example i have to open one Board1.bmp file. So write you bitmap file path here.

    File.open("C:\\bitmaps\\1-4\\1st.bmp",ios::in);

    unsigned char Ch;

    File.read((char*)&HEADER,14); //This is the header part of the Bitmap. It always looks like same. Don't change the content hear. The value remains 14 here.

    File.read((char*)&INFOHEADER,40); //This is another part of the bitmap, here also the value remains same like 40 here.

    unsigned int i;
    char ColorBytes[4];
    char*PaletteData;

    PaletteData=new char[256*3];

    if(PaletteData)//if memory allocated successfully
    {
	//read color data
	for(i=0;i<256;i++)
	{
	    //Don't change the code here because i have done some shifting here. Its working fine.
	    File.read(ColorBytes,4);
	    PaletteData[(int)(i*3+2)]=ColorBytes[0]>>2;
	    PaletteData[(int)(i*3+1)]=ColorBytes[1]>>2;
	    PaletteData[(int)(i*3+0)]=ColorBytes[2]>>2;
	}

	outp(0x03c8,0);      //tell DAC that data is coming

	for(i=0;i<256*3;i++) //send data to SVGA DAC
	{
	    outp(0x03c9,PaletteData[i]);
	}
	delete[]PaletteData;
    }

    for(i=0;i<INFOHEADER.height;i++)       //This for loop is used to display the bitmap.
    {
	for(int j=0;j<INFOHEADER.width;)
	{
	    File.read(&Ch,1); // Here Ch reads the color of your bitmap.
	    putpixel(XCor+j++,YCor+INFOHEADER.height-i-1,Ch); //XCor and YCor are the X and Y cordinates. It depends upon you.

	}
    }

    File.close();

 
 controls();

  }

//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////HELP/////////////////////////////////////////

int help (int x, int y)
{
bg();

setcolor (4);
settextstyle (1, 0, 6);
outtextxy (x + 30, y-70, "Controls:");

setcolor (15);
settextstyle (1, 0, 4);
outtextxy (x + 30, y + 30, "q - left upper tray ");
outtextxy (x + 30, y + 130, "a - left lower tray ");
outtextxy (x + 30, y + 230, "e - right upper tray ");
outtextxy (x + 30, y + 330, "d - right lower tray");
      
      setcolor(4);   
      line (x + 400, y-100, x + 400, y + 601);

setcolor (4);
settextstyle (1, 0, 6);
outtextxy (x + 530, y-70, "Rules:");

setcolor (15);
settextstyle (1, 0, 2);
outtextxy (x + 410, y + 30, "Four chicken sitting on perches,lay");
outtextxy (x + 410, y + 50, "eggs,which rolls down for four trays.");
outtextxy (x + 410, y + 90, "Controlling the basket,which can");
outtextxy (x + 410, y + 110, "take four positions required to catch");
outtextxy (x + 410, y + 130, "as many eggs as possible.");
outtextxy (x + 410, y + 170, "When player caught one egg,");
outtextxy (x + 410, y + 190, "one point will be add to scoreboard.");


setcolor (4);
settextstyle (1, 0, 3);
outtextxy (x + 415, y + 270, "Press 'Enter' to play ");

setcolor (4);
settextstyle (1, 0, 3);
outtextxy (x + 415, y + 300, "Press 'Esc' to exit");

 char a;
 a = getch ();

if (a == 13) Show();
if (a == 27) exit(1);


return 0;}




//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////MENU/////////////////////////////////////////

void Menu (int x, int y)
{
 rectangle (x + 30, y + 30, x + 160, y + 80);
}

void paint_menu (int x, int y, int count)
{
 setcolor(3);
 for (int i = 0; i < count; i++)
 {
  Menu (x + i * 100, y - 100);
 }
}

void paint_menu_name_game (int x, int y, char *name_game[])
{
 setcolor (15);
 settextstyle (10, 0, 8);

 for (int i = 0; i < 1; i++)
 {
  outtextxy (x + i * 100 + 45, y + 20, name_game[i]);
 }
}

void paint_menu_text (int x, int y, char *PLAY[], char *HELP[], char *QUIT[])
{
 setcolor (4);
 settextstyle (10, 0, 4);

 for (int i = 0; i < 1; i++)
 {
  outtextxy (x + i * 150 + 330, y + 250, PLAY[i]);
  outtextxy (x + i * 160 + 334, y + 350, HELP[i]);
  outtextxy (x + i * 170 + 337, y + 450, QUIT[i]);
 }
}


int move_menu (int x, int y, int count)
{
 int count_menu = 0;
 char c = 0;
 count--;
 setcolor(7);
 {Menu(x + 295, y + 235);
 setcolor(0);}

 while (c != 13)
 {
  c = getch();

 if (!c) c += getch();
 switch (c)
 {
 case 80:
  {
   if (count_menu == count) count_menu = 0;
    else count_menu++;
   setcolor (7);
   y = count_menu * 100 + 10;
   Menu (x + 295, y + 226);


   if (count_menu > 0)
   {
    setcolor (0);
    Menu (x + 295, y + 126);
   }
    else
     {
      setcolor (0);
      Menu (x + 295, y + 426);
     }
  break;
  } // move down


  }
 }
 if ((c==13)&&(count_menu==0)) Show();
 if ((c==13)&&(count_menu==1)) help(x,y);
 if ((c==13)&&(count_menu==2)) exit(1);
 return count_menu;
}



//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////MAIN/////////////////////////////////////////
 int main()

{

 int x = 1;
 int y = 1;
 int count = 3;

 char *PLAY[] = {"PLAY\0"};
 char *HELP[] = {"HELP\0"};
 char *EXIT[] = {"QUIT\0"};
 char *name_game[] = {"NU,POGODI!\0"};

  int gd = DETECT, md, a;

    installuserdriver("SVGA256",&DetectSvga);
    initgraph(&gd,&md,"C:\\TC\\BGI"); //Path may be different in your computer.




 int count_menu;
 paint_menu (x, y, count);
 paint_menu_name_game (x, y, name_game);
 paint_menu_text (x, y, PLAY, HELP, EXIT);
 count_menu = move_menu (x, y, count);


 /*settextstyle (10, 0, 4);
 char *s;
 sprintf (s, "%d", 1);
 outtextxy (x + 550, y + 30, s);
     //outtext score*/

 

 getch();
 closegraph();
 return 0;
}

//////////////////////////////////////////////////////////////////////////////////
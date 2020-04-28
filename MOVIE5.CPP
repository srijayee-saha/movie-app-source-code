
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>


//************FILE INSTANCES************//
	 FILE *f1,*f2;
	 FILE *f3,*f4,*f5;
//**************************************//




      //----------------------------------------------//
	 //MAIN FUNCTION PROTOTYPE......
	 void adminis();
	 void user();
      //----------------------------------------------//


     struct admini
		  {
		     char name[60];
		     char category[50];
		     int print;
		   };
     struct users
		  {
		    char umoviename[50];
		    char username[50];
		    char useradd[50];
		    char tele[50];
		    char id[40];
		    char pass[20];
		  };


 //---------------------------------//
  //CHARACTER DECLARATIONS.....
   char moviename[100];
   char id1[50];
   char pass1[50];
   char moviename1[100];
   char umovie[100];
   char username1[100];
   char useradd1[100];
   char name1[60];
   char uname[60];
   char choice1;
 //---------------------------------//

		 //general function prototypes.....
		    void create();
		    void append();
		    void edit();
		    void del();
		    void display();
		    void avail();
		    void submitt();
		    void newuser();
		    void existuser();

		    void userdisplay();
		    void removeusers();

	     //-------------------------------------------//


		 //integer declaration....
		 int n;
		 int f;
		 int p;
		 int print;
		 int nx;
		 int i;
		 int choice;
	      //----------------------------//

void help(void)
{
	clrscr();
	setbkcolor(6);
	settextstyle(4, HORIZ_DIR, 5);
	outtextxy(20, 20, "Welcome to Video Library System");
	settextstyle(2, HORIZ_DIR, 6);
	outtextxy(60, 100, "This project  can keep record of CD transaction");
	outtextxy(60, 150, "This program is capable of holding any no. of customer");
	outtextxy(60, 200, "-In first option you can select Adminstrative");
	outtextxy(60, 250, "-In second option you can select User");
	outtextxy(60, 300, "-And last option is Quit (Exit to Window)");
	settextstyle(7, HORIZ_DIR, 4);
	outtextxy(80, 420, "Press any key to continue...");
	getch();

}

//--------------------------------------------------------------//
 void main()
 {

  /* Requesting autodetect of the graphics drivers */
  int gdriver = DETECT, gmode, errorcode;

  /* Set your graphics mode where the graphic files are present */
  initgraph(&gdriver, &gmode, "e:\\tc\\bgi");

  help();
  cleardevice();
  int ch;
  setbkcolor(5);
  //settextstyle(4, VERT_DIR, 5);
  while(ch!=3)
  {
   clrscr();
   printf ("\n\tMAIN MENU...");
   printf ("\n\t1.ADMINISTRATOR...");
   printf ("\n\t2.USER...");
   printf ("\n\t3.EXIT...");
   printf ("\n\n\tPlease choose 1 ,2 OR 3.");
   printf ("\n\tYour choice?");
   scanf("%d",&ch);
   switch(ch)
    {
      case 1:adminis();
	     break;
      case 2:user();
	     break;

    }
  }
  printf("\n\n\tTHANX FOR VISITING MY PROGRAM");
  printf("\n\tPLEASE PRESS ANY KEY....");

 getch();
}//end of main()......

//------------------------------------------------------------------//



		      //USER FUNCTION//

void user()
{
 int uchi;

 while(uchi!=4)
 {
  clrscr();
  printf ("\n**USER MENU**");
  printf ("\n**1.FOR NEW USER**");
  printf ("\n**2.FOR EXISTING USER**");
  printf ("\n**3.FOR DISPLAY USERS**");
  printf ("\n**4.TO EXIT**");


  printf ("\n\nPlease enter your choice (1/2/3) ");
  scanf ("%d",&uchi);
  switch(uchi)
   {
    case 1: newuser();
	    break;
    case 2: existuser();
	    break;
    case 3:userdisplay();
	   break;
   }//end of switch case::
 }//end of while....
 clrscr();
 printf ("\n\n\tPLEASE VISIT AGAIN ....THANK YOU");
 printf ("\n\n\tPRESS ANY KEY....");
 getch();
}//end of user()....


//ooooooooooooUDISPLAY FUNCTIONooooooooooooooooooo//
void userdisplay()
{
   users d;
   f3=fopen("user1.dat","rb");
   clrscr();
   printf("USER \tADD\t    TELEPHONE\tID");
    while(fread(&d,sizeof(d),1,f3)==1)
       {
       printf("\n%s\t%s\t%s\t%s",d.username,d.useradd,d.tele,d.id);
       }

      fclose(f3);
      getch();

} //end of udisplay()......


void newuser()
{
  users d;
  f3=fopen("user1.dat","wb+");

  fflush(stdin);
  printf("\nENTER THE NAME OF THE USER ?");
  gets(d.username);
  printf("\nENTER THE ADD OF THE USER?");
  gets(d.useradd);
  printf("\nENTER THE TELEPHONE NUMBER OF THE USER?");
  gets(d.tele);
  printf("\nENTER THE ID OF THE USER?");
  gets(d.id);
  printf("\nENTER THE USER PASS WORD ?");
  gets(d.pass);
  strcpy(d.umoviename,"nill");
  fwrite(&d,sizeof(d),1,f3);
  fclose(f3);
}
void existuser()
{
   users d;
   int ch;
  f3=fopen("user1.dat","rb");
  fflush(stdin);

  printf("\nENTER THE USER ID?");
  gets(id1);
  printf("\nENTER THE PASSWORD?");
  gets(pass1);

  int flag=0;
  while(fread(&d,sizeof(d),1,f3)==1)
  {
  if(strcmp(d.id,id1)==0 &&strcmp(d.pass,pass1)==0)
     {
     flag++;
     }
  }

  if(flag!=0)
  {
   while(ch!=4)
   {
     printf("\n**USER MENU**");
     printf("\n**1.TO CHECK");
     printf("\n**2.TO SUBMITT");
     printf("\n**3.TO DISPLAY");
     printf("\n**4.TO EXIT");

     printf("\n\nENTER YOUR CHOICE(1/2/3)?");
     scanf("%d",&ch);
     switch(ch)
      {case 1: avail();
	       break;
       case 2: submitt();
	       break;
       case 3: display();
	       break;
      }//end of switch();
   }//end of while....
  }//end of if....
  else
   printf("\nYOU ARE NOT A VALID USER");
   getch();

}//end of existuser()....


void adminis()
{ int chi;
   while(chi!=6)
    {clrscr();

      printf ("\n\tADMINISTRATOR MENU");
      printf ("\n\t1.  TO CREATE A NEW STOCK FILE");
      printf ("\n\t2.  TO APPEND A TITLE IN THE STOCK");
      printf ("\n\t3.  TO EDIT A TITLE IN THE STOCK");
      printf ("\n\t4.  TO DELETE A TITLE FROM THE STOCK");
      printf ("\n\t5.  TO DISPLAY THE TITLES IN THE STOCK");
      printf ("\n\t6.  TO EXIT THE PROGRAM");
      printf ("\n\t Enter your choice (1/2/3/4/5/6):: ");
      scanf ("%d",&chi);

       switch(chi)
       { case 1:printf("\n\n\tWARNING :IF YOU HAVE AN EXISTING STOCK IT MIGHT BE LOST");
		printf("\n\n\tTo continue any how PRESS 1 else PRESS 0....?");
		scanf("%d",&p);
		if (p==1)
		{
		create();
		break;
		}
		break;
	 case 2:append();
		break;
	 case 3:display();
		edit();
		break;
	 case 4:display();
		del();
		break;
	 case 5:display();
		getch();
		break;
       }//end of switch case......

    }//end of while......
    clrscr();
    printf ("\n\n\tPLEASE VISIT AGAIN ....THANK YOU");
    printf ("\n\n\tPRESS ANY KEY....");

   getch();
}//end of adminis().....
    //**************ADMINISTRATOR***************//





//+++++++++++++++++++++++CREATE FUNCTION++++++++++++++++++++++++++++//
void create()
{  admini g;

   f1=fopen("movi.dat","wb");
   clrscr();
   printf("\n\nEnter the number of records you want to enter?");
   scanf("%d",&n);
   for(i=0;i<n;i++)
    {
      fflush(stdin);
      printf("\nEnter the name of the movie?");
      gets(g.name);
      printf("\nEnter the category of the movie(eng/hin/beng)?");
      gets(g.category);
      printf("\nEnter the number of prints of the movie?");
      scanf("%d",&g.print);
      fwrite(&g,sizeof(g),1,f1);

    }

   fclose(f1);
}//end of create().....

//+++++++++++++++++++++++APPEND FUNCTION++++++++++++++++++++++++++++++++++++++++++++++++++//
void append()
{ admini g;

   f1=fopen("movi.dat","ab");
   clrscr();
   printf("\nEnter the number of data items you want to add into the existing file ?");
   scanf("%d",&nx);
   for(i=0;i<nx;i++)
   {fflush(stdin);
    printf("\nEnter the name of the movie?");
    gets(g.name);
    printf("\nEnter the category of the movie(eng/hin/beng)?");
    gets(g.category);
    printf("\nEnter the number of prints of the movie?");
    scanf("%d",&g.print);
    fwrite(&g,sizeof(g),1,f1);
   }//end of for loop.....

  fclose(f1);

}//end of append().....
//++++++++++++++++++++++END APPEND++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



//++++++++++++++++++++++EDIT FUNCTION++++++++++++++++++++++++++++++++++++++++++++//
void edit()
 {
 admini g;
   f1=fopen("movi.dat","rb");
   f2=fopen("tempo.dat","wb");
   fflush(stdin);

   printf ("\nEnter the movie name you want to edit?");
   gets(moviename);
    int flag=0;

   while(fread(&g,sizeof(g),1,f1)==1)
    { if(strcmp(g.name,moviename)==0)
	  { flag++;
	    printf ("\nEDIT MENU");
	    printf ("\n1.TO EDIT NAME");
	    printf ("\n2.TO EDIT CATEGORY");
	    printf ("\n3.TO EDIT PRINT");
	    printf ("\n4.TO EDIT ALL");
	    printf ("\n5.TO EXIT WITHOUT EDITING");
	    printf ("\n\nYour choice (1/2/3/4/5)?");
	    scanf("%d",&choice);
	   switch(choice)
	   { case 1:fflush(stdin);
		    printf("\nEnter new name?");
		    gets(g.name);
		     break;
	    case 2:fflush(stdin);
		   printf ("\nEnter it's category?");
		   gets(g.category);
		    break;
	    case 3:fflush(stdin);
		    printf ("\nEnter new number of prints available?");
		    scanf("%d",&g.print);
		    break;
	    case 4: fflush(stdin);
		    printf ("\nEnter new name ?");
		    gets(g.name);
		    printf ("\nEnter new category?");
		    gets(g.category);
		    printf("\nEnter new number of prints available?");
		    scanf("%d",&g.print);
	    case 5: break;
	    default :printf("\nPlease enter a valid choice....");
	   }//end of switch:case ::

	  }

	 fwrite(&g,sizeof(g),1,f2);
    } //end of while.....
    if(flag==0)
     { printf("\n\n\tTHE MOVIE YOU ARE SEACRHING IS NOT FOUND");
	getch();
     }

   fclose(f1);
   fclose(f2);
   remove("movi.dat");
   rename("tempo.dat","movi.dat");
 } //end of edit().....
//++++++++++++++++++++++END EDIT+++++++++++++++++++++++++++++++++++++++++++++++++//







//++++++++++++++++++++++DELETE FUNCTION+++++++++++++++++++++++++++++++++//
 void del()
  {
   admini g;
   f1=fopen("movi.dat","rb");
   f2=fopen("tempo.dat","wb");
   fflush(stdin);
   printf ("\nEnter the movie name you want to delete?");
   gets(moviename1);
  int  flag1=0;
   while(fread(&g,sizeof(g),1,f1)==1)
    { if(strcmp(g.name,moviename1)!=0)
	  {flag1++;
	   fwrite(&g,sizeof(g),1,f2);
	  }//end of if......
    }//end of while......
    if (flag1==0)
     { printf("\n\n\tTHE MOVIE YOU ARE SEACRHING IS NOT FOUND");
       getch();
     }

    fclose(f1);
    fclose(f2);
    remove("movi.dat");
    rename("tempo.dat","movi.dat");
  }//end of del()......
//++++++++++++++++++++++END DELETE++++++++++++++++++++++++++++++++++++++//



//++++++++++++++++++++++DISPLAY FUNCTION++++++++++++++++++++++++++++//
  void display()
   { admini g;

     f1=fopen("movi.dat","rb");
     clrscr();
     printf("Name\tCategory\tPrint");


     while(fread(&g,sizeof(g),1,f1)==1)
       { printf("\n%s\t\t%s\t%d",g.name,g.category,g.print);

       }
      fclose(f1);


  }//end of display().........
			 //*******USER********//

void avail()
 {
 int uchi1;
   admini g;
   clrscr();
   f1=fopen("movi.dat","rb");
   f2=fopen("tempo.dat","wb");
   fflush(stdin);
   printf ("\n\n\tEnter the name of the movie you want to take home?");
   gets(umovie);
   while (fread(&g,sizeof(g),1,f1)==1)
    { if(strcmp(g.name,umovie)==0)
	   if(g.print==0)
	    {
	    printf("\n\n\tSORRY WE DONOT HAVE THE MOVIE IN OUR STOCK");
	    printf("\n\n\tPLEASE TRY AFTER SOME DAYS");
	    }
	   else
	   {
	    printf ("\n\n\tNUMBER OF PRINTS AVAILABLE ==%d",g.print);
	    printf ("\n\tDO YOU CHOOSE TO TAKE THE MOVIE:-");
	    printf ("\n\tPRESS 1 IF 'YES' ;0 IF 'NO' ?");
	    scanf("%d",&uchi1);
	    switch(uchi1)
	     {
	      case 0:break;
	      case 1:g.print--;
		     break;
	      default:printf("\n\tPlease enter a valid choice....");
		      break;
	     }
	   } //end of else...

	   //end of if...

	fwrite(&g,sizeof(g),1,f2);
    }//end of while....
    printf("\n\n\tPLEASE VISIT AGAIN....TILL THEN BYE");
    printf("\n\tPRESS ANY KEY....");
    getch();

   fclose(f1);
   fclose(f2);
   remove("movi.dat");
   rename("tempo.dat","movi.dat");
}//end of avail()....










void submitt()
{
   int x;
   admini g;
   users d;
   clrscr();
   f1=fopen("movi.dat","r");
   f2=fopen("tempo.dat","w");
   f3=fopen("user.dat","r");
   printf ("\n\n\tEnter the name of the user?");
   scanf ("%s",uname);
   int flag2=0;
while(feof(f3)==0)
{
    fscanf(f3,"\n%s\t%s\t     %s",d.umoviename,d.username,d.useradd);
    if(strcmp(d.username,uname)==0)
    flag2++;
 }
   fclose(f3);

 if(flag2>0)
 { printf ("\n\n\tEnter the name of the movie you want to return?");
   scanf("%s",umovie);
   while (feof(f1)==0)
    {
       fscanf(f1,"\n%s\t%s\t        %d",g.name,g.category,&g.print);
       if(strcmp(g.name,umovie)==0)
	{ printf("\n\t\t***SUBMITT MOVIE***");
	  printf("\n\tPRESS 1 TO SUBMITT or 0 TO EXIT?");
	  scanf("%d",&x);
	  switch(x)
	  { case 0: break;
	    case 1: g.print++;
		    break;
	    default:printf("\n\tPlease enter a valid choice...");
	  }//end of switch case::
	}  //end of if loop....

       fprintf(f2,"\n%s\t%s\t          %d",g.name,g.category,g.print);
     } //end of while....

    printf("\n\n\tPLEASE VISIT AGAIN....TILL THEN BYE");
    printf("\n\tPRESS ANY KEY....");
    getch();

   fclose(f1);
   fclose(f2);
   remove("movi.dat");
   rename("tempo.dat","movi.dat");
   }
  }
   /*f3=fopen("user.dat","rb");
   f4=fopen("tempo1.dat","wb");
   while(feof(f3)==0)
   {
    fscanf(f3,"\n%s\t%s\t     %s",name,username,useradd);
    if(strcmp(username,uname)!=0)
    fprintf(f4,"\n%s\t%s\t     %s",name,username,useradd);
   }
   strcpy(name,"");
   strcpy(username,"");
   strcpy(useradd,"");;
   fclose(f3);
   fclose(f4);
   remove("user.dat");
   rename("tempo1.dat","user.dat");
   }
   else
       {
       printf("\n\n\tTHE USER NOT VALID");
       getch();
	}


}//end of submitt()....
//oooooooooooooooooooooooooEND AVAILooooooooooooooooooooooooooooooooooooooo//*/
//void submitt()
//{
//}

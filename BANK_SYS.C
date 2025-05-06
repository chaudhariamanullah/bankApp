#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void ac_crt ();
void login();
void ac_mng( int );
int transfer();
int deposit();
void logout();
int withdraw();
int chkBal();
int statement();
void statement_creation(int,int);
void printfMoreDot( int );

int access = 0;
char User_Name[20]={'\0'};
char receiver[20]={'\0'};

struct UserInfo
{
	char Fname[20];
	char Mname[20];
	char Lname[20];
	char gender;
	char dob[25];
	char num[20];
	char email[30];
	char aadhaar[20];
	char password[25];
	char account[20];


} u ;

int main()
{
   int ch;
   clrscr();



   while ( ch != 3)
   {    clrscr();
	printf("\n                     WELCOME TO INDIA BANK ");
	printf("\n*-------------------------------------------------------------*");
	printf("\n                      1.Create Account  ");
	printf("\n                      2.Login           ");
	printf("\n                      3.Exit            ");
	printf("\n*-------------------------------------------------------------*");
	printf("\nEnter Your Choice : ");
	scanf("%d",&ch);

	switch( ch )
	{
		case 1:
			ac_crt();
			break;

		case 2:
			login();
			break;

		case 3:
			exit(1);

		default :
			 printf("\nWrong Choice ");
	 }



   }






    getch();
    return 0;

}

void ac_crt ()
{
     FILE *write;
     const char *state="statemen.txt";
     const char *money="cash.txt";
     char sav[]="Savings", cur[]="Current";
     char male='M' , female='F';
     int ch,con;


	clrscr();
	printf("\n____________________________________");
	printf("\nEnter Your First Name : ");
	scanf("%s",u.Fname);
	printf("\n____________________________________");
	printf("\nEnter Your Middle Name : ");
	scanf(" %s",u.Mname);
	printf("\n____________________________________");
	printf("\nEnter Your Last Name : ");
	scanf(" %s",u.Lname);

	acc:
		printf("\nChh\ose Your Account Type");
		printf("\n____________________________________");
		printf("\n[   1.Saving 2.Current   ]");
		printf("\n____________________________________");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
			       strcpy(u.account,sav);
			       break;
			case 2:
			       strcpy(u.account,cur);
			       break;
			default:
				printf("\nWrong Choice");
				goto acc;
		}


	gen:
	printf("\n____________________________________");
	printf("\n*Note* Only First Character M or F ");
	printf("\n____________________________________");
	printf("\nEnter Your Gender : ");
	scanf(" %c",&u.gender);
	if ( u.gender != male && u.gender != female )
	{
		printf("\nWrong Gender Character");
		printf("\n-----------------------");
		goto gen;
	}
	printf("\n");
	printf("\n____________________________________");
	printf("\nExample - 31/10/2000 or 31-12-1999");
	printf("\n____________________________________");
	printf("\nEnter Your Date of Birth : ");
	scanf(" %s",u.dob);
	printf("\n____________________________________");
	printf("\nEnter Your Aadhaar Number : ");
	scanf(" %s",u.aadhaar);
	printf("\n____________________________________");
	printf("\nEnter Your Email Id : ");
	scanf(" %s",u.email);
	printf("\n____________________________________");
	printf("\nEnter Your Phone Number : ");
	scanf(" %s",u.num);
	printf("\n____________________________________");
	printf("\nEnter Your Password : ");
	scanf(" %s",u.password);
	printf("\n____________________________________");
	printf("\nPress 1 To Confirm Registration: ");
	scanf("%d",&con);

	if ( con == 1)
	{
	   write = fopen("UserInfo.txt","w");
	   fprintf(write,"%s %s %s %s %c %s %s %s %s %s",u.Fname,u.Mname,u.Lname,u.account,u.gender,u.dob,u.aadhaar,u.email,u.num,u.password);
	   fclose(write);
	   remove(state);
	   remove(money);
	   printf("\n           *-------------------Registration Completed----------------*\n");
	}

	else
	{
	   printf("\n              *--------------Registraion Failed---------------*");
	}

	getch();



}

void login()
{
  FILE *read;
  char name[30], pswrd[20];
  char Fname[30], password[20];
  int  login=0;

  clrscr();

  read = fopen("UserInfo.txt","r");

  printf("\n                   LOGIN                    ");
  printf("\n    *--------------------------------------*");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n    -------------------------------");
  printf("\n    Enter Your Name : ");
  scanf("%s",name);
  fscanf(read,"%s",Fname);

  if ( strcmp(Fname,name) == 0 )
  {
	printf("\n");
	printf("\n    ---------------------------------------------");
	printf("\n    Enter Your Password : ");
	scanf(" %s",pswrd);
	fscanf(read,"%*s %*s %*s %*s %*c %*s %*s %*s %*s %s",password);

	if( strcmp(password,pswrd) == 0 )
	{
		login++;
		printf("\n");
		printf("\n             **************LOGIN SUCCESS****************");
		getch();
	}
	else
	{
		printf("\nWrong Password");
		getch();
	}


  }
  else
  {
	printf("\nUser Not Found");
	getch();
  }
     fclose(read);
     if ( login == 1)
     {

	  access++;
	  ac_mng(access);
     }

}

void ac_mng()
{
  FILE *read;
  char name[25];
  int ch;

	read = fopen("UserInfo.txt","r");
	fscanf(read,"%s",User_Name);
	fclose(read);

	while ( ch != 7)
	{       clrscr();
		printf("\n                          WELCOME  %s ",User_Name);
		printf("\n                    *---------------------*");
		printf("\n");

		printf("\n                       *----------------*");
		printf("\n                        1.Check Balance ");
		printf("\n                        2.Transfer Money");
		printf("\n                        3.Withdraw      ");
		printf("\n                        4.Deposit       ");
		printf("\n                        5.Log Out       ");
		printf("\n                        6.Check Statment");
		printf("\n                        7.Exit          ");
		printf("\n                       *----------------*");
		printf("\n");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch( ch )
		{
			case 1:
			       chkBal();
			       break;

			case 2:
			       transfer();
			       break;

			case 3:
			       withdraw();
			       break;

			case 4:
			       deposit();
			       break;

			case 5:
			       logout();
			       break;

			case 6:
			       statement();
			       break;

			case 7:
			       exit(1);

			default : printf("\nWrong Choice");
		}

	}


}

int transfer ()
{
   FILE *read, *write;
   char creditor[20];
   int amt,bal,rem,i;
   int num = 2;
   clrscr();
   printf("\n*---------------------*");
   printf("\n");
   printf("\n__________________________________");
   printf("\nEnter Receiver Name: ");
   scanf("%s",creditor);
   printf("\n__________________________________");
   printf("\nEnter Amount : ");
   scanf("%d",&amt);

   strcpy(receiver,creditor);

   read = fopen("cash.txt","r");

   if ( read == NULL )
   {
	for(i = 1; i<=7; i++)
	printf("\n");
	printf("\n                         _____________________");
	printf("\n                         Insufficient Balance");
	printf("\n                         *-------------------*");
	getch();
	return 1;

   }


   fscanf(read,"%*s %d",&bal);
   fclose(read);

   write = fopen("cash.txt","w");
   fseek(write,0,SEEK_SET);

   if ( amt <= bal )
   {
	printf("\n");
	printf("\n                -------------------------------------------");
	printf("\n                 %d Rupess Have Been Transfered To %s",amt,creditor);
	printf("\n                --------------------------------------------");
	rem = bal - amt;
	fprintf(write,"%s",User_Name);
	fprintf(write," %d",rem);
	statement_creation(amt,num);
	getch();
   }

   else
   {    printf("\n               ---------------------------------------------");
	printf("\n                      You Dont Have Sufficient Balance");
	printf("\n               ---------------------------------------------");
	getch();
   }

    fclose(write);
    return 0;
}

int deposit ()
{
  FILE *read , *write;
  int add,amt,total;
  int num=1;
  clrscr();
  printf("\n\n\n\n");
  printf("\n          _______________________________________");
  printf("\n          Enter Your Amount For Deposit: ");
  scanf("%d",&add);

  read = fopen("cash.txt","r");

  if ( read == NULL )
  {
     write = fopen ("cash.txt","w");
     fprintf(write,"%s %d",User_Name,add);
     fclose(write);
     statement_creation(add,num);
     printf("\n\n\n");
     printf("\n         *------------------------------------------*");
     printf("\n            %d Has Been Deposited SuccessFully",add);
     printf("\n         *------------------------------------------*");
     getch();
     return 1;
  }

  fscanf(read,"%*s %d",&amt);
  fclose(read);
  total = amt + add;

  fseek(write,0,SEEK_SET);
  write = fopen("cash.txt","w");
  fprintf(write,"%s %d",User_Name,total);
  fclose(write);
  statement_creation(add,num);
  printf("\n\n\n");
  printf("\n       *----------------------------------------------*");
  printf("\n          %d Has Been Deposited SuccessFully",add);
  printf("\n       *----------------------------------------------*");
  getch();
  return 0;
}

int withdraw()
{
  FILE *read, *write;
  int bal,taken,rem;
  int num=0;


  read = fopen ("cash.txt","r");

  if ( read == NULL )
  {
	printf("\n\n\n");
	printf("\n         Insufficient Balance");
	printf("\n         *-------------------*");
	getch();
	return 1;
  }

  fscanf(read,"%*s %d",&bal);
  fclose(read);
  clrscr();
  printf("\n--------------------------");
  printf("\n   Your Balance : %d",bal);
  printf("\n\n\n");
  printf("\n          *-----------------------------------------------*");
  printf("\n           Enter The Amount You Want To Withdraw: ");
  scanf("%d",&taken);

  if ( bal == 0 )
  {
	printf("\n\n\n");
	printf("\n            No Cash Available in Your Account.");
	printf("\n            *--------------------------------*");
	getch();
  }

  else if ( bal < taken )
  {
	printf("\n\n\n");
	printf("\n                  Low Cash");
	printf("\n               *----------------*");
	getch();
  }

  else
  {
       printf("\n\n\n");
       printf("\n                ____________________________________");
       printf("\n                  %d Has Been Withdrawn",taken);
       printf("\n                *-----------------------------------*");
       rem = bal - taken;
       write = fopen("cash.txt","w");
       fseek(write,0,SEEK_SET);
       fprintf(write,"%s  %d",User_Name,rem,num);
       statement_creation(taken,num);
       fclose(write);
       getch();
  }
   return 0;
}


void logout()
{
	access--;
	printf("\n\n\n\n\n");
	printf("\n               **********---------------***********");
	printf("\n                    You Have Been Logged Out");
	printf("\n               **********---------------***********");
	getch();
	main();
}


int chkBal()
{
  FILE *read;
  int amt;

  read = fopen("cash.txt","r");

  if ( read == NULL)
  {
	printf("\n\n\n");
	printf("\n            -----------------------------");
	printf("\n             Your Balance is 0.00 Rupees ");
	printf("\n            -----------------------------");
	getch();
	return 1;
  }

  fscanf(read,"%*s %d",&amt);
  fclose(read);
  printf("\n\n\n");
  printf("\n                *---------------------------------*");
  printf("\n                   Your Balance is %d Rupees",amt);
  printf("\n                *---------------------------------*");
  getch();
  return 0;

}

int statement()
{
   FILE *read;
   char name[25], day[5], mon[5],time[30],cha;
   int srn=1,amt,dot_cnt=0,date,hour,min,sec,year,ch,cnt;

   clrscr();

   read = fopen("statement.txt","r");
   if (read == NULL)
   {
	printf("\nNo Transaction Found");
	getch();
	return 1;
   }

   while ( cha != EOF)
   {
	cha = getc(read);
	if ( cha == '.' )
	dot_cnt++;
   }
   if ( fseek(read,0,SEEK_SET ) != 0 )

   fclose(read);

   if ( dot_cnt <= 10 )
   {

	while ( ch != 4)
	{
		clrscr();

		printf("\n--------------------------------------------------");
		printf("\nThis Only shows Recent 10 Transactions ");
		printf("\n--------------------------------------------------");
		printf("\nRecent Transaction Are In Reverse Order");
		printf("\n--------------------------------------------------");
		printf("\n1. 1st PAGE 2. 2nd PAGE 3. 3rd PAGE 4. BACK");
		printf("\n--------------------------------------------------");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);

		switch ( ch )
		{
		   case 1:
			  clrscr();
			  printf("PG 1/3");
					cnt = dot_cnt;
					srn = 1;
					read = fopen("statement.txt","r");
					fseek(read,0,SEEK_SET);
					while ( cnt > 0)
					{
						fscanf(read,"%*c %s %d %s %s %d %s %d\n",name,&amt,day,mon,&date,time,&year);
						if ( srn < 5 )
						{
						printf("\n *------------------------------*");
						printf("\n    SRNO: %d",srn);
						printf("\n    Account:%s",name);
						printf("\n    Amount: %d ",amt);
						printf("\n    Time: %s %s %d %s %d",day,mon,date,time,year);
						}
						cnt--;
						srn++;
					}

				fclose(read);
				getch();
				break;

		   case 2:
			  clrscr();
			  printf("PG 2/3");
					cnt = dot_cnt;
					srn = 1;
					read = fopen("statement.txt","r");
					fseek(read,0,SEEK_SET);
					while ( cnt > 0)
					{
						fscanf(read,"%*c %s %d %s %s %d %s %d\n",name,&amt,day,mon,&date,time,&year);
						if (  srn >= 5 && srn <= 8 )
						{
						printf("\n *------------------------------*");
						printf("\n    SRNO: %d",srn);
						printf("\n    Account:%s",name);
						printf("\n    Amount: %d ",amt);
						printf("\n    Time: %s %s %d %s %d",day,mon,date,time,year);
						}
						cnt--;
						srn++;

					}
			      fclose(read);
			      getch();
			      break;
		   case 3:
			  clrscr();
			  printf("PG 3/3");
					cnt = dot_cnt;
					srn = 1;
					read = fopen("statement.txt","r");
					while   ( cnt > 0)
					{
						fscanf(read,"%*c %s %d %s %s %d %s %d\n",name,&amt,day,mon,&date,time,&year);
						if (  srn <=10 && srn >=9 )
						{

						printf("\n *------------------------------*");
						printf("\n    SRNO: %d",srn);
						printf("\n    Account:%s",name);
						printf("\n    Amount: %d ",amt);
						printf("\n    Time: %s %s %d %s %d",day,mon,date,time,year);
						}
						cnt--;
						srn++;

					}
				fclose(read);
					       printf("\n");
					       printf("\n  ********************************");
					       printf("\n               END                ");
				getch();
				break;

		   case 4:
			   ac_mng(access);
			   break;

		   default: printf("\nWrong Choice");


		}

	 }

  }

  else
  {
	printfMoreDot( dot_cnt);
  }
   getch();
   return 0;
}

void statement_creation(int amt,int num)
{
  FILE *write;
  time_t current_time;
  char with[]="Withdraw", dep[]="Deposit", dot='.';

  time(&current_time);

  write = fopen("statement.txt","a");
  if (num == 1 )
  fprintf(write,"%c %s %d %s",dot,dep,amt,ctime(&current_time) );
  else if ( num == 2)
  fprintf(write,"%c %s %d %s",dot,receiver,amt,ctime(&current_time) );
  else if ( num == 0)
  fprintf(write,"%c %s %d %s",dot,with,amt,ctime(&current_time) );
  fclose(write);
}

void printfMoreDot( int dot_cnt)
{

   FILE *read;

   char name[25], day[5], mon[5],time[30];
   int srn=1,amt,date,hour,min,sec,year;
   int cnt,ch,rec_cnt=0,n_srn=1;

   cnt = dot_cnt;

   while ( cnt > 10 )
   {
	cnt--;
	rec_cnt++;
   }

	while ( ch != 4)
	{
		clrscr();
		printf("\n--------------------------------------------------");
		printf("\nThis Only shows Recent 10 Transactions ");
		printf("\n--------------------------------------------------");
		printf("\nNewer Transactions Will Be Found On Later Pages");
		printf("\n---------------------------------------------------");
		printf("\n1. 1st PAGE 2. 2nd PAGE 3. 3rd PAGE 4. BACK");
		printf("\n---------------------------------------------------");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);

		switch ( ch )
		{
		   case 1:
			  clrscr();
			  printf("PG 1/3");
					cnt = dot_cnt;
					n_srn = 1;
					srn = 1;
					read = fopen("statement.txt","r");
					fseek(read,0,SEEK_SET);
					while ( cnt > 0)
					{
						fscanf(read,"%*c %s %d %s %s %d %s %d\n",name,&amt,day,mon,&date,time,&year);
						if ( srn < 5+rec_cnt && srn > rec_cnt )
						{
						printf("\n *------------------------------*");
						printf("\n    SRNO: %d",n_srn);
						printf("\n    Account:%s",name);
						printf("\n    Amount: %d ",amt);
						printf("\n    Time: %s %s %d %s %d",day,mon,date,time,year);
						n_srn++;
						}
						cnt--;
						srn++;
					}

				fclose(read);
				getch();
				break;

		   case 2:
			  clrscr();
			  printf("PG 2/3");
					cnt = dot_cnt;
					n_srn = 1;
					srn = 1;
					read = fopen("statement.txt","r");
					fseek(read,0,SEEK_SET);
					while ( cnt > 0)
					{
						fscanf(read,"%*c %s %d %s %s %d %s %d\n",name,&amt,day,mon,&date,time,&year);
						if (  srn >= 5+rec_cnt && srn <= 8+rec_cnt && srn > rec_cnt )
						{
						n_srn = srn;
						n_srn -= rec_cnt;
						printf("\n *------------------------------*");
						printf("\n    SRNO: %d",n_srn);
						printf("\n    Account:%s",name);
						printf("\n    Amount: %d ",amt);
						printf("\n    Time: %s %s %d %s %d",day,mon,date,time,year);
						n_srn++;
						}
						cnt--;
						srn++;

					}
			      fclose(read);
			      getch();
			      break;
		   case 3:
			  clrscr();
			  printf("PG 3/3");
					cnt = dot_cnt;
					n_srn = 1;
					srn = 1;
					read = fopen("statement.txt","r");
					while   ( cnt > 0)
					{
						fscanf(read,"%*c %s %d %s %s %d %s %d\n",name,&amt,day,mon,&date,time,&year);
						if (  srn >=9+rec_cnt && srn <=10+rec_cnt && srn > rec_cnt )
						{
						n_srn = srn;
						n_srn -= rec_cnt;
						printf("\n *------------------------------*");
						printf("\n    SRNO: %d",n_srn);
						printf("\n    Account:%s",name);
						printf("\n    Amount: %d ",amt);
						printf("\n    Time: %s %s %d %s %d",day,mon,date,time,year);
						n_srn++;
						}
						cnt--;
						srn++;

					}
				fclose(read);
					       printf("\n");
					       printf("\n  ********************************");
					       printf("\n               END                ");
				getch();
				break;

		   case 4:
			   ac_mng(access);
			   break;

		   default: printf("\nWrong Choice");


		}

	 }


}
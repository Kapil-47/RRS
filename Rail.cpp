#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
void viewinfo(void);
void bookticket(void);
void cancelticket(void);
void password(void);
void admin(void);
void viewpassenger(void);
void addtrain(void);
void dlttrain(void);
void awrite(void);
void aread(void);
void bookticket_write(void);
void viewpassengers_read(void);

struct adddata
{
	char si[10];
	char train_number[10];
	char train_name[20];
	char start[10];
	char destination[10];
	char price[10];
	int seat;
	char time[10];
} add[1000];

struct bookticket
{
	char train_number[20];
	char name[20];
	char phone[20];
	char date[20];
	int seat;
} book[1000];
//---------------------------------------Global variable---------------------------------------------------
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];
//-------------------------------------------------starting amin------------------------------------------
int main()
{   
    char choice;
    time_t ct;
    time(&ct);
    printf("***************************************************************************");
    printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
    printf("***************************************************************************\n");
    printf("\nWELCOME USER :)\t\t\t\t\t%s",ctime(&ct));	
	printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    printf("|                                                                         |\n");
    printf("|\t\t\t\t  MENU\t\t\t\t\t  |\n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|\t\t[1] VIEW INFORMATION\t\t\t\t\t  |\n");
    printf("|\t\t[2] BOOK TICKET\t\t\t\t\t\t  |\n");
    printf("|\t\t[3] CANCEL TICKET\t\t\t\t\t  |\n");
    printf("|\t\t[4] ADMIN\t\t\t\t\t\t  |\n");
    printf("|\t\t[5] EXIT\t\t\t\t\t\t  |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n");
    printf("\n\t\t\tENTER YOUR CHOICE:");
    scanf("%s",&choice);
    switch (choice)
    {
    case '1':viewinfo();
			break;
	case '2':bookticket();
			break;
	case '3':cancelticket();
			break;
    case '4':password();
      break;
    case '5':system("cls");
          printf("***************************************************************************");
          printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
          printf("***************************************************************************\n");
          printf("\n\nYOU ARE SUCCUSSFULLY EXIT.....\n");
          printf("\nHAVE A NICE DAY :)\n");
          getch();
          exit(0);
    break;
    default:system("cls");
            printf("***************************************************************************");
            printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
            printf("***************************************************************************\n");
            printf("\n\n\tOops!....YOU ENTERED WRONG KEYWORD :(\n");
            printf("\n\tPRESS ANY KEY TO GO BACK MAIN WINDOW................\n");
            getch();
            system("cls");
            main();
    }
    return 0;
}
//-----------------------------------------------------------end of main---------------------------------------------------
//-----------------------------------------------------------book ticket function---------------------------------------------
void bookticket()
{
	int c,j,n,i,found=-1;
	char v,train_number[10];
	system ("cls");
	aread();
	printf("***************************************************************************");
    printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
    printf("***************************************************************************\n");
	printf("\n\n\t\t\tHow many ticket do you want to buy: ");
	scanf("%d",&n);
	for(j=u;j<u+n;j++)
	{
	printf("\n\n\t\t\tEnter train number: ");
	scanf("%s", book[j].train_number);
	for(i=0;i<k;i++)
	{
	if(strcmp(book[j].train_number,add[i].train_number)==0)
	{
	if(add[i].seat==0)
	{
		printf("\n\n\t\t\tnot available seat");	
		getch();
		system("cls");
		main();
	}
	else
	{
	    found=1;
		printf("\n\t\t\tenter book %d no ticket: ",j+1);
		printf("\n\t\t\tenter date: ");
		scanf("%s",book[j].date);
		printf("\n\t\t\tenter your name: ");
		scanf("%s",book[j].name);
		printf("\n\t\t\tenter your phone number: ");
		scanf("%s",book[j].phone);
		printf("\n\t\t\tseat number : %d",add[i].seat );
		book[j].seat=add[i].seat;
		bookticket_write();
		add[i].seat--;
		awrite();
		}
	}
}
	if(found==-1)
	{
		printf("\n\n\t\t\tTrain not found!!!");
		getch();
		system("cls");
		main();
	}

	}
		u=j;
		bookticket_write();
		printf("\n\n\t\t\t\tEnter '1' for main menu & press any key to exit: ");
		scanf("%d",&c);
			if(c==1)
			{
				system("cls");
				main();
			}
			if(c!=1)
			{
				exit;
			}			
}
//---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{
	viewpassengers_read();
    char pnnmbr[100];
    int location = -1,e;
    printf ("\n\n\t\t\tenter phone number: ");
    scanf ("%s",pnnmbr);
    for (e=0;e<u;e++)
    {
        if (strcmp(pnnmbr,book[e].phone)==0)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main();
    }
    else
    {
        for (e=location;e<u;e++)
        {
            strcpy(book[e].date,book[e+1].date);
            strcpy(book[e].train_number,book[e+1].train_number);
            strcpy(book[e].name,book[e+1].name);
            strcpy(book[e].phone,book[e+1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        printf("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
        getch();
        system("cls");
        main();
    }
}

//--------------------------------------------------------password function-------------------------------------------------
void password()
{
  int pass=123456789;
  int e_pass;
  printf("\n\tENTER THE PASSWORD : ");
  scanf("%d",&e_pass);
  if(e_pass==pass)
  {
    printf("\n\tLOGIN SUCCUSSFULLY...........PRESS ANY KEY TO CONTINUE > > >");
    getch();
    system("cls");
    admin();
  }
  else
  {
    system("cls");
    printf("***************************************************************************");
    printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
    printf("***************************************************************************\n");
    printf("\n\t\t\tWRONG PASSWORD :(\n\n\t\tPRESS ANY KEY TO CONTINUE > > >");
    getch();
    system("cls");
    main();
  }
}
//------------------------------------------------------------admin------------------------------------------
void admin()
{
    char cho;
    printf("***************************************************************************");
    printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
    printf("***************************************************************************\n");
    printf("\nWELCOME ADMIN :)\t\t\t\t\t\t\t\t\n");	
	printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
    printf("\n|                                                                         |\n");
    printf("|\t\t\t   SELECT OPERARION\t\t\t\t  |\n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|\t\t[1] VIEW PASSENGERS\t\t\t\t\t  |\n");
    printf("|\t\t[2] ADD TRAINS\t\t\t\t\t\t  |\n");
    printf("|\t\t[3] DELETE TRAINS\t\t\t\t\t  |\n");
    printf("|\t\t[4] BACK\t\t\t\t\t\t  |\n");
    printf("|\t\t[5] EXIT\t\t\t\t\t\t  |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n");
    printf("\n\t\t\tENTER YOUR CHOICE:");
    scanf("%s",&cho);
    switch (cho)
    {
    case '1': viewpassenger();
			break;
	case '2': addtrain();
			break;
	case '3': dlttrain();
			break;
    case '4':system("cls");
        main();
        break;
    case '5':system("cls");
          printf("***************************************************************************");
          printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
          printf("***************************************************************************\n");
          printf("\n\nYOU ARE SUCCUSSFULLY EXIT.....\n");
          printf("\nHAVE A NICE DAY :)\n");
          getch();
          exit(0);
          break;
    default:system("cls");
            printf("***************************************************************************");
            printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
            printf("***************************************************************************\n");
            printf("\n\n\tOops!....YOU ENTERED WRONG KEYWORD :(\n");
            printf("\n\tPRESS ANY KEY TO GO BACK MAIN WINDOW................\n");
            getch();
            system("cls");
            main();
    }
    getch();
}
//------------------------------------delete train function----------------------------------------------
void dlttrain()
{
	aread();
    char train[100];
    int location = -1,f;
    printf ("\n\n\tenter train number: ");
    scanf ("%s",train);
    for (f=0;f<k;f++)
    {
        if (strcmp(train,add[f].train_number)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        admin();
    }
    else
    {
        for (f=location;f<k;f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].train_number,add[f+1].train_number);
            strcpy(add[f].train_name,add[f+1].train_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].price,add[f+1].price);
            strcpy(add[f].time,add[f+1].time);
            awrite();
        }
        k--;
        awrite();
		printf("\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>");
		getch();
		system("cls");
		admin();
    }
}
//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
	int a,j;
	system("cls");
	viewpassengers_read();
	printf("***************************************************************************");
    printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
    printf("***************************************************************************\n");
	printf("\n\n\t\t\ttrain number\t\tname\t\tphone number\t\tdate\t\tseat\n");
	printf("\n\t\t\t**********************************************************************************\n");
	for(j=0;j<u;j++)
	{
		printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t   %d",book[j].train_number,book[j].name,book[j].phone,book[j].date,book[j].seat);
		book[j].seat++;
	}
	printf("\n\t\t\t**********************************************************************************\n");
	printf("\n\n\t\t\tenter '1' for main menu & enter '0' for back: ");
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		main();
	}
	if(a==0)
	{
		system("cls");
		admin();
	}
}
//--------------------------------------add train function--------------------------------------------
void addtrain()
{
	system("cls");
	int ch;
	aread();
	int i,a;
            printf("***************************************************************************");
            printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
            printf("***************************************************************************\n");
	printf("\n\n\t\t\thow many trains do you want to add: ");
	scanf("%d",&a);
	for(i=k;i<k+a;i++)
	{
		printf("\n\t\t\tenter %d train details: ",i+1);
		printf("\n\t\t\tenter serial number: ");
		scanf("%s",add[i].si);
		printf("\n\t\t\tenter train number: ");
		scanf("%s",add[i].train_number);
		printf("\n\t\t\tenter train name: ");
		scanf("%s",add[i].train_name);
		printf("\n\t\t\tenter start place: ");
		scanf("%s",add[i].start);
		printf("\n\t\t\tenter destination place: ");
		scanf("%s",add[i].destination);
		printf("\n\t\t\t enter price: ");
		scanf("%s",add[i].price);
		printf("\n\t\t\t enter seat: ");
		scanf("%d", & add[i].seat);
		printf("\n\t\t\t enter time: ");
		scanf("%s",add[i].time);
	}

		printf("\n\n\t\t\tconfirm train: (y=1/n=0):- ");
		scanf("%d",&ch);
		if(ch==1)
		{
			awrite();
			k=i;
			awrite();
			system("cls");
            printf("***************************************************************************");
            printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
            printf("***************************************************************************\n");
			printf("\n\n");
			printf("\n\t\t\t\t   **********************************");
			printf("\n\t\t\t\t   *<<<<<train add successfully>>>>>*");
			printf("\n\t\t\t\t   **********************************");
			getch();
			system("cls");
			main();
		}
			if(ch==0)
			{
				system("cls");
				admin();
			}
			if((ch!=1)&&(ch!=0))
			{
				system("cls");
				main();
			}
}
//-----------------------------------view information function--------------------------------------
void viewinfo()
{
	int ch,i;
	system("cls");
	aread();
            printf("***************************************************************************");
            printf("\n\t\t\tRAILWAY RESERVATION SYSTEM\n");
            printf("***************************************************************************\n");
	printf("\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\tseat\ttime\n\n");
	for(i=0;i<k;i++)
	{
		printf("    %s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%d\t%s\n",add[i].si,add[i].train_number,add[i].train_name,add[i].start,add[i].destination,add[i].price,add[i].seat,add[i].time);
	}
	printf("    ***********************************************************************************************\n");
	printf("\n\t\t\tpress '1' for main menu & press any key for exit:  ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			system("cls");
			main();
			break;
				default:
					exit(0);
	}
}
//------------------------------------------book ticket file start-----------------------------------------
void bookticket_write()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
void viewpassengers_read()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book,sizeof(book),1,booklist);
	fclose(booklist);
	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
//-----------------------------------------add train file start---------------------------------------------------
void awrite()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","w");
	fwrite(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","w");
	fwrite(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
void aread()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","r");
	fread(&add,sizeof(add),1,train_details);
	fclose(train_details);
	FILE *train_report;
	train_report = fopen("train_report.txt","r");
	fread(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
//----------------------------------------------------file close----------------------------------------------
//----------------------------------------------------program close----------------------------------------

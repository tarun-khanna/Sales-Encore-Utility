#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

int i=0;
int h=-1;
int j=0;

void home(void);
void login();
void home_opt(int c);

void view_pros();
void pass_change();

void admin_home();

void new_emp();
void view_emp();
void del_pros();


void monitor_home();

void new_pros();
void search_pros();
void upd_pros();

struct employee
{
char name[20];
char role[10];
char pass[5];
char address[50];
char no[15];
}e[50];

struct prospect
{
char name[20];
char address[20];
char no[15];
char status[10];
}p[50];

void main()
{

clrscr();
strcpy(e[0].name,"tarun");
strcpy(e[0].role,"admin");
strcpy(e[0].pass,"1234");
strcpy(e[0].address,"Rohini,DELHI");
strcpy(e[0].no,"7042466206");
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");

cleardevice();
home();

closegraph();
}

void home()
{
setcolor(WHITE);
char ch;
cleardevice();

rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,BLUE);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(80,50,"Sales Encore Utility");
settextstyle(6,HORIZ_DIR,4);
outtextxy(getmaxx()/2-100,200,"1.LOGIN");
outtextxy(getmaxx()/2-200,250,"2.ABOUT THE DEVELOPER");
outtextxy(getmaxx()/2-120,300,"3.TERMINATE");
settextstyle(5,HORIZ_DIR,3);
outtextxy(getmaxx()-250,getmaxy()-60,"==>enter your choice");
fflush(stdin);
ch=getch();
switch(ch)
{
case '1':login();
	break;

case '2':
cleardevice();
settextstyle(1,HORIZ_DIR,5);
outtextxy(getmaxx()/2-150,getmaxy()/2-50,"TARUN KHANNA") ;
outtextxy(getmaxx()/2-50,getmaxy()/2,"CSE-A");
outtextxy(50,getmaxy()/2+50,"ENROLL. NO-06120802714");
delay(5000);
home();
break;

case '3':exit(0);

default:cleardevice();
settextstyle(1,HORIZ_DIR,5);
outtextxy(getmaxx()/2-100,getmaxy()/2,"ERROR!!!");
delay(1000);
home();}
getch();
}



void login()
{char user[20],pass[5];
cleardevice();
setcolor(WHITE);
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(80,50,"Sales Encore Utility");
settextstyle(6,HORIZ_DIR,5);
outtextxy(getmaxx()/2-280,150,"enter username=>");
fflush(stdin);
gotoxy(46,12);
cin>>user;
outtextxy(getmaxx()/2-280,180,"enter password=>");
fflush(stdin);
gotoxy(46,14);
int k=0;
while(k<=3)
{
pass[k]=getche();
cout<<pass[k];
delay(100);
cout<<'\b';
cout<<"*";
++k;
}
pass[k]='\0';
int flag=0;
for(j=0;j<=i;++j)
{
if(strcmp(e[j].name,user)==0)
{    flag=1;
if(strcmp(e[j].pass,pass)==0)
{
if(strcmp(e[j].role,"admin")==0)
{
outtextxy(getmaxx()/2-200,getmaxy()/2+50,"WELCOME:");
outtextxy(getmaxx()/2+50,getmaxy()/2+50,e[j].name);
delay(1800);
admin_home();
}
else if(strcmp(e[j].role,"monitor")==0)
{
outtextxy(getmaxx()/2-200,getmaxy()/2+50,"WELCOME:");
outtextxy(getmaxx()/2+50,getmaxy()/2+50,e[j].name);
delay(1800);
monitor_home();
}
}
else
{
cout<<"\n\n\t\tWRONG PASSWORD....press any key to go to HOMEPAGE";
getch();
home();
}

 }
 }
if(flag==0)
{
gotoxy(5,18);
cout<<"NO SUCH USERNAME EXIST IN RECORDS!!...press any key to go to HOMEPAGE";
getch();
home();
}
getch();
}

void admin_home()
{
setcolor(WHITE);
char ch;
cleardevice();

rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(80,50,"ADMINISTRATOR HOME");
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);
settextstyle(7,HORIZ_DIR,3);
outtextxy(getmaxx()/2-280,150,"1.add new prospect monitor/adminisrtator");
outtextxy(getmaxx()/2-280,190,"2.view all employees");
outtextxy(getmaxx()/2-280,230,"3.view all prospects");
outtextxy(getmaxx()/2-280,270,"4.change password");
outtextxy(getmaxx()/2-280,310,"5.delete prospect details");
outtextxy(getmaxx()/2-280,350,"6.sign out");
settextstyle(5,HORIZ_DIR,3);
outtextxy(getmaxx()-250,getmaxy()-60,"==>enter your choice");
fflush(stdin);
ch=getch();
switch(ch)
{
case '1':new_emp();
	break;

case '2':view_emp();
	break;

case '3':view_pros();
	break;

case '4':pass_change();
	break;

case '5':del_pros();
	break;
case '6':home();
	break;

default:cleardevice();
settextstyle(1,HORIZ_DIR,5);outtextxy(getmaxx()/2-100,getmaxy()/2,"ERROR!!!");
delay(1000);
admin_home();
}
getch();
}

void new_emp()
{setcolor(WHITE);

++i;

b:
randomize();
cleardevice();
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(80,50,"ADMINISTRATOR HOME");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(100,150,"ADD NEW MONITOR/ADMIN");
settextstyle(1,HORIZ_DIR,4);
outtextxy(getmaxx()/2-280,200,"Username:");
outtextxy(getmaxx()/2-280,250,"Role(monitor/admin):");
outtextxy(getmaxx()/2-280,300,"Address:");
outtextxy(getmaxx()/2-280,350,"Contact no:");
gotoxy(27,15);
gets(e[i].name);
//FOR SAME USERNAME
for(int y=0;y<i;++y)
{
if(strcmp(e[y].name,e[i].name)==0)
{              cleardevice();
outtextxy(20,100,"USERNAME ALREADY EXIST!!  ..TRY AGAIN ");
delay(1000);
goto b;
}
}
c:

setfillstyle(1,BLACK);
bar(380,250,600,300);

gotoxy(50,18);
gets(e[i].role);
if(strcmp(e[i].role,"monitor")!=0 && strcmp(e[i].role,"admin")!=0 )
goto c;

gotoxy(24,21);
gets(e[i].address);

gotoxy(30,24);
gets(e[i].no);

cleardevice();
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(80,50,"ADMINISTRATOR HOME");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(120,210,"ACCOUNT SUCCESFULLY CREATED!!");
outtextxy(120,250,"YOUR USERNAME IS>");
outtextxy(120,300,"YOUR PASSWORD IS>");
long int rno;
char r[5];
a:
rno=rand()%10000;

      if(rno<=1000 || rno>=9999 )
      {
      goto a;
      }
      else
      {
      sprintf(r,"%ld",rno);
      strcpy(e[i].pass,r);
      outtextxy(420,250,e[i].name);
      outtextxy(420,300,e[i].pass);
      }

getch();
admin_home();
}

void view_emp()
{
cleardevice();
setcolor(WHITE);
char temp[20];
int f=0;
rectangle(30,30,getmaxx()-40,100);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,25);
outtextxy(70,50,"LIST OF ALL EMPLOYEES");
settextstyle(7,HORIZ_DIR,3);
setcolor(WHITE);
setfillstyle(1,LIGHTGRAY);
bar(20,120,getmaxx()-20,getmaxy()-30);
line(20,120,getmaxx()-20,120);
line(20,120,20,getmaxy()-30);
line(20,getmaxy()-30,getmaxx()-20,getmaxy()-30);
line(getmaxx()-20,120,getmaxx()-20,getmaxy()-30);
setcolor(BLACK);
line(20,150,getmaxx()-20,150);
line(180,120,180,getmaxy()-30);
line(350,120,350,getmaxy()-30);
line(510,120,510,getmaxy()-30);

outtextxy(30,115,"NAME");
outtextxy(200,115,"ADDRESS");
outtextxy(380,115,"PHONE");
outtextxy(525,115,"ROLE");

for(int y=0;y<=i;++y)
{
settextstyle(2,HORIZ_DIR,6);
outtextxy(30,170+f,e[y].name);
outtextxy(200,170+f,e[y].address);
outtextxy(360,170+f,e[y].no);
outtextxy(520,170+f,e[y].role);

f=f+20;
}

getch();
admin_home();
}


void view_pros()
{

cleardevice();
setcolor(WHITE);
char temp[20];
int f=0;
rectangle(30,30,getmaxx()-40,100);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,25);
outtextxy(70,50,"LIST OF ALL PROSPECTUS");
settextstyle(7,HORIZ_DIR,3);
setcolor(WHITE);
setfillstyle(1,LIGHTGRAY);
bar(20,120,getmaxx()-20,getmaxy()-30);
line(20,120,getmaxx()-20,120);
line(20,120,20,getmaxy()-30);
line(20,getmaxy()-30,getmaxx()-20,getmaxy()-30);
line(getmaxx()-20,120,getmaxx()-20,getmaxy()-30);
setcolor(BLACK);
line(20,150,getmaxx()-20,150);
line(180,120,180,getmaxy()-30);
line(350,120,350,getmaxy()-30);
line(510,120,510,getmaxy()-30);

outtextxy(30,115,"NAME");
outtextxy(200,115,"ADDRESS");
outtextxy(380,115,"PHONE");
outtextxy(525,115,"STATUS");

for(int y=0;y<=h;++y)
{
outtextxy(30,170+f,p[y].name);
outtextxy(195,170+f,p[y].address);
outtextxy(360,170+f,p[y].no);
outtextxy(520,170+f,p[y].status);
f=f+20;

}
getch();
if(strcmp(e[j].role,"admin")==0)
admin_home();
else
monitor_home();

}


void pass_change()
{
cleardevice();
setcolor(WHITE);
int flag=0;
char opass[5];
char pass[5];
char user[25];
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(150,50,"CHANGE PASSWORD");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(155,200,"Your Username is:");
outtextxy(420,200,e[j].name);
int k=0;
outtextxy(148,250,"Enter The OLD PASSWORD:");
gotoxy(60,17);
gets(opass);
if(strcmp(e[j].pass,opass)==0)
{
outtextxy(145,300,"Enter NEW PASSWORD:");
gotoxy(54,20);
while(k<=3)
{
pass[k]=getche();
cout<<pass[k];
delay(100);
cout<<'\b';
cout<<"*";
++k;
}
pass[k]='\0';
strcpy(e[j].pass,pass);
settextstyle(7,HORIZ_DIR,7);
outtextxy(getmaxx()/2-100,350,"DONE!!");
}
else if(strcmp(e[j].pass,opass)!=0)
{
outtextxy(80,150,"OLD PASSWORD MISMATCH");
outtextxy(80,getmaxy()-50,"....press any key to go to HOME");
}

getch();
if(strcmp(e[j].role,"admin")==0)
admin_home();
else
monitor_home();

}





void del_pros()
{

cleardevice();
setcolor(WHITE);
int flag=0;
setcolor(WHITE);
char user[25];
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(150,50,"DELETE PROSPECTS");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);
outtextxy(148,200,"Enter The name:");
gotoxy(48,14);
gets(user);
for(int y=0;y<=h;++y)
{
if(strcmp(p[y].name,user)==0)
{
flag=1;
int k=0;
for(int x=y;x<h;++x)
{
strcpy(p[x].name,p[x+1].name);
strcpy(p[x].status,p[x+1].status);
strcpy(p[x].address,p[x+1].address);
strcpy(p[x].no,p[x+1].no);
}

outtextxy(200,300,"RECORD DELETED");
--h;
}
}

if(flag==0)
{
outtextxy(80,150,"NO SUCH PROSPECT EXIST IN RECORDS");
outtextxy(80,getmaxy()-50,"....press any key to go to ADMIN HOME");
}

getch();
admin_home();

}


void monitor_home()
{
char ch;
cleardevice();
setcolor(WHITE);
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(170,50,"MONITOR HOME");
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);
settextstyle(7,HORIZ_DIR,3);
outtextxy(getmaxx()/2-280,150,"1.add new prospects");
outtextxy(getmaxx()/2-280,190,"2.view all prospects");
outtextxy(getmaxx()/2-280,230,"3.search prospect");
outtextxy(getmaxx()/2-280,270,"4.change password");
outtextxy(getmaxx()/2-280,310,"5.update prospect phone no.");
outtextxy(getmaxx()/2-280,350,"6.sign out");
settextstyle(5,HORIZ_DIR,3);
outtextxy(getmaxx()-250,getmaxy()-60,"==>enter your choice");
fflush(stdin);
ch=getch();


switch(ch)
{
case '1':new_pros();
	break;

case '2':view_pros();
	break;

case '3':search_pros();
	break;

case '4':pass_change();
	break;

case '5':upd_pros();
	break;
case '6':home();
	break;

default:cleardevice();
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(getmaxx()/2-100,getmaxy()/2,"ERROR!!!");
delay(500);
monitor_home();
}
getch();
}


void new_pros()
{

++h;
setcolor(WHITE);

cleardevice();
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(170,50,"MONITOR HOME");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(170,150,"ADD NEW PROSPECT");
settextstyle(1,HORIZ_DIR,4);
outtextxy(getmaxx()/2-280,200,"Name:");
outtextxy(getmaxx()/2-280,250,"Status(hot/warm/cold):");
outtextxy(getmaxx()/2-280,300,"Address:");
outtextxy(getmaxx()/2-280,350,"Contact no:");
gotoxy(22,15);
gets(p[h].name);
c:

setfillstyle(1,BLACK);
bar(420,250,600,300);
gotoxy(54,18);
gets(p[h].status);
if(strcmp(p[h].status,"hot")!=0 && strcmp(p[h].status,"warm")!=0 && strcmp(p[h].status,"cold")!=0)
goto c;
gotoxy(24,21);
gets(p[h].address);
gotoxy(30,24);
gets(p[h].no);

cleardevice();
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(170,50,"MONITOR HOME");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(120,210,"ACCOUNT SUCCESFULLY CREATED!!");

getch();
monitor_home();

}


void search_pros()
{
setcolor(WHITE);
cleardevice();
int flag=0;
char temp[20];
char pname[25];
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,50);
outtextxy(150,50,"SEARCH PROSPECTUS");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(148,200,"Enter The NAME to search:");
gotoxy(64,14);
gets(pname);
for(int y=0;y<=h;++y)
{
if(strcmp(p[y].name,pname)==0)
{
flag=1;
outtextxy(155,250,"PROSPECTUS FOUND");
outtextxy(155,280,"DETAILS-->");

outtextxy(130,305,"NAME:");
outtextxy(130,330,"STATUS:");
outtextxy(130,355,"ADDRESS:");
outtextxy(130,380,"Contact No:");
settextstyle(7,HORIZ_DIR,3);
outtextxy(300,305,p[y].name);

outtextxy(300,330,p[y].status);

outtextxy(300,355,p[y].address);

outtextxy(300,380,p[y].no);
}
}
if(flag==0)
{
outtextxy(80,150,"NO SUCH Prospectus EXIST IN RECORDS");
outtextxy(80,getmaxy()-50,"....press any key to go to MONITOR HOME");

}
getch();
monitor_home();


}


void upd_pros()
{
cleardevice();
int flag=0;
char temp[20];
setcolor(WHITE);
char pname[25];
rectangle(10,10,getmaxx()-20,getmaxy()-10);
rectangle(20,20,getmaxx()-30,getmaxy()-20);
rectangle(30,30,getmaxx()-40,150);
setfillstyle(XHATCH_FILL,RED);
floodfill(40,40,WHITE);
settextstyle(2,HORIZ_DIR,30);
outtextxy(20,50,"CHANGE PROSPECTUS CONTACT");
settextstyle(7,HORIZ_DIR,3);
line(getmaxx()/2,10,getmaxx()/2,20);
line(getmaxx()-30,getmaxy()/2,getmaxx()-20,getmaxy()/2);
line(getmaxx()/2,getmaxy()-20,getmaxx()/2,getmaxy()-10);
line(10,getmaxy()/2,20,getmaxy()/2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,15,WHITE);
delay(150);
floodfill(getmaxx()/2+5,15,WHITE);
delay(150);
floodfill(getmaxx()-25,getmaxy()/2+10,WHITE);
delay(150);
floodfill(getmaxx()/2-5,getmaxy()-15,WHITE);

outtextxy(148,200,"Enter The NAME to search:");
gotoxy(64,14);
gets(pname);
for(int y=0;y<=h;++y)
{
if(strcmp(p[y].name,pname)==0)
{
flag=1;
outtextxy(155,250,"PROSPECTUS FOUND");
outtextxy(155,280,"DETAILS-->");

outtextxy(130,305,"NAME:");
outtextxy(130,330,"PREVIOUS Contact No:");
settextstyle(7,HORIZ_DIR,3);
outtextxy(450,305,p[y].name);

outtextxy(450,330,p[y].no);

outtextxy(130,355,"NEW Contact No:");
gotoxy(58,24);
gets(p[y].no);

settextstyle(7,HORIZ_DIR,7);
outtextxy(getmaxx()/2-100,370,"DONE!!");
}
}
if(flag==0)
{
outtextxy(80,150,"NO SUCH Prospectus EXIST IN RECORDS");
outtextxy(80,getmaxy()-50,"....press any key to go to MONITOR HOME");

}
getch();
monitor_home();
}

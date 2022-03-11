#include<time.h>
#include<iomanip>
#include <conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
#define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s on line %d\n", __FILE__, GetLastError(), api, __LINE__);}
struct student
{
    char num[15];
    char name[10];
    char phone[20];
    char adress[20];
    student *next;
};
static int i=1;
void MyCls(HANDLE) ;


/*
//读文件记录函数
student *readfile(student *p)
{
    int k=1;
    student *head=p;
    ifstream read("input.txt");    // 读文件流
    //ofstream write("c://record.dat");    // 写文件流

    // 判断是否打开成功
    if(!read)
    {
        printf("文件打开失败\n");return head;
    }
    while(!read.eof())
    {
        if(k++==1)head=p=new student;
        else{p->next=new student;p=p->next;}
        read>>p->num>>p->name>>p->phone>>p->adress;
    }
    p=NULL;
    read.close();
    return head;
}

void writerecord(student *pointer)
{
	student *p=pointer;
	ofstream write("output.txt");
	if(!write){cout<<"文件打开失败\n";
	}
	while(p!=NULL)
	{
		write<<p->num<<" "<<p->name<<" "<<p->phone<<" "<<p->adress<<endl;
		p=p->next;
	}
	write.close();
}
*/

//清屏函数
void clrscr(void)
{
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
MyCls(hStdOut);
return;
}
void MyCls(HANDLE hConsole)
{
COORD coordScreen={0,0};//设置清屏后光标返回的屏幕左上角坐标
BOOL bSuccess;
DWORD cCharsWritten;
CONSOLE_SCREEN_BUFFER_INFO csbi;//保存缓冲区信息
DWORD dwConSize;//当前缓冲区可容纳的字符数
bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息
PERR(bSuccess,"GetConsoleScreenBufferInfo");
dwConSize=csbi.dwSize.X * csbi.dwSize.Y;//缓冲区容纳字符数目
//用空格填充缓冲区
bSuccess=FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
PERR(bSuccess,"FillConsoleOutputCharacter");
bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息
PERR(bSuccess,"ConsoleScreenBufferInfo");
//填充缓冲区属性
bSuccess=FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
PERR(bSuccess,"FillConsoleOutputAttribute");
//光标返回屏幕左上角坐标
bSuccess=SetConsoleCursorPosition(hConsole,coordScreen);
PERR(bSuccess,"SetConsoleCursorPosition");
return;
}
//直接退出函数
void exit()
{
    clrscr();
	printf("\n\n\n\n\n\n\n\n\n\n                          谢谢您的使用 祝您生活愉快\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");getchar();

}


    HANDLE hInput;  /*  获取标准输入设备句柄 */
INPUT_RECORD inRec;/*  返回数据记录 */
DWORD numRead; /*  返回已读取的记录数 */
int Y,X;/* X和Y的坐标 */

student * search(student *pointer)
{char num[15];char name[10];
student *p=pointer;
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  按学号查找  ┃         ┃   按姓名查找   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==0||Y==1||Y==2)&&X>3&&X<19)
            {
            	cout<<"请输入学号:"<<endl;
            	cin>>num;
            	while(p!=NULL)
				{
            		if(strcmp(p->num,num)==0)
					{
            			cout<<setw(14)<<p->num<<setw(8)<<p->name<<setw(14)<<p->phone<<setw(15)<<p->adress<<endl;goto L1;
					}
					else p=p->next;
				}
				cout<<"该学生不存在"<<endl;
				goto L1;
			}
		if((Y==0||Y==1||Y==2)&&X>28&&X<38)
		{
			cout<<"请输入姓名:"<<endl;
            	cin>>name;
            	while(p!=NULL)
				{
            		if(strcmp(name,p->name)==0)
					{
            			cout<<setw(14)<<p->num<<setw(8)<<p->name<<setw(14)<<p->phone<<setw(15)<<p->adress<<endl;goto L1;
					}
					else p=p->next;
				}
				cout<<"该学生不存在"<<endl;goto L1;
		}
        }
    }

L1:HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
		SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	//////"1234567890123456789012345678901234567890123456789
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  返回主菜单  ┃         ┃   直接退出   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==7||Y==9||Y==8)&&X>3&&X<24){
            	clrscr();return pointer;
			}
if((Y==7||Y==8||Y==9)&&X>28&&X<39){clrscr();exit();}
        }
    }
}
student *sort(student *p)
{
	student *pointer=p;student *upsort(student*);student *downsort(student *);
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃     升序     ┃         ┃     降序     ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
		ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==0||Y==1||Y==2)&&X>3&&X<24)
			{
            	p=upsort(pointer);
    cout<<"              ┏━━━━━━━━━━━━━━┓                                  \n"
		<<"              ┃ 升序排列成功 ┃                                  \n"//3-21
		<<"              ┗━━━━━━━━━━━━━━┛                                  \n";
		HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
		SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	//////"1234567890123456789012345678901234567890123456789
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  返回主菜单  ┃         ┃   直接退出   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==7||Y==6||Y==8)&&X>3&&X<24){
            	clrscr();return p;
			}
if((Y==7||Y==8||Y==6)&&X>28&&X<39){clrscr();exit();}
        }
    }
			}
if((Y==0||Y==1||Y==2)&&X>28&&X<39)
		{
			p=downsort(pointer);
    cout<<"              ┏━━━━━━━━━━━━━━┓                                  \n"
		<<"              ┃ 降序排列成功 ┃                                  \n"//3-21
		<<"              ┗━━━━━━━━━━━━━━┛                                  \n";
		HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
		SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	//////"1234567890123456789012345678901234567890123456789
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  返回主菜单  ┃         ┃   直接退出   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==7||Y==6||Y==8)&&X>3&&X<24)
			{
            	clrscr();return p;
			}
if((Y==7||Y==8||Y==6)&&X>28&&X<39){clrscr();exit();}
        }
    }
		}
        }
    }

}

int compare(char p1[],char p2[])
{int i=0;
	while(i<strlen(p1)&&i<strlen(p2))
	{
		if(p1[i]==p2[i]){i++;}
		else return p1[i]-p2[i];
	}
	return 0;
}



student *upsort(student*p)
{
	char t;student *head=p;
	student *pointer=p;
	int len=0;
	while(pointer!=NULL){
		pointer=pointer->next;
		len++;
	}
	for(int k=0;k<len;k++)
	{
		p=head;
		for(int j=0;j<len-k-1;j++)
		{
		if(compare(p->num,p->next->num)>0)
		{
			for(int i=0;i<15;i++){t=p->num[i];p->num[i]=p->next->num[i];p->next->num[i]=t;	}
			for(int i=0;i<10;i++){t=p->name[i];p->name[i]=p->next->name[i];p->next->name[i]=t;	}
			for(int i=0;i<20;i++){t=p->phone[i];p->phone[i]=p->next->phone[i];p->next->phone[i]=t;	}
			for(int i=0;i<20;i++){t=p->adress[i];p->adress[i]=p->next->adress[i];p->next->adress[i]=t;	}
		}
			p=p->next;
		}

	}
	return head;
}

student *downsort(student *p)
{
	char t;student *head=p;
	student *pointer=p;
	int len=0;
	while(pointer!=NULL){
		pointer=pointer->next;
		len++;
	}
	for(int k=0;k<len;k++)
	{
		p=head;
		for(int j=0;j<len-k-1;j++)
		{
		if(compare(p->num,p->next->num)<0)
		{
			for(int i=0;i<15;i++){t=p->num[i];p->num[i]=p->next->num[i];p->next->num[i]=t;	}
			for(int i=0;i<10;i++){t=p->name[i];p->name[i]=p->next->name[i];p->next->name[i]=t;	}
			for(int i=0;i<20;i++){t=p->phone[i];p->phone[i]=p->next->phone[i];p->next->phone[i]=t;	}
			for(int i=0;i<20;i++){t=p->adress[i];p->adress[i]=p->next->adress[i];p->next->adress[i]=t;	}
		}
			p=p->next;
		}

	}
	return head;
}

//主菜单函数
int menu()
{
hInput = GetStdHandle(STD_INPUT_HANDLE); /*  输入设备句柄 */
       /*printf("********************************************************\n");
        printf("*             student information system               *\n");
        printf("*insert information         ");//(2,1)-(2,20)
        printf("      print the information*\n");//(2,29)-(2,51)
        printf("*delete a specific student        ");//(3,1)-(3,26)
        printf("exit                 *\n");//(3,35)-(3,40)
        printf("*add new student          ");//(4,1)-(4,16)
        printf("        modify information   *\n");//(4,26)-(4,46)
        printf("********************************************************\n");*/



        HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0, 0, 90,80};
	SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);
	cout<<endl
		<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<<"┃                                                                            ┃\n"
		<<"┃                           小型学生通讯录管理系统                           ┃\n"
		<<"┃                                                                            ┃\n"
		<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
		//"12345678901234567890123456789012345678901234567890
		<<"                             ┏━━━━━━主菜单━━━━━━┓\n"
		<<"                             ┃                  ┃\n"//30-50
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    创建通讯录    ┃\n"//9
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    显示通讯录    ┃\n"//11
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    查询通讯录    ┃\n"
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    添加通讯录    ┃\n"
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    修改通讯录    ┃\n"
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    删除通讯录    ┃\n"
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    通讯录排序    ┃\n"
		<<"                             ┣━━━━━━━━━━━━━━━━━━┫\n"
		<<"                             ┃    退出通讯录    ┃\n"
		<<"                             ┗━━━━━━━━━━━━━━━━━━┛\n";
 time_t tt = time(NULL);//这句返回的只是一个时间cuo
 tm* t= localtime(&tt);
 printf("%d-%02d-%02d\n",
  t->tm_year + 1900,
  t->tm_mon + 1,
  t->tm_mday);

ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if(Y==9&&X>30&&X<50){clrscr();return 1;}
            if(Y==11&&X>30&&X<50){clrscr();return 2;}
            if(Y==13&&X>30&&X<50){clrscr();return 3;}
            if(Y==15&&X>30&&X<50){clrscr();return 4;}
            if(Y==17&&X>30&&X<50){clrscr();return 5;}
            if(Y==19&&X>30&&X<50){clrscr();return 6;}
            if(Y==21&&X>30&&X<50){clrscr();return 7;}
            if(Y==23&&X>30&&X<50){clrscr();return 8;}
        }
    }

}

//隐藏光标
void HideCursor()//隐藏控制台的光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}



//main函数
int main()
{
void writerecord(student*);
void mydisplay(student *);
void clrscr();
    int menu();
      //HideCursor(); //隐藏控制台的光标
    struct student *head=NULL;
    student *insert(struct student *);
    void print(struct student *);
    student *del(struct student *,char [15]);
student *add(student*);
student *modify(student *);
//head=readfile(head);

    int rt=1;
    while(rt)
           {
                  rt=menu();
                switch(rt)
                {
                    case 1:{head=insert(head);break;}
                    case 2:mydisplay(head);break;
                    case 3:head=search(head);break;
                    case 4:{head=add(head);break;}
                    case 5:{head=modify(head);break;}
                    case 6:{printf("请输入要删除的学生姓名:\n");char n[15];cin>>n;head=del(head,n);break;}
                    case 7:head=sort(head);break;
                	case 8:{exit();return 0;}
                    default :{printf("error, try again");/*sleep(1);*/break;}
                }
            }


    return 0;
}




//创建函数
student *insert(struct student *head)
{int i;
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
	student *p=head;
	SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	clrscr();
	//////"123456789012345678
    cout<<"┏━━━━━━━━━━━━━━┓                                                              \n"
		<<"┃  返回主菜单  ┃                                                              \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛                                                              \n";

    int n;struct student *p1,*p2;
    head=p1=p2=new student;
    printf("请输入人数：");
    scanf("%d",&n);

        printf("请输入学号，姓名，手机号码和学院名称\n");
    for(i=0;i<n;i++)
    {
    	p2=p1;
        if(i!=0)p1=new student;
		scanf("%s%s%s%s",(p1->num),p1->name,p1->phone,p1->adress);
        p2->next=p1;
    }
    p1->next=NULL;
    Sleep(1000);
    cout<<"┏━━━━━━━━━━━━━━┓                                      \n"
		<<"┃   创建成功   ┃                                      \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛                                      \n";
    ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==0||Y==2||Y==1)&&X>3&&X<19){
            	clrscr();return head;
			}
        }
    }
    return (head);
}


//显示函数
void mydisplay(student *head)
{
	int len(int);
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
	student *p=head;
	int n=0;
	SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	clrscr();
	cout<<endl
	//////"123456789012345678
		<<"┏━━━━━━━━━━━━━━┓                                                              \n"
		<<"┃  返回主菜单  ┃                                                              \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛                                                              \n"
		<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━通讯录列表━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<<"┃                                                            ┃\n"
		<<"┣━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━┫\n"
		<<"┃     学号     ┃     姓名     ┃    联系电话    ┃    学院     ┃\n";
	if(p==NULL)
	cout<<"┣━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━┫\n"
		<<"┃没有任何记录.                                               ┃\n"
		<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	else
	{
    cout<<"┣━━━━━━━━━━━━━━┫━━━━━━━━━━━━━━┫━━━━━━━━━━━━━━━━┫━━━━━━━━━━━━━┫\n";
		while(p!=NULL)
		{
			n=n+1;
			if(n!=1)
	cout<<"┣━━━━━━━━━━━━━━┫━━━━━━━━━━━━━━┫━━━━━━━━━━━━━━━━┫━━━━━━━━━━━━━┫\n";
	cout<<"┃"<<setw(14)<<p->num<<"│"<<setw(14)<<p->name<<"│"<<setw(16)<<p->phone<<"│"<<setw(13)<<p->adress<<"┃\n";
			p=p->next;
		}
	cout<<"┣━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━┫\n"
		<<" 总共有"<<n<<"条记录";cout<<string(4-len(n),' ')<<endl;
		cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==0||Y==2||Y==1)&&X>3&&X<19){
            	clrscr();return;
			}
        }
    }
clrscr();
}
int len(int n)
{
	int i=0;
	while(n>0)
	{
		n=n/10;
		i++;
	}
	return i;
}


//添加函数
student *add(student *p)
{
		//writerecord(p);
    student *head=p;
    while(p->next!=NULL)p=p->next;
    p->next=new student;
    printf("请输入学号，姓名，手机号码和学院名称\n");
    scanf("%s%s%s%s",(p->next->num),p->next->name,p->next->phone,p->next->adress);
    p=p->next;
    p->next=NULL;

HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
		SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	cout<<"             ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"             ┃   添加成功   ┃                                   \n"//3-21
		<<"             ┗━━━━━━━━━━━━━━┛                                   \n";
	//////"1234567890123456789012345678901234567890123456789
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  返回主菜单  ┃         ┃   直接退出   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==6||Y==5||Y==7)&&X>3&&X<19){
            	clrscr();return head;
			}
if((Y==5||Y==6||Y==7)&&X>28&&X<35){clrscr();exit();}
        }
    }
    return head;
}




//修改函数
student *modify(student *p)
{
    student *pointer=p;
    char name[10];
    printf("输入要修改的学生姓名\n");
    scanf("%s",name);
    while(p!=NULL&&strcmp(p->name,name)!=0)p=p->next;
    if(strcmp(p->name,name)==0){printf("已找到该学生的信息\n");printf(" %s   %s   %s     %s\n",p->num,p->name,p->phone,p->adress);
    printf("请输入修正的学生信息");
    printf("请输入学号，姓名，手机号码和学院名称\n");scanf("%s%s%s%s",(p->num),p->name,p->phone,p->adress);
    cout<<"             ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"             ┃   修改成功   ┃                                   \n"//3-21
		<<"             ┗━━━━━━━━━━━━━━┛                                   \n";
    }
    else {printf("该学生不存在\n");Sleep(1000);}
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
		SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	//////"1234567890123456789012345678901234567890123456789
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  返回主菜单  ┃         ┃   直接退出   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==8||Y==10||Y==9)&&X>3&&X<19){
            	clrscr();return pointer;
			}
if((Y==8||Y==9||Y==10)&&X>28&&X<35){clrscr();exit();}
        }
    }
        return (pointer);
}





//删除函数
student *del(student *head,char n[15])
{
			student *p1=head;student *p2=head;
        if(p1!=NULL){
                if(strcmp(p1->name,n)==0){printf("删除成功\n");p2=p1->next;delete p1;head=p2;goto L2;}
		p1=p1->next;
            while(p1!=NULL)
            {
                p2->next=p1;
                if(strcmp(p1->name,n)==0){printf("删除成功\n");p2->next=p1->next;delete p1;goto L2;}
                p2=p1;
                p1=p1->next;
            }
            printf("找不到对应的学生\n");
        }

L2:HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={90,80};
    SMALL_RECT rc={0,0, 90, 80};
		SetConsoleTitle("小型学生通讯录管理系统");
	SetConsoleScreenBufferSize(hOut, pos);
	SetConsoleWindowInfo(hOut, true,&rc);string stra(int);
	//////"1234567890123456789012345678901234567890123456789
	cout<<"┏━━━━━━━━━━━━━━┓         ┏━━━━━━━━━━━━━━┓                                   \n"
		<<"┃  返回主菜单  ┃         ┃   直接退出   ┃                                   \n"//3-21
		<<"┗━━━━━━━━━━━━━━┛         ┗━━━━━━━━━━━━━━┛                                   \n";
ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
        while(1)
     {
        COORD pos = {0,0};
        ReadConsoleInput(hInput, &inRec, 1, &numRead);
        pos = inRec.Event.MouseEvent.dwMousePosition;
        Y=(int)pos.Y;
        X=(int)pos.X;
        if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        {
            if((Y==4||Y==5||Y==3)&&X>3&&X<19){
            	clrscr();return head;
			}
if((Y==4||Y==5||Y==3)&&X>28&&X<35){clrscr();exit();}
        }
    }
        return (head);
}

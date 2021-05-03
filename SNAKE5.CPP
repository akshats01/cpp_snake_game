#include<iostream.h>//case where @ does not spawn on the body
#include<conio.h>//end case for body hit
#include<dos.h>//condition where 2 body parts, cant move back
#include<process.h>
#include<stdlib.h>
int endcond(int stackx[1920],int stacky[1920],int f,int l)
{   for(int i=l+1;i<f;i++)
    {	if(stackx[f]==stackx[i]&&stacky[f]==stacky[i])
		return(2);
    }
    return(0);
}
void main()
{	int x,y,fx,fy,stackx[1920],stacky[1920],l,f;
	char c;
	x=y=2;
	f=1;
	l=0;
	fx=fy=20;
	clrscr();
	gotoxy(x,y);
	cout<<"0";
	c=getch();
	int ty=75;
	int tx=50;
	int flag=0;
	randomize();
	do{

	gotoxy(80,24);
	if(c=='w')
	{	for(;y!=0;y--,l++,f++)
		{       stackx[f]=x;
			stacky[f]=y;
			flag=endcond(stackx,stacky,f,l);
			if(flag==2)
				break;
			gotoxy(stackx[l],stacky[l]);
			cout<<" ";
			gotoxy(x,y);
			cout<<"0";
			gotoxy(fx,fy);
			cout<<"@";
			gotoxy(80,24);
			if(fx==x&&fy==y)
			{	flag=1;
				break;
			}
			delay(ty);
			if(kbhit())
			{	c=getch();
				if(c!='w')
					break;
			}
			if(l==1919)
				l=-1;
			if(f==1919)
				f=-1;
		}
	}
	if(c=='s'&&flag==0)
	{	for(;y!=24;y++,l++,f++)
		{       stackx[f]=x;
			stacky[f]=y;
			flag=endcond(stackx,stacky,f,l);
			if(flag==2)
				break;
			gotoxy(stackx[l],stacky[l]);
			cout<<" ";
			gotoxy(x,y);
			cout<<"0";
			gotoxy(fx,fy);
			cout<<"@";
			gotoxy(80,24);
			if(fx==x&&fy==y)
			{	flag=1;
				break;
			}
			delay(ty);
			if(kbhit())
			{	c=getch();
				if(c!='s')
					break;
			}
			if(l==1919)
				l=-1;
			if(f==1919)
				f=-1;
		}
	}
	if(c=='a'&&flag==0)
	{	for(;x!=0;x--,l++,f++)
		{  	stackx[f]=x;
			stacky[f]=y;
			flag=endcond(stackx,stacky,f,l);
			if(flag==2)
				break;
			gotoxy(stackx[l],stacky[l]);
			cout<<" ";
			gotoxy(x,y);
			cout<<"0";
			gotoxy(fx,fy);
			cout<<"@";
			gotoxy(80,24);
			if(fx==x&&fy==y)
			{	flag=1;
				break;
			}
			delay(tx);
			if(kbhit())
			{	c=getch();
				if(c!='a')
					break;
			}
			if(l==1919)
				l=-1;
			if(f==1919)
				f=-1;
		}
	}
	if(c=='d'&&flag==0)
	{	for(;x!=80;x++,l++,f++)
		{  	stackx[f]=x;
			stacky[f]=y;
			flag=endcond(stackx,stacky,f,l);
			if(flag==2)
				break;
			gotoxy(stackx[l],stacky[l]);
			cout<<" ";
			gotoxy(x,y);
			cout<<"0";
			gotoxy(fx,fy);
			cout<<"@";
			gotoxy(80,24);
			if(fx==x&&fy==y)
			{	flag=1;
				break;
			}
			delay(tx);
			if(kbhit())
			{	c=getch();
				if(c!='d')
					break;
			}
			if(l==1919)
				l=-1;
			if(f==1919)
				f=-1;
		}
	}
	if(flag==1)
	{	fx=random(79)+1;
		fy=random(23)+1;
		flag=0;
		l--;
	}
	}while(c!='q'&&x!=0&&y!=0&&x!=80&&y!=24&&flag==0);
	clrscr();
	cout<<"BYE-BYE";
	delay(500);
	getch();
}
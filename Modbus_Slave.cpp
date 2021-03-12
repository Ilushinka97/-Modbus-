#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <iostream>

char hex(int x)
	{
		switch(x)
				{
				case 0:return '0';
				case 1:return '1';
				case 2:return '2';
				case 3:return '3';
				case 4:return '4';
				case 5:return '5';
				case 6:return '6';
				case 7:return '7';
				case 8:return '8';
				case 9:return '9';
				case 10:return 'A';
				case 11:return 'B';
				case 12:return 'C';
				case 13:return 'D';
				case 14:return 'E';
				case 15:return 'F';
				}
	}
	
	using namespace std;

int main()
{
	int i=0;
	char a[20],ans[100];
	int a1[20];
	int LRC, LRC_S;
	//outport(0x3FB,0x80);
	//outport(0x3F8,0x0C);
	//outport(0x3F9,0x00);
	//outport(0x3FB,0x6);
	
	for(i=0;i<15;i++)
	{
	/*	do 
		{
		while (inportb(0x3FD)%2==0);
		a[i] = inportb(0x3F8);
		}
while(i==1&&a[i]==':');
	}*/
for(i=1;i<15;i++)
		{
		if(a[i]>47&&a[i]<58)a1[i]=a[i]-48;
		else a1[i]= a[i]-55;
		}
	for(i=1;i<15;i++)
	cout<<"a1["<<i<<"]="<<a1[i]<<endl;
	LRC=0;
	for(i=1;i<13;i++)
		{
		if(i%2==0)LRC=LRC+a1[i];
		else LRC=LRC+a1[i]*16;
		}
	LRC=LRC%256;
	LRC=0xFF-LRC+1;
	LRC_S=a1[13]*16+a1[14];
	cout<<"LRC   = "<<LRC<<endl;
	cout<<"LRC_S = "<<LRC_S<<endl;
	if(LRC==LRC_S)
		cout<<"Controlnie summy soshlis"<<endl;
	else
	{
cout<<"Vnimanie! Summy ne soshlis!"<<endl;
	}
    cout<<"a1[4], a1[3]"<<a1[4]<<a1[3]<<endl;
	if(a1[4]==1&&a1[3]==0)
		cout<<"Funktsia verna"<<endl;
	else
	{
cout<<"Vnimanie! Funktsia ne verna!"<<endl;
	}
if (a1[4]==1&&a1[3]==0&&LRC==LRC_S)
{
	int x2=a1[11]*16+a1[12]+a1[9]*4096+a1[10]*256;
	int x22;
	cout<<"x2="<<x2<<endl;
	if(x2%8==0)x22=x2/8;
	else x22=x2/8+1;
//генерация ответа 
	ans[0]=':';
	ans[1]='0';
	ans[2]='1';
	ans[3]='0';
	ans[4]='1';
	int y[2];
	y[1]=x22%16;
    y[0]=x22/16;
	ans[5]=hex(y[0]);
	ans[6]=hex(y[1]);
	for(i=7;i<x22*2+7;i++) ans[i]='3';
for(i=0;i<x22*2+7;i++)
	{
		if(a[i]>47&&a[i]<58)a1[i]=ans[i]-48;
		else a1[i]=ans[i]-55;
	}
	LRC=0;
for(i=1;i<x22*2+7;i++)
	{
		if(i%2==0)LRC=LRC+a1[i];
		else LRC=LRC+a1[i]*16;
	}
	LRC=LRC%256;
	LRC=0xFF-LRC+1;
	cout<<"LRC="<<LRC<<endl;
	y[0]=LRC/16;
	y[1]=LRC-y[0]*16;
	ans[x22*2+7]=hex(y[0]);
	ans[x22*2+8]=hex(y[1]);/*
	for(i=0;i<x22*2+11;i++)
	{
		while((inportb(0x3FD%2)==0);
		outportb(0x3F8,ans[i]);
	}*/
      cout<<endl;	
}
}
}



#pragma once
#include "Base.h"
#include <math.h>
using namespace System::Drawing;
using namespace System;
class MyPoint: public Base
{ 
private:
	int x;
	int y;
public:
	MyPoint(int _x,int _y,string name):Base("TPoint",name)
	{
		x=_x;
		y=_y;
	}
	MyPoint(string _name,string _color,int _radius=0,bool _visible=true,int _x=0,int _y=0):Base("TPoint",_name,_color,_radius,_visible)
	{
		x=_x;
		y=_y;
	}
	MyPoint(const MyPoint &tmp):Base("TPoint")
	{
		name=tmp.name;
		color=tmp.color;
		radiusW=tmp.radiusW;
		radiusL=tmp.radiusL;
		visible=tmp.visible;
		rate=tmp.rate;
		x=tmp.x;
		y=tmp.y;
	}
	~MyPoint()
	{
	}
	MyPoint &operator=(const MyPoint &tmp)
	{
		color=tmp.color;
		radiusW=tmp.radiusW;
		radiusL=tmp.radiusL;
		visible=tmp.visible;
		rate=tmp.rate;
		x=tmp.x;
		y=tmp.y;
		return *this;
	}
	bool Distance(int _x,int _y)
	{
		if(sqrt(pow(x-_x,2)+pow(y-_y,2))<radiusL)
			return true;
		else
			return false;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void Move(int dx,int dy)
	{
		x+=dx;
		y+=dy;
	}
	void Draw(Graphics ^g)
	{
		if(visible==true)
		{
		String^ colname=gcnew String(color.c_str());
		Color clr=Color::FromName(colname);
		Pen^ mypen;
		if(clr==Color::Red)
		{
			mypen=gcnew Pen(clr,5);
		}
		else
		{
			mypen=gcnew Pen(clr);
		}
		g->DrawEllipse(mypen,x-radiusW,y-radiusW,radiusW*2,radiusW*2);
		}
	}
	void SetRateUp()
	{
		rate++;
	}
	void SetRateDown()
	{
		rate--;
	}
	MyPoint StrToPoint(string str)
	{
		string w[7]= {"","","","","","",""};
		string cstr=str;
		int k=cstr.find("&&");
		string valuecsr=str.substr(0,k);
		cstr.erase(0,k);
		w[0]=valuecsr;
		k=cstr.find("&&");
		valuecsr=str.substr(0,k);
		w[1]=valuecsr;
		k=cstr.find("&&");
		valuecsr=str.substr(0,k);
		w[2]=valuecsr;
		k=cstr.find("&&");
		valuecsr=str.substr(0,k);
		w[3]=valuecsr;
		k=cstr.find("&&");
		valuecsr=str.substr(0,k);
		w[4]=valuecsr;
		k=cstr.find("&&");
		valuecsr=str.substr(0,k);
		w[5]=valuecsr;
		MyPoint res(w[0],w[1],(atoi)(w[2].c_str()),(atoi)(w[3].c_str()),(atoi)(w[4].c_str()),(atoi)(w[5].c_str()));
		return res;
	}
	MyPoint(string str):Base("TPoint")
	{
		string w[7]= {"","","","","","",""};
		string cstr=str;
		int k=cstr.find("&&");
		string valuecsr=cstr.substr(0,k);
		cstr.erase(0,k+2);
		w[0]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k+2);
		w[1]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k+2);
		w[2]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k+2);
		w[3]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k+2);
		w[4]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k+2);
		w[5]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k);
		w[6]=valuecsr;
		name=w[0];
		color=w[1];
		rate=(atoi)(w[2].c_str());
		radiusW=(atoi)(w[3].c_str());
		radiusL=3*radiusW;
		if(w[4]=="True")
		{
			visible=true;
		}
		else
		{
			visible=false;
		}
		x=(atoi)(w[5].c_str());
		y=(atoi)(w[6].c_str());
	}
	string PointToString()
	{
		string str="TPoint&&";
		str=str+name;
		String^ rad=radiusW.ToString();
		string srad;
		String^ vis;
		string svis;
		String^ wra=radiusW.ToString();
		string swra;
		String^ xis=x.ToString();
		String^ yis=y.ToString();
		string xres;
		string yres;
		rad=rate.ToString();
		MarshalString(xis,xres);
		MarshalString(yis,yres);
		MarshalString(rad,srad);
		vis=visible.ToString();
		MarshalString(vis,svis);
		MarshalString(wra,swra);
		str=str+"&&"+color+"&&"+srad+"&&"+swra+"&&"+svis+"&&"+xres+"&&"+yres;
		return str;
	}
	void SetX(int _x)
	{
		x=_x;
	}
	void SetY(int _y)
	{
		y=_y;
	}


};


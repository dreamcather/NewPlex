#pragma once
#include "Base.h"
#include "MyLine.h"
class MyLine:public Base
{
private:
	Base* left;
	Base* right;
public:
	MyLine(Base* _left,Base* _right):Base("TLine")
	{
		left=_left;
		right=_right;
		name=_left->GetName()+" "+_right->GetName();
		radiusW=_left->GetWidht();
		radiusL=3*radiusW;
		visible=true;
		color=_left->GetColor();
	}
	MyLine(const MyLine &tmp):Base("Line",tmp.name)
	{
		left=tmp.left;
		right=tmp.right;
		name=tmp.name;
	}
	~MyLine()
	{
	}
	MyLine &operator =(const MyLine &tmp)
	{
		left=tmp.left;
		right=tmp.right;
		name=tmp.name;
		return *this;
	}
	string MyLineToString()
	{
		string str="TLine&&";
		str=str+name;
		String^ rad;
		string srad;
		String^ wra=radiusW.ToString();
		string swra;
		String^ vis;
		string svis;
		rad=rate.ToString();
		vis=visible.ToString();
		MarshalString(rad,srad);
		MarshalString(vis,svis);
		MarshalString(wra,swra);
		str=str+"&&"+color+"&&"+srad+"&&"+swra+"&&"+svis+"&&";
		return str;
	}
	MyLine(string str,Base *_left,Base *_right):Base("TLine")
	{
		string w[5]= {"","","","",""};
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
		w[4]=valuecsr;
		k=cstr.find("&&");
		valuecsr=cstr.substr(0,k);
		cstr.erase(0,k);
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
		left=_left;
		right=_right;
	}
	Base* GetLeft()
	{
		return left;
	}
	Base* GetRight()
	{
		return right;
	}
	void ChangeRate()
	{
		if(rate<3)
		{
			rate++;
		}
		else
			rate=1;
	}
	void SetLeft(Base* tmp)
	{
		left=tmp;
	}
	void SetRight(Base* tmp)
	{
		right=tmp;
	}
};


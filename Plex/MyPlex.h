#pragma once
#include "Base.h"
#include "MyPoint.h"
#include "MyLine.h"
#include <stack>
#include <iostream> 
#include <fstream>
class MyPlex
{
private:
	Base* start;
	int count;
public:

	MyPlex(Base* _start=NULL)
	{
		start=_start;
		count=0;
	}
	MyPlex(string path)
	{
		start=Open(path);
	}
	~MyPlex()
	{

	}
	Base* FindPoint(string name)
	{
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		Base * res=NULL;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
				if(current->GetName()==name)
				{
					res = current;
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
				}
				else
				{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					((MyLine*)current)->ChangeRate();
				}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						current=(Base*)lstack.top();
						lstack.pop();
						if(current!=NULL)
						((MyLine*)current)->ChangeRate();
						break;
					}
				default:
					break;
				}
			}
		}
		return res;
	}
	Base* FindPointP(string name)
	{
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		Base * res=start;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
				if(current->GetName()==name)
				{
					res = lstack.top();
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					((MyLine*)current)->ChangeRate();
				}
				else
				{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					((MyLine*)current)->ChangeRate();
				}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						current=(Base*)lstack.top();
						lstack.pop();
						if(current!=NULL)
						((MyLine*)current)->ChangeRate();
						break;
					}
				default:
					break;
				}
			}
		}
		return res;
	}
	Base* FindPoint(int x,int y)
	{
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		Base * res=NULL;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
				if(((MyPoint*)current)->Distance(x,y))
				{
					res = current;
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
				}
				else
				{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					((MyLine*)current)->ChangeRate();
				}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						current=(Base*)lstack.top();
						lstack.pop();
						if(current!=NULL)
						((MyLine*)current)->ChangeRate();
						break;
					}
				default:
					break;
				}
			}
		}
		return res;
	}
	string GenerateName()
	{
		int k=count/26;
		int l=count%26;
		string res="";
		for(int i=0;i<k;i++)
		{
			res=res+"A";
		}
		char let=(char)(65+l);
		res=res+let;
		count++;
		return res;
	}
	void AddLine(Base* point,int x,int y)
	{
		Base* left=FindPoint(point->GetName());
		if(left!=NULL)
		{
		MyPoint* right=new MyPoint(x,y,GenerateName());
		Base* res=(Base*)(new MyLine((Base*)left,(Base*)right));
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
				if(current->GetName()==(((MyLine*)res)->GetLeft()->GetName()))
				{
					current=res;
					current=lstack.top();
					if(current!=NULL)
					{
					if(current->GetRate()==1)
					{
						((MyLine*)current)->SetLeft(res);
					}
					else
					{
						((MyLine*)current)->SetRight(res);
					}
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
					}
					else
					{
						start=res;
					}

				}
				else
				{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					((MyLine*)current)->ChangeRate();
				}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						current=(Base*)lstack.top();
						lstack.pop();
						if(current!=NULL)
						{
						((MyLine*)current)->ChangeRate();
						}
						break;
					}
				default:
					break;
				}
			}
		}
		}
		}
	void AddPoint(int x,int y)
	{
		MyPoint* copy=new MyPoint(x,y,GenerateName());
		Base* res =(Base*)(copy);
		start=res;
	}
	bool IsEmpty()
	{
		if(start==NULL)
			return true;
		else
			return false;
	}
	void DrawLine(Graphics^ g,MyLine * line,MyPoint* left,MyPoint* right)
	{

		if(line->GetVisible()==true)
		{
		String^ colname=gcnew String(line->GetColor().c_str());
		Color clr=Color::FromName(colname);
		Pen^ mypen=gcnew Pen(clr);
		Point lf(left->GetX(),left->GetY());
		Point rh(right->GetX(),right->GetY());
		g->DrawLine(mypen,lf,rh);
		}
	}
	void DrawPlex(Graphics^ g)
	{
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		Base * res;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
				((MyPoint*)current)->Draw(g);
				pstack.push((MyPoint*)current);
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						string nmes=current->GetName();
						MyLine* copys=(MyLine*)current;
					    nmes=copys->GetName();
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						MyPoint* lf=pstack.top();
						pstack.pop();
						MyPoint* rh=pstack.top();
						//pstack.pop();
						DrawLine(g,(MyLine*)current,lf,rh);
						((MyLine*)current)->ChangeRate();
						current=(Base*)lstack.top();
						if(current!=NULL)
						{
						((MyLine*)current)->ChangeRate();
						}
						lstack.pop();
						break;
					}
				default:
					break;
				}
			}
	}
	}
	void Save(string path)
	{
		FILE *file = fopen(path.c_str(), "w");
		if (file)
		{
			stack<MyLine*> lstack;
			stack<MyPoint*> pstack;
			lstack.push(NULL);
			Base *current=start;Base * res;
			while(current!=NULL)
			{
				if(current->GetFigures()=="TPoint")
				{
					fputs(((MyPoint*)current)->PointToString().c_str(),file);
					fputs("\n",file);
					pstack.push((MyPoint*)current);
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
				}
				else
				{
					switch (current->GetRate())
					{
					case 1:
						{
							lstack.push((MyLine*)current);
							MyLine* copys=(MyLine*)current;
							current=((MyLine*)current)->GetLeft();
							break;
						}
					case 2:
						{
							lstack.push((MyLine*)current);
							current=((MyLine*)current)->GetRight();
							break;
						}
					case 3:
						{
							((MyLine*)current)->ChangeRate();
							fputs(((MyLine*)current)->MyLineToString().c_str(),file);
							fputs("\n",file);
							current=(Base*)lstack.top();
							if(current!=NULL)
							{
								((MyLine*)current)->ChangeRate();
							}
							lstack.pop();
							break;
						}
					default:
						break;
					}
				}
			}
		}
		fclose(file);
	}
	Base* Open(string path)
	{
		ifstream file(path,ios::in);
		count=0;
		start=NULL;
		string str;
		stack<Base*> bstack;
		if (file.is_open())
		{
			while(!file.eof())
			{
				getline(file, str);
				cout<<str<<endl;
				if(str.length()!=0)
				{
				if((str.find("TPoint")>=0)&&((str.find("TPoint")<str.length())))
				{
					str.erase(0,8);
					MyPoint * point=new MyPoint(str);
					count++;
					bstack.push((Base*)point);
				}
				else
				{
					str.erase(0,7);
					Base* right=bstack.top();
					bstack.pop();
					Base* left=bstack.top();
					bstack.pop();
					MyLine* line = new MyLine(str,left,right);
					bstack.push((Base*)line);
				}
			}
			}
			file.close();
			start=bstack.top();
		}
		return start;
	}
	int GetCount()
	{
		return count;
	}
	int CountLine()
	{
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		int k=0;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						string nmes=current->GetName();
						MyLine* copys=(MyLine*)current;
					    nmes=copys->GetName();
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						k++;
						current=(Base*)lstack.top();
						if(current!=NULL)
						{
						((MyLine*)current)->ChangeRate();
						}
						lstack.pop();
						break;
					}
				default:
					break;
				}
			}
	}
		return k;
	}
	Base* FindLine(string name)
	{
		
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		Base* res;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						string nmes=current->GetName();
						MyLine* copys=(MyLine*)current;
					    nmes=copys->GetName();
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						if(current->GetName()==name)
							res=current;
						current=(Base*)lstack.top();
						if(current!=NULL)
						{
						((MyLine*)current)->ChangeRate();
						}
						lstack.pop();
						break;
					}
				default:
					break;
				}
			}
	}
		return res;
	}
	Base* NumLine(int n)
	{
		stack<MyLine*> lstack;
		stack<MyPoint*> pstack;
		lstack.push(NULL);
		Base *current=start;
		Base* res;
		int k=0;
		while(current!=NULL)
		{
			if(current->GetFigures()=="TPoint")
			{
					current=(Base*)lstack.top();
					lstack.pop();
					if(current!=NULL)
					{
					((MyLine*)current)->ChangeRate();
					}
			}
			else
			{
				switch (current->GetRate())
				{
				case 1:
					{
						lstack.push((MyLine*)current);
						string nmes=current->GetName();
						MyLine* copys=(MyLine*)current;
					    nmes=copys->GetName();
						current=((MyLine*)current)->GetLeft();
						break;
					}
				case 2:
					{
						lstack.push((MyLine*)current);
						current=((MyLine*)current)->GetRight();
						break;
					}
				case 3:
					{
						((MyLine*)current)->ChangeRate();
						if(n==k)
							res=current;
						k++;
						current=(Base*)lstack.top();
						if(current!=NULL)
						{
						((MyLine*)current)->ChangeRate();
						}
						lstack.pop();
						break;
					}
				default:
					break;
				}
			}
	}
		return res;
	}
};


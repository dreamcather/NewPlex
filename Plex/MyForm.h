#pragma once
#include "MyPlex.h"


namespace Plex {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			left=Point(-1,-1);
			right=Point(-1,-1);
			iplex = gcnew Bitmap(200,200);
			clear=iplex;
			changeplex=iplex;
			plex=new MyPlex;
			flag=false;
			change=false;
			dataGridView1->ColumnCount=4;
			dataGridView1->Columns[0]->HeaderCell->Value="Èìÿ";
			dataGridView1->Columns[1]->HeaderCell->Value="Âèäèìîñòü";
			dataGridView1->Columns[2]->HeaderCell->Value="X";
			dataGridView1->Columns[3]->HeaderCell->Value="Y";
			dataGridView2->ColumnCount=2;
			dataGridView2->Columns[0]->HeaderCell->Value="Èìÿ";
			dataGridView2->Columns[1]->HeaderCell->Value="Âèäèìîñòü";
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Òğåáóåòñÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;
		Point left;
		MyPlex* plex;
		Base* changep;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
		Point right;
		Bitmap^ iplex;
		Bitmap^ clear;
		Bitmap^ changeplex;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñîõğàíèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  íîâûéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòêğûòüToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
			 bool flag;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
			 bool change;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà - íå èçìåíÿéòå
		/// ñîäåğæèìîå äàííîãî ìåòîäà ïğè ïîìîùè ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîõğàíèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íîâûéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 37);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove_1);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ôàéëToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(583, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ñîõğàíèòüToolStripMenuItem, 
				this->íîâûéToolStripMenuItem, this->îòêğûòüToolStripMenuItem});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// ñîõğàíèòüToolStripMenuItem
			// 
			this->ñîõğàíèòüToolStripMenuItem->Name = L"ñîõğàíèòüToolStripMenuItem";
			this->ñîõğàíèòüToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->ñîõğàíèòüToolStripMenuItem->Text = L"Ñîõğàíèòü";
			this->ñîõğàíèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîõğàíèòüToolStripMenuItem_Click);
			// 
			// íîâûéToolStripMenuItem
			// 
			this->íîâûéToolStripMenuItem->Name = L"íîâûéToolStripMenuItem";
			this->íîâûéToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->íîâûéToolStripMenuItem->Text = L"Íîâûé";
			this->íîâûéToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::íîâûéToolStripMenuItem_Click);
			// 
			// îòêğûòüToolStripMenuItem
			// 
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòêğûòüToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(236, 37);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(240, 127);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::dataGridView1_MouseDoubleClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(482, 37);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Change";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(236, 191);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(240, 127);
			this->dataGridView2->TabIndex = 4;
			this->dataGridView2->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::dataGridView2_MouseDoubleClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(583, 348);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:void MarshalString ( String ^ s, string& os ) 
		{  
   using namespace Runtime::InteropServices;  
   const char* chars =   
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
   os = chars;  
   Marshal::FreeHGlobal(IntPtr((void*)chars));  
}
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
			 {
				 if(change)
				 {
					 int x=e->X;
					 int y=e->Y;
					 if(changep==NULL)
					 {
					 changep = plex->FindPoint(x,y);
					 if(changep!=NULL)
					 {
						 left.X=((MyPoint*)changep)->GetX();
						 left.Y=((MyPoint*)changep)->GetY();
					 }
					 }

				 }
				 else
				 {
				 if(plex->IsEmpty())
				 {
				 int x=e->X;
				 int y=e->Y;
				 plex->AddPoint(x,y);
				 left=Point(x,y);
				 changeplex=iplex;
				 Graphics^ g=Graphics::FromImage(iplex);
				 plex->DrawPlex(g);
				 ChangeTable();
				 ChangeTableLine();
				 pictureBox1->Image=changeplex;
				 pictureBox1->Refresh();
				 iplex=changeplex;
				 }
				 else
				 {
					 int x=e->X;
					 int y=e->Y;
					 Base* res = plex->FindPoint(x,y);
					 if(res!=NULL)
					 {
						 left.X=((MyPoint*)res)->GetX();
						 left.Y=((MyPoint*)res)->GetY();
						 if((left.X==dataGridView1->CurrentRow->Cells[2]->Value)&&(left.Y==dataGridView1->CurrentRow->Cells[3]->Value))
						 {
							 right.X=((MyPoint*)res)->GetX();
							 right.Y=((MyPoint*)res)->GetY();

						 }

					 }
				 }
				 }
			 }
private: System::Void pictureBox1_MouseMove_1(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if((change)&&(flag))
			 {
				 right.X=e->X;
				 right.Y=e->Y;
				 pictureBox1->Image=iplex;
				 pictureBox1->Refresh();
				 Graphics^ g=pictureBox1->CreateGraphics();
				 g->DrawEllipse(Pens::Yellow,right.X-5,right.Y-5,10,10);
				 plex->DrawPlex(g);
			 }
			 else
			 {
			 if((flag)&&(left.X!=-1))
				 {
						 right.X=e->X;
						 right.Y=e->Y;
						 Base* cur=plex->FindPoint(right.X,right.Y);
						 if(cur!=NULL)
						 {
							 right.X=((MyPoint*)cur)->GetX();
							 right.Y=((MyPoint*)cur)->GetY();
						 }
						 pictureBox1->Image=iplex;
						 pictureBox1->Refresh();
						 Graphics^ g=pictureBox1->CreateGraphics();
						 g->DrawLine(Pens::Black,left.X,left.Y,right.X,right.Y);
				 }
			 }
		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if(change)
			 {
				 left.X=e->X;
				 left.Y=e->Y;
				 changep=plex->FindPoint(left.X,left.Y);
				 if(changep!=NULL)
				 {
				 Graphics^ g=pictureBox1->CreateGraphics();
				 g->DrawEllipse(Pens::Yellow,left.X-5,left.Y-5,10,10);
				 flag=true;
				 }
			 }
			 else
			 {
			 if(left.X!=-1)
				 {
						 right.X=e->X;
						 right.Y=e->Y;
						 Base* cur=plex->FindPoint(right.X,right.Y);
						 if(cur!=NULL)
						 {
							 right.X=((MyPoint*)cur)->GetX();
							 right.Y=((MyPoint*)cur)->GetY();
						 }
						 pictureBox1->Image=iplex;
						 pictureBox1->Refresh();
						 Graphics^ g=pictureBox1->CreateGraphics();
						 g->DrawLine(Pens::Black,left.X,left.Y,right.X,right.Y);
						 flag=true;
				 }
			 }
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if(change)
			 {
				 int x=e->X;
				 int y=e->Y;
				 Base* chec=plex->FindPoint(x,y);
				 if(chec!=NULL)
				 {
					 x=((MyPoint*)chec)->GetX();
					 y=((MyPoint*)chec)->GetY();
				 }
				 ((MyPoint*)changep)->SetX(x);
				 ((MyPoint*)changep)->SetY(y);
				 iplex=gcnew Bitmap(200,200);
				 Graphics^ g=Graphics::FromImage(iplex);
				 plex->DrawPlex(g);
				 ChangeTable();
				 ChangeTableLine();
				 pictureBox1->Image=iplex;
				 pictureBox1->Refresh();
				 left.X=-1;
				 right.X=-1;
				 flag=false;
				 change=false;
				 changep=NULL;
			 }
			 else
			 {
			 if(right.X!=-1)
			 {
				 int x=e->X;
				 int y=e->Y;
				 Base* cur=plex->FindPoint(right.X,right.Y);
						 if(cur!=NULL)
						 {
							 x=((MyPoint*)cur)->GetX();
							 y=((MyPoint*)cur)->GetY();
						 }
				 Base* res = plex->FindPoint(left.X,left.Y);
				 plex->AddLine(res,x,y);
				 Graphics^ g=Graphics::FromImage(iplex);
				 plex->DrawPlex(g);
				 ChangeTable();
				 ChangeTableLine();
				 pictureBox1->Image=iplex;
				 pictureBox1->Refresh();
				 left.X=-1;
				 right.X=-1;
				 flag=false;
				 change=false;
			 }
			 }
		 }
private: System::Void ñîõğàíèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			String^ spath;
			string path;
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
            if(dialog->ShowDialog()==System::Windows::Forms::DialogResult::OK)
            {
				spath = dialog->FileName;
            }
			MarshalString(spath,path);
			plex->Save(path);
		 }
private: System::Void íîâûéToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pictureBox1->Image=gcnew Bitmap(200,200);
			 iplex=gcnew Bitmap(200,200);
			 pictureBox1->Refresh();
			 plex=new MyPlex();
			 ChangeTable();
			 ChangeTableLine();
		 }
private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ spath;
			 string path;
			 OpenFileDialog^ dialog = gcnew OpenFileDialog();
			 if(dialog->ShowDialog()==System::Windows::Forms::DialogResult::OK)
			 {
				 spath = dialog->FileName;
			 }
			 MarshalString(spath,path);
			 plex=new MyPlex(path);
			  iplex=gcnew Bitmap(200,200);
			 Graphics^ g=Graphics::FromImage(iplex);
			 plex->DrawPlex(g);
			 ChangeTable();
			 ChangeTableLine();
			 pictureBox1->Image=iplex;
				 pictureBox1->Refresh();
				 left.X=-1;
				 right.X=-1;
				 flag=false;


		 }
private:string GenerateName(int count)
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
private:void ChangeTable()
		{
			string name;
			int k=plex->GetCount();
			int n=0;
			while (dataGridView1->RowCount != 0)
			{
				n=dataGridView1->RowCount;
				dataGridView1->Rows->RemoveAt(0);
			}
			for(int i=0;i<k;i++)
			{
				name=GenerateName(i);
				Base* res =plex->FindPoint(name);
				n=dataGridView1->RowCount;
				dataGridView1->RowCount++;
				String^ str2 = gcnew String(((MyPoint*)res)->GetName().c_str());
				dataGridView1->Rows[n]->Cells[0]->Value=str2;
				dataGridView1->Rows[n]->Cells[1]->Value=((MyPoint*)res)->GetVisible().ToString();
				dataGridView1->Rows[n]->Cells[2]->Value=((MyPoint*)res)->GetX().ToString();
				dataGridView1->Rows[n]->Cells[3]->Value=((MyPoint*)res)->GetY().ToString();
				
			}
		}
private:void ChangeTableLine()
		{
			string name;
			Base* current;
			int k=plex->CountLine();
			int n=0;
			while (dataGridView2->RowCount != 0)
			{
				n=dataGridView2->RowCount;
				dataGridView2->Rows->RemoveAt(0);
			}
			for(int i=0;i<k;i++)
			{
				current=plex->NumLine(i);
				n=dataGridView2->RowCount;
				dataGridView2->RowCount++;
				String^ str2 = gcnew String(((MyPoint*)current)->GetName().c_str());
				dataGridView2->Rows[n]->Cells[0]->Value=str2;
				dataGridView2->Rows[n]->Cells[1]->Value=((MyPoint*)current)->GetVisible().ToString();
			}
		}
private: System::Void dataGridView1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 String^ cname=(dataGridView1->CurrentRow->Cells[0]->Value)->ToString();
			 string name;
			 MarshalString(cname,name);
			 Base* res=plex->FindPoint(name);
			 ((MyPoint*)res)->SetColor("Red");
			 iplex=gcnew Bitmap(200,200);
			 Graphics^ g=Graphics::FromImage(iplex);
			 plex->DrawPlex(g);
			 pictureBox1->Image=iplex;
			 pictureBox1->Refresh();
			 ((MyPoint*)res)->SetColor("Black");
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 change=true;
		 }
private: System::Void dataGridView2_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 string name;
			 bool resb;
			 if((dataGridView2->CurrentRow->Cells[1]->Value)->ToString()=="True")
				 resb=true;
			 else
				 resb=false;
			 String^ cname=(dataGridView2->CurrentRow->Cells[0]->Value)->ToString();
			 if(resb)
				 dataGridView2->CurrentRow->Cells[1]->Value="False";
			 else
				 dataGridView2->CurrentRow->Cells[1]->Value="True";
			 MarshalString(cname,name);
			 Base* res=plex->FindLine(name);
			 res->SetVisible(!resb);
			 iplex=gcnew Bitmap(200,200);
			 Graphics^ g=Graphics::FromImage(iplex);
			 plex->DrawPlex(g);
			 pictureBox1->Image=iplex;
			 pictureBox1->Refresh();

		 }
};
}
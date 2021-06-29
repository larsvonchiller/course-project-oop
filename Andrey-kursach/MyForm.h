#pragma once
#include <time.h>
namespace Andreykursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	class Cylinder
	{
	public:
		double R, H;
		Cylinder()
		{
			Random rnd;

			R = rnd.Next(50) + 1;
			H = rnd.Next(50) + 1;
		}
		Cylinder(double a, double b)
		{
			R = a;
			H = b;
		}

		void Metod1(RichTextBox ^rtb)
		{
			rtb->Text = "\nR=" + Convert::ToString(R) + "\nH=" + Convert::ToString(H) + "\nS=" + Convert::ToString(2 * Math::PI*R*(R + H));
		}
	};

	class Cylinder2 :public Cylinder
	{
	public:
		int K;
		Cylinder2()
		{
			Random rnd;

			K = rnd.Next(50) + 1;
		}
		Cylinder2(double a, double b, int c) :Cylinder(a, b)
		{
			K = c;
		}

		void Metod2(RichTextBox ^rtb)
		{
			rtb->Text = "\nR=" + Convert::ToString(R) + "\nH=" + Convert::ToString(H) + "\nKol=" + Convert::ToString(K) + "\nS * K=" + Convert::ToString((2 * Math::PI*R*(R + H)) * K);
		}
	};

	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  TbR;
	private: System::Windows::Forms::TextBox^  TbH;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  TbKOl;

	private: System::Windows::Forms::Label^  TbK;
	private: System::Windows::Forms::Button^  btnS;
	private: System::Windows::Forms::Button^  btnSK;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  RTBOutput;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TbR = (gcnew System::Windows::Forms::TextBox());
			this->TbH = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TbKOl = (gcnew System::Windows::Forms::TextBox());
			this->TbK = (gcnew System::Windows::Forms::Label());
			this->btnS = (gcnew System::Windows::Forms::Button());
			this->btnSK = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->RTBOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Радиус окружности:";
			// 
			// TbR
			// 
			this->TbR->Location = System::Drawing::Point(129, 13);
			this->TbR->Name = L"TbR";
			this->TbR->Size = System::Drawing::Size(100, 20);
			this->TbR->TabIndex = 1;
			this->TbR->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::TbR_KeyPress);
			// 
			// TbH
			// 
			this->TbH->Location = System::Drawing::Point(129, 53);
			this->TbH->Name = L"TbH";
			this->TbH->Size = System::Drawing::Size(100, 20);
			this->TbH->TabIndex = 3;
			this->TbH->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::TbH_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Высота цилиндра:";
			// 
			// TbKOl
			// 
			this->TbKOl->Location = System::Drawing::Point(129, 98);
			this->TbKOl->Name = L"TbKOl";
			this->TbKOl->Size = System::Drawing::Size(100, 20);
			this->TbKOl->TabIndex = 5;
			this->TbKOl->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::TbKOl_KeyPress);
			// 
			// TbK
			// 
			this->TbK->AutoSize = true;
			this->TbK->Location = System::Drawing::Point(13, 98);
			this->TbK->Name = L"TbK";
			this->TbK->Size = System::Drawing::Size(101, 13);
			this->TbK->TabIndex = 4;
			this->TbK->Text = L"Кол-во цилиндров:";
			// 
			// btnS
			// 
			this->btnS->Location = System::Drawing::Point(16, 137);
			this->btnS->Name = L"btnS";
			this->btnS->Size = System::Drawing::Size(94, 23);
			this->btnS->TabIndex = 6;
			this->btnS->Text = L"Площадь";
			this->btnS->UseVisualStyleBackColor = true;
			this->btnS->Click += gcnew System::EventHandler(this, &MyForm::btnS_Click);
			// 
			// btnSK
			// 
			this->btnSK->Location = System::Drawing::Point(129, 137);
			this->btnSK->Name = L"btnSK";
			this->btnSK->Size = System::Drawing::Size(100, 23);
			this->btnSK->TabIndex = 7;
			this->btnSK->Text = L"Общая площадь";
			this->btnSK->UseVisualStyleBackColor = true;
			this->btnSK->Click += gcnew System::EventHandler(this, &MyForm::btnSK_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Output:";
			// 
			// RTBOutput
			// 
			this->RTBOutput->Location = System::Drawing::Point(19, 184);
			this->RTBOutput->Name = L"RTBOutput";
			this->RTBOutput->Size = System::Drawing::Size(210, 138);
			this->RTBOutput->TabIndex = 9;
			this->RTBOutput->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 345);
			this->Controls->Add(this->RTBOutput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnSK);
			this->Controls->Add(this->btnS);
			this->Controls->Add(this->TbKOl);
			this->Controls->Add(this->TbK);
			this->Controls->Add(this->TbH);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->TbR);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnS_Click(System::Object^  sender, System::EventArgs^  e) {
		if (TbR->Text == "" || TbH->Text=="")
		{
			Cylinder obj;

			obj.Metod1(RTBOutput);
		}
		else
		{
			Cylinder obj(Convert::ToDouble(TbR->Text),Convert::ToDouble(TbH->Text));

			obj.Metod1(RTBOutput);
		}
	}
	private: System::Void btnSK_Click(System::Object^  sender, System::EventArgs^  e) {
		if (TbR->Text == "" || TbH->Text == "" || TbK->Text == "")
		{
			Cylinder2 obj;

			obj.Metod2(RTBOutput);
		}
		else
		{
			Cylinder2 obj(Convert::ToDouble(TbR->Text), Convert::ToDouble(TbH->Text),Convert::ToInt32(TbKOl->Text));

			obj.Metod2(RTBOutput);
		}
	}
private: System::Void TbR_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	char number = e->KeyChar;
	if ((e->KeyChar <= 47 || e->KeyChar >= 58) && number != 8 && number != 44) //цифры, клавиша BackSpace и запятая а ASCII 
	{
		e->Handled = true;
	}
}
private: System::Void TbH_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	char number = e->KeyChar;
	if ((e->KeyChar <= 47 || e->KeyChar >= 58) && number != 8 && number != 44) //цифры, клавиша BackSpace и запятая а ASCII 
	{
		e->Handled = true;
	}
}
private: System::Void TbKOl_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	char number = e->KeyChar;
	if ((e->KeyChar <= 47 || e->KeyChar >= 58) && number != 8) //цифры, клавиша BackSpace и запятая а ASCII 
	{
		e->Handled = true;
	}
}
};
}


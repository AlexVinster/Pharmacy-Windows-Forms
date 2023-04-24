#pragma once
#include "Add_E.h"
#include "Add_PH.h"
#include "Add_PR.h"
#include "Add_PRO.h"
#include "Add_SP.h"
#include "Employees.h"
#include "Pharmacy.h"
#include "Preparation.h"
#include "Producer.h"
#include "About_Creator.h"
#include "Sound.h"
#include "Supplied_Preparation.h"
#include <Windows.h>


namespace Pharmacy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
		{
			InitializeComponent();
			Sounds^ sounds = gcnew Sounds();
			sounds->Welcome();
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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ creatorToolStripMenuItem;


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creatorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::LemonChiffon;
			this->button1->Location = System::Drawing::Point(12, 161);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(207, 87);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Працівники";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::LemonChiffon;
			this->button2->Location = System::Drawing::Point(251, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(207, 87);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Аптека";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::Color::LemonChiffon;
			this->button3->Location = System::Drawing::Point(12, 283);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(207, 87);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Препарат";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button4->ForeColor = System::Drawing::Color::LemonChiffon;
			this->button4->Location = System::Drawing::Point(251, 283);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(207, 87);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Виробник";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::Color::LemonChiffon;
			this->button5->Location = System::Drawing::Point(520, 324);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(276, 118);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Вихід";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button6->ForeColor = System::Drawing::Color::LemonChiffon;
			this->button6->Location = System::Drawing::Point(520, 161);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(207, 87);
			this->button6->TabIndex = 17;
			this->button6->Text = L"Поставщик";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem1 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(808, 24);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->creatorToolStripMenuItem });
			this->aboutToolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->aboutToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem1.Image")));
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(68, 20);
			this->aboutToolStripMenuItem1->Text = L"About";
			this->aboutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem1_Click);
			// 
			// creatorToolStripMenuItem
			// 
			this->creatorToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"creatorToolStripMenuItem.Image")));
			this->creatorToolStripMenuItem->Name = L"creatorToolStripMenuItem";
			this->creatorToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->creatorToolStripMenuItem->Text = L"Creator";
			this->creatorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::creatorToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(808, 454);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Аптека";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Click();
		Employees^ form = gcnew Employees();
		form->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Click();
		Pharmacy^ form = gcnew Pharmacy();
		form->ShowDialog();
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	Preparation^ form = gcnew Preparation();
	form->ShowDialog();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	Producer^ form = gcnew Producer();
	form->ShowDialog();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Stop();
	Sleep(250);
	this->Close();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	Supplied_Preparation^ form = gcnew Supplied_Preparation();
	form->ShowDialog();
}
private: System::Void creatorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	About_Creator^ form = gcnew About_Creator();
	form->ShowDialog();
}
private: System::Void aboutToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
}
};
}

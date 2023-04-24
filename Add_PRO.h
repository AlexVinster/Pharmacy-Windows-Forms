#pragma once
#include <Windows.h>
#include <vcclr.h>
#include "Sound.h"

namespace Pharmacy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::IO;
	using namespace System::Data::SqlServerCe;


	/// <summary>
	/// Summary for Profit
	/// </summary>
	public ref class Add_PRO : public System::Windows::Forms::Form
	{
		System::Data::SqlServerCe::SqlCeConnection^ connect;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
		   int pId;
	public:
		Add_PRO(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Add_PRO(int pId) {
			InitializeComponent();
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf;";
			connect = gcnew SqlCeConnection("Data Source=Apteka.sdf;");
			connect->Open();

			this->pId = pId;
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Producer WHERE [id]=@pId";
			command->Parameters->AddWithValue("@pId", pId);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			while (sqlRead->Read()) {
				textBox1->Text = System::Convert::ToString(sqlRead["Name"]),
					textBox2->Text = System::Convert::ToString(sqlRead["Address"]),
					textBox3->Text = System::Convert::ToString(sqlRead["Contacts"]),
					textBox4->Text = System::Convert::ToString(sqlRead["Email"]);
			}
			connect->Close();
			sqlRead->Close();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_PRO()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Add_PRO::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(122, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 24);
			this->label3->TabIndex = 64;
			this->label3->Text = L"Назва";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(55, 212);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(230, 26);
			this->textBox3->TabIndex = 63;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Add_PRO::textBox3_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(53, 90);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(230, 26);
			this->textBox1->TabIndex = 67;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Add_PRO::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(119, 129);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 24);
			this->label1->TabIndex = 69;
			this->label1->Text = L"Адрес";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(233, 365);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 70);
			this->button2->TabIndex = 73;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Add_PRO::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 365);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 70);
			this->button1->TabIndex = 72;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Add_PRO::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(110, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 24);
			this->label4->TabIndex = 75;
			this->label4->Text = L"Контакт";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(53, 156);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(230, 26);
			this->textBox2->TabIndex = 76;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Add_PRO::textBox2_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(55, 281);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(230, 26);
			this->textBox4->TabIndex = 78;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Add_PRO::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(69, 254);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(194, 24);
			this->label5->TabIndex = 77;
			this->label5->Text = L"Електронна пошта";
			// 
			// Add_PRO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Green;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(329, 454);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Add_PRO";
			this->Text = L"Виробник";
			this->Load += gcnew System::EventHandler(this, &Add_PRO::Add_PRO_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Add_PRO_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void insert() {
		connect->Open();
		String^ query = "INSERT INTO Producer([Name],[Address],[Contacts],[Email])" +
			"VALUES('" + textBox1->Text + "','" + textBox2->Text +
			"','" + textBox3->Text + "','" + textBox4->Text + "');";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() > 0)
		{
			Sounds^ sounds = gcnew Sounds();
			sounds->Notification();
			MessageBox::Show("Запис додано.");
		}
		else { 
			Sounds^ sounds = gcnew Sounds();
			sounds->Error();
			MessageBox::Show("Введіть коректні дані."); 
		}
		connect->Close();
	}

	private: void update() {
		try
		{
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			String^ query = "UPDATE Producer SET [Name]='" + textBox1->Text + "', [Address]='" + textBox2->Text +
				"',[Contacts]='" + textBox3->Text + "',[Email]='" + textBox4->Text + "' WHERE [id]=" + this->pId + ";";
			command->CommandText = query;
			if (command->ExecuteNonQuery() == 0)
			{
				Sounds^ sounds = gcnew Sounds();
				sounds->Notification();
				MessageBox::Show("Запис оновлено.");
			}
		}

		finally
		{
			// Гарантировать освобождение подключения

			connect->Close();
		}
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Success();
	if (textBox1->Text->Length != 0 && textBox3->Text->Length != 0) {
		if (this->pId == -1) insert();
		else update();
		this->Close();
	}
	else {
		Sounds^ sounds = gcnew Sounds();
		sounds->Error();
		MessageBox::Show("Заповніть усі поля");
	}
}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Stop();
		Sleep(250);
		Close();
	}


private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
};
}

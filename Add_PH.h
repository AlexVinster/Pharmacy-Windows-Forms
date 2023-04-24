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
	/// Summary for Add_S
	/// </summary>
	public ref class Add_PH : public System::Windows::Forms::Form
	{
		System::Data::SqlServerCe::SqlCeConnection^ connect;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   int clId;
	public:
		Add_PH(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Add_PH(int clId) {
			InitializeComponent();
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf";
			connect = gcnew SqlCeConnection("Data Source=Apteka.sdf");
			connect->Open();

			this->clId = clId;
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Pharmacy WHERE [id]=@clId";
			command->Parameters->AddWithValue("@clId", clId);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			while (sqlRead->Read()) {
				textBox1->Text = System::Convert::ToString(sqlRead["Name"]);
				textBox2->Text = System::Convert::ToString(sqlRead["Address"]);
				maskedTextBox1->Text = System::Convert::ToString(sqlRead["Сontact_number"]);
				textBox3->Text = System::Convert::ToString(sqlRead["Open_24_hours"]);
				textBox4->Text = System::Convert::ToString(sqlRead["Work_time"]);
			}
			connect->Close();
			sqlRead->Close();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_PH()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Add_PH::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(101, 67);
			this->textBox1->MaximumSize = System::Drawing::Size(200, 25);
			this->textBox1->MinimumSize = System::Drawing::Size(200, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 24);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Add_PH::textBox1_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(148, 174);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 25);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Телефон";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(160, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 25);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Назва";
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
			this->button2->Location = System::Drawing::Point(374, 233);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 70);
			this->button2->TabIndex = 52;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Add_PH::button2_Click);
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
			this->button1->Location = System::Drawing::Point(284, 233);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 70);
			this->button1->TabIndex = 51;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Add_PH::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(417, 94);
			this->textBox3->MaximumSize = System::Drawing::Size(200, 25);
			this->textBox3->MinimumSize = System::Drawing::Size(200, 25);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 24);
			this->textBox3->TabIndex = 54;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Add_PH::textBox3_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(148, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 25);
			this->label2->TabIndex = 53;
			this->label2->Text = L"Адреса";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->maskedTextBox1->Location = System::Drawing::Point(101, 202);
			this->maskedTextBox1->Mask = L"(999) 000-0000";
			this->maskedTextBox1->MaximumSize = System::Drawing::Size(200, 25);
			this->maskedTextBox1->MinimumSize = System::Drawing::Size(200, 25);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(200, 24);
			this->maskedTextBox1->TabIndex = 55;
			this->maskedTextBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Add_PH::maskedTextBox1_MaskInputRejected);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(101, 135);
			this->textBox2->MaximumSize = System::Drawing::Size(200, 25);
			this->textBox2->MinimumSize = System::Drawing::Size(200, 25);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 24);
			this->textBox2->TabIndex = 57;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Add_PH::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(442, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 25);
			this->label3->TabIndex = 56;
			this->label3->Text = L"Працює 24/7";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(417, 163);
			this->textBox4->MaximumSize = System::Drawing::Size(200, 25);
			this->textBox4->MinimumSize = System::Drawing::Size(200, 25);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(200, 24);
			this->textBox4->TabIndex = 59;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Add_PH::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(442, 135);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(137, 25);
			this->label5->TabIndex = 58;
			this->label5->Text = L"Робочий час";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::SaddleBrown;
			this->pictureBox1->Location = System::Drawing::Point(101, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(524, 195);
			this->pictureBox1->TabIndex = 60;
			this->pictureBox1->TabStop = false;
			// 
			// Add_PH
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSalmon;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(706, 360);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Add_PH";
			this->Text = L"Аптека";
			this->Load += gcnew System::EventHandler(this, &Add_PH::Add_PH_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Add_PH_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		  private: void insert() {
			  connect->Open();
			  String^ query = "INSERT INTO Pharmacy([Name],[Address],[Сontact_number],[Open_24_hours],[Work_time])" +
				  "VALUES('" + textBox1->Text + "','" + textBox2->Text + "','" + maskedTextBox1->Text + "','" + textBox3->Text + "','" + textBox4->Text + "');";
			  SqlCeCommand^ command = connect->CreateCommand();
			  command->CommandText = query;
			  if (command->ExecuteNonQuery() == 0) {
				  Sounds^ sounds = gcnew Sounds();
				  sounds->Success();
				  MessageBox::Show("Добавлено!");
			  }
			  connect->Close();
		  }

	private: void update() {
		connect->Open();
		String^ query = "UPDATE Pharmacy SET [Name]='" + textBox1->Text +
			"',[Address]='" + textBox2->Text + "', [Сontact_number]='" + maskedTextBox1->Text + "', [Open_24_hours]='" + textBox3->Text + "', [Work_time]='" + textBox4->Text + "' WHERE [id]=" + this->clId + ";";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() == 0) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Success();
			MessageBox::Show("Оновлено!");
		}
		connect->Close();
	}

	 private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		 Sounds^ sounds = gcnew Sounds();
		 sounds->Success();
		if (textBox1->Text->Length != 0) {
			if (this->clId == -1) insert();
			else update();
			this->Close();
		}
		else {
			Sounds^ sounds = gcnew Sounds();
			sounds->Error();
			MessageBox::Show("Додайте більше даних");
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
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
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

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


	public ref class Add_E : public System::Windows::Forms::Form
	{
	System::Data::SqlServerCe::SqlCeConnection^ connect;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   int autoid;
	public:
		Add_E(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Add_E(int auId) {
			InitializeComponent();
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf";
			connect = gcnew SqlCeConnection("Data Source=Apteka.sdf");
			connect->Open();

			this->autoid = auId;
			int cCC;
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Employees WHERE [id]=@auId";
			command->Parameters->AddWithValue("@auId", auId);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			while (sqlRead->Read()) {
				textBox1->Text = System::Convert::ToString(sqlRead["full_Name"]);
				textBox2->Text = System::Convert::ToString(sqlRead["date_of_Birth"]);
				textBox3->Text = System::Convert::ToString(sqlRead["gender"]);
				textBox4->Text = System::Convert::ToString(sqlRead["identification_Code"]);
				maskedTextBox1->Text = System::Convert::ToString(sqlRead["card_id_Number"]);
				cCC = System::Convert::ToInt32(sqlRead["pharmacy"]);
			}
			connect->Close();
			sqlRead->Close();
			this->currComboBoxSetAddÑ(cCC);
		}
	
		void currComboBoxSetAddÑ(int id)
		{
			connect->Open();
			String^ query = "SELECT Name FROM pharmacy WHERE id LIKE '" + id + "';";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			bool hasRow = sqlRead->Read();
			if (hasRow)
			{
				comboBox1->Text = System::Convert::ToString(sqlRead["Name"]);
			}
			connect->Close();
			sqlRead->Close();
		}

		int GetSelectedGroupIndexForAddC()
		{
			int id;
			connect->Open();
			String^ query = "SELECT id FROM pharmacy WHERE Name LIKE '" + comboBox1->Text + "';";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			bool hasRow = sqlRead->Read();
			if (hasRow) {
				id = System::Convert::ToInt32(sqlRead["id"]);
			}
			connect->Close();
			sqlRead->Close();
			return id;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_E()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Add_E::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(119, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 25);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Ï²Á ïðàö³âíèêà";
			this->label1->Click += gcnew System::EventHandler(this, &Add_E::label1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(152, 222);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 25);
			this->label6->TabIndex = 52;
			this->label6->Text = L"Ñòàòü";
			this->label6->Click += gcnew System::EventHandler(this, &Add_E::label6_Click);
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
			this->button2->Location = System::Drawing::Point(545, 301);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 70);
			this->button2->TabIndex = 50;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Add_E::button2_Click);
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
			this->button1->Location = System::Drawing::Point(62, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 70);
			this->button1->TabIndex = 49;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Add_E::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(431, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(177, 25);
			this->label5->TabIndex = 48;
			this->label5->Text = L"Íîìåð ïàñïîðòà";
			this->label5->Click += gcnew System::EventHandler(this, &Add_E::label5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(55, 250);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(297, 31);
			this->textBox3->TabIndex = 47;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Add_E::textBox3_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(55, 188);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(297, 31);
			this->textBox2->TabIndex = 46;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Add_E::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(55, 121);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(297, 31);
			this->textBox1->TabIndex = 45;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Add_E::textBox1_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(38, 227);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 25);
			this->label4->TabIndex = 44;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(105, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(190, 25);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Äàòà íàðîäæåííÿ";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->maskedTextBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->maskedTextBox1->Location = System::Drawing::Point(382, 183);
			this->maskedTextBox1->Mask = L"000000000";
			this->maskedTextBox1->MaximumSize = System::Drawing::Size(297, 31);
			this->maskedTextBox1->MinimumSize = System::Drawing::Size(297, 31);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(297, 31);
			this->maskedTextBox1->TabIndex = 53;
			this->maskedTextBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->maskedTextBox1->ValidatingType = System::Int32::typeid;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Add_E::maskedTextBox1_MaskInputRejected);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(415, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(226, 25);
			this->label3->TabIndex = 55;
			this->label3->Text = L"²äåíòèô³êàö³éíèé êîä";
			this->label3->Click += gcnew System::EventHandler(this, &Add_E::label3_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(382, 121);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(297, 31);
			this->textBox4->TabIndex = 54;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Add_E::textBox4_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(382, 250);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(297, 33);
			this->comboBox1->TabIndex = 56;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Add_E::comboBox1_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(447, 222);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(161, 25);
			this->label7->TabIndex = 57;
			this->label7->Text = L"Ôàðìàöåâòèêà";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::OliveDrab;
			this->pictureBox1->Location = System::Drawing::Point(52, 86);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(626, 196);
			this->pictureBox1->TabIndex = 58;
			this->pictureBox1->TabStop = false;
			// 
			// Add_E
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(715, 376);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Add_E";
			this->Text = L"Ïðàö³âíèê";
			this->Load += gcnew System::EventHandler(this, &Add_E::Add_E_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void update() {
		int cCC = this->GetSelectedGroupIndexForAddC();
		connect->Open();
		String^ query = "UPDATE Employees SET [full_Name]='" + textBox1->Text +
			"', [date_of_Birth]='" + textBox2->Text + "', [gender]='" + textBox3->Text + "', [identification_Code]='" + textBox4->Text + "',[card_id_Number]='" + maskedTextBox1->Text +
			"', [pharmacy]=" + cCC + " WHERE [id]=" + this->autoid + ";";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() == 0) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Success();
			MessageBox::Show("Îíîâëåíî!");
		}
		connect->Close();
	}

	private: void insert() {
		int cCC = this->GetSelectedGroupIndexForAddC();
		connect->Open();
		String^ query = "INSERT INTO Employees([full_Name],[date_of_Birth],[gender],[identification_Code],[card_id_Number],[pharmacy])" +
			"VALUES('" + textBox1->Text + "','" + textBox2->Text + "','" + textBox3->Text + "','" + textBox4->Text + "','" + maskedTextBox1->Text + "'," + cCC + ");";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() == 0) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Success();
			MessageBox::Show("Äîáàâëåíî!");
		}
		connect->Close();
	}

	private: System::Void Add_E_Load(System::Object^ sender, System::EventArgs^ e) {
		connect->Open();
		SqlCeCommand^ command = gcnew SqlCeCommand("SELECT Name FROM pharmacy",
			connect);
		SqlCeDataReader^ sqlRead = command->ExecuteReader();
		while (sqlRead->Read()) {
			comboBox1->Items->Add(sqlRead["Name"]);
		}
		sqlRead->Close();
		connect->Close();
	}

	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Success();
	if (textBox1->Text->Length != 0 && textBox2->Text->Length != 0) {
		if (this->autoid == -1) insert();
		else update();
		this->Close();
	}
	else {
		Sounds^ sounds = gcnew Sounds();
		sounds->Error();
		MessageBox::Show("Add more data");
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Stop();
	Sleep(250);
	Close();
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	SoundPlayer^ player1 = gcnew SoundPlayer();
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
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
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
}
};
}

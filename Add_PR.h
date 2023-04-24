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
	using namespace System::Data::SqlClient;


	public ref class Add_PR : public System::Windows::Forms::Form
	{
	public:
		Add_PR(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Add_PR(int contId) {
			InitializeComponent();
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf;";
			connect = gcnew SqlCeConnection("Data Source=Apteka.sdf;");
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();

			this->contId = contId;
			int cCP;
			int cCC;
			command->CommandText = "SELECT * FROM Preparation WHERE [id]=@contId";
			command->Parameters->AddWithValue("@contId", contId);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			while (sqlRead->Read()) {
				textBox1->Text = System::Convert::ToString(sqlRead["preparation"]);;
				textBox2->Text = System::Convert::ToString(sqlRead["model"]);;
				textBox3->Text = System::Convert::ToString(sqlRead["active_Substances"]);;
				textBox4->Text = System::Convert::ToString(sqlRead["application"]);;
				textBox5->Text = System::Convert::ToString(sqlRead["contraindication"]);;
				textBox6->Text = System::Convert::ToString(sqlRead["side_Reactions"]);;
				textBox7->Text = System::Convert::ToString(sqlRead["termin"]);;
				textBox8->Text = System::Convert::ToString(sqlRead["dates"]);;
				cCP = System::Convert::ToInt32(sqlRead["producer"]);;
				cCC = System::Convert::ToInt32(sqlRead["pharmacy"]);
			}
			connect->Close();
			sqlRead->Close();
			this->currComboBoxSetAddP(cCP);
			this->currComboBoxSetAddС(cCC);
		}

		void currComboBoxSetAddP(int id)
		{
			connect->Open();
			String^ query = "SELECT Name FROM Producer WHERE id LIKE '" + id + "';";
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


		void currComboBoxSetAddС(int id)
		{
			connect->Open();
			String^ query = "SELECT Name FROM Pharmacy WHERE id LIKE '" + id + "';";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			bool hasRow = sqlRead->Read();
			if (hasRow)
			{
				comboBox2->Text = System::Convert::ToString(sqlRead["Name"]);
			}
			connect->Close();
			sqlRead->Close();
		}

		int GetSelectedGroupIndexForAddP()
		{
			int id;
			connect->Open();
			String^ query = "SELECT id FROM Producer WHERE Name LIKE '" + comboBox1->Text + "';";
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

		int GetSelectedGroupIndexForAddC()
		{
			int id;
			connect->Open();
			String^ query = "SELECT id FROM Pharmacy WHERE Name LIKE '" + comboBox2->Text + "';";
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
		~Add_PR()
		{
			if (components)
			{
				delete components;
			}
		}
	System::Data::SqlServerCe::SqlCeConnection^ connect;
	int phoneid;
	int shoptelid;
	int VId;
	int contId;


	protected:

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox2;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ textBox5;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::TextBox^ textBox8;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Add_PR::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(417, 308);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(266, 33);
			this->comboBox1->TabIndex = 76;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Add_PR::comboBox1_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(152, 71);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 25);
			this->label7->TabIndex = 75;
			this->label7->Text = L"Модель";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(417, 372);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(266, 33);
			this->comboBox2->TabIndex = 74;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Add_PR::comboBox2_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(501, 344);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 25);
			this->label6->TabIndex = 72;
			this->label6->Text = L"Аптека";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(73, 158);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(266, 31);
			this->textBox3->TabIndex = 71;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox3_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(73, 99);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(266, 31);
			this->textBox2->TabIndex = 70;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(101, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 25);
			this->label4->TabIndex = 69;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(483, 280);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 25);
			this->label5->TabIndex = 68;
			this->label5->Text = L"Виробник";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(140, 133);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(108, 25);
			this->label8->TabIndex = 67;
			this->label8->Text = L"Речовини";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(156, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 25);
			this->label9->TabIndex = 66;
			this->label9->Text = L"Назва";
			this->label9->Click += gcnew System::EventHandler(this, &Add_PR::label9_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(73, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(266, 31);
			this->textBox1->TabIndex = 79;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Olive;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(282, 334);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 70);
			this->button2->TabIndex = 81;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Add_PR::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Olive;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(67, 334);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 70);
			this->button1->TabIndex = 80;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Add_PR::button1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(73, 228);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(266, 31);
			this->textBox4->TabIndex = 83;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox4_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(120, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(153, 25);
			this->label1->TabIndex = 82;
			this->label1->Text = L"Використання";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(413, 37);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(266, 31);
			this->textBox5->TabIndex = 85;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox5_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(442, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(201, 25);
			this->label2->TabIndex = 84;
			this->label2->Text = L"Противопоказання";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(413, 99);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(266, 31);
			this->textBox6->TabIndex = 87;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox6_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(460, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(159, 25);
			this->label3->TabIndex = 86;
			this->label3->Text = L"Побічні реакції";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(413, 170);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(266, 31);
			this->textBox7->TabIndex = 89;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox7_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(503, 142);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(81, 25);
			this->label10->TabIndex = 88;
			this->label10->Text = L"Термін";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(413, 243);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(266, 31);
			this->textBox8->TabIndex = 91;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Add_PR::textBox8_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(509, 215);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(62, 25);
			this->label11->TabIndex = 90;
			this->label11->Text = L"Дата";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Olive;
			this->pictureBox1->Location = System::Drawing::Point(67, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(615, 397);
			this->pictureBox1->TabIndex = 92;
			this->pictureBox1->TabStop = false;
			// 
			// Add_PR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(758, 411);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Add_PR";
			this->Text = L"Препарат";
			this->Load += gcnew System::EventHandler(this, &Add_PR::Add_PR_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Add_PR_Load(System::Object^ sender, System::EventArgs^ e) {
		connect->Open();
		SqlCeCommand^ command = gcnew SqlCeCommand("SELECT Name FROM producer",
			connect);
		SqlCeDataReader^ sqlRead = command->ExecuteReader();
		while (sqlRead->Read()) {
			comboBox1->Items->Add(sqlRead["Name"]);
		}
		sqlRead->Close();

		SqlCeCommand^ command1 = gcnew SqlCeCommand("SELECT Name FROM pharmacy",
			connect);
		SqlCeDataReader^ sqlRead1 = command1->ExecuteReader();
		while (sqlRead1->Read()) {
			comboBox2->Items->Add(sqlRead1["Name"]);
		}
		sqlRead1->Close();
		connect->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Stop();
		Sleep(250);
		Close();
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Success();
	if (textBox2->Text->Length != 0 && textBox3->Text->Length != 0) {
		if (this->contId == -1) insert();
		else update();
		this->Close();
	}
	else {
		Sounds^ sounds = gcnew Sounds();
		sounds->Error();
		MessageBox::Show("Заповніть усі поля");
	}
}
	private: void insert() {
		int cCP = this->GetSelectedGroupIndexForAddP();
		int cCC = this->GetSelectedGroupIndexForAddC();
		
		connect->Open();
		String^ query = "INSERT INTO Preparation([preparation],[model],[active_Substances],[application],[contraindication],[side_Reactions],[termin],[dates],[producer],[pharmacy])" +
				"VALUES('" + textBox1->Text + "','" + textBox2->Text + "','" + textBox3->Text +
				"','" + textBox4->Text + "','" + textBox5->Text + "','" + textBox6->Text + "','" + textBox7->Text + "','" + textBox8->Text + "'," + cCP + "," + cCC + ");";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			if (command->ExecuteNonQuery() > 0)
			{
				Sounds^ sounds = gcnew Sounds();
				sounds->Success();
				MessageBox::Show("Запис додано.");
			}
			
			connect->Close();
	}
	private: void update() {
		try
		{
			int cCP = this->GetSelectedGroupIndexForAddP();
			int cCC = this->GetSelectedGroupIndexForAddC();
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			String^ query = "UPDATE Preparation SET [preparation]='" + textBox1->Text + "', [model]='" + textBox2->Text + "', [active_Substances]='" + textBox3->Text +
				"', [application]='" + textBox4->Text + "', [contraindication]='" + textBox5->Text + "', [side_Reactions]='" + textBox6->Text + "', [termin]='" + textBox7->Text + "', [dates]='" + textBox8->Text + "',[producer]=" + cCP + ",[pharmacy]=" + cCC + " WHERE [id]=" + this->contId + ";";
			command->CommandText = query;
			if (command->ExecuteNonQuery() == 0)
			{
				Sounds^ sounds = gcnew Sounds();
				sounds->Success();
				MessageBox::Show("Запис оновлено.");
			}
			
		}
	
		finally
		{
			// Вивільнення даних

			connect->Close();
		}
	}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
}
};
}

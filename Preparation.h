#include "Preparation_header.h"
#include "Add_PR.h"
#include "Sound.h"
#pragma once

namespace Pharmacy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlServerCe;

	/// <summary>
	/// Summary for Validacia
	/// </summary>
	public ref class Preparation : public System::Windows::Forms::Form
	{
		System::Data::SqlServerCe::SqlCeConnection^ connect;
		int crId;
	private:
		List<preparation2^>^ contract;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MedicineName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MedicineID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MedicineCount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PharmacyName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;











	private: System::Windows::Forms::Button^ button1;
	
	public:
		Preparation(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			contract = gcnew List<preparation2^>();
			getDataPreparation();
		}

		void updateTable() {
			int i = 0;
			dataGridView1->Rows->Clear();
			for each (preparation2 ^ a in contract) {
				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = a->getId();
				this->dataGridView1->Rows[i]->Cells[1]->Value = a->getPreparation();
				this->dataGridView1->Rows[i]->Cells[2]->Value = a->getModel();
				this->dataGridView1->Rows[i]->Cells[3]->Value = a->getActive_Substances();
				this->dataGridView1->Rows[i]->Cells[4]->Value = a->getApplication();
				this->dataGridView1->Rows[i]->Cells[5]->Value = a->getContraindication();
				this->dataGridView1->Rows[i]->Cells[6]->Value = a->getSide_Reactions();
				this->dataGridView1->Rows[i]->Cells[7]->Value = a->getTermin();
				this->dataGridView1->Rows[i]->Cells[8]->Value = a->getDates();
				this->dataGridView1->Rows[i]->Cells[9]->Value = a->getProducer();
				this->dataGridView1->Rows[i]->Cells[10]->Value = a->getPharmacy();
				++i;
			}
		}

		void getDataPreparation()
		{
			this->crId = getSelectedGroupIndex();
			if (this->crId < 0)
			{
				//connect->Close();
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Preparation";
				command->Parameters->AddWithValue(
					"@crId",
					this->crId
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				contract->Clear();
				while (sqlRead->Read()) {
					contract->Add(gcnew preparation2(
						System::Convert::ToInt32(sqlRead["id"]),
						System::Convert::ToString(sqlRead["preparation"]),
						System::Convert::ToString(sqlRead["model"]),
						System::Convert::ToString(sqlRead["active_Substances"]),
						System::Convert::ToString(sqlRead["application"]),
						System::Convert::ToString(sqlRead["contraindication"]),
						System::Convert::ToString(sqlRead["side_Reactions"]),
						System::Convert::ToString(sqlRead["termin"]),
						System::Convert::ToString(sqlRead["dates"]),
						System::Convert::ToString(sqlRead["producer"]),
						System::Convert::ToString(sqlRead["pharmacy"])
					));
				}
				connect->Close();
				this->updateTable();
			}
			else {
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Preparation WHERE [producer]=@crId";
				command->Parameters->AddWithValue(
					"@crId",
					this->crId
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				contract->Clear();
				while (sqlRead->Read()) {
					contract->Add(gcnew preparation2(
						System::Convert::ToInt32(sqlRead["id"]),
						System::Convert::ToString(sqlRead["preparation"]),
						System::Convert::ToString(sqlRead["model"]),
						System::Convert::ToString(sqlRead["active_Substances"]),
						System::Convert::ToString(sqlRead["application"]),
						System::Convert::ToString(sqlRead["contraindication"]),
						System::Convert::ToString(sqlRead["side_Reactions"]),
						System::Convert::ToString(sqlRead["termin"]),
						System::Convert::ToString(sqlRead["dates"]),
						System::Convert::ToString(sqlRead["producer"]),
						System::Convert::ToString(sqlRead["pharmacy"])
					));
				}
				connect->Close();
				this->updateTable();
			}

		}


		void getDataPreparation1()
		{
			this->crId = getSelectedGroupIndex1();
			if (this->crId < 0)
			{
				//connect->Close();
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Preparation";
				command->Parameters->AddWithValue(
					"@crId",
					this->crId
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				contract->Clear();
				while (sqlRead->Read()) {
					contract->Add(gcnew preparation2(
						System::Convert::ToInt32(sqlRead["id"]),
						System::Convert::ToString(sqlRead["preparation"]),
						System::Convert::ToString(sqlRead["model"]),
						System::Convert::ToString(sqlRead["active_Substances"]),
						System::Convert::ToString(sqlRead["application"]),
						System::Convert::ToString(sqlRead["contraindication"]),
						System::Convert::ToString(sqlRead["side_Reactions"]),
						System::Convert::ToString(sqlRead["termin"]),
						System::Convert::ToString(sqlRead["dates"]),
						System::Convert::ToString(sqlRead["producer"]),
						System::Convert::ToString(sqlRead["pharmacy"])
					));
				}
				connect->Close();
				this->updateTable();
			}
			else {
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Preparation WHERE [pharmacy]=@crId";
				command->Parameters->AddWithValue(
					"@crId",
					this->crId
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				contract->Clear();
				while (sqlRead->Read()) {
					contract->Add(gcnew preparation2(
						System::Convert::ToInt32(sqlRead["id"]),
						System::Convert::ToString(sqlRead["preparation"]),
						System::Convert::ToString(sqlRead["model"]),
						System::Convert::ToString(sqlRead["active_Substances"]),
						System::Convert::ToString(sqlRead["application"]),
						System::Convert::ToString(sqlRead["contraindication"]),
						System::Convert::ToString(sqlRead["side_Reactions"]),
						System::Convert::ToString(sqlRead["termin"]),
						System::Convert::ToString(sqlRead["dates"]),
						System::Convert::ToString(sqlRead["producer"]),
						System::Convert::ToString(sqlRead["pharmacy"])
					));
				}
				connect->Close();
				this->updateTable();
			}

		}
	

		int getSelectedGroupIndex()
		{
			//connect->Close();
			connect->Open();
			String^ query = "SELECT id FROM producer WHERE Name LIKE '" + comboBox1->Text + "';";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();

			int result = -1;
			bool hasRow = sqlRead->Read();
			if (hasRow)
			{
				result = System::Convert::ToInt32(sqlRead["id"]);
			}
			connect->Close();
			sqlRead->Close();
			return result;
		}

		int getSelectedGroupIndex1()
		{
			//connect->Close();
			connect->Open();
			String^ query = "SELECT id FROM pharmacy  WHERE Name LIKE '" + comboBox2->Text + "';";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();

			int result = -1;
			bool hasRow = sqlRead->Read();
			if (hasRow)
			{
				result = System::Convert::ToInt32(sqlRead["id"]);
			}
			connect->Close();
			sqlRead->Close();
			return result;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Preparation()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Preparation::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MedicineName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MedicineID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MedicineCount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PharmacyName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Silver;
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(0, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1382, 412);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Фільтрації";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(393, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Аптека:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(150, 62);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(198, 33);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Preparation::comboBox1_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Location = System::Drawing::Point(711, 37);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 58);
			this->button4->TabIndex = 8;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Preparation::button4_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(488, 57);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(198, 33);
			this->comboBox2->TabIndex = 7;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Preparation::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(29, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Виробник:";
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeight = 55;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->Id, this->MedicineName,
					this->MedicineID, this->Price, this->MedicineCount, this->PharmacyName, this->Column1, this->Column2, this->Column3, this->Column4,
					this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 109);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 45;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(1352, 297);
			this->dataGridView1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(308, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(153, 33);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Препарат";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 481);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1370, 81);
			this->panel1->TabIndex = 10;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(562, 15);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(199, 44);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Вихід";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Preparation::button5_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(354, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 63);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Preparation::button3_Click);
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
			this->button2->Location = System::Drawing::Point(210, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 63);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Preparation::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(55, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 63);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Preparation::button1_Click);
			// 
			// Id
			// 
			this->Id->HeaderText = L"ID";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			this->Id->Visible = false;
			this->Id->Width = 25;
			// 
			// MedicineName
			// 
			this->MedicineName->HeaderText = L"Назва";
			this->MedicineName->Name = L"MedicineName";
			this->MedicineName->ReadOnly = true;
			// 
			// MedicineID
			// 
			this->MedicineID->HeaderText = L"Модель";
			this->MedicineID->Name = L"MedicineID";
			this->MedicineID->Width = 150;
			// 
			// Price
			// 
			this->Price->HeaderText = L"Речовини";
			this->Price->Name = L"Price";
			this->Price->ReadOnly = true;
			// 
			// MedicineCount
			// 
			this->MedicineCount->HeaderText = L"Використання";
			this->MedicineCount->Name = L"MedicineCount";
			this->MedicineCount->Width = 200;
			// 
			// PharmacyName
			// 
			this->PharmacyName->HeaderText = L"Противопоказання";
			this->PharmacyName->Name = L"PharmacyName";
			this->PharmacyName->ReadOnly = true;
			this->PharmacyName->Width = 200;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Побічні реакції";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 150;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Термін";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Дата";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Виробник";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Аптека";
			this->Column5->Name = L"Column5";
			// 
			// Preparation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1370, 562);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Preparation";
			this->Text = L"Препарат";
			this->Load += gcnew System::EventHandler(this, &Preparation::Preparation_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Preparation_Load(System::Object^ sender, System::EventArgs^ e) {
		connect->Open();
		SqlCeCommand^ command = gcnew SqlCeCommand("SELECT Name FROM Producer",
			connect);
		SqlCeDataReader^ sqlRead = command->ExecuteReader();
		while (sqlRead->Read()) {
			comboBox1->Items->Add(sqlRead["Name"]);
		}
		sqlRead->Close();

		SqlCeCommand^ command2 = gcnew SqlCeCommand("SELECT Name FROM Pharmacy", connect);
		SqlCeDataReader^ sqlRead2 = command2->ExecuteReader();
		while (sqlRead2->Read()) {
			comboBox2->Items->Add(sqlRead2["Name"]);
		}
		sqlRead2->Close();
		connect->Close();
	}
	
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
	this->comboBox1->Text;
	this->getDataPreparation();
}

private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	this->comboBox2->Text;
	this->getDataPreparation1();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	comboBox1->Text = "";
	comboBox2->Text = "";
	this->getDataPreparation();
}

private: System::Void comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->comboBox1->Text;
	this->getDataPreparation();
}

private: System::Void comboBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
	   {
		   this->comboBox2->Text;
		   this->getDataPreparation();
	   }

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	Add_PR^ edit = gcnew Add_PR(-1);
	edit->ShowDialog();
	this->getDataPreparation();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	{
		Add_PR^ edit = gcnew Add_PR(System::Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value));
		edit->ShowDialog();
		this->getDataPreparation();
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	try {
		connect->Open();
		String^ query = "DELETE FROM Preparation WHERE [Id]=" +
			System::Convert::ToString(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
		SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
		if (command->ExecuteNonQuery() > 0) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Success();
			MessageBox::Show("Видалено!");
		}
		connect->Close();
		this->getDataPreparation();
	}
	catch (...) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Error();
		MessageBox::Show("Choose correct item");
	}

}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Stop();
	Sleep(250);
	Close();
}
};
}

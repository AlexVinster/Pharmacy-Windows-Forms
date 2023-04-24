#pragma once
#include "Supplied_Preparation_header.h"
#include "Add_SP.h"
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
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlServerCe;

	/// <summary>
	/// Summary for Phone
	/// </summary>
	public ref class Supplied_Preparation : public System::Windows::Forms::Form
	{
	public:
		Supplied_Preparation(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			supplied_Preparation = gcnew List<supplied_Preparation2^>();
			getDataSupplied_Preparation();
		}

		void getDataSupplied_Preparation()
		{
			this->phoid = getSelectedGroupIndex();
			if (this->phoid < 0)
			{
				//connect->Close();
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Supplied_Preparation";
				command->Parameters->AddWithValue(
					"@phoid",
					this->phoid
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				supplied_Preparation->Clear();
				while (sqlRead->Read()) {
					supplied_Preparation->Add(gcnew supplied_Preparation2(
						System::Convert::ToString(sqlRead["Amount"]),
						System::Convert::ToString(sqlRead["Price"]),
						System::Convert::ToString(sqlRead["Address_of_Delivery"]),
						System::Convert::ToString(sqlRead["Paid"]),
						System::Convert::ToString(sqlRead["preparation"]),
						System::Convert::ToInt32(sqlRead["id"])
					));
				}
				connect->Close();
				this->updateTable();
			}
			else {
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Supplied_Preparation WHERE [Preparation]=@phoid";
				command->Parameters->AddWithValue(
					"@phoid",
					this->phoid
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				supplied_Preparation->Clear();
				while (sqlRead->Read()) {
					supplied_Preparation->Add(gcnew supplied_Preparation2(
						System::Convert::ToString(sqlRead["Amount"]),
						System::Convert::ToString(sqlRead["Price"]),
						System::Convert::ToString(sqlRead["Address_of_Delivery"]),
						System::Convert::ToString(sqlRead["Paid"]),
						System::Convert::ToString(sqlRead["preparation"]),
						System::Convert::ToInt32(sqlRead["id"])
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
			String^ query = "SELECT id FROM Preparation  WHERE preparation LIKE '" + comboBox1->Text + "';";
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

		void execute(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			command->ExecuteNonQuery();
			connect->Close();
		}

		void updateTable() {
			int i = 0;
			dataGridView1->Rows->Clear();
			for each (supplied_Preparation2 ^ a in supplied_Preparation) {
				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = a->getId();
				this->dataGridView1->Rows[i]->Cells[1]->Value = a->getAmount();
				this->dataGridView1->Rows[i]->Cells[2]->Value = a->getPrice();
				this->dataGridView1->Rows[i]->Cells[3]->Value = a->getAddress_of_Delivery();
				this->dataGridView1->Rows[i]->Cells[4]->Value = a->getPaid();
				this->dataGridView1->Rows[i]->Cells[5]->Value = a->getpreparation();
				++i;
			}
		}

		void getQuerySupplied_Preparation(String^ query) {
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			supplied_Preparation->Clear();
			while (sqlRead->Read()) {
				supplied_Preparation->Add(gcnew supplied_Preparation2(
					System::Convert::ToString(sqlRead["Amount"]),
					System::Convert::ToString(sqlRead["Price"]),
					System::Convert::ToString(sqlRead["Address_of_Delivery"]),
					System::Convert::ToString(sqlRead["Paid"]),
					System::Convert::ToString(sqlRead["preparation"]),
					System::Convert::ToInt32(sqlRead["id"])
				));
			}
			sqlRead->Close();
			connect->Close();
			this->updateTable();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Supplied_Preparation()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		List<supplied_Preparation2^>^ supplied_Preparation;
		System::Data::SqlServerCe::SqlCeConnection^ connect;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	int phoid;

	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Supplied_Preparation::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(425, 9);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 33);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Поставщик";
			this->label1->Click += gcnew System::EventHandler(this, &Supplied_Preparation::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::DarkSlateGray;
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->groupBox1->Location = System::Drawing::Point(230, 301);
			this->groupBox1->Margin = System::Windows::Forms::Padding(6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(6);
			this->groupBox1->Size = System::Drawing::Size(703, 136);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Фільтації";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(75, 86);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Лікарство:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(201, 78);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(238, 33);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Supplied_Preparation::comboBox1_SelectedIndexChanged);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Green;
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button5->Location = System::Drawing::Point(504, 12);
			this->button5->Margin = System::Windows::Forms::Padding(6);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(141, 112);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Supplied_Preparation::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(201, 38);
			this->textBox1->Margin = System::Windows::Forms::Padding(6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(238, 31);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Supplied_Preparation::search);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(81, 44);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Кількість:";
			this->label2->Click += gcnew System::EventHandler(this, &Supplied_Preparation::label2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column7
			});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dataGridView1->Location = System::Drawing::Point(230, 45);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->RowTemplate->Height = 85;
			this->dataGridView1->Size = System::Drawing::Size(703, 259);
			this->dataGridView1->TabIndex = 17;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Supplied_Preparation::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"id";
			this->Column1->Name = L"Column1";
			this->Column1->Visible = false;
			this->Column1->Width = 35;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Кількість";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 130;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ціна";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 110;
			// 
			// Column4
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle2;
			this->Column4->HeaderText = L"Адреса доставки";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 160;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Оплата";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 110;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Лікарство";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 120;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightYellow;
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(165, 437);
			this->panel1->Margin = System::Windows::Forms::Padding(6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(804, 54);
			this->panel1->TabIndex = 18;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(636, 6);
			this->button4->Margin = System::Windows::Forms::Padding(6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 44);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Вихід";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Supplied_Preparation::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(342, 6);
			this->button3->Margin = System::Windows::Forms::Padding(6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 44);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Supplied_Preparation::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(180, 6);
			this->button2->Margin = System::Windows::Forms::Padding(6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 44);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Supplied_Preparation::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(18, 6);
			this->button1->Margin = System::Windows::Forms::Padding(6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Supplied_Preparation::button1_Click);
			// 
			// Supplied_Preparation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1152, 540);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Supplied_Preparation";
			this->Text = L"Поставка";
			this->Load += gcnew System::EventHandler(this, &Supplied_Preparation::Supplied_Preparation_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Supplied_Preparation_Load(System::Object^ sender, System::EventArgs^ e) {
		connect->Open();
		SqlCeCommand^ command2 = gcnew SqlCeCommand("SELECT preparation FROM Preparation",
			connect);
		SqlCeDataReader^ sqlRead2 = command2->ExecuteReader();
		while (sqlRead2->Read()) {
			comboBox1->Items->Add(sqlRead2["preparation"]);
		}
		connect->Close();
		sqlRead2->Close();
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Click();
		this->comboBox1->Text;
		this->getDataSupplied_Preparation();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Add_SP^ edit = gcnew Add_SP(-1);
		edit->ShowDialog();
		this->getDataSupplied_Preparation();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			Add_SP^ edit = gcnew Add_SP(System::Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value));
			edit->ShowDialog();
			this->getDataSupplied_Preparation();
		}
		catch (...) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Notification();
			MessageBox::Show("Виберіть правильний елемент");
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			connect->Open();
			String^ query = "DELETE FROM Supplied_Preparation WHERE [Id]=" +
				System::Convert::ToString(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			if (command->ExecuteNonQuery() > 0) {
				Sounds^ sounds = gcnew Sounds();
				sounds->Success();
				MessageBox::Show("Deleted!");
			}
			connect->Close();
			this->getDataSupplied_Preparation();
		}
		catch (...) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Notification();
			MessageBox::Show("Choose correct item");
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Click();
		textBox1->Text = "";
		comboBox1->Text = "";
		this->getDataSupplied_Preparation();
	}
	private: System::Void search(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Keyboard();
		String^ query = "SELECT * FROM Supplied_Preparation WHERE [Amount] LIKE'%" + textBox1->Text + "%';";
		this->getQuerySupplied_Preparation(query);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Stop();
		Sleep(250);
		Close();
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

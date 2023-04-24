#include "Pharmacy_header.h"
#include "Add_PH.h"
#include "Sound.h"
#pragma once

namespace Pharmacy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlServerCe;
	using namespace System::IO;
	using namespace System::Media;
	/// <summary>
	/// Summary for Shops
	/// </summary>
	public ref class Pharmacy : public System::Windows::Forms::Form
	{
	System::Data::SqlServerCe::SqlCeConnection^ connect;
	int clientid;




	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;

		   List<pharmacy2^>^ client;
	public:
		Pharmacy(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			client = gcnew List<pharmacy2^>();
			getDataPharmacy();
		}

		void getDataPharmacy() {
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Pharmacy";
			command->Parameters->AddWithValue("@client", this->clientid);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			client->Clear();
			while (sqlRead->Read()) {
				client->Add(gcnew pharmacy2(
					System::Convert::ToString(sqlRead["Name"]),
					System::Convert::ToString(sqlRead["Address"]),
					System::Convert::ToString(sqlRead["Сontact_number"]),
					System::Convert::ToString(sqlRead["Open_24_hours"]),
					System::Convert::ToString(sqlRead["Work_time"]),
					System::Convert::ToInt32(sqlRead["id"])
				));
			}
			connect->Close();
			this->updateTable();
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
			for each (pharmacy2 ^ a in client) {
				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = a->getId();
				this->dataGridView1->Rows[i]->Cells[1]->Value = a->getName();
				this->dataGridView1->Rows[i]->Cells[2]->Value = a->getAddress();
				this->dataGridView1->Rows[i]->Cells[3]->Value = a->getContact_number();
				this->dataGridView1->Rows[i]->Cells[4]->Value = a->getOpen_24_hours();
				this->dataGridView1->Rows[i]->Cells[5]->Value = a->getWork_time();
				++i;
			}
		}

		void getQueryPharmacy(String^ query) {
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			client->Clear();
			while (sqlRead->Read()) {
				client->Add(gcnew pharmacy2(
					System::Convert::ToString(sqlRead["Name"]),
					System::Convert::ToString(sqlRead["Address"]),
					System::Convert::ToString(sqlRead["Сontact_number"]),
					System::Convert::ToString(sqlRead["Open_24_hours"]),
					System::Convert::ToString(sqlRead["Work_time"]),
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
		~Pharmacy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Pharmacy::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->label1->ForeColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label1->Location = System::Drawing::Point(257, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Аптека";
			this->label1->Click += gcnew System::EventHandler(this, &Pharmacy::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::DarkKhaki;
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F));
			this->groupBox1->ForeColor = System::Drawing::Color::LightGoldenrodYellow;
			this->groupBox1->Location = System::Drawing::Point(3, 350);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(684, 134);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Фільтрації";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Green;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(500, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 86);
			this->button4->TabIndex = 8;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Pharmacy::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(260, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(194, 31);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Pharmacy::search);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(260, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 31);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Pharmacy::search);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label3->Location = System::Drawing::Point(180, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Адрес:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label2->Location = System::Drawing::Point(61, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Пошук за назвою:";
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Number,
					this->Column1, this->Column2, this->Column4, this->Column3, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 165);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(664, 179);
			this->dataGridView1->TabIndex = 2;
			// 
			// Number
			// 
			this->Number->HeaderText = L"№";
			this->Number->Name = L"Number";
			this->Number->Width = 43;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Назва";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 150;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Адреса";
			this->Column2->Name = L"Column2";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Телефон";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 120;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Працює 24/7";
			this->Column3->Name = L"Column3";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Робочий час";
			this->Column5->Name = L"Column5";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::OliveDrab;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(0, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 44);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Pharmacy::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::OliveDrab;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(156, 9);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 44);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Pharmacy::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::OliveDrab;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(318, 9);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 44);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Pharmacy::button3_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::OliveDrab;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button5->Location = System::Drawing::Point(480, 9);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 44);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Вихід";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Pharmacy::button5_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(37, 94);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(639, 65);
			this->panel1->TabIndex = 8;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Pharmacy::panel1_Paint);
			// 
			// Pharmacy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(699, 477);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Pharmacy";
			this->Text = L"Аптека";
			this->Load += gcnew System::EventHandler(this, &Pharmacy::Pharmacy_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Pharmacy_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void search(System::Object^ sender, System::EventArgs^ e) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Keyboard();
		String^ query = "SELECT * FROM Pharmacy WHERE [Name] LIKE'%" + textBox1->Text + "%' and [Address] LIKE'%" + textBox2->Text + "%';";
		this->getQueryPharmacy(query);
	}


private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
	Add_PH^ edit = gcnew Add_PH(-1);
	edit->ShowDialog();
	this->getDataPharmacy();
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	Add_PH^ edit = gcnew Add_PH(System::Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value));
	edit->ShowDialog();
	this->getDataPharmacy();
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	try {
		connect->Open();
		String^ query = "DELETE FROM Pharmacy WHERE [Id]=" +
			System::Convert::ToString(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
		SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
		if (command->ExecuteNonQuery() > 0) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Success();
			MessageBox::Show("Запис видалено!");
		}
		connect->Close();
		this->getDataPharmacy();
	}
	catch (...) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Error();
		MessageBox::Show("Виберіть запис.");
	}
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Stop();
	Sleep(250);
	Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	textBox1->Text = "";
	textBox2->Text = "";
	this->getDataPharmacy();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

#include "Producer_header.h"
#include "Add_PRO.h"
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
	/// Summary for Slaid
	/// </summary>
	public ref class Producer : public System::Windows::Forms::Form
	{
		System::Data::SqlServerCe::SqlCeConnection^ connect;
		int technid;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::Button^ button1;

		   List<producer2^>^ Technical;
	public:
		Producer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "Data Source=Apteka.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			Technical = gcnew List<producer2^>();
			getDataProducer();
		}

		void getDataProducer()
		{
				//connect->Close();
				connect->Open();
				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = "SELECT * FROM Producer";
				command->Parameters->AddWithValue(
					"@technid",
					this->technid
				);
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				Technical->Clear();
				while (sqlRead->Read()) {
					Technical->Add(gcnew producer2(
						System::Convert::ToInt32(sqlRead["id"]),
						System::Convert::ToString(sqlRead["Name"]),
						System::Convert::ToString(sqlRead["Address"]),
						System::Convert::ToString(sqlRead["Contacts"]),
						System::Convert::ToString(sqlRead["Email"])
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
			for each (producer2 ^ a in Technical) {
				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = a->getId();
				this->dataGridView1->Rows[i]->Cells[1]->Value = a->getName();
				this->dataGridView1->Rows[i]->Cells[2]->Value = a->getAddress();
				this->dataGridView1->Rows[i]->Cells[3]->Value = a->getContacts();
				this->dataGridView1->Rows[i]->Cells[4]->Value = a->getEmail();
				++i;
			}
		}


		void getQueryCallers(String^ query) {
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			Technical->Clear();
			while (sqlRead->Read()) {
				Technical->Add(gcnew producer2(
					System::Convert::ToInt32(sqlRead["id"]),
					System::Convert::ToString(sqlRead["Name"]),
					System::Convert::ToString(sqlRead["Address"]),
					System::Convert::ToString(sqlRead["Contacts"]),
					System::Convert::ToString(sqlRead["Email"])
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
		~Producer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:


	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button2;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Producer::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Olive;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(274, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 42);
			this->label1->TabIndex = 71;
			this->label1->Text = L"Виробник";
			this->label1->Click += gcnew System::EventHandler(this, &Producer::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Olive;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(63, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(247, 31);
			this->label3->TabIndex = 66;
			this->label3->Text = L"Назва виробника";
			this->label3->Click += gcnew System::EventHandler(this, &Producer::label3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Linen;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Chocolate;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column5, this->Column6
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(21, 132);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(751, 203);
			this->dataGridView1->TabIndex = 67;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№";
			this->Column1->Name = L"Column1";
			this->Column1->Visible = false;
			this->Column1->Width = 150;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Назва";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 200;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Адрес";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 200;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Контакти";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Електронна пошта";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 200;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Wheat;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(329, 75);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(194, 38);
			this->textBox3->TabIndex = 65;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Producer::search);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Green;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Location = System::Drawing::Point(542, 62);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(79, 51);
			this->button2->TabIndex = 64;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Producer::button2_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Location = System::Drawing::Point(106, 341);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(71, 68);
			this->button3->TabIndex = 72;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Producer::button3_Click);
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Location = System::Drawing::Point(479, 341);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(71, 68);
			this->button5->TabIndex = 73;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Producer::button5_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Location = System::Drawing::Point(303, 341);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(71, 68);
			this->button4->TabIndex = 74;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Producer::button4_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(606, 350);
			this->button1->Margin = System::Windows::Forms::Padding(6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 44);
			this->button1->TabIndex = 75;
			this->button1->Text = L"Вихід";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Producer::button1_Click);
			// 
			// Producer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(920, 406);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Producer";
			this->Text = L"Виробник";
			this->Load += gcnew System::EventHandler(this, &Producer::Producer_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Producer_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void search(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Keyboard();
	String^ query = "SELECT * FROM Producer WHERE [Name] LIKE'%" + textBox3->Text + "%';";
	this->getQueryCallers(query);
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	Add_PRO^ edit = gcnew Add_PRO(-1);
	edit->ShowDialog();
	this->getDataProducer();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	try
	{
		Add_PRO^ edit = gcnew Add_PRO(System::Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value));
		edit->ShowDialog();
		this->getDataProducer();
	}
	catch (...) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Notification();
		MessageBox::Show("Виберіть правильний елемент!");
	}
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		connect->Open();
		String^ query = "DELETE FROM Producer WHERE [Id]=" +
			System::Convert::ToString(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
		SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
		if (command->ExecuteNonQuery() > 0) {
			Sounds^ sounds = gcnew Sounds();
			sounds->Success();
			MessageBox::Show("Запис видалено!");
		}
		connect->Close();
		this->getDataProducer();
	}
	catch (...) {
		Sounds^ sounds = gcnew Sounds();
		sounds->Error();
		MessageBox::Show("Виберіть запис.");
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Click();
	textBox3->Text = "";
	this->getDataProducer();
}

private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Sounds^ sounds = gcnew Sounds();
	sounds->Stop();
	Sleep(250);
	Close();
}
};
}

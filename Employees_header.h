#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// ���������� �������� ���� std � System

using namespace System;
using namespace std;
// ���������� �����
ref class employees2 {
	//������ ���� ����� ��� ���������� �����
	String^ full_Name;
	String^ date_of_Birth;
	String^ gender;
	String^ identification_Code;
	String^ card_id_Number;
	String^ pharmacy;
	int id;
public: // ������ ����� �����
	employees2() {}// ������� �����������
// ����������� ����������� ���� �ᒺ��� �����
	employees2(String^ t, String^ m, String^ c, String^ r, String^ p, String^ ph, int i) {
		this->full_Name = t;
		this->date_of_Birth = m;
		this->gender = c;
		this->identification_Code = r;
		this->card_id_Number = p;
		this->pharmacy = p;
		if (i > 0) {
			this->id = i;
		}
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}

	void setFull_Name(String^ full_Name) {
		if (full_Name->Length != 0) {
			this->full_Name = full_Name;
		}
		else throw invalid_argument("Wrong nazva");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getFull_Name() {
		return this->full_Name;
	}

	void setDate_of_Birth(String^ date_of_Birth) {
		if (date_of_Birth->Length != 0) {
			this->date_of_Birth = date_of_Birth;
		}
		else throw invalid_argument("Wrong forma");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getDate_of_Birth() {
		return this->date_of_Birth;
	}
	void setGender(String^ gender) {
		if (gender->Length != 0) {
			this->gender = gender;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getGender() {
		return this->gender;
	}
	void setIdentification_Code(String^ identification_Code) {
		if (identification_Code->Length != 0) {
			this->identification_Code = identification_Code;
		}
		else throw invalid_argument("Wrong data");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getIdentification_Code() {
		return this->identification_Code;
	}
	
	void setCard_id_Number(String^ card_id_Number) {
		if (card_id_Number->Length != 0) {
			this->card_id_Number = card_id_Number;
		}
		else throw invalid_argument("Wrong data");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getCard_id_Number() {
		return this->card_id_Number;
	}

	void setPharmacy(String^ pharmacy) {
		if (pharmacy->Length != 0) {
			this->pharmacy = pharmacy;
		}
		else throw invalid_argument("Wrong data");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getPharmacy() {
		return this->pharmacy;
	}

	void setId(int id) {
		if (id > 0) {
			this->id = id;
		}
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}
	int getId() {
		return this->id;
	}

};

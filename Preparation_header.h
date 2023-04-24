#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// ���������� �������� ���� std � System

using namespace System;
using namespace std;
// ���������� �����
ref class preparation2 {
	//������ ���� ����� ��� ���������� ����� �����, ���� �� ������� ������
	int id;
	String^ preparation;
	String^ model;
	String^ active_Substances;
	String^ application;
	String^ contraindication;
	String^ side_Reactions;
	String^ termin;
	String^ dates;
	String^ producer;
	String^ pharmacy;
public: // ������ ����� �����
	preparation2() {}// ������� �����������
// ����������� ����������� ���� �ᒺ��� �����
	preparation2(int i, String^ dt, String^ v, String^ d, String^ cr, String^ c, String^ dtc, String^ vv, String^ dd, String^ crr, String^ cc) {
		this->id = i;
		this->preparation = dt;
		this->model = v;
		this->active_Substances = d;
		this->application = cr;
		this->contraindication = c;
		this->side_Reactions = dtc;
		this->termin = vv;
		this->dates = dd;
		this->producer = crr;
		this->pharmacy = cc;
		if (i > 0) {
			this->id = i;
		}
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}

	void setPreparation(String^ preparation) {
		if (preparation->Length != 0) {
			this->preparation = preparation;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getPreparation() {
		return this->preparation;
	}

	void setModel(String^ model) {
		if (model->Length != 0) {
			this->model = model;
		}
		else throw invalid_argument("Wrong station");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getModel() {
		return this->model;
	}

	void setActive_Substances(String^ active_Substances) {
		if (active_Substances->Length != 0) {
			this->active_Substances = active_Substances;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getActive_Substances() {
		return this->active_Substances;
	}


	void setApplication(String^ application) {
		if (application->Length != 0) {
			this->application = application;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getApplication() {
		return this->application;
	}

	void setContraindication(String^ contraindication) {
		if (contraindication->Length != 0) {
			this->contraindication = contraindication;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getContraindication() {
		return this->contraindication;
	}

	void setSide_Reactions(String^ side_Reactions) {
		if (side_Reactions->Length != 0) {
			this->side_Reactions = side_Reactions;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getSide_Reactions() {
		return this->side_Reactions;
	}

	void setTermin(String^ termin) {
		if (termin->Length != 0) {
			this->termin = termin;
		}
		else throw invalid_argument("Wrong station");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getTermin() {
		return this->termin;
	}

	void setDates(String^ dates) {
		if (dates->Length != 0) {
			this->dates = dates;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getDates() {
		return this->dates;
	}


	void setProducer(String^ producer) {
		if (producer->Length != 0) {
			this->producer = producer;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getProducer() {
		return this->producer;
	}

	void setPharmacy(String^ pharmacy) {
		if (pharmacy->Length != 0) {
			this->pharmacy = pharmacy;
		}
		else throw invalid_argument("Wrong vidpravlennya");
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

#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Date.h"

using namespace std;

class Packet {
private:
	int id; // packet unique identifier
	vector<string> sites; // touristic sites to visit
	Date inicio;  // begin date
	Date fim;  // end date
	double pricePerPerson; // price per person
	unsigned maxPersons; // maximum number of packages available
	unsigned reserved; // number of packages purchased

public:
	Packet();
	Packet(int id);
	Packet(vector<string> sites, Date inicio, Date fim, double pricePerPerson, unsigned maxPersons, unsigned reserved);
	Packet(int id, vector<string> sites, Date inicio, Date fim, double pricePerPerson, unsigned maxPersons, unsigned reserved);

	// GET methods
	int getId() const;
	vector<string> getSites() const;
	Date getBeginDate() const;
	Date getEndDate() const;
	double getPricePerPerson() const;
	unsigned getMaxPersons() const;
	unsigned getReserved() const;

	// SET methods
	void setId(int id);  // to set negative if "deprecated"
	void setSites(vector<string> sites);
	void setBeginDate(Date inicio);
	void setEndDate(Date fim);
	void setPricePerPerson(double pricePerPerson);
	void setMaxPersons(unsigned maxPersons);
	void setReserved(unsigned reserved);

	// other methods

	friend ostream& operator<<(ostream& out, const Packet & packet);

};

// lê ficheiro dos pacotes turisticos e guarda a informação num vetor de pacotes
vector<Packet> readfile_packs(string filename);
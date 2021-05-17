#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Packet.h"
#include "Address.h"

using namespace std;

class Client {
private:
	string name; // name of the client
	unsigned NIF; // NIF of client
	unsigned short familySize;  // number of family members
	Address address; // client's address
	vector<Packet> packets; // vector to store client's packets bought
	unsigned  totalPurchased; // total value spent by the client

public:
	Client();
	Client(string name, unsigned NIF, unsigned short familySize, Address address);  // for a new client
	Client(string name, unsigned NIF, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased);  // client read from file

	// GET methods

	string getName() const;
	unsigned getNIF() const;
	unsigned short getFamilySize() const;
	Address getAddress() const;
	vector<Packet> getPacketList() const;
	unsigned getTotalPurchased() const;

	// SET methods

	void setName(string name);
	void setNIF(unsigned NIF);
	void setFamilySize(unsigned short familySize);
	void setAddress(Address address);
	void setPacketList(vector<Packet> & packets);
	void setTotalPurchased(unsigned totalPurchased);

	// other methods

	// função que mostra o cliente no ecra
	friend ostream& operator<<(ostream& out, const Client & client);
	
};

// lê ficheiro dos clientes e guarda a informação num vetor de clientes
vector<Client> readfile_clients(string filename);

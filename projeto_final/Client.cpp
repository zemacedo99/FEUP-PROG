#include "Client.h"
#include "FilesFunctions.h"
#include <fstream>

Client::Client()
{
	name = "UNKNOWN";
	NIF = 0;
	familySize = 0;
	Address a;
	address = a;
	vector<Packet> p;
	packets = p;
	totalPurchased = 0;
}

Client::Client(string name, unsigned NIF, unsigned short familySize, Address address)
{
	this->name = name;
	this->NIF = NIF;
	this->familySize = familySize;
	this->address = address;
	vector<Packet> p;
	packets = p;
	totalPurchased = 0;
}

Client::Client(string name, unsigned NIF, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased)
{
	this->name = name;
	this->NIF = NIF;
	this->familySize = familySize;
	this->address = address;
	this->packets = packets;
	this->totalPurchased = totalPurchased;
}

// GET methods

string Client::getName() const
{
	return name;
}

unsigned Client::getNIF() const
{
	return NIF;
}

unsigned short Client::getFamilySize() const
{
	return familySize;
}

Address Client::getAddress() const
{
	return address;
}

vector<Packet> Client::getPacketList() const
{
	return packets;
}

unsigned Client::getTotalPurchased() const
{
	return totalPurchased;
}

// metodos SET

void Client::setName(string name)
{
	this->name = name;
}

void Client::setNIF(unsigned NIF)
{
	this->NIF = NIF;
}

void Client::setFamilySize(unsigned short familySize)
{
	this->familySize = familySize;
}

void Client::setAddress(Address address)
{
	this->address = address;
}

void Client::setPacketList(vector<Packet> & packets)
{
	this->packets = packets;
}

void Client::setTotalPurchased(unsigned totalPurchased)
{
	this->totalPurchased = totalPurchased;
}

// outros metodos

ostream& operator<<(ostream& out, const Client & client)
{
	out << client.name << endl
		<< client.NIF << endl
		<< client.familySize << endl
		<< client.address;

	

	if (client.packets.size() >= 1)
	{
		int i = 0;
		for ( i; i < client.packets.size() - 1;)
		{
			out << client.packets[i].getId() << " ; ";
			i++;
		}
		out << client.packets[i].getId() << endl;
	}
	else
	{
		out << endl;
	}

	out << client.totalPurchased << endl;

	return out;
}

vector<Client> readfile_clients(string filename)
{

	string temp;
	vector<Client> clients;

	ifstream infile;
	infile.open(filename);

	if (!infile.is_open())
	{
		cerr << "Error opening " << filename << endl;
	}

	while (!infile.eof()) //ciclo enquando nao chegar ao fim do ficheiro (enquanto nao ler os clientes todos) 
	{
		infile.seekg(0, ios::cur);

		getline(infile, temp);
		string name = temp;

		getline(infile, temp);
		unsigned NIF = stoi(temp);

		getline(infile, temp);
		unsigned short familySize = stoi(temp);

		getline(infile, temp);
		Address address = formatar_morada(temp);

		getline(infile, temp);
		vector<Packet> packets = formatar_pacotes(temp);

		getline(infile, temp);
		unsigned  totalPurchased = stoi(temp);

		getline(infile, temp);
		string delimiter = temp;


		Client c1(name, NIF, familySize, address, packets, totalPurchased);

		clients.push_back(c1);
	}

	infile.close();

	return clients;
}


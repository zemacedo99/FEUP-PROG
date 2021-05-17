#include "Agency.h"
#include "FilesFunctions.h"

#include <fstream>


Agency::Agency(string fileName)
{
	filename = fileName;
	ifstream infile;
	infile.open(filename);

	string temp;

	getline(infile, temp);
	name = temp;

	getline(infile, temp);
	NIF = stoul(temp);

	getline(infile, temp);
	URL = temp;

	getline(infile, temp);
	address = formatar_morada(temp);

	getline(infile, temp);
	filename_clients = temp;
	clients = readfile_clients(temp);

	getline(infile, temp);
	filename_packets = temp;
	packets = readfile_packs(temp);

	clientsInfoHasChanged = false;
	packetsInfoHasChanged = false;
}

// metodos GET
string Agency::getFilename() const
{
	return filename;
}

string Agency::getName() const
{
	return name;
}

unsigned Agency::getNIF() const
{
	return NIF;
}

Address Agency::getAddress() const
{
	return address;
}

string Agency::getURL() const
{
	return URL;
}

string Agency::getFilenameClients() const
{
	return filename_clients;
}

string Agency::getFilenamePackets() const
{
	return filename_packets;
}

vector<Client> Agency::getClients() const
{
	return clients;
}

vector<Packet> Agency::getPackets() const
{
	return packets;
}

bool Agency::getClientsInfoHasChanged() const
{
	return clientsInfoHasChanged;
}

bool Agency::getPacketsInfoHasChanged() const
{
	return packetsInfoHasChanged;
}

// SET Methods

void Agency::setFilename(string filename)
{
	this->filename = filename;
}

void Agency::setName(string name)
{
	this->name = name;
}

void Agency::setNIF(unsigned NIF)
{
	this->NIF = NIF;
}

void Agency::setAddress(Address address)
{
	this->address = address;
}

void Agency::setURL(string url)
{
	this->URL = url;
}

void Agency::setFilenameClients(string filenameClients)
{
	this->filename_clients = filenameClients;
}

void Agency::setFilenamePackets(string filenamePackets)
{
	this->filename_packets = filenamePackets;
}

void Agency::setClients(vector<Client> & clients)
{
	this->clients = clients;
}
void Agency::setPackets(vector<Packet> & packets)
{
	this->packets = packets;
}

void Agency::setClientsInfoHasChanged(bool clientsInfoHasChanged)
{
	this->clientsInfoHasChanged = clientsInfoHasChanged;
}

void Agency::setPacketsInfoHasChanged(bool packetsInfoHasChanged)
{
	this->packetsInfoHasChanged = packetsInfoHasChanged;
}

/*********************************
 * Mostrar Loja
 ********************************/

 // mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency)
{
	out << agency.name << endl
		<< agency.NIF << endl
		<< agency.URL << endl
		<< agency.address << endl;

	return out;
}

bool readfile_agency(string filename)
{
	ifstream infile;
	infile.open(filename);

	if (!infile)
	{
		cerr << "Error opening " << filename << endl;
		return false;
	}

	infile.close();

	return true;
}

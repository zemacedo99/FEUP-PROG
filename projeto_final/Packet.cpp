#include "Packet.h"
#include "FilesFunctions.h"

#include <fstream>

Packet::Packet()
{
	id = 0;
	vector<string> s;
	sites = s;
	Date begin;
	Date end;
	inicio = begin;
	fim = end;
	pricePerPerson = 0;
	maxPersons = 0;
	reserved = 0;
}

Packet::Packet(int id)
{
	this->id = id;
	vector<string> s;
	sites = s;
	Date begin;
	Date end;
	inicio = begin;
	fim = end;
	pricePerPerson = 0;
	maxPersons = 0;
	reserved = 0;
}

Packet::Packet(vector<string> sites, Date inicio, Date fim, double pricePerPerson, unsigned maxPersons, unsigned reserved)
{
	id = 0;
	this->sites = sites;
	this->inicio = inicio;
	this->fim = fim;
	this->pricePerPerson = pricePerPerson;
	this->maxPersons = maxPersons;
	this->reserved = reserved;
}

Packet::Packet(int id, vector<string> sites, Date inicio, Date fim, double pricePerPerson, unsigned maxPersons, unsigned reserved)
{
	this->id = id;
	this->sites = sites;
	this->inicio = inicio;
	this->fim = fim;
	this->pricePerPerson = pricePerPerson;
	this->maxPersons = maxPersons;
	this->reserved = reserved;
}

// metodos GET

int Packet::getId() const
{
	return id;
}

vector<string> Packet::getSites() const
{
	return sites;
}

Date Packet::getBeginDate() const
{
	return inicio;
}

Date Packet::getEndDate() const
{
	return fim;
}

double Packet::getPricePerPerson() const
{
	return pricePerPerson;
}

unsigned Packet::getMaxPersons() const
{
	return maxPersons;
}

unsigned Packet::getReserved() const
{
	return reserved;
}

// metodos SET

void Packet::setId(int id)
{
	this->id = id;
}

void Packet::setSites(vector<string> sites)
{
	this->sites = sites;
}

void Packet::setBeginDate(Date inicio)
{
	this->inicio = inicio;
}

void Packet::setEndDate(Date fim)
{
	this->fim = fim;
}

void Packet::setPricePerPerson(double pricePerPerson)
{
	this->pricePerPerson = pricePerPerson;
}

void Packet::setMaxPersons(unsigned maxPersons)
{
	this->maxPersons = maxPersons;
}

void Packet::setReserved(unsigned reserved)
{
	this->reserved = reserved;
}


/*********************************
 * Show Packet information
 ********************************/

 // shows a packet content 
ostream& operator<<(ostream& out, const Packet & packet)
{
	out << packet.id << endl;

	out << packet.sites[0];

	if (packet.sites.size() > 1)
	{
		out << " -";
		int i = 1;
		for ( i ; i < packet.sites.size()-1;)
		{
			out << packet.sites[i] << ", ";
			i++;
		}
		out << packet.sites[i] << endl;
	}
	else
	{
		out << endl;
	}
	
	out << packet.inicio;
	out << packet.fim;
	out << packet.pricePerPerson << endl;
	out << packet.maxPersons << endl;
	out << packet.reserved << endl;

	return out;
}

vector<Packet> readfile_packs(string filename)
{
	string temp;
	vector<Packet> packs;


	ifstream infile;
	infile.open(filename);

	if (!infile.is_open())
	{
		cerr << "Error opening " << filename << endl;
	}

	getline(infile, temp);
	unsigned lastid = stoi(temp); // identificador numérico único que foi atribuído ao último pacote que foi criado

	while (!infile.eof()) //ciclo enquando nao chegar ao fim do ficheiro (enquanto nao ler os packs todos) 
	{
		infile.seekg(0, ios::cur);

		getline(infile, temp);
		int id = stoul(temp);

		getline(infile, temp);
		vector<string> sites = formatar_locais(temp);

		getline(infile, temp);
		Date begin(temp);

		getline(infile, temp);
		Date end(temp);

		getline(infile, temp);
		double pricePerPerson = stod(temp);

		getline(infile, temp);
		unsigned maxPersons = stoul(temp);

		getline(infile, temp);
		unsigned reserved = stoul(temp);

		getline(infile, temp);
		string delimiter = temp;

		Packet p1(id, sites, begin, end, pricePerPerson, maxPersons,reserved);
		packs.push_back(p1);
	}

	infile.close();
	return packs;
}
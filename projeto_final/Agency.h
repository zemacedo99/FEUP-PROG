#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Address.h"
#include "Packet.h"
#include "Client.h"

using namespace std;

class Agency {
private:
	string filename; // name of agency file
	string name; // name of the  agency
	unsigned int NIF; // NIF of the agency
	string URL; // URL of the agency Web site
	Address address; // address of the agency
	string filename_clients; // name of clients file
	string filename_packets; // name of clients file
	vector<Client> clients; // vector to store the existing clients
	vector<Packet> packets; // vector to store the existing packets

	bool clientsInfoHasChanged; // flag that is set to "true" if at least one client has been changed/added/deleted
	bool packetsInfoHasChanged; // flag that is set to "true" if at least one packet has been changed/added/deleted
	unsigned int maxClientsId; // maximum value among all clients identifiers
	unsigned int maxPacketsId; // maximum value among all packets identifiers

public:
	Agency(string fileName);

	// methods GET
	string getFilename() const;
	string getName() const;
	unsigned getNIF() const;
	Address getAddress() const;
	string getURL() const;
	string getFilenameClients() const;
	string getFilenamePackets() const;
	vector<Client> getClients() const;
	vector<Packet> getPackets() const;
	bool getClientsInfoHasChanged() const;
	bool getPacketsInfoHasChanged() const;


	// methods SET
	void setFilename(string filename);
	void setName(string name);
	void setNIF(unsigned NIF);
	void setAddress(Address address);
	void setURL(string url);
	void setFilenameClients(string filenameClients);
	void setFilenamePackets(string filenamePackets);
	void setClients(vector<Client> & clients);
	void setPackets(vector<Packet> & packets);
	void setClientsInfoHasChanged(bool clientsInfoHasChanged);
	void setPacketsInfoHasChanged(bool packetsInfoHasChanged);

	// other methods */

	// função que mostra a agência no ecra
	friend ostream& operator<<(ostream& out, const Agency & agency);



};

// verifica se consegue abrir o ficheiro da agencia
bool readfile_agency(string filename);
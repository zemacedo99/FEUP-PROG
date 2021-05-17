#include "FilesFunctions.h"

using namespace std;

string escolher_ficheiro()
{
	string filename; //nome do ficheiro da agência
	cout << "Qual o nome do ficheiro da agencia a usar? " << endl << "* Nao esquecer a extensao (ex: .txt) *" << endl;
	getline(cin, filename);

	while (!readfile_agency(filename)) // força ao utilizador a colocar o nome de um ficheiro valido
	{
		system("cls");
		readfile_agency(filename);
		system("pause");
		cout << "Qual o nome do ficheiro da agencia a usar? " << endl << "* Nao esquecer a extensao (ex: .txt) *" << endl;
		getline(cin, filename);
	}

	return filename;
}

int verificar_opcao(int optionlower, int optionuper)
{
	bool temp = false;
	int option;
	string opstr;


	while (!temp)
	{
		getline(cin, opstr);
		istringstream instr(opstr);
		instr >> option;

		if (instr.fail())
		{
			cerr << " * ERRO * " << endl << " Insira o numero da opcao: " << endl;
		}
		else if (option < optionlower || option > optionuper)
		{
			cerr << " * ERRO * " << endl << " Opcao nao esta nos limites do menu " << endl << " Volte a inserir opcao: " << endl;
		}
		else
		{
			temp = true;
		}
	}
	return option;
}

int verificar_input()
{
	bool temp = false;
	int option;
	string opstr;


	while (!temp)
	{
		getline(cin, opstr);
		istringstream instr(opstr);
		instr >> option;

		if (instr.fail())
		{
			cerr << " * ERRO * " << endl << "Input invalido" << endl << "Tente novamente: " << endl;
		}
		else
		{
			temp = true;
		}
	}
	return option;
}

bool verifica_compra(Agency agency, int packindex, int clientindex)
{
	vector<Packet> p = agency.getPackets();
	vector<Client> c = agency.getClients();
	if (p[packindex].getId() != abs(p[packindex].getId()))
	{
		cout << "Pacote nao disponivel" << endl;
		return false; // pacote nao disponivel 
	}
	unsigned vendidos = p[packindex].getReserved();
	unsigned disponiveis = p[packindex].getMaxPersons();
	unsigned short familySize = c[clientindex].getFamilySize();
	unsigned update_vendidos = vendidos + familySize;

	if (update_vendidos >= disponiveis)
	{
		cout << "Numero de pacotes limitado" << endl;
		cout << "Impossivel de efetuar a compra do pacote" << endl;
		return false; // pacote nao disponivel
	}

	return true;
}


Address formatar_morada(string morada)
{
	Address m1; // morada formatada

	vector<string> elementos; // elementos da morada
	string delimiter = "/"; //separador

	size_t pos = 0;
	string elemento; // elemento da morada
	while ((pos = morada.find(delimiter)) != string::npos)
	{
		elemento = morada.substr(0, pos);
		//cout << elemento << endl;
		//cout << pos;

		//trim(elemento); função a implementar

		elementos.push_back(elemento);
		morada.erase(0, pos + delimiter.length());
	}



	m1.setStreet(elementos[0]);
	m1.setDoorNumber(stoi(elementos[1]));
	m1.setFloor(elementos[2]);
	m1.setPostalCode(elementos[3]);
	m1.setLocation(morada);

	return m1;
}

vector<Packet> formatar_pacotes(string pacotes)
{
	vector<Packet> packets;

	vector<string> elementos; // elementos do pacote
	string delimiter = ";"; //separador

	size_t pos = 0;
	string elemento; // elemento do pacote
	while ((pos = pacotes.find(delimiter)) != string::npos)
	{
		elemento = pacotes.substr(0, pos);
		//cout << elemento << endl;
		//cout << pos;
		elementos.push_back(elemento);
		pacotes.erase(0, pos + delimiter.length());
	}


	int temp; // variavel temporaria para tranformar string em int
	for (int i = 0; i < elementos.size(); i++) // ciclo para passar os elementos do vetor "elementos" de strings para int e guarda no vetor "p1"
	{
		temp = stoi(elementos[i]);
		Packet p1(temp);
		packets.push_back(p1);
	}
	temp = stoi(pacotes);
	Packet p1(temp);
	packets.push_back(p1);


	return packets;
}

vector<Packet> formatar_criar_pacote(string pacotesinfo)
{
	Packet pacote;
	int pacoteId;
	vector<Packet> pacotes;
	istringstream instr(pacotesinfo);

	while (instr >> pacoteId)
	{
		pacote.setId(pacoteId);
		pacotes.push_back(pacote);
	}

	return pacotes;
}

vector<string> formatar_locais(string sites)
{
	vector<string> v1; // vetor com os locais 


	string delimiter1 = " -"; //separador
	string delimiter = ", "; //separador


	size_t pos = 0;
	string elemento; // local

	while ((pos = sites.find(delimiter1)) != string::npos)
	{
		elemento = sites.substr(0, pos);
		//cout << elemento << endl;
		//cout << pos;
		v1.push_back(elemento);
		sites.erase(0, pos + delimiter.length());
	}

	while ((pos = sites.find(delimiter)) != string::npos)
	{
		elemento = sites.substr(0, pos);
		//cout << elemento << endl;
		//cout << pos;
		v1.push_back(elemento);
		sites.erase(0, pos + delimiter.length());
	}

	v1.push_back(sites);

	return v1;
}

vector<string> formatar_criar_locais(string sites)
{
	string local;
	vector<string> locais; // vetor com os locais
	istringstream instr(sites);

	while (instr >> local)
	{
		locais.push_back(local);
	}

	return locais;
}


bool verificar_cliente(Agency agency, unsigned NIF)
{
	vector<Client> clients = agency.getClients();

	for (size_t i = 0; i < clients.size(); i++)
	{
		if (NIF == clients[i].getNIF())
		{
			cout << endl << endl << endl;
			cout << "O NIF introduzido pretence ao cliente:" << endl << endl;
			cout << clients[i];
			cout << endl << endl << endl;
			system("pause");
			return true;  //cliente existe
		}
	}

	return false; // cliente não existe
}

int procurar_cliente(Agency agency)
{
	vector<Client> clients = agency.getClients();

	unsigned NIF;
	cout << "(0) Voltar" << endl;
	cout << "Insira o NIF do cliente : " << endl;

	NIF = verificar_input();

	if (NIF == 0)
		return -1; //voltar

	system("cls");

	bool temp = false;
	Client c1;

	for (int i = 0; i < clients.size(); i++)
	{
		if (NIF == clients[i].getNIF())
		{
			c1 = clients[i];
			cout << c1 << endl << endl << endl;

			system("pause");
			temp = true;
			return i;
		}
	}

	if (!temp)
	{
		cout << "Cliente nao encontrado" << endl << endl << endl;
		system("pause");
	}

	return -1;
}

void apagar_cliente(Agency &agency)
{
	vector<Client> clientes = agency.getClients();
	string verificar;
	int index;
	index = procurar_cliente(agency);

	if (index > -1)
	{
		cout << "Deseja apagar o cliente? " << endl;
		cout << " sim || nao : ";
		getline(cin, verificar);
		if (verificar == "sim" || verificar == "SIM" || verificar == "s" || verificar == "S")
		{
			clientes.erase(clientes.begin() + index);
			agency.setClients(clientes);
			agency.setClientsInfoHasChanged(true);
		}
	}
}

Client criar_cliente(Agency &agency)
{
	Client c1; //novo cliente
	Client erro; //cliente erro
	string temp; // string temporaria
	int intemp; // int temporario
	Address clientAddress; // morada do cliente
	vector<Packet> pacotesinfo; // pacotes comprados por o cliente
	vector<Client> clientes = agency.getClients();

	cout << "(0) Voltar" << endl;
	cout << "Nome do cliente:" << endl;
	getline(cin, temp);

	if (temp == "0")
		return erro;

	c1.setName(temp);

	do {
		cout << "NIF: " << endl << " * (-1 para sair) * " << endl;
		intemp = verificar_input();
		if (intemp == -1)
			return erro; // retorna cliente erro
	} while (verificar_cliente(agency, intemp));

	c1.setNIF(abs(intemp));

	cout << "Agregado familiar: " << endl;
	getline(cin, temp);
	c1.setFamilySize(stoul(temp));


	cout << "Morada" << endl << "rua: ";
	getline(cin, temp);
	clientAddress.setStreet(temp);

	cout << "porta: ";
	getline(cin, temp);
	clientAddress.setDoorNumber(stoul(temp));

	cout << "andar:  ( '-'  se nao aplicavel) " << endl;
	getline(cin, temp);
	clientAddress.setFloor(temp);

	cout << "codigo postal: ";
	getline(cin, temp);
	clientAddress.setPostalCode(temp);

	cout << "localidade: ";
	getline(cin, temp);
	clientAddress.setLocation(temp);

	c1.setAddress(clientAddress);


	cout << "pacotes turisticos comprados: " << endl << " * separar pacotes por espacos ' ' * " << endl;
	getline(cin, temp);
	pacotesinfo = formatar_criar_pacote(temp);
	c1.setPacketList(pacotesinfo);

	cout << "valor total de compras efetuadas: " << endl;
	getline(cin, temp);
	c1.setTotalPurchased(stoul(temp));

	system("cls");

	cout << c1;

	cout << "Pretende criar o cliente?" << endl;
	cout << " sim || nao : ";
	getline(cin, temp);
	if (temp == "sim" || temp == "SIM" || temp == "s" || temp == "S")
	{
		clientes.push_back(c1);
		agency.setClients(clientes);
		agency.setClientsInfoHasChanged(true);
		return c1; // retorna o novo cliente
	}
	else
	{
		return erro; // retorna cliente com o nome erro, para ser eliminado mais tarde
	}
}

void mostrar_clientes(Agency agency)
{
	vector<Client> clientes = agency.getClients();

	//CICLO QUE PERMITE VISUALIZAR OS CLIENTES
	for (int i = 0; i < clientes.size(); i++)
	{
		cout << clientes[i];
		if (i != clientes.size() - 1)
		{
			cout << "::::::::::" << endl;
		}
	}
}

void save_clients(Agency agency)
{
	string filename = agency.getFilenameClients();
	vector<Client> clientes = agency.getClients();
	ofstream file;
	file.open(filename);

	if (!file.is_open())
	{
		cerr << "Error opening " << filename << endl;
	}

	for (int i = 0; i < clientes.size(); i++)
	{
		file << clientes[i];
		if (i != clientes.size() - 1)
		{
			file << "::::::::::" << endl;
		}
	}

	file.close();
}

void editar_cliente(Agency &agency)
{
	int clientspot;   //posição do cliente
	int option; //opção do menu
	vector<Client> c = agency.getClients();
	vector<Packet> pacotesinfo; // lista de pacotes comprados por o cliente
	string temp;

	string name;
	unsigned nif;
	unsigned short family;
	unsigned  totalPurchased;
	Address clientAddress;
	bool exit = false;

	clientspot = procurar_cliente(agency); //procura o cliente

	if (clientspot != -1) {
		do {
			system("cls");

			cout << "Escolha o que pretende editar" << endl
				<< "(1) Nome" << endl
				<< "(2) NIF" << endl
				<< "(3) Agregado Familiar" << endl
				<< "(4) Morada" << endl
				<< "(5) Lista de pacotes turisticos comprados" << endl
				<< "(6) Total de compras efetuadas" << endl
				<< "(7) Voltar" << endl;

			option = verificar_opcao(1, 7);
			system("cls");

			switch (option) 
			{

			case 1:  //para mudar o nome
				cout << "Nome do cliente: " << c[clientspot].getName() << endl;  //nome atual
				cout << "Introduza o novo Nome do cliente: ";   //novo nome
				getline(cin, name);
				c[clientspot].setName(name);   // define o novo nome do cliente no index do vetor cliente
				cout << "Alterou o nome para " << c[clientspot].getName() << endl;   //mostra o nome novo

				agency.setClients(c);
				agency.setClientsInfoHasChanged(true);

				break;

			case 2:  //para mudar o NIF

				cout << "NIF do cliente: " << c[clientspot].getNIF() << endl;  //NIF atual
				cout << "Introduza o novo NIF do cliente: " ;   //novo NIF
				nif = verificar_input();
				c[clientspot].setNIF(nif);   //define o novo NIF
				agency.setClients(c);
				agency.setClientsInfoHasChanged(true);
				cout << "Alterou o NIF para: " << c[clientspot].getNIF() << endl;   //mostra o novo NIF
				break;

			case 3:  //para mudar o agregado
				cout << "Numero de pessoas no agregado familiar: " << c[clientspot].getFamilySize() << endl;   //atual
				cout << "Introduza o novo Numero de pessoas no agregado familiar: ";  //novo
				family = verificar_input();
				c[clientspot].setFamilySize(family);  //define o novo

				agency.setClients(c);
				agency.setClientsInfoHasChanged(true);
				cout << "Alterou o Numero de pessoas no agregado familiar para " << c[clientspot].getFamilySize() << endl;  //mostra o novo
				break;

			case 4:   //para alterar morada
				cout << "Morada do cliente: " << c[clientspot].getAddress() << endl;
				cout << "Introduza a nova Morada do cliente: ";   //nova morada
				cout << endl << "rua: ";
				getline(cin, temp);
				clientAddress.setStreet(temp);

				cout << "porta: ";
				getline(cin, temp);
				clientAddress.setDoorNumber(stoul(temp));

				cout << "andar:  ( '-'  se nao aplicavel) " << endl;
				getline(cin, temp);
				clientAddress.setFloor(temp);

				cout << "codigo postal: ";
				getline(cin, temp);
				clientAddress.setPostalCode(temp);

				cout << "localidade: ";
				getline(cin, temp);
				clientAddress.setLocation(temp);

				c[clientspot].setAddress(clientAddress); //define nova morada

				agency.setClients(c);
				agency.setClientsInfoHasChanged(true);
				cout << "Alterou a morada para: " << c[clientspot].getAddress() << endl;   //mostra a nova morada

				break;

			case 5:  //se tentar alterar a lista de Pacotes turisticos comprados
				cout << "Lista dos pacotes comprados pelo cliente: ";
				if (c[clientspot].getPacketList().size() >= 1)
				{
					int i = 0;
					for (i; i < c[clientspot].getPacketList().size() - 1;)
					{
						cout << c[clientspot].getPacketList()[i].getId() << " ; ";
						i++;
					}
					cout << c[clientspot].getPacketList()[i].getId() << endl;
				}
				else
				{
					cout << endl;
				}

				cout << "Nova lista de pacotes comprados pelo cliente: " ;
				cout << endl << " * separar pacotes por espacos ' ' * " << endl;
				getline(cin, temp);
				pacotesinfo = formatar_criar_pacote(temp);
				c[clientspot].setPacketList(pacotesinfo);

				agency.setClients(c);
				agency.setClientsInfoHasChanged(true);
				cout << "Alterou a lista de pacotes comprados para: ";

				if (c[clientspot].getPacketList().size() >= 1)
				{
					int i = 0;
					for (i; i < c[clientspot].getPacketList().size() - 1;)
					{
						cout << c[clientspot].getPacketList()[i].getId() << " ; ";
						i++;
					}
					cout << c[clientspot].getPacketList()[i].getId() << endl;
				}
				else
				{
					cout << endl;
				}								//mostra a nova morada

				break;

			case 6:   //se tentar alterar o total de compras efetuadas
				cout << "Total de compras do cliente: " << c[clientspot].getTotalPurchased() << endl;
				cout << "Introduza o novo total de compras do cliente: "; 
				totalPurchased = verificar_input();
				c[clientspot].setTotalPurchased(totalPurchased);  
				agency.setClients(c);
				agency.setClientsInfoHasChanged(true);
				cout << "Alterou o total de compras para: " << c[clientspot].getTotalPurchased() << endl;   
				break;

			case 7:
				exit = true;
				break;

			default:
				break;

			}

			if (!exit)
			{
				cout << "Deseja editar mais algum dado de cliente? " << endl;
				cout << " sim || nao : ";
				getline(cin, temp);
			}
			
			system("cls");
		} while (temp == "sim" || temp == "SIM" || temp == "s" || temp == "S");

	}

}


bool verificar_pacote(Agency agency, int ID)
{
	vector<Packet> packets = agency.getPackets();

	for (size_t i = 0; i < packets.size(); i++)
	{
		if (ID == abs(packets[i].getId()))
		{
			cout << endl << endl << endl;
			cout << "O ID introduzido pertence ao pacote:" << endl << endl;
			cout << packets[i];
			cout << endl << endl << endl;
			system("pause");
			return true; //o pacote existe
		}
	}
	return false; //o pacote não existe
}

int procurar_pacote(Agency agency)
{
	vector<Packet> packets = agency.getPackets();

	int ID;
	cout << "(0) Voltar" << endl;
	cout << "Insira o ID do pacote: " << endl;
	ID = verificar_input();

	if (ID == 0)
		return -1;

	system("cls");

	bool temp = false;
	Packet p1;

	for (int i = 0; i < packets.size(); i++)
	{
		if (ID == abs(packets[i].getId()))
		{
			p1 = packets[i];
			cout << p1 << endl << endl << endl;

			system("pause");
			temp = true;
			return i;
		}
	}
	if (!temp)
	{
		cout << "Pacote nao encontrado" << endl << endl << endl;
		system("pause");
	}
	return -1;
}

int procurar_pacote_locais(Agency agency)
{
	vector<Packet> p = agency.getPackets();
	vector<string> locais;
	string local;

	cout << "(0) Voltar" << endl;
	cout << "Insira o Local turistico a visitar: " << endl;
	getline(cin, local);

	if (local == "0")
		return -1;

	system("cls");

	bool temp = false;

	for (int i = 0; i < p.size(); i++)
	{
		locais = p[i].getSites();
		for (int j = 0; j < locais.size(); j++)
		{
			if (local == locais[j])
			{
				cout << p[i] << endl << endl << endl;
				temp = true;
			}
			
		}
	}

	system("pause");

	if (!temp)
	{
		cout << "Pacote nao encontrado" << endl << endl << endl;
		system("pause");
	}
	return -1;
}

void apagar_pacote(Agency &agency)
{
	vector<Packet> pacotes = agency.getPackets();
	string verificar;
	int index;
	index = procurar_pacote(agency);


	if (index > -1)
	{
		cout << "Deseja apagar o cliente?" << endl;
		cout << " sim || nao : ";
		getline(cin, verificar);
		if (verificar == "sim" || verificar == "SIM" || verificar == "s" || verificar == "S")
		{
			pacotes.erase(pacotes.begin() + index);
			agency.setPackets(pacotes);
			agency.setPacketsInfoHasChanged(true);
		}
	}

}

void indisponivel_pacote(Agency &agency)
{
	vector<Packet> pacotes = agency.getPackets();
	string verificar;
	int index;
	int id;
	index = procurar_pacote(agency);


	if (index > -1)
	{
		id = pacotes[index].getId();
		cout << "Deseja alterar a disponiblidade do pacote? " << endl;
		cout << " sim || nao : ";
		getline(cin, verificar);
		if (verificar == "sim" || verificar == "SIM" || verificar == "s" || verificar == "S")
		{
			id = -1 * id;
			pacotes[index].setId(id);
			agency.setPackets(pacotes);
			agency.setPacketsInfoHasChanged(true);
		}
	}
}

Packet criar_pacote(Agency &agency)
{
	Packet p1, erro;
	string temp;
	int intemp;
	bool btemp;
	btemp = true;

	int option; // opção para sair da função
	vector<string> locais; // locais turisticos
	Date packetBeginDate; //data de inicio
	Date packetEndDate; //data de termino
	vector<Packet> pacotes = agency.getPackets();

	do {
		system("cls");
		cout << "(0) Voltar" << endl;
		cout << "Identificador numerico unico do pacote " << endl;
		option = verificar_input();

		if (option == 0)
			return erro; // retorna pacote vazio
		else
			intemp = option;
	} while (verificar_pacote(agency, intemp));

	p1.setId(intemp);

	cout << "Local(ais) turistico(s) a visitar: " << endl << " * ( 1 para continuar) * " << endl;
	do {
		getline(cin, temp);
		if (temp == "1")
		{
			btemp = false;
			break;
		}
		locais.push_back(temp);

	} while (btemp);

	p1.setSites(locais);


	cout << "Data de inicio da viagem" << endl << "Ano: ";
	getline(cin, temp);
	packetBeginDate.setYear(stoul(temp));

	cout << "Mes:";
	getline(cin, temp);
	packetBeginDate.setMonth(stoul(temp));

	cout << "Dia:";
	getline(cin, temp);
	packetBeginDate.setDay(stoul(temp));

	p1.setBeginDate(packetBeginDate);

	cout << "Data de fim da viagem" << endl << "Ano: ";
	getline(cin, temp);
	packetEndDate.setYear(stoul(temp));

	cout << "Mes:";
	getline(cin, temp);
	packetEndDate.setMonth(stoul(temp));

	cout << "Dia:";
	getline(cin, temp);
	packetEndDate.setDay(stoul(temp));

	p1.setEndDate(packetEndDate);

	cout << "Preco por pessoa: " << endl;
	getline(cin, temp);
	p1.setPricePerPerson(stod(temp));

	cout << "Numero maximo de lugares disponiveis no pacote: " << endl;
	getline(cin, temp);
	p1.setMaxPersons(stoul(temp));

	cout << "Numero de lugares ja reservados: " << endl;
	getline(cin, temp);
	p1.setReserved(stoul(temp));

	system("cls");

	cout << p1;

	cout << "Pretende criar o pacote?" << endl;
	cout << " sim || nao : ";
	getline(cin, temp);

	if (temp == "sim" || temp == "SIM" || temp == "s" || temp == "S")
	{
		pacotes.push_back(p1);
		agency.setPackets(pacotes);
		agency.setPacketsInfoHasChanged(true);
		return p1;  //retorna o novo pacote
	}
	else
	{
		return erro; // retorna pacote com erro, para ser eliminado mais tarde
	}
}

void mostrar_pacotes(Agency agency)
{
	vector<Packet> pacotes = agency.getPackets();

	//CICLO QUE PERMITE VISUALIZAR OS PACOTES
	for (int i = 0; i < pacotes.size(); i++)
	{
		cout << pacotes[i];
		if (i != pacotes.size() - 1)
		{
			cout << "::::::::::" << endl;
		}
	}
}

void save_packs(Agency agency)
{
	string filename = agency.getFilenamePackets();
	vector<Packet> pacotes = agency.getPackets();
	ofstream file;
	file.open(filename);

	if (!file.is_open())
	{
		cerr << "Error opening " << filename << endl;
	}

	unsigned lastid;
	lastid = abs(pacotes.back().getId());

	file << lastid << endl;

	for (int i = 0; i < pacotes.size(); i++)
	{
		file << pacotes[i];
		if (i != pacotes.size() - 1)
		{
			file << "::::::::::" << endl;
		}
	}
	file.close();
}

void visualize_totalsold(Agency agency)
{
	unsigned totalNum = 0; // numero total de pacotes vendidos
	double totalValue = 0; // valor total de pacotes vendidos
	for (int i = 0; i < agency.getPackets().size(); i++)
	{
		unsigned num; // numero de pacotes vendidos
		unsigned value; // valor do pacote vendido
		vector<Packet> pacotes = agency.getPackets();

		num = pacotes[i].getReserved();
		totalNum = totalNum + num;

		value = pacotes[i].getPricePerPerson() * num;
		totalValue = totalValue + value;
	}

	cout << "Numero total de pacotes vendidos: " << totalNum << endl;
	cout << "Valor total de pacotes vendidos: " << totalValue << endl;
	cout << endl << endl;

	system("pause");
}

void comprar_pacote(Agency &agency) 
{
	int packspot, clientspot; // indices dos pacotes e dos clientes nos vetores respetivos
	string temp;
	Client erro;
	vector<Packet> p = agency.getPackets();
	vector<Client> c = agency.getClients();

	packspot = procurar_pacote(agency);   // procura o indice do pacote a ser comprado

	

	if (packspot != -1)   //se o packspot == -1 o pacote não existe
	{
		if (p[packspot].getId() < 0)
		{
			cout << endl;
			cout << "Pacote indisponivel" << endl;

			system("pause");
			return;
		}

		
		clientspot = procurar_cliente(agency);

		if (clientspot == -1) // se nao encontra o cliente
		{

			cout << "(1) criar cliente" << endl;
			cout << "(2) cancelar" << endl;

			clientspot = verificar_opcao(1, 2);

			switch (clientspot)
			{
			case 1:
				system("cls");
				erro = criar_cliente(agency);
				if (erro.getNIF() == 0) // sair da função
					return;
				c = agency.getClients();
				clientspot = c.size() - 1 ; // indice do novo cliente é o indice do fim do vetor
				break;
			case 2:
				return ;
			default:
				break;
			}
		}
		
		vector<Packet> pacotesDoCliente = c[clientspot].getPacketList();

		for (int i = 0; i < pacotesDoCliente.size(); i++)
		{
			if (p[packspot].getId() == pacotesDoCliente[i].getId())
			{
				cout << "Cliente ja comprou o pacote pretendido" << endl << endl << endl;
				system("pause");
				return;
			}
		}

		if (verifica_compra(agency,packspot,clientspot))   
		{

			system("cls");

			vector<Packet> pacoteclientes = c[clientspot].getPacketList();  //pacotes comprados por um cliente
			pacoteclientes.push_back(p[packspot].getId()); // põe o pacote comprado no vetor
			c[clientspot].setPacketList(pacoteclientes);   //adiciona o pacote à lista de pacotes do cliente

			unsigned totalspent = c[clientspot].getTotalPurchased();
			totalspent = totalspent + (p[packspot].getPricePerPerson() * c[clientspot].getFamilySize());
			c[clientspot].setTotalPurchased(totalspent);   //atualiza o valor total gasto do cliente

			unsigned vendidos = p[packspot].getReserved();
			vendidos = vendidos + (c[clientspot].getFamilySize());
			p[packspot].setReserved(vendidos);   //atualiza as reservas desse pacote

			agency.setClients(c);
			agency.setClientsInfoHasChanged(true);
			agency.setPackets(p);
			agency.setPacketsInfoHasChanged(true);

			cout << "Compra efetuada com sucesso" << endl;
			system("pause");
		}
	}
}

void editar_pacote(Agency &agency)
{
	int packspot; 
	int option;
	string temp;
	vector<Packet> p = agency.getPackets();

	int id;
	vector<string> locais; // novos locais
	Date newDate; // nova data
	double price;
	unsigned max;
	bool btemp = true;
	bool exit;
	exit = false;

	packspot = procurar_pacote(agency);
	system("cls");

	if (packspot != -1) {
		do {
			cout << "Escolha o que pretende editar" << endl
				<< "(1) Identificador Unico" << endl
				<< "(2) Locais turisticos" << endl
				<< "(3) Data de inicio" << endl
				<< "(4) Data de fim" << endl
				<< "(5) Preco por pessoa" << endl
				<< "(6) Numero maximo de lugares" << endl
				<< "(7) Numero de lugares ja reservados" << endl
				<< "(8) Voltar" << endl;

			option = verificar_opcao(1, 8);
			system("cls");

			switch (option) {
			case 1:
				cout << "Identificador Unico do Pacote: " << p[packspot].getId() << endl;
				cout << "Novo Identificador Unico: ";
				id = verificar_input();
				p[packspot].setId(id);
				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Alterou o Identificador Unico do Pacote para " << p[packspot].getId() << endl;
				break;

			case 2:
				cout << "Destino(s) do pacote: " << endl;
				cout << p[packspot].getSites().at(0);

				if (p[packspot].getSites().size() > 1)
				{
					cout << " -";
					int i = 1;
					for (i; i < p[packspot].getSites().size() - 1;)
					{
						cout << p[packspot].getSites().at(i) << ", ";
						i++;
					}
					cout << p[packspot].getSites().at(i) << endl;
				}
				else
				{
					cout << endl;
				}

				locais.clear();

				cout << "Novo Destino(s): "  << endl << " * ( 1 para continuar) * " << endl;
				do {
					getline(cin, temp);
					if (temp == "1")
					{
						btemp = false;
						break;
					}
					locais.push_back(temp);

				} while (btemp);

				p[packspot].setSites(locais);
				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Destino(s) alterado(s) com sucesso" << endl;
				break;

			case 3:
				cout << "Data de inicio de viagem: " << p[packspot].getBeginDate() << endl;
				cout << "Nova data de inicio de viagem: " << endl << "Ano: ";
				getline(cin, temp);
				newDate.setYear(stoul(temp));

				cout << "Mes:";
				getline(cin, temp);
				newDate.setMonth(stoul(temp));

				cout << "Dia:";
				getline(cin, temp);
				newDate.setDay(stoul(temp));

				p[packspot].setBeginDate(newDate);

				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Alterou a data de inicio de viagem para " << p[packspot].getBeginDate() << endl;
				break;

			case 4:
				cout << "Data de fim de viagem: " << p[packspot].getEndDate() << endl;
				cout << "Nova data de fim de viagem: " << endl << "Ano: ";
				getline(cin, temp);
				newDate.setYear(stoul(temp));

				cout << "Mes:";
				getline(cin, temp);
				newDate.setMonth(stoul(temp));

				cout << "Dia:";
				getline(cin, temp);
				newDate.setDay(stoul(temp));

				p[packspot].setEndDate(newDate);

				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Alterou a data de fim de viagem para " << p[packspot].getBeginDate() << endl;
				break;

			case 5:
				cout << "Preco por pessoa currente do pacote: " << p[packspot].getPricePerPerson() << endl;
				cout << "Introduza o novo preco por pessoa: ";
				getline(cin, temp);
				price = stod(temp);
				p[packspot].setPricePerPerson(price);

				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Alterou o preco por pessoa para " << p[packspot].getPricePerPerson() << endl;
				break;

			case 6:
				cout << "Numero maximo de lugares disponiveis: " << p[packspot].getMaxPersons() << endl;
				cout << "Introduza o Novo numero maximo de lugares: ";
				max = verificar_input();
				p[packspot].setMaxPersons(max);
				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Alterou o Numero maximo de lugares disponiveis para " << p[packspot].getMaxPersons() << endl;
				break;

			case 7:

				cout << "Numero de lugares ja reservados por pacote: " << p[packspot].getReserved() << endl;
				cout << "Introduza o Novo numero maximo de lugares: ";
				max = verificar_input();
				p[packspot].setReserved(max);
				agency.setPackets(p);
				agency.setPacketsInfoHasChanged(true);
				cout << "Alterou o Numero maximo de lugares disponiveis para " << p[packspot].getReserved();
				break;

			case 8:
				exit = true;
				break;

			default:
				break;
			}

			if (!exit)
			{
				cout << "Deseja editar mais algum dado de cliente? " << endl;
				cout << " sim || nao : ";
				getline(cin, temp);
			}
			
			system("cls");
		} while (temp == "sim" || temp == "SIM" || temp == "s" || temp == "S");

	}

}

void pacotes_vendidos_cliente(Agency &agency)
{
	
	int indexClient = procurar_cliente(agency);

	system("cls");

	vector<Client> c = agency.getClients();
	vector<Packet> p = agency.getPackets();
	vector<Packet> pc = c[indexClient].getPacketList();

	for (int i = 0; i < c[indexClient].getPacketList().size(); i++)
	{
		
		for (int j = 0; j < p.size(); j++)
		{
			
			if (pc[i].getId() == abs(p[j].getId()))
			{
				cout << p[j];
				cout << endl << endl << endl;
			}
		}
	}
	system("pause");
}

/*
void pacotes_vendidos_total(Agency &agency)
{
	vector<Client> c = agency.getClients();
	vector<Packet> p = agency.getPackets();
	vector<Packet> temp;

	for (int i = 0; i < c.size(); i++)
	{
		vector<Packet> pc = c[i].getPacketList();

		for (int j = 0; j < p.size(); j++)
		{
			for (int k = 0; k < pc.size(); k++)
			{
				if (pc[k].getId() == abs(p[j].getId()))
				{
					temp.push_back(p[j]);
				}
			}
			
		}
	}

	remove(temp);

	for (int z = 0; z < temp.size(); z++)
	{
		cout << temp[z];
	}

	cout << endl << endl << endl;
	system("pause");
}

void remove(vector<Packet> &v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) 
	{
		end = remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}
*/
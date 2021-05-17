#include "Menus.h"

unsigned mainMenu(Agency &agency)
{

	int option;

	cout << setfill(' ') << setw(24) << agency.getName() << endl << endl;
	cout << "(1) Gerir clientes" << endl;
	cout << "(2) Gerir pacotes turisticos" << endl;
	cout << "(3) Mostrar agencia" << endl;
	cout << "(4) Sair do programa" << endl;

	option = verificar_opcao(1, 4);

	system("cls");


	switch (option)
	{
	case 1:
		menu_clientes(agency);
		break;
	case 2:
		menu_pacotes(agency);
		break;

	case 3:
		cout << agency << endl;
		system("pause");
		break;

	case 4:
		if (agency.getClientsInfoHasChanged())
			save_clients(agency);
		if(agency.getPacketsInfoHasChanged())
			save_packs(agency);

		exit(0);
	default:
		break;
	}

	return 0;
}

void menu_clientes(Agency &agency)
{
	int option;
	cout << setfill(' ') << setw(24) << agency.getName() << endl;
	cout << setfill(' ') << setw(24) << "**CLIENTES**" << endl << endl;
	cout << "(1) Criar cliente" << endl;
	cout << "(2) Alterar cliente" << endl;
	cout << "(3) Apagar cliente" << endl;
	cout << "(4) Ver clientes" << endl;
	cout << "(5) Voltar" << endl;

	option = verificar_opcao(1, 5);

	system("cls");

	switch (option)
	{
	case 1:
		criar_cliente(agency);
		break;
	case 2:
		editar_cliente(agency);
		break;
	case 3:
		apagar_cliente(agency);
		break;
	case 4:
		menu_mostrar_clientes(agency);
		break;
	case 5:
		break;
	default:
		break;
	}

}

void menu_pacotes(Agency &agency)
{
	int option;
	cout << setfill(' ') << setw(30) << agency.getName() << endl;
	cout << setfill(' ') << setw(35) << "**PACOTES TURISTICOS**" << endl << endl;
	cout << "(1) Criar pacote" << endl;
	cout << "(2) Alterar pacote" << endl;
	cout << "(3) Apagar pacote" << endl;
	cout << "(4) Ver pacotes" << endl;
	cout << "(5) Comprar um pacote" << endl;
	cout << "(6) Mostrar o numero e o valor total de pacotes vendidos" << endl;
	cout << "(7) Voltar" << endl;

	option = verificar_opcao(1, 7);

	system("cls");

	switch (option)
	{
	case 1:
		criar_pacote(agency);
		break;

	case 2:
		editar_pacote(agency);
		break;

	case 3:
		cout << "(0) voltar" << endl;
		cout << "(1) colocar como indisponivel" << endl;
		cout << "(2) remover " << endl;

		option = verificar_opcao(0, 2);
		switch (option)
		{
		case 0:
			break;

		case 1:
			indisponivel_pacote(agency);
			break;

		case 2:
			apagar_pacote(agency);
			break;
		}

		break;

	case 4:
		menu_mostrar_pacotes(agency);
		break;

	case 5:
		comprar_pacote(agency);
		break;

	case 6:
		visualize_totalsold(agency);
		break;

	case 7:
		break;
	default:
		break;
	}
}

void menu_mostrar_pacotes(Agency &agency)
{
	int option;
	cout << setfill(' ') << setw(30) << agency.getName() << endl;
	cout << setfill(' ') << setw(35) << "**PACOTES TURISTICOS**" << endl << endl;
	cout << "(1) Mostrar todos os pacotes" << endl;
	cout << "(2) Procurar pacote" << endl;
	cout << "(3) Pacotes vendidos" << endl;
	cout << "(4) Voltar" << endl;

	option = verificar_opcao(1, 4);

	system("cls");

	switch (option)
	{
	case 1:
		mostrar_pacotes(agency);
		cout << endl << endl << endl;
		system("pause");
		break;

	case 2:
		menu_procurar_pacotes(agency);
		break;

	case 3:
		menu_pacotes_vendidos(agency);
		break;

	default:
		break;
	}
}

void menu_procurar_pacotes(Agency &agency)
{
	int option;
	cout << setfill(' ') << setw(30) << agency.getName() << endl;
	cout << setfill(' ') << setw(35) << "**PACOTES TURISTICOS**" << endl << endl;
	cout << "(1) Procurar pacote por ID" << endl;
	cout << "(2) Procurar pacote por local turistico" << endl;
	cout << "(3) Procurar pacote entre 2 datas" << endl;
	cout << "(4) Procurar pacote por local turistico e entre 2 datas" << endl;
	cout << "(5) Voltar" << endl;

	option = verificar_opcao(1, 5);

	system("cls");

	switch (option)
	{
	case 1:
		procurar_cliente(agency);
		break;

	case 2:
		procurar_pacote_locais(agency);
		break;
	case 3:
		//a implementar
		break;

	case 4:
		// a implementar
		break;

	case 5:
		break;

	default:
		break;
	}
}

void menu_pacotes_vendidos(Agency &agency)
{
	int option;
	cout << setfill(' ') << setw(30) << agency.getName() << endl;
	cout << setfill(' ') << setw(35) << "**PACOTES TURISTICOS**" << endl << endl;
	cout << "(1) Pacotes vendidos" << endl;
	cout << "(2) Pacotes vendidos a um cliente" << endl;
	cout << "(3) Voltar" << endl;

	option = verificar_opcao(1, 3);

	system("cls");

	switch (option)
	{
	case 1:
		// a implementar
		break;

	case 2:
		pacotes_vendidos_cliente(agency);
		break;
	case 3:
		//pacotes_vendidos_total(agency);
		break;

	default:
		break;
	}
}

void menu_mostrar_clientes(Agency &agency)
{
	int option;
	cout << setfill(' ') << setw(24) << agency.getName() << endl;
	cout << setfill(' ') << setw(24) << "**CLIENTES**" << endl << endl;
	cout << "(1) Mostrar todos os clientes" << endl;
	cout << "(2) Procurar cliente" << endl;
	cout << "(3) Voltar" << endl;

	option = verificar_opcao(1, 3);

	system("cls");

	switch (option)
	{
	case 1:
		mostrar_clientes(agency);
		cout << endl << endl << endl;
		system("pause");
		break;

	case 2:
		procurar_cliente(agency);
		break;

	case 3:
		break;

	default:
		break;
	}
}





/*
//initial values
int k = 0;
int selection = 0;
string username = "0";
string password = "0";
int launchcode = 1;

//setting up the menu
void menu();
void setpassword();
void setlaunch();
void login();
void launch();
void exit();

//what we want the menu to display
void menu()
{
	cout << endl;
	cout << "Welcome to our agency program!\n";
	cout << "                                     \n";
	cout << "~~~~~~~~~~~~  Initial Login Menu ~~~~~~~~~~~~\n";
	cout << " Choose one of the options above. Enter just a number. - \n";
	cout << " 1. Create client username and password.\n";
	cout << " 2. Create launch codes.\n";
	cout << " 3. Login.\n";
	cout << " 4. Enter launch codes.\n";
	cout << " 5. Exit menu.\n";
	cout << " ";
	cin >> selection;

	//selection entries
	if (selection == 1)
	{
		setpassword();
	}
	else if (selection == 2)
	{
		setlaunch();
	}
	else if (selection == 3)
	{
		login();
	}
	else if (selection == 4)
	{
		launch();
	}
	else if (selection == 5)
	{
		exit();
	}
}

//setting up a password and an username
//we can set up a client and admnistrator username and password when we start running the code
//entry 1
void setpassword()
{
	cout << " Please enter new username - ";
	cin >> username;
	cout << " Please enter new password - ";
	cin >> password;
	cout << endl;
	cout << " ** NEW USER CREDENTIALS ACCEPTED **\n";
}

//entry 2 SET LAUNCH
// **********forwarding to the next menu here!!! **************
void setlaunch()
{
	cout << " Please enter a new launch code - ";
	cin >> launchcode;
	cout << endl;
	cout << " ** NEW LAUNCH CODE ACCEPTED **\n";
}

//entry 3 LOGIN
void login()
{
	string usertest;
	string passtest;

	if (username != "0" | password != "0") //make sure a username/password has been set!
	{
		for (int i = 0; i < 5; i++)
		{
			cout << " Please enter username - ";
			cin >> usertest;
			cout << " Please enter password - ";
			cin >> passtest;

			if (username != usertest | password != passtest)
			{
				cout << endl;
				cout << " USERNAME OR PASSWORD NOT RECOGNISED\n";
			}
			else
			{
				cout << endl;
				cout << " Data Accepted\n";
				break;
			}
		}
	}

	else
	{
		cout << endl;
		cout << " NO USERNAME OR PASSWORD SET!.\n";
	}
}

//entry 4 LAUNCH CODE
void launch()
{
	int launchtest;

	if (launchcode != 1)
	{
		cout << endl;
		cout << " Please enter launch code - ";
		cin >> launchtest;

		if (launchtest == launchcode)
		{
			cout << endl;
			cout << " ** LAUNCHED **\n";
		}
		else
		{
			cout << endl;
			cout << " Launch code incorrect\n";
		}
	}
	else
	{
		cout << endl;
		cout << " NO LAUNCH CODE SET\n";
	}



}

//entry 5 EXIT (exiting the login menu)
void exit()
{
	cout << endl;
	cout << " you just exited!\n";
	k = 1;
}

int main()
{
	while (true)
	{
		cout << endl;
		if (k == 1)
		{
			break;
		}
		menu();
	}
	return 0; //returns 0 if the code is working successfully :)
}
*/
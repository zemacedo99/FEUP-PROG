#include <iostream>
#include <string>
#include <vector>

#include "Agency.h"
#include "Menus.h"

#include "FilesFunctions.h"
//#include "utils.h"

int main()
{
	//Agency agency(AGENCY_FILE_NAME);   // create the agency
	string filename;
	filename = escolher_ficheiro();

	Agency agency(filename);

	
	while (true)
	{
		system("cls");
		mainMenu(agency); // initial menu inicial with the major options of the application
	}

	return 0;
}


#pragma once

#include "Agency.h"
#include "FilesFunctions.h"

// main menu
unsigned mainMenu(Agency &agency);

// menu dos clientes
void menu_clientes(Agency & agency);

// menu dos pacotes
void menu_pacotes(Agency & agency);

// menu para ver os pacotes
void menu_mostrar_pacotes(Agency & agency);

// menu para procurar pacotes
void menu_procurar_pacotes(Agency & agency);

// menu para ver os pacotes vendidos
void menu_pacotes_vendidos(Agency & agency);

// menu para ver os clientes
void menu_mostrar_clientes(Agency & agency);

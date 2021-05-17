#pragma once
#include "Address.h"
#include "Packet.h"
#include "Agency.h"
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <algorithm> 
#include <cstdlib>

// pede ao utilizador para inserir o nome do ficheito de texto pretendido
string escolher_ficheiro();

// verifica se a opção do utilizador é valida
int verificar_opcao(int optionlower, int optionuper);

// verifica se o input do utilizador é valido
int verificar_input();

// verifica se é possivel comprar um determinado pacote
bool verifica_compra(Agency agency, int packindex, int clientindex);


/*********************************
		Funções de formatar
 ********************************/


// formata a morada *string to Address*
Address formatar_morada(string morada);

// formata os pacotes dos clientes *string to vector<Packet>*
vector<Packet> formatar_pacotes(string pacotes);

// formata os pacotes dos clientes ao criar o cliente *string to vector<Packet>*
vector<Packet> formatar_criar_pacote(string pacotesinfo);

// formata os locais turisticos *string to vector<string>*
vector<string> formatar_locais(string sites);

// formata os locais turisticos ao criar o pacote *string to vector<Packet>*
vector<string> formatar_criar_locais(string sites);


/*********************************
		Funções de clientes
 ********************************/


// verifica se o cliente já existe
bool verificar_cliente(Agency agency, unsigned NIF);

// procura cliente por NIF
int procurar_cliente(Agency agency);

// apaga um cliente do vetor de clientes
void apagar_cliente(Agency &agency);

// cria um novo cliente
Client criar_cliente(Agency &agency);

// função que mostra todos os clientes no ecra
void mostrar_clientes(Agency agency);

// guarda os clientes no ficheiro dos clientes
void save_clients(Agency agency);

// editar cliente
void editar_cliente(Agency &agency);


/*********************************
		Funções de pacotes
 ********************************/


// verifica se o pacote já existe
bool verificar_pacote(Agency agency, int ID);

// procura pacote por Id
int procurar_pacote(Agency agency);

// procura pacote por locais
int procurar_pacote_locais(Agency agency);

// apaga um pacote do vetor de pacotes
void apagar_pacote(Agency & agency);

// colocar um pacote como indisponivel
void indisponivel_pacote(Agency & agency);

// cria um novo pacote
Packet criar_pacote(Agency & agency);

// função que mostra todos os pacotes no ecra
void mostrar_pacotes(Agency agency);

// guarda os pacotes no ficheiro dos pacotes
void save_packs(Agency agency);

// calcula e mostra no ecra o número e o valor total de pacotes vendidos
void visualize_totalsold(Agency agency);

// compra um pacote para um cliente especifico
void comprar_pacote(Agency & agency);

// edita pacote
void editar_pacote(Agency & agency);

// pacotes vendidos a um cliente
void pacotes_vendidos_cliente(Agency & agency);

// pacotes vendidos
//void pacotes_vendidos_total(Agency & agency);

// remove elementos repetidos de um vetor
//void remove(vector<int>& v);




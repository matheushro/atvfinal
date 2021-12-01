#ifndef LINEAR_DISPERSION_SOLVER_H
#define LINEAR_DISPERSION_SOLVER_H

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

struct Aluno {
	std::string nome;
	std::string matricula;
	float aep1 = 0;
	float prova1 = 0;
	float aep2 = 0;
	float prova2 = 0;
	float sub = 0;
	float media = 0;
	std::string status;
}typedef Aluno;

bool cadastraAluno (Aluno aluno);
void cadastro ();
void lista();
void cadastrar_notas();

#endif

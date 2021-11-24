#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>  
#include <vector>  
#include <sstream>  
#include <cstdlib>
struct Aluno {
	std::string nome;
	float matricula;
	float aep1 = 0;
	float prova1 = 0;
	float aep2 = 0;
	float prova2 = 0;
	float sub = 0;
	float media = 0;
	std::string status;
} typedef Aluno;


bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}


void cadastro () {
	Aluno alunoCadastro;
	std::cout << "Digite o nome do aluno: ";
	std::cin >> alunoCadastro.nome;
	std::cout << "Digite a matricula: ";
	std::cin >> alunoCadastro.matricula;
	alunoCadastro.aep1 = 0;
	alunoCadastro.prova1 = 0;
	alunoCadastro.aep2 = 0;
	alunoCadastro.prova2 = 0;
	alunoCadastro.media = 0;
	alunoCadastro.sub = 0;
	alunoCadastro.status = " ";
	
	if (cadastraAluno (alunoCadastro)) {
		std::cout << "Aluno cadastrado.\n";
	} else {
		std::cout << "Erro ao cadastrar aluno.\n";
	}
}

void lista(){
	//variaveis
	int rodar_arquivo = 0;
	int b = 0;
	char delimitador = ';';
	std::string str;
	std::fstream arquivo;
	std::ofstream arquivo_geral;
	std::ofstream arquivo_sub1;
	std::ofstream arquivo_sub2;
	std::ofstream arquivo_aprovados;
	std::ofstream arquivo_reprovados;
	int w =0;
	arquivo.open("database.csv", std::ios::in);
	// contar numero de linhas do arquivo
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
	}
	else{
		while (arquivo.good()) {
			rodar_arquivo = arquivo.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
	}
	std::string line;
	std::string linha[b];
	int i = 0;
	arquivo.close();
	std::vector<struct Aluno> alunos(b);
	
	// jogar todas as linhas para linha[i]
	
	arquivo.open("database.csv", std::ios::in);
	do{
		arquivo >> linha[i];
		i++;
	}while(getline(arquivo, line));
	arquivo.close();
	
	//dividir as linhas para a estrutura
	
	for(int i = 0; i < b; i++){
		w = 0;
		std::stringstream X(linha[i]);
		while (getline(X, str, ';')){
			if(w == 0){
				alunos[i].nome = str;
			} else if(w == 1){
				alunos[i].matricula = str;
			} else if(w == 2){
				alunos[i].aep1 = std::stof(str);
			} else if(w == 3){
				alunos[i].prova1 = std::stof(str);
			} else if(w == 4){
				alunos[i].aep2 = std::stof(str);
			} else if(w == 5){
				alunos[i].prova2 = std::stof(str);
			} else if(w == 6){
				alunos[i].sub = std::stof(str);
			} else if(w == 7){
				alunos[i].media = std::stof(str);
			} else if(w == 8){
				alunos[i].status = str;
			}
			w++;	
		}	
	}
	//switch opcoes das listas
	
	int opcao_lista = 0;
	while (opcao_lista != 6){
		std::cout << "Escolha uma das opções a seguir: " << std::endl
		          << "Digite 1 para lista geral de alunos" << std::endl
		          << "Digite 2 para lista de alunos reprovados" << std::endl
		          << "Digite 3 para lista de alunos aprovados" << std::endl
		          << "Digite 4 para lista de alunos que precisão da substitutiva do primeiro bimestre" << std::endl
		          << "Digite 5 para lista de alunos que precisão da substitutiva do segundo bimestre" << std::endl
				  << "Digite 6 para voltar" << std::endl;
		          std::cin >> opcao_lista;
		          system("cls");
    switch(opcao_lista){
      	case 1:
      		//gerar arquivo
      		
      		system("cls");
			arquivo_geral.open("geral.csv");
			
			if (!arquivo_geral.is_open()) {
				std::cout << "Houve um erro ao abrir o arquivo!\n";
				break;	
			}
			
      		//criar arquivo geral
      		
			for(int i = 0; i < b; i++){
				arquivo_geral << alunos[i].nome << ";" 
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
			}
			arquivo_geral.close();	
			std::cout << "RELATÓRIO ATUALIZADO!" << std::endl;
      	break;
      	case 2:
      		//gerar arquivo
      		
      		system("cls");
			arquivo_reprovados.open("reprovados.csv");
			
			if (!arquivo_reprovados.is_open()) {
				std::cout << "Houve um erro ao abrir o arquivo!\n";
				break;	
			}
			
      		//printar na tela todos os alunos reprovados
      		for(int i = 0; i < b; i++){
      			if(alunos[i].status == "reprovado"){
      				arquivo_reprovados << alunos[i].nome << ";" 
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
				  }
			}
			arquivo_reprovados.close();	
			std::cout << "RELATÓRIO ATUALIZADO!" << std::endl;
      	break;
      	case 3:
      		//gerar arquivo
      		
      		system("cls");
			arquivo_aprovados.open("aprovados.csv");
			
			if (!arquivo_aprovados.is_open()) {
				std::cout << "Houve um erro ao abrir o arquivo!\n";
				break;	
			}
      		//printar na tela todos os alunos reprovados
      		for(int i = 0; i < b; i++){
      			if(alunos[i].status == "aprovado"){
      				arquivo_aprovados << alunos[i].nome << ";" 
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
				  }
			}
			arquivo_aprovados.close();	
			std::cout << "RELATÓRIO ATUALIZADO!" << std::endl;
      	break;
      	case 4:
      		//gerar arquivo
      		
      		system("cls");
			arquivo_sub1.open("sub_1_bm.csv");
			
			if (!arquivo_sub1.is_open()) {
				std::cout << "Houve um erro ao abrir o arquivo!\n";
				break;	
			}
      		//printar na tela todos os alunos que precisam da substitutiva 1bm
      		for(int i = 0; i < b; i++){
      			if((alunos[i].aep1 +  alunos[i].prova1) < 6){
      				arquivo_sub1 << alunos[i].nome << ";" 
							<< alunos[i].matricula << ";"
							<< alunos[i].aep1 << ";"
							<< alunos[i].prova1 << ";"
							<< alunos[i].aep2 << ";"
							<< alunos[i].prova2 << ";"
							<< alunos[i].sub << ";"
							<< alunos[i].media << ";"
							<< alunos[i].status << "\n";
				  }
			  }
			   arquivo_sub1.close();
			  std::cout << "RELATÓRIO ATUALIZADO!" << std::endl;
			  
      	break;
      	case 5:
      		//gerar arquivo
      		
      		system("cls");
			arquivo_sub2.open("sub_2_bm.csv", std::fstream::app);
			
			if (!arquivo_sub2.is_open()) {
				std::cout << "Houve um erro ao abrir o arquivo!\n";
				break;	
			}
      		//printar na tela todos os alunos que precisam da substitutiva 1bm
      		for(int i = 0; i < b; i++){
      			if((alunos[i].aep2 +  alunos[i].prova2) < 6){
      				arquivo_sub2 << alunos[i].nome << ";" 
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
				  }
			  }
			   arquivo_sub2.close();
			  std::cout << "RELATÓRIO ATUALIZADO!" << std::endl;
			 
      	break;
		}
	}
}



void cadastrar_notas (){
	system("cls");
	int matricula_alt = 0;
	std::cout << "Digite uma matricula para alterar as notas: ";
	std::cin >> matricula_alt;
	//variaveis
	int rodar_arquivo = 0;
	int b = 0;
	char delimitador = ';';
	std::string str;
	std::fstream arquivo;
	int w =0;
	int opcao_notas = 0;
	arquivo.open("database.csv", std::ios::in);
	// contar numero de linhas do arquivo
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
	}
	else{
		while (arquivo.good()) {
			rodar_arquivo = arquivo.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
	}
	std::string line;
	std::string linha[b];
	int i = 0;
	arquivo.close();
	std::vector<struct Aluno> alunos(b);
	
	// jogar todas as linhas para linha[i]
	
	arquivo.open("database.csv", std::ios::in);
	do{
		arquivo >> linha[i];
		i++;
	}while(getline(arquivo, line));
	arquivo.close();
	
	//dividir as linhas para a estrutura
	
	for(int i = 0; i < b; i++){
		w = 0;
		std::stringstream X(linha[i]);
		while (getline(X, str, ';')){
			if(w == 0){
				alunos[i].nome = str;
			} else if(w == 1){
				alunos[i].matricula = str;
			} else if(w == 2){
				alunos[i].aep1 = std::stof(str);
			} else if(w == 3){
				alunos[i].prova1 = std::stof(str);
			} else if(w == 4){
				alunos[i].aep2 = std::stof(str);
			} else if(w == 5){
				alunos[i].prova2 = std::stof(str);
			} else if(w == 6){
				alunos[i].sub = std::stof(str);
			} else if(w == 7){
				alunos[i].media = std::stof(str);
			} else if(w == 8){
				alunos[i].status = str;
			}
			w++;	
		}	
	}
	//laço para encontrar a matricula correta e alterar as notas
	for(int i = 0; i < b; i++){
		if(alunos[i].matricula == matricula_alt){
			std::cout << " Nome: " << alunos[i].nome 
					<< " Matricula: " << alunos[i].matricula
					<< " AEP1: " << alunos[i].aep1
					<< " Prova1: " << alunos[i].prova1
					<< " AEP2: " << alunos[i].aep2
					<< " PROVA2: " << alunos[i].prova2
					<< " SUB1: " << alunos[i].sub
					<< " Media: " << alunos[i].media
					<< " Status: " << alunos[i].status << std::endl;
			std::cout << "Escolha uma das opções a seguir: " << std::endl
		          << "Digite 1 alterar a nota da AEP1" << std::endl
		          << "Digite 2 alterar a nota da prova1" << std::endl
		          << "Digite 3 alterar a nota da AEP2" << std::endl
		          << "Digite 4 alterar a nota da prova2" << std::endl
		          << "Digite 5 alterar a nota da substitutiva" << std::endl
				  << "Digite 6 para voltar" << std::endl;
		          std::cin >> opcao_notas;
	    	switch(opcao_notas){
	    		case 1:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome 
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da AEP1: ";
					std::cin >> alunos[i].aep1;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 2:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome 
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da Prova1: ";
					//std::getline(std::cin,alunos[i].prova1)
					std::cin >> alunos[i].prova1;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 3:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome 
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da AEP2: ";
					std::cin >> alunos[i].aep2;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 4:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome 
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da Prova2: ";
					std::cin >> alunos[i].prova2;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 5:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome 
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da Prova2: ";
					std::cin >> alunos[i].sub;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
			}
		}
	}
	arquivo.open("database.csv");
	// contar numero de linhas do arquivo
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
	}
	else{
		for(int i = 0; i < b; i++){
			if(alunos[i].media >= 6){
				arquivo << alunos[i].nome << ";" 
					<< alunos[i].matricula << ";"
					<< alunos[i].aep1 << ";"
					<< alunos[i].prova1 << ";"
					<< alunos[i].aep2 << ";"
					<< alunos[i].prova2 << ";"
					<< alunos[i].sub << ";"
					<< alunos[i].media << ";"
					<< "aprovado" << "\n";
			} else {
				arquivo << alunos[i].nome << ";" 
					<< alunos[i].matricula << ";"
					<< alunos[i].aep1 << ";"
					<< alunos[i].prova1 << ";"
					<< alunos[i].aep2 << ";"
					<< alunos[i].prova2 << ";"
					<< alunos[i].sub << ";"
					<< alunos[i].media << ";"
					<< "reprovado" << "\n";
			}
		}
	}
	arquivo.close();
}
#include"header.h"

int main() {
	setlocale(LC_ALL, "portuguese");
	int opcao = 0;
	while (opcao != 4) {

		std::cout << "Escolha uma das opções a seguir: " << std::endl;
		std::cout << "Digite 1 para cadastrar novo aluno." << std::endl;
		std::cout << "Digite 2 para cadastrar notas de um aluno." << std::endl;
		std::cout << "Digite 3 para solicitar lista de alunos." << std::endl;
		std::cout << "Digite 4 para finalizar o programa." << std::endl;
		std::cin >> opcao;

		system("cls");

		switch (opcao) {
		case 1:
			cadastro();
		break;
		case 2:
			cadastrar_notas();
		break;
		case 3:
			lista();
		break;
		}
	}
}

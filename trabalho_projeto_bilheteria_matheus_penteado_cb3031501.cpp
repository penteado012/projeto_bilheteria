#include <iostream>
#include <iomanip>
#include <cstdlib>

#define fileira 15
#define tamanhofileira 40

using namespace std;

void mostrar_teatro(char **x) {
	for(int i = 0; i < fileira; ++i) {
		for(int j = 0; j < tamanhofileira; ++j) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char** argv)
{	
	int faturamento = 0;
	int quantidadeLugarOcupado = 0;;
	char **teatro;
	teatro = (char**)malloc(fileira * sizeof(char*));
	
	int i;
	for(i = 0; i < fileira; ++i) {
		teatro[i] = (char*)malloc(tamanhofileira * sizeof(char));
	}
	
	int j;
	for(i = 0; i < fileira; ++i) {
		for(j = 0; j < tamanhofileira; ++j) {
			teatro[i][j] = '.';
		}
	}
	
	int opcao;
	do {
		cout << "0.	Finalizar\n"
	 	 "1.	Reservar poltrona\n"
	 	 "2.	Mapa de ocupação\n"
	 	 "3.	Faturamento\n";		
         cin >> opcao;
         
         if(opcao == 1) {
			 int fila, poltrona;
			 cout << "Digite a fileira (1 a 15): ";
			 cin >> fila;
			 cout << "Digite a poltrona (1 a 40): ";
			 cin >> poltrona;
			 
			 // Validação da entrada
            if (fila < 1 || fila > 15 || poltrona < 1 || poltrona > 40) {
                cout << "Erro: Fileira ou poltrona inválida!\n";
                continue;
            }
			 
			 fila -= 1;
			 poltrona -= 1;
			 
			 if(teatro[fila][poltrona] == '#'){
				 cout << "Poltrona já reservada\n";
			 } else {
				 teatro[fila][poltrona] = '#';
				 cout << "Reserva feita com sucesso!\n";
				 if(fila < 5) {
					faturamento += 50; 
					quantidadeLugarOcupado += 1;
				 }	else if(fila < 10){
				 	faturamento += 30;
					 quantidadeLugarOcupado += 1;					 
				 } else{
					 faturamento += 15;
					 quantidadeLugarOcupado += 1;
				 }
			 }
		 }
         
         if(opcao == 2) {
			 mostrar_teatro(teatro);
		 }
		 
		 if(opcao == 3) {
			 cout << "Qtde de lugares ocupados: " << quantidadeLugarOcupado << endl;
			  cout << "Valor da bilheteria: R$" << faturamento << endl;			 
		 }
         
         if(opcao == 0 ) {
			 break;
		 }	
	} while(1);
	
	for(i = 0; i < fileira; ++i) {
		free(teatro[i]);
	}
	free(teatro);
	

	return 0;
}

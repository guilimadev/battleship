
#include <iostream>
#include <iterator>
#include <algorithm>  
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>





int main(void){

	std::string line;
	std::string col;
	std::string times;

	std::string Col[25] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"
	, "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "Z" };

	std::ifstream myfile("databattleship.txt");
	std::ofstream mydata;
	mydata.open("test.txt", std::ios::ate);

	std::getline(myfile, line);
	std::getline(myfile, col);
	std::getline(myfile, times);



	auto n_times = std::stoi (times);
	auto n_cols = std::stoi (col);
	auto n_lines = std::stoi (line);

	if(n_cols < 10 or n_lines < 10){
		std::cout << "Para gerar um tabuleiro valido para o jogo" << std::endl
		<< "deve ter pelo menos 10 linhas e 10 colunas!" << std::endl
		<< "Modifique o arquivo de entrada" << std::endl;

		return 0;
	}

	srand(time(NULL));

	int rand_line;
	int rand_col;
	int rand_pos;


	
	//Number of puzzles

	for(int t = 0; t < n_times; t++){

		std::cout << n_cols << " " << n_lines << "\n";


		
		int A[n_lines+1][n_cols+1];
		for (int i = 0; i < n_lines+1; ++i)
		{
			for (int j = 0; j < n_cols+1; ++j)
			{
				
				A[i][j] = 0;
				
			}
		}

		

		// Implementando 1 Battleship (tamanho 4)

		for (int i = 0; i < 1; ++i)
		{
			rand_line = rand() % n_lines;
			rand_col = rand() % n_cols;
			rand_pos = rand() % 2 + 1;

			std::cout << rand_line << " " << rand_col << " " << rand_pos <<" - Battleship";

			if(rand_pos == 1){
				if(rand_col+3 >= n_cols){
					i--;
					std::cout << " entrada invalida" << "\n";
				}
				else{
					A[rand_line][rand_col+3] = 4;
					A[rand_line][rand_col+2] = 4; 
					A[rand_line][rand_col+1] = 4; 
					A[rand_line][rand_col] = 4;
					std::cout << "\n";
				}
			}

			if(rand_pos == 2){
				if(rand_line+3 >= n_lines){
					i--;
					std::cout << " entrada invalida" << "\n";;
				}
				else{
					A[rand_line+3][rand_col] = 4;
					A[rand_line+2][rand_col] = 4; 
					A[rand_line+1][rand_col] = 4; 
					A[rand_line][rand_col] = 4;
					std::cout << "\n";

					mydata << "Battleship: " << rand_line << " " << rand_col << " " << rand_pos << "\n";
					
				}
			}
			
		}

		// Implementando 2 Cruisers (tamanho 3)

		for (int i = 0; i < 2; ++i)
		{
			rand_line = rand() % n_lines;
			rand_col = rand() % n_cols;
			rand_pos = rand() % 2 + 1;

			std::cout << rand_line << " " << rand_col << " " << rand_pos << " - Cruiser";

			if(rand_pos == 1){
				if(A[rand_line][rand_col] != 0 or A[rand_line-1][rand_col] != 0 or A[rand_line+1][rand_col] != 0  or A[rand_line-1][rand_col-1] != 0 or A[rand_line+1][rand_col-1] != 0 
					or A[rand_line-1][rand_col-2] != 0 or A[rand_line][rand_col-2] != 0 or A[rand_line+1][rand_col-2] != 0 or A[rand_line-1][rand_col+1] != 0
					or A[rand_line+1][rand_col+1] != 0  or A[rand_line-1][rand_col+2] != 0 or A[rand_line][rand_col+2] != 0 or A[rand_line+1][rand_col+2] != 0 ){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				else if(A[rand_line][rand_col+1] != 0 or A[rand_line][rand_col-1] != 0 or rand_col-1 < 0 or rand_col+1 >= n_cols){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				else{
					A[rand_line][rand_col] = 3;
					A[rand_line][rand_col-1] = 3;
					A[rand_line][rand_col+1] = 3;
					std::cout << std::endl;
					mydata << "Cruiser: " << rand_line << " " << rand_col << " " << rand_pos << std::endl;
				
				}
			}
			if (rand_pos == 2)
			{
				if(A[rand_line][rand_col] != 0 or A[rand_line][rand_col-1] != 0 or A[rand_line][rand_col+1] != 0  or A[rand_line-1][rand_col-1] != 0 or A[rand_line-1][rand_col+1] != 0 
					or A[rand_line-2][rand_col-1] != 0 or A[rand_line-2][rand_col] != 0 or A[rand_line-2][rand_col+1] != 0 or A[rand_line+1][rand_col-1] != 0
					or A[rand_line+1][rand_col+1] != 0  or A[rand_line+2][rand_col-1] != 0 or A[rand_line+2][rand_col] != 0 or A[rand_line+2][rand_col+1] != 0 ){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				else if(A[rand_line+1][rand_col] != 0 or A[rand_line-1][rand_col] != 0 or rand_line-1 < 0 or rand_line+1 >= n_lines){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				else{
					A[rand_line][rand_col] = 3;
					A[rand_line-1][rand_col] = 3;
					A[rand_line+1][rand_col] = 3;
					mydata << "Cruiser: " << rand_line << " " << rand_col << " " << rand_pos << std::endl;
				
					std::cout << std::endl;
				}
			}
		}



		// Implementando 3 Destroyers (tamanho 2)

		for (int i = 0; i < 3; ++i)
		{
			rand_line = rand() % n_lines;
			rand_col = rand() % n_cols;
			rand_pos = rand() % 2 + 1;
			
			std::cout << rand_line << " " << rand_col << " " << rand_pos << " - Destroyer";

			if(rand_pos == 2){


				if(A[rand_line][rand_col] != 0 or A[rand_line+1][rand_col] != 0 or A[rand_line-1][rand_col] != 0 or A[rand_line][rand_col+1] != 0 
				   or A[rand_line+1][rand_col+1] != 0 or A[rand_line-1][rand_col+1] != 0 or A[rand_line-1][rand_col+1] != 0
				   or A[rand_line-1][rand_col-1] != 0 or A[rand_line][rand_col-1] != 0 or A[rand_line+1][rand_col-1] != 0
				   or A[rand_line+2][rand_col-1] != 0 or A[rand_line+2][rand_col] != 0 or A[rand_line+2][rand_col+1] != 0
					){
					i--;	
					std::cout << " entrada invalida" << std::endl;		
				}
				else 
				{

					A[rand_line][rand_col] = 2;

					if(rand_line + 1 >= n_lines){
						A[rand_line-1][rand_col] = 2;
					}
					else{
						A[rand_line+1][rand_col] = 2;
					}	
						std::cout << std::endl;
				}
			}
			if(rand_pos == 1){
				if(rand_col+1 >= n_cols){
					i--;
					std::cout << " entrada invalida" << std::endl;	
				}
				else{
				if(A[rand_line][rand_col] != 0 or A[rand_line+1][rand_col] != 0 or A[rand_line][rand_col-1] != 0 or A[rand_line+1][rand_col] != 0 
				   or A[rand_line+1][rand_col+1] != 0 or A[rand_line+1][rand_col-1] != 0 or A[rand_line+1][rand_col-1] != 0
				   or A[rand_line-1][rand_col-1] != 0 or A[rand_line-1][rand_col] != 0 or A[rand_line-1][rand_col+1] != 0
				   or A[rand_line-1][rand_col+2] != 0 or A[rand_line][rand_col+2] != 0 or A[rand_line+1][rand_col+2] != 0
				   ){
					i--;	
					std::cout << " entrada invalida" << std::endl;		
				}
				else 
					{

						A[rand_line][rand_col] = 2;

						if(rand_line + 1 >= n_lines){
							A[rand_line][rand_col-1] = 2;
						}
						else{
							A[rand_line][rand_col+1] = 2;
						}	
							std::cout << std::endl;
					}

				}
			}

			
		} 
	 	
		
		// Implementando 4 Submarines (tamanho 1)

		int contSub = 0;

		for (int i = 0; i < 4; ++i)
		{
			
			rand_line = rand() % n_lines;
			rand_col = rand() %  n_cols;
			


			if(contSub > 300000){				
				break;
			}

			std::cout << rand_line << " " << rand_col << " - Submarine";


			// Canto inferior Esquerdo
			if(rand_col == 0 and rand_line+1 == n_lines){
				if(A[rand_line][rand_col] != 0  or A[rand_line-1][rand_col] != 0 or 
				 A[rand_line][rand_col+1] != 0  or A[rand_line][rand_col+1] != 0 or A[rand_line-1][rand_col+1] != 0)
				{
					
					i--;	
					std::cout << " entrada invalida 1" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = 1;
					std::cout << std::endl;
				}
			}

			//Lado superior esquerdo
			else if(rand_col == 0 and rand_line == 0){
				if(A[rand_line][rand_col] != 0 or A[rand_line+1][rand_col] != 0	or A[rand_line][rand_col+1] != 0  or A[rand_line][rand_col+1] != 0 or
				 A[rand_line+1][rand_col+1] != 0 )
				{
					
					i--;	
					std::cout << " entrada invalida" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = 1;
					std::cout << std::endl;
				}
			}


			// Lado esquerdo 
			else if(rand_col == 0 and rand_line > 0 and rand_line+1 < n_lines){

				if(A[rand_line][rand_col] != 0 or A[rand_line+1][rand_col] != 0 or A[rand_line-1][rand_col] != 0 or
				 A[rand_line][rand_col+1] != 0  or A[rand_line][rand_col+1] != 0	or A[rand_line+1][rand_col+1] != 0 or A[rand_line-1][rand_col+1] != 0)
				{
					
					i--;	
					std::cout << " entrada invalida 1" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = 1;
					std::cout << std::endl;
				}
			}
			
			// Canto inferior direito
			else if(rand_col+1 == n_cols and rand_line+1 == n_lines){
				if(A[rand_line][rand_col] != 0  or A[rand_line-1][rand_col] != 0 or A[rand_line][rand_col-1] != 0
				 or A[rand_line-1][rand_col-1] != 0 )
				{
					
					i--;	
					std::cout << " entrada invalida 1" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = 1;
					std::cout << std::endl;
				}
			}

			//Borda superior
			else if(rand_line == 0){

				if(A[rand_line][rand_col] != 0 or A[rand_line+1][rand_col] != 0  or A[rand_line][rand_col-1] != 0
				or A[rand_line][rand_col+1] != 0  or A[rand_line][rand_col+1] != 0 or A[rand_line +1][rand_col-1] != 0
				or A[rand_line+1][rand_col+1] != 0 )
					{
					
					i--;	
					std::cout << " entrada invalida" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = 1;
					std::cout << std::endl;
				}

				

			}

			else{
				if(A[rand_line][rand_col] != 0 or A[rand_line+1][rand_col] != 0 or A[rand_line-1][rand_col] != 0 or A[rand_line][rand_col-1] != 0
				or A[rand_line][rand_col+1] != 0 or A[rand_line-1][rand_col-1] != 0 or A[rand_line][rand_col+1] != 0 or A[rand_line +1][rand_col-1] != 0
				or A[rand_line+1][rand_col+1] != 0 or A[rand_line-1][rand_col+1] != 0)
				{
					
					i--;	
					std::cout << " entrada invalida" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = 1;
					std::cout << std::endl;
				}
			}
		}

		std::cout << std::endl;
		
		for(int c = 0; c < n_cols; c++){
			std::cout << "|" << Col[c] << "|";
		}
		std::cout << std::endl;
		int contLine = 0;
		
		for (int i = 0; i < n_lines; ++i)
			{

				for (int j = 0; j < n_cols; ++j)
				{
					if(A[i][j] != 0){
						contLine++;
					}
					std::cout << " " << A[i][j] << " ";
				}
				std::cout << "|" << i + 1  << "| = " << contLine <<std::endl;
				contLine = 0;
			}

			std::cout << std::endl;
		}


	mydata.close();
	return 0;

}


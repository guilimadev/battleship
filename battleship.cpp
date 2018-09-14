
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
	mydata.open("boards.txt", std::ios::ate);

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

	std::string basic = "x";


	
	//Number of puzzles

	for(int t = 0; t < n_times; t++){

		std::cout << n_cols << " " << n_lines << "\n";


		
		std::string A[n_lines+1][n_cols+1];

		for (int i = 0; i < n_lines+1; ++i)
		{
			for (int j = 0; j < n_cols+1; ++j)
			{
				
				A[i][j] = "x";
				
			}
		}

		

		// Implementando 1 Battleship (tamanho 4)

		for (int i = 0; i < 1; ++i)
		{
			rand_line = rand() % n_lines;
			rand_col = rand() % n_cols;
			rand_pos = rand() % 2 + 1;

			std::cout << rand_line << " " << rand_col << " " << rand_pos <<" - Battleship";

			//1 = Horizontal, 2 = Vertical

			if(rand_pos == 1){
				if(rand_col+3 >= n_cols){
					i--;
					std::cout << " entrada invalida" << "\n";
				}
				else{
					A[rand_line][rand_col+3] = ">";
					A[rand_line][rand_col+2] = "o"; 
					A[rand_line][rand_col+1] = "o"; 
					A[rand_line][rand_col] = "<";
					std::cout << "\n";
					mydata << "Battleship: " << rand_line << " " << rand_col << " " << rand_pos << "\n";
					
				}
			}

			if(rand_pos == 2){
				if(rand_line+3 >= n_lines){
					i--;
					std::cout << " entrada invalida" << "\n";;
				}
				else{
					A[rand_line+3][rand_col] = "v";
					A[rand_line+2][rand_col] = "o"; 
					A[rand_line+1][rand_col] = "o"; 
					A[rand_line][rand_col] = "^";
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
				if(A[rand_line][rand_col+1] != basic or A[rand_line][rand_col-1] != basic or rand_col-1 < 0 or rand_col+1 >= n_cols){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				else if(A[rand_line][rand_col] != basic or A[rand_line-1][rand_col] != basic or A[rand_line+1][rand_col] != basic  or A[rand_line-1][rand_col-1] != basic or A[rand_line+1][rand_col-1] != basic 
					or A[rand_line-1][rand_col-2] != basic or A[rand_line][rand_col-2] != basic or A[rand_line+1][rand_col-2] != basic or A[rand_line-1][rand_col+1] != basic
					or A[rand_line+1][rand_col+1] != basic  or A[rand_line-1][rand_col+2] != basic or A[rand_line][rand_col+2] != basic or A[rand_line+1][rand_col+2] != basic ){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				
				else{
					A[rand_line][rand_col] = "o";
					A[rand_line][rand_col-1] = "<";
					A[rand_line][rand_col+1] = ">";
					std::cout << std::endl;
					mydata << "Cruiser: " << rand_line << " " << rand_col << " " << rand_pos << std::endl;
				
				}
			}
			if (rand_pos == 2)
			{
				if(A[rand_line+1][rand_col] != basic or A[rand_line-1][rand_col] != basic or rand_line-1 < 0 or rand_line+1 >= n_lines){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}

				 else if(A[rand_line][rand_col] != basic or A[rand_line][rand_col-1] != basic or A[rand_line][rand_col+1] != basic  or A[rand_line-1][rand_col-1] != basic or A[rand_line-1][rand_col+1] != basic 
					or A[rand_line-2][rand_col-1] != basic or A[rand_line-2][rand_col] != basic or A[rand_line-2][rand_col+1] != basic or A[rand_line+1][rand_col-1] != basic
					or A[rand_line+1][rand_col+1] != basic  or A[rand_line+2][rand_col-1] != basic or A[rand_line+2][rand_col] != basic or A[rand_line+2][rand_col+1] != basic ){
					i--;	
					std::cout << " entrada invalida" << std::endl;	
				}
				
				else{
					A[rand_line][rand_col] = "o";
					A[rand_line-1][rand_col] = "^";
					A[rand_line+1][rand_col] = "v";
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


				if(A[rand_line][rand_col] != basic or A[rand_line+1][rand_col] != basic or A[rand_line-1][rand_col] != basic or A[rand_line][rand_col+1] != basic 
				   or A[rand_line+1][rand_col+1] != basic or A[rand_line-1][rand_col+1] != basic or A[rand_line-1][rand_col+1] != basic
				   or A[rand_line-1][rand_col-1] != basic or A[rand_line][rand_col-1] != basic or A[rand_line+1][rand_col-1] != basic
				   or A[rand_line+2][rand_col-1] != basic or A[rand_line+2][rand_col] != basic or A[rand_line+2][rand_col+1] != basic
					){
					i--;	
					std::cout << " entrada invalida" << std::endl;		
				}
				else 
				{

					

					if(rand_line + 1 >= n_lines){
						A[rand_line-1][rand_col] = "^";
						A[rand_line][rand_col] = "v";
					}
					else{
						A[rand_line+1][rand_col] = "v";
						A[rand_line][rand_col] = "^";
					}	
						std::cout << std::endl;
					mydata << "Destroyer: " << rand_line << " " << rand_col << " " << rand_pos << "\n";
					
				}
			}
			if(rand_pos == 1){
				if(rand_col+1 >= n_cols){
					i--;
					std::cout << " entrada invalida" << std::endl;	
				}
				else{
				if(A[rand_line][rand_col] != basic or A[rand_line+1][rand_col] != basic or A[rand_line][rand_col-1] != basic or A[rand_line+1][rand_col] != basic 
				   or A[rand_line+1][rand_col+1] != basic or A[rand_line+1][rand_col-1] != basic or A[rand_line+1][rand_col-1] != basic
				   or A[rand_line-1][rand_col-1] != basic or A[rand_line-1][rand_col] != basic or A[rand_line-1][rand_col+1] != basic
				   or A[rand_line-1][rand_col+2] != basic or A[rand_line][rand_col+2] != basic or A[rand_line+1][rand_col+2] != basic
				   ){
					i--;	
					std::cout << " entrada invalida" << std::endl;		
				}
				else 
					{

						

						if(rand_line + 1 >= n_lines){
							A[rand_line][rand_col-1] = "<";
							A[rand_line][rand_col] = ">";
						}
						else{
							A[rand_line][rand_col+1] = ">";
							A[rand_line][rand_col] = "<";
						}	
							std::cout << std::endl;
							mydata << "Destroyer: " << rand_line << " " << rand_col << " " << rand_pos << "\n";
					
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
				if(A[rand_line][rand_col] != basic  or A[rand_line-1][rand_col] != basic or 
				 A[rand_line][rand_col+1] != basic  or A[rand_line][rand_col+1] != basic or A[rand_line-1][rand_col+1] != basic)
				{
					
					i--;	
					std::cout << " entrada invalida 1" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = "S";
					std::cout << std::endl;
					mydata << "Submarine: " << rand_line << " " << rand_col  << "\n";
					
				}
			}

			//Lado superior esquerdo
			else if(rand_col == 0 and rand_line == 0){
				if(A[rand_line][rand_col] != basic or A[rand_line+1][rand_col] != basic	or A[rand_line][rand_col+1] != basic  or A[rand_line][rand_col+1] != basic or
				 A[rand_line+1][rand_col+1] != basic )
				{
					
					i--;	
					std::cout << " entrada invalida" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = "S";
					std::cout << std::endl;
					mydata << "Submarine: " << rand_line << " " << rand_col  << "\n";
					
				}
			}


			// Lado esquerdo 
			else if(rand_col == 0 and rand_line > 0 and rand_line+1 < n_lines){

				if(A[rand_line][rand_col] != basic or A[rand_line+1][rand_col] != basic or A[rand_line-1][rand_col] != basic or
				 A[rand_line][rand_col+1] != basic  or A[rand_line][rand_col+1] != basic	or A[rand_line+1][rand_col+1] != basic or A[rand_line-1][rand_col+1] != basic)
				{
					
					i--;	
					std::cout << " entrada invalida 1" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = "S";
					std::cout << std::endl;
					mydata << "Submarine: " << rand_line << " " << rand_col  << "\n";
					
				}
			}
			
			// Canto inferior direito
			else if(rand_col+1 == n_cols and rand_line+1 == n_lines){
				if(A[rand_line][rand_col] != basic  or A[rand_line-1][rand_col] != basic or A[rand_line][rand_col-1] != basic
				 or A[rand_line-1][rand_col-1] != basic )
				{
					
					i--;	
					std::cout << " entrada invalida 1" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = "S";
					std::cout << std::endl;
					mydata << "Submarine: " << rand_line << " " << rand_col  << "\n";
					
				}
			}

			//Borda superior
			else if(rand_line == 0){

				if(A[rand_line][rand_col] != basic or A[rand_line+1][rand_col] != basic  or A[rand_line][rand_col-1] != basic
				or A[rand_line][rand_col+1] != basic  or A[rand_line][rand_col+1] != basic or A[rand_line +1][rand_col-1] != basic
				or A[rand_line+1][rand_col+1] != basic )
					{
					
					i--;	
					std::cout << " entrada invalida" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = "S";
					std::cout << std::endl;
					mydata << "Submarine: " << rand_line << " " << rand_col  << "\n";
					
				}

				

			}

			else{
				if(A[rand_line][rand_col] != basic or A[rand_line+1][rand_col] != basic or A[rand_line-1][rand_col] != basic or A[rand_line][rand_col-1] != basic
				or A[rand_line][rand_col+1] != basic or A[rand_line-1][rand_col-1] != basic or A[rand_line][rand_col+1] != basic or A[rand_line +1][rand_col-1] != basic
				or A[rand_line+1][rand_col+1] != basic or A[rand_line-1][rand_col+1] != basic)
				{
					
					i--;	
					std::cout << " entrada invalida" <<std::endl;	
					contSub++;
				}
				else{
					A[rand_line][rand_col] = "S";
					std::cout << std::endl;
					mydata << "Submarine: " << rand_line << " " << rand_col  << "\n";
					
				}
			}
		}
		
		mydata << "\n";
					

		std::cout << std::endl;


		// Piece of code that prints the board
		
		for(int c = 0; c < n_cols; c++){
			std::cout << "|" << Col[c] << "|";
			mydata  << "|" << Col[c] << "|";
		}
		std::cout << std::endl;
		mydata << "\n";
		int contLine = 0;
		


		for (int i = 0; i < n_lines; ++i)
			{

				for (int j = 0; j < n_cols; ++j)
				{
					if(A[i][j] != basic){
						contLine++;
					}
					// Prints the elements of the board
					std::cout << " " << A[i][j] << " ";
					mydata << " " << A[i][j] << " ";
				}

				//Prints the number of the line and the amount os pieces of ship on that line
				std::cout << "|" << i + 1  << "| = " << contLine <<std::endl;
				mydata << "|" << i + 1  << "| = " << contLine << "\n";
				contLine = 0;
			}

			std::cout << std::endl;
			mydata << "\n";
		}
		mydata << "\n" << "\n";


	mydata.close();
	return 0;

}


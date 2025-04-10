#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

const int ROW_MAX = 30;
const int COL_MAX = 30;


void show_table(int** table) {
	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			if (table[i][j] == 1) {
				cout << "x"<<" ";
			}
			else {
				cout << " "<<" ";
			}
		}
		cout << endl;
	}
}

void check_table(int** table) {
	int live_neighbor_counter = 0;
	int tempTAB[ROW_MAX][COL_MAX];


	for (int i = 0; i < ROW_MAX; i++) 
		for (int j = 0; j < COL_MAX; j++) {
			live_neighbor_counter = 0;

			if (i > 0) {
				if (j > 0 && table[i - 1][j - 1] == 1 ) live_neighbor_counter++;
				if (table[i - 1][j] == 1) live_neighbor_counter++;
				if (j + 1 < COL_MAX && table[i - 1][j + 1] == 1) live_neighbor_counter++;
			}

			if (j > 0 && table[i][j-1] == 1) live_neighbor_counter++;
			if (j + 1 < COL_MAX && table[i][j+1] == 1) live_neighbor_counter++;

			if (i + 1 < ROW_MAX) {
				if (j > 0 && table[i + 1][j - 1] == 1) live_neighbor_counter++;
				if (table[i + 1][j] == 1) live_neighbor_counter++;
				if (j + 1 < COL_MAX && table[i + 1][j + 1] == 1) live_neighbor_counter++;
			}







			if (table[i][j] == 1) {			//live cell
				if (live_neighbor_counter == 2 || live_neighbor_counter == 3) tempTAB[i][j] = 1;
				else tempTAB[i][j] = 0;
				}
			else {							//dead cell
				if (live_neighbor_counter == 3) tempTAB[i][j] = 1;
				else tempTAB[i][j] = 0;
			}
		}

	for (int i = 0; i < ROW_MAX; i++)
		for (int j = 0; j < COL_MAX; j++) {
			table[i][j] = tempTAB[i][j];
		}
}



int main() {

	
	int** startTAB = new int* [ROW_MAX];
	for (int i = 0; i < ROW_MAX; i++) {
		startTAB[i] = new int[COL_MAX];
	}

	string next_it;

	ifstream plik;
	plik.open("start_table.txt");


	for (int i = 0; i < ROW_MAX; i++)
		for (int j = 0; j < COL_MAX; j++) {
			plik >> startTAB[i][j];
		}

	plik.close();
	
	while (true) {

		show_table(startTAB);
		check_table(startTAB);
		
		//cin >> next_it;
		cin.get();
		

		system("cls");
	}
	

	return 0;
}
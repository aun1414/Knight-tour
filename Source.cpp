#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

int** board;
int pSize = 0;
int cornerMissed[9][9];
int closed5x8[5][8];
int stretched4x7[4][7];
int double_loop[4][5];
int Aboard100[10][10];
int board2[10][10];


void initBoard2() {
	int temp[10][10] = { {94, 19, 66, 39, 42, 17, 44, 63, 48, 15},
					{67, 38, 93, 18, 65, 86, 41, 16, 45, 62},
					{20, 95, 68, 87, 40, 43, 64, 49, 14, 47},
					{69, 32, 37, 92, 85, 72, 89, 46, 61, 50},
					{96, 21, 84, 71, 88, 91, 74, 59, 78, 13},
					{33, 70, 31, 36,73,82,79,90,51,60},
					{ 22, 97,34,83,30,75,58,81,12,77},
					{ 3,100,25,56,35,80,29,76,9,52 },
					{ 98,23,2,5,26,57,54,7,28,11 },
					{ 1,4,99,24,55,6,27,10,53,8 }
	};

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board2[i][j] = temp[i][j];
		}
	}

}
void initAboard100() {
	int temp[10][10] = { {58,83,28,87,60,81,94,77,62,79},
							{29,86,59,82,27,90,61,80,93,76},
							{84,57,30,39,88,95,4,91,78,63},
							{17,42,85,26,31,38,89,96,75,92},
							{56,33,18,43,40,5,24,3,64,97},
							{19, 16, 41, 32, 25, 44, 37, 98, 7, 74},
							{34, 55, 20, 69, 36, 23, 6, 45, 2, 65},
							{15, 52, 35, 22, 11, 70, 99, 8, 73, 46},
							{54, 21, 50, 13, 68, 9, 48, 71, 66, 1},
							{51, 14, 53, 10, 49, 12, 67, 100, 47, 72} };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Aboard100[i][j] = temp[i][j];
		}
	}
}
void initStretched() {
	int temp[4][7] = {
						{5,24,9,18,13,28,1},
						{8,15,6,25,10,19,12},
						{23,4,17,14,21,2,27},
						{16,7,22,3,26,11,20}
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			stretched4x7[i][j] = temp[i][j];
		}
	}
}


void initDoubleLoop() {
	int temp[4][5] = {
							   {6,-9,2,-3,8}
							 , {1,-4,7,-8,3}
							 , {-10,5,-6,9,-2}
							 , {-5,10,-1,4,-7}

	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			double_loop[i][j] = temp[i][j];
		}
	}
}

void initClosed() {

	int temp[5][8] = { {1,32,9,6,39,30,23,18},
				  {10,7,40,31,22,17,38,29},
				  {33,2,13,8,5,26,19,24},
				  {14,11,4,35,16,21,28,37},
				  {3,34,15,12,27,36,25,20}
	};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			closed5x8[i][j] = temp[i][j];
		}
	}
}

void initCornerMissed() {
	cornerMissed[0][0] = 0;
	cornerMissed[0][1] = 1;
	cornerMissed[0][2] = 62;
	cornerMissed[0][3] = 47;
	cornerMissed[0][4] = 32;
	cornerMissed[0][5] = 79;
	cornerMissed[0][6] = 20;
	cornerMissed[0][7] = 23;
	cornerMissed[0][8] = 34;

	cornerMissed[1][0] = 63;
	cornerMissed[1][1] = 50;
	cornerMissed[1][2] = 3;
	cornerMissed[1][3] = 80;
	cornerMissed[1][4] = 19;
	cornerMissed[1][5] = 48;
	cornerMissed[1][6] = 33;
	cornerMissed[1][7] = 78;
	cornerMissed[1][8] = 21;

	cornerMissed[2][0] = 2;
	cornerMissed[2][1] = 61;
	cornerMissed[2][2] = 18;
	cornerMissed[2][3] = 49;
	cornerMissed[2][4] = 46;
	cornerMissed[2][5] = 31;
	cornerMissed[2][6] = 22;
	cornerMissed[2][7] = 35;
	cornerMissed[2][8] = 24;

	cornerMissed[3][0] = 51;
	cornerMissed[3][1] = 64;
	cornerMissed[3][2] = 59;
	cornerMissed[3][3] = 4;
	cornerMissed[3][4] = 53;
	cornerMissed[3][5] = 38;
	cornerMissed[3][6] = 45;
	cornerMissed[3][7] = 30;
	cornerMissed[3][8] = 77;

	cornerMissed[4][0] = 60;
	cornerMissed[4][1] = 17;
	cornerMissed[4][2] = 52;
	cornerMissed[4][3] = 27;
	cornerMissed[4][4] = 44;
	cornerMissed[4][5] = 29;
	cornerMissed[4][6] = 40;
	cornerMissed[4][7] = 25;
	cornerMissed[4][8] = 36;

	cornerMissed[5][0] = 65;
	cornerMissed[5][1] = 58;
	cornerMissed[5][2] = 5;
	cornerMissed[5][3] = 54;
	cornerMissed[5][4] = 39;
	cornerMissed[5][5] = 26;
	cornerMissed[5][6] = 37;
	cornerMissed[5][7] = 76;
	cornerMissed[5][8] = 11;

	cornerMissed[6][0] = 6;
	cornerMissed[6][1] = 55;
	cornerMissed[6][2] = 16;
	cornerMissed[6][3] = 43;
	cornerMissed[6][4] = 28;
	cornerMissed[6][5] = 41;
	cornerMissed[6][6] = 12;
	cornerMissed[6][7] = 73;
	cornerMissed[6][8] = 70;

	cornerMissed[7][0] = 15;
	cornerMissed[7][1] = 66;
	cornerMissed[7][2] = 57;
	cornerMissed[7][3] = 8;
	cornerMissed[7][4] = 13;
	cornerMissed[7][5] = 68;
	cornerMissed[7][6] = 71;
	cornerMissed[7][7] = 10;
	cornerMissed[7][8] = 75;

	cornerMissed[8][0] = 56;
	cornerMissed[8][1] = 7;
	cornerMissed[8][2] = 14;
	cornerMissed[8][3] = 67;
	cornerMissed[8][4] = 42;
	cornerMissed[8][5] = 9;
	cornerMissed[8][6] = 74;
	cornerMissed[8][7] = 69;
	cornerMissed[8][8] = 72;
}



void printBoard(int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

int* possibilities(int x, int y, int x2, int y2) {
	int XPos[8] = { 2,1,2,1,-2,-1,-2,-1 };
	int YPos[8] = { 1,2,-1,-2,1,2,-1,-2 };
	int* possibilities = new int[20]();
	for (int x = 0; x < 20; x++)
		possibilities[x] = -1;
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		if (XPos[i] + x >= 0 && XPos[i] + x < x2 && YPos[i] + y >= 0 && YPos[i] + y < y2 && board[XPos[i] + x][YPos[i] + y] == 0) {
			possibilities[counter] = XPos[i] + x;
			possibilities[counter + 1] = YPos[i] + y;
			counter += 2;

		}
	}
	int index = 0;
	while (possibilities[index] != -1) {
		//cout << possibilities[index] << " ";
		index++;
	}
	pSize = index;
	//cout << pSize << endl;

	return possibilities;
}


void wansdorff(int xx, int yy, int x1, int y1) {
	int* p2 = new int[20];
	int tempSize;
	int movement = 2;
	int x = xx;
	int y = yy;
	int temp1;
	int temp2;
	int min[2];

	for (int a = 0; a < (x1 * y1) - 1; a++) {
		p2 = possibilities(x, y, x1, y1);
		tempSize = pSize;
		min[0] = p2[0];
		min[1] = p2[1];
		//cout << p2[0] << " " << p2[1] << endl;
		for (int i = 0; i < tempSize; i += 2) {
			possibilities(p2[i], p2[i + 1], x1, y1);
			temp1 = pSize;
			possibilities(min[0], min[1], x1, y1);
			temp2 = pSize;
			//cout << temp1 << " " << temp2 << endl;
			if (temp1 <= temp2) {
				min[0] = p2[i];
				min[1] = p2[i + 1];
			}


		}
		x = min[0];
		y = min[1];
		board[x][y] = movement;
		movement++;
	}
	return;
}

void JoinTours3(vector<vector<int>> array, int col, int row) {

	vector<vector<int>> ptr(row * 2, vector<int>(col * 2, 0));

	//First Quadrant 
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			ptr[i][j] = array[i][j];


		}

	}

	int check = array[0][col - 1];
	int last = row * col;
	ptr[row][col - 1] = last + 1;
	int sum = last - check + 1;
	int add2 = 0;
	int index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = 0; j < col; j++) {

			if (array[index1][index2] > check) {
				ptr[i][j] = array[index1][index2] + sum;
				add2 = ptr[i][j];
			}
			index2++;
		}
		index1++;
	}
	index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = 0; j < col; j++) {

			if (array[index1][index2] < check) {
				ptr[i][j] = array[index1][index2] + add2;

			}
			index2++;
		}
		index1++;
	}



	//4th Quadrant 
	last = row * col;
	check = array[1][0];
	sum = ((2 * last) - check) + 1;

	ptr[row + 1][col] = (2 * last) + 1;
	index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {

			if (array[index1][index2] > check) {
				ptr[i][j] = array[index1][index2] + sum;
				add2 = ptr[i][j];
			}

			index2++;
		}
		index1++;
	}


	//cout << "ADD 2  " << add2 << endl;
	index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {

			if (array[index1][index2] < check) {
				ptr[i][j] = array[index1][index2] + add2 + check;
				//add2 = ptr[i][j];
			}

			index2++;
		}
		index1++;
	}


	// first
	last = row * col;
	check = array[row - 1][0];
	sum = ((3 * last));
	add2 = 0;
	//ptr[row -1][col] = (3 * last) + 1;
	index1 = 0;
	for (int i = 0; i < row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {


			ptr[i][j] = board2[index1][index2] + sum;



			index2++;
		}
		index1++;
	}



	for (int i = 0; i < 2 * row; i++) {

		for (int j = 0; j < 2 * col; j++) {

			cout << setw(3) << ptr[i][j] << "  ";

		}


		cout << endl;

	}








}


void JoinTours() {
	int answer[4][12];
	int start_x, start_y, end_x, end_y;
	int sum = 28;
	int diff = (4 / 2) * 5;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			answer[i][j] = stretched4x7[i][j] + diff;

			if (stretched4x7[i][j] == 1) {
				start_x = i;
				start_y = j;

			}
			if (stretched4x7[i][j] == 28) {
				end_x = i;
				end_y = j;
			}
		}
	}


	for (int i = 0; i < 4; i++) {
		int x = 0;
		for (int j = 7; j < 12; j++) {
			answer[i][j] = double_loop[i][x];
			x++;
		}
	}





	for (int i = 0; i < 4; i++) {
		int x = 0;
		for (int j = 7; j < 12; j++) {
			//Re balancing 
			if (answer[i][j] > 0) {

				answer[i][j] += answer[end_x][end_y];
			}
			else {
				answer[i][j] *= -1;
			}


		}
	}



	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 12; j++) {

			cout << answer[i][j] << "   ";

		}
		cout << endl;
	}








}



void JoinTours2(vector<vector<int>> array, int col, int row) {

	vector<vector<int>> ptr(row * 2, vector<int>(col * 2, 0));

	//First Quadrant 
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			ptr[i][j] = array[i][j];


		}

	}

	int check = array[0][col - 1];
	int last = row * col;
	ptr[row][col - 1] = last + 1;
	int sum = last - check + 1;
	int add2 = 0;
	int index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = 0; j < col; j++) {

			if (array[index1][index2] > check) {
				ptr[i][j] = array[index1][index2] + sum;
				add2 = ptr[i][j];
			}
			index2++;
		}
		index1++;
	}
	index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = 0; j < col; j++) {

			if (array[index1][index2] < check) {
				ptr[i][j] = array[index1][index2] + add2;

			}
			index2++;
		}
		index1++;
	}



	//4th Quadrant 
	last = row * col;
	check = array[1][0];
	sum = ((2 * last) - check) + 1;

	ptr[row + 1][col] = (2 * last) + 1;
	index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {

			if (array[index1][index2] > check) {
				ptr[i][j] = array[index1][index2] + sum;
				add2 = ptr[i][j];
			}

			index2++;
		}
		index1++;
	}


	//cout << "ADD 2  " << add2 << endl;
	index1 = 0;
	for (int i = row; i < 2 * row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {

			if (array[index1][index2] < check) {
				ptr[i][j] = array[index1][index2] + add2 + check;
				//add2 = ptr[i][j];
			}

			index2++;
		}
		index1++;
	}


	// Second  
	last = row * col;
	check = array[row - 1][0];
	sum = ((3 * last) - check) + 1;
	add2 = 0;
	ptr[row - 1][col] = (3 * last) + 1;
	index1 = 0;
	for (int i = 0; i < row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {

			if (array[index1][index2] > check) {
				ptr[i][j] = array[index1][index2] + sum;
				if (ptr[i][j] > add2) {
					add2 = ptr[i][j];
				}
			}

			index2++;
		}
		index1++;
	}

	index1 = 0;
	for (int i = 0; i < row; i++) {
		int index2 = 0;
		for (int j = col; j < 2 * col; j++) {

			if (array[index1][index2] < check) {
				ptr[i][j] = array[index1][index2] + add2;
			}

			index2++;
		}
		index1++;
	}


	for (int i = 0; i < 2 * row; i++) {

		for (int j = 0; j < 2 * col; j++) {

			cout << setw(3) << ptr[i][j] << "  ";

		}


		cout << endl;

	}
}

void AlgorithmOpenKnight(int n, int m) {
	if ((n <= m) && ((n == 3 && (m == 4 || m >= 7)) || (n >= 4 && m >= 5))) {
		cout << "Open Knight tour exists on this board!" << endl;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = 0;
			}
		}

		if (n <= 10 && m <= 10) {

			board[0][0] = 1;
			wansdorff(0, 0, n, m);
			printBoard(n, m);
		}
		else if (n == 4 && m == 12) {
			initStretched();
			initDoubleLoop();
			JoinTours();
		}
		else if (n > 10 && m > 10) {
			initAboard100();
			int row = 10;
			int column = 10;
			vector<vector<int>> a(row, vector<int>(column, 0));
			for (int i = 0; i < row; i++) {

				for (int j = 0; j < column; j++) {
					a[i][j] = Aboard100[i][j];
				}
			}


			JoinTours2(a, row, column);

		}




	}

	else {
		cout << "An open knight tour does not exist on this board" << endl;
	}


}

void AlgorithmKnight(int n, int m) {
	if (n <= m && (n % 2 == 0 || m % 2 == 0) && (n >= 5 || (n == 3 && m >= 10))) {
		cout << "Closed knight tour exists!" << endl;
		if (n > 10 && m > 10) {
			initBoard2();
			int row = 10;
			int col = 10;
			vector<vector<int>> a(row, vector<int>(col, 0));
			for (int i = 0; i < row; i++) {

				for (int j = 0; j < col; j++) {
					a[i][j] = board2[i][j];
				}
			}


			JoinTours3(a, row, col);


		}
		if (n == 5 && m == 8) {
			initClosed();
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 8; j++) {
					cout << closed5x8[i][j] << "\t";
				}
				cout << endl;
			}
		}
	}

	else if (n <= m && n % 2 == 1 && m % 2 == 1 && (n >= 5 || (n == 3 && m >= 9))) {
		cout << "Corner missed closed knight tour exists!" << endl;
		if (n == 9 && m == 9) {
			initCornerMissed();
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << cornerMissed[i][j] << "\t";
				}
				cout << endl;
			}
		}
	}
	else {
		cout << "A closed (or a corner missed closed) knight tour does not exist on this board" << endl;
	}

}

int main() {

	int n, m;
	cout << "Input number of rows" << endl;
	cin >> n;

	cout << "Input number of columns" << endl;
	cin >> m;

	int row = n;
	int columns = m;
	board = new int* [row];
	for (int i = 0; i < row; ++i)
		board[i] = new int[columns];

	AlgorithmKnight(n, m);
	cout << endl;
	AlgorithmOpenKnight(n, m);
	

}
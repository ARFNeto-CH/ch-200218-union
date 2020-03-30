#define _CRT_SECURE_NO_WARNINGS

// https://www.clubedohardware.com.br/forums/topic/
// 1427656-retornando-array-2d-de-fun%C3%A7%C3%B5es/
// ?tab=comments#comment-7699344

#include <iomanip>
#include <iostream>
#include <string.h>

struct multiD
{
	int len;
	union
	{
		int(*x1D)[60];
		int(*x2D)[4][15];
		int(*x3D)[3][4][5];
		int(*x4D)[2][3][2][5];
		int(*x5D)[1][2][2][3][5];
	};
};

void        mostra(multiD*, int);

using namespace std;

int main(int argc, char** argv)
{
	// exemplos de vetores xD
	int v1D[60];
	int v2D[4][15];
	int v3D[3][4][5];
	int v4D[2][3][2][5];
	int v5D[1][2][2][3][5];

	multiD teste;	// estrutura de teste
	teste.len = 60;
	teste.x1D = &v1D;// so testes, para mostrar o acesso
	teste.x2D = &v2D;// so testes, para mostrar o acesso
	teste.x3D = &v3D;// so testes, para mostrar o acesso
	teste.x4D = &v4D;// so testes, para mostrar o acesso
	teste.x5D = &v5D;// so testes, para mostrar o acesso
	// preenche usando o vetor v1D
	teste.x1D = &v1D;
	// for (int i = 0; i < teste.len; i += 1) *(*(teste.x1D) + i) = i; // igual
	for (int i = 0; i < teste.len; i += 1) (*teste.x1D)[i] = i;
	// mostra a mesma area de 1 a 5 dimensoes
	for (int i = 1; i <= 5; i += 1)
		mostra(&teste, i);
	// nada a liberar: so usamos valores estaticos
	// agora mostra o ultimo elemento de cada vetor
	::std::cout << "\nO ultimo elemento, visto com 1 a 5 indices, deve ser o mesmo:\n" << endl;
	cout << "1D v[59] = " << (*teste.x1D)[59] << endl;
	cout << "2D v[3][14] = " << (*teste.x2D)[3][14] << endl;
	cout << "3D v[2][3][4] = " << (*teste.x3D)[2][3][4] << endl;
	cout << "4D v[1][2][1][4] = " << (*teste.x4D)[1][2][1][4] << endl;
	cout << "5D v[0][1][1][2][4] = " << (*teste.x5D)[0][1][1][2][4] << endl;
	cout << "\nARFNETO 2020" << endl;
	return 0;
};	// main()


void mostra(multiD* matriz, int planos)
{
	cout << "\n\nMatriz de " <<
		matriz->len << " elementos em " <<
		planos << " dimensoes:\n\n";
	switch (planos)
	{
	case 1:
		//	int(*x1D)[60];
		for (int i = 0; i < matriz->len; i += 1)
		{
			std::cout << setw(2) << i << ": " <<
				setw(2) << *(*(matriz->x1D) + i) << " ";
			if (i % 10 == 9) cout << endl;
		};	// for
		break;

	case 2:
		//	int(*x2D)[4][15];
		for (int i = 0; i < 4; i += 1)
			for (int j = 0; j < 15; j += 1)
				std::cout << "(" <<
				setw(2) << i << ", " <<
				setw(2) << j << ") = " <<
				(*matriz->x2D)[i][j] << endl;
		break;

	case 3:
		//	int (*x3D)[3][4][5];
		for (int i = 0; i < 3; i += 1)
			for (int j = 0; j < 4; j += 1)
				for (int k = 0; k < 5; k += 1)
					std::cout << "(" <<
					setw(2) << i << "," <<
					setw(2) << j << "," <<
					setw(2) << k << ") = " <<
					(*matriz->x3D)[i][j][k] << endl;
		break;

	case 4:
		//	int(*x4D)[2][3][2][5];
		for (int i = 0; i < 2; i += 1)
			for (int j = 0; j < 3; j += 1)
				for (int k = 0; k < 2; k += 1)
					for (int l = 0; l < 5; l += 1)
						std::cout << "(" <<
						setw(2) << i << "," <<
						setw(2) << j << "," <<
						setw(2) << k << "," <<
						setw(2) << l << ") = " <<
						(*matriz->x4D)[i][j][k][l] << endl;
		break;

	case 5:
		//	int(*x5D)[1][2][2][3][5];
		for (int i = 0; i < 1; i += 1)
			for (int j = 0; j < 2; j += 1)
				for (int k = 0; k < 2; k += 1)
					for (int l = 0; l < 3; l += 1)
						for (int m = 0; m < 5; m += 1)
							std::cout << "(" <<
							setw(2) << i << "," <<
							setw(2) << j << "," <<
							setw(2) << k << "," <<
							setw(2) << l << "," <<
							setw(2) << m << ") = " <<
							(*matriz->x5D)[i][j][k][l][m] << endl;
		break;

	default:
		break;
	};	// switch()
	return;
};	// mostra()

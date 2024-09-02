#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

float getnum() {
	float x;
	printf("Введите число ");
	scanf_s("%g", &x);
	return(x);
}

void setMatrix(int rows, int collums, int** matrix, char name) {
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * collums);
		for (int j = 0; j < collums; j++) {
			printf("%c%d%d = ", name, i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void printMatrix(int rows, int collums, int** matrix) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collums; j++) {
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}

int** multiplyMatrixes(int rows_A, int collums_B, int collums_A_rows_B, int** matrix1, int** matrix2) {
	int** resultingMatrix = (int**)malloc(sizeof(int*) * rows_A);
	for (int i = 0; i < rows_A; i++) {
		resultingMatrix[i] = (int*)malloc(sizeof(int) * collums_B);
		for (int j = 0; j < collums_B; j++) {
			resultingMatrix[i][j] = 0;
			for (int k = 0; k < collums_A_rows_B; k++) {
				resultingMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return(resultingMatrix);
}

void arifmetica() {
	float x, y;
	char i;
	start: printf("1. x * y\n2. x + y\n3. x / y\n4. x - y\n5. x ^ y\n6. Извлечение корня степени y из x\n7. Вернуться в главное меню.\nВыберите пункт: ");
	i = getch();

	if (i == '7') {
		system("cls");
		menu();
		return;
	}
	x = getnum();
	y = getnum();
	switch (i) {
	case ('1'):
		printf("%g * %g = %g", x, y, x * y);
		break;
	case ('2'):
		printf("%g + %g = %g", x, y, x + y);
		break;
	case ('3'):
		printf("%g / %g = %g", x, y, x / y);
		break;
	case ('4'):
		printf("%g - %g = %g", x, y, x - y);
		break;
	case ('5'):
		printf("%g ^ %g = %g", x, y, pow(x, y));
		break;
	case ('6'):
		printf("Корень степени %g из %g = %g", y, x, pow(x, (1 / y)));
		break;
	default:
		system("cls");
		printf("Пожалуйста, введите корректное число.\n");
		goto start;
		break;
	}
	wrong_num: printf("\nПродолжить выполнение арифметических действий? \n1 - Да\n2 - Нет, вернуться в главное меню\nВыберите пункт: ");
	i = getch();
	switch (i)
	{
	case ('1'):
		system("cls");
		goto start;
		break;
	case ('2'):
		system("cls");
		menu();
		return;
	default:
		printf("Пожалуйста, введите корректное число.\n");
		goto wrong_num;
		break;		
	}
}

void matrixes() {
	int** matrix1;
	int** matrix2;
	int x;
	int rows1, collums1, rows2, collums2;
	char i;
	start: printf("1. Умножение матрицы на целое число\n2. Сложение матриц одной размерности\n3. Умножение матриц\n4. Вернуться в главное меню\nВыберите пункт: ");
	i = getch();
	switch (i)
	{
		if (i == '4') {
			system("cls");
			menu();
			return;
		}
	case ('1'):
		printf("\nВведите количество строк матрицы > ");
		scanf_s("%d", &rows1);
		printf("\nВведите количество столбцов матрицы > ");
		scanf_s("%d", &collums1);
		matrix1 = (int**)malloc(sizeof(int*) * rows1);
		setMatrix(rows1, collums1, matrix1, 'a');
		printf("\nЗаданная матрица:\n");
		printMatrix(rows1, collums1, matrix1);
		printf("\n");
		printf("Введите число, на которое хотите умножить матрицу > ");
		scanf_s("%d", &x);
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < collums1; j++) {
				matrix1[i][j] = matrix1[i][j] * x;
			}
		}
		printf("\nПолученная матрица: \n");
		printMatrix(rows1, collums1, matrix1);
		free(matrix1);
		break;
	case ('2'):
		printf("\nВведите количество строк матриц > ");
		scanf_s("%d", &rows1);
		printf("\nВведите количество столбцов матриц > ");
		scanf_s("%d", &collums1);
		rows2 = rows1;
		collums2 = collums1;
		matrix1 = (int**)malloc(sizeof(int*) * rows1);
		matrix2 = (int**)malloc(sizeof(int*) * rows2);
		setMatrix(rows1, collums1, matrix1, 'a');
		printf("\nЗаданная матрица A:\n");
		printMatrix(rows1, collums1, matrix1);
		printf("\n");
		setMatrix(rows2, collums2, matrix2, 'b');
		printf("\nЗаданная матрица B:\n");
		printMatrix(rows2, collums2, matrix2);
		printf("\n");
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < collums1; j++) {
				matrix1[i][j] += matrix2[i][j];
			}
		}
		printf("\nПолученная матрица:\n");
		printMatrix(rows1, collums1, matrix1);
		free(matrix1);
		free(matrix2);
		break;
	case ('3'):
	wrong_input: printf("\n!!Перемножение матриц возможно только когда количество СТОЛБЦОВ матрицы A равняется количеству СТРОК матрицы B");
		printf("\nВведите количество строк матрицы A > ");
		scanf_s("%d", &rows1);
		printf("\nВведите количество столбцов матрицы A > ");
		scanf_s("%d", &collums1);
		printf("\nВведите количество строк матрицы B > ");
		scanf_s("%d", &rows2);
		printf("\nВведите количество столбцов матрицы B > ");
		scanf_s("%d", &collums2);
		if (collums1 != rows2) {
			system("cls");
			goto wrong_input;
		}
		matrix1 = (int**)malloc(sizeof(int*) * rows1);
		matrix2 = (int**)malloc(sizeof(int*) * rows2);
		setMatrix(rows1, collums1, matrix1, 'a');
		printf("\nЗаданная матрица A:\n");
		printMatrix(rows1, collums1, matrix1);
		printf("\n");
		setMatrix(rows2, collums2, matrix2, 'b');
		printf("\nЗаданная матрица B:\n");
		printMatrix(rows2, collums2, matrix2);
		printf("\n");
		int** resultingMatrix = multiplyMatrixes(rows1, collums2, rows2, matrix1, matrix2);
		printf("\nПолученная матрица: \n");
		printMatrix(rows1, collums2, resultingMatrix);
		free(matrix1);
		free(matrix2);
		free(resultingMatrix);
		break;
	default:
		system("cls");
		printf("Пожалуйста, введите корректное число.\n");
		goto start;
		break;
	}
	wrong_num: printf("\nПродолжить выполнение операций над матрицами? \n1 - Да\n2 - Нет, вернуться в главное меню\nВыберите пункт: ");
	i = getch();
	switch (i)
	{
	case ('1'):
		system("cls");
		goto start;
		break;
	case ('2'):
		system("cls");
		menu();
		return;
	default:
		printf("Пожалуйста, введите корректное число.\n");
		goto wrong_num;
		break;
		
	}
}

int menu() {
	char i;
	start: printf("Главное меню\n");
	printf("1.Арифметические действия с десятичными числами\n2.Операции над матрицами\n3.Завершить выполнение программы\nВыберите пункт: ");
	i = getch();
	switch (i){
	case ('1'):
		system("cls");
		arifmetica();
		break;
	case ('2'):
		system("cls");
		matrixes();
		break;
	case ('3'):
		return 0;
	default:
		system("cls");
		printf("Пожалуйста, введите корректное число.\n");
		goto start;
		break;
	}
	return 0;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	menu();
}
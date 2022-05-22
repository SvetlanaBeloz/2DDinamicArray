#include <iostream>

void AllocateMemory(int**& arr, int height, int width)
{
	arr = new int* [height];
	for (int i = 0; i < height; i++)
	{
		arr[i] = new int[width] {0};
	}
}

void FillArrayInSpiral(int**& arr, int height, int width)
{
	int x = 0;
	int y = 0; 
	int current = 1;
	int direction = 1;
	int N = width * height;
	

	for (int i = 0; i < N; i++)
	{
		arr[y][x] = current++; 
		if (direction == 1) y++;
		else if (direction == 2) x++;
		else if (direction == 3) y--;
		else if (direction == 4) x--;

		if (direction == 1 && (y == height - 1 || arr[y + 1][x] != 0)) direction = 2;
		else if (direction == 2 && (x == width - 1 || arr[y][x + 1] != 0)) direction = 3;
		else if (direction == 3 && (y == 0 || arr[y - 1][x] != 0)) direction = 4;
		else if (direction == 4 && (x == 1 || arr[y][x - 1] != 0)) direction = 1;
	}
}

void ShowArray(int**& arr, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			std::cout << arr[y][x] << "\t";
		}
		std::cout << std::endl;
	}
}

void DeleteArray(int**& arr, int height)
{
	for (int i = 0; i < height; i++)
		delete[] arr[i];
	delete[] arr;
}


int main()
{
	int height = 0;
	int width = 0;
	std::cout << "Enter height" << std::endl;
	std::cin >> height;
	std::cout << "Enter width" << std::endl;
	std::cin >> width;
	std::cout << std::endl;
	int** arr;

	AllocateMemory(arr, height, width);
	FillArrayInSpiral(arr, height, width);
	ShowArray(arr, height, width);
	DeleteArray(arr, height);
}
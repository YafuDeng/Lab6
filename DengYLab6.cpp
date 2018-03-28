//Yafu Deng
//CPSC 121 Lab6
//3/27/2018

#include<iostream>
using namespace std;

/*
Create a program, with an array of 10 ints, that will:
  1.  Ask the user if they would like to:
    a)  input values 
    b)  provide a range for randomly generated values to fill the array 
    c)  use the default range for random values
    -Random values will be generated with the rand function. See end of chapter 8 slides.
  2.  Display all elements of the array
  3.  Ask the user to choose between sorting ascended and descended
  4.  Ask the user to choose between Bubble and Selection sort
Extra credit: Also include BOGOsort (aka dumb sort), where the array is shuffled randomly then checked for order. If BOGOsort is chosen, the user should be told how many shuffles the solution took.
  5.  Display the array
    -See 4
  6.  Ask the user if they wish to return to step 1. The array should be recreated if they return to step 1.
*/
const int SIZE = 10;

void mySwap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void fillRandom(int arr[], int range = 100, int min = 0)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % range + min;
}

int main()
{
	int arr[SIZE];
	int *p = arr;
	bool loop = 1;
	bool judge = 1;

	while (loop)
	{
		system("cls");
		char choice = 0;
		int range = 0;
		int min = 0;
		bool up = 0;
		//Ask the user of what they prefer to do
		//input value
		//provide a range for randomly generated values to fill the array
		//use the default range for for random values
		cout << "Choose the one you prefer from the following:\n";
		cout << "1. input value by your choice into the array with the size of 10;\n";
		cout << "2. provide a range for randomly generate values to fill the array with the size of 10;\n";
		cout << "3. use the default range for random values." << endl;


		while (judge)
		{
			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case '1':
			{
				//input value
				for (int i = 0; i < SIZE; i++)
					cin >> *(p+i);
				judge = 0;
				break;
			}
			case '2':
			{
				//input range for randomly generation
				cout << "Please enter the range and the start point you wish.";
				cin >> range >> min;
				for (int i = 0; i < SIZE; i++)
					*(p+i) = rand() % range + min;
				judge = 0;
				break;
			}
			case '3':
			{
				//default range
				fillRandom(arr);
				judge = 0;
				break;
			}
			default:
			{
				cout << "This is not a valid input. Please enter yout choice again." << endl;
				break;
			}
			}
		}



		//display all elements of the array
		for (int i = 0; i < SIZE; i++)
			cout << arr[i] << " ";
		cout << "\n" << endl;

		judge = 1;
		choice = '0';

		//ask the user to choose between sorting ascended and descended
		cout << "DO you want to sort the array ascended or descended?\n";
		cout << "Enter a if you want to sort ascended\n";
		cout << "Or enter b if you want to sort descended\n";
		
		while (judge)
		{
			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case 'a':
			{
				//sorting ascended, up
				up = 1;
				judge = 0;
				break;
			}
			case 'b':
			{
				//sorting descended, down
				up = 0;
				judge = 0;
				break;
			}
			default:
				cout << "This is not a valid input. Please enter your choice again." << endl;
				break;
			}
		}

		choice = '0';
		judge = 1;

		//ask the user to choose between bubble and selection sort or BOGOsort
		cout << "Which method do you want to sort the array\n";
		cout << "Enter 1 to use bubble sort\n";
		cout << "Or enter 2 to use slection sort\n";

		if (up)
		{
			while (judge)
			{
				cin >> choice;
				cout << endl;
				switch (choice)
				{
				case '1':
				{
					//bubble sort
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < (SIZE - i - 1); j++)
						{
							if (*(p + j) > *(p + j + 1))
							{
								mySwap(*(p + j), *(p + j + 1));
							}
						}
					}
					judge = 0;
					break;
				}
				case '2':
				{
					//selection sort
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = i+1; j < SIZE; j++)
						{
							if (*(p + j) < *(p+i))
								mySwap(*(p + j), *(p+i));
						}
					}
					judge = 0;
					break;
				}
				default:
					cout << "This is not a valid input. Please enter your choice again.\n";
					break;
				}
			}
		}
		else
		{
			while (judge)
			{
				cin >> choice;
				cout << endl;
				switch (choice)
				{
				case '1':
				{
					//bubble sort
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < (SIZE - i - 1); j++)
						{
							if (*(p + j) < *(p + j + 1))
							{
								mySwap(*(p + j), *(p + j + 1));
							}
						}
					}
					judge = 0;
					break;
				}
				case '2':
				{
					//selection sort
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = i + 1; j < SIZE; j++)
						{
							if (*(p + j) > *(p + i))
								mySwap(*(p + j), *(p + i));
						}
					}
					judge = 0;
					break;
				}
				default:
					cout << "This is not a valid input. Please enter your choice again.\n";
					break;
				}
			}
		}

		choice = '0';
		judge = 1;

		//display the array
		for (int i = 0; i < SIZE; i++)
			cout << arr[i] << " ";
		cout << "\n" << endl;

		//ask the user if they wish to return to step 1
		cout << "Do you want to do the process again?\n";
		cout << "Enter 1 if you want to redo\n";
		cout << "Or enter 0 if you want to end";
		cin >> loop;
	}

	system("pause");
	return 0;
}
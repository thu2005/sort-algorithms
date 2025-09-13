#include "function.h"

#if 1
int main(int argc, char *argv[])
{
	if (argc == 5)
	{

		string mode = argv[1];
		if (mode == "-a")
		{
			string input = argv[3];

			if (isFileExists(input))
			{

				// COMMAND 1
				// a.exe -a radix-sort input.txt -both
				// ./program -a insertion-sort input_1.txt -both
				int n;
				string algorithm = argv[2];
				string inputFile = argv[3];
				string outputParam = argv[4];

				int *a = readFile(inputFile, n);

				if (a == NULL)
					cout << "ERROR: Cannot open input file." << endl;
				else
				{
					cout << "ALGORITHM MODE" << endl;
					cout << "Algorithm: " << algorithm << endl;
					cout << "Input file: " << inputFile << endl;
					cout << "Input size: " << n << endl;
					cout << "------------------------------------" << endl;

					ll count_compare = 0;
					double time = 0;

					optionSort(a, n, algorithm, outputParam, count_compare, time);

					writeFile(a, n, "output.txt");

					if (outputParam == "-time")
						cout << "Running time: " << time << endl;
					else if (outputParam == "-comp")
						cout << "Comparisons: " << count_compare << endl;
					else if (outputParam == "-both")
					{
						cout << "Running time: " << time << endl;
						cout << "Comparisons: " << count_compare << endl;
					}
				}

				delete[] a;
			}

			else if (isNumber(input))
			{

				// COMMAND 3
				// a.exe -a binary-insertion-sort 70000 -comp
				// ./program -a flash-sort 100000 -comp
				string algorithm = argv[2];
				string inputSize = argv[3];
				string outputParam = argv[4];

				int n = stoi(inputSize);
				int *a = new int[n];

				cout << "ALGORITHM MODE" << endl;
				cout << "Algorithm: " << algorithm << endl;
				cout << "Input size: " << n << endl;
				cout << endl;

				GenerateData(a, n, 0);

				writeFile(a, n, "input_1.txt");

				ll count_compare = 0;
				double time = 0;

				optionSort(a, n, algorithm, outputParam, count_compare, time);

				cout << "Input order: Randomize" << endl;
				cout << "------------------------------------" << endl;
				if (outputParam == "-time")
					cout << "Running time: " << time << endl;
				else if (outputParam == "-comp")
					cout << "Comparisons: " << count_compare << endl;
				else if (outputParam == "-both")
				{
					cout << "Running time: " << time << endl;
					cout << "Comparisons: " << count_compare << endl;
				}

				cout << endl;

				GenerateData(a, n, 3);

				writeFile(a, n, "input_2.txt");

				count_compare = 0;
				time = 0;

				optionSort(a, n, algorithm, outputParam, count_compare, time);

				cout << "Input order: Nearly Sorted" << endl;
				cout << "------------------------------------" << endl;
				if (outputParam == "-time")
					cout << "Running time: " << time << endl;
				else if (outputParam == "-comp")
					cout << "Comparisons: " << count_compare << endl;
				else if (outputParam == "-both")
				{
					cout << "Running time: " << time << endl;
					cout << "Comparisons: " << count_compare << endl;
				}

				cout << endl;

				GenerateData(a, n, 1);

				writeFile(a, n, "input_3.txt");

				count_compare = 0;
				time = 0;

				optionSort(a, n, algorithm, outputParam, count_compare, time);

				cout << "Input order: Sorted" << endl;
				cout << "------------------------------------" << endl;
				if (outputParam == "-time")
					cout << "Running time: " << time << endl;
				else if (outputParam == "-comp")
					cout << "Comparisons: " << count_compare << endl;
				else if (outputParam == "-both")
				{
					cout << "Running time: " << time << endl;
					cout << "Comparisons: " << count_compare << endl;
				}

				cout << endl;

				GenerateData(a, n, 2);

				writeFile(a, n, "input_4.txt");

				count_compare = 0;
				time = 0;

				optionSort(a, n, algorithm, outputParam, count_compare, time);

				cout << "Input order: Reversed" << endl;
				cout << "------------------------------------" << endl;
				if (outputParam == "-time")
					cout << "Running time: " << time << endl;
				else if (outputParam == "-comp")
					cout << "Comparisons: " << count_compare << endl;
				else if (outputParam == "-both")
				{
					cout << "Running time: " << time << endl;
					cout << "Comparisons: " << count_compare << endl;
				}

				cout << endl;

				delete[] a;
				a = NULL;
			}
		}
		else if (mode == "-c")
		{
			// COMMAND 4
			// a.exe -c selection-sort insertion-sort input.txt
			// ./program -c selection-sort insertion-sort input_.txt
			// ./program -c bubble-sort heap-sort input_.txt
			// ./program -c merge-sort quick-sort input_.txt
			// ./program -c radix-sort shaker-sort input_.txt
			// ./program -c shell-sort count-sort input_.txt
			// ./program -c flash-sort count-sort input_.txt
			string algorithm1 = argv[2];
			string algorithm2 = argv[3];
			string inputFile = argv[4];

			int n;
			ll count_compare1 = 0, count_compare2 = 0;
			double time1 = 0, time2 = 0;

			int *a = readFile(inputFile, n);
			int *a1 = new int[n];
			int *a2 = new int[n];
			int *a3 = new int[n];

			for (int i = 0; i < n; i++)
			{
				a1[i] = a[i];
				a2[i] = a[i];
				a3[i] = a[i];
			}

			Time(a, n, algorithm1, time1);
			Time(a1, n, algorithm2, time2);
			Compare(a2, n, algorithm1, count_compare1);
			Compare(a3, n, algorithm2, count_compare2);

			cout << "COMPARE MODE" << endl;
			cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
			cout << "Input file: " << inputFile << endl;
			cout << "Input size: " << n << endl;
			cout << "------------------------------------" << endl;
			cout << "Running time: " << time1 << " | " << time2 << endl;
			cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;

			delete[] a;
			a = NULL;
			delete[] a1;
			a1 = NULL;
			delete[] a2;
			a2 = NULL;
			delete[] a3;
			a3 = NULL;
		}
	}

	else if (argc == 6)
	{

		string mode = argv[1];
		if (mode == "-a")
		{

			// COMMAND 2
			// a.exe -a selection-sort 50 -rand -time
			//./program -a flash-sort 50 -rand -time

			string algorithm = argv[2];
			string inputSize = argv[3];
			string inputOrder = argv[4];
			string outputParam = argv[5];

			int n = stoi(inputSize);
			int *a = new int[n];
			ll count_compare = 0;
			double time = 0;

			int order;
			if (inputOrder == "-rand")
				order = 0;
			else if (inputOrder == "-sorted")
				order = 1;
			else if (inputOrder == "-rev")
				order = 2;
			else if (inputOrder == "-nsorted")
				order = 3;

			GenerateData(a, n, order);

			writeFile(a, n, "input.txt");

			optionSort(a, n, algorithm, outputParam, count_compare, time);

			writeFile(a, n, "output.txt");

			cout << "ALGORITHM MODE" << endl;
			cout << "Algorithm: " << algorithm << endl;
			cout << "Input size: " << n << endl;
			cout << "Input order: " << inputOrder << endl;
			cout << "------------------------------------" << endl;

			if (outputParam == "-time")
				cout << "Running time: " << time << endl;
			else if (outputParam == "-comp")
				cout << "Comparisons: " << count_compare << endl;
			else if (outputParam == "-both")
			{
				cout << "Running time: " << time << endl;
				cout << "Comparisons: " << count_compare << endl;
			}

			delete[] a;
			a = NULL;
		}

		else if (mode == "-c")
		{

			// COMMAND 5
			// a.exe -c quick-sort merge-sort 100000 -nsorted
			//./program -c flash-sort shell-sort 100000 -nsorted

			string algorithm1 = argv[2];
			string algorithm2 = argv[3];
			string inputSize = argv[4];
			string inputOrder = argv[5];

			int n = stoi(inputSize);
			ll count_compare1 = 0, count_compare2 = 0;
			double time1 = 0, time2 = 0;

			int *a = new int[n];
			int *a1 = new int[n];
			int *a2 = new int[n];
			int *a3 = new int[n];

			int order;
			if (inputOrder == "-rand")
				order = 0;
			else if (inputOrder == "-sorted")
				order = 1;
			else if (inputOrder == "-rev")
				order = 2;
			else if (inputOrder == "-nsorted")
				order = 3;

			GenerateData(a, n, order);

			for (int i = 0; i < n; i++)
			{
				a1[i] = a[i];
				a2[i] = a[i];
				a3[i] = a[i];
			}

			Time(a, n, algorithm1, time1);
			Time(a1, n, algorithm2, time2);
			Compare(a2, n, algorithm1, count_compare1);
			Compare(a3, n, algorithm2, count_compare2);

			cout << "ALGORITHM MODE" << endl;
			cout << "Alogorithm: " << algorithm1 << " | " << algorithm2 << endl;
			cout << "Input size: " << n << endl;
			cout << "Input order: " << inputOrder << endl;
			cout << "------------------------------------" << endl;
			cout << "Running time: " << time1 << " | " << time2 << endl;
			cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;

			delete[] a;
			a = NULL;
			delete[] a1;
			a1 = NULL;
			delete[] a2;
			a2 = NULL;
			delete[] a3;
			a3 = NULL;
		}
	}

	return 0;
}

#endif

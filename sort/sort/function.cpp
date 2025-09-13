#include "function.h"

bool isFileExists(const string& filename) {
	ifstream file(filename);
	return file.good();
}

bool isNumber(const string& str) {
	for (char c : str) {
		if (c < '0' || c > '9') return false;
	}
	return true;
}

// Read an array data from an input file
int* readFile(string inputFile, int& n) {
	fstream input;

	input.open(inputFile, ios::in);

	if (!input.is_open())
		return NULL;

	input >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
		input >> a[i];
	input.close();

	return a;
}

//=============================================
// =========== SORT ===========================

// SORT CODE

// INSERTION SORT
void insertionSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// HEAP SORT
void heapify(int* arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int* arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

// SHELL SORT
void shellSort(int* arr, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
		gap /= 2;
	}
}

// FLASH SORT
void flashSort(int* arr, int n)
{
	int minVal = arr[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < minVal)
			minVal = arr[i];
		if (arr[i] > arr[max])
			max = i;
	}
	if (arr[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (arr[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (arr[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(arr[max], arr[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (arr[j] - minVal));
		}
		flash = arr[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = arr[t = --l[k]];
			arr[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(arr, n);
}

// COUNTING SORT
void countingSort(int* arr, int n) {

	int M = 0;
	for (int i = 0; i < n; i++) {
		M = max(M, arr[i]);
	}
	int* countArray = new int[M + 1] {0};
	for (int i = 0; i < n; i++) {
		countArray[arr[i]]++;
	}
	for (int i = 1; i <= M; i++) {
		countArray[i] += countArray[i - 1];
	}
	//tao mang output Array de tra ve ket qua
	int* outputArray = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		outputArray[countArray[arr[i]] - 1] = arr[i];
		countArray[arr[i]]--;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = outputArray[i];
	}
	delete[] countArray;
	delete[] outputArray;
}

// SHAKER SORT
void shakerSort(int* arr, int n) {
	int left = 0, right = n - 1, k = 0;
	while (left < right) {
		for (int i = left; i < right; i++)
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		right = k;

		for (int i = right; i > left; i--)
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		left = k;
	}
}
// BUBBLE SORT
void bubbleSort(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		bool swapped = false;
		//day max ve cuoi mang
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				swapped = true;
				HoanVi(a[j], a[j + 1]);
			}
		if (!swapped)
			return;
	}
}

// SELECTION SORT
void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

// QUICK SORT
void quickSort(int* arr, int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];

	//partition
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

// MERGE SORT
void merge(int* arr, int nb, int nc, int k, int* b, int* c) {
	int p, pb, pc, ib, ic, kb, kc;
	p = pb = pc = 0;
	ib = ic = 0;
	while ((0 < nb) && (0 < nc)) {
		kb = min(k, nb);
		kc = min(k, nc);
		if (b[pb + ib] <= c[pc + ic]) {
			arr[p++] = b[pb + ib];
			ib++;
			if (ib == kb) {
				for (; ic < kc; ic++) {
					arr[p++] = c[pc + ic];
				}
				pb += kb;
				pc += kc;
				ib = ic = 0;
				nb -= kb;
				nc -= kc;
			}
		}
		else {
			arr[p++] = c[pc + ic];
			ic++;
			if (ic == kc) {
				for (; ib < kb; ib++) {
					arr[p++] = b[pb + ib];
				}
				pb += kb;
				pc += kc;
				ib = ic = 0;
				nb -= kb;
				nc -= kc;
			}
		}
	}
}
void mergeSort(int* arr, int n) {
	int* b = new int[n];
	int* c = new int[n];
	int p, pb, pc; // cac chi so tren cac mang a,b,c
	int i, k = 1; // do dai cua day con khi phan hoach
	do {
		// tach a thanh b va c
		p = pb = pc = 0;
		while (p < n) {
			for (i = 0; (p < n) && (i < k); i++)
				b[pb++] = arr[p++];
			for (i = 0; (p < n) && (i < k); i++)
				c[pc++] = arr[p++];
		}
		merge(arr, pb, pc, k, b, c);
		k *= 2;
	} while (k < n);
	delete[] b;
	delete[] c;
}

// RADIX SORT
int getMax(int* arr, int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort(int* arr, int n, int exp) {
	vector<int> output(n);
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
	}
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void radixSort(int* arr, int n) {
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}


// =============================================
// ==== COUNT COMPARISON =======================

// COMPARISON CODE

// INSERTION SORT
void insertionSort_withCount(int* arr, int n, ll& count_compare)
{
	for (int i = 1; ++count_compare && i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while ((++count_compare && j >= 0) && (++count_compare && key < arr[j]))
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

// HEAP SORT
void heapify_withCount(int* arr, int n, int i, ll& count_compare) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// So sánh với con trái
	if ((++count_compare && (left < n)) && (++count_compare && (arr[left] > arr[largest]))) {
		largest = left;
	}

	// So sánh với con phải
	if ((++count_compare && (right < n)) && (++count_compare && (arr[right] > arr[largest]))) {
		largest = right;
	}

	// Nếu phần tử lớn nhất không phải là gốc
	if (++count_compare && largest != i) {
		swap(arr[i], arr[largest]);
		heapify_withCount(arr, n, largest, count_compare);
	}
}
void heapSort_withCount(int* arr, int n, ll& count_compare) {
	// Xây dựng heap
	for (int i = n / 2 - 1; ++count_compare && (i >= 0); i--) {
		heapify_withCount(arr, n, i, count_compare);
	}

	// Trích xuất từng phần tử từ heap
	for (int i = n - 1; ++count_compare && (i > 0); i--) {
		swap(arr[0], arr[i]); // Đưa gốc (lớn nhất) về cuối mảng
		heapify_withCount(arr, i, 0, count_compare);
	}
}

// SHELL SORT
void shellSort_withCount(int* arr, int n, ll &count_compare)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap)
            { 
				count_compare++;
                if (arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

// FLASH SORT
void flashSort_withCount(int* arr, int n, long long& count_compare) {
	if (n <= 1)
		return;

	int minVal = arr[0], maxVal = arr[0], maxIndex = 0;
	// Tìm giá trị nhỏ nhất và lớn nhất
	for (int i = 1; i < n; i++) {
		if (++count_compare && arr[i] < minVal) {
			minVal = arr[i];
		}
		if (++count_compare && arr[i] > maxVal) {
			maxVal = arr[i];
			maxIndex = i;
		}
	}
	if (++count_compare && maxVal == minVal)
		return;

	int m = floor(0.45 * n);
	int* l = new int[m](); // Mảng l khởi tạo giá trị 0
	// Phân phối các phần tử vào các lớp
	double c1 = (double)(m - 1) / (maxVal - minVal);
	for (int i = 0; i < n; i++) {
		int k = floor(c1 * (arr[i] - minVal));
		if (k >= m) k = m - 1; // Giới hạn k trong khoảng [0, m-1]
		l[k]++;
	}

	// Tích lũy mảng L
	for (int k = 1; k < m; k++) {
		l[k] += l[k - 1];
	}

	// Đưa phần tử lớn nhất về đầu mảng
	swap(arr[maxIndex], arr[0]);

	int move = 0;
	int j = 0;
	int k = m - 1;

	// Flash sort
	while (++count_compare && move < n - 1) {
		while (++count_compare && j > l[k] - 1) {
			j++;
			if (j >= n) break; // Kiểm tra giới hạn mảng
			k = floor(c1 * (arr[j] - minVal));
			if (k >= m) k = m - 1; // Giới hạn k trong khoảng [0, m-1]
		}
		if (j >= n) break;

		int flash = arr[j];
		while (++count_compare && j != l[k]) {
			k = floor(c1 * (flash - minVal));
			if (k >= m) k = m - 1; // Giới hạn k trong khoảng [0, m-1]
			int t = --l[k];
			swap(flash, arr[t]);
			move++;
		}
	}
	// Giải phóng mảng L
	delete[] l;
	// Gọi hàm sắp xếp chèn để hoàn thiện
	insertionSort_withCount(arr, n, count_compare);
}

// COUNTING SORT
void countingSort_withCount(int* arr, int n, ll& count_compare) {

	int M = 0;
	for (int i = 0; ++count_compare && i < n; i++) {
		M = max(M, arr[i]);
	}
	int* countArray = new int[M + 1] {0};
	for (int i = 0; ++count_compare && i < n; i++) {
		countArray[arr[i]]++;
	}
	for (int i = 1; ++count_compare && i <= M; i++) {
		countArray[i] += countArray[i - 1];
	}
	//tao mang output Array de tra ve ket qua
	int* outputArray = new int[n];
	for (int i = n - 1; ++count_compare && i >= 0; i--) {
		outputArray[countArray[arr[i]] - 1] = arr[i];
		countArray[arr[i]]--;
	}
	for (int i = 0; ++count_compare && i < n; i++) {
		arr[i] = outputArray[i];
	}
	delete[] countArray;
	delete[] outputArray;
}

// SHAKER SORT
void shakerSort_withCount(int* arr, int n, ll& count_compare) {
	int left = 0, right = n - 1, k = 0;
	while (++count_compare && left < right) {
		for (int i = left; ++count_compare && i < right; i++)
			if (++count_compare && arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		right = k;

		for (int i = right; ++count_compare && i > left; i--)
			if (++count_compare && arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		left = k;
	}
}

// BUBBLE SORT
void bubbleSort_withCount(int* arr, int n, ll& count_compare) {
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		bool swapped = false;
		for (int j = 0; ++count_compare && j < n - i - 1; j++) {
			if (++count_compare && arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
			
		}
		if (++count_compare && !swapped)
				break;
	}
}

// SELECTION SORT
void selectionSort_withCount(int* arr, int n, ll& count_compare) {
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; ++count_compare && j < n; j++) {
			if (++count_compare && arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

// QUICK SORT
void quickSort_withCount(int* arr, int left, int right, ll& count_compare) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];

	//partition
	while (++count_compare && i <= j) {
		while (++count_compare && arr[i] < pivot)
			i++;
		while (++count_compare && arr[j] > pivot)
			j--;
		if (++count_compare && i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (++count_compare && left < j)
		quickSort(arr, left, j);
	if (++count_compare && i < right)
		quickSort(arr, i, right);
}

// MERGE SORT
void merge_withCount(int* arr, int nb, int nc, int k, int* b, int* c, ll& count_compare) {
	int p, pb, pc, ib, ic, kb, kc;
	p = pb = pc = 0;
	ib = ic = 0;
	while ((++count_compare && (0 < nb)) && (++count_compare && (0 < nc))) {
		kb = min(k, nb);
		kc = min(k, nc);
		if (++count_compare && (b[pb + ib] <= c[pc + ic])) {
			arr[p++] = b[pb + ib];
			ib++;
			if (++count_compare && (ib == kb)) {
				for (; ++count_compare && (ic < kc); ic++) {
					arr[p++] = c[pc + ic];
				}
				pb += kb;
				pc += kc;
				ib = ic = 0;
				nb -= kb;
				nc -= kc;
			}
		}
		else {
			arr[p++] = c[pc + ic];
			ic++;
			if (++count_compare && (ic == kc)) {
				for (; ++count_compare && (ib < kb); ib++) {
					arr[p++] = b[pb + ib];
				}
				pb += kb;
				pc += kc;
				ib = ic = 0;
				nb -= kb;
				nc -= kc;
			}
		}
	}
}
void mergeSort_withCount(int* arr, int n, ll& count_compare) {
	int* b = new int[n];
	int* c = new int[n];
	int p, pb, pc; // cac chi so tren cac mang a,b,c
	int i, k = 1; // do dai cua day con khi phan hoach
	do {
		// tach a thanh b va c
		p = pb = pc = 0;
		while (++count_compare && p < n) {
			for (i = 0; (++count_compare && p < n) && (++count_compare && i < k); i++)
				b[pb++] = arr[p++];
			for (i = 0; (++count_compare && p < n) && (++count_compare && i < k); i++)
				c[pc++] = arr[p++];
		}
		merge_withCount(arr, pb, pc, k, b, c, count_compare);
		k *= 2;
	} while (++count_compare && k < n);
	delete[] b;
	delete[] c;
}

// RADIX SORT
void getMax_withCount(int* arr, int n, int& mx, ll& count_compare) {
	mx = arr[0];
	for (int i = 1; ++count_compare && (i < n); i++)
		if (++count_compare && (arr[i] > mx))
			mx = arr[i];
}
void countSort_withCount(int* arr, int n, int exp, ll& count_compare) {
	vector<int> output(n);
	int i, count[10] = { 0 };
	for (i = 0; ++count_compare && (i < n); i++) {
		count[(arr[i] / exp) % 10]++;
	}
	for (i = 1; ++count_compare && (i < 10); i++)
		count[i] += count[i - 1];
	for (i = n - 1; ++count_compare && (i >= 0); i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; ++count_compare && (i < n); i++)
		arr[i] = output[i];
}
void radixSort_withCount(int* arr, int n, ll& count_compare) {
	int m;
	getMax_withCount(arr, n, m, count_compare);
	for (int exp = 1; ++count_compare && (m / exp > 0); exp *= 10)
		countSort_withCount(arr, n, exp, count_compare);
}


// 
// Write an array data into output file
void writeFile(int* a, int n, string outputFile) {
	fstream output;

	output.open(outputFile, ios::out);

	if (!output.is_open()) {
		cout << "ERROR: Cannot open output file. " << endl;
		delete[]a;
		a = NULL;
		return;
	}

	output << n << endl;

	for (int i = 0; i < n; i++)
		output << a[i] << " ";

	output.close();
}

// Pick a sort from commandline
void optionSort(int* a, int n, string algorithm, string outputParam, ll& count_compare, double& time) {
	if (outputParam == "-time")
		Time(a, n, algorithm, time);
	else if (outputParam == "-comp")
		Compare(a, n, algorithm, count_compare);
	else if (outputParam == "-both")
	{
		int* b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = a[i];

		Time(b, n, algorithm, time);
		Compare(a, n, algorithm, count_compare);
		delete[]b; b = NULL;
	}
}

void Compare(int* a, int n, string algorithm, ll& count_compare) {
	if (algorithm == "selection-sort")
	{
		selectionSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "insertion-sort")
	{
		insertionSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "bubble-sort")
	{
		bubbleSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "heap-sort")
	{
		heapSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "merge-sort")
	{
		mergeSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "quick-sort")
	{
		quickSort_withCount(a, 0, n - 1, count_compare);
	}
	else if (algorithm == "radix-sort")
	{
		radixSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "shaker-sort")
	{
		shakerSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "shell-sort")
	{
		shellSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "count-sort")
	{
		countingSort_withCount(a, n, count_compare);
	}
	else if (algorithm == "flash-sort")
	{
		flashSort_withCount(a, n, count_compare);
	}

}

void Time(int* a, int n, string algorithm, double& time) {
	if (algorithm == "selection-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		selectionSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "insertion-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		insertionSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "bubble-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		bubbleSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "heap-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		heapSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "merge-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		mergeSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "quick-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		quickSort(a, 0, n - 1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "radix-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		radixSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "shaker-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		shakerSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "shell-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		shellSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if (algorithm == "count-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		countingSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
	else if  (algorithm == "flash-sort")
	{
		auto start = chrono::high_resolution_clock::now();
		flashSort(a, n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = end - start;
		time = elapsed.count();
	}
}

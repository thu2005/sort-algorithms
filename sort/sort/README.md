# Sorting Algorithms Comparison

## Giới thiệu

Project so sánh hiệu năng các thuật toán sắp xếp, cho phép:
- Đo thời gian thực thi và số phép so sánh của từng thuật toán.
- So sánh hai thuật toán trên cùng một bộ dữ liệu.
- Hỗ trợ nhiều kiểu dữ liệu đầu vào: ngẫu nhiên, tăng dần, giảm dần, gần như có thứ tự.

## Các thuật toán hỗ trợ

- Insertion Sort
- Heap Sort
- Shell Sort
- Flash Sort
- Counting Sort
- Shaker Sort
- Bubble Sort
- Selection Sort
- Quick Sort
- Merge Sort
- Radix Sort

## Cách sử dụng

### Biên dịch

```sh
g++ main.cpp function.cpp DataGenerator.cpp -o sort
```

### Chạy chương trình

#### 1. Chế độ thuật toán (`-a`)

- Sử dụng file input:
  ```
  sort -a <algorithm> <input_file> <output_param>
  ```
  - `<output_param>`: `-time`, `-comp`, hoặc `-both`

- Sinh dữ liệu tự động:
  ```
  sort -a <algorithm> <input_size> <output_param>
  ```
  hoặc
  ```
  sort -a <algorithm> <input_size> <input_order> <output_param>
  ```
  - `<input_order>`: `-rand`, `-sorted`, `-rev`, `-nsorted`

#### 2. Chế độ so sánh (`-c`)

- So sánh trên file input:
  ```
  sort -c <algorithm1> <algorithm2> <input_file>
  ```

- So sánh trên dữ liệu sinh tự động:
  ```
  sort -c <algorithm1> <algorithm2> <input_size> <input_order>
  ```

## Cấu trúc thư mục

- `main.cpp`: Chương trình chính, xử lý tham số dòng lệnh.
- `function.cpp`, `function.h`: Cài đặt các thuật toán sắp xếp và hàm hỗ trợ.
- `DataGenerator.cpp`: Sinh dữ liệu đầu vào với nhiều kiểu khác nhau.


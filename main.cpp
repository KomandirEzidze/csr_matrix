#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct CSR
{
  int *value;
  int *j_index;
  int *pos;
  int nnz;
};

int main()
{
    ifstream file;
	  file.open("csr_matrix.txt");

    string data;
    CSR matrix;

    if (file.is_open()) {
        file >> data;
        matrix.nnz = atoi(data.c_str());
        matrix.value = new int[matrix.nnz];
        matrix.j_index = new int[matrix.nnz];
        matrix.pos = new int[matrix.nnz];

        for(int i=0;!file.eof();i++) {
            file >> data;
            matrix.value[i] = atoi(data.c_str());
            file >> data;
            matrix.j_index[i] = atoi(data.c_str());
            file >> data;
            matrix.pos[i] = atoi(data.c_str());
        }

        for(int i=0;i<matrix.nnz;i++) {
          cout << matrix.value[i] << " " << matrix.j_index[i] << " " << matrix.pos[i] << "\n";
        }

        file.close();
    } else {
        cout << "Не удалось открыть файл.\n";
    }

    return 0;
}

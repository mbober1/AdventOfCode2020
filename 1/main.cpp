#include <fstream>

int main() {
    std::ifstream report("input.txt");
    std::string line;
    int dupa = 0;
    int raportSize = 200;
    int* data = new int[raportSize];

    for(int i = 0; i < raportSize; ++i) {
        std::getline(report, line);
        int number = std::stoi(line);
        data[dupa++] = number;
    }
    report.close();

    
    for(int i = 0; i < raportSize; ++i) {
        for(int j = 0; j < raportSize; ++j) {
            for(int k = 0; k < raportSize; ++k) {
                if (data[i] + data[j] + data[k] == 2020) printf("Liczba %d, %d i %d. Wynik: %d \n", data[i], data[j], data[k],  data[k]*data[j]*data[i]);
            }
        }
    }

    return 0;
}
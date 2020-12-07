#include <fstream>
#include <iostream>

int main() {
    std::ifstream database ("input3.txt");
    int trees = 0;
    
    std::string line[323];

    char buffor[32];
    int i = 0;

    if (database) {
        while(!database.eof())
        {
            database.getline(buffor,32);
            line[i] = buffor;
            std::cout << line[i] << std::endl;
            i++;
        }
    }  else printf("Nie ma pliku!");

    int x = 0;

    for(int index = 0; index < 323; ++index) {
        if(line[index][x] == '#') trees++; 
        x = (x+3) % line->length();
    }

    printf("Drzewa: %d", trees);

    return 0;
}
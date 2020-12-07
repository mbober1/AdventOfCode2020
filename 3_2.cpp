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

    int x= 0;
    unsigned long long result = 1;

    for(int index = 0; index < 323; ++index) {
        if(line[index][x] == '#') trees++; 
        x = (x+1) % line->length();
    }
    x= 0;
    result *= trees;
    printf("%d\n", trees);
    trees = 0;

    for(int index = 0; index < 323; ++index) {
        if(line[index][x] == '#') trees++; 
        x = (x+3) % line->length();
    }
    x= 0;

    result *= trees;
    printf("%d\n", trees);
    trees = 0;

    for(int index = 0; index < 323; ++index) {
        if(line[index][x] == '#') trees++; 
        x = (x+5) % line->length();
    }
    x= 0;
    result *= trees;
    printf("%d\n", trees);
    trees = 0;

    for(int index = 0; index < 323; ++index) {
        if(line[index][x] == '#') trees++; 
        x = (x+7) % line->length();
    }
    x= 0;
    result *= trees;
    printf("%d\n", trees);
    trees = 0;

    for(int index = 0; index < 323; index+=2) {
        if(line[index][x] == '#') trees++; 
        x = (x+1) % line->length();
    }
    x= 0;
    result *= trees;
    printf("%d\n", trees);
    trees = 0;
    

    // printf("Drzewa: %d", result);
    std::cout << result;

    return 0;
}
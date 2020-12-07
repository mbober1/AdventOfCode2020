#include <fstream>
#include <iostream>

int main() {
    int goodPass = 0;
    std::ifstream database ("input2.txt", std::ifstream::binary);

    if (database) {

        std::string buffer;
        while(!database.eof())
        {
            getline(database,buffer,'-');
            int first = std::stoi(buffer);
            // std::cout << first << " ";

            getline(database,buffer,' ');
            int second = std::stoi(buffer);
            // std::cout << second << " ";

            getline(database,buffer,':');
            char letter = *buffer.c_str();

            // std::cout << letter << " ";

            getline(database,buffer);
            // std::cout << buffer;

            if(buffer[first]==letter ^ buffer[second]==letter) goodPass++;
        }
    }  else printf("Nie ma pliku!");

    printf(" Dobrych haseł %d \n", goodPass);

    return 0;
}
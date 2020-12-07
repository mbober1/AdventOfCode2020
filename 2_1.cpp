#include <fstream>
#include <iostream>

int main() {
    int goodPass = 0;
    std::ifstream database ("2/input.txt", std::ifstream::binary);

    if (database) {

        std::string buffer;
        while(!database.eof())
        {
            getline(database,buffer,'-');
            int min = std::stoi(buffer);
            std::cout << min << " ";

            getline(database,buffer,' ');
            int max = std::stoi(buffer);
            std::cout << max << " ";

            getline(database,buffer,':');
            char letter = *buffer.c_str();

            std::cout << letter << " ";

            getline(database,buffer);
            std::cout << buffer;

            int count = 0;
            
            std::size_t found = buffer.find(letter);
            while (found!=std::string::npos)
            {
                buffer[found] = '*';
                count++;
                found = buffer.find(letter);
            }
            printf(" Znaleziono %c %d razy \n", letter, count);

            if(count <= max && count >= min) goodPass++;
        }
    }

    printf(" Dobrych haseł %d \n", goodPass);

    return 0;
}
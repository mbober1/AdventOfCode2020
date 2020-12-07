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
            char dupa = *buffer.c_str();

            std::cout << dupa << " ";

            getline(database,buffer);
            std::cout << buffer;

            int count = 0;
            
            std::size_t found = buffer.find(dupa);
            while (found!=std::string::npos)
            {
                buffer[found] = '*';
                count++;
                found = buffer.find(dupa);
            }
            printf(" Znaleziono %c %d razy \n", dupa, count);

            if(count <= max && count >= min) goodPass++;
        }
    }

    printf(" Dobrych haseł %d \n", goodPass);

    return 0;
}
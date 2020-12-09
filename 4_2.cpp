#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>



int main() {
    std::ifstream database ("input4.txt");
    
    std::string data, line, category;
    int byr, iyr, eyr, hgt, pid, cid, hcl, ecl;
    int valid = 0;


    if (database) {
        while(!database.eof())
        {
            byr = iyr = eyr = hgt = pid = cid = hcl = ecl = 0;

            while(getline(database,line, '\n')) {
                std::stringstream ss(line);

                if((!line.length())) {
                        if(byr && iyr && eyr && hgt && pid && hcl && ecl) valid++;
                        byr = iyr = eyr = hgt = pid = cid = hcl = ecl = 0;
                } else {
                    while(getline(ss, category, ':')){

                        if(category == "byr") {
                            getline(ss, data, ' ');
                            int validation = std::stoi(data);
                            if(validation >= 1920 && validation <= 2002) byr = 1;
                        }
                        else if(category == "iyr") {
                            getline(ss, data, ' ');
                            int validation = std::stoi(data);
                            if(validation >= 2010 && validation <= 2020) iyr = 1;
                        }
                        else if(category == "eyr") {
                            getline(ss, data, ' ');
                            int validation = std::stoi(data);
                            if(validation >= 2020 && validation <= 2030) eyr = 1;
                        }
                        else if(category == "hgt") {
                            getline(ss, data, ' ');

                            if(data.back() == 'm') {
                                data.pop_back();
                                data.pop_back();
                                int validation = std::stoi(data);
                                if(validation >= 150 && validation <= 193) hgt = 1;
                            }
                            else if(data.back() == 'n') {
                                data.pop_back();
                                data.pop_back();
                                int validation = std::stoi(data);
                                if(validation >= 59 && validation <= 76) hgt = 1;
                            }
                        }
                        else if(category == "pid") {
                            getline(ss, data, ' ');
                            if(data.length() == 9) {
                                pid = 1;
                                for(int i = 0; i<9; i++) {
                                    if(data[i] > '9' || data[i] < '0') pid = 0;
                                }
                            }
                        }
                        else if(category == "cid") {
                            getline(ss, data, ' ');
                            cid = 1;
                        }
                        else if(category == "hcl") {
                            getline(ss, data, ' ');
                            if(data[0] == '#' && data.length() == 7) {
                                hcl = 1;
                                for(int i = 1; i<7; i++) if(data[i] < '0' || (data[i] > '9' && data[i] < 'a') || data[i] > 'f') hcl = 0;
                            }
                        }
                        else if(category == "ecl") {
                            getline(ss, data, ' ');
                            if(data == "amb" || data == "gry" || data == "blu" || data == "brn" || data == "grn" || data == "hzl" || data == "oth") ecl = 1;
                        }
                        else {
                            printf("error");
                        }
                    }
                }
            }
            

        }
    }  else printf("Nie ma pliku!");

    printf("Poprawnych: %d \n", valid);

    return 0;
}
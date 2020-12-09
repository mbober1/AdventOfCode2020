#include <fstream>
#include <iostream>
#include <sstream>


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
                            byr = 1;
                        }
                        else if(category == "iyr") {
                            getline(ss, data, ' ');
                            iyr = 1;
                        }
                        else if(category == "eyr") {
                            getline(ss, data, ' ');
                            eyr = 1;
                        }
                        else if(category == "hgt") {
                            getline(ss, data, ' ');
                            hgt = 1;
                        }
                        else if(category == "pid") {
                            getline(ss, data, ' ');
                            pid = 1;
                        }
                        else if(category == "cid") {
                            getline(ss, data, ' ');
                            cid = 1;
                        }
                        else if(category == "hcl") {
                            getline(ss, data, ' ');
                            hcl = 1;
                        }
                        else if(category == "ecl") {
                            getline(ss, data, ' ');
                            ecl = 1;
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
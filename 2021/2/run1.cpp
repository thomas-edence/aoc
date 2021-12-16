#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

const std::string FORWARD = "forward";
const std::string DOWNWARD = "down";
const std::string UPWARD = "up";
const std::string input_file_name = "input.txt";

template <char delimiter, class Container>
static void split(std::istream& stream, Container& cont)
{
    // get the line from the stream
    std::string line, token;
    std::getline(stream, line);
    
    // now split the line with the delimiter
    std::stringstream ss(line);
    while (std::getline(ss, token, delimiter)) {
        // ignore all whitespace lines
        if(token.find_first_not_of(' ') != std::string::npos){
            cont.push_back(token);
        }
    }
}

int main(){

    std::string line;
    std::ifstream input_file(input_file_name);

    std::map<const std::string, int> sums {{FORWARD, 0}, {DOWNWARD, 0}, {UPWARD, 0} }; 
    while(std::getline(input_file, line)){
        std::stringstream stream(line);
        std::vector<std::string> contents;
        split<' '>(stream, contents);
        // std::cout << contents[0] << contents[1] << "\n";
        sums[contents[0]] += std::stoi(contents[1]);
    }

    input_file.close();
    for(const auto& [key, value]: sums){
         std::cout << key << " = " << value << "\n";
    }

    const int result = sums[FORWARD]*(sums[DOWNWARD]-sums[UPWARD]);
    std::cout << "Result = " << result << "\n";

    return 0;
}

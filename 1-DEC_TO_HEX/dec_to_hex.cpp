#include <iostream>
#include <string>
#include <algorithm>

void DecToHex(uint64_t N) {
char hex_list[17] = "0123456789ABCDEF";    
std::string out;
if (N==0) {
    std::cout << "0";
    return;
}    

while (N!=0) {    
    out.push_back(hex_list[N%16]);    
    N/=16;
}

std::reverse(out.begin(),out.end());
std::cout << out;

}

int main() {
uint64_t N;
std::cin >> N;

DecToHex(N);

}

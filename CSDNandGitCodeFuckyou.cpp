#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

void blockWebsite(const std::string& website, std::ofstream& hostsFile) {
    hostsFile << "127.0.0.1 " << website << std::endl;
    hostsFile << "::1 " << website << std::endl; // IPv6 loopback address
}

int main() {
    std::string hostsPath = "C:\\Windows\\System32\\drivers\\etc\\hosts";

    std::vector<std::string> websitesToBlock = {"csdn.com", "gitcode.com"};

  
    std::ofstream hostsFile(hostsPath, std::ios::app);
    if (!hostsFile.is_open()) {
        std::cerr << "无法打开 hosts 文件" << std::endl;
        return 1;
    }

    for (const auto& website : websitesToBlock) {
        blockWebsite(website, hostsFile);
    }

    hostsFile.close();

    std::cout << "successful" << std::endl;

    return 0;
}

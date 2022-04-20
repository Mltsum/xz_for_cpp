#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "src/xz/decode.hpp"
#include "src/xz/encode.hpp"
using namespace std;

int main(int argc, char *argv[])  // argc是main内使用参数个数+1,argv[0]是文件路径，argv[1]是文件名
{
    cout << "enter main ... " << endl;
    string inFilePath = "/Users/mingren/Documents/09.demoTest/cppDemo/data/2020090100382966.txt";
    string outFilePath = "/Users/mingren/Documents/09.demoTest/cppDemo/data/2020090100382966.txt.xz";

    filebuf inBuf, outBuf;
    if (inBuf.open(inFilePath.c_str(), ios::in) == nullptr) {
        cout << "打开输入文件出错" << endl;
        return -1;
    }
    istream inFile(&inBuf);

    if (outBuf.open(outFilePath.c_str(), ios::out) == nullptr) {
        cout << "打开输出文件出错" << endl;
        return -1;
    }
    ostream outFile(&outBuf);

    bool success = xz::compress(inFile, outFile);
    fclose(stdout);
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}

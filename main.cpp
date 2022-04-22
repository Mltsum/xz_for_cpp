#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "src/xz/decode.hpp"
#include "src/xz/encode.hpp"
using namespace std;

int main(int argc, char *argv[])  // argc是main内使用参数个数+1,argv[0]是文件路径，argv[1]是文件名
{
    cout << __LINE__ << endl;
    string inFilePath = "/data/local/tmp/lzma_compress/2020090100382966.txt";
    string outFilePath = "/data/local/tmp/lzma_compress//2020090100382966.txt.xz";

    filebuf inBuf, outBuf;
    if (inBuf.open(inFilePath.c_str(), ios::in) == nullptr) {
        cout << "打开输入文件出错" << endl;
        return -1;
    }
    cout << __LINE__ << endl;
    istream inFile(&inBuf);

    if (outBuf.open(outFilePath.c_str(), ios::out) == nullptr) {
        cout << "打开输出文件出错" << endl;
        return -1;
    }
    ostream outFile(&outBuf);
    cout << __LINE__ << endl;
    bool success = xz::compress(inFile, outFile);
    fclose(stdout);
    cout << __LINE__ << endl;
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}

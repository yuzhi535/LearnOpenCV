#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    try
    {
        FileStorage fs;
        fs.open("abc.yaml", FileStorage::WRITE);

        fs << "string";
        fs << "["; // vector
        fs << "jpg"
           << "hello";

        fs << "str"
           << "justin";
        fs << "]";

        fs << "hero";
        fs << "{" // map
           << "parker"
           << "spider man";
        fs << "ironman"
           << "i don't know"
           << "}";

        fs << "framecount" << 5 << "hello"
           << "world"
           << "hey";

        fs.release();

        fs.open("abc.yaml", FileStorage::READ);

        FileNode n = fs["string"];

        if (n.type() != FileNode::SEQ)
        {
            std::cerr << "wrong" << std::endl;
        }
        else
        {
            FileNodeIterator it = n.begin(), it_end = n.end();

            for (; it != it_end; ++it)
            {
                cout << (std::string)*it << endl;
            }
        }
        fs.release();
    }
    catch (char *err)
    {
        cout << "err is " << err << endl;
    }

    return 0;
}
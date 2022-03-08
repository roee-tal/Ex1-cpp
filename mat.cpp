#include "mat.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    string mat(int len, int height, char sign1, char sign2){
        if(len % 2 == 0 || height % 2 == 0){
            throw invalid_argument("Mat size is always odd");
        }
        if(len <0 || height < 0)
        {
            throw invalid_argument("Mat size is always positive");
        }
        string res;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < len; j++)
            {
                res.push_back(sign1);
            }
            res.push_back('\n');
        }
        return res;
    }
}

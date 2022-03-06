#include "mat.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    string mat(int len, int height, char sign1, char sign2){
        if(len %2 == 0 || height %2 == 0){
            throw invalid_argument("Mat size is always odd");
        }
        if(len <0 || height < 0)
        {
            throw invalid_argument("Mat size is always positive");
        }
        char matrix[height][len];  
        for(int i=0;i<height;i++){
            for(int j=0;j<len;j++){
                matrix[i][j] = sign1;
            }

        }
        string res;
         for(int i=0;i<height;i++){
            for(int j=0;j<len;j++){
                res.push_back(matrix[i][j]);
            }
            res += "\n";
    }
    return res;
}
}
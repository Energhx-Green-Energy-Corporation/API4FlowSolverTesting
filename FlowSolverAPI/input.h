#pragma once
#include "mymain.h"

void input(std::ifstream& infile, std::string& outpfn, float& xl, float& yl, int& nx, int& ny)
{
    std::string datalabel;
    infile >> outpfn >> datalabel;
    infile >> xl >> datalabel;
    infile >> yl >> datalabel;
    infile >> nx >> datalabel;
    infile >> ny >> datalabel;
}

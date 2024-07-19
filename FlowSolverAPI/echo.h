#pragma once
#include "mymain.h"

void echo(std::ofstream& outfile, const std::string& datafn, int ib, int ie, int jb, int je, int id, int jd, float xl, float yl, int nx, int ny)
{
    outfile << "Input data was read from: " << datafn << "\n";
    outfile << "==== Input Data ======\n\n";
    outfile << "X length = " << xl << " [m]\n";
    outfile << "Y length = " << yl << " [m]\n";
    outfile << "<<<< Array Parameters >>>>\n";
    outfile << "Number of x nodes = " << nx << "\n";
    outfile << "    I begin index = " << ib << "\n";
    outfile << "    I end   index = " << ie << "\n";
    outfile << "Number of y nodes = " << ny << "\n";
    outfile << "    J begin index = " << jb << "\n";
    outfile << "    J end   index = " << je << "\n";
    outfile << "I array dimension = " << id + 1 << "\n";
    outfile << "J array dimension = " << jd + 1 << "\n";
}

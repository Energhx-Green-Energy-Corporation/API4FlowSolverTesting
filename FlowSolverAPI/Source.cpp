#include "mymain.h"
#include "input.h"
#include "echo.h"
#include "gridgen.h"

int main()
{
    std::ifstream casefile; // Use ifstream for file input
    std::ofstream outfilep, prjfilep; // Use ofstream for file output

    const float zl = 1.0;

    string datafn, outpfn1, outpfn2, outpfn3, outpfn4;


    float xl, yl, dx, dy;
    int nx, ny, ncase;

    int ib, ie, jb, je, id, jd;
    ib = 1; jb = 1;
    id = IM - 1; jd = JM - 1;

    std::cout << "Enter the no. of cases: ";
    std::cin >> ncase;

    std::cout << "Project cases file: ";
    std::cin >> outpfn3;

    // Open the cases file using ifstream
    casefile.open(outpfn3);
    if (!casefile) {
        std::cerr << "Unable to open input data file: " << outpfn3 << std::endl;
        return 1;
    }

    std::cout << "\nProgram commences to run for " << ncase << " different cases" << std::endl;

    for (int icase = 1; icase <= ncase; icase++) {
        std::cout << "Starting case[" << icase << "].............";
        casefile >> datafn >> outpfn1 >> outpfn2 >> outpfn4;


        // Open the input file using ifstream
        std::ifstream infilep(datafn);
        if (!infilep) {
            std::cerr << "Unable to open input data file: " << datafn << std::endl;
            return 1;
        }

        // Call the input function
        input(infilep, outpfn4, xl, yl, nx, ny);
        infilep.close();

        ie = (ib - 1) + nx;
        je = (jb - 1) + ny;

        // Open the output files using ofstream
        outfilep.open(outpfn1);
        if (!outfilep) {
            std::cerr << "Unable to open output file: " << outpfn1 << std::endl;
            std::cin.ignore();
            return 1;
        }

        prjfilep.open(outpfn2);
        if (!prjfilep) {
            std::cerr << "Unable to open output file: " << outpfn2 << std::endl;
            std::cin.ignore();
            return 1;
        }

        // Call the echo function
        echo(outfilep, outpfn1, ib, ie, jb, je, id, jd, xl, yl, nx, ny);
        // Call the gridgen function
        gridgen(ib, ie, jb, je, nx, ny, xl, yl, zl, dx, dy);

        prjfilep.close();
        outfilep.close();
    }


    cout << xl << yl << endl;

    casefile.close();
    return 0;
}

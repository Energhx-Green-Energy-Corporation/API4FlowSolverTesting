#pragma once
#include "mymain.h"


void gridgen(int ib, int ie, int jb, int je, int nx, int ny, float xl, float yl, float zl,
    float& dx, float& dy) {
    // Instead of creating static multidimensional array in the stack memory we are creating 
    // a dynamic multidimensional array in the heap memory

    double** disw = (double**)calloc(IM, sizeof(double*));
    double** dise = (double**)calloc(IM, sizeof(double*));
    double** dinw = (double**)calloc(IM, sizeof(double*));
    double** dine = (double**)calloc(IM, sizeof(double*));
    double** djsw = (double**)calloc(IM, sizeof(double*));
    double** djse = (double**)calloc(IM, sizeof(double*));
    double** djnw = (double**)calloc(IM, sizeof(double*));
    double** djne = (double**)calloc(IM, sizeof(double*));
    double** answ = (double**)calloc(IM, sizeof(double*));
    double** anse = (double**)calloc(IM, sizeof(double*));
    double** anne = (double**)calloc(IM, sizeof(double*));
    double** annw = (double**)calloc(IM, sizeof(double*));
    double** aesw = (double**)calloc(IM, sizeof(double*));
    double** aese = (double**)calloc(IM, sizeof(double*));
    double** aenw = (double**)calloc(IM, sizeof(double*));
    double** aene = (double**)calloc(IM, sizeof(double*));
    double** vlsw = (double**)calloc(IM, sizeof(double*));
    double** vlse = (double**)calloc(IM, sizeof(double*));
    double** vlnw = (double**)calloc(IM, sizeof(double*));
    double** vlne = (double**)calloc(IM, sizeof(double*));
    double** xsw = (double**)calloc(IM, sizeof(double*));
    double** ysw = (double**)calloc(IM, sizeof(double*));
    double** xse = (double**)calloc(IM, sizeof(double*));
    double** yse = (double**)calloc(IM, sizeof(double*));
    double** xnw = (double**)calloc(IM, sizeof(double*));
    double** ynw = (double**)calloc(IM, sizeof(double*));
    double** xne = (double**)calloc(IM, sizeof(double*));
    double** yne = (double**)calloc(IM, sizeof(double*));



    for (int i = 0; i < JM; i++)
    {
        disw[i] = (double*)calloc(JM, sizeof(double));
        dise[i] = (double*)calloc(JM, sizeof(double));
        dinw[i] = (double*)calloc(JM, sizeof(double));
        djsw[i] = (double*)calloc(JM, sizeof(double));
        djse[i] = (double*)calloc(JM, sizeof(double));
        djnw[i] = (double*)calloc(JM, sizeof(double));
        djne[i] = (double*)calloc(JM, sizeof(double));
        answ[i] = (double*)calloc(JM, sizeof(double));
        anse[i] = (double*)calloc(JM, sizeof(double));
        annw[i] = (double*)calloc(JM, sizeof(double));
        anne[i] = (double*)calloc(JM, sizeof(double));
        aesw[i] = (double*)calloc(JM, sizeof(double));
        aese[i] = (double*)calloc(JM, sizeof(double));
        aenw[i] = (double*)calloc(JM, sizeof(double));
        aene[i] = (double*)calloc(JM, sizeof(double));
        vlsw[i] = (double*)calloc(JM, sizeof(double));
        vlse[i] = (double*)calloc(JM, sizeof(double));
        vlnw[i] = (double*)calloc(JM, sizeof(double));
        vlne[i] = (double*)calloc(JM, sizeof(double));
        xsw[i] = (double*)calloc(JM, sizeof(double));
        ysw[i] = (double*)calloc(JM, sizeof(double));
        xse[i] = (double*)calloc(JM, sizeof(double));
        yse[i] = (double*)calloc(JM, sizeof(double));
        xnw[i] = (double*)calloc(JM, sizeof(double));
        ynw[i] = (double*)calloc(JM, sizeof(double));
        xne[i] = (double*)calloc(JM, sizeof(double));
        yne[i] = (double*)calloc(JM, sizeof(double));
    }


    dx = xl / float(nx);
    dy = yl / float(ny);

    xsw[0][0] = -dx / 2.0;
    ysw[0][0] = -dy / 2.0;
    xse[0][0] = 0.0;
    yse[0][0] = -dy / 2.0;
    xnw[0][0] = -dx / 2.0;
    ynw[0][0] = 0.0;
    xne[0][0] = 0.0;
    yne[0][0] = 0.0;

    for (int j = jb; j <= je + 1; j++) {
        xsw[0][j] = xsw[0][j - 1];
        ysw[0][j] = ysw[0][j - 1] + dy;
        xse[0][j] = xse[0][j - 1];
        yse[0][j] = yse[0][j - 1] + dy;
        xnw[0][j] = xnw[0][j - 1];
        ynw[0][j] = ynw[0][j - 1] + dy;
        xne[0][j] = xne[0][j - 1];
        yne[0][j] = yne[0][j - 1] + dy;
    }

    for (int j = jb - 1; j <= je + 1; j++) {
        for (int i = ib; i <= ie + 1; i++) {
            xsw[i][j] = xsw[i - 1][j] + dx;
            ysw[i][j] = ysw[i - 1][j];
            xse[i][j] = xse[i - 1][j] + dx;
            yse[i][j] = yse[i - 1][j];
            xnw[i][j] = xnw[i - 1][j] + dx;
            ynw[i][j] = ynw[i - 1][j];
            xne[i][j] = xne[i - 1][j] + dx;
        }
    }

    for (int j = jb - 1; j <= je + 1; j++) {
        for (int i = ib - 1; i <= ie + 1; i++) {
            disw[i][j] = 0.5 * dx;
            dise[i][j] = 0.5 * dx;
            dinw[i][j] = 0.5 * dx;
            dine[i][j] = 0.5 * dx;
            djsw[i][j] = 0.5 * dy;
            djse[i][j] = 0.5 * dy;
            djnw[i][j] = 0.5 * dy;
            djne[i][j] = 0.5 * dy;

            answ[i][j] = disw[i][j] * zl;
            anse[i][j] = dise[i][j] * zl;
            annw[i][j] = dinw[i][j] * zl;
            anne[i][j] = dine[i][j] * zl;
            aesw[i][j] = djsw[i][j] * zl;
            aese[i][j] = djse[i][j] * zl;
            aenw[i][j] = djnw[i][j] * zl;
            aene[i][j] = djne[i][j] * zl;

            vlsw[i][j] = disw[i][j] * djsw[i][j] * zl;
            vlse[i][j] = dise[i][j] * djse[i][j] * zl;
            vlnw[i][j] = dinw[i][j] * djnw[i][j] * zl;
            vlne[i][j] = dine[i][j] * djne[i][j] * zl;
        }
    }
}


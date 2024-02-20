
#include <fstream.h>
#include <math.h>
#include <stdio.h>
#include <process.h>
#include <float.h>
#include <string.h>
#include <malloc.h>
#include "main.h"
#include "input.h"
#include "echo.h"
#include "gridgen.h"

main( int argc, char *argv[])

{
	FILE *infilep, *outfilep, *prjfilep, *casefilep;  /* file pointers */
	const float zl=1.0;


	char datafn[FNLEN], outpfn1[FNLEN], outpfn2[FNLEN], outpfn3[FNLEN], outpfn4[FNLEN];

	double disw[IM][JM], dise[IM][JM], dinw[IM][JM], dine[IM][JM],
          djsw[IM][JM], djse[IM][JM], djnw[IM][JM], djne[IM][JM],
          answ[IM][JM], anse[IM][JM], annw[IM][JM], anne[IM][JM],
          aesw[IM][JM], aese[IM][JM], aenw[IM][JM], aene[IM][JM],
          vlsw[IM][JM], vlse[IM][JM], vlnw[IM][JM], vlne[IM][JM],
          xsw[IM][JM], ysw[IM][JM], xse[IM][JM], yse[IM][JM],
          xnw[IM][JM], ynw[IM][JM], xne[IM][JM],  yne[IM][JM];

	float xl, yl, dx, dy;   
	int nx, ny, ncase;

	int ib, ie, jb, je, id, jd, iref, jref, ispec, jspec, imax,jmax;

   ib = 1;    jb = 1; 
   id = IM-1; jd = JM-1; 
  
   
// read in the data 
   char datalabel[50];
   cout<<"Enter the no. of cases:";
   cin>>ncase;

   printf("Project cases file : ");
   scanf("%s",outpfn3);
   if ( ( casefilep = fopen (outpfn3, "r") ) == NULL)
      {   printf("Unable to open input data file: %s\n", outpfn3);
          exit( 1 );
      }  
   cout<<"\nProgram commences to run for "<<ncase<<" different cases"<<endl;

   for(int icase=1; icase<=ncase; icase++)
   {
	   printf("Starting case[%i].............",icase);
	   fscanf(casefilep,"%s %s %s %s",datafn,outpfn1,outpfn2,datalabel);
   	if ( ( infilep = fopen (datafn, "r") ) == NULL)
      {   printf("Unable to open input data file: %s\n", datafn);
          exit( 1 );
      }  
   input( infilep, outpfn4, &xl, &yl, &nx, 
	   &ny);
   fclose(infilep);

   ie = (ib-1) + nx;
   je = (jb-1) + ny;
 
  if ( ( outfilep = fopen (outpfn1, "w") ) == NULL)
      {   printf("Unable to open output file: %s\n", outpfn1);
          cin.ignore();
          exit( 1 );
		  
      }
  if ( ( prjfilep = fopen (outpfn2, "w") ) == NULL)
      {   printf("Unable to open output file: %s\n", outpfn2);
          cin.ignore();
          exit( 1 );
		  
      }
  echo( outfilep, outpfn1, ib, ie, jb, je, id, jd,xl, yl, nx, ny);
  gridgen(ib, ie, jb, je, nx, ny, xl, yl, zl, dx, dy, disw, dise, dinw, dine,
          djsw, djse, djnw, djne, answ, anse, annw, anne, aesw, aese, aenw, aene,
          vlsw, vlse, vlnw, vlne, xsw, ysw, xse, yse, xnw, ynw, xne,  yne);

  fclose(prjfilep);

   fclose(outfilep);
   }
   fclose(casefilep);
  
}



void input ( FILE *infilep, char outpfn[FNLEN], 
			float *xl, float *yl, int *nx, int *ny)
{
  char datalabel[50]; /* holds single comment string to the right of the data */

 

  fscanf( infilep, "%s %s", outpfn, datalabel);
  fscanf( infilep, "%g %s", xl, datalabel);
  fscanf( infilep, "%g %s", yl, datalabel);
  fscanf( infilep, "%i %s", nx, datalabel);
  fscanf( infilep, "%i %s", ny, datalabel);
  
}
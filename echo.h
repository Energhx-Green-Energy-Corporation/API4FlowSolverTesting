
void echo  ( FILE *outfilep, char datafn[FNLEN],int ib, int ie, int jb, int je, int id, int jd, 
             float xl, float yl, int nx, int ny  )
{
  fprintf( outfilep, "Input data was read from: %s\n", datafn);
  fprintf( outfilep, "==== Input Data ======\n\n");
  fprintf( outfilep, "X length = %f [m]\n", xl);
  fprintf( outfilep, "Y length = %f [m]\n", yl);
  fprintf( outfilep, "<<<< Array Parameters >>>>\n");
  fprintf( outfilep, "Number of x nodes = %i\n", nx);
  fprintf( outfilep, "    I begin index = %i\n", ib);
  fprintf( outfilep, "    I end   index = %i\n", ie);
  fprintf( outfilep, "Number of y nodes = %i\n", ny);
  fprintf( outfilep, "    J begin index = %i\n", jb);
  fprintf( outfilep, "    J end   index = %i\n", je);
  fprintf( outfilep, "I array dimension = %i\n", id+1);
  fprintf( outfilep, "J array dimension = %i\n", jd+1);

}


void gridgen(int ib, int ie, int jb, int je, int nx, int ny, float xl, float yl, float zl,
            float &dx, float &dy, double disw[IM][JM], double dise[IM][JM], double dinw[IM][JM], double dine[IM][JM],
          double djsw[IM][JM], double djse[IM][JM], double djnw[IM][JM], double djne[IM][JM],
          double answ[IM][JM], double anse[IM][JM], double annw[IM][JM], double anne[IM][JM],
          double aesw[IM][JM], double aese[IM][JM], double aenw[IM][JM], double aene[IM][JM],
          double vlsw[IM][JM], double vlse[IM][JM], double vlnw[IM][JM], double vlne[IM][JM],
          double xsw[IM][JM], double ysw[IM][JM], double xse[IM][JM], double yse[IM][JM],
          double xnw[IM][JM], double ynw[IM][JM], double xne[IM][JM],  double yne[IM][JM])

{

	 dx=xl/float(nx);
	 dy=yl/float(ny);
//intialise the point arrays at the origin of the indices
	xsw[0][0]= -dx/2.0;
	ysw[0][0]= -dy/2.0;
	xse[0][0]= 0.0;
	yse[0][0]= -dy/2.0;
	xnw[0][0]= -dx/2.0;
	ynw[0][0]= 0.0;
	xne[0][0]= 0.0;
	yne[0][0]= 0.0;
//initialise all the j-point arrays on the boundary
	for(int j=jb; j<=je+1; j++)
	{
		xsw[0][j]=xsw[0][j-1];
		ysw[0][j]=ysw[0][j-1] + dy;
		xse[0][j]=xse[0][j-1];
		yse[0][j]=yse[0][j-1] + dy;
		xnw[0][j]=xnw[0][j-1];
		ynw[0][j]=ynw[0][j-1] + dy;
		xne[0][j]=xne[0][j-1];
		yne[0][j]=yne[0][j-1] + dy;
	}

// filling the point arrays for the domain
	for(int j=jb-1; j<=je+1; j++)
	{
		for(int i=ib; i<=ie+1; i++)
		{
			xsw[i][j]=xsw[i-1][j] + dx;
			ysw[i][j]=ysw[i-1][j];
			xse[i][j]=xse[i-1][j] + dx;
			yse[i][j]=yse[i-1][j];
			xnw[i][j]=xnw[i-1][j] + dx;
			ynw[i][j]=ynw[i-1][j];
			xne[i][j]=xne[i-1][j] + dx;
		}
	}

 // Calculate the other arrays
 for (int j=jb-1; j <= je+1; j++ )
{ 
  for (int i=ib-1; i <= ie+1; i++ ) 
	{
// The length arrays		
		  disw[i][j]=0.5*dx;
		  dise[i][j]=0.5*dx;
		  dinw[i][j]=0.5*dx;
		  dine[i][j]=0.5*dx;
          djsw[i][j]=0.5*dy;
	      djse[i][j]=0.5*dy;
		  djnw[i][j]=0.5*dy;
		  djne[i][j]=0.5*dy;
// The Area arrays
          answ[i][j]=disw[i][j]*zl;
		  anse[i][j]=dise[i][j]*zl;
		  annw[i][j]=dinw[i][j]*zl;
		  anne[i][j]=dine[i][j]*zl;
		  aesw[i][j]=djsw[i][j]*zl;
		  aese[i][j]=djse[i][j]*zl;
		  aenw[i][j]=djnw[i][j]*zl;
		  aene[i][j]=djne[i][j]*zl;
// The Volume arrays
		  vlsw[i][j]=disw[i][j]*djsw[i][j]*zl;
		  vlse[i][j]=dise[i][j]*djse[i][j]*zl;
		  vlnw[i][j]=dinw[i][j]*djnw[i][j]*zl;
		  vlne[i][j]=dine[i][j]*djne[i][j]*zl;
   
      }
  }

}
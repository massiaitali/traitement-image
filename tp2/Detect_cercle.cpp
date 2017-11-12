#include <vector>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cmath>

// Var fixés
#define Seuil_Maximum 255
#define NombreColonnes 100
#define Maximumz 100 
#define NombreLignes 100

using namespace std;
using namespace cv;

//Calc Max Accu
cv::Point3d Max_accu(vector<vector<vector<int> > > array3d) {
	
	cv::Point3d LocValMax;
	int maximum = 0, ValeurAct = 0;
		
	for(int i=0; i<NombreLignes; i++){
		for(int j=0; j<NombreColonnes; j++){
			for(int k=0; k<Maximumz; k++){
				ValeurAct = array3d[i][j][k];
				if(ValeurAct >= maximum){
					LocValMax.y = i;
					LocValMax.z = k;
					LocValMax.x = j;
					maximum = ValeurAct;
				}
			}
		}
	}
	return LocValMax;
}

int main(int argc, char** argv){
	
	// lancement du temps d'execution
	int64 debut = cv::getTickCount();

	int seuil = atoi(argv[1]);
	
	Mat imageOut_x, imageOut_y, abs_imageOut_x, abs_imageOut_y,imageOut, imageOutCopie;
	Mat imageIn = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE );
		
	int echel = 1;
	int prof = CV_8U;
	int delt = 0;

   	GaussianBlur( imageIn, imageIn, Size(3,3), 0, 0, BORDER_DEFAULT );
	//Sobel 
	//Gz en Y
	Sobel( imageIn, imageOut_y, prof, 0, 1, 3, echel, delt, BORDER_DEFAULT );
	convertScaleAbs( imageOut_y, abs_imageOut_y );
	//Gz en X
 	Sobel( imageIn, imageOut_x, prof, 1, 0, 3, echel, delt, BORDER_DEFAULT );
	convertScaleAbs( imageOut_x, abs_imageOut_x );
	// Gz approxi
	addWeighted( abs_imageOut_x, 0.5, abs_imageOut_y, 0.5, 0, imageOut );
	//Seuil gris
	for (int i = 0; i < imageOut.rows; ++i)
	{
		for (int j = 0; j < imageOut.cols; ++j)
		{
			if (imageOut.at<float>(i,j) > seuil)
			{
				imageOut.at<uchar>(i,j) = 255;
			}
			else
				imageOut.at<uchar>(i,j) = 0;
		}
	}
	
	// Ini Accu
	//Creation 
	vector<vector<vector<int> > > Accu; 
	Accu.resize(NombreLignes);
	for (int i = 0; i < NombreLignes; ++i) 
	{
		Accu[i].resize(NombreColonnes);
		for (int j = 0; j < NombreColonnes; ++j)
		{  
			Accu[i][j].resize(Maximumz);
		}
	}
	for(int w=0; w<NombreLignes; w++){
		for(int z=0; z<NombreColonnes; z++){
			for(int r=0; r<Maximumz; r++){
				Accu[w][z][r] = 0;		  
			} 
		}
	}
	cout << "Initialisation de l'accu fin" << std::endl; 
	// parcour pixel detecte si il y a un cercle pour increment l'accu
	for(int i=0; i<NombreLignes; i++){
		for(int j=0; j<NombreColonnes; j++){		
				
			if(imageOut.at<uchar>(i,j)==255){	
				for(int r=0; r<NombreLignes; r++){
					for(int w=0; w<NombreColonnes; w++){
						int z = int(sqrt(pow((i-r),2) + pow((j-w),2)));
						if(z > 0 && z < Maximumz){						
							(Accu[r][w][z])++; // Vote
						}
					}
				}
				
			}
		}
	}
	cout << "Incrément de l'accu fin" << std::endl; 

	// Detection des cases supérieur 
	int ValeurActuelle = 0;
	// Boucle dans l'accu	
	  for(int r=0; r<NombreLignes; r++){
		for(int c=0; c<NombreColonnes; c++){
			for(int z=0; z<Maximumz; z++){
				ValeurActuelle = Accu[r][c][z];
				if(ValeurActuelle>0 && r>0 && c>0 
				&& z>0 
				&& r<NombreLignes-1 
				&& c<NombreColonnes-1 
				&& z<Maximumz-1){
					for(int i=r-1; i<=r+1; i++){
						for(int j=c-1; j<=c+1; j++){
							for(int k=z-1; k<=z+1; k++){			
								if(ValeurActuelle < Accu[i][j][k]){
									Accu[r][c][z] = -1;
								}
							}
						}
					}
				}else{
					Accu[r][c][z] = -1;
				}
			}
		}
	}
	cout << "Fin detection des cases sup" << std::endl; 
	// N le plus grand
	cv::Point3d IndicesMaximum;	
	for(int i=0; i<atoi(argv[4])+3; i++){	
		IndicesMaximum = Max_accu(Accu);		
		Accu[IndicesMaximum.x][IndicesMaximum.y][IndicesMaximum.z]=-1; 
		circle( imageOut, Point(IndicesMaximum.x,IndicesMaximum.y), 1, Scalar( 255, 255, 255 ), 2, 8, 0);
		circle( imageOut, Point(IndicesMaximum.x,IndicesMaximum.y), IndicesMaximum.z, Scalar( 255, 255, 255 ), 2, 8, 0);	
	}
	imwrite(argv[3], imageOut);

	//Temps execution end
	int64 fin = cv::getTickCount();
	double sec = (fin-debut)/cv::getTickFrequency();
	cout << "Temps exe =" << sec << " s" << std::endl;

	return 0;
}
#include <vector>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cmath>

// Var fixés
#define Seuil_Maximum 255
#define NombreColonnes 100
#define MaximumRad 100 
#define NombreLignes 100

using namespace std;
using namespace cv;

//Calc Max Accu
cv::Point3d Max_accu(vector<vector<vector<int> > > array3d) {
	
	cv::Point3d LocValMax;
	int maximum = 0, ValeurAct = 0;
		
	for(int i=0; i<NombreLignes; i++){
		for(int j=0; j<NombreColonnes; j++){
			for(int k=0; k<MaximumRad; k++){
				ValeurAct = array3d[i][j][k];
				if(ValeurAct >= maximum){
					LocValMax.x = j;
					LocValMax.y = i;
					LocValMax.z = k;
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
	
	Mat imageOut, imageOutCopie;
	Mat abs_imageOut_x, abs_imageOut_y;
	Mat imageOut_x, imageOut_y;
	Mat imageIn = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE );
		
	int echel = 1;
	int prof = CV_8U;
	int delt = 0;

   	GaussianBlur( imageIn, imageIn, Size(3,3), 0, 0, BORDER_DEFAULT );
	//Sobel 
	//Grad en Y
	Sobel( imageIn, imageOut_y, prof, 0, 1, 3, echel, delt, BORDER_DEFAULT );
	convertScaleAbs( imageOut_y, abs_imageOut_y );
	//Grad en X
 	Sobel( imageIn, imageOut_x, prof, 1, 0, 3, echel, delt, BORDER_DEFAULT );
	convertScaleAbs( imageOut_x, abs_imageOut_x );
	// Grad approxi
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
			Accu[i][j].resize(MaximumRad);
		}
	}
	for(int r=0; r<NombreLignes; r++){
		for(int c=0; c<NombreColonnes; c++){
			for(int rad=0; rad<MaximumRad; rad++){
				Accu[r][c][rad] = 0;		  
			} 
		}
	}
	cout << "Initialisation de l'accu fin" << std::endl; 
	// parcour pixel detecte si il y a un cercle pour increment l'accu
	for(int x=0; x<NombreLignes; x++){
		for(int y=0; y<NombreColonnes; y++){		
			
			//Si c'est un pixel de contour	
			if(imageOut.at<uchar>(x,y)==255){
				
				//Pour toutes les lignes et colonnes possibles		
				for(int r=0; r<NombreLignes; r++){
					for(int c=0; c<NombreColonnes; c++){
						//Calcul du rayon
						int rad = int(sqrt(pow((x-r),2) + pow((y-c),2)));
						if(rad > 0 && rad < MaximumRad){						
							(Accu[r][c][rad])++; //Si on trouve un cercle potentiel on vote pour ce cercle
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
			for(int rad=0; rad<MaximumRad; rad++){
				ValeurActuelle = Accu[r][c][rad];
				if(ValeurActuelle>0 && r>0 && c>0 && rad>0 && r<NombreLignes-1 && c<NombreColonnes-1 && rad<MaximumRad-1){
					for(int i=r-1; i<=r+1; i++){
						for(int j=c-1; j<=c+1; j++){
							for(int k=rad-1; k<=rad+1; k++){			
								if(ValeurActuelle < Accu[i][j][k]){
									Accu[r][c][rad] = -1;
								}
							}
						}
					}
				}else{
					Accu[r][c][rad] = -1;
				}
			}
		}
	}
	cout << "Fin detection des cases sup" << std::endl; 
	// N le plus grand
	cv::Point3d IndicesMaximum;	
	for(int i=0; i<atoi(argv[4])+3; i++){	
		IndicesMaximum = Max_accu(Accu);		
		Accu[IndicesMaximum.x][IndicesMaximum.y][IndicesMaximum.z]=-1; //Il a deja ete reconnu on le met a -1	
		//Dessiner le cercle
		circle( imageOut, Point(IndicesMaximum.x,IndicesMaximum.y), 1, Scalar( 255, 255, 255 ), 2, 8, 0);
		//Dessiner son centre
		circle( imageOut, Point(IndicesMaximum.x,IndicesMaximum.y), IndicesMaximum.z, Scalar( 255, 255, 255 ), 2, 8, 0);	
	}
	imwrite(argv[3], imageOut);

	//Temps execution end
	int64 fin = cv::getTickCount();
	double sec = (fin-debut)/cv::getTickFrequency();
	cout << "Temps exe =" << sec << " s" << std::endl;

	return 0;
}





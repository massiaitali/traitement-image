#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv){


	Mat imageIn = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE ); // Entrer de l'image et sauvegarde dans une matrice
	Mat imageOut = Mat(), imageGradX , imageGradY , imageGradX_abs, imageGradY_abs; // Initialisation de la matrice de sortie
	
	if(! imageIn.data ) // Check for invalid input
  	{
		cout <<  "Could not open or find the image" << endl ;
		return -1;
  	}
  	// X
  	Sobel(imageIn, imageGradX, CV_8U, 1, 0, 3, 1, 0, BORDER_DEFAULT);
  	convertScaleAbs( imageGradX, imageGradX_abs );
  	//Y
  	Sobel(imageIn, imageGradY, CV_8U, 0, 1, 3, 1, 0, BORDER_DEFAULT);
  	convertScaleAbs( imageGradY, imageGradY_abs );
    //Gradient
  	addWeighted( imageGradX_abs, 0.5, imageGradY_abs, 0.5, 0, imageOut );

    threshold(imageOut, imageOut, 50, 255, THRESH_BINARY_INV); // Application du seuil sur la matrice

	imwrite(argv[2], imageOut); // Ecriture de l'image avec le chemin fourni 


	return 0;
}


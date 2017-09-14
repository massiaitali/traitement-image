#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv){


	Mat imageIn = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE ); // Entrer de l'image et sauvegarde dans une matrice
	Mat imageOut = Mat(); // Initialisation de la matrice de sortie
	
	if(! imageIn.data ) // Check for invalid input
  	{
		cout <<  "Could not open or find the image" << std::endl ;
		return -1;
  	}


  	Sobel(imageIn, imageOut, CV_8U, 1, 1, 1, 1, 0, BORDER_DEFAULT);

	imwrite(argv[2], imageOut); // Ecriture de l'image avec le chemin fourni 

	return 0;
}


#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv){


	Mat imageIn = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE ); // Entrer de l'image et sauvegarde dans une matrice
	Mat imageOut = Mat(); // Initialisation de la matrice de sortie
	
	if(! imageIn.data ) // Check for invalid input
  {
      cout <<  "Could not open or find the image" << std::endl ;
      return -1;
  }

 	double min = atoi(argv[1]); // Definition du seuil à partir de la valeur entree en arg
  if( min >= 0 && min <= 255) // Verification du seuil (il doit etre compris entre 0 et 255)
  {
   	double max = 255;

   	threshold(imageIn, imageOut, min, max, THRESH_BINARY_INV); // Application du seuil sur la matrice
     
    imwrite(argv[3], imageOut); // Ecriture de l'image avec le chemin fourni 
  }
	else // Message d'erreur pour le seuil 
  {
    cout << "La valeur de seuil doit etre comprise entre 0 et 255" << std::endl;
  }

	return 0;
}


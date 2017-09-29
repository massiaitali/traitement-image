#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv){


	Mat imageInVT = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE ); // Entrer de l'image et sauvegarde dans une matrice
	Mat imageInBin = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE ); // Entrer de l'image et sauvegarde dans une matrice
	
	if(! imageInVT.data | ! imageInBin.data ) // Check for invalid input
  	{
		cout <<  "Could not open or find the image" << endl ;
		return -1;
  	}
	int TP = 0, FP = 0, FN = 0; // Initialisation des variables de calculs
  for (int i = 0; i < imageInBin.rows ; ++i)
  {
  	for (int j = 0; j < imageInBin.cols ; ++j)
  	{
      // Incrémentation des variables de calcul
  		if ((int)imageInVT.at<uchar>(i, j) > 127 && (int)imageInBin.at<uchar>(i, j) > 127)
  		{
  			TP++;
  		}
  		else if((int)imageInVT.at<uchar>(i, j) <= 127 && (int)imageInBin.at<uchar>(i, j) > 127){
  			FN++;
  		}
  		else if((int)imageInVT.at<uchar>(i, j) > 127 && (int)imageInBin.at<uchar>(i, j) <= 127){
  			FP++;
  		}

  		/* TEST LECTURE DES PIXELS */
  		
  		// cout << "Image verite terrain pixel( " <<
  		// i << ", " << j << ") = " <<
  		// (int)imageInVT.at<uchar>(i, j) << 
  		// endl;
  		// cout << "Image resultat bin pixel( " <<
  		// i << ", " << j << ") = " <<
  		// (int)imageInBin.at<uchar>(i, j) << 
  		// endl;
  		
  	}
  }
  // Calcul de p et r
  // cout << "TP = " << TP << " FP = " << FP << " FN = " << FN << endl;
  double p = (double)TP / (TP + FP);  		
	double r = (double)TP / (TP + FN);
	
  cout << p << endl;
  cout << r << endl;
	

	return 0;
}


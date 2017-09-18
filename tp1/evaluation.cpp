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
		cout <<  "Could not open or find the image" << std::endl ;
		return -1;
  	}
	int TP = 0, FP = 0, FN = 0;
  for (int i = 0; i < imageInBin.rows ; ++i)
  {
  	for (int j = 0; j < imageInBin.cols ; ++j)
  	{
  		if ((int)imageInVT.at<uchar>(i, j) > 125 && (int)imageInBin.at<uchar>(i, j) > 125)
  		{
  			TP++;
  		}
  		else if((int)imageInVT.at<uchar>(i, j) > 125 && (int)imageInBin.at<uchar>(i, j) <= 125){
  			FN++;
  		}
  		else if((int)imageInVT.at<uchar>(i, j) <= 125 && (int)imageInBin.at<uchar>(i, j) > 125){
  			FP++;
  		}

  		/* TEST LECTURE DES PIXELS */
  		
  		// cout << "Image verite terrain pixel( " <<
  		// i << ", " << j << ") = " <<
  		// (int)imageInVT.at<uchar>(i, j) << 
  		// std::endl;
  		// cout << "Image resultat bin pixel( " <<
  		// i << ", " << j << ") = " <<
  		// (int)imageInBin.at<uchar>(i, j) << 
  		// std::endl;
  		
  	}
  }
  // cout << "TP = " << TP << " FP = " << FP << " FN = " << FN << std::endl;
  double p = (double)TP / (TP + FP);  		
	double r = (double)TP / (TP + FN);
	
  cout << 
	"(p,r) = (" <<
	p << 
	", " << 
	r << 
	")" <<
	std::endl;

	return 0;
}


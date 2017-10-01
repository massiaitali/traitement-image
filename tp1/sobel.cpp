#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv){


  Mat imageIn = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE ); // Entrer de l'image et sauvegarde dans une matrice
  Mat imageOut = imageIn.clone(); // Initialisation de la matrice de sortie

  Mat imageMagnitude = Mat(imageIn.rows,imageIn.cols, CV_32F, cvScalar(0.));
  Mat imageGradX = Mat(imageIn.rows,imageIn.cols, CV_32F, cvScalar(0.));
  Mat imageGradY = Mat(imageIn.rows,imageIn.cols, CV_32F, cvScalar(0.));

	if(! imageIn.data ) // Check for invalid input
  	{
		cout <<  "Could not open or find the image" << endl ;
		return -1;
  	}
  	// X
  	Sobel(imageIn, imageGradX, CV_32F, 1, 0, 3, 1, 0, BORDER_DEFAULT);
  	//Y
  	Sobel(imageIn, imageGradY, CV_32F, 0, 1, 3, 1, 0, BORDER_DEFAULT);

  //Gradient
  float max = 0.;
  for (int i = 0; i < imageMagnitude.rows; ++i)
   {
    for (int j = 0; j < imageMagnitude.cols; ++j)
    {
      imageMagnitude.at<float>(i,j) = sqrt(pow(imageGradX.at<float>(i, j),2) + pow(imageGradY.at<float>(i, j), 2) );
      if (imageMagnitude.at<float>(i,j) > max)
      {
        max = imageMagnitude.at<float>(i,j);
      }
    }
  }

  //Seuil gris
  for (int i = 0; i < imageMagnitude.rows; ++i)
     {
      for (int j = 0; j < imageMagnitude.cols; ++j)
      {
        if (imageMagnitude.at<float>(i,j) > (max*2)/4)
        {
          imageOut.at<uchar>(i,j) = 255;
        }
        else
          imageOut.at<uchar>(i,j) = 0;
      }
    }

	imwrite(argv[2], imageOut); // Ecriture de l'image avec le chemin fourni 


	return 0;
}


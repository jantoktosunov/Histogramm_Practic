#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;
int main() {
    Mat gray=imread("/home/tokjan/ClionProjects/HIstTest/lena.jpg",0);
    namedWindow( "Gray", 1 );
    imshow( "Gray", gray );

    // Инициализация параметров
    int histSize = 256;
    float range[] = { 0, 255 };
    const float *ranges[] = { range };

    // Гистограмма
    MatND hist;
    calcHist( &gray, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false );

    // Показать подсчитанную гистограмму
    double total;
    total = gray.rows * gray.cols;
    for( int h = 0; h < histSize; h++ )
    {
        float binVal = hist.at<float>(h);
        cout<<" "<<binVal;
    }
    // График
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );

    Mat histImage( hist_h, hist_w, CV_8UC1, Scalar( 0,0,0) );
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

    for( int i = 1; i < histSize; i++ )
    {
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ) ,
              Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
              Scalar( 255, 0, 0), 2, 8, 0  );
    }
    for(int i =0; i < gray.rows; i++){
        for(int k = 0; k <gray.cols; k ++){

            if(gray.at<uchar>(i,k)<=25){
                gray.at<uchar>(i,k)=(gray.at<uchar>(i,k))*0.45;
            }


        }

    }


    namedWindow( "Result", 1 );
    imshow( "Result", histImage );
    waitKey(0);
    return 0;

}

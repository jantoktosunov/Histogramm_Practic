#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;
int main() {
    Mat gray=imread("/home/muhila/ClionProjects/HIstTest/lena.jpg",0);
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
    waitKey(0);
    return 0;
    //commit
}

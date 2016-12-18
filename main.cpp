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
    waitKey(0);
    return 0;
}

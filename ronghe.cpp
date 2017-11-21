#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img, img_tmp;
Mat logo;
Mat img_roi, out_img;

void on_track_bar(int bar_value, void *)
{
    double alpha, beta;

    cout << bar_value << endl;

    beta = (double)bar_value/100;
    alpha = 1 - beta;

//    cout << "a:" << alpha << "b:" << beta << endl;
    
    img_tmp = img.clone();

    img_roi = img_tmp(Rect(380, 50, logo.cols, logo.rows));
    addWeighted(img_roi, alpha, logo, beta, 0, img_roi);

    imshow("show", img_tmp);
}

int main(int argc, char ** argv)
{
    int init_value = 80;

    img = imread("./data/test.jpg");
    logo = imread("./data/hel.jpeg");
    
    namedWindow("show", WINDOW_NORMAL);

    createTrackbar("bar", "show", &init_value, 100, on_track_bar);

    on_track_bar(init_value, 0);

    waitKey(-1);

    return 0;
}


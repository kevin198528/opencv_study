#include <opencv2/opencv.hpp>

#define test_face

#ifdef test_face
#include <opencv2/objdetect/objdetect.hpp>
#endif

using namespace std;
using namespace cv; 

int main(int argc, char ** argv)
{
    Mat read_img, write_img;
    vector<int> c_p;

    read_img = imread("./data/index.jpeg"); 

    resize(read_img, write_img, Size(read_img.cols*0.1, read_img.rows*0.1), 0, 0, INTER_LINEAR);
//    c_p.push_back(CV_IMWRITE_JPEG_QUALITY);
//    c_p.push_back(50);

    imwrite("./data/hel.jpeg", write_img, c_p); 

    return 0;
}

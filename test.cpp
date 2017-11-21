#include <opencv2/opencv.hpp>

#define test_face

#ifdef test_face
#include <opencv2/objdetect/objdetect.hpp>
#endif

using namespace std;
using namespace cv;


int main(int argc, char ** argv)
{
#ifdef test_img
    Mat srcImage = imread("test.jpg");
    Mat dstImage, edge, grayImage;

    namedWindow("test", WINDOW_NORMAL);
    namedWindow("filter", WINDOW_NORMAL);
    imshow("test", srcImage);

//    Mat filter = getStructuringElement(MORPH_RECT, Size(5, 5));
//    erode(srcImage, dstImage, filter);
//    blur(srcImage, dstImage, Size(10, 10));

    dstImage.create(srcImage.size(), srcImage.type());

    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

    blur(grayImage, edge, Size(15, 15));

    Canny(edge, edge, 3, 9, 3);

    imshow("filter", edge);

    waitKey(-1); 

#endif

#ifdef test_video    
    VideoCapture cap(argv[1]);
    Mat frame, edge;    

    if (argc < 2)
    {
        cout << "input argument must greater than 2" << endl;
        return -1;
    }

    if (cap.isOpened())
        cout << "open successful"<< endl;
    else 
        cout << "open fail" << endl;

    namedWindow("read_v", WINDOW_NORMAL); 

    while(1)
    {
        cap >> frame;
        cvtColor(frame, edge, COLOR_BGR2GRAY);
        blur(edge, edge, Size(15, 15));
        Canny(edge, edge, 3, 9, 3);
        imshow("read_v", edge);
        waitKey(30);
    }
#endif

#ifdef test_face
    CascadeClassifier faceCascade;

    VideoCapture cap;    
    //cap.open(0);   //打开摄像头  
    cap.open(argv[1]);   //打开视频  
    Mat img, imgGray;  
    vector<Rect> faces;  
    int c = 0;  

    if (argc < 2)
    {
        cout << "input argument must greater than 2" << endl;
        return -1;
    }

    cout << CV_VERSION << endl;
    
    namedWindow("girl", WINDOW_NORMAL);

    faceCascade.load("./data/haarcascade_frontalface_alt2.xml");   //加载分类器，注意文件路径  
  
  
    if(!cap.isOpened())  
    {  
      return 1;  
    }  
  
    while(c!=27)  
    {  
        cap>>img;  
       if(img.channels() ==3)  
       {  
          cvtColor(img, imgGray, CV_RGB2GRAY);  
       }  
       else  
       {  
          imgGray = img;  
       }  
  
       faceCascade.detectMultiScale(imgGray, faces, 1.2, 6, 0, Size(0, 0));   //检测人脸  
  
       if(faces.size()>0)  
       {  
          for(int i =0; i<faces.size(); i++)  
          {  
              rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),   
                              Scalar(0, 255, 0), 1, 8);    //框出人脸位置  
          }  
       }  
         
       imshow("girl", img);  
       c = waitKey(1);  
    }  
 
    return 0;  
#endif
}


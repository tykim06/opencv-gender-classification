#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

string g_listname_t[]= 
{
	"Male",
	"Female"
};

int main(int argc, const char *argv[]) {
    string fn_haar = "/usr/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml";
    int deviceId = 2;

    int im_width = 200;
    int im_height = 200;

    Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
    model->load("gender_at.yml");
    CascadeClassifier haar_cascade;
    haar_cascade.load(fn_haar);

    VideoCapture cap(deviceId);
    if(!cap.isOpened()) {
        cerr << "Capture Device ID " << deviceId << " cannot be opened." << endl;
        return -1;
    }

    Mat frame;
    Mat original;
    Mat gray;
    vector< Rect_<int> > faces;
    int i=0, prediction;

    for(;;) {
        cout << "Detecting Gender...";
        cap >> frame;
        original = frame.clone();
        cvtColor(original, gray, CV_BGR2GRAY);

        haar_cascade.detectMultiScale(gray, faces, 1.2, 2,
				0
				| CV_HAAR_DO_ROUGH_SEARCH
				| CV_HAAR_SCALE_IMAGE
				| CV_HAAR_FIND_BIGGEST_OBJECT
				, Size(100, 100)
				, Size(300, 300)
				);
	if(faces.size() > 0) {
            Rect face_i = faces[i];
            Mat face = gray(face_i);
            Mat face_resized;
            cv::resize(face, face_resized, Size(im_width, im_height), 1.0, 1.0, INTER_CUBIC);
            prediction = model->predict(face_resized);

	    if (prediction == 0 || prediction == 1)
		cout << g_listname_t[prediction];
	    else
		cout << "Unknown";

	}
        cout << endl;
	faces.empty();
     }
    return 0;
}

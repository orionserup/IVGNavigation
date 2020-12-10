
#include "test.hpp"

using namespace std;
using namespace cv;
using namespace igv;

Test::Test(const char* logfile): logfile(logfile){}
Test::Test(){}

Test::~Test(){

    logfile.close();

}

bool Test::CameraTest(){

    bool Passed = true;

    logfile << "Creating USB Camera Object \n";
    HardwareInterface::Camera cam1(USB);

    logfile << "Taking a Picture \n";
    cam1.Capture();

    logfile << "Retrieving the Image \n";
    Mat testimage = cam1.GetImage();

    logfile <<  "Image Specs: \n" <<
                "=========================" << 
                "Is Empty:       " << testimage.empty() << endl << 
                "Dimensionality: " << testimage.dims << endl <<
                "Pixel Format:   " << testimage.depth() << endl <<
                "Size:           " << testimage.size << endl << endl;


    if(testimage.empty() || !testimage.size) Passed = false;
    else Passed = true;

    logfile << "Creating Internal Camera Object \n";
    HardwareInterface::Camera cam2(INT);

    logfile << "Taking a Picture: \n";
    cam2.Capture();

    logfile << "Retrieving the Image \n";
    logfile <<  "Image Specs: \n" <<
                "=========================" << 
                "Is Empty:       " << testimage.empty() << endl << 
                "Dimensionality: " << testimage.dims << endl <<
                "Pixel Format:   " << testimage.depth() << endl <<
                "Size:           " << testimage.size << endl << endl << endl;


    if(testimage.empty() || !testimage.size) Passed = false;
    else Passed = true;

    return Passed;
}

bool Test::LaneDetectionTest(){

    bool passed = true;

    logfile << "Opening Image: 'test.png' \n"; 
	
	Mat testmat = imread("test.png", IMREAD_GRAYSCALE);  // load the sample image to test and compare

    logfile << "Retrieving the Image \n";
    logfile <<  "Image Specs: \n" <<
                "=========================" << 
                "Is Empty:       " << testmat.empty() << endl << 
                "Dimensionality: " << testmat.dims << endl <<
                "Pixel Format:   " << testmat.depth() << endl <<
                "Size:           " << testmat.size << endl << endl;

    if(!testmat.size || !testmat.empty()) passed = false;

    logfile << "Creating Empty Lane Array: Lanes Full of Zeros \n";

	array<Lane, 2> testlanes = { Lane({0, 0}), Lane({0, 0})}; 

    logfile << "Detecting Lanes: \n";
	// uint32_t numlanes = DetectLanes(testlanes, testmat);

    return passed;

}


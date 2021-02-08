#pragma once

#include "main.hpp"

#include "Camera.hpp"

using namespace std;
using namespace cv;

namespace igv {

struct Object {

  double distance;
  Direction angle;
  string classification;

  friend ostream& operator<<(ostream& os, Object& obj);

};
class ObjDetector{

public:

  uint32_t DetectObjects(Mat& Image);
  static uint32_t DetectObjects(list<Object>& objs, Mat& Image);
  bool isBusy() { return this->busy; }
  list<Object>& GetObjects() { return objects; }

private:

  bool busy;
  list<Object> objects;

};

}

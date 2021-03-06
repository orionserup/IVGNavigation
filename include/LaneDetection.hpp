/**
 * @file LaneDetection.hpp
 * @brief Contains Prototypes of Lane Detection Functionality
 * @author Orion Serup
 * @bug None
 */

#pragma once

#include "main.hpp"
#include "Camera.hpp"

/**
* @brief namespace for this project
*/
namespace igv{

/**
* @brief Structure to hold the Data for a Lane
*/
struct Lane{

  double slope;
  int intercept;

};

/**
 * @brief Prints a Lane to an Output Stream
 * @param os Output Stream Object
 * @param lane Lane to Print
 * @returns std::ostream&
 */
std::ostream& operator<<(std::ostream& os, Lane& lane);

/**
* @brief Class that Detects Lanes From Images
*/
class LaneDetector{

public:

  /**
  * @brief Detects Lanes and Fills array with detected lanes
  * @param LaneArray Array of Lanes to be filled
  * @param image Photo To Detect Lanes From
  * @returns Number of Lanes Detected 
  */
  static uint32_t DetectLanes(std::array<Lane, 4>& LaneArray, cv::Mat& image);
  
  /**
  * @brief Detects Lanes and Fills the Private Data with the Lane Data
  * @param Image Photo To Detect Lanes From
  * @returns void
  */
  void DetectLanes(cv::Mat& Image);

  /**
  * @brief Return the Number of Lanes Detected
  * @returns uint32_t
  */
  uint32_t GetNumLanes() { return numlanes; }
  
  /**
  * @brief Return if the Lane Detector is Busy
  * @returns bool
  */
  bool isBusy(){ return busy; }
  
  /**
  * @brief Return the Array full of detected Lanes
  * @returns std::array<Lane, 4>&
  */
  std::array<Lane, 4>& GetLanes() { return lanes; }

private:

  bool busy;
  std::array<Lane, 4> lanes;
  uint32_t numlanes;

};
  
}



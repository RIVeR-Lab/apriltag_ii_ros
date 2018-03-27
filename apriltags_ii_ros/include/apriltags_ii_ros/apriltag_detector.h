#ifndef APRILTAG_DETECTOR_H
#define APRILTAG_DETECTOR_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <Eigen/Dense>
#include <apriltags_ii/apriltag.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/PoseStamped.h>


namespace apriltags_ii_ros{


class AprilTagDescription{
 public:
  AprilTagDescription(int id, double size, std::string &frame_name): id_(id), size_(size), frame_name_(frame_name)
  { }
  double size(){return size_;}
  int id(){return id_;} 
  std::string& frame_name(){return frame_name_;} 
 private:
  int id_;
  double size_;
  std::string frame_name_;
};


class AprilTagDetector{
 public:
  AprilTagDetector(ros::NodeHandle &nh, ros::NodeHandle &pnh);
  ~AprilTagDetector();
 private:
  void imageCb(const sensor_msgs::ImageConstPtr &msg, const sensor_msgs::CameraInfoConstPtr &cam_info);
  std::map<int, AprilTagDescription> parse_tag_descriptions(XmlRpc::XmlRpcValue &april_tag_descriptions);

 private:
  std::map<int, AprilTagDescription> descriptions_;
  std::string sensor_frame_id_;
  image_transport::ImageTransport it_;
  image_transport::CameraSubscriber image_sub_;
  image_transport::Publisher image_pub_;
  ros::Publisher detections_pub_;
  ros::Publisher pose_pub_;
  tf::TransformBroadcaster tf_pub_;

  // TODO: Needs attention, no more valid if using standard package
  // OLD: boost::shared_ptr<AprilTags::TagDetector> tag_detector_;
  std::string tag_family_name_;
  apriltag_family_t* tag_family_;
  apriltag_detector_t* tag_detector_;
  bool projected_optics_;

  

  Eigen::Matrix4d getRelativeTransform(double tag_size, double fx, double fy, double px, double py, double p[4][2]) const;
};



}


#endif

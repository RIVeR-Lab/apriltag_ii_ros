# apriltags_ii_ros
This package has been originally built upon [`apriltags_ros`](https://github.com/RIVeR-Lab/apriltags_ros) package. I modified the ROS wrapper to work with the latest [`apriltags` library ](https://april.eecs.umich.edu/software/apriltag.html) (which is 2016-12-01 at this time) in its original language (C). See the paper: [AprilTag 2: Efficient and robust fiducial detection](https://april.eecs.umich.edu/papers/details.php?name=wang2016iros), IROS 2016.

Some of functions of ROS wrapper are borrowed from [AprilTags C++ Library](http://people.csail.mit.edu/kaess/apriltags/).

## How to use
Clone this repository into your catkin workspace. Then compile using the following:

```bash
catkin_make -DCMAKE_BUILD_TYPE=Release
```

You need to calibrate your camera before use. A monocular camera would be sufficient for using this package.

## ROS
The package was tested on Ubuntu 16.04 with ROS Kinetic as well as Ubuntu 14.04 with ROS Indigo.


## Issues
Use the issue page of the project.

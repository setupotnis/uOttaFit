/*

Replace 25 joints by names (refer to kinect vs skeleton names vs nuitrack skeleton names)
Standing
Sitting
Lying down 

(10 mins session)
or break down into multiple sessions moving backwards and forwards



3 mins 
*/

#include <nuitrack/Nuitrack.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#ifndef PI
#define PI 3.14159265358979323846
#endif
#include <math.h>
#include <nuitrack/types/Vector3.h>
using namespace tdv::nuitrack;

void showHelpInfo()
{
    std::cout << "Usage: nuitrack_console_sample [path/to/nuitrack.config]" << std::endl;
}

// Callback for the skeleton data update event
void onSkeletonUpdate(SkeletonData::Ptr skeletonData)
{
	int user_height = 0; //Initialized height value, used for height of skeleton calculation and fall distance
    if (!skeletonData)
    {
        // No skeleton data
        std::cout << "No skeleton data" << std::endl;
        return;
    }
    auto skeletons = skeletonData->getSkeletons();
    if (skeletons.empty())
    {
        // No skeletons
        return;
    }


	
	std::ofstream dataFile;

	// The real_time_joints_data.txt will contain all the features to be fed into the Python classifier

	dataFile.open("C:\\Users\\James\\Documents\\uOttahack3\\Fall Detection\\NuitrackFallDetection\\FallDetection\\nuitrack_fall_detection\\data\\real_time_joints_data.txt", std::ofstream::out | std::ofstream::app);
	if (!dataFile) { //create file if not exists
		dataFile.open("C:\\Users\\James\\Documents\\uOttahack3\\Fall Detection\\NuitrackFallDetection\\FallDetection\\nuitrack_fall_detection\\data\\real_time_joints_data.txt", std::ofstream::out | std::ofstream::trunc);
	}


        for (auto skeleton: skeletons)

    {
        //drawSkeleton(skeleton.joints);
        auto joints = skeleton.joints;


		std::cout << std::fixed << std::setprecision(3);

		//std::cout << "Joint left knee confidence: " << joints[JOINT_LEFT_KNEE].confidence << std::endl;

	

				tdv::nuitrack::Vector3 &spineBasePos = joints[JOINT_WAIST].real;
				tdv::nuitrack::Vector3 &spineMidPos = joints[JOINT_TORSO].real;
				tdv::nuitrack::Vector3 &neckPos = joints[JOINT_NECK].real;
				tdv::nuitrack::Vector3 &headPos = joints[JOINT_HEAD].real;
				tdv::nuitrack::Vector3 &shoulderLeftPos = joints[JOINT_LEFT_SHOULDER].real;

				tdv::nuitrack::Vector3 &elbowLeftPos = joints[JOINT_LEFT_ELBOW].real;
				tdv::nuitrack::Vector3 &wristLeftPos = joints[JOINT_LEFT_WRIST].real;
				tdv::nuitrack::Vector3 &handLeftPos = joints[JOINT_LEFT_HAND].real;
				tdv::nuitrack::Vector3 &shoulderRightPos = joints[JOINT_RIGHT_SHOULDER].real;
				tdv::nuitrack::Vector3 &elbowRightPos = joints[JOINT_RIGHT_ELBOW].real;

				tdv::nuitrack::Vector3 &wristRightPos = joints[JOINT_RIGHT_WRIST].real;
				tdv::nuitrack::Vector3 &handRightPos = joints[JOINT_RIGHT_HAND].real;
				tdv::nuitrack::Vector3 &hipLeftPos = joints[JOINT_LEFT_HIP].real;
				tdv::nuitrack::Vector3 &kneeLeftPos = joints[JOINT_LEFT_KNEE].real;
				tdv::nuitrack::Vector3 &ankleLeftPos = joints[JOINT_LEFT_ANKLE].real;

				tdv::nuitrack::Vector3 &footLeftPos = joints[JOINT_LEFT_FOOT].real; //NOT USED IN CURRENT VERSION
				tdv::nuitrack::Vector3 &hipRightPos = joints[JOINT_RIGHT_HIP].real;
				tdv::nuitrack::Vector3 &kneeRightPos = joints[JOINT_RIGHT_KNEE].real;
				tdv::nuitrack::Vector3 &ankleRightPos = joints[JOINT_RIGHT_ANKLE].real;

				tdv::nuitrack::Vector3 &footRightPos = joints[JOINT_RIGHT_FOOT].real; //Foot not used, ankle replaced for foot

				tdv::nuitrack::Vector3 &spineShoulderPos = joints[JOINT_LEFT_COLLAR].real; //LEFT COLLAR SAME AS RIGHT
				tdv::nuitrack::Vector3 &handTipLeftPos = joints[JOINT_LEFT_HAND].real;
				tdv::nuitrack::Vector3 &thumbLeftPos = joints[JOINT_LEFT_HAND].real;//DONT HAVE LEFT THUMB SO SAME AS LEFT HAND
				tdv::nuitrack::Vector3 &handTipRightPos = joints[JOINT_RIGHT_HAND].real;
				tdv::nuitrack::Vector3 &thumbRightPos = joints[JOINT_RIGHT_HAND].real; // DONT HAVE RIGHT THUMB SO SAME AS RIGHT HAND


				//distances between joints
				float a = sqrt(pow(hipLeftPos.x - kneeLeftPos.x, 2) + pow(hipLeftPos.y - kneeLeftPos.y, 2) + pow(hipLeftPos.z - kneeLeftPos.z, 2));
				float b = sqrt(pow(spineBasePos.x - hipLeftPos.x, 2) + pow(spineBasePos.y - hipLeftPos.y, 2) + pow(spineBasePos.z - hipLeftPos.z, 2));
				float c = sqrt(pow(spineBasePos.x - kneeLeftPos.x, 2) + pow(spineBasePos.y - kneeLeftPos.y, 2) + pow(spineBasePos.z - kneeLeftPos.z, 2));

				float d = sqrt(pow(hipRightPos.x - kneeRightPos.x, 2) + pow(hipRightPos.y - kneeRightPos.y, 2) + pow(hipRightPos.z - kneeRightPos.z, 2));
				float e = sqrt(pow(spineBasePos.x - hipRightPos.x, 2) + pow(spineBasePos.y - hipRightPos.y, 2) + pow(spineBasePos.z - hipRightPos.z, 2));
				float f = sqrt(pow(spineBasePos.x - kneeRightPos.x, 2) + pow(spineBasePos.y - kneeRightPos.y, 2) + pow(spineBasePos.z - kneeRightPos.z, 2));

				float g = sqrt(pow(hipLeftPos.x - ankleLeftPos.x, 2) + pow(hipLeftPos.y - ankleLeftPos.y, 2) + pow(hipLeftPos.z - ankleLeftPos.z, 2));
				float h = sqrt(pow(kneeLeftPos.x - ankleLeftPos.x, 2) + pow(kneeLeftPos.y - ankleLeftPos.y, 2) + pow(kneeLeftPos.z - ankleLeftPos.z, 2));

				float i = sqrt(pow(hipRightPos.x - ankleRightPos.x, 2) + pow(hipRightPos.y - ankleRightPos.y, 2) + pow(hipRightPos.z - ankleRightPos.z, 2));
				float j = sqrt(pow(kneeRightPos.x - ankleRightPos.x, 2) + pow(kneeRightPos.y - ankleRightPos.y, 2) + pow(kneeRightPos.z - ankleRightPos.z, 2));

				float k = sqrt(pow(kneeLeftPos.x - footLeftPos.x, 2) + pow(kneeLeftPos.y - footLeftPos.y, 2) + pow(kneeLeftPos.z - footLeftPos.z, 2));
				float l = sqrt(pow(ankleLeftPos.x - footLeftPos.x, 2) + pow(ankleLeftPos.y - footLeftPos.y, 2) + pow(ankleLeftPos.z - footLeftPos.z, 2));

				float m = sqrt(pow(kneeRightPos.x - footRightPos.x, 2) + pow(kneeRightPos.y - footRightPos.y, 2) + pow(kneeRightPos.z - footRightPos.z, 2));
				float n = sqrt(pow(ankleRightPos.x - footRightPos.x, 2) + pow(ankleRightPos.y - footRightPos.y, 2) + pow(ankleRightPos.z - footRightPos.z, 2));

				float o = sqrt(pow((0.5*ankleLeftPos.x + 0.5*ankleRightPos.x) - footLeftPos.x, 2) + pow(ankleLeftPos.z - footLeftPos.z, 2));
				float p = sqrt(pow((0.5*ankleLeftPos.x + 0.5*ankleRightPos.x) - footRightPos.x, 2) + pow(ankleRightPos.z - footRightPos.z, 2));
				float q = sqrt(pow(footLeftPos.x - footRightPos.x, 2) + pow(footLeftPos.y - footRightPos.y, 2) + pow(footLeftPos.z - footRightPos.z, 2));

				//remove these
				//float r = sqrt(pow(spineMidPos.x - spineBasePos.x, 2) + pow(spineMidPos.y - spineBasePos.y, 2) + pow(spineMidPos.z - spineBasePos.z, 2));
				//float s = sqrt(pow(spineShoulderPos.x - spineMidPos.x, 2) + pow(spineShoulderPos.y - spineMidPos.y, 2) + pow(spineShoulderPos.z - spineMidPos.z, 2));

				float r = sqrt(pow(spineBasePos.x - spineShoulderPos.x, 2) + pow(spineBasePos.z - spineShoulderPos.z, 2));
				float s = sqrt(r + pow(spineShoulderPos.y - spineBasePos.y, 2));
				float t = sqrt(pow(spineShoulderPos.x - spineBasePos.x, 2) + pow(spineShoulderPos.y - spineBasePos.y, 2) + pow(spineShoulderPos.z - spineBasePos.z, 2));

				float u = sqrt(pow(spineShoulderPos.x - ((kneeLeftPos.x + kneeRightPos.x) / 2), 2) + pow(spineShoulderPos.y - ((kneeLeftPos.y + kneeRightPos.y) / 2), 2) + pow(spineShoulderPos.z - ((kneeLeftPos.z + kneeRightPos.z) / 2), 2));
				float v = sqrt(pow(spineBasePos.x - ((kneeLeftPos.x + kneeRightPos.x) / 2), 2) + pow(spineBasePos.y - ((kneeLeftPos.y + kneeRightPos.y) / 2), 2) + pow(spineBasePos.z - ((kneeLeftPos.z + kneeRightPos.z) / 2), 2));

				//8 features from body joints
				float height = headPos.y - std::fmin(ankleLeftPos.y, ankleRightPos.y);
				float leftHipAngle = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a*b)) * 180 / PI;  //180 - (acos(a/c) *180.0 / PI) - (acos(b/c) *180.0 / PI);
				float rightHipAngle = acos((pow(e, 2) + pow(d, 2) - pow(f, 2)) / (2 * e*d)) * 180 / PI; // 180 - (acos(d / f) *180.0 / PI) - (acos(e / f) *180.0 / PI);
				float leftKneeAngle = acos((pow(a, 2) + pow(h, 2) - pow(g, 2)) / (2 * a*h)) * 180 / PI; // 180 - (acos(a / g) *180.0 / PI) - (acos(h / g) *180.0 / PI);
				float rightKneeAngle = acos((pow(d, 2) + pow(j, 2) - pow(i, 2)) / (2 * d*j)) * 180 / PI; // 180 - (acos(d / i) *180.0 / PI) - (acos(j / i) *180.0 / PI);


				// Note: The following ankle angles were originally not used in Kinect version
				float leftAnkleAngle = acos((pow(h, 2) + pow(l, 2) - pow(k, 2)) / (2 * h*l)) * 180 / PI; // 180 - (acos(h / k) *180.0 / PI) - (acos(l / k) *180.0 / PI);
				float rightAnkleAngle = acos((pow(j, 2) + pow(n, 2) - pow(m, 2)) / (2 * j*n)) * 180 / PI;  // 180 - (acos(j / m) *180.0 / PI) - (acos(n / m) *180.0 / PI);
				//float twoFeetAngle = acos((pow(o, 2) + pow(p, 2) - pow(q, 2)) / (2 * o*p)) * 180 / PI; // 180 - (acos(o / q) *180.0 / PI) - (acos(p / q) *180.0 / PI);

				float chestAngle = 180 - (acos((pow(t, 2) + pow(s, 2) - pow(r, 2)) / (2 * t*s)) * 180 / PI); //acos((pow(r, 2) + pow(s, 2) - pow(t, 2)) / (2 * r*s)) * 180 / PI;
				float chestKneeAngle = acos((pow(t, 2) + pow(v, 2) - pow(u, 2)) / (2 * t*v)) * 180 / PI;


				//Prints the joints coords in the data file if data is not 'nan'
				if (height == height && leftHipAngle == leftHipAngle && rightHipAngle == rightHipAngle && leftKneeAngle == leftKneeAngle
					&& rightKneeAngle == rightKneeAngle && chestAngle == chestAngle && chestKneeAngle == chestKneeAngle && footRightPos.y == footRightPos.y
					&& footLeftPos.y == footLeftPos.y) {
					dataFile << height << "\n";
					dataFile << leftHipAngle << "\n";
					dataFile << rightHipAngle << "\n";
					dataFile << leftKneeAngle << "\n";
					dataFile << rightKneeAngle << "\n";
					//dataFile << leftAnkleAngle << "\n";
					//dataFile << rightAnkleAngle << "\n";
					//dataFile << twoFeetAngle << "\n";
					dataFile << chestAngle << "\n";
					dataFile << chestKneeAngle << "\n";
					//these two are only for the real time application!
					//dataFile << footRightPos.y << "\n";
					//dataFile << footLeftPos.y << "\n
					dataFile << rightAnkleAngle << "\n";
					dataFile << leftAnkleAngle << "\n";

					//frame timestamp
					dataFile << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "\n";

					//Visual output
					std::cout << height << "\n";
					std::cout << leftHipAngle << "\n";
					std::cout << rightHipAngle << "\n";
					std::cout << leftKneeAngle << "\n";
					std::cout << rightKneeAngle << "\n";
					//dataFile << leftAnkleAngle << "\n";
					//dataFile << rightAnkleAngle << "\n";
					//dataFile << twoFeetAngle << "\n";
					std::cout << chestAngle << "\n";
					std::cout << chestKneeAngle << "\n";
					//these two are only for the real time application!
					std::cout << rightAnkleAngle << "\n";
					std::cout << leftAnkleAngle << "\n";
					//frame timestamp
					std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "\n";



				}
    }
	dataFile.close();

}





int main(int argc, char* argv[])
{
    showHelpInfo();
    std::string configPath = "";
    if (argc > 1)
        configPath = argv[1];
    // Initialize Nuitrack
    try
    {
        Nuitrack::init(configPath);
    }
    catch (const Exception& e)
    {
        std::cerr << "Can not initialize Nuitrack (ExceptionType: " << e.type() << ")" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Create SkeletonTracker module, other required modules will be
    // created automatically
    auto skeletonTracker = SkeletonTracker::create();
    // Connect onSkeletonUpdate callback to receive skeleton tracking data
    skeletonTracker->connectOnUpdate(onSkeletonUpdate); //handTracker->connectOnUpdate(onHandUpdate);
    // Start Nuitrack
    try
    {
        Nuitrack::run();
    }
    catch (const Exception& e)
    {
        std::cerr << "Can not start Nuitrack (ExceptionType: " << e.type() << ")" << std::endl;
        return EXIT_FAILURE;
    }
    int errorCode = EXIT_SUCCESS;
    while (true)
    {
        try
        {
            // Wait for new skeleton tracking data
            Nuitrack::waitUpdate(skeletonTracker);
        }
        catch (LicenseNotAcquiredException& e)
        {
            std::cerr << "LicenseNotAcquired exception (ExceptionType: " << e.type() << ")" << std::endl;
            errorCode = EXIT_FAILURE;
            break;
        }
        catch (const Exception& e)
        {
            std::cerr << "Nuitrack update failed (ExceptionType: " << e.type() << ")" << std::endl;
            errorCode = EXIT_FAILURE;
        }
    }
    // Release Nuitrack
    try
    {
        Nuitrack::release();
    }
    catch (const Exception& e)
    {
        std::cerr << "Nuitrack release failed (ExceptionType: " << e.type() << ")" << std::endl;
        errorCode = EXIT_FAILURE;
    }
    return errorCode;
}

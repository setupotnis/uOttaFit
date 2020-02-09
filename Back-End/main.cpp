#include <iostream>

#include <math.h>

#include <cstdlib>

namespace session {

    float leftHipHeight;
    float rightHipHeight;
    int stage;
    std::string error;

}

//TODO: Use API to include Vector3, Joint, and JointType
namespace joints {

    Vector3 head;
    Vector3 torso;
    Vector3 leftAnkle;
    Vector3 rightAnkle;
    Vector3 leftHip;
    Vector3 rightHip;
    Vector3 leftElbow;
    Vector3 rightElbow;
    Vector3 leftKnee;
    Vector3 rightKnee;
    Vector3 leftShoulder;
    Vector3 rightShoulder;

}

int defineJoints(vector<Joint> jointsArray){
    using namespace joints;
    head = jointsArray[JointType::JOINT_HEAD];
    torso = jointsArray[JointType::JOINT_TORSO];
    leftAnkle = jointsArray[JointType::JOINT_LEFT_ANKLE];
    rightAnkle = jointsArray[JointType::JOINT_RIGHT_ANKLE];
    leftHip = jointsArray[JointType::JOINT_LEFT_HIP];
    rightHip = jointsArray[JointType::JOINT_RIGHT_HIP];
    leftElbow = jointsArray[JointType::JOINT_LEFT_ELBOW];
    rightElbow = jointsArray[JointType::JOINT_RIGHT_ELBOW];
    leftKnee = jointsArray[JointType::JOINT_LEFT_KNEE];
    rightKnee = jointsArray[JointType::JOINT_RIGHT_KNEE];
    leftShoulder = jointsArray[JointType::JOINT_LEFT_SHOULDER];
    rightShoulder = jointsArray[JointType::JOINT_RIGHT_SHOULDER];
}
//Verify Stages

bool isStageOne(){
    using namespace joints;
    bool conditionA = isStandingStraight(head, torso, leftAnkle, rightAnkle);
    bool conditionB = areFeetHipWidth(leftHip, rightHip, leftAnkle, rightAnkle);
    return (conditionA && conditionB);
}

bool isStageTwo() {
    using namespace joints;
    bool conditionA = areElbowsKneeLevel(leftElbow, rightElbow, leftKnee, rightKnee);
    bool conditionB = areElbowsOutsideKnees(leftElbow, rightElbow, leftKnee, rightKnee);
    bool conditionC = areKneesFacingStraight(leftKnee, rightKnee, leftAnkle, rightAnkle);
    return (conditionA && conditionB && conditionC);
}

bool isStageThree(){
    using namespace joints;
    bool conditionA = areFeetHipWidth(leftHip, rightHip, leftAnkle, rightAnkle);
    bool conditionB = areKneesOutsideAnkles(leftKnee, rightKnee, leftAnkle, rightAnkle);
    bool conditionC = areKneesSlightlyBent(leftAnkle, leftKnee, leftHip, rightAnkle, rightKnee, rightHip);
    session::leftHipHeight = leftHip.y;
    session::rightHipHeight = leftHip.y;
    return (conditionA && conditionB && conditionC);
}

bool isStageFour(){
    using namespace joints;
    bool conditionA = isBackStraight(leftShoulder, rightShoulder, torso, leftHip, rightHip);
    bool conditionB = hipsNotLower(leftHip, rightHip);
    bool conditionC = hipsNotHigher(leftHip, rightHip);
    return (conditionA && conditionB && conditionC);
}

bool isStageFive(){
    using namespace joints;
    bool conditionA = isBackStraight(leftShoulder, rightShoulder, torso, leftHip, rightHip);
    bool conditionB = isStandingStraight(head, torso, leftAnkle, rightAnkle);
    return (conditionA && conditionB);

}

//CONDITIONS
bool areFeetHipWidth(Vector3 leftHip, Vector3 rightHip, Vector3 leftAnkle, Vector3 rightAnkle) {
    if (!areAlignedHorizontally(leftHip, rightHip, leftAnkle, rightAnkle)){
        session::error = "Place feet at hip's width!";
        return false;
    }
    return true;
}

bool areElbowsKneeLevel(Vector3 leftElbow, Vector3 rightElbow, Vector3 leftKnee, Vector3 rightKnee) {
    if (!areAlignedVertically(leftElbow, rightElbow, leftKnee, rightKnee)){
        session::error = "Elbows must be at about knee level!";
        return false;
    }
    return true;
}

bool areElbowsOutsideKnees(Vector3 leftElbow, Vector3 rightElbow, Vector3 leftKnee, Vector3 rightKnee) {
    if (!areOutside(leftElbow, rightElbow, leftKnee, rightKnee)){
        session::error = "Arms must be outside your knees!";
        return false;
    }
    return true;
}

bool areKneesFacingStraight(Vector3 leftKnee, Vector3 rightKnee, Vector3 leftAnkle, Vector3 rightAnkle) {
    if (!areAlignedHorizontally(leftKnee, rightKnee, leftAnkle, rightAnkle)){
        session::error = "Keep knees facing straight for now!";
        return false;
    }
    return true;
}

bool areKneesOutsideAnkles(Vector3 leftKnee, Vector3 rightKnee, Vector3 leftAnkle, Vector3 rightAnkle){
    if (!(areAlignedHorizontally(leftKnee, rightKnee, leftAnkle, rightAnkle) && (abs(leftKnee.x - rightKnee.x) > abs(leftAnkle.x - rightAnkle.x))){
        session::error = "Keep toes and knees turned slightly outward!";
        return false;
    }
    return true;
}

bool areKneesSlightlyBent(Vector leftAnkle, Vector3 leftKnee, Vector3 leftHip, Vector3 rightAnkle, Vector3 rightKnee, Vector3 rightHip) {
    float leftKneeAngle = calcAngle(leftAnkle, leftKnee, leftHip);
    float rightKneeAngle = calcAngle(rightAnkle, rightKnee, rightHip);
    if (!((leftKneeAngle < 180) && (leftKneeAngle > 90) && (rightKneeAngle < 180) && (rightKneeAngle > 90))){
        session::error = "Keep knees slightly bent!";
        return false;
    }
    return true;

}

bool isBackStraight(Vector3 leftShoulder, Vector3 rightShoulder, Vector3 torso, Vector3 leftHip, Vector3 rightHip) {
    if (!(isStraight(leftShoulder, torso, leftHip) && isStraight(rightShoulder, torso, rightHip))){
        session::error = "Keep your back straight!";
        return false;
    }
    return true;
}

bool hipsNotLower(Vector3 leftHip, Vector3 rightHip){
    if (!((leftHip.y/session::leftHipHeight > 0.95) && (rightHip.y/session::rightHipHeight > 0.95))){
        session::error = "Hips must be stable during this step! Raise them back higher.";
        return false;
    }
    return true;
}

bool hipsNotHigher(Vector3 leftHip, Vector3 rightHip){
    if (!((leftHip.y/session::leftHipHeight < 1.05) && (rightHip.y/session::rightHipHeight < 1.05))){
        session::error = "Hips must be stable during this step! Lower them back.";
        return false;
    }
    return true;
}

bool isStandingStraight(Vector3 headJoint, Vector3 torsoJoint, Vector3 leftAnkleJoint, Vector3 rightAnkleJoint){
    if (!isStraight(headJoint, torsoJoint, leftAnkleJoint) && isStraight(headJoint, torsoJoint, rightAnkleJoint){
        session::error = "Make sure you are standing straight!";
        return false;
    }
    return true;
}

//JOINT COMPARISON
bool areAlignedHorizontally(Vector3 leftA, Vector3 rightA, Vector3 leftB, Vector3 rightB){
    float xRatio = ((abs(leftA.x - rightA.x))/(abs(leftB.x-rightB.x)));
    return ((xRatio > 0.9) || (xRatio < 1.1));
}

bool areAlignedVertically(Vector3 leftA, Vector3 rightA, Vector3 leftB, Vector3 rightB){
    float yRatio = ((abs(leftA.y - rightA.y))/(abs(leftB.y-rightB.y)));
    return ((yRatio > 0.9) || (yRatio < 1.1));
}

bool areOutside(Vector3 leftA, Vector3 rightA, Vector3 leftB, Vector3 rightB){
    return (abs(leftA.x - rightA.x) > abs(leftB.x - rightB.x));
}

bool isStraight(Vector3 a, Vector3 b, Vector3 c){
    float angle = calcAngle(a, b, c);
    return ((angle < 185) || (angle > 175));
}

//ANGLE CALCULATIONS
float calcAngle(Vector3 a, Vector3 b, Vector3 c) {
    float abSlope = (a.y + b.y)/(a.x - b.x);
    float bcSlope = (b.y + c.y)/(b.x - c.x);
    return atan(abs((abSlope - bcSlope)/(1 + abSlope * bcSlope)));
}

//TODO: This is what should get called when receiving event
int verifyEvent(vector<Joint> jointsArray){
    using namespace session;
    defineJoints(jointsArray);
    error = "";
    if (stage == 1 && isStageOne()){
        stage = 2;
    }
    if (stage == 2 && isStageTwo()){
        stage = 3;
    }
    if (stage == 3 && isStageThree()){
        stage = 4;
    }
    if (stage == 4 && isStageFour()){
        stage = 5;
    }
    if (stage == 5 && isStageFive()){
        stage = 0;
    }
    //TODO: Inject current stage and event into UI
}

int main() {

    session::stage = 0;

}


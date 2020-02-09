import tensorflow as tf
import numpy as np
import pyttsx3
import time
import os
#import tkinter

#from time import sleep
#from common import common as cm
#from builtins import True
from sklearn.externals import joblib

#from PIL import Image
#from PIL import ImageTk


#USE_TESTING_DATA = False
#USE_ROS = False
#UBUNTU = True
#UBUNTU = False
CLASSIFICATION_OUTPUT_TO_STR = {0:"STANDING", 1:"SITTING", 2:"LAYING DOWN"}

# The threshold of how many consecutive lying down classifications are required before it is considered a fall
LYING_DOWN_THRESHOLD = 5
#fallNum = 0
SITTING_THRESHOLD = 5

STANDING_THRESHOLD = 5

#lowest_y_point = 1000

#Threshold of how many m from the lowest point in the room is acceptable to approve the person is laying down on the ground?
#M_FROM_FLOOR = 0.25

# X_START_NONFLOOR = 0.0
# X_END_NONFLOOR = 0.0
# Z_START_NONFLOOR = 0.0
# Z_END_NONFLOOR = 0.0
#objects_per_room = {}

DATA_LOCATION = '../nuitrack_fall_detection/data/real_time_joints_data.txt'

#comm= cm()

def getClassification(inputVals):
    #print('inputVals = ' + str(inputVals))
    classification_output = loaded_model.predict(inputVals)
    print('prediction == ' + str(CLASSIFICATION_OUTPUT_TO_STR[classification_output[0]]))
    # if(inputVals[0][0] < 0.3):
    #     return "LAYING DOWN"
    #Gets the argmax value of the output of the neural network
    # if(inputVals[0][0] < 0.45):
    #     classification_output *= [0,1,2,1] #Can't be standing
    # elif(inputVals[0][0] >= 0.75):
    #     classification_output *= [1,1,0,1] #Can't be laying down
    #classification_output = tf.argmax(classification_output,1).eval()
    #print("INPUT == " + str(inputVals))
    return CLASSIFICATION_OUTPUT_TO_STR[classification_output[0]]

# def importFloorData(roomNumber):
#     filepath = "data/floorplans/" + str(roomNumber) + ".txt"
#     if(os.path.isfile(filepath)):
#         file = open(filepath, 'r')
#         objects_per_room[str(roomNumber)] = [] #This room has a list of objects
#         objects = file.read().splitlines()
#         num_objects = int(len(objects)/4) #Each file has 4 coords
#         for i in range(num_objects):
#             objects_per_room[str(roomNumber)].append(objects[(i*4):(i*4)+4]) #Append the object to the list of objects for that particular room
#     print("FLOOR OBJECT DATA IMPORTED FOR ROOM #" + str(roomNumber) + "... !")
#     return

#deprecated but still usable, isLayingOnTheFloor() is the new implementation
# def isWithinGroundRange(x, z, roomNumber):
#     objects = objects_per_room[str(roomNumber)] #Impoted floor data for that room
#     for object in objects:
#         if(x > float(object[0]) and x < float(object[1]) and z > float(object[2]) and z < float(object[3])): #If person is on that object
#             return False
#     return True

# def isLayingOnTheFloor(footRightPosY, footLeftPosY):
#     if((footRightPosY < (lowest_y_point + M_FROM_FLOOR)) and (footLeftPosY < (lowest_y_point + M_FROM_FLOOR))):
#         #print("PERSON LS LAYING ON THE FLOOR!")
#         return True
#     #print("PERSON not laying on the floor ..")
#     return False

if __name__ == "__main__":
    loaded_model = joblib.load('model/posture_model_feb_9_2020.pkl')
    engine = pyttsx3.init()
    
    # if(USE_TESTING_DATA):
    #     #inputs, labels = comm.getTestingData()
    #     testNetwork(inputs, labels)
    # else:
    #LAUNCH TKINTER UI IF USING WINDOWS   
    # root = ""
    # labelText = ""
    # if(not UBUNTU):
    #     from tkinter import Tk, StringVar, Label
    #     root = Tk()
    #     root.title("POSTURE DETECTION")
    #     root.geometry("400x100")
    #     labelText = StringVar()
    #     labelText.set('Starting...!')
    #     button = Label(root, textvariable=labelText, font=("Helvetica", 40))
    #     button.pack()


		
    #     root.update()
    
    
    # roomNumber = 0 #Room number 0
    # importFloorData(roomNumber)
    
    file = open(DATA_LOCATION,'w+')
    index = 0
    

    # lowest_y_point = 0
                
    # print("LOWEST_Y_POINT === " + str(lowest_y_point))
    
    #End of initialization step
    # file = open(DATA_LOCATION,'w+')
    # index = 0
    
    #SETUP ROS PUBLISHERS IF USING UBUNTU
    # pub1 = ""
    # pub2 = ""
    # r = ""
    # if(USE_ROS):
    #     import rospy
    #     from std_msgs.msg import String
    #     pub1 = rospy.Publisher('CAM_POSTURE', String, queue_size=10)
    #     pub2 = rospy.Publisher('CAM_FALL', String, queue_size=10)
    #     rospy.init_node('demo_pub_node')
    #     r = rospy.Rate(1)
        
    #Start system
    print('Starting..')
    lying_down_count =0

    # Sitting and standing counted used for resetting text file
    sitting_count = 0
    standing_count = 0
    
    #lying_down_start_time = 0 # Used to calculated length of time on floor
    while True:#not rospy.is_shutdown(): #while True (windows) | not rospy.is_shutdown()
        file = open(DATA_LOCATION,'r')
        lines = file.read().splitlines()
        file.seek(0) #move cursor to beggining of file for next loop

        

        if(len(lines) >= index+10): #if there is new data
            print('Classyfing ..')
            if(index > 2000):
                index = 0
                file = open(DATA_LOCATION,'w+')
            index += 10
            inp = lines[index-10:index] #get data for next frame
            #index += 20 #10 FPS
            inp = [float(i) for i in inp]
            inputVals = np.random.rand(1,7)
            inputVals[0] = inp[:7] #Only the first 7 values. The other two values will be used to check the floor plan
            posture = getClassification(inputVals)


            # if(not UBUNTU):
            #     labelText.set(posture)
            #     if(posture == "LAYING DOWN"):
            #         load = Image.open("lying.JPG")
            #         #load = load.resize(50,50)
            #         render = ImageTk.PhotoImage(load)
            #         img = Label(image=render)
            #         img.image = render
            #         img.place(x=400, y=300)
            #         #load.load()
            #         root.update()
            #         img.destroy()

            #         #Used to clear data in textfile 
            #         standing_count = standing_count + 1
            #         if(standing_count >= 7):
            #             file = open(DATA_LOCATION,'w+')
            #             file.truncate() # Clear text file
            #             standing_count = 0
                        
                    
            #     elif(posture == "SITTING"):
            #         load = Image.open("sitting.JPG")
            #         #load = load.resize(50,50)
            #         render = ImageTk.PhotoImage(load)
            #         img = Label(image=render)
            #         img.image = render
            #         img.place(x=500, y=100)
            #         #load.load()
            #         root.update()
            #         img.destroy()

            #         # Used to clear data in textfile
            #         sitting_count = sitting_count + 1
            #         if(standing_count >= 7):
            #             file = open(DATA_LOCATION,'w+')
            #             file.truncate() # Clear text file
            #             sitting_count = 0
                    

            #     else:
            #         load = Image.open("standing.JPG")
            #         #load = load.resize(50,50)
            #         render = ImageTk.PhotoImage(load)
            #         img = Label(image=render)
            #         img.image = render
            #         img.place(x=500, y=100)
            #         #load.load()
            #         root.update()
            #         img.destroy()
    
            print(posture)
            if(posture == "LAYING DOWN"):
                lying_down_count = lying_down_count + 1
                

            else:
                lying_down_count = 0

            print("Bad posture count: "+str(lying_down_count))

            if(lying_down_count >= LYING_DOWN_THRESHOLD):
                print("\a")
                time.sleep(1)
                engine.say("(Bad posture! Curved Back!")
                engine.runAndWait()
                #wait = input("PRESS ENTER TO CONTINUE")
                file = open(DATA_LOCATION,'w+')
                file.truncate() # Clear text file
                #wait = input("Fall detected!! PRESS ENTER TO CONTINUE.") #Sound alarm and pause
                time.sleep(3)
                lying_down_count =0


            if(posture == "SITTING"):
                sitting_count = sitting_count + 1
                
            else:
                sitting_count = 0

            print("Good posture count: "+str(sitting_count))

            if(sitting_count >= SITTING_THRESHOLD):
                print("\a")
                time.sleep(1)
                engine.say("Great Posture!")
                engine.runAndWait()
                #wait = input("PRESS ENTER TO CONTINUE")
                file = open(DATA_LOCATION,'w+')
                file.truncate() # Clear text file
                #wait = input("Fall detected!! PRESS ENTER TO CONTINUE.") #Sound alarm and pause
                time.sleep(3)
                sitting_count =0


            if(posture == "STANDING"):
                standing_count = standing_count + 1
                
            else:
                standing_count = 0

            print("Standing count: "+str(standing_count))

            if(standing_count >= STANDING_THRESHOLD):
                print("\a")
                time.sleep(1)
                engine.say("STANDING!")
                engine.runAndWait()
                #wait = input("PRESS ENTER TO CONTINUE")
                file = open(DATA_LOCATION,'w+')
                file.truncate() # Clear text file
                #wait = input("Fall detected!! PRESS ENTER TO CONTINUE.") #Sound alarm and pause
                time.sleep(3)
                standing_count =0
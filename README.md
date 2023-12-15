# ISS-2023-Gas-Sensor-AJB-RM

# Authors
Romain Moulin & Aude Jean-Baptiste

# Introduction
The objective of this project is to integrate a gas sensor that we made ourselves during a training period at AIME (Atelier Interuniversitaire de Micro Electronique) and send its data over a Lora network to a dashboard to see and analyse the values.

# Initiation to Electronics and Arduino programming
As we both come from a computer science background (4IR-SC), we used the first labs as an introduction to Arduino and Kicad. We tested some small projects from simply making a LED from an Arduino blink to collecting data sent by a Nunchunck (A nintendo WII controller). We also designed an android application able to communicate and interact with an arduino.

<img src="./Image/Application_Bluetooth.png" alt="Screenshot of our Android application" width="200"/>
*Screenshot of our Android application*


These first sessions were really usefull to understand the basics of Arduino programming and electronics. These small projects were a good introduction to the real project of this course.

#  Begining of the project
To begin our project, we first tried to connect an arduino to the Lora network. To do so, we used a RN2483 chip made by Microship which is a module that is able to communicate on a Lora network. As this chip only has tiny connectors, we needed to weld the component to a board that would have bigger connectors for the communication with the arduino.

<img src="./Image/RN2483_with_board.jpeg" alt="Screenshot of our Android application" width="200"/>
*RN2483 Module weld on the board*

After this step, we were able to connect our arduino to the INSA's Lora network. For this, we used *The Things Network* library for arduino, the code is available [here](./Arduino-Code/lora_connection.ino).
For this, we had used the otaa authentication method. We got the device ID using the library and the application ID and key on the chirpstack website. 

<img src="./Image/Arduino_Authentification.png" alt="Screenshot of our Android application" width="200"/>
*Authentication of the arduino to the Lora network*

# Integration of the MQ-3B gas sensor

With the established connection, we had to send data to the gateway in order to retrive it and display it on a dashboard. As a first implementation of this application we connected an alreay made gas sensor which is the MQ-3B gas sensor to our arduino. The final montage of our circuit is the following:

<img src="./Image/final_montage.jpeg" alt="Screenshot of our Android application" width="200"/>
*Montage of the circuit with the MQ-3B gas sensor*



# Design of a node-red application


# Design of the PCB 

# To go further

# Conclusion

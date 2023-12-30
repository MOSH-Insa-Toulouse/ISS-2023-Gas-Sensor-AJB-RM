# ISS-2023-Gas-Sensor-AJB-RM

# Authors
Romain Moulin & Aude Jean-Baptiste, 5ISS 2023-2024

# Introduction
The objective of this project is to integrate a gas sensor that we made ourselves during a training period at AIME (Atelier Interuniversitaire de Micro Electronique) and send its data over a Lora network to a dashboard to see and analyse the values.

# Initiation to Electronics and Arduino programming
As we both come from a computer science background (4IR-SC), we used the first labs as an introduction to Arduino and Kicad. We tested some small projects from simply making a LED from an Arduino blink to collecting data sent by a Nunchunck (A nintendo WII controller). We also designed an android application able to communicate and interact with an arduino.

<img src="./Image/Application_Bluetooth.png" alt="Screenshot of our Android application" width="200"/> *Screenshot of our Android application*



These first sessions were really usefull to understand the basics of Arduino programming and electronics. These small projects were a good introduction to the real project of this course.

#  Beginning of the project
To begin our project, we first tried to connect an arduino to the Lora network. To do so, we used a RN2483 chip made by Microship which is a module that is able to communicate on a Lora network. As this chip only has tiny connectors, we needed to weld the component to a board that would have bigger connectors for the communication with the arduino. The following image features the board with an antenna for the 868MHz frequency band. 

<img src="./Image/RN2483_with_board.jpeg" alt="RN2483 Module weld on the board" width="400"/> *RN2483 Module weld on the board*

After this step, we were able to connect our arduino to the INSA's Lora network. For this, we used *The Things Network* library for arduino, the code is available [here](./Arduino-Code/lora_connection/lora_connection.ino).
For this, we had used the otaa authentication method. We got the device ID using the library and the application ID and key on the [chirpstack's INSA website](https://srv-chirpstack.insa-toulouse.fr/#/login) (please note that this server is only available if you are directly connected to INSA's network, or using a VPN). 

<img src="./Image/Arduino_Authentification.png" alt="Authentication of the arduino to the Lora network" width="200"/> *Authentication of the arduino to the Lora network*

# Integration of the MQ-3B gas sensor

With the established connection, we had to send data to the gateway in order to retrive it and display it on a dashboard. As a first implementation of this application we connected an alreay made gas sensor which is the MQ-3B gas sensor to our arduino. The final montage of our circuit is the following:

<img src="./Image/final_montage.jpeg" alt="Montage of the circuit with the MQ-3B gas sensor" width="400"/> *Montage of the circuit with the MQ-3B gas sensor*

After that we changed our arduino code to read the value from the gas sensor and send it to our LoRa network. As the max value we can get from the sensor is 1024, we encoded the information on 2 bytes before sending it.

<img src="./Image/Arduino_Code.png" alt="*Our arduino setup and loop functions" width="400"/> *Our arduino setup and loop functions*

# Design of a node-red application

As the data is received by the LoRa network, we could visualize it on the chirpstack web page. However, it is not fitted for a real usage of our gas sensor. A user of gas sensor would like to see the state of the sensor in real time in a dashboard. To do so, we decided to use node-red and MQTT.

MQTT is a communication protocol particulary used for IoT devices. With this protocol there are two kind of nodes, the publisher and the subscribers. Publishers publish data in a topic and subscriber get all the data published on a specific topic. This protocol is supported by chirpstack which automatically upload the data it receives in a MQTT topic. 

Node-red is a web-browser flow editor that helps to easily connect flows. It provides visual coding with blocks for the ease of conception. It also implements dashboard library to display the data is user friendly dahsboards. We used a MQTT subscribe block to get the data from chirpstack that we pipe into a javascript function that decodes the data (it is encoded in base64 by chirpstack). Finaly we send the decoded data to a dashboard block to visualize the data.

<img src="./Image/flux_node_red.png" alt="The node-red flow" width="600"/> *The node-red flow*


To test our sensor, we putted hydroalcoholic gel near it to see if we could see it on our dashboard. This experience was a succes and we were able to see through the dashboard the increase of the gas rate near the sensor.

<img src="./Image/Gas_Sensor_Dashboard.png" alt="Dashboard for the witness experience in ambient air" width="600"/> *Dashboard for the witness experience in ambient air*

<img src="./Image/Dashboard_Gas_Sensor.png" alt="Dashboard for the experience with alcoholic gel" width="600"/> *Dashboard for the experience with alcoholic gel*

# Design of the PCB 

# Datasheet 

# To go further

# Conclusion

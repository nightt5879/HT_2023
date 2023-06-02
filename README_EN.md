[中文](README.md) | English
- [2023 Holtek Cup Project](#2023-holtek-cup-project)
  - [1 Project Introduction](#1-project-introduction)
  - [2 Main File Description](#2-main-file-description)
    - [2.1 Holtek HT32init](#21-holtek-ht32init)
    - [2.2 Project](#22-project)
    - [2.3 su-03t](#23-su-03t)
    - [2.4 Communication Protocol](#24-communication-protocol)
    - [2.5 Board](#25-board)
    - [Other Files](#other-files)
  - [3 Instructions for Use](#3-instructions-for-use)
  - [4 Other Information](#4-other-information)
- [Special Thanks](#special-thanks)

# 2023 Holtek Cup Project
## 1 Project Introduction
The purpose of this project is to assist the medical system in portable and integrated information entry, allowing the medical system to cover more areas at a lower cost. The function of this work is to simplify the complicated process of information entry. With just one portable device, temperature measurement and information entry (such as Yuekang Code and nucleic acid code) can be completed without requiring personnel participating in testing to present their information, making it more comfortable for those involved in information entry.<br>
Supports multiple devices, data synchronization and intelligent voice assistance. It makes the entire medical information input more efficient while also providing a better experience for both staff and participants.<br>
For detailed introduction please refer to: [**Report**](Report.docx)

## 2 Main File Description
### 2.1 Holtek HT32init
HT official encapsulation init tool used for initializing registers of HT32F125x. Convenient for programming use.
### 2.2 Project
Main program for HT single-chip microcomputer written with Keil software.
### 2.3 su-03t 
SDK and burning software for su-03t; details can be found on [Smartpi's](http://smartpi.cn/#/) official website.
### 2.4 Communication Protocol 
Describes the protocol between serial ports but due to last-minute changes during development, please refer specifically to the program itself.
### 2.5 Board 
PCB schematic diagram (Jialichuang EDA Professional Edition).
### Other Files 
As this project was participated by multiple people who did not put everything into one project,<br>for codes related to mini-programs, ESP8266, ESP32-CAM or face recognition please visit [here](https://github.com/caiyilian/holtekFaceRecognition).

 ## 3 Instructions for Use
Burn HT32, ESP8266, ESP32-CAM and su-03t into the device and complete hotspot connection configuration to use.<br>
The face recognition code runs on a computer (simulated server).

 ## 4 Other Information
Due to various reasons this project **did not win any awards**, but it is very inspiring for getting started with HT32 (with encapsulated init).<br>It can be used as an example of splicing different modules together. The unified C port charging and burning design in PCB also has great inspiration.<br>
Project demonstration video can be found [here](https://www.bilibili.com/video/BV17T411b7BC/?share_source=copy_web&vd_source=ccdd4439e8d8c1f809ca65541a51d508)<br>
If you have any questions please contact me at:<br>scnuyyj@gmail.com or 1469259223@qq.com<br>
My Bilibili account is [here](https://space.bilibili.com/23620249?spm_id_from=333.788.0.0)
# Special Thanks
Thanks to my classmates Cai, Liu and Peng for their selfless contributions during the development of this project in their spare time related to the competition.<br>**Thank you everyone who contributed to this project**
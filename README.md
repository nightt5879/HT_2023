中文 | [English](README_EN.md)
# 2023合泰杯项目
## 1 项目简介
本作品创作目的是助力医疗系统便携式一体化录入信息，让医疗系统以更低的成本覆盖到更多地区。作品的功能是可以将本需要繁杂录入信息流程的。只需要一个便携式的设备就能完成测温，录入信息（例如粤康码和核酸码），并且不需要参与测试的人员出示信息，使得参与信息录入的人们有更舒适的体验。<br>
支持多设备、数据同步可查、智能语音辅助等。使整个医疗信息录入更加的高效，同时也能让工作人员与参与人员有更好的体验。<br>
详细的介绍请看: [**报告书**](报告书.docx)

## 2 主要文件说明
### 2.1 Holtek HT32init
HT官方的封装init工具，用于初始化HT32F125x的寄存器。方便编程使用
### 2.2 project
HT单片机的主要程序，使用keil编写与烧录
### 2.3 su-03t
su-03t的SDK与烧录软件，详情请移步[智能公元](http://smartpi.cn/#/)官方网站了解
### 2.4 通信协议
说明了串口间的协议，但由于后期赶工临时更改了很多，具体以程序内的为准
### 2.5 board
PCB原理图（嘉立创EDA专业版）
### 2.6 project_backup
程序后期好像有烧录不了之类的奇怪问题，backup里为最后比赛前烧录的程序.
### 2.7 其他
 由于该项目由多人参与并且未放到同一个项目里面<br>
 有关小程序、8266、ESP32-CAM、人脸识别的代码移步[这里](https://github.com/caiyilian/holtekFaceRecognition)进行了解

 ## 3 使用说明
 把HT32,8266,ESP32-CAM,su-03t,烧录进入设备，最后进行热点连接配置完成就可以使用<br>
 其中的人脸识别代码运行在电脑上（模拟服务器）

 ## 4 其他
由于种种原因很该项目**并没有获奖**，但对于上手HT32很有启发（有封装好的init）<br>
可以学习各个不同模块进行拼接的思路，PCB设计的统一C口充电与烧录也很有启发性<br>
项目演示视频在[这里](https://www.bilibili.com/video/BV17T411b7BC/?share_source=copy_web&vd_source=ccdd4439e8d8c1f809ca65541a51d508)<br>
如果有相关问题可以联系我<br>
我的邮箱: scnuyyj@gmail.com ， 1469259223@qq.com<br>
我的b站账号在[这里](https://space.bilibili.com/23620249?spm_id_from=333.788.0.0)
# 特别鸣谢
感谢蔡同学、刘同学、蓬同学在项目中的无私付出。在一个个闲暇时间进行比赛相关的开发。<br>
**感谢所有人对这个项目做出的贡献**

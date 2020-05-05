# Com2Arduino
Windows Console to Arduino - Control your arduino from console on PC!!

Hello Github. 
This is my first git, and my first considerably useful program. 
I feel like this can really help others, and so I want to share it. 

2016 Manash Kumar Mandal from MIT created a fantastic serial to arduino program. 
I made several changes to his c++ code found here:
https://github.com/manashmandal/SerialPort

My code implements a few features:
-Specify port (Port can be found in arduino IDE under TOOLS->PORT
    -Enter in ALL CAPS
-Arduino 328 and 2560 Support.
  - Right now this is all that is supported that I have tested. Many more may work. but that is all I have tested out.
-You can send commands directly to your arduino from the command console. I just created this program in C++, and its basically an end user feature to be used in combination with your own modificiation of my arduino code(or your own, provided you understand that c++ is sending Dec/hex data to your arduino, it needs to be converted to be understood. Thats what my arduino program does. )

The sky is the limit!
  
  I have left some notes in the arduino. You will quickly see that by modifying your arduino code, you can activate your arduino over the web, from your computer in your house, perhaps in your barn, or at your friends house. Just implement some networking, actuators, motors, the sky is the limit. 


I will work on enhancements and two way readability. For now, whatever you code in arduino can be a command in com2ardunio!

Cheers!

-A


# 💫 Azura

> 📜 An application that allows the connection of Discord to a computer in order to make dynamic streams where the chat can perform real actions.

❗ This project is still in development so it is susceptible to some errors or performance problems, any contribution is appreciated to advance the development of the project.

# ⚡ Features

+ ✨ **Open source and free to use:** You can do whatever you want with the code in this project, even improve it or implement it in other projects for free.
+ 🍉 **Easy to use and customize:** Azura has its own console application programmed in C to facilitate both the installation process and the execution of the project, in addition, it has configurable files to be able to modify the functionality of the bot as desired.
+ 🔒 **Logs system:** The bot has a log system to know the actions it takes on the computer, which can be viewed from the website.

# 💾 Requirements

+ [Python](https://www.python.org/)
+ [Node.js](https://nodejs.org/en) (Required only if you want to use the website)
+ Windows 7 or above

# 📖 Instructions

+ Run the Azura.exe file (It is recommended that you make a shortcut if you plan to move the file)
> ![image](https://github.com/RiothDev/Azura/assets/109932988/93b72e73-8ad1-4d76-a6e6-56a210ee47cf)

+ In the Azura menu you will find the following options: The ".env setup" option will allow you to create and modify the .env file which will request as requirements the ID of the guild in which you want to run the bot and the bot token. "Project setup" will install everything necessary to run the bot. "Website setup" will install everything necessary to run the website. "Complete project setup" will install the entire project (i.e. the three options above). "Run project" will open the project run menu.
> ![image](https://github.com/RiothDev/Azura/assets/109932988/f1760f76-3d1d-418e-82b1-11acd55d8154)

+ In the run menu you will find the following options: "Start project" will start the project (that is, the web page and the bot) (it is recommended that they be run separately but there should be no problem running both). "Start bot" will start the bot execution. "Start website" will begin the execution of the web page.
> ![image](https://github.com/RiothDev/Azura/assets/109932988/8c1eebd5-46e4-45fd-992a-b8b130007bc2)

+ **In the "Config.ini" file located in the "Settings" folder you can change different bot configurations.**
- Prefixes are used in the typing system, "prefix" refers to the prefix for writing the message and "send_prefix" refers to the final character for sending the message. For example "(hello)" will send the message "hello" on the computer.
- In data, the value of "maximum_logs" refers to the maximum number of logs that the logging system can store on the page.
- Input refers to the characters that will be taken into account to execute commands from the computer and what exactly they will do, for example 'a="left"' refers to the fact that every time "a" is typed the "left" key is executed " on the keyboard. (You can remove and add any input, but the "enter" input should not be removed)
> ![image](https://github.com/RiothDev/Azura/assets/109932988/5cdc5480-9424-4e12-8bf6-bf35abc67c2f)

# 🤖 Commands
+ ```/connect``` - Send a request to the computer to connect the user.
+ ```/disconnect``` - Disconnect the user from the computer.
+ ```/typing``` - Toggle typing mode, which allows the user to use the computer keyboard to type messages.
+ ```/gamemode``` - Toggle the game mode which allows the user to use the inputs assigned by the computer owner.

# 📘 Website
+ The web page will display a list of all currently saved logs.
> ![image](https://github.com/RiothDev/Azura/assets/109932988/37e200c8-fa11-471b-a812-75c08ff5cd37)

+ When you press a log, all the information saved regarding that log will be displayed.
> ![image](https://github.com/RiothDev/Azura/assets/109932988/f33614d8-3db3-410f-b8f1-687426935bb6)

# 📄 Notes
*This project was scheduled as a weekend project, so it will likely have several bugs, I will be working on fixing them occasionally.*

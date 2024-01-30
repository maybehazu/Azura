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

+ Compile and run the Azura.c file (It is recommended that you create a shortcut of the .exe file if you plan to move the file)
> ![image](https://github.com/nothazu/Azura/assets/153567247/a35d42f9-ec84-4616-9afd-22b92fd9bbac)

+ In the Azura menu you will find the following options: The ".env setup" option will allow you to create and modify the .env file which will request as requirements the ID of the guild in which you want to run the bot and the bot token. "Project setup" will install everything necessary to run the bot. "Website setup" will install everything necessary to run the website. "Complete project setup" will install the entire project (i.e. the three options above). "Run project" will open the project run menu.
> ![image](https://github.com/NotInit/Azura/assets/153567247/3403aa22-0001-4c84-a505-a21c7c9cd934)

+ In the run menu you will find the following options: "Start project" will start the project (that is, the web page and the bot) (it is recommended that they be run separately but there should be no problem running both). "Start bot" will start the bot execution. "Start website" will begin the execution of the web page.
> ![image](https://github.com/NotInit/Azura/assets/153567247/7cba6b41-5285-4a48-9e7a-b417b820d737)

+ **In the "Config.ini" file located in the "Settings" folder you can change different bot configurations.**
- Prefixes are used in the typing system, "prefix" refers to the prefix for writing the message and "send_prefix" refers to the final character for sending the message. For example "(hello)" will send the message "hello" on the computer.
- In data, the value of "maximum_logs" refers to the maximum number of logs that the logging system can store on the page.
- Input refers to the characters that will be taken into account to execute commands from the computer and what exactly they will do, for example 'a="left"' refers to the fact that every time "a" is typed the "left" key is executed " on the keyboard. (You can remove and add any input, but the "enter" input should not be removed)
> ![image](https://github.com/NotInit/Azura/assets/153567247/f4329a73-849e-4934-818b-adf1424c484d)

+ **In case there is any problem with the .env file or the logs, you can run the clear.bat file to delete the .env file and also clear the logs** 

# 🤖 Commands
+ ```/connect``` - Send a request to the computer to connect the user.
+ ```/disconnect``` - Disconnect the user from the computer.
+ ```/typing``` - Toggle typing mode, which allows the user to use the computer keyboard to type messages.
+ ```/gamemode``` - Toggle the game mode which allows the user to use the inputs assigned by the computer owner.

# 📘 Website
+ The web page will display a list of all currently saved logs.
> ![image](https://github.com/NotInit/Azura/assets/153567247/23ed16ee-8e36-412e-a2d2-86e40edaee83)

+ When you press a log, all the information saved regarding that log will be displayed.
> ![image](https://github.com/NotInit/Azura/assets/153567247/a98a0597-79e2-4ba4-ad86-a2e0488b001d)

# 📄 Notes
*This project was scheduled as a weekend project, so it will likely have several bugs, I will be working on fixing them occasionally.*

import os, discord, dotenv, colorama, keyboard, time, configparser, re
from discord import interactions
from unidecode import unidecode
from src.Database import save_log
from src.Connection import send_connection_request

dotenv.load_dotenv(dotenv.find_dotenv())

print(colorama.Fore.LIGHTCYAN_EX + """
                                      
     /\                         
    /  \    _____   _ _ __ __ _ 
   / /\ \  |_  / | | | '__/ _` |
  / ____ \  / /| |_| | | | (_| |
 /_/    \_\/___|\__,_|_|  \__,_|
                                
                                
      """ + colorama.Fore.RESET)

print(colorama.Fore.YELLOW + "* " + colorama.Fore.LIGHTYELLOW_EX + "Starting bot..." + colorama.Fore.RESET + "\n")

connections = []

config = configparser.ConfigParser()
config.read("settings/Config.ini")

config_data = {}

for section in config.sections():
    config_data[section] = {}

    for option in config.options(section):
        config_data[section][option] = config.get(section, option)

commands = {
    "connect": "Command to make a request to connect to the computer.",
    "disconnect": "Command to disconnect from the computer.",
    "gamemode": "Command to toggle gamemode.",
    "typing": "Command to toggle typing mode."
}

class Client(discord.Client):
    def __init__(self, *, intents) -> None:
        super().__init__(intents=intents)
        self.tree = discord.app_commands.CommandTree(self)
    
    async def setup_hook(self) -> None:
        self.tree.copy_global_to(guild=discord.Object(id=int(os.getenv("GUILD"))))
        await self.tree.sync(guild=discord.Object(id=int(os.getenv("GUILD"))))

client = Client(intents=discord.Intents.all())

@client.tree.command(name="connect", description="Command to make a request to connect to the computer.")
async def connect(interaction: interactions.Interaction) -> None:
    try:
        await interaction.response.send_message(embed=discord.Embed(color=discord.Color.green(), title="Connection request sent.", description="Current connections: **{}**".format(len(connections))))

        if send_connection_request(interaction.user.id, interaction.user.name) and not interaction.user.id in connections:
            connections.append((interaction.user.id, False, False))

            connections_id = []

            for connection in connections:
                connections_id.append(connection[0])

            print(colorama.Fore.LIGHTYELLOW_EX + "* Current connections: {}\n".format(str(connections_id)) + colorama.Fore.RESET)
            save_log(interaction.user.name, "Connected", config_data["data"]["maximum_logs"])
    
    except Exception as err:
        await interaction.response.send_message(embed=discord.Embed(title="Error when trying to make the request.", description="This may be due to an internal problem.", color=discord.Color.red()))

@client.tree.command(name="gamemode", description="Command to toggle gamemode.")
async def gamemode(interaction: interactions.Interaction) -> None:
    try:
        is_connected = False

        for connection in connections:
            if connection[0] == interaction.user.id:
                value = not connection[2]
                is_connected = True; connections[connections.index(connection)] = (connection[0], connection[1], value)

                status = "On" if value else "Off"

                await interaction.response.send_message(embed=discord.Embed(title="The gamemode state has been changed correctly.", description="Actual state: **{}**".format(status), color=discord.Color.green()))

        if not is_connected:
            await interaction.response.send_message(embed=discord.Embed(title="It is necessary to be connected to the computer to activate gamemode.", color=discord.Color.red()))

    except Exception as err:
        await interaction.response.send_message(embed=discord.Embed(title="Error when trying to activate gamemode.", description="This may be due to an internal problem.", color=discord.Color.red()))

@client.tree.command(name="typing", description="Command to toggle typing mode.")
async def typing(interaction: interactions.Interaction) -> None:
    try:
        is_connected = False

        for connection in connections:
            if connection[0] == interaction.user.id:
                value = not connection[1]
                is_connected = True; connections[connections.index(connection)] = (connection[0], value, connection[2])

                status = "On" if value else "Off"

                await interaction.response.send_message(embed=discord.Embed(title="The typing state has been changed correctly.", description="Actual state: **{}**".format(status), color=discord.Color.green()))

        if not is_connected:
            await interaction.response.send_message(embed=discord.Embed(title="It is necessary to be connected to the computer to activate typing mode.", color=discord.Color.red()))

    except Exception as err:
        await interaction.response.send_message(embed=discord.Embed(title="Error when trying to activate typing mode.", description="This may be due to an internal problem.", color=discord.Color.red()))

@client.tree.command(name="disconnect", description="Command to disconnect from the computer.")
async def disconnect(interaction: interactions.Interaction) -> None:
    try:
        found = False

        for connection in connections[:]:
            if interaction.user.id in connection:
                found = True

                connections.remove(connection)

                await interaction.response.send_message(embed=discord.Embed(color=discord.Color.green(), description="Current connections: {}".format(len(connections)), title="{} has disconnected from the computer.".format(interaction.user.name)))

                save_log(interaction.user.name, "Disconnected", config_data["data"]["maximum_logs"])

        if not found:
            await interaction.response.send_message(embed=discord.Embed(color=discord.Color.red(), description="You are not connected to the computer.", title="Error trying to disconnect."))

    except Exception as err:
        await interaction.response.send_message(embed=discord.Embed(color=discord.Color.red(), description="This may be due to an internal error.", title="Error trying to disconnect."))

@client.tree.command(name="help", description="Command to view bot commands.")
async def help(interaction: interactions.Interaction) -> None:
    try:
        embed = discord.Embed(title="Help", description="Bot commands", color=discord.Color.green())

        for k, v in commands.items(): embed.add_field(name=k, value=v)

        await interaction.response.send_message(embed=embed)

    except Exception as err:
        await interaction.response.send_message(embed=discord.Embed(title="Error when trying to perform the action.", description="This may be due to an internal error.", color=discord.Color.red()))

def main() -> None:
    os.system("cls")

    @client.event
    async def on_ready() -> None:
        print(colorama.Fore.BLUE + "\n- Invite: " + colorama.Fore.CYAN + "https://discord.com/api/oauth2/authorize?client_id={}&scope=applications.commands%20bot".format(client.user.id) + colorama.Fore.RESET)

        activity = discord.Activity(type=discord.ActivityType.playing, name="bot programmed by NotInit", bot_status=discord.Status.idle)
        await client.change_presence(activity=activity)

        print(colorama.Fore.GREEN + "- " + colorama.Fore.LIGHTGREEN_EX + "The bot is ready" + colorama.Fore.RESET + "\n")
    
    @client.event
    async def on_message(msg: discord.Message) -> None:
        try:
            for connection in connections:
                if connection[0] == msg.author.id:
                    if msg.content.startswith(re.search('"([^"]*)"', config_data["prefixes"]["prefix"]).group(1)) and connection[1]:
                        for x in unidecode(msg.content[len(re.search('"([^"]*)"', config_data["prefixes"]["prefix"]).group(1)):]):
                            if x == re.search('"([^"]*)"', config_data["prefixes"]["send_prefix"]).group(1): keyboard.send("enter"); continue
                            keyboard.press(x)
                    
                        save_log(msg.author.name, "Sent the message '{}'".format(msg.content[len(re.search('"([^"]*)"', config_data["prefixes"]["prefix"]).group(1)):-1]), config_data["data"]["maximum_logs"])
                
                    elif connection[2]:
                        if msg.content.lower().startswith("enter"): keyboard.send("enter"); continue

                        for key, value in config_data["input"].items():
                            if msg.content.lower().startswith(key):
                                keyboard.press(re.search('"([^"]*)"', value).group(1))
                                time.sleep(0.32 * (10 if len(msg.content) > 10 else len(msg.content)))
                                keyboard.release(re.search('"([^"]*)"', value).group(1))
        
        except Exception as err:
            print(colorama.Fore.LIGHTRED_EX + "- Error when trying to perform an action: " + str(err) + colorama.Fore.RESET)
    
if __name__ == "__main__":
    main()

client.run(os.getenv("TOKEN"))
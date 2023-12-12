import colorama

def send_connection_request(id: int, username: str) -> None:
    return str(input(colorama.Fore.MAGENTA + "> " + colorama.Fore.LIGHTMAGENTA_EX + "Accept connection from user '{}'? (Y/N): ".format(username) + colorama.Fore.MAGENTA)).lower() == "y"
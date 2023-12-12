import json, colorama
from datetime import datetime

def save_log(log: str, action: str, max_logs: int) -> None:
    try:
        with open("web/public/data/Logs.json", "r") as logs:
            content_json = json.load(logs)

            data = {}
            index = 0

            if len(content_json) > int(max_logs):
                content_json = {}
        
            else:
                for i, x in enumerate(content_json):
                    index = i + 1

                    data[i] = {}
                    data[i]["log"] = content_json[x]["log"]
                    data[i]["action"] = content_json[x]["action"]
                    data[i]["date"] = content_json[x]["date"]
        
            data[index] = {}
            data[index]["log"] = log
            data[index]["action"] = action
            data[index]["date"] = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        if not isinstance(data, dict):
            data = {}

        with open("web/public/data/Logs.json", "w+") as logs:
            json.dump(data, logs, indent=4)

    except Exception as err:
        print(colorama.Fore.LIGHTRED_EX + "- Error when trying to save data" + colorama.Fore.RESET)
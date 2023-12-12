const queryString = window.location.search
const params = new URLSearchParams(queryString)

const key = params.get("key")

fetch("data/Logs.json")
    .then((response) => response.json())
    .then((data) => {
        const element = data[key]

        if(element) {
            document.getElementById("log-name").innerText = `Log #${key}`
            document.getElementById("log").innerText = `Log: ${element["log"]}`
            document.getElementById("action").innerText = `Action: ${element["action"]}`
            document.getElementById("date").innerText = `Date: ${element["date"]}`
        }
    })
    .catch((err) => console.error("- Error trying to load logs.json: ", err));
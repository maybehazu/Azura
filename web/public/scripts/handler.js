fetch("data/Logs.json")
    .then((response) => response.json())
    .then((data) => {
        for (const key in data) {
            if (Object.hasOwnProperty.call(data, key)) {
                const item = data[key]
                const listItem = document.createElement("li")

                listItem.textContent = `Log-${key}: ${item.log} - ${item.date}`
                document.getElementById("logs").appendChild(listItem)

                listItem.addEventListener("click", function() {
                    window.location.href = `/get?key=${key}`
                })
            }
        }
    })
    .catch((err) => console.error("- Error trying to load logs.json: ", err));
const express = require("express")
const http = require("http")
const path = require("path")

const app = express()
const server = http.createServer(app)

const port = 8080

app.use(express.static(path.join(__dirname + "/public")))
app.use((req, res, next) => {
    res.setHeader("Access-Control-Allow-Origin", "*")

    res.setHeader(
      "Access-Control-Allow-Methods",
      "GET, POST, OPTIONS, PUT, PATCH, DELETE"
    )

    res.setHeader(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept, Authorization"
    )

    next()
})

app.get("/", (req, res) => res.sendFile(path.join(__dirname + "/index.html")))
app.get("/get", (req, res) => res.sendFile(path.join(__dirname + "/public/display.html")))

server.listen(port)
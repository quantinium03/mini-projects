package main

import (
	"github.com/gofiber/fiber/v2"
	"github.com/quantinium03/mini-projects/golang-in-docker/database"
)

func main() {
	database.ConnectDb()
	app := fiber.New()

	setupRoutes(app)
	app.Listen(":3000")
}

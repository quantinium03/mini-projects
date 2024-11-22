package main

import (
	"github.com/gofiber/fiber/v2"
	"github.com/quantinium03/mini-projects/golang-in-docker/handlers"
)

func setupRoutes(app *fiber.App) {
	app.Get("/", handlers.Home)
	app.Post("/fact", handlers.CreatePost)
}

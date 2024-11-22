package handlers

import (
	"github.com/gofiber/fiber/v2"
	"github.com/quantinium03/mini-projects/golang-in-docker/database"
	"github.com/quantinium03/mini-projects/golang-in-docker/models"
)

func List(c *fiber.Ctx) error {
	facts := []models.Fact{}

	database.DB.Db.Find(&facts)
	return c.Status(200).JSON(facts)
}

func CreatePost(c *fiber.Ctx) error {
	fact := new(models.Fact)
	if err := c.BodyParser(fact); err != nil {
		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{
			"message": err.Error(),
		})
	}

	database.DB.Db.Create(&fact)
	return c.Status(200).JSON(fact)
}

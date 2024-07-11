package main

import (
	"bufio"
	"fmt"
	"github.com/QuantiniumX/mini-projects/pokedex-in-go/packages/pokedexapi"
	"log"
	"os"
	"strings"
)

type config struct {
	pokedexapiClient   pokedexapi.Client
	nextLocationURI *string
	prevLocationURI *string
}

func startREPL(cfg *config) {
	reader := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("Pokedex > ")
		reader.Scan()

		words := cleanInput(reader.Text())

		if len(words) == 0 {
			continue
		}

		commandName := words[0]

		command, exists := getCommands()[commandName]
		if !exists {
			fmt.Println("Unknown Command")
			continue
		}

		err := command.callback(cfg)
		if err != nil {
			log.Fatal(err)
		}
	}
}

func cleanInput(text string) []string {
	op := strings.ToLower(text)
	wd := strings.Fields(op)
	return wd
}

type cliCommand struct {
	name        string
	description string
	callback    func(*config) error
}

func getCommands() map[string]cliCommand {
	return map[string]cliCommand{
		"help": {
			name:        "help",
			description: "Display a help message",
			callback:    helpCommand,
		},
		"exit": {
			name:        "exit",
			description: "Exits the program",
			callback:    exitCommand,
		},
		"map": {
			name:        "map",
			description: "displays the name of next 20 location areas in the pokemon world",
			callback:    mapfCommand,
		},
		"mapb": {
			name:        "mapb",
			description: "displays the name of previous 20 location in the pokemon world",
			callback:    mapbCommand,
		},
	}
}

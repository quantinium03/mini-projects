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
	pokedexapiClient pokedexapi.Client
	nextLocationURI  *string
	prevLocationURI  *string
	caughtPokemon    map[string]pokedexapi.Pokemon
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
		args := []string{}
		if len(words) > 1 {
			args = words[1:]
		}

		command, exists := getCommands()[commandName]
		if !exists {
			fmt.Println("Unknown Command")
			continue
		}

		err := command.callback(cfg, args...)
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
	callback    func(*config, ...string) error
}

func getCommands() map[string]cliCommand {
	return map[string]cliCommand{
		"help": {
			name:        "help",
			description: "Displays a help message",
			callback:    helpCommand,
		},
		"catch": {
			name:        "catch <pokemon_name>",
			description: "Attempt to catch a pokemon",
			callback:    catchCommand,
		},
		"inspect": {
			name:        "inspect <pokemon_name>",
			description: "View details about a caught Pokemon",
			callback:    inspectCommand,
		},
		"explore": {
			name:        "explore <location_name>",
			description: "Explore a location",
			callback:    exploreCommand,
		},
		"map": {
			name:        "map",
			description: "Get the next page of locations",
			callback:    mapfCommand,
		},
		"mapb": {
			name:        "mapb",
			description: "Get the previous page of locations",
			callback:    mapbCommand,
		},
		"pokedex": {
			name:        "pokedex",
			description: "See all the pokemon you've caught",
			callback:    pokedexCommand,
		},
		"exit": {
			name:        "exit",
			description: "Exit the Pokedex",
			callback:    exitCommand,
		},
	}
}

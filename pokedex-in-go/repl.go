package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func startREPL() {
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

		err := command.callback()
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
	callback    func() error
}

func getCommands() map[string]cliCommand {
	return map[string]cliCommand{
		"help": {
			name:        "help",
			description: "Display a help message",
			callback:    help_command,
		},
		"exit": {
			name:        "exit",
			description: "Exits the program",
			callback:    exit_command,
		},
	}
}

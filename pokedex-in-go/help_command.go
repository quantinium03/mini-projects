package main

import (
	"fmt"
)

func help_command() error {
	fmt.Println("Welcome to Pokedex")
	fmt.Printf("Usage: \n\n")

	for _, cmd := range getCommands() {
		fmt.Printf("%s: %s\n", cmd.name, cmd.description)
	}
	fmt.Println();
	return nil;
}

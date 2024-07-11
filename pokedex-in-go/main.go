package main

import (
	"github.com/QuantiniumX/mini-projects/pokedex-in-go/packages/pokedexapi"
	"time"
)

func main() {
	pokeClient := pokedexapi.NewClient(5 * time.Second)
	cfg := &config{
		pokedexapiClient: pokeClient,
	}
	startREPL(cfg)
}

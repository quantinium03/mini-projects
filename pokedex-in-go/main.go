package main

import (
	"github.com/QuantiniumX/mini-projects/pokedex-in-go/packages/pokedexapi"
	"time"
)

func main() {
	pokeClient := pokedexapi.NewClient(5 * time.Second, time.Minute*5)
	cfg := &config{
		caughtPokemon: map[string]pokedexapi.Pokemon{},
		pokedexapiClient: pokeClient,
	}
	startREPL(cfg)
}

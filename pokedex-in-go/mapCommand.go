package main

import (
	"errors"
	"fmt"
)

func mapfCommand(cfg *config) error {
	locationResp, err := cfg.pokedexapiClient.FetchLocation(cfg.nextLocationURI)
	if err != nil {
		return err
	}

	cfg.nextLocationURI = locationResp.Next
	cfg.prevLocationURI = locationResp.Previous

	for _, loc := range locationResp.Results {
		fmt.Println(loc.Name)
	}
	return nil
}

func mapbCommand(cfg *config) error {
	if cfg.prevLocationURI == nil {
		return errors.New("You are on the first page")
	}
	locationResp, err := cfg.pokedexapiClient.FetchLocation(cfg.prevLocationURI)
	if err != nil {
		return err
	}

	cfg.nextLocationURI = locationResp.Next
	cfg.prevLocationURI = locationResp.Previous

	for _, loc := range locationResp.Results {
		fmt.Println(loc.Name)
	}
	return nil
}

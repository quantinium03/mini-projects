package main

import (
	"os"
)

func exitCommand(cfg* config) error {
	os.Exit(1)
	return nil
}

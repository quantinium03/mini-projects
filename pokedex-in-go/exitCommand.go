package main

import (
	"os"
)

func exitCommand(cfg* config, args ...string) error {
	os.Exit(1)
	return nil
}

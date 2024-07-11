package pokedexapi

import (
	"net/http"
	"time"
)

type client struct {
	httpClient http.Client
}

func NewClient(timeout time.Duration) client {
	return client{
		httpClient: http.Client{
			Timeout: timeout,
		},
	}
}

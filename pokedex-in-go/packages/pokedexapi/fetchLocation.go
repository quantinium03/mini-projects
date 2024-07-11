package pokedexapi

import (
	"encoding/json"
	"io"
	"net/http"
)

func (c Client) FetchLocation(pageURI *string) (locationResponse, error) {
	url := baseURI + "/location-area"
	if pageURI != nil {
		url = *pageURI
	}

	if val, ok := c.cache.Get(url); ok {
		location := locationResponse{}
		err := json.Unmarshal(val, &location)
		if err != nil {
			return locationResponse{}, err
		}
		return location, nil

	}

	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		return locationResponse{}, err
	}

	resp, err := c.httpClient.Do(req)
	if err != nil {
		return locationResponse{}, err
	}
	defer resp.Body.Close()

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return locationResponse{}, err
	}

	location := locationResponse{}
	err = json.Unmarshal(data, &location)
	if err != nil {
		return locationResponse{}, err
	}
	c.cache.Add(url, data)
	return location, nil
}

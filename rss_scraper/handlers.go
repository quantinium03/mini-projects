package main

import (
	"log"
	"net/http"
)

func respondWithError(w http.ResponseWriter, code int, message string) {
	if code > 499 {
		log.Println("Internal Server Error: ", code, " ", message)
	}
	type errResponse struct {
		Error string `json:"error"`
	}
	respondWithJSON(w, code, errResponse{
		Error: message,
	})
}

func handleRequest(w http.ResponseWriter, r *http.Request) {
	respondWithJSON(w, 200, struct{}{})
}

func handlerErr(w http.ResponseWriter, r *http.Request) {
	respondWithJSON(w, 400, "Something went wrong")
}

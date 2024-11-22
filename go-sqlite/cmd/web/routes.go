package main

import "net/http"

func (app *app) routes() http.Handler {
	mux := http.NewServeMux()
	mux.HandleFunc("/", app.getHome)
	mux.HandleFunc("/posts/create", app.postHandler)
	return mux
}

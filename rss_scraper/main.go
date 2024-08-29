package main

import (
	"fmt"
	"log"
	"net/http"
	"os"

	"github.com/joho/godotenv"

	"github.com/go-chi/chi"
	"github.com/go-chi/cors"
)

func main() {
	godotenv.Load()
	PORT := os.Getenv("PORT")
	if PORT == "" {
		log.Fatal("PORT was not found in the environment variables")
	}

	router := chi.NewRouter()

	router.Use(cors.Handler(cors.Options{
		AllowedOrigins:   []string{"https://*", "http://*"},
		AllowedMethods:   []string{"GET", "POST", "PUT", "DELETE", "OPTIONS"},
		AllowedHeaders:   []string{"*"},
		ExposedHeaders:   []string{"Link"},
		AllowCredentials: false,
		MaxAge:           300,
	}))

	v1Router := chi.NewRouter()
	v1Router.Get("/healthz", handleRequest)
	v1Router.Get("/error", handlerErr)

	router.Mount("/v1", v1Router)

	srv := &http.Server{
		Handler: router,
		Addr:    ":" + PORT,
	}

	log.Println("Starting the server at Port: ", PORT)
	err := srv.ListenAndServe()
	if err != nil {
		log.Fatal(err)
		return
	}

	fmt.Println("Port: ", PORT)
}

package main

import (
	"database/sql"
	"fmt"
	"log"
	"net/http"
	"os"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
	"github.com/joho/godotenv"
	"github.com/mini-projects/keylogger-server/internal/auth"
	"github.com/mini-projects/keylogger-server/internal/database"
	"github.com/mini-projects/keylogger-server/internal/handler"
	"github.com/mini-projects/keylogger-server/internal/tp"

	_ "github.com/mattn/go-sqlite3"
)

func main() {
	godotenv.Load(".env")
	port := os.Getenv("PORT")
	if port == "" {
		log.Fatal("PORT environment is not set")
	}

	db, err := sql.Open("sqlite3", "keylogger")
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	dbQuery := database.New(db)
	apicfg := tp.ApiConf{
		DB: dbQuery,
	}

	/* loginHandler := &handler.LoginUserHandler{
		ApiCfg: apicfg,
	} */

	countHandler := &handler.CounterHandler{
		ApiCfg: apicfg,
	}

	r := chi.NewRouter()
	r.Use(middleware.Logger)
	r.Use(middleware.Recoverer)

	v1 := chi.NewRouter()
	v1.Post("/increment", auth.MiddlewareAuth(&apicfg, countHandler.IncrementCounter))
/* 	v1.Get("/login", loginHandler.LoginUser); */
	v1.Get("/counter", countHandler.GetCounter)

	r.Mount("/v1", v1)

	srv := &http.Server{
		Addr:    ":" + port,
		Handler: r,
	}

	fmt.Println("Listening on port %s", port);
	srv.ListenAndServe()
}

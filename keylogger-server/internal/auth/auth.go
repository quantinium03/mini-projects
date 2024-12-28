package auth

import (
	"database/sql"
	"log"
	"net/http"
	"strings"

	"github.com/mini-projects/keylogger-server/internal/tp"
	"github.com/mini-projects/keylogger-server/utils"
	"golang.org/x/crypto/bcrypt"
)

type authHandler func(http.ResponseWriter, *http.Request)

func MiddlewareAuth(cfg *tp.ApiConf, handler authHandler) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		authHeader := r.Header.Get("Authorization")
		if authHeader == "" {
			log.Println("Auth header is missing")
			utils.ResponseWithError(w, http.StatusUnauthorized, "Unauthorized Request")
			return
		}

		if !strings.HasPrefix(authHeader, "Bearer: ") {
			log.Println("Malformed bearer token")
			utils.ResponseWithError(w, http.StatusUnauthorized, "Malformed Bearer Token")
			return
		}

		password := strings.TrimPrefix(authHeader, "Bearer: ")
		if password == "" {
			utils.ResponseWithError(w, http.StatusUnauthorized, "Unauthorized Request")
			return
		}

		username := r.URL.Query().Get("user")
		if username == "" {
			utils.ResponseWithError(w, http.StatusUnauthorized, "No username in the URL query")
			return
		}

		userhash, err := cfg.DB.GetUserHash(r.Context(), username)
		if err != nil {
			if err == sql.ErrNoRows {
				log.Println("No user found with username:", username)
				utils.ResponseWithError(w, http.StatusUnauthorized, "Unauthorized Request")
				return
			}
			log.Println("Failed to query the database:", err)
			utils.ResponseWithError(w, http.StatusInternalServerError, "Internal Server Error")
			return
		}

		log.Println("userhash", userhash)

		err = bcrypt.CompareHashAndPassword([]byte(userhash), []byte(password))
		if err != nil {
			log.Println("Password hash doesn't match")
			utils.ResponseWithError(w, http.StatusUnauthorized, "Unauthorized Request")
			return
		}

		handler(w, r)
	}
}

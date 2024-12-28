package handler

import (
	"encoding/json"
	"log"
	"net/http"

	"github.com/mini-projects/keylogger-server/internal/tp"
	"github.com/mini-projects/keylogger-server/utils"
)

type CounterHandler struct {
	ApiCfg tp.ApiConf
}

/* type parameters struct {
	Username string `json:"username"`
	Password string `json:"password"`
} */

/* func (cfg *LoginUserHandler) LoginUser(w http.ResponseWriter, r *http.Request) {
	params := parameters{}
	err := json.NewDecoder(r.Body).Decode(&params)
	if err != nil {
		utils.ResponseWithError(w, http.StatusBadRequest, "Invalid request")
		return
	}

	hash, err := bcrypt.GenerateFromPassword([]byte(params.Password), bcrypt.DefaultCost)
	if err != nil {
		utils.ResponseWithError(w, http.StatusInternalServerError, "Failed to generate hash")
		return
	}

	log.Println("Username:", params.Username)
	log.Println("Password:", params.Password)

	user, err := cfg.ApiCfg.DB.InsertUser(r.Context(), database.InsertUserParams{
		Username:  params.Username,
		Userhash:  string(hash),
		Updatedat: time.Now().UTC(),
		Createdat: time.Now().UTC(),
	})
	if err != nil {
		log.Println(err)
		utils.ResponseWithError(w, http.StatusInternalServerError, "Couldn't create user")
		return
	}

	utils.RespondWithJson(w, http.StatusOK, utils.DatabaseUserToUser(user))
} */

func (cfg *CounterHandler) IncrementCounter(w http.ResponseWriter, r *http.Request) {
	count, err := cfg.ApiCfg.DB.GetCounter(r.Context())
	if err != nil {
		log.Printf("Error fetching counter: %v", err)
		utils.ResponseWithError(w, http.StatusInternalServerError, "Couldn't fetch the counter from the database")
		return
	}

	params := tp.CounterParameters{}
	err = json.NewDecoder(r.Body).Decode(&params)
	if err != nil {
		log.Printf("Invalid request body: %v", err)
		utils.ResponseWithError(w, http.StatusBadRequest, "Invalid Request")
		return
	}

	if params.Counter < 0 {
		utils.ResponseWithError(w, http.StatusBadRequest, "Counter cannot be negative")
		return
	}

	newCount, err := cfg.ApiCfg.DB.UpdateCounter(r.Context(), params.Counter+count)
	if err != nil {
		log.Printf("Error updating counter: %v", err)
		utils.ResponseWithError(w, http.StatusInternalServerError, "Couldn't update the counter")
		return
	}

	utils.RespondWithJson(w, http.StatusOK, map[string]int{"counter": int(newCount)})
}

func (cfg *CounterHandler) GetCounter(w http.ResponseWriter, r *http.Request) {
	count, err := cfg.ApiCfg.DB.GetCounter(r.Context())
	if err != nil {
		log.Printf("Error fetching counter: %v", err)
		utils.ResponseWithError(w, http.StatusInternalServerError, "Couldn't fetch the counter from the database")
		return
	}

	utils.RespondWithJson(w, http.StatusOK, map[string]int{"counter": int(count)})
}
